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
    p->_value = value;
    p->_next = NULL;
    return p;
}

SinglyLinkedList *newSinglyLinkedList() {
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
    list->length = 0;
    list->head = NULL;
    return list;
}

void add(SinglyLinkedList *list, int value) {
    SingleLinkNode *node = newSingleLink(value);
    SingleLinkNode *root = list->head;

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

SingleLinkNode *_prepend(SingleLinkNode *old_root, SingleLinkNode * new_root) {
    new_root->_next = old_root;
    return new_root;
}

void prepend(SinglyLinkedList *list, int value) {
    list->head = _prepend(list->head, newSingleLink(value));
    list->length++;
}

void _traverse(SingleLinkNode *list) {
    printf("value: %d\n", list->_value);
    if (list->_next) {
        _traverse(list->_next);
    }
}

void remove_at(SinglyLinkedList *list, int index) {
    if (index < 0 || index >= list->length) {
        return;
    }

    if (index == 0) {
        SingleLinkNode *to_remove = list->head;
        list->head = to_remove->_next;
        list->length--;
        free(to_remove);
        return;
    }

    SingleLinkNode *prev = list->head;
    int current_index = 0;

    while (current_index < index-1) {
        prev = prev->_next;
        current_index++;
    }


    SingleLinkNode *to_remove = prev->_next;

    SingleLinkNode *new_next = NULL;

    if (to_remove != NULL) {
        new_next = to_remove->_next;
    }

    prev->_next = new_next;
    free(to_remove);
    list->length--;
}

/* prints the value of each node in order */
void traverse(SinglyLinkedList *list) {
    if (list->length) {
        _traverse(list->head);
    }
}

int length(SinglyLinkedList *list) {
    return list->length;
}

void destroy(SinglyLinkedList *list) {
    SingleLinkNode *root = list->head;
    SingleLinkNode *tmp;

    while (root != NULL) {
        tmp = root->_next;
        free(root);
        root = tmp;
    }

    free(list);
}

/* reverses a linked list in place */
void reverse(SinglyLinkedList *list) {
    if (list->head == NULL) {
        return;
    }

    SingleLinkNode *new_head = NULL;
    SingleLinkNode *next = list->head;
    SingleLinkNode *tmp;

    while (next != NULL) {
        tmp = next->_next;
        new_head = _prepend(new_head, next);
        next = tmp;
    }

    list->head = new_head;
}

/* returns a new reversed linked list */
SinglyLinkedList *reversed(SinglyLinkedList *list) {
    SinglyLinkedList *reversed = newSinglyLinkedList();
    SingleLinkNode *next = list->head;
    while (next != NULL) {
        prepend(reversed, next->_value);
        next = next->_next;
    }
    return reversed;
}

int main() {
    SinglyLinkedList *list = newSinglyLinkedList();
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

    SinglyLinkedList *other_list = newSinglyLinkedList();
    add(other_list, 1);
    add(other_list, 2);
    add(other_list, 3);
    add(other_list, 4);
    add(other_list, 5);

    puts("ok\n\n\n");
    printf("size: %d\n\n\n", other_list->length);

    traverse(other_list);

    remove_at(other_list, 0);

    puts("ok\n\n\n");

    traverse(other_list);
    printf("size: %d\n\n\n", other_list->length);
    return 0;
}
