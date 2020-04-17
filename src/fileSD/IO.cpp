/* IO functions for Arduino */
#include "IO.h"


IO::IO(char * fname){
	//Nothing to do
	recipeFile_ = SD.open(fname, FILE_READ); // recipeFile is global to IO.h
}

void IO::initSerial(){
	Serial.begin(115200);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}
	if (!SD.begin(SD_CS)) {
		Serial.println("SD Card not found");
	}
	else
	{
		Serial.println("SD Card Ready");
	
		/* Get some info about the card */
		uint8_t cardType = SD.cardType();
		if(cardType == CARD_NONE)
		{
			Serial.println("Card Type not recognized");
		}
	
		Serial.print("SD Card Type: ");
		if(cardType == CARD_MMC){
			Serial.println("MMC");
		} else if(cardType == CARD_SD){
			Serial.println("SDSC");
		} else if(cardType == CARD_SDHC){
			Serial.println("SDHC");
		} else {
			Serial.println("UNKNOWN");
		}
	
		uint64_t cardSize = SD.cardSize() / (1024 * 1024);
		Serial.printf("SD %lluMB\n", cardSize);
	
		/* Test if file can actually be opened for writing */
		File dataFile = SD.open("/test.txt", FILE_WRITE);
		if(!dataFile)
		{
			Serial.println("Failed to open file for writing");
		}
		if(dataFile.print("Hello world"))
		{
			Serial.println("test.txt written");
		} else
		{
			Serial.println("Write test.txt failed");
		}	
		dataFile.close();
	}
}


void IO::serialPrint(float message) {
	Serial.print(message,2);
}

void IO::serialPrintln(float message) {
	Serial.println(message,2);
}

void IO::serialPrint(char * message) {
	Serial.print(message);
}

void IO::serialPrintln(char * message) {
	Serial.println(message);
}

/* Test if recipes file is present */
bool IO::checkFile(char* filename) {
	//recipeFile = SD.open("/RECIPES.CSV"); // recipeFile is global to IO.h
	if (SD.exists(filename) && recipeFile_) {
		serialPrintln((char*)"File checked");
		return true;
	}
	else {
		serialPrintln((char*)"File not exists");
		return false;
	}
}
/* Check if recipefile still has on more character */
bool IO::recipeFileavailable() {
	return recipeFile_.available();
}

/* Read next character from recipe file */
char IO::recipeFileread(){
	char c;
	c = recipeFile_.read();
	return c;
}

/* Close the recipefile */
void IO::recipeFileclose(){
	recipeFile_.close();
}
