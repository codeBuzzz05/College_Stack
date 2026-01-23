#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<ctype.h>

void printing(const char* str){
int i=0;
for(i=0;str[i]!='\0';i++){
  putc(str[i],stdout);
  fflush(stdout);
  usleep(10000);
}
}

int main(){
  pid_t pid;
  if((pid=fork())==-1){
    perror("Fork error");
    exit(0);
  }
  if(pid==0){
    printing("I am child");
  }
  if(pid>0){
    printing("I am parent");
  }
  return 1;
}

