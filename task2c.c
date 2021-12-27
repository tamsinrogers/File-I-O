/**
 * CS333 Project 6 - signal handling in C: SIGSEGV handler
 * 
 * Tamsin Rogers
 * 11/11/21
 *
 * gcc -o task2c task2c.c 
 * ./task2c
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int quit = 0;

/* handler for the SIGINT signal */
void handler (int signal) 
{
	printf("\n segmentation fault %d\n", signal);	// print signal #
	quit = 1;
 	exit(-1);									// terminate
}

/* uses the signal function to set up a handler for the SIGINT signal & enter an infinite loop */
int main() 
{
	signal(SIGSEGV, *handler); 					// send interrupt signal when INTR character typed

	int *p = NULL;
	*p = 1;

}