/*

Project started at 19/10/2023 10:44 PM

This is a calculator project

Calculator stage 1 completed at >> 19/10/2023 11:08 PM

*/


#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)




float sum(float num1, float num2);
float minus(float num1, float num2);
float multiply(float num1, float num2);
float devide(float num1, float num2);
void calculator();


void main_calculator() {
	calculator();
	system("cls");
	printf("[Thank you for using our calculator]\n\n\n\n\n\n\n");
	system("exit");
}

float sum(float num1, float num2) {
	printf("%f + %f = %f", num1, num2, num1+num2);
	return 0;
}

float minus(float num1, float num2) {
	printf("%f - %f = %f", num1, num2, num1 - num2);
	return 0;
}

float multiply(float num1, float num2) {
	printf("%f x %f = %f", num1, num2, num1 * num2);
	return 0;
}

float devide(float num1, float num2) {
	printf("%f / %f = %f", num1, num2, num1 / num2);
	return 0;
}

void calculator() {
	float num1;
	float num2;
	int function;
	char yn;

	system("cls");
	printf("[Calculator]\n\n");
	printf("Please input the first number >> ");
	scanf("%f", &num1);
	rewind(stdin);

	printf("Please input the second number >> ");
	scanf("%f", &num2);
	rewind(stdin);

	system("cls");
	printf("[Calculator]\n\n");
	printf("Select the function for it :\n");
	printf("[1] sum\n");
	printf("[2] minus\n");
	printf("[3] multiply\n");
	printf("[4] devide\n\n");

	printf("Enter your selection >> ");
	scanf("%d", &function);
	rewind(stdin);

	system("cls");
	printf("[Calculator]\n\n");

	switch (function) {
	case 1:
		sum(num1, num2);
		break;
	case 2:
		minus(num1, num2);
		break;
	case 3:
		multiply(num1, num2);
		break;
	case 4:
		devide(num1, num2);
		break;
	default:
		printf("\n[Error input]");
	}

	printf("\nDo you want to make another calculation ? (y/n)\n>> ");
	scanf("%c", &yn);

	if (yn == 'y' || yn == 'Y')
		calculator();
}
