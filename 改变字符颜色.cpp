#include<stdio.h>
#include <windows.h>
int main()
{
	printf("default\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("FORGROUND_RED\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("FORGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN + FOREGROUND_RED);
	printf("yellow\n");
	return 0;
}