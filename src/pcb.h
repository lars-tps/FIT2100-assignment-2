/* Special enumerated data type for process state */
typedef enum {
    READY, RUNNING, EXIT
} process_state_t;

/* C data structure used as process control block.
*  The scheduler should create one instance per running
*  process in the system.
*/
typedef struct {
    char process_name[11]; // A string that identifies the process
    /* Times are measured in seconds */
    int entryTime; // The time process entered system
    int serviceTime; // The total CPU time required by the process
    int remainingTime; // Remaining service time until completion
    int deadline; // The time from entry by which a process would ideally be exited properly
    int exitTime; // the actual time when the process exits
    process_state_t state; // current process state (e.g READY)
} pcb_t;