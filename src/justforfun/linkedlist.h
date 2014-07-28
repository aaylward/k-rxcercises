typedef struct LinkedList LinkedList;

LinkedList *newList(void);

void add(LinkedList *list, int value);

void prepend(LinkedList *list, int value);

void traverse(LinkedList *list);

void destroy(LinkedList *list);

LinkedList *reversed(LinkedList *list); /* return a new reversed linked list */

void reverse(LinkedList *list); /* reverse a linked list in place (ish) */

int length(LinkedList *list);

