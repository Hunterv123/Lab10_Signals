/**
 * File: recv_signal.c
 * Modified by: Hunter Vassar
 * Assignment: Lab 10 Signals
 * Section: 121
 * Brief summary of program: Uses sigaction to retrieve
 * the sival_int and print out its value
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <unistd.h>

 //Three argument signal handler using SA_SIGINFO
 void handle_sigusr(int signum, siginfo_t *info, void *context) {
    (void)signum;
    (void)context;

    printf("Recieved SIGUSR1 signal. The sival_int value: %d\n", info->si_value.sival_int);
    exit(1);
 }

//To recieve the signal, have the program running,
//then in another window type /bin/kill -q 42 -SIGUSR1 [pid of processor]


int main(void) {
    //create the sigaction struct
    struct sigaction sa;

    //print the current process PID
    printf("PID of running program is %d\n", getpid());
    
    //Clear the sigaction struct memory
    sa.sa_handler = NULL;
    //assign the three argyment signal handler
    sa.sa_sigaction = handle_sigusr;
    //clear the signal mask during handler runtime
    sigemptyset(&sa.sa_mask);

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