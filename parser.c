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
    Node    *tree;
    lexer   tok;

    tree = NULL;
    tree = term();
    if (token == NULL)
        return (tree);
    while (token->tokenType == PLUS || token->tokenType == MINUS)
    {
        tok = *token;
        next_token();
        tree = new_node(tok.tokenType, tok.value, tree, term());
        if (token == NULL)
            return (tree);
    }
    // printf("expression--------%c-------->\n",token->value);
    return (tree);
}

Node    *term(void)
{
    Node *tree;
    lexer tok;

    tree = NULL;
    tree = factor();
    if (token == NULL)
        return (tree);
    while (token->tokenType == MULT || token->tokenType == DIV)
    {
        tok = *token;
        next_token();
        tree = new_node(tok.tokenType, tok.value, tree, factor());
        if (token == NULL)
            return (tree);
    }
    // printf("term--------%c-------->\n",token->value);
    return (tree);
}

Node    *factor(void)
{
    Node *tree;

    tree = NULL;
    if (token == NULL)
        return (tree);
    if (accept(NUM))
    {
        tree = new_node(token->tokenType, token->value, NULL, NULL);
        next_token();
    }
    else if(accept(LPAREN))
    {
        next_token();
        tree = expression();
        expect(token);
    }
    else
    {
        printf("Synatxe Error!");
        next_token();
    }
    // printf("factor--------%c-------->\n",token->value);
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

int accept(NodeType tok)
{
    if (tok == token->tokenType)
        return 1;
    return 0;
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
    // display(ast);
    int result = eval(ast);
    printf("%d\n",result);
}
