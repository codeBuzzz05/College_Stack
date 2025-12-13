#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

int n;
int size=0;
typedef struct student{
    char name[20];
    char usn[20];
    char dept[10];
    int marks;
}student;
student *s=NULL;
void initialise(){
    s=(struct student *)malloc(n*sizeof(struct student));
    if(s==NULL){
        printf("Dynamic allocation failed\n");
        exit(0);
    }
}

void addstudent(){
    size++;
    if(size>n){
        printf("Student record is full");
        size-=1;
        return ;
    }
    printf("Enter student USN");
    scanf("%s",s[size-1].usn);
    printf("Enter student Name");
    scanf("%s",s[size-1].name);
    printf("Enter student department");
    scanf("%s",s[size-1].dept);
    printf("Enter student marks");
    scanf("%d",&s[size-1].marks);
    printf("Data entered successfully\n");
}
void searchstudent(){
    char key[20];
    printf("Enter student's USN");
    scanf("%s",key);
    for(int i=0;i<size;i++){
        if(strcmp(s[i].usn,key)==0){
            printf("\n--------------------------------------------\n");
            printf("Student USN:%s\nStudent Name:%s\nDept:%s\nMarks:%d",s[i].usn,s[i].name,s[i].dept,s[i].marks);
            printf("\n----------------------------------------------\n");
            return ;
        }
    }
    printf("Student record not found!\n");
    return ;
}
void display(){
    if(size==0){
        printf("Empty!\n");
        return ;
    }
    for(int i=0;i<size;i++){
        printf("\n---------------------------------------------------------------------------\n");
         printf("Student USN:%s\nStudent Name:%s\nDept:%s\nMarks:%d\n",s[i].usn,s[i].name,s[i].dept,s[i].marks);
    }
}
int main(){
    int choice;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    initialise();
   while(1){
    printf("1.Add Student\n2.Search student\n3.Display\n4.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 :addstudent();
        break;
        case 2:searchstudent();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        default : printf("Invalid choice\n");
    }
   }
    return 1;
}