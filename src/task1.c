/*
FCFS scheduling algorithm simulator

DESCRIPTION:
    Simulates how the First Come, First Served scheduling algorithm works
    with a queue data structure.
AUTHOR:         Tan Pei Sheng
STUDENT ID:     32185235
START DATE:     6 Oct 2022
LAST MODIFIED:  6 Oct 2022

 */

#include "./libraries.h";
#include "./read_processes.h";

int main() {
    FILE *file;
    file = fopen("file.txt", "r");

    node** incoming_queue = read_from_file(file);
    show_queue(incoming_queue);

    pop(incoming_queue);
    show_queue(incoming_queue);
}