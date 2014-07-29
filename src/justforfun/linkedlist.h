typedef struct SinglyLinkedList SinglyLinkedList;

SinglyLinkedList *newSinglyLinkedList(void);

void add(SinglyLinkedList *list, int value);

void prepend(SinglyLinkedList *list, int value);

void remove_at(SinglyLinkedList *list, int index);

void traverse(SinglyLinkedList *list);

int length(SinglyLinkedList *list);

void destroy(SinglyLinkedList *list);

void reverse(SinglyLinkedList *list); /* reverse a linked list in place */

SinglyLinkedList *reversed(SinglyLinkedList *list); /* return a new reversed linked list */

