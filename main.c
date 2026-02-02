#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, char *argv[])
{
    NodePtr head = NULL;
    NodePtr current = NULL;
    NodePtr iter = NULL;
    int n, i;

    n = (argc - 1) / 2;
    if (n <= 0)
        return 0;

    head = (NodePtr)malloc(sizeof(Node));
    if (head == NULL)
        return 1;

    current = head;

    for (i = 0; i < n; i++)
    {
        current->id = atoi(argv[1 + i * 2]);
        strcpy(current->name, argv[2 + i * 2]);

        if (i != n - 1)
        {
            current->next = (NodePtr)malloc(sizeof(Node));
            current = current->next;
        }
        else
        {
            current->next = NULL;
        }
    }

    iter = head;
    while (iter != NULL)
    {
        printf("%d %s\n", iter->id, iter->name);
        iter = iter->next;
    }

    iter = head;
    while (iter != NULL)
    {
        head = iter->next;
        free(iter);
        iter = head;
    }

    return 0;
}
