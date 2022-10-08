/*
* Reads process information from a file descriptor and place them in a queue.
* 
* DESCRIPTION :
*     placeholder
* 
* PUBLIC FUNCTIONS :
*
* REFERENCES :
*       file reading code referenced from  
*  https://www.youtube.com/watch?v=X-1qodkHCHo
* 
* AUTHOR:         Tan Pei Sheng
* STUDENT ID:     32185235
* START DATE:     8 Oct 2022
* LAST MODIFIED:  8 Oct 2022
* 
*/

#include "./read_processes.h"

node** read_from_file(FILE *file) {
    char line_data[MAX_LINE_LEN];
    fgets(line_data, MAX_LINE_LEN, file);
    char **splitted_line = stringsplitter(line_data);
    pcb_t first_process = {
        .process_name = splitted_line[0],
        .entryTime = splitted_line[1],
        .serviceTime = splitted_line[2],
        .deadline = splitted_line[3],
        .remainingTime = splitted_line[2],
        .state = READY,
        .exitTime = -1
    };
    pcb_t *ptr_first_process = malloc(sizeof(pcb_t));
    ptr_first_process = &first_process;

    node *incoming_queue = new_node(ptr_first_process, 0);
    return &incoming_queue;
}