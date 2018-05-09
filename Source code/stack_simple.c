//
//  main.c
//  test1
//
//  Created by 许珍 on 08/05/2018.
//  Copyright © 2018 yagami. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 5

typedef int ElemType;

struct Stack{
    ElemType elems[STACK_SIZE];
    int stacksize;
};

int length(struct Stack S){
    return S.stacksize;
}

bool isEmpty(struct Stack S){
    if (S.stacksize==0)
        return 1;
    else return 0;
}

void clearStack(struct Stack *S){
    S->stacksize = 0;
}

ElemType top(struct Stack S){
    if (isEmpty(S))
        return -1;
    return S.elems[S.stacksize-1];
}

ElemType pop(struct Stack *S){
    if (isEmpty(*S))
        return -1;
    return S->elems[--S->stacksize];
}

ElemType push (struct Stack *S, ElemType e){
    if (length(*S)>=STACK_SIZE)
        return -1;
    S->elems[S->stacksize++] = e;
    return e;
}

void stackTraverse(struct Stack S){
    for(int i=0; i<S.stacksize; i++)
        printf("%d", S.elems[i]);
    printf("\n");
}

int main() {
    struct Stack s;
    clearStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    stackTraverse(s);
    pop(&s);
    pop(&s);
    stackTraverse(s);
    return 0;
}
