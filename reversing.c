#include <stdio.h>
#include <string.h>

int top = -1;
char stack[20];
int max = 20;
void push(char value)
{
    if (top==max-1)
        printf("\nStack is Overflow");
    else
        stack[++top] = value;
}
char pop()
{
    if (top==-1)
        printf("\nStack is Underflow");
    else
        return stack[top--];
}
int main()
{
    char value[20];

    // user inputs for the stack
    printf("\nEnter the word less than 20 charctors (ex:abcde): ");
    scanf("%s", &value);

    //word length 
    int len = strlen(value);

    // element push in the stack
    for (int i = 0; i < len; i++)

        push(value[i]);

    // reversing stack printing
    int j=0;
    printf("Reversed word: ");
    while (j<len){
        printf("%c", pop());
        j++;
    }
    printf("\n\n");
    return 0;
}