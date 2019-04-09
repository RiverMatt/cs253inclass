/**
 * Demonstrates multi-threading in java by extending the JRE's Thread class
 * <p>
 * In this example, each ExampleJavaThread object implements a single thread by extending the JRE's
 * Thread class and overriding its run method.  Each object's run method appears to execute
 * concurrently with the executing run method in the other objects, an example of pseudo-concurrency
 * in which the number of threads may exceed the number of processors (cores).
 * 
 * @author jimconrad@boisestate.edu
 *
 */
public class ExampleJavaThread extends Thread {
	
	//The attributes of an ExampleJavaThread object (in addition to those in Thread)
	private long msBetweenMsgs;		//milliSeconds
	private String msg;				//Print this message every msBetweenMsgs milliseconds
	private boolean stop;			//Flag polled by run() to determine when to stop running
	
	//Constructor (initializes the attributes of this ExampleJavaThread object)
	ExampleJavaThread(long msBetweenMsgs, String msg) {
		this.msBetweenMsgs = msBetweenMsgs;
		this.msg = msg;
		this.stop = false;
		this.printString("Starting");
	} //constructor
	
	//---------------------------------------------------------------------------------------------------
	// The JRE invokes this run method to execute this thread's code.  This example merely loops
	// until this object's stop flag is set true, printing a message, and sleeping for msBetweenMsgs
	// milliseconds.  Real threads do much more.  ;)
	//---------------------------------------------------------------------------------------------------
	public void run() {
		while(!stop) {
			printString(msg);								  	//Print's thread id number and msg
			try {
				Thread.sleep(msBetweenMsgs);					//Pause thread from executing
			} catch (InterruptedException e) {
				printString("Insomnia");
				e.printStackTrace();
			}
		} //while
		printString("Exiting");
	} //run
	
	//Set the stop flag true
	private void setStop() {
		this.stop = true;		
	}

	//Print a string on the console labeled with our thread id number
	private void printString(String s) {
		System.out.println("Thread "+getId()+":  "+s);					
	} //printString

	
	
	//---------------------------------------------------------------------------------------------------
	// The JRE starts the example here.  The main method will create several ExampleJavaThread objects
	// and then exit as there's nothing else for it to do.  The references for the objects are static
	// so they will remain even after main exits.
	//---------------------------------------------------------------------------------------------------
	private static ExampleJavaThread thing1, thing2, thing3; 
	public static void main(String[] args) throws InterruptedException {
		
		//Build every thing
		thing1 = new ExampleJavaThread(1000L,"You are a silly thing.");
		thing2 = new ExampleJavaThread(5000L,"Inconceivable!");
		thing3 = new ExampleJavaThread(5500L,"You keep using that word. I do not think it means what you think it means.");
		
		//Start every thing running
		thing1.start();
		thing2.start();
		thing3.start();
		
		//Stop every thing after they've had enough fun
		sleep(20000L);
		thing1.setStop();
		thing2.setStop();
		thing3.setStop();
		System.out.println("Everything is stopping");
		
	} //main



}
