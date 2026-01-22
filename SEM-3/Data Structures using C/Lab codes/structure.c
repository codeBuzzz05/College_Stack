#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int size;
struct student{
  char name[30];
  char usn[30];
  char dept[30];
  int marks;
};
struct student* s;

void initialise(){
  s=(struct student*)malloc(size*sizeof(struct student));
  if(s==NULL){
    printf("Allocation failed\n");
    return ;
  }
}
void addStudent(){
  for(int i=0;i<size;i++){
    printf("Enter Details of student %d\n",i+1);
    printf("Enter Name\n");
    scanf("%s",s[i].name);
    printf("Enter usn\n");
    scanf("%s",s[i].usn);
    printf("Enter department\n");
    scanf("%s",s[i].dept);
    printf("Enter total marks\n");
    scanf("%d",&s[i].marks);
  }
  printf("Students data stored successfully");
}
void display(){
    printf("student details:\n");
    for(int i=0;i<size;i++){
        printf("Student name : %s  USN : %s  Department : %s  Marks : %d \n",s[i].name,s[i].usn,s[i].dept,s[i].marks);
    }
}
void search(){
    char key[30];
    printf("Enter the student USN\n");
    scanf("%s",key);
    for(int i=0;i<size;i++){
        if(strcmp(key,s[i].usn)==0){
            printf("Student details found in the database:\n");
            printf("Student name : %s  USN : %s  Department : %s  Marks : %d \n",s[i].name,s[i].usn,s[i].dept,s[i].marks);
            return ;
        }
    }
    printf("Student details not found, check USN\n");
}

int main(){
    printf("Enter number of students to store\n");
    scanf("%d",&size);
    initialise();
    addStudent();
    display();
    search();
    return 0;
}