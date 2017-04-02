#ifndef VECTOR_H
#define VECTOR_H

typedef struct VectorStruct{
	int x;
	int y;
	int z;
} Vector;

Vector createVectorByCoordinates(int x, int y, int z);

Vector createNullVector();

Vector createUnitVector();

Vector sumOfVectors(Vector vec1, Vector vec2);

Vector subVectors(Vector from, Vector vec);

Vector multVectorByNumber(Vector vec, int n);

int scalarProduct (Vector vec1, Vector vec2);

Vector vectorProduct (Vector vec1, Vector vec2);

int compareVectors (Vector vec1, Vector vec2); // 1 - equal, 0 - nit equal

char* vecToString(Vector vec);

#endif