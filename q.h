#include <stdbool.h>
#include "TCB.h"

typedef struct QElement 
{
 struct QElement* prev_pointer;
 struct QElement* next_pointer;
 int payload;
}qelement;

typedef struct The_queue
{
  qelement *head;
  bool isNull;
}queue;

// Returns a pointer to a new qelement
void* NewItem()
{
 return malloc(sizeof(qelement));
}

//creates a new queue and returns a pointer to the new queue. The nxt and previous pointers 
void* newQueue()
{
 queue *new_queue = malloc(sizeof(queue));
 new_queue->head = malloc(sizeof(qelement));
 new_queue->head->next_pointer = NULL;
 new_queue->head->prev_pointer = NULL;
 new_queue->isNull = 1;
 return new_queue;
}



void AddQueue(queue *queue, qelement *item)
{

 //printf("prinintg the payload inside the Add queue %d\n", item -> payload);
 if(queue->isNull)
 {
   queue->isNull = 0;
   queue->head = item;
   queue->head->prev_pointer = item;
   queue->head->next_pointer = item;
   printf("checking if isNUll works or not\n");
 }

 else
 {
   printf("inside general adds now\n");
   item -> prev_pointer = queue -> head -> prev_pointer;
   queue -> head -> prev_pointer -> next_pointer = item;
   item -> next_pointer = queue -> head;
   queue -> head -> prev_pointer = item;
 }
}


qelement* DelQueue(queue *queue)
{
 if(queue->isNull)
 {
   printf("no element in the queue to delete\n");
   return NULL;
 }

 else if (queue -> head -> next_pointer == queue -> head -> prev_pointer)
 {
  queue -> isNull = 1;
  queue -> head -> next_pointer = NULL;
  queue -> head -> prev_pointer = NULL;
  return queue -> head;
 }

 else
 {
  queue -> head -> next_pointer -> prev_pointer = queue -> head -> prev_pointer;
  queue -> head -> prev_pointer -> next_pointer = queue -> head -> next_pointer;
  qelement* item_to_be_deleted = queue -> head;
  queue -> head = queue -> head -> next_pointer;
  
  item_to_be_deleted -> next_pointer = NULL;
  item_to_be_deleted -> prev_pointer = NULL;
  return item_to_be_deleted;
 }
}


void print_queue(queue *queue)
{
 qelement* first_element = queue -> head;
 if(queue -> isNull)
 {
   printf("nothing in queue to print\n");
   return;
 }
 printf("prinitng first element %d\n", queue -> head -> payload);
 qelement* current_element = queue -> head -> next_pointer;
 while(current_element != first_element)
{
  printf("prinnitg the next element in the queue %d\n", current_element -> payload);
  current_element = current_element -> next_pointer;
}
}
