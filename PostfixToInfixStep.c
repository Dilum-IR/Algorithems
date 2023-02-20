// This Scenario use in a Stack Algorithems.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For Stack to push the charactors.
void push(char);

// Use for the Operators.
void AD();
void SB();
void ML();
void DV(char);
// Create tempn variables.
void temp_create();

// this is a Registration stack
char registers[20];
int top1 = -1;
int j = 0;

// For charactor numbers push into the Stack (1,2,3,4,...) >>> Make for Temp1,Temp2,Temp3,...
char c, l = 48; // 48 is a number 1's ASCII value

int ST;
char temp;

int main()
{
    // User Input the postfix expression.
    // postfix expression containing single-letter operands.

    char num[20];
    // User manual printing the CMD.
    printf("\n---------------------- Postfix Expression TO Infix Expression Program----------------------\n");
    printf("\n*****  <<<<<<<<<<<<<<<<<<<  IMPORTANT >>>>>>>>>>>>>>>>>\n       1. Postfix expression containing single-letter operands \n       2. For Operands use the alphabet charactors only \n**************************************************************");
    printf("\nEnter the Postfix Expression : ");
    scanf("%s", &num);

    // "num" > String value Itterate the one by one for the Spliting.

    for (int i = 0; i < strlen(num); i++)
    {
        // c is a char type variabel. c to asign the "num" String value charactors.
        // This is useing for the Easy.
        c = num[i];

        // Find the operands for Push to the stack.
        if (c >= 97 && c <= 122 || c >= 65 && c <= 90)
            push(c);

        // When c is a '*', Call for ML Funciton.
        else if (c == '*')
            ML(c);

        // When c is a '/', Call for DV Funciton.
        else if (c == '/')
            DV(c);

        // When c is a '+', Call for AD Funciton.
        else if (c == '+')
            AD(c);

        // When c is a '-', Call for SB Funciton.
        else if (c == '-')
            SB(c);

        // If User input is Invalid,then else part to come.
        else
            printf("Invalid operations\n");
    }
    return 0;
}
// For Stack to push the charactor values.
void push(char c)
{
    registers[++top1] = c;
}
void pop(char c)
{
    char LD;
    LD = registers[top1--];

    if (LD > 48 && LD <= 57)
        printf("LD\tTemp%c\n", LD);

    else
        printf("LD\t%c\n", LD);
}
// Create tempn variables in this function.
void temp_create()
{
    j++;
    printf("ST\tTemp%d\n", j);
    ST = j;
}

// ML Function is useing for Multiplication the Stack top Two operands
void ML()
{
    char MLt;

    MLt = registers[top1--];
    pop(c);
    if (MLt > 48 && MLt <= 57)
        printf("ML\tTemp%c\n", MLt);

    else
        printf("ML\t%c\n", MLt);

    // temp is showing the LD & ML value multiplication
    registers[++top1] = ++l;
    temp_create();
}

// DV Function is useing for Division the Stack top Two operands
void DV(char num)
{
    char DVt = registers[top1--];
    pop(c);
    if (DVt > 48 && DVt <= 57)
        printf("DV\tTemp%c\n", DVt);

    else
        printf("DV\t%c\n", DVt);

    registers[++top1] = ++l;
    temp_create();
}

// AD Function is useing for Add the Stack top Two operands
void AD()
{
    char ADt;

    ADt = registers[top1--];
    pop(c);

    if (ADt > 48 && ADt <= 57)
        printf("AD\tTemp%c\n", ADt);

    else
        printf("AD\t%c\n", ADt);

    registers[++top1] = ++l;
    temp_create();
}

// SB Function is useing for Substraction the Stack top Two operands
void SB()
{
    char SBt;

    SBt = registers[top1--];
    pop(c);
    if (SBt > 48 && SBt <= 57)
        printf("SB\tTemp%c\n", SBt);

    else
        printf("SB\t%c\n", SBt);

    registers[++top1] = ++l;
    temp_create();
}
