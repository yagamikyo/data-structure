//
//  main.c
//  queue
//
//  Created by 许珍 on 2018/5/15.
//  Copyright © 2018 yagami. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#define QSIZE 8
typedef int ElemType;
/*构建结构体*/
struct Queue{
    ElemType elem[QSIZE];
    bool full;
    int front;
    int rear;
};

/*初始化*/
struct Queue initQueue(){
    struct Queue q;
    q.full=false;
    q.front=0;
    q.rear=0;
    return q;
};
/*查询是否为空*/
int empty(struct Queue* q){
    return q->front==q->rear && q->full==false;
};

/*查询长度*/
int size(struct Queue* q){
    if(q->full) return QSIZE;
    return (QSIZE+q->rear-q->front)%QSIZE;
}
/*放入元素*/
void enqueue(struct Queue* q,ElemType e){
    if(q->full) return;
    if(size(q)+1==QSIZE)
        q->full=true;
    q->elem[q->rear]=e;
    q->rear=(q->rear+1)%QSIZE;
};
/*弹出元素*/
ElemType dequeue(struct Queue* q){
    if(empty(q)) return -1;
    ElemType e;
    e=q->elem[q->front];
    q->front=(q->front+1)%QSIZE;
    q->full=false;
    return e;
};
/*测试*/
int main() {
    struct Queue q=initQueue();
    for(int i=0;i<7;i++)
        enqueue(&q, i);
    printf("size = %d \n",size(&q));
    for(int j=0;j<5;j++)
        printf("dequeue = %d \n", dequeue(&q));
    printf("size = %d \n",size(&q));
}
