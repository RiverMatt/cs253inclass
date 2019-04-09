/**
 * Implements a counter as shared data
 * <p>
 * Note:  If you use the synchronized keyword in this class, the JRE will
 * construct a mutex and conditional variable to implement the monitor
 * in each instance of a Counter.
 * 
 * @author jimconrad
 *
 */
class Counter {
	
	//Objects of type Counter have one instance variable, a counter.
	//Note:  The keyword "private" refers to count's visibility in other
	//classes --- it has nothing to do with how many threads share its value
	private int count=0;
	
	//This method merely increments the counter.  To protect its critical
	//section with mutual exclusion, it must be synchronized.
	synchronized void increment() {
		count++;  	//This statement is a critical section that must be executed atomically 
	}
	
	//Provide a getter to access the count
	public int getCount() {return count;}
}
