//Name- Daksh Joshi E.no.- 01414002025
//4. WAP to implement a Static Circular Queue (CO2)

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (front == (rear + 1) % MAX) {
        printf("Queue is Full\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue ---\n");
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
}
