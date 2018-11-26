#include<iostream>
#include<cstring>
using namespace std;

int HT[100][4];
char HT_code[100][100];

int Select(int &s0,int &s1){
	int w[2];
	w[0] = 1000;
	w[1] = 1000;
	for(int i=1;HT[i][0];i++){
		if(HT[i][1])	continue;
		if(HT[i][0]<w[0]){
			w[1] = w[0];
			s1 = s0;
			w[0] = HT[i][0];
			s0 = i;
		}
		else if(HT[i][0]<w[1]){
			w[1] = HT[i][0];
			s1 = i;
		}
	}
}

void SetValue(int a, char *v){
    strcpy(HT_code[a],v);
    char t[100];
    if(HT[a][2]){
        strcpy(t,v);
        strcat(t,"0");
        SetValue(HT[a][2], t);
    }
    if(HT[a][3]){
        strcpy(t,v);
        strcat(t,"1");
        SetValue(HT[a][3], t);
    }
}

int main(){
    char str[100];
    int num[26][2];
    bool flg[26];
    char code[26][5];
    int count;
    int s0,s1;
    while(1){
        memset(str,0,sizeof(str));
        memset(num,0,sizeof(num));
        memset(flg,0,sizeof(flg));
        memset(code,0,sizeof(code));
        memset(HT,0,sizeof(HT));
        memset(HT_code,0,sizeof(HT_code));
        count = 1;
        s0 = 0;
        s1 = 0;
        
        cin>>str;
        if(!strcmp(str,"0"))    break;
        for(char *p = str;*p;p++)
            num[*p-'a'][0]++;
        bool flag = false;
        for(int i=0;i<26;i++){
            if(num[i][0]){
                if(flag)    cout<<' ';
                else    flag = true;
                char t = 'a'+i;
                cout<<t<<':'<<num[i][0];
                num[i][1] = count;
                HT[count++][0] = num[i][0];
            }
        }
        cout<<endl;
        while(1){
        	s0 = 0;
        	s1 = 0;
	        Select(s0,s1);
	        if(!(s0&&s1))	break;
	        HT[count][0] = HT[s0][0] + HT[s1][0];
	    	HT[count][2] = s0;
	    	HT[count][3] = s1;
	    	HT[s0][1] = count;
	    	HT[s1][1] = count;
			count++;
		}
		for(int i=1;HT[i][0];i++){
			cout<<i<<' '<<HT[i][0]<<' '<<HT[i][1]<<' '<<HT[i][2]<<' '<<HT[i][3]<<endl;
		}
		char aa[5];
		strcpy(aa,"");
		SetValue(count-1,aa);
        flag = false;
		for(int i=0;i<26;i++){
			if(!num[i][0])	continue;
			char t = 'a'+i;
            if(flag)    cout<<' ';
            else    flag = true;
			cout<<t<<':'<<HT_code[num[i][1]];
		}
        cout<<endl;
        for(char *p = str;*p;p++)
            cout<<HT_code[num[*p-'a'][1]];
        cout<<endl<<str<<endl;
    }
}
