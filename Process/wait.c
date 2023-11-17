int main() {
pid_t child_pid;
else if (child_pid > 0) {
// Parent process
printf("Parent process created child with PID: %d\n",child_pid);
// Create child processsleep(4); // Parent sleeps for a while
child_pid = fork();printf("Parent process woke up.\n");
if (child_pid == 0) {} else {
// Error handling
// Child processperror("fork");
printf("Child process is running.\n");exit(1);
sleep(2); // Simulate some work
}
// Parent process doesn't wait for child
printf("Parent process is done.\n");
return 0;
printf("Child process is done.\n");
exit(0);
}
