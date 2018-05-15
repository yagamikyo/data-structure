//
//  main.c
//  Stack_linklist
//
//  Created by 许珍 on 2018/5/15.
//  Copyright © 2018 yagami. All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"

typedef int Elemtype;
/*构建结构体*/
struct Stack{
    Elemtype data;
    struct Stack*next;
};

struct Stack* HEAD=NULL;

/*创建节点*/
struct Stack* createnode(){
    struct Stack*node=(struct Stack*)malloc(sizeof(struct Stack));
    node->next=NULL;
    return node;
};

/*查询总长度*/
int length(){
    if(HEAD==NULL) return 0;
    int len=0;
    for(struct Stack* p=HEAD;p!=NULL;p=p->next)
        len++;
    return len;
};

/*查询栈顶*/
Elemtype top(){
    if(HEAD==NULL) return -1;
    return HEAD->data;
};

/*放入元素*/
void push(Elemtype e){
    struct Stack*node=createnode();
    node->data=e;
    node->next=HEAD;
    HEAD=node;
};

/*弹出元素*/
Elemtype pop(){
    if(HEAD==NULL) return -1;
    struct Stack* p;
    Elemtype e=HEAD->data;
    p=HEAD;
    HEAD=p->next;
    free(p);
    return e;
};

/*测试*/
int main() {
    for(Elemtype i=1;i<20;i++)
        push(i);
    Elemtype e=length();
    printf("length= %d \n",e);
    for(Elemtype j=0;j<10;j++)
        printf("pop= %d \n",pop());
}
