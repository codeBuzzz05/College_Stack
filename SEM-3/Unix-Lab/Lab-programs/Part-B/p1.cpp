//Implimenting ln command
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
using namespace std;
int main(int argc, char * argv[]){
	if(argc!=3){
		cout<<"Usage : ./a.out sourceFile linkNAme";
		exit(0);
	}
	if((link(argv[1],argv[2]))==-1){
		perror("Link Error");
		exit(0);
	}
	cout<<"Link has been done with "<<argv[2];

	return 1;
}

//Implimenting rm command
#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

int main( int argc, char* argv[]){
	if(argc<2){
		cout<<"Usage ./a.out file1,file2,...filen";
		exit(0);
	}
	for(int i=1;i<argc;i++){
		if(unlink(argv[i])==-1){
				perror("Deleting error");
		}
		else{
			cout<<"File "<<argv[i]<< " deleted successfully"<<"\n";
		}
	}
	
	return 0;
}

//Implementing mv command
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[]){
	if(argc!=3){
		cout<<"Usage: Source File name, Newfile name";
		exit(0);
	}
	if(link(argv[1],argv[2])==-1){
		perror("Link error");
		exit(0);
	}
	unlink(argv[1]);
	cout<<"The new name of the file is "<<argv[2];
	return 1;
}

