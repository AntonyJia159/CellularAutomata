#include<iostream>
#include<cstdio>
#include<cmath> 
#include<string>
#include<windows.h>
#define L 60
#define Thre 7

using namespace std;

bool rule[128] = {};
int rulen[8] = {};


void ruletr(){
	int ind = 0;
	for(int i = 0;i<8;i++){
		for(ind = i*16;ind<i*16+16;ind++){
		rule[ind]=bool(rulen[i]%2);
		cout<<rulen[i]%2;
		rulen[i]/=2;
	    }
	}
	cout<<"\n";
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
	for(int i=3;i<L-3;i++){
		clist[i].nexv = iter(clist[i]);
	}
	for(int i=3;i<L-3;i++){
		clist[i].exch();
	}
	bound();
} 

void GlobalDisp(){
	for(int i=3;i<L-3;i++){
		cout<<clist[i].curv<<' ';
	}
	cout<<endl;
}

void rulein(){
	cout<<"\n";
	for(int i = 0;i<8;i++){
		cin>>rulen[i];
		cout<<rulen[i]<<' ';
	}
}

int main(){
	freopen("rule.out", "a", stdout);
	GlobalInit();
	rulein();
	fclose(stdout);
	freopen("rulelist.out", "a", stdout);
	ruletr();
	fclose(stdout);
	freopen("sample.out", "w", stdout);
	GlobalDisp();
	for(int i=0;i<60;i++){
	   module();
	   GlobalDisp();
	}
	fclose(stdout);
    return 0;
}

//1238 21394 61111 12312 12313 12313 12312 21159
//21159 21159 21159 21159 21159 21159 21159 21159
//22369 22888 22369 22888 22369 22888 22369 22888
// 22888 22888 22888 22888 22888 22888 22888 22888
//114 514 1919 810 114 514 1919 810

