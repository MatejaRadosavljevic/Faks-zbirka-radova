#include <stdio.h>


void main()
{
	int n;
	scanf(" %d", &n);

	int A[n];
	float suma = 0;
	printf("Sad unosi elemente niza:\n");

	for (int i = 0; i < n; i++)
	{
		scanf("\n %d", &A[i]);
		suma += A[i];

	}

	float srednja = suma / n;
	int counter = 0;

	printf("\n %.2f", srednja);
	for (int i = 0; i < n; i++)
	{
		if (A[i] < srednja)
		{
			printf("\n %d", A[i]);
			counter++;
		}
	}
	printf("\n Elemenata manjih od proseka je:	%d", counter);
}