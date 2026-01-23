#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

using namespace std;

int main(int argc , char* argv[]){
	int n,fd1,fd2;
	char buff[10];
	if(argc!=3){
		cout<<"Usage : ./a.out sourceFile Destination File";
		exit(0);
	}
	if((fd1=open(argv[1],O_RDONLY))==-1){
		cout<<"Coudnt open the file "<<argv[1]<<" for reading ";
		exit(0);
	}
	if((fd2=open(argv[2],O_WRONLY |O_CREAT| O_TRUNC,777))==-1){
	       cout<<"Failed to open the file for writing purpose";
       		exit(0);
	}
	

	while((n=read(fd1,buff,1)>0)){
		write(1,buff,n);
		write(fd2,buff,n);
		}
	close(fd1);
	close(fd2);
	return 1;
}
