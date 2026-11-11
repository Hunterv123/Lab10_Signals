/**
 * File: send_signal.c
 * Modified by: Hunter Vassar
 * Assignment: Lab 10 Signals
 * Section: 121
 * Brief summary of program: Sends SIGUSR1 along with a 
 * random integer to the process using sigqueue
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <time.h>
 #include <unistd.h>

 int main(int argc, char *argv[]) {
    //check to make sure user provided the pid
    if (argc != 2) {
        fprintf(stderr, "Need to include the pid for the process\n");
        exit(1);
    }
    //Convert the pid into an integer
    pid_t pid = atoi(argv[1]);

    srand(time(NULL));
    //generate a random integer
    int random_value = rand();

    printf("Sender PID: %d\n", getpid());
    printf("Generated number: %d\n", random_value);
    printf("Sending SIGUSR1 to process %d\n", pid);
    
    union sigval value;
    value.sival_int = random_value;

    //send the signal using sigqueue
    if(sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue failed to deliever signal");
        exit(1);
    }
    printf("Signal Sent!!\n");
    return 1;
 }
