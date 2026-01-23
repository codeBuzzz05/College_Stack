#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(int argc, char* argv[]){
	int fd,n,fseek;
	char c;
	if(argc!=2){
		cout<<"USage: ./a.out filenaem";
		exit(0);
	}
	if((fd=open(argv[1],O_RDONLY))==-1){
		cout<<"Failed to open the file";
		exit(0);
	}
	while((n=read(fd,&c,1)>0)){
	cout<<"File Charecter : "<<c<<"     ";
		fseek=lseek(fd,1,1);
		cout<<"New seek value "<<fseek<<"\n";
	}
	return 1;
}