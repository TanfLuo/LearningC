#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct queue //基于数组的队列实现（首尾游标）
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
	if ((q->rear + 1) % N == q->front)//队列满 
	{
		printf("queue is full now,inqueue failed\n");
		return;
	}
	else//非满 
	{
		q->store[q->rear] = data;
		q->rear = (q->rear + 1) % N;
	}
}

int dequeue(Queue*q)
{
	int temp;
	if (q->front == q->rear)//队列是空 
	{
		printf("queue is empty,dequeue failed\n");
		return -1;
	}
	temp = q->store[q->front];//队列非空 
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

