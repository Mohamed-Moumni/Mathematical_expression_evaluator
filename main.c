#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "node.h"

int main(void)
{
    char *expression;
    
    expression = readline("Enter The Expression !");

    while (expression != NULL)
    {
        expression = readline("Enter The Expression !");
    }
}