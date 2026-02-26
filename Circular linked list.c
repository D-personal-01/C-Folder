//Name- Daksh Joshi E.no.- 01414002025
//3. WAP to implement a Circular Linked Lists.

#include<stdio.h>
#include<stdlib.h>

struct student{

    int num;
    struct student *next;


};

struct student *h;

void add();
void display();

int main(){

    h=NULL;
    int ch=0;


    while(ch!=6){
    printf("\n Enter 1 to insert value ");
    printf("\n Enter 2 to display all values of Circular Linked list");
    printf("\n Enter 3 to delete node ");
    printf("\n Enter 4 to Exit\n");

    printf("\n Enter the choice: ");
    scanf("%d",&ch);

    if (ch == 1) add();

    else if (ch == 2) display();

    else if (ch == 3) del();

    else return 0;}

    return 0;
}

void add(){
    struct student *tp1,*tp;
    tp=(struct student *) malloc(sizeof(struct student));
    printf("\n Enter num:");
    scanf("%d",&tp->num);

    if (h==NULL){
        h=tp;
        h->next=h;
    }
    else{
        tp1=h->next;
        tp->next=tp1;
        h->next=tp;

    }

}


void display() {

    if (h == NULL){
        printf("\n No linked list\n");
        return;
    }

    struct student *tp = h;

    do{
        printf(" |%d|------>", tp->num);
        tp = tp->next;
    }while(tp != h);

    printf("(back to the first)\n\n");
}


void del(){

    if (h == NULL){
        printf("\nThere is no linked list\n");
        return;
    }

    int value;
    printf("Enter the number you want to delete: ");
    scanf("%d",&value);

    struct student *curr = h;
    struct student *prev = NULL;

    if(h->num == value && h->next == h){
        free(h);
        h = NULL;
        return;
    }

    if(h->num == value){
        while(curr->next != h)
            curr = curr->next;

        struct student *temp = h;
        h = h->next;
        curr->next = h;
        free(temp);
        return;
    }

    prev = h;
    curr = h->next;

    while(curr != h){
        if(curr->num == value){
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Value not found\n");
}
