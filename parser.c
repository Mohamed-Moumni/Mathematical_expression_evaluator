#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "node.h"
#include "token.h"
// #include <>

/*

<exp> := <term> { ("+" | "-") <term> }

<term> := <factor> { ("*" | "/") <factor> }

<factor> := <number>
        |   "(" <exp> ")"

<number> :: positive integer
*/

TokenType tok;

Node *new_node(NodeType type, int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

Node *new_leaf(Node **ast, int value, char *s, int *i)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = NUM;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    if (*ast == NULL)
        *ast = node;
    else
    {
        int count;

        count = (*i);
        if (s[count--] == '+' || s[count--] == '-')
            (*ast)->right = node;
        else
            (*ast)->left = node;
    }
    return (*ast);
}

Node    *expression(Node **ast, char *s, int *i)
{
    Node    *tree1;

    *ast = term(ast, s, i);
    while (s[*i] == '+' || s[*i] == '-')
    {
        if (s[*i] == '+')
        {
            tok = scan_next_token(s, i);
            tree1 = term(ast, s, i);
            *ast = new_node(PLUS, 43, *ast, tree1);
        }
        if (s[*i] == '-')
        {
            tok = scan_next_token(s, i);
            tree1 = term(ast, s,i);
            *ast = new_node(MINUS, 45, *ast, tree1);
        }
    }
    return (*ast);
}

Node    *term(Node **ast, char *s, int *i)
{
    Node *tree1;
    *ast = factor(ast, s, i);
    while (s[*i] == '*' || s[*i] == '\\')
    {
        if (s[*i] == '*')
        {
            tok = scan_next_token(s, i);
            tree1 = factor(ast, s, i);
            *ast = new_node(MULT, 42, *ast, tree1);
        }
        if (s[*i] == '\\')
        {
            tok = scan_next_token(s, i);
            tree1 = factor(ast, s, i);
            *ast = new_node(DIV, 47, *ast, tree1);
        }
    }
    return (*ast);
}

Node    *factor(Node **ast, char *s, int *i)
{
    Node *tree1;

    if (s[*i] >= '0' && s[*i] <= '9')
    {
        *ast = new_leaf(ast, (s[*i] - '0'), s, i);
        tok = scan_next_token(s, i);
    }
    if (s[*i] == '(')
    {
        tok = scan_next_token(s,i);
        *ast = expression(ast, s, i);
        if (s[*i] == ')')
            return (NULL);
    }
    return (*ast);
}

Node *parser(char *s) {
    int i;

    i = 0;
    Node *ast;
    ast = NULL;
    ast = expression(&ast, s, &i);
    return (ast);
}

void    display(Node *ast)
{
    if (ast == NULL)
        return ;
    display(ast->left);
    display(ast->right);
    printf("%d\n",ast->value);
}
int main() {
    char *exp;
    exp = readline("Enter The expression \n");
    Node *ast = parser(exp);
    display(ast);
}
