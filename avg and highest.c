#include <stdio.h>

void calculate(int marks[], int n)
{
    int i, highest;
    float sum = 0, average;

    highest = marks[0];

    for(i = 0; i < n; i++)
    {
        sum = sum + marks[i];
        if(marks[i] > highest)
            highest = marks[i];
    }

    average = sum / n;

    printf("Average marks: %.2f\n", average);
    printf("Highest mark: %d\n", highest);
}

int main()
{
    int n, i;
    int marks[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &marks[i]);

    calculate(marks, n);

    return 0;
}
