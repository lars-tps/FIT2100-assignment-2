/*
* A min-priority queue data structure implementation using sequentially linked nodes.
* 
* DESCRIPTION :
*     placeholder
* 
* PUBLIC FUNCTIONS :
*     node*   new_node(pcb_t *ptr_process, int priority)
*     pcb_t*  peek(node** root)
*     void    append(node** root)
*     pcb_t*  pop(node** root)
*     void    show_queue(void)
* 
* AUTHOR:         Tan Pei Sheng
* STUDENT ID:     32185235
* START DATE:     6 Oct 2022
* LAST MODIFIED:  6 Oct 2022
* 
*/

#include "./process_queue.h"

/* 
* Creates a new priority node and return its pointer.
* 
*     ptr_process: pointer to an instance of pcb_t
*     priority: priority value of the node, smaller values is higher priority.
*     returns: a pointer to an instance of node
*/
node* new_node(pcb_t *ptr_process, int priority) {
    node* new = (node*)malloc(sizeof(node)); // remember to free when popped!
    new->ptr_process = ptr_process;
    new->priority = priority;
    new->next = NULL; // newly made nodes have no next

    return new;
}

pcb_t* peek(node** root) {
    return (*root)->ptr_process;
}

// pcb_t* pop(node** root) {
//     node* temp = root;

// }
