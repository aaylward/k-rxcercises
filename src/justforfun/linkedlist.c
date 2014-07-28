#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct LinkNode LinkNode;

struct LinkNode {
    int _value;
    LinkNode *_next;
};

struct LinkedList {
    int length;
    LinkNode *head;
};

LinkNode *newLink(int value) {
    LinkNode *p = malloc(sizeof(LinkNode));
    p->_value = value;
    p->_next = NULL;
    return p;
}

LinkedList *newList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->length = 0;
    list->head = NULL;
    return list;
}

void add(LinkedList *list, int value) {
    LinkNode *node = newLink(value);
    LinkNode *root = list->head;

    if (list->head == NULL) {
        list->head = node;
        list->length++;
        return;
    }

    while (root->_next != NULL) {
        root = root->_next;
    }

    root->_next = node;
    list->length++;
}

LinkNode *_prepend(LinkNode *old_root, LinkNode * new_root) {
    new_root->_next = old_root;
    return new_root;
}

void prepend(LinkedList *list, int value) {
    list->head = _prepend(list->head, newLink(value));
    list->length++;
}

void _traverse(LinkNode *list) {
    printf("value: %d\n", list->_value);
    if (list->_next) {
        _traverse(list->_next);
    }
}

/* prints the value of each node in order */
void traverse(LinkedList *list) {
    if (list->length) {
        _traverse(list->head);
    }
}

/* returns a new reversed linked list */
LinkedList *reversed(LinkedList *list) {
    LinkedList *reversed = newList();
    LinkNode *next = list->head;
    while (next != NULL) {
        prepend(reversed, next->_value);
        next = next->_next;
    }
    return reversed;
}

/* reverses a linked list in place (ish) */
void reverse(LinkedList *list) {
    if (list->head == NULL) {
        return;
    }

    LinkNode *new_head = NULL;
    LinkNode *next = list->head;
    LinkNode *tmp;
    while (next != NULL) {
        tmp = next->_next;
        new_head = _prepend(new_head, next);
        next = tmp;
    }

    list->head = new_head;
}

void destroy(LinkedList *list) {
    LinkNode *root = list->head;
    LinkNode *tmp;
    while (root != NULL) {
        tmp = root->_next;
        free(root);
        root = tmp;
    }

    free(list);
}

int main() {
    LinkedList *list = newList();
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);

    puts("forwards");
    traverse(list);

    reverse(list);

    puts("backwards");
    traverse(list);

    destroy(list);
    return 0;
}
