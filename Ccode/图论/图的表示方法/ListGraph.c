#include <stdio.h>

#define MAX_NODE_NUM

inline unsigned long long GetNTime()
{
	__asm ("RDTSC");
}

struct Node {
	int	node_index;
	int weight;
	struct Node * next;
}*head[MAX_NODE_NUM];

struct Node node_pool[1000];
int t = 0;

void add_node(int p1, int p2, int weight)
{
	//struct Node *ptr_alloc_Node = (struct Node*)malloc(sizeof(struct Node));  ///动态分配
	struct Node *ptr_alloc_Node = &node_pool[t++];    //静态分配空间  在添加是快几十倍
	ptr_alloc_Node->node_index = p2;
	ptr_alloc_Node->weight = weight;
	ptr_alloc_Node->next = head[p1];
	head[p1] = ptr_alloc_Node;
}

void Init(void)
{
	memset(head, 0, sizeof(struct Node));
}


int main(void)
{
	int num_node,num_edge,p1,p2,weight = 1;
	unsigned long long time1_nanosec_end, time_naosec_start;
	
	
	 
	
	Init();
	freopen("d:\\my.txt", "r", stdin);
	scanf("%d %d", &num_node, &num_edge);
	
	while (num_edge > 0)
	{
		scanf("%d %d %d", &p1, &p2,&weight);
		time_naosec_start = GetNTime();
		add_node(p1, p2, weight);
		time1_nanosec_end = GetNTime();
		add_node(p2, p1, weight);
		printf("%u纳秒\n", (time1_nanosec_end - time_naosec_start) * 5 / 9);
		printf("%u毫秒\n", (time1_nanosec_end - time_naosec_start) * 5 / 9 / 1000000);
		num_edge -= 1;
	}

	while (num_node > 0)
	{
		printf("与点%d邻接的点有：",num_node - 1);
		struct Node *ptr_node_tmp = head[num_node - 1];
		for (; ptr_node_tmp != NULL; ptr_node_tmp = ptr_node_tmp->next)
			printf("%d ", ptr_node_tmp->node_index);
		putchar('\n');
		num_node -= 1;
	}
}