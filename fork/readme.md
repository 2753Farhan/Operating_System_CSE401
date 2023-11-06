# The `fork` System Call

The `fork` system call is used for creating a new process in Linux and Unix systems. This new process is referred to as the child process and runs concurrently with the process that invokes the `fork()` call, known as the parent process. After creating a new child process, both processes will execute the next instruction following the `fork()` system call.

## Child Process Characteristics

- **Program Counter (PC):** The child process uses the same program counter as the parent process.
- **CPU Registers:** It shares the same CPU registers as the parent process.
- **Open Files:** The child process has access to the same open files used by the parent process.
- **Parameters:** `fork()` takes no parameters.
- **Return Value:** `fork()` returns an integer value.

## Return Values

- **Negative Value:** If the creation of a child process was unsuccessful.
- **Zero:** Returned to the newly created child process.
- **Positive Value:** Returned to the parent or caller. The value contains the process ID of the newly created child process.

## Example 2: Calculate the number of times 'hello' is printed

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}
Output
hello
hello
hello
hello
hello
hello
hello
hello



