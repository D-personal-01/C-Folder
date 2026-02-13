#include<stdio.h>
#include<stdlib.h>
struct stud{

    int roll;
    struct stud *next;

};

struct stud *head=NULL,*temp=NULL;



void display(){
    if(head==NULL){
        printf("\nThere is no list.\n");
        return;
    }
    temp=head;
    printf("\n");
    while(temp!=NULL){
        printf("%d-> ",temp->roll);
        temp=temp->next;
    }
    printf("NULL\n");
}



void add_b(){
    if (head==NULL){
        temp=(struct stud*)malloc(sizeof(struct stud));
        printf("\nEnter the roll number:");
        scanf("%d",&temp->roll);
        head=temp;
        head->next=NULL;
        return;
    }

    temp=(struct stud*)malloc(sizeof(struct stud));
    printf("\nEnter the roll number: ");
    scanf("%d",&temp->roll);
    temp->next=head;
    head=temp;

}

void add_e(){
    if (head==NULL){
        temp=(struct stud*)malloc(sizeof(struct stud));
        printf("\nEnter the roll number:");
        scanf("%d",&temp->roll);
        head=temp;
        head->next=NULL;
        return;
    }
    struct stud *temp1;
    temp=(struct stud*)malloc(sizeof(struct stud));
    printf("\nEnter the roll number: ");
    scanf("%d",&temp->roll);
    temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
    temp->next=NULL;
}


int main(){

    int c;
    head=NULL;
    printf("This is your Linked list Lets start!!\n\n");


    while(1){
        printf("\n\nWhat do you want to do:\n 1.Display Linked list\n 2.Add node at beginning\n 3.Add at the end.\n");
        printf("Enter your choice:");
        scanf("%d",&c);

    switch (c){

        case 1:
            display();
            break;
        case 2:
            add_b();
            break;
        case 3:
            add_e();
            break;
            }
}
}
