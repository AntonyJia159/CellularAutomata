#include<iostream>
#include<cstdio>
#include<cmath> 
#include<string>
#include<windows.h>
#define L 100
#define Thre 7

using namespace std;

short rule[343] = {};
int rulen;

void ruletr(){
	int ind = 0;
	int i = 0; 
	for(i;i<343;i++)rule[i]=rand()%7;
	    /*for(ind;rulen>0;ind++){
			rule[ind]=rulen%7;
			rulen/=7;
	    }*/
	return;
}

struct cell{
	short curv,nexv;
	int index;
	
    void init(int ind){
    	curv = short(rand()%7);
    	nexv = 0;
    	index = ind;
	} 
	void exch(){
		curv = nexv;
	}
}; 

cell clist[L];

void GlobalInit(){
	for(int i = 0;i < L;i++){
		clist[i].init(i);
	}	
}
void GlobalExch(){
	for(int i = 0;i < L;i++){
		clist[i].curv=clist[i].nexv;
	}	
}

void bound(){
    for(int i=0;i<1;i++){
        clist[i] = clist[L-2+i];
	}
	for(int i=L-1;i<L;i++){
		clist[i] = clist[i-L+2];
	}
}
	
short iter(cell a){
	int base = 1,ind = 0;
    for(int i = a.index - 1;i <= a.index + 1;i++){
    	ind+=base*clist[i].curv;
    	base*=7;
	}
	return rule[ind];
}

void module(){
	for(int i=1;i<L-1;i++){
		clist[i].nexv = iter(clist[i]);
	}
	for(int i=1;i<L-1;i++){
		clist[i].exch();
	}
	bound();
} 

void GlobalDisp(){
	for(int i=1;i<L-1;i++){
		cout<<clist[i].curv<<' ';
	}
	cout<<endl;
}

void rulein(){
	for(int i = 0;i<1;i++){
		cin>>rulen;
	}
}

int main(){
	GlobalInit();
	//rulein();
	ruletr();
	GlobalDisp();
	for(int i=0;i<80;i++){
	   module();
	   GlobalDisp();
	}
    return 0;
}

//1238 21394 61111 12312 12313 12313 12312 21159
//21159 21159 21159 21159 21159 21159 21159 21159
//22369 22888 22369 22888 22369 22888 22369 22888
// 22888 22888 22888 22888 22888 22888 22888 22888
//114 514 1919 810 114 514 1919 810

