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

bool StackEmpty(Stack a){
    return s.top == s.base;
}

it StackLength(Stack a){
    return s.top - s.base;
}

Status ClearStack(Stack& a){
    a.top = a.base;
    return OK;
}

Status DestroyStack(Stack &s){
    delete s.base;
    s.max_size = 0;
    s.base = NULL;
    s.top = NULL;
    return OK;
}

Status Push(Stack& a, ELEMTYPE e){
    if(a.top - a.base == a.max_size)    return ERROR;
    *a.top++ = e;
    return OK;
}

Status Pop(Stack& a, ELEMTYPE& e){
    if(a.top == a.base) return ERROR;
    else e = *--a.top;
    return OK;
}

Status GetTop(Stack a, ELEMTYPE& e){
    if(a.top = a.base)  return ERROR;
    e = *(a.top-1);
    return OK;
}