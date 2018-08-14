#include <stdio.h>

int main(void)
{
	char str[200];
	int i = 6;
	freopen("d:\\my.txt", "r", stdin);
	
	while (i)
	{
		str[0] = '\0';
		scanf("%s", str);
		printf("%d:%s\n",i--, str);
		
	}
	return 0;
	
}