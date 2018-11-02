#include<iostream>
using namespace std;
typedef struct pnode
{
	int coef;
	int expn;
	struct pnode *next;
}pnode,*polynomial;
void pbtrash(polynomial &p)
{
	pnode *pb=p;
	while(pb->next->next)
	{
		if(pb->next->expn==pb->next->next->expn)
		{
			pb->next->next->coef+=pb->next->coef;
			
			pnode *r=pb->next;
			pb->next=r->next;
			delete r;
			if(pb->next->coef==0)
			{
				pnode *r=pb->next;
				pb->next=r->next;
				delete r;
			}
			if(!pb->next)break;
		}
		else 
		pb=pb->next;
	}
}
void createpolyn(polynomial &p,int n)
{
	p=new pnode;
	p->next=nullptr;
	for(int i=1;i<=n;i++)
	{
		pnode *s=new pnode;
		cin>>s->coef>>s->expn;
		pnode *pre=p,*q=p->next;
		while(q&&q->expn>s->expn)
		{
			pre=q;
			q=q->next;
		}
		s->next=q;
		pre->next=s;
	}
	pbtrash(p);
}
void printpolyn(polynomial &p)
{
	pnode *r=p->next;
	while(r)
	{
		if(r==p->next&&r->coef>0)
			;
		else if(r->coef>0)
			cout<<'+';
		
		cout<<r->coef;
		
		if(r->expn!=0)
			cout<<'x'<<'^'<<r->expn;
		r=r->next;
		if(!r)
		{
			cout<<endl;
			return;
		}
	}
	cout<<0<<endl;
}
void copypolyn(polynomial &pa,polynomial &pb)
{
	pnode *p=pa->next,*q=pb;
	while(p)
	{
		pnode *r=new pnode;
		r->coef = p->coef;
		r->expn = p->expn;
		q->next=r;
		q=q->next;
		p=p->next;
	}
	q->next=nullptr;
}
void addpolyn(polynomial &pa,polynomial &pb)
{
	pnode *p1=pa->next,*p2=pb->next,*p3=pa;
	while(p1&&p2)
	{
		if(p1->expn==p2->expn)
		{
			int sum=p1->coef+p2->coef;
			if(sum!=0)
			{
				p1->coef=sum;
				p3->next=p1;
				p3=p1;
				p1=p1->next;
				pnode *r=p2;
				p2=p2->next;
				delete r;
			} 
			else
			{
				pnode *r=p1;
				p1=p1->next;
				
				r=p2;
				p2=p2->next;
				delete r;
			}
		}
		else if(p1->expn>p2->expn)
		{
			p3->next=p1;
			p3=p1;
			p1=p1->next;
		}
		else
		{
			p3->next=p2;
			p3=p2;
			p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;
	delete pb;
}
void negpolyn(polynomial &pb)
{
	pnode *p=pb->next;
	if(p)
	{
		p->coef=-p->coef;
		p=p->next;
	}
}
void mulpolyn(polynomial &pa,polynomial &pb,polynomial &pc)
{
	pnode *p=pb;
	p->coef=1;
	p->expn=0;
	while(p->next)
	{
		pnode *q=pa->next;
		while(q)
		{
			q->coef/=p->coef;
			q->expn-=p->expn;
			q->coef*=p->next->coef;
			q->expn+=p->next->expn;

			q=q->next;
		}
		pnode *P=new pnode;
		copypolyn(pa,P);
		addpolyn(pc,P);
		p=p->next;
	}
}
void dpolyn(polynomial &pa)
{
	pnode *p=pa;
	while(p->next)
	{
		if(p->next->expn)
		{
			p->next->coef*=p->next->expn;
			p->next->expn--;
			p=p->next;
		}
		else
		{
			pnode *r=p->next;
			p->next=r->next;
			delete r;
		}
	}
	printpolyn(pa);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		polynomial pa,pb,pc=new pnode;
		pc->next=nullptr; 
		int a,b;
		cin>>a>>b;
		createpolyn(pa,a);
		createpolyn(pb,b);
		char ch;
		cin>>ch;
		switch(ch)
		{
			case '+':addpolyn(pa,pb);printpolyn(pa);break;
			case '-':negpolyn(pb);addpolyn(pa,pb);printpolyn(pa);break;
			case '*':mulpolyn(pa,pb,pc);printpolyn(pc);break;
			default:dpolyn(pa);dpolyn(pb);
		}
		
	}
}
