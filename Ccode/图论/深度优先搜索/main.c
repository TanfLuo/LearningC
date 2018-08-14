#include <stdio.h>

#define MAX_V 100
//varibles and functions for dfs_search
typedef enum 
{ 
	White,
	Black,
	Gray 
}vertexColor;

vertexColor color[MAX_V];
int pre[MAX_V];
int dis[MAX_V];
int fin[MAX_V];
int counter;

void depthFirstSearch(int s);
void dfs_visit(int u);


//varibles and func for graph
struct Node {
	int node_index;
	int weight;
	struct Node* next;
}*head[MAX_V];

struct {
	int V;
	int E;
	//struct node* head;
} Gragh;

void Init()
{
	memset(head, 0, sizeof head);
	Gragh.E = 0;
	Gragh.V = 0;
	//Gragh.head = head;

}

struct Node node_pool[MAX_V];
int t = 0;

void add_node(int p1, int p2, int weight)
{
	struct Node *p = &node_pool[t++];
	p->node_index = p2; p->weight = weight; 
	p->next = head[p1];
	head[p1] = p;
	
}



int main(void)
{
	int num_node, num_edge, p1, p2, weight = 1;
	Init();
	freopen("d:\\my.txt", "r", stdin);
	scanf("%d %d", &num_node, &num_edge);
	printf("%d %d\n",  num_node,  num_edge);
	Gragh.E = num_edge; Gragh.V = num_node;

	while (num_edge > 0)
	{
		scanf("%d %d %d", &p1, &p2, &weight);
		printf("%d %d %d\n",  p1,  p2,  weight);
		add_node(p1, p2, weight);
		//add_node(p2, p1, weight);
		num_edge -= 1;
	}

	depthFirstSearch(0);

	int i;
	printf("color: ");
	for(i = 0;i < Gragh.V;i++)
	{
		printf("%d ",color[i]);
	}
	printf("\n");
	printf("dis:   ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", dis[i]);
	}
	printf("\n");
	printf("fin:   ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", fin[i]);
	}
	printf("\n");
	printf("pre:   ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", pre[i]);
	}
	printf("\n");




	
}



void depthFirstSearch(int s)
{
	
	int i;
	counter = 0;
	for (i = 0; i < Gragh.V; i++)//没有完全初始化的问题？？
	{
		dis[i] = fin[i] = pre[i] = -1;
		color[i] = White;
	}
	
	dfs_visit(s);
	//int i;
	printf("color: ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", color[i]);
	}
	printf("\n");
	printf("dis:   ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", dis[i]);
	}
	printf("\n");
	printf("fin:   ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", fin[i]);
	}
	printf("\n");
	printf("pre:   ");
	for (i = 0; i < Gragh.V; i++)
	{
		printf("%d ", pre[i]);
	}
	printf("\n");

	for (i = 0; i < Gragh.V; i++)
	{
		if (color[i] == White)
		{
			dfs_visit(i);
		}
	}
}

void dfs_visit(int u)
{
	color[u] = Gray;
	dis[u] = ++counter;
	struct Node* tmp_p_node = head[u];
	while (tmp_p_node)
	{
		int v = tmp_p_node->node_index;
		if (color[v] == White)
		{
			pre[v] = u;
			dfs_visit(v);
		}
		tmp_p_node = tmp_p_node->next;
	}
	color[u] = Black;
	fin[u] = ++counter;
}
