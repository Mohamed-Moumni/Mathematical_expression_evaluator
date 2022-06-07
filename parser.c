#include "header.h"
/*

<exp> := <term> { ("+" | "-") <term> }

<term> := <factor> { ("*" | "/") <factor> }

<factor> := <number>
        |   "(" <exp> ")"

<number> :: positive integer
*/

lexer *token = NULL;


Node *new_node(NodeType type, int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

Node    *expression(void)
{
    Node *tree;
    lexer tok;

    tree = NULL;
    if (token == NULL)
        return (tree);
    tree = term();
    tok = *token;
    while (tok.tokenType == PLUS || tok.tokenType == MINUS)
    {
        next_token();
        tree = new_node(tok.tokenType, tok.value, tree, term());
        tok = *token;
    }
    return (tree);
}

Node    *term(void)
{
    Node *tree;
    lexer tok;

    tree = NULL;
    tree = factor();
    tok = *token;
    while (tok.tokenType == MULT || tok.tokenType == DIV)
    {
        next_token();
        tree = new_node(tok.tokenType, tok.value, tree, factor());
        tok = *token;
    }
    return (tree);
}

Node    *factor(void)
{
    Node *tree;
    lexer tok;

    tree = NULL;
    tok = *token;
    if (token->tokenType == NUM)
    {
        tree = new_node(tok.tokenType, tok.value, NULL, NULL);
        next_token();
        return (tree);
    }
    else if (token->tokenType == LPAREN)
    {
        next_token();
        tree = expression();
        return (tree);
    }
    else
    {
        printf("syntax Error");
        return (NULL);
    }
    return (tree);
}

void    next_token(void)
{
    if (token == NULL)
        return ;
    token = token->next;
}

int     expect(lexer *token)
{
    if (token->tokenType == RPAREN)
    {
        next_token();
        return (1);
    }
    return (0);
}

Node *parser(char *s) {
    int i = 0;
    Node *ast;

    token = lexer_list(s);
    ast = expression();
    return (ast);
}

void    display(Node *ast)
{
    if (ast == NULL)
        return ;
    display(ast->left);
    display(ast->right);
    printf("%c\n",ast->value);
}

int main() {
    char *exp;
    exp = readline("Enter The expression \n");
    Node *ast = parser(exp);
    // token = lexer_list(exp);
    // // next_token();
    // while (token)
    // {
    //     printf("%c\n", token->value);
    //     token = token->next;
    // }
    display(ast);
}
