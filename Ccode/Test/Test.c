#include<stdlib.h>
#include<stdio.h>

int main(void)
{
    int i;
    for(i = 0; i < 20; i++)// 这个20你也自己改
    {
        _sleep(200);// 停止200毫秒，自己修改到需要的时间
        printf(".");
    }
    printf("\n");
    system("PAUSE");
    return 0;
}