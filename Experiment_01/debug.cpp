#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
using namespace std;
typedef int Status;

typedef struct LNode{
	struct LNode *next;
	int data;
}LNode,*LinkList;

Status CreatList(LinkList &L,int n)
{
	L=new LNode;
	L->next=NULL;
	LNode *r=L;
	while(n--)
	{
		LNode *p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	return OK;
}


int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		LinkList a,b;
		CreatList(a,n);
		CreatList(b,m);
		LNode *p=a->next,*q=b,*pc=a;
		while(p&&q->next)
		{
			if(p->data > q->next->data)
			{
			    pc->next=q->next;
			    q=q->next;
				pc=pc->next;
				
			}
			else if(p->data < q->next->data)
			{
				pc->next=p;
				p=p->next;
				pc=pc->next;
			}
			else
			{
				pc->next=p;
				p=p->next;
				LNode *r=q->next;
				q->next=r->next;
				delete r;
			}
			p=p->next;
			q=q->next;
		}
		if(p)
		{
			pc->next=q->next;
			q=q->next;
		}
		if(q->next)
		{
			pc->next=p;
			p=p->next;
		cout<<"ZaoShangHao"<<endl;
		}
		pc=a;
		cout<<'1';
		while(pc)
		{
			cout<<'1';
			cout<<pc->data<<' ';
			pc=pc->next;
		}
		
	}
}

