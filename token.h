#ifndef TOKEN_H
#define TOKEN_H

typedef enum Tokens{
    NUM_TOKEN = 0,
    OPER_TOKEN = 1,
    LPAREN_TOKEN = 2,
    RPAREN_TOKEN = 3,
    UNKNOW_TOKEN = 4
} TokenType;

TokenType   scan_next_token(char *s, int *i);
void nextToken(char *s, int *i);
#endif