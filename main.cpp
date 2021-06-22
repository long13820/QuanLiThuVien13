using namespace std; 

//#include <winbgim.h> 
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>
             

#include "define.h"


#include "view.h"
#include "local.h"

   
bool isExit = false;

             
int main(int argc, char *argv[])
{
	srand(time(NULL));
	initwindow(w, h, AppTitle);
	ClearScreen();
	
	
	DrawMenu();
	
	while(true){
		Event();
		if(isExit) break;
		delay(50);
	}	
	
	closegraph();	
	return 0;
}


