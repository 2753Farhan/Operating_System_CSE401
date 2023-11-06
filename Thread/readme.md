Thread operations include thread creation, termination, synchronization (joins, blocking), scheduling, data management, and process interaction.

- A thread does not maintain a list of created threads, nor does it know the thread that created it.
- All threads within a process share the same address space.

Threads in the same process share:
- Process instructions
- Most data
- Open files (descriptors)
- Signals and signal handlers
- Current working directory
- User and group id

Each thread has a unique:
- Thread ID
- Set of registers, stack pointer
- Stack for local variables, return addresses
- Signal mask
- Priority
- Return value: errno

pthread functions return "0" if OK.

## Mutexes:
Mutexes are used to prevent data inconsistencies due to race conditions. A race condition often occurs when two or more threads need to perform operations on the same memory area, but the results of computations depends on the order in which these operations are performed. Mutexes are used for serializing shared resources. Anytime a global resource is accessed by more than one thread the resource should have a Mutex associated with it. One can apply a mutex to protect a segment of memory ("critical region") from other threads. Mutexes can be applied only to threads in a single process and do not work between processes as do semaphores. 
