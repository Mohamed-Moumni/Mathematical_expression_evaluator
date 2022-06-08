#include "header.h"

int eval(Node *tree)
{
    if (!tree)
        return (0);
    if (!tree->left && !tree->right)
        return (tree->value - 48);
    int l = eval(tree->left);
    int r = eval(tree->right);
    return (operation(l, r, tree->type));
}

int operation(int a, int b, NodeType oper)
{
    if (oper == PLUS)
        return (a + b);
    if (oper == MINUS)
        return (a - b);
    if (oper == MULT)
        return (a * b);
    if (oper == DIV)
        return (a / b);
    return (0);
}