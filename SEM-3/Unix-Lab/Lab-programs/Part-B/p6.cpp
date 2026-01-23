#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
using namespace std;

int main(){
  pid_t pid;

  if((pid=fork())==-1){
    perror("Fork error ");
        exit(0);
  }
  if(pid==0){
    cout<<"Child Process :"<<getpid();
    cout<<"Waitinig for the parent to execute the exit code by the child ";
    exit(0);
  }
  if(pid>0){
  sleep(5);
  cout<<"Parent process :"<<getpid();
  system("ps u");

  }
}
