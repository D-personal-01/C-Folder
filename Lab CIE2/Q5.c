//Name- Daksh Joshi E.no.- 01414002025
//5. WAP to implement a Dynamic Circular Queue (CO2)
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Dynamic Circular Queue ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
