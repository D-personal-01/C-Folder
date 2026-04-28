//Name- Daksh Joshi   Enrollment number-01414002026
//19. WAP to implement an expression tree. (For example: (a + b / (c * d) – e) )

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node
{
    char data;
    struct node *left, *right;
};

struct node* newNode(char x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* stack[100];
int top = -1;

void push(struct node* x)
{
    stack[++top] = x;
}

struct node* pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    char s[100];
    int top2 = -1, k = 0;

    for(int i = 0; infix[i]; i++)
    {
        if(isalnum(infix[i]))
            postfix[k++] = infix[i];
        else if(infix[i] == '(')
            s[++top2] = '(';
        else if(infix[i] == ')')
        {
            while(s[top2] != '(')
                postfix[k++] = s[top2--];
            top2--;
        }
        else
        {
            while(top2 != -1 && priority(s[top2]) >= priority(infix[i]))
                postfix[k++] = s[top2--];
            s[++top2] = infix[i];
        }
    }

    while(top2 != -1)
        postfix[k++] = s[top2--];

    postfix[k] = '\0';
}

struct node* buildTree(char postfix[])
{
    for(int i = 0; postfix[i]; i++)
    {
        if(isalnum(postfix[i]))
        {
            push(newNode(postfix[i]));
        }
        else
        {
            struct node* t = newNode(postfix[i]);
            t->right = pop();
            t->left = pop();
            push(t);
        }
    }
    return pop();
}

void inorder(struct node* root)
{
    if(root)
    {
        if(!isalnum(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if(!isalnum(root->data)) printf(")");
    }
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    struct node* root = buildTree(postfix);

    printf("Postfix: %s\n", postfix);

    printf("Inorder Traversal (Expression): ");
    inorder(root);

    return 0;
}
