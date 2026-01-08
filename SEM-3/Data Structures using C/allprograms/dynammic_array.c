#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int * array;
    int size;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    array=(int *)malloc(size*sizeof(int));
    int *q=array;
    printf("enter array elements\n");
    for(int i=0;i<size;i++){
        scanf("%d",array+i);
    }
    printf("Successful!\n");
    for(int i=0;i<size;i++){
        printf("%d ",*(q+i));
    }

    printf("\nprinting done\n");
    free(array);
    return 1;
}