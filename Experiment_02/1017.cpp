#include<iostream>
#include<cstring>
using namespace std;

bool FindV(char *V, char *DNA,int len){
    bool f = false;
    int count=0;
    char *pd, *pv;
    pd = DNA;
    pv = V; 
    while(*pd&&*pv){
    	if(*pd==*pv)	count++;
    	else{
    		if(count >= len)	break;
			else	count = 0;
		}
		pd++;
		pv++;
	}
	if(count >= len)	f=true;
	return f;
}

int main(){
    char DNA[1000];
    char V[1000];
    char m[1000];
    int f,len;
    while(1){
        cin>>V>>DNA;
        if(!strcmp(V,"0")&&!strcmp(DNA,"0"))    break;
        f=0;
        len = strlen(V);
        strcpy(m, V);
        strcat(m,V);
        for(char *p = m;*p;p++){
            if(FindV(p, DNA,len)){
                f=1;
                break;
            }
        }
        for(char *p = DNA;*p;p++){
            if(FindV(m, p,len)){
                f=1;
                break;
            }
        }
        if(f)   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
}

//ccccccccca aaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccccccccc
