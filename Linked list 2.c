//Name- Daksh Joshi E.no.- 01414002025
//2. WAP to implement a Singly Linked List.

#include<stdio.h>
#include<stdlib.h>

struct stud {
    int roll;
    struct stud *next;
};

struct stud *head = NULL;


void display() {
    struct stud *temp = head;

    if (head == NULL) {
        printf("\nThere is no list.\n");
        return;
    }

    printf("\n");
    while (temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}


void add_b() {
    struct stud *newnode = (struct stud*)malloc(sizeof(struct stud));

    if (!newnode) return;

    printf("\nEnter roll number: ");
    scanf("%d", &newnode->roll);

    newnode->next = head;
    head = newnode;
}


void add_e() {
    struct stud *newnode = (struct stud*)malloc(sizeof(struct stud));
    struct stud *temp;

    if (!newnode) return;

    printf("\nEnter roll number: ");
    scanf("%d", &newnode->roll);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}


void add_l() {
    int pos, i;
    struct stud *newnode, *temp;

    printf("Enter position (starting from 1): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct stud*)malloc(sizeof(struct stud));
    if (!newnode) return;

    printf("Enter roll number: ");
    scanf("%d", &newnode->roll);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void del_b() {
    struct stud *temp;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}


void del_e() {
    struct stud *temp, *prev;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}


void del_l() {
    int pos, i;
    struct stud *temp, *prev;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        del_b();
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void delete_all() {
    struct stud *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("All nodes deleted.\n");
}


int main() {

    int c;

    while (1) {

        printf("\n1.Display\n2.Add at beginning\n3.Add at end\n4.Insert at location\n5.Delete beginning\n6.Delete end\n7.Delete location\n8.Delete whole list\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c) {

            case 1: display(); break;
            case 2: add_b(); break;
            case 3: add_e(); break;
            case 4: add_l(); break;
            case 5: del_b(); break;
            case 6: del_e(); break;
            case 7: del_l(); break;
            case 8: delete_all(); break;
            case 9: delete_all(); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
