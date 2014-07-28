typedef struct LinkedList LinkedList;

LinkedList *newList(void);

void add(LinkedList *list, int value);

void prepend(LinkedList *list, int value);

void remove_at(int index);

void traverse(LinkedList *list);

int length(LinkedList *list);

void destroy(LinkedList *list);

void reverse(LinkedList *list); /* reverse a linked list in place (ish) */

LinkedList *reversed(LinkedList *list); /* return a new reversed linked list */

