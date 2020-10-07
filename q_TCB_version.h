#include <stdbool.h>
#include "TCB.h"

/*
typedef struct QElement 
{
 struct QElement* prev_pointer;
 struct QElement* next_pointer;
 int payload;
}qelement;
*/

// In changing the regular q.h described in task 1 to the one that 
// accomodates TCB_t, we just need to replace qelement (the structure name for task 1) with TCB_t
// Additionally, TCB_t had a thread_id field extra but that is irrelevant here as of now and hence I have not initilaized it here as well
// you might have to see if that needs a change here or not...if it does, it will be under the function newQueue()....probably something like 
// new_queue->head->thread_id = something  .... that is if initialization is needed at all (for thread_id)
// also not sure what value it needs to be intialized to cos 0 may lead to unintended consequences
// because 0 for a thread id means special things
// also, since I am still troubleshooting a corner case, I have given u this file with a different file name and the name of the file will be changed....has to be...
// but this works for most cases and is good enough for you to proceed ahead!!!


// Definition of the queue
typedef struct The_queue
{
  TCB_t *head;
  bool isNull;
}queue;

// Returns a pointer to a new TCB_t
TCB_t* NewItem()
{
 return malloc(sizeof(TCB_t));
}

//creates a new queue and returns a pointer to the new queue. The nxt and previous pointers 
void* newQueue()
{
 queue *new_queue = malloc(sizeof(queue));
 new_queue->head = malloc(sizeof(TCB_t));
 new_queue->head->next_pointer = NULL;
 new_queue->head->prev_pointer = NULL;
 new_queue->isNull = 1;
 return new_queue;
}


// Function to add element to queue
void AddQueue(queue *queue, TCB_t *item)
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


// Function to Delete element from queue
TCB_t* DelQueue(queue *queue)
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
  TCB_t* item_to_be_deleted = queue -> head;
  queue -> head = queue -> head -> next_pointer;
  
  item_to_be_deleted -> next_pointer = NULL;
  item_to_be_deleted -> prev_pointer = NULL;
  return item_to_be_deleted;
 }
}


// This function is not to be submitted and is for troubleshooting...prints a queue..is not perfect either...gives segmentation fault if used on empty queue..anyways...just here for testing
// has to be removed
void print_queue(queue *queue)
{
 TCB_t* first_element = queue -> head;
 if(queue -> isNull)
 {
   printf("nothing in queue to print\n");
   return;
 }
 printf("prinitng first element %d\n", queue -> head -> payload);
 TCB_t* current_element = queue -> head -> next_pointer;
 while(current_element != first_element)
{
  printf("prinnitg the next element in the queue %d\n", current_element -> payload);
  current_element = current_element -> next_pointer;
}
}
