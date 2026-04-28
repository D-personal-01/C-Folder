//Name- Daksh Joshi   Enrollment number-01414002026
//20. Sometimes a program requires two stacks containing the same type of items. Suppose two
//stacks are stored in separate arrays, then one stack might overflow while there is considerable
//unused space in the other. A neat way to avoid this problem is to put all spaces in one stack
//and let this stack grow from one end of the array, and the other stack starts from the other
//end and grows in the opposite direction, i.e., toward the first stack. In this way, if one stack
//turns out to be large and the other small, then they will still both fit, and there will be no
//overflow until all space is used. Declare a new structure that includes these two stacks and
//perform various stack operations.

#include <stdio.h>
#define MAX 100

struct twostack
{
    int arr[MAX];
    int top1;
    int top2;
};

void init(struct twostack *s)
{
    s->top1 = -1;
    s->top2 = MAX;
}

void push1(struct twostack *s, int x)
{
    if(s->top1 + 1 == s->top2)
    {
        printf("Overflow\n");
        return;
    }
    s->arr[++s->top1] = x;
}

void push2(struct twostack *s, int x)
{
    if(s->top1 + 1 == s->top2)
    {
        printf("Overflow\n");
        return;
    }
    s->arr[--s->top2] = x;
}

void pop1(struct twostack *s)
{
    if(s->top1 == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Popped from Stack1: %d\n", s->arr[s->top1--]);
}

void pop2(struct twostack *s)
{
    if(s->top2 == MAX)
    {
        printf("Underflow\n");
        return;
    }
    printf("Popped from Stack2: %d\n", s->arr[s->top2++]);
}

void display(struct twostack *s)
{
    printf("\nStack1: ");
    for(int i = 0; i <= s->top1; i++)
        printf("%d ", s->arr[i]);

    printf("\nStack2: ");
    for(int i = MAX-1; i >= s->top2; i--)
        printf("%d ", s->arr[i]);

    printf("\n");
}

int main()
{
    struct twostack s;
    init(&s);

    push1(&s, 10);
    push1(&s, 20);
    push2(&s, 100);
    push2(&s, 200);

    display(&s);

    pop1(&s);
    pop2(&s);

    display(&s);

    return 0;
}
