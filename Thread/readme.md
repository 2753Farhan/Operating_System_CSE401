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
