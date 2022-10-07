#include "./pcb.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER_SIZE 100

/* Min-priority node */
typedef struct node {
    pcb_t *ptr_process;
    int priority; // Smaller values means higher priority.
    struct node* next;
} node;

node* new_node(pcb_t *ptr_process, int priority);
pcb_t* peek(node** root);
void insert(node** root, pcb_t *ptr_process, int priority);
pcb_t* pop(node** root);
void show_queue(node** root);
int is_empty(node** root);