#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>
#include<sys/types.h>
#include<stdlib.h>
#include<wait.h>

using namespace std;

int main(){
  int pfd[2],n;
  char buff[10];
  if(pipe(pfd)==-1){
    perror("pipe");
    exit(0);
  }
  pid_t pid;
  if((pid=fork()==-1)){
      perror("Fork error");
      exit(0);
      }
  if(pid>0){
    close(pfd[0]);
    write(pfd[1],"Test\n",6);
  }
  if(pid==0){
      close(pfd[1]);
      n=read(pfd[0],buff,7);
      cout<<buff;
    }
      return 0;

}


//Demonstration of pipe
#include <stdio.h> 
#include <stdlib.h> 
 #include <errno.h> 
#include <unistd.h> 
#include <iostream> 
using namespace std; 
 
 int main() 
 { 
     int pfds[2];            
     char buf[30]; 
     if (pipe(pfds) == -1) 
     { 
          perror("pipe"); 
          exit(1); 
     } 
     cout<<"writing to file descriptor #"<<pfds[1]<<endl; 
     write(pfds[1], "test", 5);            
     cout<<"reading from file descriptor #"<<pfds[0]<<endl; 
     read(pfds[0], buf, 5); 
     cout<<"read : "<<buf<<endl; 
     return 0;
    }