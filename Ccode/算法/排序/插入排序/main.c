#include <stdio.h>
#include <stdlib.h>

//另一个用memmove的插入排序实现提高大量内存移动的效率
int main(void)
{
	int a[10] = { 3,3,5,2,1,6,4,9,0,8 };
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
	for (i = 1; i < 10; i++)
	{
		int j = i - 1;
		int tmp = a[i];
		while (j >= 0 && tmp < a[j])
		{
			
			//a[i] = a[i - 1];
			a[j + 1] = a[j];
			j--;
		}
		a[j +  1] = tmp;
	}
	//printf("%d ", strlen(a));
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	system("pause");

}