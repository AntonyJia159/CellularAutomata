#include<iostream>
#include<cstdio>
#include<cmath> 
#include<string>
#include<windows.h>
#define L 1000
#define Thre 7

using namespace std;

bool rule[128] = {};
int rulen[8] = {};

void ruletr(){
	int ind = 0;
	for(int i = 0;i<8;i++){
		for(ind = i*16;rulen[i]>0;ind++){
		rule[ind]=bool(rulen[i]%2);
		rulen[i]/=2;
	    }
	}
	return;
}

struct cell{
	bool curv,nexv;
	int index;
	
    void init(int ind){
    	curv = bool(rand()%2);
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
    for(int i=0;i<3;i++){
        clist[i] = clist[L-6+i];
	}
	for(int i=L-3;i<L;i++){
		clist[i] = clist[i-L+6];
	}
}
	
bool iter(cell a){
	int base = 1,ind = 0;
    for(int i = a.index - 3;i <= a.index + 3;i++){
    	if(clist[i].curv)ind+=base;
    	base*=2;
	}
	return rule[ind];
}

void module(){
	double sum = 0,entr=0;
	for(int i=3;i<L-3;i++){
		clist[i].nexv = iter(clist[i]);
	}
	for(int i=3;i<L-3;i++){
		clist[i].exch();
		sum+=clist[i].curv;
	}
	cout<<sum<<' ';
	bound();
} 

void GlobalDisp(){
	for(int i=3;i<L-3;i++){
		cout<<clist[i].curv<<' ';
	}
	cout<<endl;
}

void rulein(){
	for(int i = 0;i<8;i++){
		cin>>rulen[i];
	}
}

int main(){
	GlobalInit();
	rulein();
	ruletr();
	//GlobalDisp();
	for(int i=0;i<1250;i++){
	   module();
	   //GlobalDisp();
	}
	return 0;

}

//1238 21394 61111 12312 12313 12313 12312 21159
//21159 21159 21159 21159 21159 21159 21159 21159
//22369 22888 22369 22888 22369 22888 22369 22888
// 22888 22888 22888 22888 22888 22888 22888 22888
// 11 33 99 297 22873 22873 22873 22873
// 11 33 99 297 22873 22873 22873 0
// 11 33 99 297 22873 22873 0 0
// 21673 20470 21159 20851 19168 22555 21880 22205
//21361 21361 21361 21361 21361 21361 21361 21361
//2307 4203 3095 2776 753 8323 19818 12369
