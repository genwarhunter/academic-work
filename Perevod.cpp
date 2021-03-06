#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void openFiles(int argc, char * argv[], FILE **input, FILE **output);
void closeFiles(int argc, char * argv[], FILE **input, FILE **output);
void readString(char *A, FILE *input);

int main(int argc, char *argv[]) {
	FILE *input, *output;
	char A[100];
	input = NULL;
	output = NULL;
	openFiles(argc, argv, &input, &output);
	readString(A, input);
	for (int i = 0; i < strlen(A); i++) {
		if (isalpha(A[i])) {
			if (isupper(A[i]))
				A[i]= tolower(A[i]);
			else A[i] = toupper(A[i]);
		}
	}
	fprintf(output,"A: %s Length A: %d\n", A, strlen(A));
	closeFiles(argc, argv, &input, &output);
	system("pause");
	return 0;
}

void openFiles(int argc, char * argv[], FILE **input, FILE **output)
{
	if (argc>1)
	{
		for (int i = 1; i<argc; i++)
		{
			if (!strcmp(argv[i], "-input") && argc >= i + 2)
			{
				if (strcmp(argv[i + 1], "-output"))
				{
					*input = fopen(argv[i + 1], "r");
				}
			}
			else if (!strcmp(argv[i], "-output") && argc >= i + 2)
			{
				if (strcmp(argv[i + 1], "-input"))
				{
					*output = fopen(argv[i + 1], "w");
				}
			}
		}
	}
}

void closeFiles(int argc, char * argv[], FILE **input, FILE **output)
{
	if (*input != NULL)
	{
		fclose(*input);
	}
	if (*output != NULL)
	{
		fclose(*output);
	}
}

void readString(char *A, FILE *input)
{
	if (input == NULL)
	{
		printf("Enter string A : ");
		fgets(A, 98, stdin);
	}
	else
	{
		fgets(A, 98, input);
	}
}
