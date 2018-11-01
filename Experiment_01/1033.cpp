#include<iostream>
using namespace std;

int FindMiddle(int a[], int b[], int n){
    int ia=0, ib=0, f=0;
    for(int i=0;i<n;i++){
        if(a[ia] > b[ib]){
            ib++;
			f=1;
		}
        else{
            ia++;
        	f=0;
		}
    }
    if(!f)	return a[ia-1];
    else return b[ib-1];
}

int main(){
    int n;
    while(1){
        cin>>n;
        if(!n)  break;
        int j[n],k[n];
        for(int i=0;i<n;i++)    cin>>j[i];
        for(int i=0;i<n;i++)    cin>>k[i];
        cout<<FindMiddle(j,k,n)<<endl;
    }
}
