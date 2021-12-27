/**
 * CS333 Project 6 - error/exception handling in C++
 * 
 * Tamsin Rogers
 * 11/11/21
 *
 * g++ -o task3cpp task3.cpp
 * ./task3cpp
 */

//#include <stdio.h>
//#include <stdlsdib.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <exception>

using namespace std;

double divideByZero(int a, int b) 
{
   if( b == 0 ) 
   {
      throw "exception: dividing by zero";
   }
   return (a/b);
}

struct Excep : public exception 
{
   const char * what () const throw () 
   {
      return "new exception";
   }
};


/* error handling */
int main(int argc, char *argv[])							
{

	// divide by zero example
	int x = 1;
	int y = 0;
	double z = 0;

	try 
	{
		z = divideByZero(x, y);
		cout << z << endl;
	} 
	
	catch (const char* msg) 
	{
		cerr << msg << endl;
	}
	
	// make your own exception example 
	try 
	{
		throw Excep();
	} 
	
	catch(Excep& ex) 
	{
		std::cout << "exception has been caught" << std::endl;
		std::cout << ex.what() << std::endl;
	} 
	
		
	return 0;
	
}

