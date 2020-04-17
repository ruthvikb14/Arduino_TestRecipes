#include "TestRecipes.h"

IO *  myIO;      //The exact IO routines depend on defined(SD) or defined(stdio)
recipes * myrecipes; //Defintion of recipe file

int main(){
  
  //myIO.serialPrintln((char*)"TestRecipes, expects RECIPES.CSV in current directory");

  /* check if Recipes file exists */
  char filename[] = "/RECIPES.CSV";
  myIO = new IO(filename);
  bool check = myIO->checkFile(filename);
  if(!check){
    myIO->serialPrintln((char*)"Failed to open file for writing recipes file");
    return 0;
    }

  /* Read file contents character by character and display on command
     line or serial monitor */
  //while(myIO->recipeFileavailable())
    //{
      //myIO->serialPrint((char*)myIO->recipeFileread());
    //}
    
  /* Read Recipes from file */
  int numRecipes= myrecipes->LoadRecipes();
  myIO->serialPrint((char*)"Number of recipes found : ");
  myIO->serialPrintln(numRecipes);
  myIO->recipeFileclose();
}

void setup(){
  myIO->initSerial();
  main();
}


void loop(){
  
  }
