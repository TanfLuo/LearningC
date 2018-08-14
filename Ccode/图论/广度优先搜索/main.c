#include <stdio.h>

#define MAX_V 100
#define ¡Þ 99999
//varibles and func for breadthFirstSearch
typedef enum
{
	White,
	Black,
	Gray
}vertexColor;

vertexColor color[MAX_V];
int pre[MAX_V];
int dist[MAX_V];
int counter;
void bfs(int s);


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

	




	
}



void bfs(int s)
{
	int i;
	for (i = 0; i < Gragh.V; i++)
	{
		pre[i] = -1;
		dist[i] = ¡Þ;
		color[i] = White;
	}
	color[s] = Gray;
	dist[s] = 0;

}