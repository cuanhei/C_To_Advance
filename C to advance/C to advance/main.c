#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch() function
#include <string.h>


#include "calculator.h"
#include "ToDoList.h"
#include "encrypt.h"
#include "banksystem.h"
#pragma warning (disable:4996)

//#define CALCULATOR
//#define TODOLIST
//#define ENCRYPT
#define BANKSYSTEM

void main() {

#ifdef CALCULATOR
			main_calculator();
#endif	
	
#ifdef TODOLIST
			ToDo_main();
#endif

#ifdef ENCRYPT
			encrypt_main();
#endif

#ifdef BANKSYSTEM
			bankSystemMain();
#endif
}

