#ifndef STDNODE_H
#define STDNODE_H

struct std_node
{
    int id;
    char name[30];
    struct std_node *next;
};

typedef struct std_node Node;
typedef Node* NodePtr;

#endif
