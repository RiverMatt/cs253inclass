
public class ThreadDriver {

	public static void main(String[] args) {
		
		TestThread thread1, thread2;
		
		thread1 = new TestThread();
		thread2 = new TestThread();
		
		thread1.start();
		thread2.start();
		
		try {
			Thread.sleep(20000);
		} catch (InterruptedException e) {
			System.out.printf("Stopped!!");
			e.printStackTrace();
		}
		
		thread1.setStop();
		thread2.setStop();

	}

}

