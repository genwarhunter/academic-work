#include "stdafx.h"
#include <stdlib.h>
#include "string.h"



int comb(int k, int n, int** mass);

int main() {
	int k, n, **mass;
	scanf_s("%d %d", &k, &n);
	mass = (int**)malloc(sizeof(int*)*(k + 1));
	for (int i = 0; i <= k; i++) {
		mass[i] = (int*)malloc(sizeof(int)*(n + 1));
		memset(mass[i], -1, (n + 1) * sizeof(int));
	}
	comb(k, n, mass);
	comb(k, n, mass);
	printf("\nNumber of combinations: %d\n", mass[k][n]);
	system("pause");
	return 0;
}

int comb(int k, int n, int **mass)
{

	if (mass[k][n] != -1)
		return mass[k][n];
	if (n<k)
		mass[k][n] = 0;
	else if (k == n || k == 0)
		mass[k][n] = 1;
	else if (k == 1)
		mass[k][n] = n;
	else
		mass[k][n] = comb(k - 1, n - 1, mass) + comb(k, n - 1, mass);
	return mass[k][n];
}
