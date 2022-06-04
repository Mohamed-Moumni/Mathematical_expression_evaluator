#include "token.h"

TokenType   scan_next_token(char *s, int *i)
{
    // if (s[*i] == ' ')
    // {
    //     (*i)++;
    //     scan_next_token(s, i);
    // }
    if (s[*i] >= '0' && s[*i] <= '9')
    {
        (*i)++;
        return (NUM_TOKEN);
    }
    if (s[*i] == '*' || s[*i] == '+' || s[*i] == '-' || s[*i] == '\\')
    {
        (*i)++;
        return (OPER_TOKEN);
    }
    if (s[*i] == '(')
    {
        (*i)++;
        return (LPAREN_TOKEN);
    }
    if (s[*i] == ')')
    {
        (*i)++;
        return (RPAREN_TOKEN);
    }
    return (UNKNOW_TOKEN);
}


