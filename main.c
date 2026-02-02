#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, char *argv[])
{
    NodePtr head = NULL;
    NodePtr temp = NULL;
    NodePtr tmp = NULL;
    int n, i;

    n = (argc - 1) / 2;
    if (n <= 0) return 0;

    head = malloc(sizeof(Node));
    temp = head;

    for (i = 0; i < n; i++)
    {
        temp->id = atoi(argv[1 + i * 2]);
        strcpy(temp->name, argv[2 + i * 2]);

        if (i < n - 1)
        {
            temp->next = malloc(sizeof(Node));
            temp = temp->next; }
        else
        {
            temp->next = NULL;
        }
    }

    tmp = head;
    while (tmp)
    {
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

    tmp = head;
    while (tmp)
    {
        head = tmp->next;
        free(tmp);
        tmp = head;
    }

    return 0;
}
