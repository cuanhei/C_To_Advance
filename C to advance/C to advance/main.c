#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch() function
#include <string.h>


#include "calculator.h"
#include "ToDoList.h"
#include "encrypt.h"
#include "banksystem.h"
#include "shell.h"
#pragma warning (disable:4996)

//#define CALCULATOR
//#define TODOLIST
//#define ENCRYPT
//#define BANKSYSTEM
#define SHELL


void main() {

#ifdef CALCULATOR
			calculator_main();
#endif	
	
#ifdef TODOLIST
			ToDo_main();
#endif

#ifdef ENCRYPT
			encrypt_main();
#endif

#ifdef BANKSYSTEM
			bank_system_main();
#endif

#ifdef SHELL
			shell_main();
#endif
}

