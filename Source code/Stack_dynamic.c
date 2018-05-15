//
//  main.c
//  stack_dynamic
//
//  Created by 许珍 on 09/05/2018.
//  Copyright © 2018 yagami. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 4
typedef int ElemType;
/*构建结构体*/
struct Stack{
    ElemType* elems;  //内容值
    int length;       //当前位置
    int TOTAL_SIZE;   //总长度
};

/*初始化堆栈*/
struct Stack initStack(){
    struct Stack S;
    S.TOTAL_SIZE=STACK_SIZE;
    S.elems=(ElemType*)malloc(S.TOTAL_SIZE*sizeof(stack_t));  //申请空间
    S.length=0;     //当前位置清零
    return S;
};

/*动态分配空间*/
void expandStack(struct Stack* S){
    S->TOTAL_SIZE *=2;
    S->elems=(ElemType*)realloc(S->elems,sizeof(ElemType)*S->TOTAL_SIZE);
};

/*确认是否为空*/
bool isEmpty(struct Stack S){
    return S.length==0;
};

/*确认当前放入总数*/
int length(struct Stack S){
    return S.length;
};

/*清空堆栈*/
void clearStack(struct Stack* S){
    S->length=0;
    S->TOTAL_SIZE=0;
    S->elems=NULL;
};

/*返回当前顶部内容值*/
ElemType top(struct Stack S){
    if(isEmpty(S))return -1;
    return S.elems[S.length-1];
};

/*放入元素*/
void push(struct Stack* S,ElemType e){
    if(length(*S)>=S->TOTAL_SIZE)
        expandStack(S);
    S->elems[S->length++]=e;
};
/*弹出元素并返回*/
ElemType pop(struct Stack*S){
    if(isEmpty(*S))return -1;
    return S->elems[--S->length];
}
/*输入当前堆栈内所有元素*/
void stackTraverse(struct Stack S){
    printf("[%d/%d]",S.length,S.TOTAL_SIZE);
    for(int i=0;i<S.length;i++)
        printf("%d",S.elems[i]);
    printf("\n");
}

/*测试*/
int main() {
    struct Stack S=initStack();
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    stackTraverse(S);
    pop(&S);
    pop(&S);
    stackTraverse(S);
}
