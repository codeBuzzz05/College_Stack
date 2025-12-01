#include <stdio.h>

int fibo(int n){
    if(n==1||n==0)
        return n;
     return fibo(n-1)+fibo(n-2);
 
}

int main(){
    int n;
    int res;
    printf("Enter a positive integer\n");
    scanf("%d",&n);
    res=fibo(n);
    printf("\n%d",res);
    return 2;
}