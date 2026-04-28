//Name- Daksh Joshi   Enrollment number-01414002026
//14. Write a C program to create two linked lists from a given list in following way INPUT List:- 1 2
//3 4 5 6 7 8 9 10 OUTPUT:- First List:- 1 3 5 7 9 Second List:- 2 4 6 8 10 (CO2)

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* original = NULL;
    struct node* oddList = NULL;
    struct node* evenList = NULL;

    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&original, x);
    }


    struct node* temp = original;
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            insertEnd(&oddList, temp->data);
        } else {
            insertEnd(&evenList, temp->data);
        }
        temp = temp->next;
    }


    printf("First List (Odd): ");
    display(oddList);

    printf("Second List (Even): ");
    display(evenList);

    return 0;
}
