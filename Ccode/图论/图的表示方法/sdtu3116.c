#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 5000
int main(void)
{
	
	int n,m,i,j;
	int p1, p2;
	int check_num;
	int g[MAX_POINT][MAX_POINT];
	for (p1 = 0; p1 < MAX_POINT; p1++)
		for (p2 = 0; p2 < MAX_POINT ;p2++)
			g[p1][p2] = -1;
	while (1)
	{
		scanf("%d %d", &n, &m);
		
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &p1, &p2);
			g[p1][p2] = 1;
		}

		
		scanf("%d", &check_num);
		for (i = 0; i < check_num; i++)
		{
			scanf("%d %d", &p1, &p2);
			if (1 == g[p1][p2])
				printf("Yes\n");
			else
				printf("No\n");
		}

	}
	return 0;
}