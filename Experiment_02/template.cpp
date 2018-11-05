#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000
typedef int Status;

typedef struct{
    ELEMTYPE* top;
    ELEMTYPE *data;
    int stack_size;
}Stack;

Status InitStack(Stack& a){
    a.base = new int[MAX];
    if(!a.base) exit(OVERFLOW);
    a.top = a.base;
    a.stack_size = MAX;
    return OK;
}

Status ClearStack(Stack& a){
    a.top = a.base;
}

Status Push(Stack& a, ELEMTYPE e){
    a.top++ = e;
}

Status Pop(Stack& a, ELEMTYPE& e){
    if(a.top == a.base) return ERROR;
    else e = --a.top;
    return OK;
}

Status GetTop(Stack a, ELEMTYPE& e){
    e = a.top--;
}