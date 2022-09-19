#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define BUFFERSIZE 128
 
 
typedef struct node{
    char* lastname;
    char* firstname;
    char* status;
    long ID;
    int year;
 
    struct node* next;
    struct node* prev;
 
} studentObject;
struct node* head = NULL;
struct node* tail = NULL;

/* Takes in a student object to be pushed to the end of the list, if the list is empty, set head and tail to student, if not, iterate to the end of the list
and push the new student node and setting tail to the new node*/
void push(studentObject *student){
    struct node* temp = head;
    if(head == NULL && tail == NULL){
        head = student;
        tail = student;
        student->next = NULL;
        student->prev = NULL;
    }
    else{
        temp = tail;
        temp->next = student;
        student->prev = temp;
        student -> next = NULL;
        tail = student;
    }
    return;
}
/* asks user for input: Student last name, student First name, student status, and student ID. Allocating memory for the last name, first namem
and for status. Afterwards, setting new student node with all attributes */
studentObject* addNewStudent(){
    studentObject *student;
    char ln[BUFFERSIZE];
    char fn[BUFFERSIZE];
    char stat[BUFFERSIZE];
    int len;
    printf("student last name: ");
     if (fgets(ln, BUFFERSIZE , stdin) != NULL){
         len = (int) strlen(ln);
         ln[len - 1] = '\0';
         student = (studentObject*) malloc(sizeof(studentObject));
         student->lastname = (char *) malloc(len);
         strcpy(student->lastname, ln);
     }
     printf("student first name: ");
     if (fgets(fn, BUFFERSIZE , stdin) != NULL){
         len = (int) strlen(fn);
         fn[len - 1] = '\0';
         student->firstname = (char *) malloc(len);
         strcpy(student->firstname, fn);
     }
     printf("student status: ");
     if (fgets(stat, BUFFERSIZE , stdin) != NULL){
         len = (int) strlen(stat);
         stat[len - 1] = '\0';
         student->status = (char *) malloc(len);
         strcpy(student->status, stat);
     }
     printf("new student id: ");
     scanf("%ld",&(student->ID));
     printf("new student graduation year: ");
     scanf("%d",&(student->year));
     printf("Successfully created student!\n");
     student->next=student->prev= NULL;
     push(student);
     return student;
};
//Prints list in order
void printIO(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%s, ", temp->firstname);
        temp = temp->next;
    }
}
//Prints list in reverse
void printIR(){
    struct node* temp = tail;
    while(temp != NULL){
        printf("%s, ", temp->firstname);
        temp = temp->prev;
    }
}
//free student info before removing from DLL
void freeStudent(studentObject *student){
    free(student->lastname);
    free(student->firstname);
    free(student->status);
    free(student);
}
//creates a node at the head and traverses the list until it finds the correct node, then deletes it
void deletestudent(){
    struct node* temp = head;
    char findMe[BUFFERSIZE];
    printf("Enter student last name to be deleted: ");
    scanf("%s", findMe);
    while(temp){
        if (strcmp(temp->lastname,findMe)){
            temp = temp->next;
        }
        break;
    }
    struct node* temp2 = temp;
    if(temp->prev == NULL){
        head = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    freeStudent(temp);
    return;
}
 
 
void deleteList(){
    struct node* temp = head;
    while(temp != NULL){
        struct node* temp2=temp;
        temp = temp->next;
        free(temp2->lastname);
        free(temp2->firstname);
        free(temp2->status);
        free (temp2);
    }
    head = tail = NULL;
}
/* Creates endless loop for user to choose between 5 options of what they would like to do, choosing 5 ends the program and returns*/
int main()
{   
    char input[BUFFERSIZE];
    int dontStop = 1;
    while(dontStop == 1){
        printf("Please Choose an Option\n");
        printf("=============================================\n");
        printf("Use (1) to add student to list\n");
        printf("Use (2) to delete a student from list\n");
        printf("Use (3) to print the list from the start\n");
        printf("Use (4) to print the list in reverse\n");
        printf("Use (5) to exit the application and wipe list\n");
        printf("=============================================\n");
        fgets(input, BUFFERSIZE , stdin);
        if(input[0] == '1'){
            addNewStudent();
        }
        else if(input[0] == '2'){
            deletestudent();
        }
        else if(input[0] == '3'){
            printf("Students in order: ");
            printIO();
            printf("\n");
            printf("\n");
        }
        else if(input[0] == '4'){
            printf("Students in reverse order: ");
            printIR();
            printf("\n");
            printf("\n");
        }
        else if(input[0] == '5'){
            deleteList();
            printf("removed all students... exiting");
            break;
        }
    }
    return 0;
}
 
// check all instances of delete node, like if the node is tail, and head, only head or only tail, OR just null. Delete each one. 
// FREE(temp->lastname, firstname, status,).
// use temp variable to hold places. 

