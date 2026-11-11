/******************************
 * File: signal_segfault.c
 * Name: Hunter Vassar
 * Assignment: Lab 10 Signals
 * Section Number: 121
 *****************************/

/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//Make the signal handler to print the message
void handle_segfault() {
    printf("Segmenation Fault, you broke something!!!!!\n");
    exit(1);
}

int main (int argc, char* argv[]) {
    
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}