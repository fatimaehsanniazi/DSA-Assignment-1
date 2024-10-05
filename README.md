# Simple-Process-Scheduling-Algorithm
Description
This project implements a CPU Process Scheduling Algorithm using a Circular Linked List in C++. The algorithm simulates process scheduling in a system where processes are assigned CPU time in a round-robin fashion. The system supports dynamic addition of new processes during the execution cycle.
Each process has attributes such as:
•	Process ID
•	Execution Time
•	Remaining Time
The program assigns a fixed CPU time to each process in every cycle, updating the remaining execution time. Once a process completes its execution, it is removed from the list.
Features
•	Round-Robin Scheduling: Each process gets equal CPU time per cycle.
•	Dynamic Process Addition: New processes can be added during the scheduling cycle.
•	Completion Handling: Processes are removed once their execution is complete.
•	Process Information: After each cycle, the current state of each process is displayed.
Assumptions
•	The CPU assigns a fixed time slice to each process in every cycle.
•	If the remaining time of a process becomes zero, it is removed from the list.
•	Users can dynamically add new processes during the scheduling cycle.

Challenges Faced
•	Circular Linked List Management: Managing the head and tail pointers while ensuring that the list remains circular was a challenge, especially during dynamic addition and deletion of processes.
•	Dynamic Process Addition: Inserting new processes into the list while the scheduling was ongoing required handling process IDs and memory allocation carefully to avoid conflicts.
•	Memory Management: Proper deletion of completed processes to prevent memory leaks was critical.
Technologies
•	C++: The project is implemented in C++ with object-oriented principles.
