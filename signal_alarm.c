/******************************
 * File: signal_handler.c
 * Name: Hunter Vassar
 * Assignment: Lab 10 Signals
 * Section Number: 121
 * Description: Sends an alarm signal after 5 seconds
 * and then prints out the signal was recieved
 *****************************/

 #include <stdio.h>
 #include <unistd.h>
 #include <signal.h>
 

 //alarm handler to print message
 void handle_alarm() {
    printf("Signal recieved, the alarm has gone off!!!!!\n");
 }

 int main() {
    //registers the signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    //sets the alarm for 5 seconds
    alarm(5);

    pause();
    return 0;
 }
