//Name- Daksh Joshi 
//E.no.- 01414002025
//WAP to implement Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct student{

    int num;
    struct student *next;

};

struct student *h;

void add();
void display();
void del();
void search();
void insertBegin();
void insertEnd();
void deleteFront();
void deleteEnd();

int main(){

    h=NULL;
    int ch=0;

    while(ch!=8){

        printf("\n===== Circular Linked List Menu =====");
        printf("\n1. Insert Node");
        printf("\n2. Display List");
        printf("\n3. Delete Specific Node");
        printf("\n4. Search Node");
        printf("\n5. Insert at Beginning");
        printf("\n6. Insert at End");
        printf("\n7. Delete Front");
        printf("\n8. Delete End");
        printf("\n9. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){

            case 1: add();
                    break;

            case 2: display();
                    break;

            case 3: del();
                    break;

            case 4: search();
                    break;

            case 5: insertBegin();
                    break;

            case 6: insertEnd();
                    break;

            case 7: deleteFront();
                    break;

            case 8: deleteEnd();
                    break;

            case 9: printf("\nProgram Ended\n");
                    break;

            default: printf("\nInvalid Choice\n");
        }
    }

    return 0;
}

void add(){

    struct student *tp1,*tp;

    tp=(struct student *) malloc(sizeof(struct student));

    printf("\nEnter num: ");
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

void insertBegin(){

    struct student *tp,*last;

    tp=(struct student *)malloc(sizeof(struct student));

    printf("\nEnter value: ");
    scanf("%d",&tp->num);

    if(h==NULL){

        h=tp;
        h->next=h;
    }

    else{

        last=h;

        while(last->next!=h)
            last=last->next;

        tp->next=h;
        last->next=tp;
        h=tp;
    }

    printf("\nNode inserted at beginning\n");
}

void insertEnd(){

    struct student *tp,*last;

    tp=(struct student *)malloc(sizeof(struct student));

    printf("\nEnter value: ");
    scanf("%d",&tp->num);

    if(h==NULL){

        h=tp;
        h->next=h;
    }

    else{

        last=h;

        while(last->next!=h)
            last=last->next;

        last->next=tp;
        tp->next=h;
    }

    printf("\nNode inserted at end\n");
}

void deleteFront(){

    if(h==NULL){

        printf("\nList is empty\n");
        return;
    }

    struct student *last=h;

    if(h->next==h){

        free(h);
        h=NULL;

        printf("\nFront node deleted\n");
        return;
    }

    while(last->next!=h)
        last=last->next;

    struct student *temp=h;

    h=h->next;
    last->next=h;

    free(temp);

    printf("\nFront node deleted\n");
}

void deleteEnd(){

    if(h==NULL){

        printf("\nList is empty\n");
        return;
    }

    struct student *curr=h;
    struct student *prev=NULL;

    if(h->next==h){

        free(h);
        h=NULL;

        printf("\nLast node deleted\n");
        return;
    }

    while(curr->next!=h){

        prev=curr;
        curr=curr->next;
    }

    prev->next=h;

    free(curr);

    printf("\nLast node deleted\n");
}

void display(){

    if (h == NULL){

        printf("\nNo linked list\n");
        return;
    }

    struct student *tp = h;

    printf("\nCircular Linked List:\n");

    do{

        printf("|%d|----->", tp->num);
        tp = tp->next;

    }while(tp != h);

    printf("(Back to first node)\n");
}

void del(){

    if (h == NULL){

        printf("\nThere is no linked list\n");
        return;
    }

    int value;

    printf("\nEnter the number you want to delete: ");
    scanf("%d",&value);

    struct student *curr = h;
    struct student *prev = NULL;

    if(h->num == value && h->next == h){

        free(h);
        h = NULL;

        printf("\nNode deleted\n");
        return;
    }

    if(h->num == value){

        while(curr->next != h)
            curr = curr->next;

        struct student *temp = h;

        h = h->next;
        curr->next = h;

        free(temp);

        printf("\nNode deleted\n");
        return;
    }

    prev = h;
    curr = h->next;

    while(curr != h){

        if(curr->num == value){

            prev->next = curr->next;
            free(curr);

            printf("\nNode deleted\n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("\nValue not found\n");
}

void search(){

    if(h==NULL){

        printf("\nList is empty\n");
        return;
    }

    int value,flag=0;

    printf("\nEnter value to search: ");
    scanf("%d",&value);

    struct student *tp=h;

    do{

        if(tp->num==value){

            flag=1;
            break;
        }

        tp=tp->next;

    }while(tp!=h);

    if(flag==1)
        printf("\nValue Found\n");

    else
        printf("\nValue Not Found\n");
}