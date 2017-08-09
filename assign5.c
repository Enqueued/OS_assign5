#include "geninc.h"
int quant;
char *file;
char *algo;
pthread_t read_file;
struct PCB ready_q[2048];

void error_exit(char *string, int flag){
  fprintf(stderr, string);
  exit(flag);
}

/**************MAIN******************
 * this is where the actual setup is taking place
 * should be able to call all the different processes
 ************************************/
void main (int nargs, char *args[]){
  if(nargs < 3){
    error_exit("Not Enough Variables", -1);
  }

  printf("%d : starting args\n", nargs);
  check_args(nargs, args);
  printf("Algo: %s\t File: %s\t Quant: %d\n", algo, file, quant);
}

void check_args( int nargs, char *args[]){
  int i = 0;
  while (i < nargs){
    //gotta do if-else ladder
    int size = sizeof(args[i]);
    char arg[size];
    strcpy(arg, args[i]);
    printf("arg: %s\n", arg);

    if(strcmp(arg,"-algo") == 0){
      //printf("%d||i\t", i);
      i++;
      algo=malloc(sizeof(args[i]));
      strcpy(algo,args[i]);
      //printf(" [%s], args", algo);
    }else if(strcmp(arg,"-quantum") == 0){
      i++;
      //printf("%d||i\t", i);
      char *num = args[i];
      quant = atoi(num);
      //printf("%d||Quant || %s :ARGS\t", quant, args[i]);
    }else if(strcmp(arg, "-input") == 0){
      //printf("%d||i\t", i);
      i++;
      file=malloc(sizeof(args[i]));
      strcpy(file,args[i]);
    }
    i++;
  }
  FILE * fp = file_open();
  decision_time(fp);
}

void decision_time(FILE * fp){
  if(strcpy(algo, "fifo")==0){
    fifo(fp, running, ready_q);
  }else if(strcpy(algo, "rr")==0){
    rr(file, thread);
  }
}

FILE * file_open(){
  FILE *fp;
  fp = fopen(file, "r");
  return fp;
}

void file_close(FILE * fp){
  fclose(fp);
  fprintf(stderr, "Closed file");
}

char * get_next_word(FILE * fp){
  char * string;
  if(fscanf(fp, string)){
    return string;
  } else {
    return NULL;
  }
}
