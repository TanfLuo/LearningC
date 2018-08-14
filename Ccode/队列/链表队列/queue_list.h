#ifndef _QUEUE_LIST_H  
#define _QUEUE_LIST_H  

#define ElementType int  
struct Node;
struct QNode;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;


void FatalError(const char* str);
void Error(const char* str);
int IsEmpty(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);


#endif /* _QUEUE_LIST_H */  
