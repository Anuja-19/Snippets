#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left,*right;
};

void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node *create_expression_tree(char *exp); // pass the char array (the postfix expression)
int isOperator(char ch); // check if ch is an operator
void push(struct node **s, int *t, struct node *temp);
struct node *pop(struct node **s, int *t);
int eval(struct node *root);

int main()
{
    struct node *root = NULL;
    char exp[100];
    int result;
    printf("\n\n***** EXPRESSION TREE *****\n");
    printf("Enter postfix expression : ");
    scanf("%s",exp);

    root = create_expression_tree(exp);

    printf("\nPreorder : ");
    preorder(root);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);

    result = eval(root);
    printf("\nThe expression evaluates to : %d\n",result);
    return 0;
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }

}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}

struct node *create_expression_tree(char *exp) // pass the postfix expression
{
    char ch;
    struct node *stack[100];
    int top = -1;
    int i=0;

    struct node *temp;

    while(exp[i] != '\0')
    {
        ch = exp[i];
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->data = ch;

        if(isOperator(ch))
        {
            temp->right = pop(stack,&top);
            temp->left = pop(stack,&top);
            push(stack,&top,temp);
        }
        else
            push(stack,&top,temp);
        i++;
    }
    return pop(stack,&top);
}


int eval(struct node *root) // recursive function
{
    int x;
    switch(root->data)
    {
        case '+': return(eval(root->left) + eval(root->right));
        case '-': return(eval(root->left) - eval(root->right));
        case '*': return(eval(root->left) * eval(root->right));
        case '/': return(eval(root->left) / eval(root->right));
        default: printf("%c = ",root->data);
        scanf("%d",&x);
        return x;
    }
}

void push(struct node **s, int *t, struct node *temp)
{
    ++(*t);
    s[*t] = temp;
}

struct node *pop(struct node **s, int *t)
{
    struct node *temp = s[*t];
    (*t)--;
    return temp;
}

int isOperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default: return 0;
    }
}
