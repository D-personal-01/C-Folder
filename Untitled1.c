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
        printf("\nEnter the roll number: ");
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
    struct stud *temp1;
    if (head==NULL){
        temp=(struct stud*)malloc(sizeof(struct stud));
        printf("\nEnter the roll number: ");
        scanf("%d",&temp->roll);
        head=temp;
        head->next=NULL;
        return;
    }

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



void add_l(){
    int n,i;
    printf("Enter the index where the element has to be inserted: ");
    scanf("%d",&n);
    struct stud *temp1;
    if (head==NULL){
        temp=(struct stud*)malloc(sizeof(struct stud));
        printf("\nEnter the roll number:");
        scanf("%d",&temp->roll);
        head=temp;
        head->next=NULL;
        return;
    }
    temp1=head;
    for(i=1;i<=n-1;i++)
    {
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;

}

int main(){

    int c;
    head=NULL;
    printf("This is your Linked list Lets start!!\n\n");


    while(1){
        printf("\n\nWhat do you want to do: \n 1.Display Linked list\n 2.Add node at beginning\n 3.Add at the end.\n 4.Insert at specific location.\n 5.Delete at beginning.\n 6.Delete at End.\n 7.Delete at specific location.\n 8.Delete whole list. \n 9.Exit");
        printf("Enter your choice: ");
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
        case 4:
            add_l();
            break;
        case 5:
            del_b();
            break;
        case 6:
            del_e();
            break;
        case 7:
            del_l();
            break;
        case 8:

            while(head!=NULL)
            {
                temp=head;
                head=head->next;
                free(temp);
            }
        case 9:
            exit(0);

            }
}
}
