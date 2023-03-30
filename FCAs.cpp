#include<iostream>
#include<cstdio>
#include<cmath> 
#include<string>
#include<windows.h>
#define L 100

int rulename = 110,mode = 1;
int rule[8] = {},displen;
double VCache[L]={};

void RuleDecode(){
	int temp = rulename;
	for(int i = 0;i < 8;i++){
		rule[i] = temp%2;
		temp/=2;
	}
}

void RuleDisp(){
	
    for(int i = 0;i < 8;i++){
    	
	}	
}


struct cell{
	double curv,nexv;
	int index;
	
    void init(int ind){
    	curv = double(rand()%2);
    	nexv = 0;
    	index = ind;
	} 
	void iter(){
		double l=0,r=0,c=0;
		
		if(index == 0)l=VCache[L-1];
		else l = VCache[index - 1];
		if(index == L-1)r=VCache[0];
		else r = VCache[index + 1];
		c=curv;
		
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < 2;j++){
				for(int k = 0;k < 2;k++){
					if(mode == 1){
						nexv += abs((i - l)*(j - c)*(k - r))*double(rule[i*4+j*2+k*1]);
						nexv = min(nexv,1);
					}else{
						if(rule[i*4+j*2+k*1]==1){
							nexv = max(min(min(abs(i - l),abs(j - c)),abs(k - r)),nexv);
						}
					}
					
				}
			}
		}

		
	}
	void exch(){
		curv = nexv;
	}
}; 

cell celllist[L];

/*cell cprev(int ind){
	return celllist[ind-1];
}

cell cnext(int ind){
	return celllist[ind+1];
}*/

void GlobalCache(){
	for(int i = 0;i < L;i++){
		VCache[i] = celllist[i].curv;
	}
}

void GlobalInit(){
	for(int i = 0;i < L;i++){
		celllist[i].init(i);
	}	
	GlobalCache();
}
void GlobalExch(){
	for(int i = 0;i < L;i++){
		celllist[i].iter();
		celllist[i].exch();
	}	
	GlobalCache();
}
void GlobalDisp(){
	for(int i = 0;i < displen;i++){
		cout<<setprecision(3)<<celllist[i].curv<<' ';
	}
}
int main(){
	srand((int)time(0)+156); 
	Globalinit();
	cout<<"Input Mode, 1 for +*, 2 for ><\n";
	cin>>mode;
	cout<<"Input rule code\n";
	cin>>rulename;
	RuleDecode();
	cout<<"Input disp len\n";
	cin>>displen;
	GlobalDisp();
	GlobalExch();
	GlobalDisp();
	
}
