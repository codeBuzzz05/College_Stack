#include<stdio.h>

int binarySearch(int arr[], int low, int high,int key){
    int mid=(low + high)/2;
    if(low>high){
        return -1;
    }    
    if (arr[mid]==key){
        return mid;
    }
    else if(key<arr[mid]){
        return binarySearch(arr,low,mid-1,key);
    }   
    else{
        return binarySearch(arr,mid+1,high,key);
    }   
}
int main(){
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element\n");
        scanf("%d",arr+i);
    }
    int low=-1;
    int high=n-1;
    int key;
    printf("Enter the key element to search\n");
    scanf("%d",&key);
    int res=binarySearch(arr,low,high,key);
    if(res==-1){
        printf("Oops! element not found\n");

    }
    else{
        printf("Element %d found in the location %d",key,res);
    }
    return 1;
}