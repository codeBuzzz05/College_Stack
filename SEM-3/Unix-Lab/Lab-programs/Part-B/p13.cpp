#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

void p_exit(int status){
  if(WIFEXITED(status)){
    cout<<"Nnormal : "<<WEXITSTATUS(status);
  }
  if(WIFSIGNALED(status)){
    cout<<"Terminated :"<<WTERMSIG(status);
  }
  if(WIFSTOPPED(status)){
    cout<<"stopped :"<<WSTOPSIG(status);
  }
}

int main(){
  int status;
  pid_t child, pid;

  if((pid=fork())==-1){
    perror("fork error");
    return 0;
  }

  if(pid==0)
    exit(23);
  child=wait(&status);
  p_exit(status);


if((pid=fork())==-1){
  perror("errpr");
  return 0;
}
if(pid==0)
  abort();

child=wait(&status);
p_exit(status);

if((pid=fork())==-1){
  perror("Error");
  return 0;
}
if(pid==0)
  int res=5/0;

child=wait(&status);
p_exit(status);

return 0;
}
