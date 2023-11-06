/*
* Started at 6/11/2023 9:35 PM
*
* Create Account
* Deposit
* Withdraw Money
* Check Balance
* 
* Finished at 6/11/2023 11:38 PM
* 
* Bugs to fix : 
*     1. After return to menu by pressing 0, when they exit on the menu with pressing 0 it will show
*        out those running stuff that not completed from the older function, example : "Your current 
*        balance :RM XX.xx ".
*
*/




char enter[10];
char registeredAccount[5000][2][50];// [amount of account] [account ID and Password] [string]
float accountBalance[5000];
int registeredIndex = 0;



void menu();
void createAcc();
void logIn();
void loggedIn(int accountIndex);
void deposit(int accountIndex);
void withdraw(int accountIndex);
void checkBalance(int accountIndex);
void clearScreen(char title[50]);
void isZero(int zero, char stringZero[1024]);



void bankSystemMain() {
	menu();
}


void menu() {
	int action;

	do {
		system("cls");
		printf("[Menu]\n\n");
		printf("Please choose following action :\n");
		printf("[0] Exit\n");
		printf("[1] Create Account\n");
		printf("[2] Log In\n\n");

		printf(">> ");

		scanf("%d", &action);
		rewind(stdin);
	} while (action != 1 && action != 2 && action != 0);

	switch (action)
	{
	case 1:
		createAcc();
		break;
	case 2:
		logIn();
		break;
	default:
		system("exit");
	}

}

void createAcc() {
	char accID[50], accPswd[50];
	char pswdTemp;
	int i;

	clearScreen("Creating Account");

	printf("Please enter your account ID\n>> ");
	gets(accID);
	rewind(stdin);
	isZero(1, accID);

	if (registeredIndex != 0) {
		for (i = 0; i < registeredIndex; i++) {
			if (strcmp(registeredAccount[i][0], accID) == 0) {
				printf("\n[Sorry that account ID has been created]\n\n");
				printf("[Press ENTER to return menu page]");
				gets(enter);
				menu();
				break;
			}
		}
	}

	printf("\nPlease enter your account password\n>> ");
	for (i = 0; i < 50; i++) {
		pswdTemp = getch();
		if (pswdTemp == '\b' && i == 0) {
			i--;
		}
		else if (pswdTemp == '\b' && i > 0) {
			printf("\b \b");
			i--;
		}
		else if (pswdTemp == '\r' && i > 3) {
			accPswd[i] = '\0';
			break;
		}
		else if ((pswdTemp == '\r' && i <= 3)) {
			i--;
		}
		else {
			accPswd[i] = pswdTemp;
			printf("*");
		}
	}
	isZero(1, accPswd);

	strcpy(registeredAccount[registeredIndex][0], accID);
	strcpy(registeredAccount[registeredIndex][1], accPswd);
	accountBalance[registeredIndex] = 0;
	registeredIndex += 1;

	printf("\n\n[You had successfully created your account]\n\n");
	printf("[Press ENTER to return to menu page]");
	gets(enter);
	menu();

}
void logIn() {
	char accID[50], accPswd[50];
	char pswdTemp;
	int i;

	clearScreen("Login");

	if (registeredIndex != 0) {
		printf("Please enter your account ID\n>> ");
		gets(accID);
		rewind(stdin);
		isZero(1, accID);

		printf("Please enter your account password\n>> ");
		for (i = 0; i < 50; i++) {
			pswdTemp = getch();
			if (pswdTemp == '\b' && i == 0) {
				i--;
			}
			else if (pswdTemp == '\b' && i > 0) {
				printf("\b \b");
				i--;
			}
			else if (pswdTemp == '\r' && i > 3) {
				accPswd[i] = '\0';
				break;
			}
			else if ((pswdTemp == '\r' && i <= 3)) {
				i--;
			}
			else {
				accPswd[i] = pswdTemp;
				printf("*");
			}
		}
		isZero(1, accPswd);

		for (i = 0; i < registeredIndex; i++) {
			if (strcmp(registeredAccount[i][0], accID) == 0) {
				if (strcmp(registeredAccount[i][1], accPswd) == 0) {
					loggedIn(i);
					break;
				}

				else {
					printf("\n\n[Password Incorrect]\n\n");
					printf("[Press ENTER to return menu page]");
					gets(enter);
					menu();
				}
			}
			if (i == registeredIndex - 1 && strcmp(registeredAccount[i][0], accID) != 0) {
				printf("\n\n[Account ID was not found]\n\n");
				printf("[Press ENTER to return menu page]");
				gets(enter);
				menu();
			}

		}
	}

	else {
		printf("[Sorry no account has been created yet]\n\n");
		printf("[Press ENTER to return menu page]");
		gets(enter);
		menu();
	}

}

void loggedIn(int accountIndex) {
	int action;
	do {
		clearScreen("You had successfully logged into your account");
		printf("Account ID : %s\n\n", registeredAccount[accountIndex][0]);

		printf("Please choose following action :\n");
		printf("[1] Deposit\n");
		printf("[2] Withdraw\n");
		printf("[3] Check Balance\n\n");

		printf(">> ");
		scanf("%d", &action);
		rewind(stdin);

	} while (action < 0 || action > 3);
	isZero(action, "1");

	switch (action)
	{
	case 1:
		deposit(accountIndex);
		break;
	case 2:
		withdraw(accountIndex);
		break;
	default:
		checkBalance(accountIndex);
	}
}

void deposit(int accountIndex) {
	float depositValue;

	clearScreen("Deposit");
	printf("Account ID              : %s\n", registeredAccount[accountIndex][0]);
	printf("Account current balance : RM%.2f\n\n", accountBalance[accountIndex]);

	printf("Please enter the value you wanted to deposit : RM");
	scanf("%f", &depositValue);
	rewind(stdin);

	isZero(depositValue, "1");

	accountBalance[accountIndex] += depositValue;
	printf("\nYour account balance are now : RM%.2f\n\n", accountBalance[accountIndex]);
	printf("[Press ENTER to return account page]");
	gets(enter);

	loggedIn(accountIndex);
}

void withdraw(int accountIndex) {
	float withdrawValue;

	clearScreen("Withdraw");
	printf("Account ID              : %s\n", registeredAccount[accountIndex][0]);
	printf("Account current balance : RM%.2f\n\n", accountBalance[accountIndex]);

	printf("Please enter the value you wanted to deposit : RM");
	scanf("%f", &withdrawValue);
	rewind(stdin);

	isZero(withdrawValue, "1");

	if (accountBalance[accountIndex] < withdrawValue) {
		printf("\n\n[Sorry, the balance in your account is not enough]\n\n");
		printf("[Press ENTER to return account page]");
		gets(enter);
	}
	else {
		accountBalance[accountIndex] -= withdrawValue;
		printf("\nYour account balance are now : RM%.2f\n\n", accountBalance[accountIndex]);
		printf("[Press ENTER to return account page]");
		gets(enter);
	}

	loggedIn(accountIndex);
}

void checkBalance(int accountIndex) {

	clearScreen("Balance");
	printf("Account ID              : %s\n", registeredAccount[accountIndex][0]);
	printf("Account current balance : RM%.2f\n\n", accountBalance[accountIndex]);

	printf("[Press ENTER to return account page]");
	gets(enter);
	loggedIn(accountIndex);

}

void clearScreen(char title[50]) {
	system("cls");
	printf("[%s]\n", title);
	printf("[Press [0] to return back to menu]\n\n");
}

void isZero(int zero, char stringZero[1024]) {
	if (zero == 0)
		menu();
	if (strcmp(stringZero, "0") == 0)
		menu();
}