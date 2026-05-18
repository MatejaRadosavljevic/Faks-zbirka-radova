#include <stdio.h>

int main()
{
	int A[10][10];
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("A[%d][%d] = ", i, j);
			scanf("%d",&A[i][j]);
		}
	}

	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j <= m; j++) 
		{
			for (int k = 0; k <= m - k; k++) 
			{
				if (A[i][k] > A[i][k + 1])
				{
					
					int temp = A[i][k];
					A[i][k] = A[i][k + 1];
					A[i][k + 1] = temp;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
	return;
}