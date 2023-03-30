#include<bits/stdc++.h>

using namespace std;

int rulen = 0;
bool octr[8]={};
double wfreq=0.5;
double wsum=80;
int pfreqt[32]={},sfreqt[32]={};


bool tran(bool left,bool mid,bool right){
	int ind = 0;
    if(left)ind+=1;
    if(mid)ind+=2;
    if(right)ind+=4;
    return octr[ind];
}

struct sptable{
	bool septg[7];
	bool pentg[5];
	int ind;
	double sfreq,pfreq;
	int slabel;
	void citer(){
		for(int j=1;j<6;j++){
			pentg[j-1]=tran(septg[j-1],septg[j],septg[j+1]);
		}
	}
	void autostat(){
		ind=0;
		int base=1;
		double wnums=0;
		for(int i=0;i<5;i++){
			if(pentg[i]){
				ind+=base;
				wnums++;
			}
			base*=2;
		}
		pfreqt[ind]++;
		sfreqt[ind]++;
		wsum+=pfreq*wnums;
	}
	void septprep(){
		
	}
}; 


sptable lst[128];

void init(){
	for(int i=1;i<128;i++){
		lst[i].sfreq=1/128;
		//lst[i].pfreq=1/128;
		lst[i]=lst[i-1];
		int j;
		for(j=0;lst[i].septg[j];j++){
			lst[i].septg[j]=false;
		}
		lst[i].septg[j]=true;
	}
	for(int i=0;i<128;i++){
        lst[i].citer();
	}
}

void ruletr(){
	int ind = 0;
	for(rulen;rulen>0;ind++){
		octr[ind]=rulen%2;
		rulen/=2;
	}
	return;
}

int main(){
	cout<<"Rulenum?"<<endl;
	cin>>rulen;
	ruletr();
	init();
	for(int i=0;i<128;i++){
		lst[i].autostat();
	}
	for(int i=0;i<128;i++){
		lst[i].slabel=pfreqt[lst[i].ind];
		if(pfreqt[lst[i].ind]>0)pfreqt[lst[i].ind]--;	
		cout<<i<<' '<<lst[i].ind<<' '<<lst[i].slabel<<' '<<sfreqt[lst[i].ind]<<endl;
	}
}
