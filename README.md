## Repo for Lab Week 10 - Signals
Author: Hunter Vassar
Last Updated: 11/13/2026

## Part 1: Signal Research
Explore POSIX signals, default dispositions, and how signal handlers change a program's response. Compare SIGINT, SIGTERM, SIGUSR1, SIGKILL, and SIGSTOP and learn how to send signals.

## Part 2: Working with a Signal Handler
`signal_handler.c` catches SIGINT and prints a message while continuing to run. Send SIGINT with Ctrl+C or `kill`, then use SIGKILL to stop the program.

## Part 3: Operating System Signals and Signal Details
`signal_alarm.c` prints a message after a five-second alarm, and `signal_segfault.c` handles the segmentation fault caused by dereferencing a NULL pointer. `signal_sigaction.c` uses `sigaction` with `SA_SIGINFO` to print the PID of the process that sent SIGUSR1.

## Part 4: Sending Data with a Signal
`send_signal.c` sends SIGUSR1 and a random integer to a specified process using `sigqueue`. `recv_signal.c` receives the signal and prints the integer from `sival_int`.
