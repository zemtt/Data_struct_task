#include <iostream>
using namespace std;
#define max 1000

void printlist(int data[],int size)
{
    for(int i = 0 ; i < size ; i++)
	{
        cin>>data[i];
    }
}

void Find(int data[],int size)
{
    int low = 0,high = size-1;
    int low0 = 0,high0 = size-1;
    int k = size/2;
    int flag = 1;
    while(flag)
	{
        while(low < high)
		{
			int pivot = data[low];
            while(low < high && data[high] >= pivot)
			{
                high--;
            }
            if(low != high)
			{
				data[low] = data[high];
            }
            while(low < high && data[low] <= pivot)
			{
                low++;
            }
            if(low != high)
			{
                data[high] = data[low];
            }
            data[low]=pivot;
            if(low == k-1)
			{
                flag = 0;
            }
			else if(low < k-1)
			{
                low0 = ++low;
                high = high0;
            }
			else
			{
                high0 = --high;
                low = low0;
            } 
        }
    }
    int f=0;
    for(int i=0;i<k;i++){
		if(f)
			cout<<' ';
		else
			f=1;
		cout<<data[i];
	}
    cout<<endl;
    f=0;
    for(int i=k;i<size;i++){
		if(f)
			cout<<' ';
		else
			f=1;
		cout<<data[i];
	}
    cout<<endl;
 } 

int main()
{
	int m;
	while(1)
	{
		cin>>m;
		if(m==0)
			break;
		int data[max];
		printlist(data,m);
		Find(data,m);
	}
    return 0;
}
