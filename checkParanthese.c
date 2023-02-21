#include <stdio.h>
#include <string.h>

int top=-1,max=10;
char stack[20];
int sign=1;
void push(char charactor){

    if (top==max-1)
        printf("Stack is Overflow\n");
    else
        stack[++top] = charactor;
}
char pop(){

    if (top==-1)
       sign=1;
    else
        return stack[top--];
}
int main(){
     
    char array[20];
    printf("\n\n-------------check balanced parentheses in expression-------------\n\n");
    printf("Enter your parentheses : ");
    scanf("%s",&array);

    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i]=='(' || array[i]=='{' || array[i]=='[')
        {
            push(array[i]);
        }
        else if (array[i]==')' || array[i]=='}' || array[i]==']')
        {
            char temp = pop();
            if (temp=='(' && array[i]==')')
                sign=0;

            else if (temp=='{' && array[i]=='}')
                sign=0;

            else if (temp=='[' && array[i]==']')
                sign=0;                  
        } 
           
    }
    if (sign==0 && top==-1)
        printf("Your parentheses balance\n\n");
    else
        printf("Your parentheses Unbalance\n\n");
    return 0;
}

