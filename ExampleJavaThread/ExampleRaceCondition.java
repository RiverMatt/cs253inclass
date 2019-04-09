
public class ExampleRaceCondition extends Thread {
	
	//The instance variables of counter are the shared data
	private static Counter counter = new Counter();
	
	//Define references to our two instantiated thread objects
	private static ExampleRaceCondition thread1;
	private static ExampleRaceCondition thread2;
	
	//Instance variables embedded into each thread object
	private boolean isRunning=true;  //These threads are born "running" ;)

	//The main thread begins execution here
	public static void main(String[] args) throws InterruptedException {
		System.out.println("Starting...");
		
		//Construct the two thread objects
		thread1 = new ExampleRaceCondition();
		thread2 = new ExampleRaceCondition();
		
		//Start the two threads executing
		thread1.start();
		thread2.start();
		
		//Wait for both threads to finish
		while(thread1.isRunning() && thread2.isRunning()) {
			sleep(100L);
		}
		
		//Print the final count
		System.out.println("Final count="+counter.getCount());

	}

	//Method checks to see if a thread is still running
	private boolean isRunning() {
		return isRunning;
	}
	
	//The JRE invokes run() which serves as a thread's "main" method
	public void run() {
	
		//This thread will increment count 5000000 times
		for(int i=1;i<=5000000;i++) {
			counter.increment();
		}
		
		isRunning=false;  	//This thread will quit running
		return;				//This is the end of this thread
		
	} 

}
