#include <stdio.h>

int zbir(int i)
{
	int temp=0;
	int zbir = 0;
	while (i>0)
	{
		temp = i % 10;
		zbir += temp;
		i /= 10;
	}
	return zbir;
}

static int provera(int i)
{
	while (1)
	{
		if (i >= 100 && i < 1000)
			return i;
		printf("Uneo si broj koji nije trocifren, pokusaj opet:");
		scanf_s(" %d", &i);
	}
}

void main()
{
	int k = 0;
	int f = 0;
	int c = 0;
	int z;

	printf("Unesi do kog broja zelis da ide provera:");
	scanf_s(" %d", & f);
	f=provera(f);
	printf("\nUnesi dodatni test parametar k:");
	scanf_s(" %d", &k);
	printf("\nDeljivi brojevi su:\n");

	for (int i = 100; i <= f;i++)
	{
		z = zbir(i);
		if (z % 17 == 0 && i%k==0)
		{
				c++;
				printf("%d) %d\n", c, i);
		}
	}
}