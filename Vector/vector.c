#include "vector.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Vector createVectorByCoordinates(int x, int y, int z)
{
	Vector vec = {x,y,z};
	return vec;
}

Vector createNullVector()
{
	return createVectorByCoordinates(0,0,0);
}

Vector createUnitVector()
{
	return createVectorByCoordinates(1,1,1);
}

Vector sumOfVectors(Vector vec1, Vector vec2)
{
	return createVectorByCoordinates(vec1.x+vec2.x, vec1.y+vec2.y, vec1.z+vec2.z);
}

Vector subVectors(Vector from, Vector vec)
{
	return createVectorByCoordinates(from.x-vec.x, from.y-vec.y, from.z-vec.z);
}

Vector multVectorByNumber(Vector vec, int n)
{
	return createVectorByCoordinates(vec.x*n, vec.y*n, vec.z*n);
}

int scalarProduct (Vector vec1, Vector vec2)
{
	return vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
}

Vector vectorProduct (Vector vec1, Vector vec2)
{
	int x = vec1.y*vec2.z-vec2.y*vec1.z;
	int y= -1*(vec1.x*vec2.z-vec2.x*vec1.z);
	int z = vec1.x*vec2.y-vec2.x*vec1.y;
	return createVectorByCoordinates(x,y,z);
}

int compareVectors (Vector vec1, Vector vec2) // 1 - equal, 0 - nit equal
{
	if(vec1.x==vec2.x && vec1.y==vec2.y && vec1.z==vec2.z)
		return 1;
	else
		return 0;
}

char* vecToString(Vector vec)
{
	char buffer[100] = "\0";
	char fStr[3] = "( ";
	char diffStr[2] = ";";
	char sStr[3] = " )";
	char x[20] , y[20] , z[20] ;
	sprintf(x, "%d", vec.x);
	sprintf(y, "%d", vec.y);
	sprintf(z, "%d", vec.z);
	strcat(buffer,fStr);
	strcat(buffer,x);
	strcat(buffer,diffStr);
	strcat(buffer,y);
	strcat(buffer,diffStr);
	strcat(buffer,z);
	strcat(buffer,sStr);

	char *returned = (char*)malloc(sizeof(char)*strlen(buffer));
	for(int i=0;i<strlen(buffer);i++)
		returned[i] = buffer[i];
	return returned;
}