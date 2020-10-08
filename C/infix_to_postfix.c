/* Infix to Postfix Conversion */

#include <stdio.h>
#include <string.h>
#include <math.h>
void post(char inf[], char postfix[]);
int pop();
void push(int n);
int arr[20];
int top = -1, var[256];
int main(void)
{
    char inf[20], postfix[20], c;
    int val;
    var['^'] = 5;
    var['*'] = 3;
    var['/'] = 3;
    var['+'] = 2;
    var['-'] = 2;
    var['('] = 1;
    printf("Enter the Infix expression\n");
    scanf("%s", inf);
    post(inf, postfix);
    printf("Postfix Expression: %s\n", postfix);
}
int pop()
{
    top--;
    return arr[top + 1];
}
void push(int n)
{
    top++;
    arr[top] = n;
}
void post(char inf[], char postfix[])
{
    int i = 0, j = 0, k = strlen(inf);
    push('(');
    inf[k] = ')';
    inf[k + 1] = '\0';
    while (inf[i] != '\0')
    {
        if (inf[i] == '(')
            push('(');
        else if (inf[i] >= 'a' && inf[i] <= 'z')
        {
            postfix[j] = inf[i];
            j++;
        }
        else if (inf[i] == '/' || inf[i] == '-' || inf[i] == '+' || inf[i] == '*' || inf[i] == '^')
        {
            if (arr[top] == '(')
                push(inf[i]);
            else
            {
                if (var[inf[i]] <= var[arr[top]])
                {
                    while (var[arr[top]] >= var[inf[i]])
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    push(inf[i]);
                }
                else
                    push(inf[i]);
            }
        }
        else if (inf[i] == ')')
        {
            while (arr[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            top--;
        }
        if (inf[i + 1] == '\0')
            postfix[j] = '\0';
        i++;
    }
}

/* Test Cases

a+b*(c^d-e)^(f+g*h)-i

a*(b+c)/d

Output:

abcd^e-fgh*+^*+i-

abc+*d/

*/
