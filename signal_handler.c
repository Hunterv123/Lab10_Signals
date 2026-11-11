/******************************
 * File: signal_handler.c
 * Name: Hunter Vassar
 * Assignment: Lab 10 Signals
 * Section Number: 121
 *****************************/

/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Hunter Vassar
 * 
 * Brief summary of modifications: Removed the exit(1) in the signal handler
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
//Removed the exit 
void handle_signal() {
    printf("Received a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}