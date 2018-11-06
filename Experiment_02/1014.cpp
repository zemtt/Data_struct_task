#include<iostream>
#include<cstring>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct LNode{
	double elem;
	struct LNode* next;
}LNode, *LinkList;

Status InitLinkList(LinkList &L){
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status ListDelete(LinkList& L, int i){
	if(i<1) return ERROR;
	LNode* p = L;
	LNode* pp;
	for(int k=0;k<i;k++){
		if(!p->next)	return ERROR;
		pp = p;
		p = p->next;
	}
	LNode* t = pp->next;
	pp->next = t->next;
	delete t;
	return OK; 
}

Status ListClear(LinkList& L){
	if(L->next){
		ListClear(L->next);
		delete L->next;
	}
	return OK; 
}

int ListLen(LinkList a){
	int i=0;
	while(a->next){
		i++;
		a = a->next;
	}
	return i;
}

Status InputList(LinkList& a, int n){
	LNode* p = a;
	for(int i=0;i<n;i++){
		p->next = new LNode;
		cin>>p->next->elem;
		p=p->next;
	}
	p->next = NULL;
}

Status OutputList(LinkList a){
	LNode* p = a->next;
	int f=0;
	while(p){
		if(f)
			cout<<' ';
		else
			f=1;
		cout<<p->elem;
		p = p->next;
	}
	cout<<endl;
}

double CountAver(LinkList p, int len){
    if(len==1)    return p->elem;
    else    return  (CountAver(p->next, len-1)*(len-1)+p->elem)/len;
}

int main(){
    int len, t;
    LinkList a;
    InitLinkList(a);
    while(1){
        cin>>len;
        if(!len)    break;
        InputList(a, len);
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<CountAver(a->next,len)<<endl;
        ListClear(a);
    }
}

