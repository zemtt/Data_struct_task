#include<iostream>
using namespace std;

int SearchMain(int k[], int len){
    int number[len];
    int count[len];
    int num = 0;
    for(int i=0;i<len;i++){
        bool in = false;
        for(int j=0;j<num;j++){
            if(k[i] == number[j]){
                count[j] ++;
                if(count[j]>len/2)  return k[i];
                in = true;
            }
        }
        if(!in){
            number[num] = k[i];
            count[num] = 1;
            num++;
        }
    }
    return -1;
}

int main(){
    int n;
    while(1){
        cin>>n;
        if(!n)  break;
        int k[n];
        for(int i=0;i<n;i++)    cin>>k[i];
        cout<<SearchMain(k, n)<<endl;
    }
}