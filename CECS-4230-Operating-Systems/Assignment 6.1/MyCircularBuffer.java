/*
Author: [Your Name]
Student Number: [Your Student Number]
Filename: MyCircularBuffer.java
This class represents a circular buffer implementation for the readers and writers problem.
*/

public class MyCircularBuffer {
    private int[] buffer;
    private int size;
    private int readIndex;
    private int writeIndex;
    private int count;

    public MyCircularBuffer(int size) {
        this.size = size;
        buffer = new int[size];
        readIndex = 0;
        writeIndex = 0;
        count = 0;
    }

    public synchronized void write(int value) {
        while (count == size) {
            try {
                wait(); // Wait while buffer is full
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }
        buffer[writeIndex] = value;
        writeIndex = (writeIndex + 1) % size;
        count++;
        notifyAll(); // Notify waiting readers
    }

    public synchronized int read() {
        while (count == 0) {
            try {
                wait(); // Wait while buffer is empty
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return -1;
            }
        }
        int value = buffer[readIndex];
        readIndex = (readIndex + 1) % size;
        count--;
        notifyAll(); // Notify waiting writers
        return value;
    }
}
