/**
 * CS333 Project 6 - case insensitive word counter in C++
 * 
 * Tamsin Rogers
 * 11/11/21
 *
 * g++ -o task2cpp task2.cpp
 * ./task2cpp
 */

//#include <stdio.h>
//#include <stdlsdib.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/* create a file, write to it, then close it */
void create(string filename)				
{
	fstream file;							// fstream allows for creating and writing files
	file.open(filename, ios::out);			// create new file

	if (!file) 
	{
		cout << "error: file not created! \n";
	}
	else 
	{
		cout << "file created! \n";
		file << "test \n";					// write to the file
		file << "test1 \n";					// write to the file
		file << "test2 \n";					// write to the file
		file.close(); 						// close the file
	}
	
}

/* read from the file */
void read(string filename)						// include file name to be read in command line
{
	std::ifstream file;							// ifstream allows for reading from a file
	file.open(filename);						// open the file
	std::string line;
	
	if (file.is_open()) 						// read the file
	{
		while (file) 
		{ 
			std::getline (file, line);			// read each line of the file
			std::cout << line << '\n';			// print each line of the file
		}
	}
	else 
	{
		std::cout << "file does not exist \n";
	}
	file.close();
}

/* create a binary file, write to it, then close it */
void createBinary()			
{
	ofstream file("test.mp3", ios::out | ios::binary);	// create the file "test.mp3"
	
	if(!file) 
	{
		cout << "cannot open binary file" << endl;
	}
	else
	{
		cout << "binary file created!" << endl;
	}
	
	char buffer[100];						
    file.write (buffer, 100);								// write 100 bytes to the "test.mp3" file
}

/* read the contents of a binary file and copy them to a new binary file */
void readBinary()
{
    
    std::ifstream input( "music.mp3", std::ios::binary );	// read from the music file
    std::ofstream output( "new.mp3", std::ios::binary );	// copy contents into new file

	// this is the line that does the copying
    std::copy(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>( ),std::ostreambuf_iterator<char>(output));
}

void openURL()
{
	system("open http://www.google.com");					// open URL
}


int main(int argc, char *argv[])							
{

	string filename;
	cout << "enter file name: ";							// interactive user input
	cin >> filename;										// set input to filename
	
	// open, close, and read from a text file
	create(filename);
	read(filename);
	
	// there is also support for binary files
	createBinary();
	readBinary();
	
	// C++ supports opening web locations (URLS), too
	openURL();
		
	return 0;
	
}

