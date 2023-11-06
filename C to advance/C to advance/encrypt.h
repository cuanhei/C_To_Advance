// Encrypt and decrypt tools 
// Created on 5/11/2023




#define PASSWORD 'A'
const char rawArrangement[77] =       { ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '}', '{' ,'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const char encryptedArrangement[77] = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '_', '^', ']', '\\', '[', 'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A', '@', '?', '>', '=', '}', ';', '{', '#', '<', ':' ,'8', '9', '7', '5', '6', '2', '4', '1', '3', '0'};
char enter[10];

void encrypt();
void decrypt();

void encrypt_main() {
	system("cls");
	int input;
	printf("Press [1] to encrypt text into a file\n");
	printf("Press [2] to decrypt text from a file\n");
	printf(">> ");
	scanf("%d", &input);
	rewind(stdin);

	if (input == 1)
		encrypt();
	else if (input == 2)
		decrypt();
	else
		encrypt_main();
}
void decrypt() {

	char fileName[50];
	int i, x;

	system("cls");
	printf("Please enter the file name that you want to decrypt\n>> ");
	gets(fileName);
	rewind(stdin);

	FILE* file = fopen(fileName, "r");

	if (file == NULL) {
		printf("\n[Unable to open the file.]\n");
		_sleep(1000);
		decrypt();
	}

	fseek(file, 0, SEEK_END);
	int file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* file_content = (char*)malloc(file_size + 1);
	char* decryptedText = (char*)malloc(file_size + 1);

	fread(file_content, 1, file_size, file);

	file_content[file_size] = '\0';
	fclose(file);

	printf("\nThe content inside %s\n>> %s\n", fileName, file_content);

	for (i = 0; i < (int)strlen(file_content); i++) {
		if (file_content[i] != 0)
			file_content[i] -=PASSWORD;
		for (x = 0; x < 77; x++) {
			if (file_content[i] == encryptedArrangement[x]) {
				decryptedText[i] = rawArrangement[x];
				break;
			}
			else {
				decryptedText[i] = file_content[i]+PASSWORD;
			}
		}
	}

	decryptedText[file_size] = '\0';
	printf("\nThe decrypted text inside %s\n>> %s\n\n", fileName, decryptedText);

	printf("[Press Enter To Return Menu]");
	gets(enter);

	free(file_content);
	free(decryptedText);

	encrypt_main();
}
void encrypt() {
	system("cls");
	char rawText[1024];
	char encryptedText[1024];
	char fileName[50];
	int i, x, y;



	printf("Enter the text that you wanted to encrypt\n");
	printf(">> ");
	gets(rawText);
	rewind(stdin);

	for (i = 0; i < 1024; i++) {

		if (rawText[i] != 0)
			encryptedText[i] = rawText[i];
		else
			encryptedText[i] = 0;
	}

	for (i = 0; i < (int)strlen(encryptedText); i++) {
		for (x = 0; x < 77; x++) {
			if (encryptedText[i] == rawArrangement[x]) {
				encryptedText[i] = encryptedArrangement[x];
				encryptedText[i] +=PASSWORD;
			}
		}
	}
	printf("\nYour encrypted text is \n>> %s\n\n", encryptedText);

	do {
		printf("Please enter the file name to save current encrypted text\n>> ");
		gets(fileName);
	} while (strcmp(fileName, "") == 0);

	FILE* file = fopen(fileName, "w");
	fprintf(file, "%s", encryptedText);
	fclose(file);

	printf("\n[The encrypted text has been stored into %s]\n\n", fileName);
	printf("[Press Enter To Return Menu]");
	gets(enter);
	encrypt_main();
}