#include "geninc.h"

void *reading(FILE * fp, struct PCB ready_q[]){
  char * word;
  int num = 0;
  while(word = get_next_word(fp)){
    if(strcmp(word, "proc")){
      struct PCB new = init_PCB();
      word = get_next_word(fp);
      new.priority = atoi(word);
      word = get_next_word(fp);
      int count = atoi(word);
      int i = 0, k = 0, j = 0;
      while (i < count){
        if ((i+1)!=count){
          switch(i%2){
            case 0:
              new.cpu_burst[k++] = atoi(word);
            case 1:
              new.io_burst[j++] = atoi(word);
          }
        }
      }
      ready_q[num] = new;
      num++;
    } else if (strcmp(word, "sleep")){
      int sleeps = atoi(get_next_word(fp));
      sleep(sleeps);
    } else if (strcmp(word, "stop")){
      error_exit("Finished file read", 0);
    }
  }
}

void fifo(FILE * fp){
}
