/****************************************************
 *  ps.c
 *
 *  Wendy Slattery
 *  COP4610 - Proj 3
 *  11/10/20
 *
 *  user app to implement sys call showpc which shows
 *  the runnable processes with pid and priorities
 *  inspired by Varsha Jenni YouTube tutorial
 *  and used to test new priority schedule
 ***************************************************/
#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
  
  // just essentially calling the showps command
  showps();
  exit();
}
