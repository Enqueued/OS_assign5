#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**********PCB**
* should be used to created the pcb and
* hold the ustilities that the pcb will be using
* each process will have a PCB
***************/
struct PCB{
  int priority;
  int cpu_burst[4];
  int io_burst[4];
  int cpu;
  int io;
  int Wtime;
}

