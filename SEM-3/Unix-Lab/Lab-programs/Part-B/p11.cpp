#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/stat.h>
#include<time.h>
using namespace std;

//Handler function
void handler(int signo){
  cout<<"The interrupt singal has been captured by the user defined function. The signal number-> "<<signo;
  exit(0);
}
int main(){
  signal(SIGINT, handler);

  while(1){
    cout<<"Hello";
  }
  return 1;
}
 
//default action
int main() 
{ 
 signal(SIGINT, SIG_DFL) ; 
 while(1) 
   cout<<"hello\t"; 
  } 

//Ignoring the signal
int main() 
{ 
 signal(SIGINT,SIG_IGN) ; 
 while(1) 
 cout<<"hello\t  "; 
  }