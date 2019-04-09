import java.util.Random;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;

public class TestThread extends Thread {
	
	/* Instance Variables */
	private boolean stop;
	private int counter, hash;
	private Random rand;
	private long duration;
	// List list = Collections.synchronizedList(new ArrayList<String>());
	
	/* Constructor */
	public TestThread() {
		stop = false;
		counter = 0;
		rand = new Random();
		hash = this.hashCode();
		System.out.printf("Thread %10d: Starting...\n", hash);
	}
	
	/* Other Methods */
	public void run() {
			while (!stop) {
				counter++;
				duration = (long) rand.nextInt(3000);
				System.out.printf("Thread %10d: Executed %3d times, sleeping for %4d ms.\n"  , hash, counter, duration);
				try {
					Thread.sleep(duration);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			
			System.out.printf("Thread %10d: Stopping...\n", hash);
	}
	
	public void setStop() {
		stop = true;
	}

}

