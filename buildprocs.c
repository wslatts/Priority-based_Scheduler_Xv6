#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char *argv[1]){
  int num; //number of processes to build
  int j, pid;
  double x;
  double y = 0;

  // check arguments
  if(argc < 2)
    num = 1;  
  else
    num = atoi(argv[1]);
  if(num < 0 || num > 15) 
    num = 2;

  x = 0;
  pid = 0;

  // for however many processes instructed to build
  for(j = 0; j < num; j++){
    pid = fork();
    
    if(pid < 0){
      printf(1, "ERROR: forking child process failed\n");      
    }
    else if(pid > 0){
      printf(1, "Parent process, pid = %d spawns child process, pid = %d\n", getpid(), pid);
      wait();
    }
    else{
      printf(1, "Child process,  pid = %d is created\n", getpid());
      for(x = 0; x < 90000000; x++)
        y = 24.5 * 9.7 + x;
      y++;      
      break;
    }
  }
  exit();
}
