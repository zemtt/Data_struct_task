#include<iostream>
#include<cstring>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct LNode{
	int elem;
    struct LNode* pre;
	struct LNode* next;
}LNode, *LinkList;

Status InitLinkList(LinkList &L){
	L = new LNode;
	L->next = NULL;
    L->pre = NULL;
	return OK;
}

void InputList(LinkList& a, int n){
    LNode *p = a;
    for(int i=0;i<n;i++){
        if(p->pre){
            LNode *t = p->next;
            p->next = new LNode;
            cin>>p->next->elem;
            p->next->pre = p;
            p = p->next;
            p->next = a->next;
            a->next->pre = p;
        }
        else{
            p->next = new LNode;
            p=p->next;
            cin>>p->elem;
            p->next = p;
            p->pre = p;
        }
    }
}

LNode* GetP(LNode *head, int n){
    LNode *p = head->next;
    for(int i=0;i<n-1;i++)
        p = p->next;
    //cout<<"--"<<p->elem<<"--"<<endl;
    return p;
}

void ClearList(LNode *head){
    LNode *p = head;
    LNode *end = head->next->pre;
    int f = 0;
    do{
        p = p->next;
        LNode *t = p;
        if(f)
            cout<<' ';
        else
            f = 1;
        cout<<t->elem;
        delete t;
    }while(p!=end);
    cout<<endl;
}

void Swap(LNode *p,LNode *head){
    LNode *s, *pp, *e;
    pp = p->pre;
    s = pp->pre;
    e = p->next;
    s->next = p;
    p->next = pp;
    pp->next = e;
    e->pre = pp;
    pp->pre = p;
    p->pre = s;
    if(head->next == p){
        head->next = pp;
    }
    else if(head->next == pp){
        head->next = p;
    }
}

int main(){
	int len, k;
	LinkList a;
	InitLinkList(a);
	while(1){
		int count = 0;
		cin>>len;
		if(!len)	break;
		InputList(a,len);
        cin>>k;
        Swap(GetP(a, k), a);
        ClearList(a);
	}
}
