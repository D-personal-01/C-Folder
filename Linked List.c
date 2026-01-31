#include<stdio.h>
#include<stdlib.h>

struct student{

    int num;
    struct student *next;

};

struct student *h, *t, *tp;

void begin();
void end();
void display();

int main(){

    h=t=tp=NULL;
    int ch=0;


    while(ch!=6){
    printf("\n Enter 1 to insert value at the beginning of Linked list");
    printf("\n Enter 2 to insert value at the end of Linked list");
    printf("\n Enter 3 to display all values of Linked list");
    printf("\n Enter 4 to delete head node ");
    printf("\n Enter 5 to delete tail node ");
    printf("\n Enter 6 to Exit\n");


    scanf("%d",&ch);

    if (ch == 1) begin();

    else if (ch == 2) end();

    else if (ch == 3) display();

    else if (ch == 4) del_head();

    else if (ch == 5) del_tail();

    else return;}

    return 0;
}

void begin(){

    tp=(struct student *) malloc(sizeof(struct student));
    printf("\n Enter num:");
    scanf("%d",&tp->num);

    if (h==NULL){
        h=t=tp;
        h->next=NULL;
    }
    else{
        tp->next=h;
        h=tp;

    }

}

void end(){

    tp=(struct student *) malloc(sizeof(struct student));
    printf("\n Enter num:");
    scanf("%d",&tp->num);

    if (h == NULL){

        h=t=tp;
        t->next=NULL;

    }
    else{

        t->next=tp;
        t=tp;
        t->next=NULL;

    }
}

void display() {

    int i=0;
    if (h==NULL)
        printf("\n No linked list ");
    else{
        tp=h;
        while(tp){
            printf(" |%d|------>",tp->num);
            tp=tp->next;
            i++;}
    }
    printf("NULL\n\n");

    }

void del_head(){

    if (h==NULL)
        printf("\n There is no linked list");
    else{
        tp=h;
        h=h->next;
        free(tp);
    }
    if(h==NULL)
        t==NULL;

}

void del_tail(){

    if (t == NULL)
        printf("\n There is no linked list");

    else if(t==h){

        h=tp=NULL;
        free(t);

        }

    else{

        tp=h;

        while(tp->next!=t)
            tp=tp->next;

        free(t);
        t = tp;
        t->next = NULL;

        }
        }
