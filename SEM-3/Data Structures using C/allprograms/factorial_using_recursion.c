#include <stdio.h>
#include<ctype.h>

int fact(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}

int main(){
    int sum=1,n;
    printf("Enter any positive integer\n");
    scanf("%d",&n);
    sum=fact(n);
    printf("Result : %d",sum);

}
