#include<stdio.h>
#include<sys/wait.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
  pid_t pid;
  if((pid=fork())==-1){
    perror("Fork error");
    exit(0);
  }
  if(pid==0){
    sleep(5);
    cout<<"Orphan process Id: "<<getpid()<<"\n";
    cout<<"The Orphan's parent : "<<getppid()<<"\n";
  }
  if(pid>0){
    cout<<"original Process :"<<getpid()<<"\n";
    exit(0);
  }
  return 1;
}