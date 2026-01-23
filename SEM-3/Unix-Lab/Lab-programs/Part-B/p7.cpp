#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

using namespace std;

int main()
{
  int status;
  pid_t pid;
  if((pid=fork())==-1){
    perror("Fork error");
    exit(0);
  }
  if(pid==0){
    cout<<"Child process : "<<getpid()<<"\n";
    cout<<"Waiting for the parent to retrieve the ecit code";
    exit(0);
  }
  if(pid==0){
    wait(&status);
    cout<<"Parent process : "<<getpid()<<endl;
    system(" ps u");
  }
}