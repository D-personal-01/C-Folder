//Name- Daksh Joshi E.no.- 01414002025
//7. WAP to implement a dynamic D-Queue. (CO2)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Overflow\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    printf("Inserted at front: %d\n", value);
}

void insertRear() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Overflow\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }

    printf("Inserted at rear: %d\n", value);
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted from front: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted from rear: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deque: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Dynamic Deque ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertRear();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
