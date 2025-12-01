#include<stdio.h>

void tower_of_hanoi(char A,char B,char C,int n){
    if(n==1){
        printf("Move from %c -> %c\n",A,B);
    }
    else{
        tower_of_hanoi(A,C,B,n-1);
        printf("Move from %c -> %c\n",A,B);
        tower_of_hanoi(C,B,A,n-1);
    }

}

int main(){
    int n;
    char A='A',B='B',C='C';
    printf("Enter the  number of disks \n");
    scanf("%d",&n);
    printf("The moves to follow arre:\n");
    tower_of_hanoi(A,B,C,n);

}