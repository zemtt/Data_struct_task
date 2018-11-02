#include<iostream>
using namespace std;
int partition(int a[],int n)
{
	int low=0,high=n-1,low0=0,high0=n-1,s1=0,s2=0;
	int flag=1,k=n/2;
	while(flag)
	{
		int key=a[low];
		while(low<high)
		{
			while(low<high&&a[high]>=key)
				--high;
			if(low!=high)
				a[low]=a[high];
			while(low<high&&a[low]<=key)
				++low;
			if(low!=high)
				a[high]=a[low];
		}
		a[low]=key;
		if(low==k-1)
			flag=0;
		else
		{
			if(low<k-1)
			{
				low0=++low;
				high=high0;
			}
			else
			{
				high0=--high;
				low=low0;
			}
		}
	}
	return k;
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		int *a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int k=partition(a,n);
		
		for(int i=0;i<k-1;i++)
			cout<<a[i]<<' ';
		cout<<a[k-1]<<endl;
		
		for(int i=k;i<n-1;i++)
			cout<<a[i]<<' ';
		cout<<a[n-1]<<endl;
	}
}