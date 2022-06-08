#include "header.h"


int is_digits(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
lexer   *new_lexer_node(NodeType tokenType, int value)
{
    lexer   *node;

    node = (lexer *)malloc(sizeof(lexer));
    if (!node)
        return (NULL);
    node->tokenType = tokenType;
    node->value = value;
    node->next = NULL;
    return (node);
}


NodeType    get_token_type(char c)
{
    if (is_digits(c))
        return (NUM);
    if (c == '+')
        return (PLUS);
    if (c == '-')
        return (MINUS);
    if (c == '/')
        return (DIV);
    if (c == '*')
        return (MULT);
    if (c == '(')
        return (LPAREN);
    if (c == ')')
        return (RPAREN);
    return (UNK);
}

void	free_token_list(lexer **lex)
{
	lexer *current;
	lexer *next_elm;

	current = *lex;
	while (current != NULL)
	{
		next_elm = current->next;
		free(current);
		current = next_elm;
	}
    *lex = NULL;
}

lexer   *lex_add_back(lexer *lex, lexer *new)
{
    lexer *tmp;

    if (lex == NULL)
        return (new);
    tmp = lex;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (lex);
}

lexer   *lexer_list(char *exp)
{
    int i;
    lexer   *lex;

    i = 0;
    lex = NULL;
    while (exp[i])
    {
        if (get_token_type(exp[i]) == UNK)
        {
            free_token_list(&lex);
            return (NULL);
        }
        lex = lex_add_back(lex, new_lexer_node(get_token_type(exp[i]), exp[i]));
        i++;
    }
    return (lex);
}

// int main(void)
// {
//     char *exp;
//     lexer *lex;

//     exp = readline("Enter Expression !");
//     // printf("here\n");
//     lex = lexer_list(exp);
//     lexer *tmp;

//     tmp = lex;
//     while (tmp != NULL)
//     {
//         printf("%d\n", tmp->tokenType);
//         tmp = tmp->next;
//     }
//     return (0);
// }
