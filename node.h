#ifndef NODE_H
#define NODE_H

typedef enum NodeType {
    UNK,
    NUM,
    PLUS,
    MINUS,
    MULT,
    DIV
} NodeType;

typedef struct Node {
    NodeType    type;
    int         value;
    struct Node *left;
    struct Node *right;
} Node;
Node *new_leaf(Node **ast, int value, char *s, int *i);
Node *new_node(NodeType type, int value, Node *left, Node *right);
Node    *expression(Node **ast, char *s, int *i);
Node    *term(Node **ast, char *s, int *i);
Node    *factor(Node **ast, char *s, int *i);
Node    *parser(char *s);
void    display(Node *ast);
#endif
