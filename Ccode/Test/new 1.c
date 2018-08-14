#include <stdio.h>
int main()
{
	char str[] = "\012";
	printf("%d", strlen("ab\n\\012/\\\""));
	int i = 0;
	while(i < 5)
	{
		printf("%d:%c\r\n",i,str[i]);
		i++;
	}
	return 0;
}
