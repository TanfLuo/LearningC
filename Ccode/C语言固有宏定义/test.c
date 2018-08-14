#include<stdlib.h>
#include<stdio.h>

int main(void)
{
    //setlocale(LC_ALL, "zh_CN.UTF-8");
	printf("File    Fame: %s\n", __FILE__);
    printf("Present Line: %d\n", __LINE__);
	printf("Present Function: %s\n", __func__);
	printf("DATE: %s\n", __DATE__);
	printf("TIME: %s\n", __TIME__);
	printf("ISO标准 is iso standard: %d\n", __STDC__);
	printf("编译器标准 standard of compiler: %d\n", __STDC_VERSION__);
	printf("本地系统 full standard C: %d\n", __STDC_HOSTED__);
    system("PAUSE");
    return 0;
}