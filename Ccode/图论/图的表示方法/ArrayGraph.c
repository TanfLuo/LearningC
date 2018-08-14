/*
ʱ�䣺2017��4��6��
����Ŀ�ģ���������ͼ���ж��Ƿ�Ϊ����ͼ
���ߣ�tanf



*/
#include <stdio.h>

#define INF  0



//���iΪ�������   colorΪȾ����ɫ��1����-1�� ֵ�òο��ĵط���δ��ݶ�ά�����һά����
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
		G[y][x] = 1;//tanf ����ͼ����
	}
	/*չʾͼ����
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






