/*
时间：2017年4月6日
程序目的：输入无向图，判断是否为二分图
作者：tanf



*/
#include <stdio.h>

#define INF  0



//入参i为顶底序号   color为染的颜色（1或者-1） 值得参考的地方如何传递二维数组和一维数组
bool dfs(int i,int c, int** G,int size,int* color)
{
	color[i] = c;
	for(int j = 0;j < size;j++)
	{	
		if(1 == *((int*)G + size*i + j))
		{
			if(c == color[j]) return false;
			if(0 == color[j] && !dfs(j,-c,G,size,color)) return false;
		}
	}
	return true;
	
}


int main()
{
	int point_num,line;
	
	scanf("%d %d",&point_num,&line);
	int color[point_num];
	int G[point_num][point_num];
	for(int i = 0;i < point_num;i++)
	{	
		for(int j = 0;j < point_num;j++)
		{	
			G[i][j] = INF;
		}
		color[i] = 0;
	}
	while(line--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		G[x][y] = 1;
		G[y][x] = 1;//tanf 无向图设置
	}
	/*展示图数据
	for(int i = 0;i < point_num;i++)
	{	
		for(int j = 0;j < point_num;j++)
		{	
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}*/


	for(int i = 0;i < point_num;i++)
	{
		if(0 == color[i])
			if(!dfs(i,1,(int**)G,point_num,color))
		    {
				printf("No\n");
				return -1;
			}
	
	}
	printf("Yes\n");
	return 0;
	
}






