#include <stdlib.h>

int main(void)
{
	int a = 100;
	int *p = (void*)&a;
	printf("a = %d;",a);
	printf("*p = %d;", *p);
	p = NULL;
	printf(" p = %p;",  p);
	//*p -= 2;
	if(p == '\0')
		printf("yes; ");
	printf("\"nihao\":%p;", "nihao");
	printf("\"nihao\":%p;\n", &"nihao");
	const int *const_p = &a;
	{
	printf("a = %d; ", a);
	int* p1 = const_p;
	(*p1)--;
	printf("a = %d;", *const_p);
	
}
}