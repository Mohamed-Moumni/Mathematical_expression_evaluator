#ifndef LEXER_H
#define LEXER_H

typedef struct lexer
{
    NodeType tokenType;
	int			value;
    struct lexer *next;
}lexer;

NodeType    get_token_type(char c);
lexer		*new_lexer_node(NodeType tokenType, int value);
int			is_digits(char c);
lexer       *lex_add_back(lexer *lex, lexer *new);
void		next_token(void);
lexer		*lexer_list(char *exp);
void		free_token_list(lexer **lex);
int     expect(lexer *token);

#endif