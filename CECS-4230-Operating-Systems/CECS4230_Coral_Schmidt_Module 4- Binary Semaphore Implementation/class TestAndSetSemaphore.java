public class TestAndSetSemaphore {
    private volatile boolean lock;

    public TestAndSetSemaphore() {
        lock = false; // Semaphore is initially unlocked
    }

    public void acquire() {
        while (testAndSet(lock)) {
            // Busy waiting until the lock becomes false
        }
    }

    public void release() {
        lock = false; // Release the lock
    }

    // Atomic test-and-set operation
    private synchronized boolean testAndSet(boolean value) {
        boolean previous = value;
        value = true; // Set to true to indicate lock attempt
        return previous;
    }
}