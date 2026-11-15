#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    char *str;
    int length;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *first;
    Node *last;
    int total;
} Lines;

Lines *newLines(void);
Node *newNode(const char *str);

int deleteLast(Lines *list);
int order_insert(Lines *list, const char *str, const int limit);
int insert(Lines *list, const char *str);
int deleteFirst(Lines *list);
void deleteLines(Lines *list);
int printLines(Lines *list);

#endif