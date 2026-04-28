
#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    int rollno;
    int marks[5];
    float avg;
    char result[5];
    struct student *next;
};

struct student *head = NULL;

void addStudent()
{
    struct student *n, *temp;
    n = (struct student*)malloc(sizeof(struct student));

    printf("Enter Name: ");
    scanf("%s", n->name);

    printf("Enter Roll No: ");
    scanf("%d", &n->rollno);

    int sum = 0;
    printf("Enter marks of 5 subjects:\n");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &n->marks[i]);
        sum += n->marks[i];
    }

    n->avg = sum / 5.0;

    if(n->avg < 50)
        strcpy(n->result, "Fail");
    else
        strcpy(n->result, "Pass");

    n->next = NULL;

    if(head == NULL)
    {
        head = n;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}

void display()
{
    struct student *temp = head;

    while(temp != NULL)
    {
        printf("\nName: %s", temp->name);
        printf("\nRoll No: %d", temp->rollno);

        printf("\nMarks: ");
        for(int i = 0; i < 5; i++)
            printf("%d ", temp->marks[i]);

        printf("\nAverage: %.2f", temp->avg);
        printf("\nResult: %s\n", temp->result);

        temp = temp->next;
    }
}

int main()
{
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        addStudent();
    }

    display();

    return 0;
}
