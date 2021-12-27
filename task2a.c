/**
 * CS333 Project 6 - task 2 part a
 * signal handling in C: SIGINT handler
 * 
 * Tamsin Rogers
 * 11/11/21
 *
 * gcc -o task2a task2a.c 
 * ./task2a
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int quit = 0;

/* handler for the SIGINT signal */
void handler (int signal) 
{
	printf("\n caught signal %d\n", signal);	// print signal #
	quit = 1;
 	exit(-1);									// terminate
}

/* uses the signal function to set up a handler for the SIGINT signal & enter an infinite loop */
int main() 
{
	signal(SIGINT, *handler); 					// send interrupt signal when INTR character typed

	while (!quit) 
	{
		printf("nothing \n");
	}
	
	printf("\n Cleaning up \n");

	return 0; 

}