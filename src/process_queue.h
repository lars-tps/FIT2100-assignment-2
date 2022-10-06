#include "./pcb.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER_SIZE 100

/* priority queue implementation referenced from 
*  https://www.geeksforgeeks.org/priority-queue-using-linked-list/ 
*/

// typedef struct {
//     pcb_t *buffer[MAX_BUFFER_SIZE];
//     int length; // length of queue
//     int count; // number of processes in queue
//     pcb_t *ptr_head; // pointer to first item in queue
//     pcb_t *ptr_tail; // pointer to end of queue
// } process_queue;

/* Min-priority node */
typedef struct node {
    pcb_t *ptr_process;
    int priority; // Smaller values means higher priority.
    struct node* next;
} node;

node* new_node(pcb_t *ptr_process, int has_priority);
pcb_t* peek(node** root);
void append(node** root);
pcb_t* pop(node** root);
void show_queue(void);