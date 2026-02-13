#include<stdio.h>

struct stud{

    int roll;
    struct stud *next;

};

struct stud *head=NULL,*temp=NULL;

void display(){
if(head==NULL){
        printf("There is no list.\n");
}
 temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->roll);
    }
}

void begi(){
    if (head==NULL){
        temp=(struct stud*)malloc(sizeof(struct stud));
        head=temp;
        return;
    }

    temp=(struct stud*)malloc(sizeof(struct stud));
    scanf("%d",temp->roll);
    temp->next=head;
    head=temp;

}



int main(){

    int c;
    head=NULL;
    printf("This is your Linked list Lets start!!\n\n");

    printf("What do you want to do:\n 1.Display Linked list\n 2.Add node at beginning\n 3.Add at the end.\n");
    printf("Enter your choice:");
    scanf("%d",&c);
    while(temp){

    switch (c){

        case 1:
            display();
            break;
        case 2:
            begi();
            break;
            }
}
}
