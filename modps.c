/*****************************************************************************
 *  modps.c
 *
 *  Wendy Slattery
 *  COP 4610 - Priority Scheduler
 *  11/11/20
 *
 *  user app to create processes and display initial default values at 50
 *  place procs to sleep, change priority values, and observe aging
 ****************************************************************************/


#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
  int pid;
  
  printf(1, "\n\nStarting processes\n\n");
  showps();

  pid = fork();
  
  if(pid < 0){
    printf(1, "ERROR: forking child process failed\n");
  }
  else if(pid > 0){
    printf(1, "\n^^^^Parent pid %d initialized to default priority 50\n", getpid());
    printf(1, "\nParent creates child process....\n\n");
    showps();
    wait();
    sleep(90);
    setpriority(90);
    printf(1, "\nParent %d set to priority 90....\n\n", getpid());
    showps();
    showps();
    showps();
    showps();
    showps();
    showps();

  }
  else{
    int cpid = getpid();
    printf(1, "\n^^^^Child pid %d initialized to priority 50\n\n", cpid);
    printf(1,"Child process starts....\n\n");
    showps();
    sleep(60);
    setpriority(60);
    printf(1,"\nChild %d set to priority 60.... \n\n", cpid);
    showps();
  }

  exit();
}
