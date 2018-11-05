#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct{
    int top[2], bot[2];
    int *data;
    int max_size;
}Stack;

Status InitStack(Stack& a, int max_size){
    a.top = 0;
    a.bot = 0;
    a.max_size = max_size;
    a.data = new int[max_size];
}

Status PushStack(Stack& a, )