#include "./read_processes.h"

/*
*  Reads process information from a file descriptor and place them in a queue.
*   REFERENCES :
*       file reading code referenced from  
*  https://www.youtube.com/watch?v=X-1qodkHCHo
*/
node** read_from_file(FILE *file) {
    char line_data[MAX_LINE_LEN];
    fgets(line_data, MAX_LINE_LEN, file);
    char **splitted_line = stringsplitter(line_data);
    pcb_t first_process = {
        .process_name = splitted_line[0],
        .entryTime = atoi(splitted_line[1]),
        .serviceTime = atoi(splitted_line[2]),
        .deadline = atoi(splitted_line[3]),
        .remainingTime = atoi(splitted_line[2]),
        .state = READY,
        .exitTime = -1 // -1 for not yet exited
    };
    pcb_t *ptr_first_process = (pcb_t *) malloc(sizeof(pcb_t)); // will be freed when popped
    ptr_first_process = &first_process;

    node *first_node = new_node(ptr_first_process, 0);
    node **incoming_queue = (node **) malloc(sizeof(&first_node));
    incoming_queue = &first_node;
    return incoming_queue;
}

/*
* Splits a string separated by space. Returns an array of char arrays.
*
* Format of input string is : 
*   "[Process Name] [Arrival Time] [Service Time] [Deadline]"
*
* REFERENCE :
*   string splitting code referenced from
*  https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
*
*   2d array memory allocation code referenced from
*   https://stackoverflow.com/questions/2614249/dynamic-memory-for-2d-char-array
*/
char** stringsplitter(char *string) {
    int i = 0;
    char *splitted_string[4] = (char**) calloc(4, sizeof(char*)); // we only have 4 fields in input string

    char *ptr_token = strtok(string, " ");

    while (ptr_token != NULL) {
        splitted_string[i] = ptr_token;
        ptr_token = strtok(NULL, " ");
    }

    return splitted_string;
}

