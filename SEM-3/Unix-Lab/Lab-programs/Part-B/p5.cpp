//using fork
#include<stdio.h>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
int main(){
  pid_t pid;
  if((pid=fork())==-1){
    perror("Fork error");
    exit(0);
  }
  if(pid==0){
    cout<<"Child :"<<getpid();
    cout<<" Parent :"<<getppid();

  }
  if(pid>0){
    cout<<"Original Process:"<<getpid();
    cout<<"Parent Process :"<<getppid();
  }
cout<<"End of the program";
return 1;
}

//using vfork
#include<stdio.h>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


using namespace std;
int main(){
  pid_t pid;
  if((pid=vfork())==-1){
    perror("Fork error");
    exit(0);
  }
  if(pid==0){
    cout<<"Child :"<<getpid();
    cout<<" Parent :"<<getppid();

  }
  if(pid>0){
    cout<<"Original Process:"<<getpid();
    cout<<"Parent Process :"<<getppid();
  }
cout<<"End of the program";
return 1;
}