#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	struct tm *ltime;
	time_t rawTime;
	time_t rawTimeTmp;
	char timeStr[20];
	time(&rawTime);
	printf("time\(&rawTime\)�ķ���ֵ�ǣ�%d\n",rawTime);
	ltime = localtime(&rawTime);
	strftime(timeStr, sizeof timeStr, "%H:%M:%S", ltime);
	printf("ת��struct tm��ʽ��%s\n", timeStr);
	int i = 0;
	while (1)
	{
		Sleep(2000);
		rawTimeTmp = rawTime;
		if (time(&rawTime) && rawTime > rawTimeTmp)
		{
			ltime = localtime(&rawTime);
			strftime(timeStr, sizeof timeStr, "%H:%M:%S", ltime);
			printf("%d,����ʱ���ǣ�%s\n",i++, timeStr);
		}

	}


}
