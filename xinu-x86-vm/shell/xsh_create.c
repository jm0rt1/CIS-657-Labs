/* xsh_create.c - xsh_create */
#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*------------------------------------------------------------------------
* xsh_create - shell command to create
*------------------------------------------------------------------------
*/
shellcmd xsh_create(int nargs, char *args[])
{
  pri16 priority;
  char ch;
  char *chprio;
  pid32 pid;
  if (nargs == 1) {
    priority=INITPRIO;
  }
  else if ( nargs == 2 ) {
    chprio = args[1];
    //ch = *chprio++;
    
    priority = 0;
    priority = atoi(chprio);
    //kprintf("prio = %d", priority);
  }
  else {
    kprintf("Too many arguments\n");
    return 1;
  }
  pid = create(runforever, 1024, priority, "Test", 1, priority);
  //kprintf("pid = %d\n", pid);
  resume(pid);
  return 0;
}
