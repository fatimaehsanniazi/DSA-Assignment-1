# CPU Process Scheduling Algorithm

## Approach
The CPU Process Scheduling Algorithm is designed to manage the execution of multiple processes using a circular linked list data structure. Each process is represented as a node in the linked list, containing attributes such as process ID, execution time, and remaining time. The algorithm allocates a fixed amount of CPU time to each process in each cycle until all processes complete their execution. If a new process arrives during execution, it can be added to the list dynamically, allowing the system to adapt to changing workloads.

### Key Features:
- Circular linked list implementation to manage processes.
- Fixed CPU time allocation per cycle.
- Dynamic addition of new processes during execution.
- Displays the state of each process after each cycle.

## Assumptions
- Each process is uniquely identified by its process ID.
- The execution time for each process is a positive integer.
- The CPU time assigned per cycle is also a positive integer.
- The scheduler is capable of handling dynamic additions of new processes at any time during execution.


## Challenges Faced
- Ensuring that processes are correctly removed from the circular linked list once they have completed execution.
- Managing dynamic memory allocation for processes to avoid memory leaks.
- Handling edge cases such as empty lists or all processes completing in the same cycle.
