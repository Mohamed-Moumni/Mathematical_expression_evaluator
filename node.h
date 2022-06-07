#ifndef NODE_H
#define NODE_H

typedef enum NodeType {
    UNK,
    NUM,
    PLUS,
    MINUS,
    MULT,
    DIV,
    LPAREN,
    RPAREN
} NodeType;

typedef struct Node {
    NodeType    type;
    int         value;
    struct Node *left;
    struct Node *right;
} Node;


Node    *new_node(NodeType type, int value, Node *left, Node *right);
Node    *expression(void);
Node    *term(void);
Node    *factor(void);
Node    *parser(char *s);
void    display(Node *ast);
#endif
