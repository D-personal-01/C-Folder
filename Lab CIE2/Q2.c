//Name- Daksh Joshi E.no.- 01414002025
//2. Write a menu driven program to implement static stack (CO2)

#include <stdio.h>
#define MAX 150

int stack[MAX];
int top = -1;

void push() {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    int val;
   printf("Enter value: ");
   scanf("%d", &val);
    stack[++top] = val;
    printf("Pushed %d\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped %d\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
