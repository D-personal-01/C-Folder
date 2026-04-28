//Name- Daksh Joshi   Enrollment number-01414002026
//16. Write a program to convert Infix to equivalent (i) Prefix expression (ii) Postfix expression.
//(CO1, CO2)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    char exp[100];
    strcpy(exp, infix);   // FIX: copy instead of modifying original

    int i = 0, k = 0;
    char ch;

    push('(');
    strcat(exp, ")");

    while(exp[i] != '\0')
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(isalnum(exp[i]))
            postfix[k++] = exp[i];
        else if(exp[i] == ')')
        {
            while((ch = pop()) != '(')
                postfix[k++] = ch;
        }
        else
        {
            while(priority(stack[top]) >= priority(exp[i]))
                postfix[k++] = pop();
            push(exp[i]);
        }
        i++;
    }
    postfix[k] = '\0';
}

void reverse(char exp[])
{
    int i, j;
    char temp;
    int len = strlen(exp);

    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    char temp[100];
    strcpy(temp, infix);

    reverse(temp);

    for(int i = 0; temp[i]; i++)
    {
        if(temp[i] == '(') temp[i] = ')';
        else if(temp[i] == ')') temp[i] = '(';
    }

    char postfix[100];
    top = -1;
    infixToPostfix(temp, postfix);

    reverse(postfix);
    strcpy(prefix, postfix);
}

int main()
{
    int choice;
    char infix[100], postfix[100], prefix[100];

    while(1)
    {
        printf("\n1. Infix to Postfix");
        printf("\n2. Infix to Prefix");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 3)
            break;

        printf("Enter Infix: ");
        scanf("%s", infix);

        if(choice == 1)
        {
            top = -1;
            infixToPostfix(infix, postfix);
            printf("Postfix = %s\n", postfix);
        }
        else if(choice == 2)
        {
            infixToPrefix(infix, prefix);
            printf("Prefix = %s\n", prefix);
        }
        else
            printf("Invalid choice\n");
    }

    return 0;
}
