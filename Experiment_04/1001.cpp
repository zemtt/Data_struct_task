#include<iostream>
using namespace std;

typedef struct LNode{
    struct LNode *front;
    struct LNode *next;
    int data;
}LNode, *LinkList;

void CreatList(LinkList &a, int len){
    LNode *p = a;
    a->front = NULL;
    while(len--){
        p->next = new LNode;
        cin>>p->next->data;
        p->next->front = p;
        p = p->next;
    }
    p->next = NULL;
}

void Sort(LinkList a){
    LNode *b, *e, *p;
    b = a;
    p = b->next;
    e = NULL;
    int f = 1;
    while(!e||b->next != e){
        if(f){
            if(p->next == e){
                if(e)   e = e->front;
                else    e = p;
                f = 0;
            }
            else{
                if(p->data>p->next->data){
                    LNode *t1 = p->front;
                    LNode *t2 = p->next;
                    LNode *t3 = t2->next;
                    t1->next = t2;
                    t2->next = p;
                    p->next = t3;
                    if(t3)  t3->front = p;
                    p->front = t2;
                    t2->front = t1;
                }
                else    p = p->next;
            }
        }
        else{
            if(p->front == b){
                b = b->next;
                f = 1;
            }
            else{
                if(p->data<p->front->data){
                    LNode *t1 = p->next;
                    LNode *t2 = p->front;
                    LNode *t3 = t2->front;
                    t1->front = t2;
                    t2->front = p;
                    p->front = t3;
                    if(t3)  t3->next = p;
                    p->next = t2;
                    t2->next = t1;
                }
                else    p = p->front;

            }
        }
    }
}

void Show(LinkList a){
    LNode * p = a->next;
    int f = 0;
    while(p){
        if(f)   cout<<' ';
        else    f = 1;
        cout<<p->data;
        p = p->next;
    }
    cout<<endl;
}

void ClearList(LinkList a){
    
}

int main(){
    int n;
    LinkList a = new LNode;
    while(1){
        cin>>n;
        if(!n)  break;
        CreatList(a, n);
        Sort(a);
        Show(a);
        ClearList(a);
    }
}
