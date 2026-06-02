#include <stdio.h>


struct indeksi
{
	int mini;
	int maxi;
};

struct indeksi minmax(int* X, int n)
{

	struct indeksi rezultat;

	rezultat.mini = 0;
	rezultat.maxi = 0;


	for (int i = 1; i < n; i++)
	{
		if (X[i] > X[rezultat.maxi])
		{
			rezultat.maxi = i;
		}
		else if (X[i] < X[rezultat.mini])
		{
			rezultat.mini = i;
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

	struct indeksi pozicije = minmax(X, n);

	printf("Min index: %d, min vrednost: %d \n", pozicije.mini, X[pozicije.mini]);
	printf("Max indeks: %d, max vrednost: %d \n", pozicije.maxi, X[pozicije.maxi]);
}