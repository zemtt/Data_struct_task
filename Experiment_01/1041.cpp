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
	struct LNode* next;
}LNode, *LinkList;

Status InitLinkList(LinkList &L){
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i, int&e){
	LNode* p = L->next;
	for(int k=1;k<i;k++){
		if(!p->next)	return ERROR;
		p = p->next;
	}
	e = p->elem;
	return OK;
}

LNode* LocateElem(LinkList L, int e){
	LNode* p = L->next;
	while(p){
		if(e=p->elem)
			return p;
		p = p->next;
	}
	return NULL;
}

Status ListInsert(LinkList& L, int i, int e){
	LNode* p = L;
	for(int k=1;k<i;k++){
		if(!p->next)	return ERROR;
		p = p->next;
	}
	LNode* t = new LNode;
	t->elem = e;
	t->next = p->next;
	p->next = t;
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
	else{
		L->next = NULL;
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

Status CreatList(LinkList& a, int n){
	LNode* p = a;
	for(int i=0;i<n;i++){
		p->next = new LNode;
        p->next->elem = i+1;
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

LNode* Go(LNode *p, LNode *head, int steap){
    if(steap==1)    return p;
    else{
        if(p->next){
            return Go(p->next, head, steap-1);
        }
        else{
            return Go(head, head, steap-1);
        }
    }
}

void King(LinkList& a, int k){
    LNode *head = a->next, *s = a->next;
    LNode *t;
    int f=0;
    while(head){
        t = Go(s, head, k);
        if(t==head){
            head = head->next;
            if(f)	cout<<' ';
			else f=1;
			cout<<t->elem; 
            delete t;
            s = head;
        }
        else{
            LNode *pre = head;
            while(pre->next != t)
                pre = pre->next;
            pre->next = t->next;
            if(f)	cout<<' ';
			else f=1;
			cout<<t->elem; 
            delete t;
            if(pre->next)
                s = pre->next;
            else
                s = head;
        }
    }
    cout<<endl;
}

int main(){
	int len, k;
	LinkList a;
	InitLinkList(a);
	while(1){
		int count = 0;
		cin>>len>>k;
		if(!len)	break;
		CreatList(a,len);
        King(a,k);
	}
}
