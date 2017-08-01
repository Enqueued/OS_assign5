#include "geninc.h"

void error_exit(char *string, int flag){
  fprintf(stderr, string);
  exit(flag);
}

/**************MAIN******************
* this is where the actual setup is taking place
* should be able to call all the different processes
************************************/
void main (int nargs, char * args[]){
  if(nargs < 3){
    error_exit("Not Enough Variables", -1);
  }

  char * filename = args[2];
  printf("File name is %s\t", filename);


}

void fifo(){
}

void sjf(){
}
void rr(){
}
void pr(){
}
