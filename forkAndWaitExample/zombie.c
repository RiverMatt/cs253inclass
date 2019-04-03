//-----------------------------------------------------------------------------
//
// zombie -- Demonstrate the creation of a zombie process
//
//
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


//We start with a single process executing the main function
int main(void) {

  //Only one process, the parent, executes here
  printf("PARENT:  The parent's PID=%d\n",getpid());

  //Create a new, duplicate process that will execute the code below
  fflush(stdout);               //Flush parent's stdout buffer into kernel
  int pid = fork();             //Fork will return twice, once in each process

  //Both the parent and the child are executing now.  If they are executing on
  //a multi-core CPU, both processes may execute this code simultaneously.

  //Am I the child process?
  if (pid==0) {
    printf("CHILD:  I am the child\n");//The child speaks
    fclose(stdout);                    //The child flushes and closes stdout
    return 0;                          //The child exits but is undead until parent retrieves its exit status

  //Am I the parent process?
  } else if (pid>0) {
    printf("PARENT:  The child PID=%d\n",pid);  //The parent speaks
    fflush(stdout);                    //Flush stdout buffer to kernel

    //Don't wait for the child to exit, leaving it as a zombie
    system("ps l");                   //Print info about each process
    return 0;                          //The parent's normal exit, leaving zombie to wonder the earth

  //Did the fork fail?
  } else {
    perror("Fork failed");             //Oh no!
  }
  return -1;                           //The parent's abnormal exit
}
