#include <stdio.h>


/*struct indeksi
{
	int mini;
	int maxi;
};

struct indeksi minmax(int* X, int n)
{

	struct indeksi rezultat;

	int min = X[0];
	int max = X[0];
	rezultat.mini = 0;
	rezultat.maxi = 0;

	for (int i = 0; i < n; i++)
	{
		if (X[i] > max)
		{
			rezultat.maxi =i;
			max = X[i];
		}
		else if (X[i]<min)
		{
			rezultat.mini = i;
			min = X[i];
		}	
	}
	return rezultat;
}


int main()
{
	int X[50];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
			scanf("%d", &X[i]);
		
	}

for (int i = 0; i < n; i++)
	{	
			printf("\t %d", X[i]);	
	}

printf("\n");

	struct indeksi pozicije = minmax(X, n);

	printf("Min index: %d, min vrednost: %d \n", pozicije.mini, X[pozicije.mini]);
	printf("Max indeks: %d, max vrednost: %d \n", pozicije.maxi, X[pozicije.maxi]);
}*/