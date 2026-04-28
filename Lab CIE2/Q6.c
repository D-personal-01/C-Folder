//Name- Daksh Joshi E.no.- 01414002025
//6. WAP to implement a static D-Queue. (CO2)

#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int dq[MAX];
int front = -1, rear = -1;

void insertFront() {

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is Full\n");
        return;
    }
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    dq[front] = value;
    printf("Inserted at front: %d\n", value);
}

void insertRear() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is Full\n");
        return;
    }
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = value;
    printf("Inserted at rear: %d\n", value);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted from front: %d\n", dq[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted from rear: %d\n", dq[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }

    int i = front;
    printf("Deque: ");

    while (1) {
        printf("%d ", dq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Static Deque ---\n");
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
