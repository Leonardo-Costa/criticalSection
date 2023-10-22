//Leonardo Loureiro Costa
import java.util.concurrent.Semaphore;

public class TrafficController {

    private Semaphore bridgeSemaphore;

    public TrafficController() {
        bridgeSemaphore = new Semaphore(1);
    }

    public void enterLeft() {
        try {
            bridgeSemaphore.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void leaveLeft() {
        bridgeSemaphore.release();
    }

    public void enterRight() {
        try {
            bridgeSemaphore.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void leaveRight() {
        bridgeSemaphore.release();
    }
}
