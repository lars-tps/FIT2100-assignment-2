/*
* Splits a string separated by space. Returns an array of char arrays.
* REFERENCE :
*   string splitting code referenced from
*  https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
*/
#include "./stringsplitter.h"

char** stringsplitter(char *string) {
    int i = 0;

    char *ptr = strtok(string, " ");
    char *splitted_string[NUM_PCB_FIELDS];

    while (ptr != NULL) {
        splitted_string[i] = ptr;
        ptr = strtok(NULL, " ");
    }

    return splitted_string;
}