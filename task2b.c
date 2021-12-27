/**
 * CS333 Project 6 - task 2 part b
 * signal handling in C: SIGFPE handler
 * 
 * Tamsin Rogers
 * 11/11/21
 *
 * gcc -o task2b task2b.c 
 * ./task2b
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int quit = 0;

/* handler for the SIGINT signal */
void handler (int signal) 
{
	printf("\n floating point exception %d\n", signal);	// print signal #
	quit = 1;
 	exit(-1);									// terminate
}

/* uses the signal function to set up a handler for the SIGFPE signal & enter an infinite loop */
int main() 
{
	signal(SIGFPE, *handler); 					// send interrupt signal when INTR character typed

	int i = 1;
	int j = 2;
	int a = i/0;	
}