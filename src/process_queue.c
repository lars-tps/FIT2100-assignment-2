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
* REFERENCES :
*       priority queue implementation referenced from 
*  https://www.geeksforgeeks.org/priority-queue-using-linked-list/ 
* 
* AUTHOR:         Tan Pei Sheng
* STUDENT ID:     32185235
* START DATE:     6 Oct 2022
* LAST MODIFIED:  7 Oct 2022
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

/* 
* Returns the process within the first node in queue without removing it from queue.
*
*   root: pointer to the root node of a queue.
*   returns: pointer to a process of type pcb_t
*/
pcb_t* peek(node** root) {
    return (*root)->ptr_process;
}

/* 
* Inserts a new node which contains process information into the priority queue.
*
*   root: the root node of the priority queue
*   ptr_process: pointer to a process
*   priority: priority value of the node, smaller values is higher priority.
*/
void insert(node** root, pcb_t *ptr_process, int priority) {
    node *current = (*root);
    node *new = new_node(ptr_process, priority);

    if ((*root)->priority > priority) {
        // root priority is lower than new node priority, so insert new node before root
        new->next = *root;
        (*root) = new;
    } else {
        while (current->next != NULL && current->next->priority <= priority) {
            // while next exists and still higher priority than new node
            current = current->next;
        }

        // end of traversal, insert the new node in queue
        new->next = current->next;
        current->next = new;
    }
}

/* 
* Returns the process within the first node in queue and removes it from queue.
*
*   root: pointer to the root node of a queue.
*   returns: pointer to a process of type pcb_t
*/
pcb_t* pop(node** root) {
    node *temp = *root;
    pcb_t *ptr_process = (*temp).ptr_process;
    (*root) = (*root)->next; // switch root node to the next in queue
    free(temp); // free the malloced resources

    return ptr_process;
}

/* 
* Checks if queue is empty
*   root: pointer to the root node of a queue
*   returns: integer 1 for empty, integer 0 for not empty
*/
int is_empty(node** root) {
    return (*root) == NULL;
}

/* 
* Prints a visual representation of the queue.
*/
void show_queue(node** root) {
    while(!is_empty(root)) {
        printf("%s | %d\n", peek(root)->process_name, peek(root)->deadline);
        pop(root);
    }
}

// int main() {
//     // testing code
//     pcb_t first = {
//         .process_name = 'A',
//         .entryTime = 0,
//         .serviceTime = 3,
//         .remainingTime = 3,
//         .deadline = 5,
//         .state = READY
//         };
//     pcb_t second = {
//         .process_name = 'B',
//         .entryTime = 1,
//         .serviceTime = 6,
//         .remainingTime = 6,
//         .deadline = 7,
//         .state = READY
//         };
//     pcb_t third = {
//         .process_name = 'C',
//         .entryTime = 4,
//         .serviceTime = 4,
//         .remainingTime = 4,
//         .deadline = 6,
//         .state = READY
//         };
//     pcb_t fourth = {
//         .process_name = 'D',
//         .entryTime = 6,
//         .serviceTime = 2,
//         .remainingTime = 2,
//         .deadline = 2,
//         .state = READY
//         };
//     pcb_t fifth = {
//         .process_name = 'E',
//         .entryTime = 7,
//         .serviceTime = 2,
//         .remainingTime = 2,
//         .deadline = 8,
//         .state = READY
//         };

//     node* pq = new_node(&first, 5);
//     insert(&pq, &second, 7);
//     insert(&pq, &third, 6);
//     insert(&pq, &fourth, 2);
//     insert(&pq, &fifth, 8);
 
//     show_queue(&pq);
 
//     return 0;
// }