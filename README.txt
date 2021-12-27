CS333 - Project #6 - README
Tamsin Rogers
10/11/2021

Directory Layout:
Project6
├── task1.c
├── task1_test.txt
├── task1_test2.txt
├── task1
├── task2a.c
├── task2a
├── task2b.c
├── task2b
├── task2c.c
├── task2c
├── task1.cpp
├── task1cpp
├── task2.cpp
├── task2cpp
├── test.txt
├── test.mp3
├── music.mp3
├── new.mp3
├── task3.cpp
├── task3cpp
└── task1_test2

Run and build configuration for C:
macOS Big Sur 11.5.2 - Apple LLVM version 12.0.5 (clang-1205.0.22.11)

Description for each subsection:

C:
  This is the C programming task (part 1)

task1.c is a case-insensitive word counter that prints out the top 20 words in terms of the word
frequency in descending order, using arrays.
 			   
  Compile:
	gcc -o task1c task1.c 

  Run:
	./task1 task1_test.txt

  Output:
	the 17
	of 7
	and 6
	was 5
	with 4
	in 4
	a 3
	windows 3
	central 2
	portion 2
	wings 2
	were 2
	broken 2
	but 2
	up 2
	had 2
	been 2
	building 1
	grey 1
	lichen-blotched 1
	stone 1
	

task2a.c demonstrates signal handling in C with a SIGINT handler.  The main function uses the
signal function to set up a handler for the SIGINT signal and responds "caught" to a cntl-C interrupt.
 			   
  Compile:
	gcc -o task2a task2a.c

  Run:
	./task2a

  Output:
	nothing 
	nothing 
	nothing 
	nothing 
	nothing 
	nothing 
	nothing 
	noth^Cing 
	nothing 

	 caught signal 2

task2b.c demonstrates signal handling in C with a SIGFPE handler.  The main function uses the
signal function to set up a handler for the SIGFPE signal and prints "floating point exception 8"
when a divide by zero exception is raised.
 			   
  Compile:
	gcc -o task2b task2b.c 

  Run:
	./task2b
	
  Output:
  	floating point exception 8
  	
	
task2c.c demonstrates signal handling in C with a segmentation fault error.  The main function sets
up a handler for the SIGSEGV signal and returns a segmentation fault when we attempt to access
a non-existent location in memory.
 			   
  Compile:
	gcc -o task2c task2c.c 

  Run:
	./task2c

  Output:
	segmentation fault 11

	
C++:
	This is the C++ programming task (part 2)

task1.cpp implements a case-sensitive word counter in C++.  This program uses a 2D array
to store words as rows and letters as columns and a 1D array to store the frequency of each word.
The row indices of the word array correspond with each column of the counter array.  The program
runs through the array to determine the words with the largest frequency and continuously decrements 
from the max to output the 20 most frequent words and their word count in the given text file.
 			   
  Compile: 
  	g++ -o task1cpp task1.cpp

  Run: 
  	./task1cpp task1_test.txt

  Output: 
	
	
	
task2.cpp demonstrates how C++ is able to read from and write to a file.
The create() function takes in a string filename (.txt file), which is provided by the 
user in the command line.  C++ then uses an fstream object and the open() function to open 
the file.  Create() writes 3 new lines of text to the newly created empty file.  The read()
function takes in a string filename (.txt file), which is provided by the user in the command line.  
C++ uses an ifstream object, along with the open() function to open the file.  The file is read 
through and printed line by line to the terminal.  This program also demonstrates opening, closing 
reading, and writing for binary files.  The createBinary() function uses the ofstream object to manipulate 
binary files, and the readBinary() function implements the C++ copy function in reading and rewriting
the contents of one binary file to another.  This program also incorporates interactive user 
input by prompting the user to name the file they would like to create/read and uses the C++ 
system() function to open a web URL.

Compile:
	g++ -o task2cpp task2.cpp
	
  Run:
	./task2cpp

  Output:
  	file created! 
	test 
	test1 
	test2 
	binary file created!
	
	* program then opens http://www.google.com *
	
task3.cpp demonstrates error/exception handling in C++.  
C++ uses throw, catch, and try (in the form of throw-catch blocks) to intercept and handle exceptions
in the code.  This program handles a divide by zero exception and also implements defining a new exception.

Compile:
	g++ -o task3cpp task3.cpp
	
  Run:
	./task3cpp

  Output:
  	exception: dividing by zero
  	exception has been caught
  	new exception