#include <stdio.h>

int main()
{
	char s[256];
	char rez[256];
	int n=0, i, j, k;
	int razmak_poz=-1, razmak=0;

	//fgets(s, sizeof(s), stdin); 
	scanf("%[^\n]", s);

	while (s[n] != '\0')
		n++;

		i = n - 1;
		while (i >= 0 && razmak == 0)
		{
			if (s[i] == ' ')
			{
				razmak_poz = i;
				razmak = 1;
			}
			else
			{
				i--;
			}
		}
		
		if (razmak == 1)
		{
			k = 0;

			j = razmak_poz + 1;

			while (s[j] != '\0')
			{
				rez[k] = s[j];
				k++;
				j++;

			}


			rez[k] = ' ';
			k++;

			j = 0;
			while (j < razmak_poz)
			{
				rez[k] = s[j];
				k++;
				j++;
			}

			rez[k] = '\0';

			j = 0;
			while (rez[j] != '\0')
			{
				s[j] = rez[j];
				j++;

			}
			s[j] = '\0';
		}

		printf("%s", s);
		//return 0;
}