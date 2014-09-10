#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct SingleLinkNode SingleLinkNode;

struct SingleLinkNode {
    int _value;
    SingleLinkNode *_next;
};

struct SinglyLinkedList {
    int length;
    SingleLinkNode *head;
};

SingleLinkNode *newSingleLink(int value) {
    SingleLinkNode *p = malloc(sizeof(SingleLinkNode));
    if (p != NULL) {
        p->_value = value;
        p->_next = NULL;
    }
    return p;
}

SinglyLinkedList *newSinglyLinkedList() {
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
    if (list != NULL) {
        list->length = 0;
        list->head = NULL;
    }
    return list;
}

void add(SinglyLinkedList *list, int value) {
    SingleLinkNode *node = newSingleLink(value);

    if (node == NULL) { return; } /* OOM? */

    SingleLinkNode *cur = list->head;
    SingleLinkNode *prev = NULL;

    while (cur != NULL) {
        prev = cur;
        cur = cur->_next;
    }

    if (prev == NULL) {
        list->head = node;
    } else {
        prev->_next = node;
    }

    list->length++;
}

SingleLinkNode *_prepend(SingleLinkNode *old_root, SingleLinkNode *new_root) {
    new_root->_next = old_root;
    return new_root;
}

void prepend(SinglyLinkedList *list, int value) {
    SingleLinkNode *node = newSingleLink(value);

    if (node == NULL) { return; } /* OOM? */

    list->head = _prepend(list->head, node);
    list->length++;
}

void remove_at(SinglyLinkedList *list, int index) {
    if (index < 0 || index >= list->length) { return; }

    SingleLinkNode *prev = NULL;
    SingleLinkNode *cur = list->head;

    for (int i=0; i<index; i++) {
        prev = cur;
        cur = cur->_next;
    }

    /* still at the beginning? */
    if (prev == NULL) {
        list->head = cur->_next;
    } else {
        prev->_next = cur->_next;
    }

    free(cur);
    list->length--;
}

void _traverse(SingleLinkNode *node) {
    if (node == NULL) { return; }

    printf("value: %d\n", node->_value);
    _traverse(node->_next);
}

/* prints the value of each node in order */
void traverse(SinglyLinkedList *list) {
    if (list != NULL) {
        _traverse(list->head);
    }
}

int length(SinglyLinkedList *list) {
    return list->length;
}

void destroy(SinglyLinkedList *list) {
    if (list != NULL) {
        SingleLinkNode *root = list->head;
        SingleLinkNode *tmp = NULL;

        while (root != NULL) {
            tmp = root->_next;
            free(root);
            root = tmp;
        }
    }

    free(list);
}

/* reverses a linked list in place */
void reverse(SinglyLinkedList *list) {
    if (list->head == NULL) {
        return;
    }

    SingleLinkNode *new_head = NULL;
    SingleLinkNode *cur = list->head;
    SingleLinkNode *tmp = NULL;

    while (cur != NULL) {
        tmp = cur->_next;
        new_head = _prepend(new_head, cur);
        cur = tmp;
    }

    list->head = new_head;
}

/* returns a new reversed linked list */
SinglyLinkedList *reversed(SinglyLinkedList *list) {
    SinglyLinkedList *reversed = newSinglyLinkedList();

    if (reversed != NULL) {
        SingleLinkNode *next = list->head;
        while (next != NULL) {
            prepend(reversed, next->_value);
            next = next->_next;
        }
    }

    return reversed;
}

int main() {
    SinglyLinkedList *list = newSinglyLinkedList();
    int items[] = {1, 2, 3, 4, 5, 0};
    int index = 0;
    while (items[index] != 0) {
        add(list, items[index++]);
    }

    puts("forwards");
    traverse(list);
    reverse(list);
    puts("reversed");
    traverse(list);

    puts("removing index 0");

    remove_at(list, 0);
    traverse(list);
    printf("size: %d\n\n\n", list->length);
    destroy(list);

    SinglyLinkedList *null_list = NULL;
    destroy(null_list);

    SinglyLinkedList *singleton = newSinglyLinkedList();
    add(singleton, 100);

    printf("size: %d\n\n\n", singleton->length);
    puts("ok");
    remove_at(singleton, 0);
    traverse(singleton);
    printf("size: %d\n\n\n", singleton->length);
    return 0;
}
