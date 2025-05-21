/*
Author: [Your Name]
Student Number: [Your Student Number]
Filename: MyCircularBufferTest.java
This class tests the MyCircularBuffer class by setting up producer and consumer threads.
*/

public class MyCircularBufferTest {
    public static void main(String[] args) {
        MyCircularBuffer buffer = new MyCircularBuffer(5);

        Thread producerThread = new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                buffer.write(i);
                System.out.println("Producer wrote: " + i);
                try {
                    Thread.sleep(1000); // Simulate writing time
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });

        Thread consumerThread = new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                int value = buffer.read();
                System.out.println("Consumer read: " + value);
                try {
                    Thread.sleep(2000); // Simulate reading time
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });

        producerThread.start();
        consumerThread.start();
    }
}
