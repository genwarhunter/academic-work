#include "stdafx.h"
#include <stdlib.h>


int comparison(const int *a, const int *b)
{
	return(*a - *b);
}

int main()
{
	int size;
	scanf_s("%d", &size);
	int *mass;
	mass= (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
		scanf_s("%d", &mass[i]);
	printf("\n");
	system("cls");
	for (int i = 0; i < size; i++)
		printf("%d", mass[i]);
	printf("\n");
	qsort(mass, size, sizeof(int), (int(*) (const void *, const void *)) comparison);
	for (int i = 0; i < size; i++)
		printf("%d", mass[i]);
	getchar();
	getchar();
    return 0;
}

