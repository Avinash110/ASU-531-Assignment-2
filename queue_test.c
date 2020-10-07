#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int main()
{
qelement *item = (qelement*) NewItem();

//printf("checking the memeory address gained by item %p \n", item);
item->payload = 5;

//printf("prionitng the payload %d\n", item->payload);

// the head pointer is set to null when a new queue is being initialized
//void pointer cos that it holds just an address
queue *head = newQueue();

//printf("checking if head has a memeory address %p \n", head);

AddQueue(head, item);

qelement *item2 = (qelement*) NewItem();
item2->payload = 6;
AddQueue(head, item2);

qelement *item3 = (qelement*) NewItem();
item3->payload = 7;
AddQueue(head, item3);

qelement *item4 = (qelement*) NewItem();
item4->payload = 8;
AddQueue(head, item4);

printf("prinintg queue before delete\n");

print_queue(head);

DelQueue(head);

printf("prinintg queue after delete\n");
print_queue(head);

DelQueue(head);

printf("prinintg queue after delete\n");
print_queue(head);

DelQueue(head);

printf("prinintg queue after delete\n");
print_queue(head);

DelQueue(head);

printf("prinintg queue after delete\n");
print_queue(head);

DelQueue(head);

printf("prinintg queue after delete\n");
print_queue(head);
/*
printf("checking if head is giving payload or not %d\n", head->head->payload);

item
AddQueue(head, item);
*/
 return 0;
}
