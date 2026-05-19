//Name- Daksh Joshi 
//E.no.- 01414002025
//4. WAP to implement Doubly Linked Lists.

#include<stdio.h>
#include<stdlib.h>

struct student{
    int num;
    struct student *prev;
    struct student *next;
};

struct student *head = NULL;

void insert_begin();
void insert_end();
void display_forward();
void display_backward();
void delete_node();
void delete_front();
void delete_end();

int main(){

    int ch;

    while(1){

        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Display forward");
        printf("\n4. Display backward");
        printf("\n5. Delete specific node");
        printf("\n6. Delete front node");
        printf("\n7. Delete end node");
        printf("\n8. Exit\n");

        printf("\nEnter the choice: ");
        scanf("%d",&ch);

        switch(ch){

            case 1: insert_begin();
                    break;

            case 2: insert_end();
                    break;

            case 3: display_forward();
                    break;

            case 4: display_backward();
                    break;

            case 5: delete_node();
                    break;

            case 6: delete_front();
                    break;

            case 7: delete_end();
                    break;

            case 8: return 0;

            default: printf("Invalid choice\n");
        }
    }
}

void insert_begin(){

    struct student *temp = (struct student*)malloc(sizeof(struct student));

    printf("Enter number: ");
    scanf("%d",&temp->num);

    temp->prev = NULL;
    temp->next = head;

    if(head != NULL)
        head->prev = temp;

    head = temp;
}

void insert_end(){

    struct student *temp = (struct student*)malloc(sizeof(struct student));

    printf("Enter number: ");
    scanf("%d",&temp->num);

    temp->next = NULL;

    if(head == NULL){

        temp->prev = NULL;
        head = temp;
        return;
    }

    struct student *ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
}

void display_forward(){

    if(head == NULL){

        printf("List empty\n");
        return;
    }

    struct student *ptr = head;

    while(ptr != NULL){

        printf("|%d| <-> ", ptr->num);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

void display_backward(){

    if(head == NULL){

        printf("List empty\n");
        return;
    }

    struct student *ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    while(ptr != NULL){

        printf("|%d| <-> ", ptr->num);
        ptr = ptr->prev;
    }

    printf("NULL\n");
}

void delete_node(){

    if(head == NULL){

        printf("List empty\n");
        return;
    }

    int value;

    printf("Enter value to delete: ");
    scanf("%d",&value);

    struct student *ptr = head;

    while(ptr != NULL && ptr->num != value)
        ptr = ptr->next;

    if(ptr == NULL){

        printf("Value not found\n");
        return;
    }

    if(ptr == head){

        head = ptr->next;

        if(head != NULL)
            head->prev = NULL;
    }

    else{

        ptr->prev->next = ptr->next;

        if(ptr->next != NULL)
            ptr->next->prev = ptr->prev;
    }

    free(ptr);

    printf("Node deleted\n");
}

void delete_front(){

    if(head == NULL){

        printf("List empty\n");
        return;
    }

    struct student *temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);

    printf("Front node deleted\n");
}

void delete_end(){

    if(head == NULL){

        printf("List empty\n");
        return;
    }

    struct student *ptr = head;

    if(head->next == NULL){

        free(head);
        head = NULL;

        printf("End node deleted\n");
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;

    free(ptr);

    printf("End node deleted\n");
}