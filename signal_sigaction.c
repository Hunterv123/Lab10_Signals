/**
 * File: signal_sigaction.c
 * Modified by: Hunter Vassar
 * Assignment: Lab 10 Signals
 * Section: 121
 * Brief summary of program: Makes a three argument signal handler
 * that terminates the process using the process ID
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//To send the signal, have the program running,
//then in another window type kill -SIGUSR1 [id of running process]

// Three argument signal handler
void handle_sigusr(int signum, siginfo_t *info, void *context) {
    (void)signum;
    (void)context;

    printf("Process identifier of the sender: %d\n", info->si_pid);
    exit(1);
}

int main(void) {
    //create the sigaction struct
    struct sigaction sa;

    //print the current process PID
    printf("PID of running program is %d\n", getpid());
    
    //Clear the sigaction struct memory
    sa.sa_handler = NULL;
    //assign the three argyment signal handler
    sa.sa_sigaction = handle_sigusr;

    sa.sa_flags = SA_SIGINFO;

    //register the handler for sigusr1
    if(sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error registering sigaction");
        exit(1);
    }

    //infinite loop
    while(1) {
        pause();
    }

    

}
