#ifndef IO_h
#define IO_h

#include <Arduino.h>
#include <SD.h>
#include <cstring>
#include <stdio.h>

#define SD_CS   15 //Pin for SD card.


class IO
{
	private:
	File recipeFile_; // Global variable to remember the file handle
	
	public:
	IO(); //constructor
	IO(char *);
	/* Initialize serial communication */
	void initSerial();
	/* Message to serial monitor */
	void serialPrint(float message);
	void serialPrintln(float message);
	void serialPrint(char* message);
	void serialPrintln(char* message);
	/* Check for presence of file */
	bool checkFile(char* filename);
	/* Check if recipefile still has on more character */
	bool recipeFileavailable();
	/* Read next character from recipe file */
	char recipeFileread();
	/* Close the recipefile */
	void recipeFileclose();
};

#endif
