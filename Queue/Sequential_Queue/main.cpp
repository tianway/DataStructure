//顺序队列
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear;
    //int size; 队列长度 队满size==MaxSize 队空size==0
    //int tag; 入队操作后设为1，出队操作后设为0，队满rear==front&&tag==1，队空rear==front&&tag==0
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false; //队列已满
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int &x) {
    if (Q.front == Q.rear)
        return false; //队列为空
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, int &x) {
    if (Q.front == Q.rear)
        return false; //队列为空
    x = Q.data[Q.front];
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);

    return 0;
}
