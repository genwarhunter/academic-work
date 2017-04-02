#include <stdio.h>
#include "vector.h"

int main(){

	Vector vec1, vec2, vec3, sumVector, subVector, multVector,vecProduct;
	int scalProduct;

	vec1 = createVectorByCoordinates(1,2,3);
	vec2 = createNullVector();
	vec3 = createUnitVector();

	sumVector = sumOfVectors(vec1, vec3);

	subVector = subVectors(vec1, vec3);

	multVector = multVectorByNumber(vec1, 3);

	scalProduct = scalarProduct(vec1, vec3);

	vecProduct = vectorProduct(vec1,vec3);

	printf("Vector 1 = %s\nVector 2 = %s\nVector 3 =  %s\nSum of Vectors 1 and 2 = %s\nSub of Vectors 1 and 2 = %s\nMultiplication vector 1 by 3 = %s\nScalar product of vector 1 and vector 3 = %d\nVector Product of vector 1 and vector 3 = %s\n",
		    vecToString(vec1), vecToString(vec2), vecToString(vec3),
		    vecToString(sumVector),
		    vecToString(subVector),
		    vecToString(multVector),
		    scalProduct,
		    vecToString(vecProduct));

	if(compareVectors(vec1, vec3))
		printf("Vector 1 and Vector 3 are equals\n");
	else
		printf("Vector 1 and Vector 3 are not equals\n");
	if(compareVectors(vec1, vec1))
		printf("Vector 1 and Vector 1 are equals\n");
	else
		printf("Vector 1 and Vector 1 are not equals\n");

	return 0;
}
