//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//#include <sys/unistd.h>
#include <stdio.h>
//#include <stdlib.h>

static inline unsigned long long GetNTime()//有时候没有static编译失败
{
	__asm ("RDTSC");
}
#define CPU_FREQUECE (1000 * 1000 * 1000 * 9/5)   //我的电脑cpu主频是1.8GHz
unsigned long long millionSecond_set = 0;
unsigned long long millionSecond_get = 0;
unsigned long long percentage = 0;
unsigned long long i = 0;
int main()
{
	unsigned long long time1_nanosec_end, time_naosec_start;

	time_naosec_start = GetNTime();
	//printf("%d\n", sizeof time);
	millionSecond_set = 1;
    for(;i < 100000;i++)
    {
        //i = i +1;
    }
	//Sleep(millionSecond_set);((millionSecond_set > millionSecond_get)?(millionSecond_set - millionSecond_get):(millionSecond_get - millionSecond_set   ))
	time1_nanosec_end = GetNTime();
	printf("%u\n", time_naosec_start);
	printf("%u\n", time1_nanosec_end);
	printf("%u \n", (time1_nanosec_end - time_naosec_start)*5/9);//一个计数相当于1/(CPU主频Hz数)秒  我的电脑是1.8GHz
	printf("%u 毫秒\n",millionSecond_get = 1000* (time1_nanosec_end - time_naosec_start)*5/9/(1000*1000*1000) );
	printf("%u 纳秒\n",1000 * 1000* (time1_nanosec_end - time_naosec_start)*5/9/(1000*1000*1000)  );
    percentage  =  10000*((millionSecond_set > millionSecond_get)?(millionSecond_set - millionSecond_get):(millionSecond_get - millionSecond_set   ))/((millionSecond_set > millionSecond_get)?(millionSecond_set):(millionSecond_get  ));
    printf("%u%%%% \n", percentage);
	return 0;
}
