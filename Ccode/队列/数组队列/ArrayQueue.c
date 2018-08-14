#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct queue //��������Ķ���ʵ�֣���β�α꣩
{
	int store[N];
	int front;
	int rear;
}Queue;

void init_queue(Queue*q)
{
	q->front = q->rear = 0;
}

void inqueue(Queue*q, int data)
{
	if ((q->rear + 1) % N == q->front)//������ 
	{
		printf("queue is full now,inqueue failed\n");
		return;
	}
	else//���� 
	{
		q->store[q->rear] = data;
		q->rear = (q->rear + 1) % N;
	}
}

int dequeue(Queue*q)
{
	int temp;
	if (q->front == q->rear)//�����ǿ� 
	{
		printf("queue is empty,dequeue failed\n");
		return -1;
	}
	temp = q->store[q->front];//���зǿ� 
	q->front = (q->front + 1) % N;
	return temp;

}

int main()
{
	int i;
	Queue*q = (Queue*)malloc(sizeof(Queue));
	init_queue(q);
	for (i = 0; i<10; i++)
		inqueue(q, i);
	while (q->front != q->rear)
	{
		printf("\r\n%d", dequeue(q));
	}
}

