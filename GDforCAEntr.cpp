
#include<bits/stdc++.h>

using namespace std;

#define B 7
#define Lat 3
#define I 400

#define VN 21

#define alpha 1.5
#define beta 0.06

double input[B][I],exput[B][I];
double ciph[B][Lat];

double grad[VN];
double mome[VN];

double bloss[B];
double sqr(double num){
	return num*num;
}

double Relu(double num){
	if(num>1)return 1.0;
	else if(num<0)return 0.0;
	else return num;
}

void inputa(){
	for(int i=0;i<I;i++){
		for(int j=0;j<B;j++){
			cin>>input[j][i];
		}
	}
}


struct chrom{
    double solu[VN];	
    double encw[I][Lat];
    double decw[I][Lat];
    void autograd(int ind){
    	solu[ind]+=0.0001;
    	//mtrans();
   }  
    void mtrans(){
		int cou = 0;
		for(int i=0;i<I;i++){
			for(int j=0;j<Lat;j++){
				encw[i][j]=solu[cou];
				cou++;
			}
		}
		for(int i=0;i<I;i++){
			for(int j=0;j<Lat;j++){
				decw[i][j]=solu[cou];
				cou++;
			}
		}
	 
	}
	void gd(){
		for(int i=0;i<VN;i++){
			solu[i]-=beta*alpha*mome[i];
			solu[i]-=alpha*grad[i];
			mome[i]+=alpha*grad[i]+beta*alpha*mome[i];
			mome[i]*=0.9;
		}
	}
	void init(){
		for(int i=0;i<B;i++){
			solu[0+3*i]=3+double(rand()%10000)/10000;
			solu[1+3*i]=1+double(rand()%10000)/10000;
			solu[2+3*i]=3;
		}
	}
	void disp(){
		for(int i=0;i<VN;i++){
			cout<<solu[i]<<' ';
		}
		cout<<endl;
	}
};

chrom cur;
chrom gradc[VN];

double func(chrom one){         //Ä¿±êº¯Êý 
	double value = 0,temp=0,cch[100],temp2=0;
	double output[B][I]={};
    for(int i=0;i<B;i++){
    	for(int j=0;j<I;j++){
    	    output[i][j] = one.solu[0+3*i]-(log(j+30*one.solu[2+3*i]))/log(one.solu[1+3*i]);
		}
	}

	for(int i=0;i<B;i++){
		for(int k=0;k<I;k++){
		double temp3=0;
		temp3 = input[i][k]-output[i][k];
		value+= sqr(temp3);
		if(k<101)value+=sqr(temp3);
		}
   }
   value/=double(I);
   //one.disp();
   return value;
}
   
double module(){
	srand((int)time(0)+156); 
	double loss;
	loss = 0;
	//cur.mtrans();
	loss = func(cur);
	for(int i=0;i<VN;i++){
		gradc[i]=cur;
		//gradc[i].mtrans();
	}
	for(int i=0;i<VN;i++){
		gradc[i].autograd(i);
		grad[i] = func(gradc[i])-loss;
		//cout<<grad[i]<<' ';
		//cout<<func(gradc[i])<<endl;
	}
	//gradc[1].disp();
 	cur.gd();
	cout<<loss<<endl;
	return loss;
}


int main(){
    inputa();
    cur.init();
    //cur.disp();
    for(int i=0;module()/B>=0.13;i++){
    	if(i>75000)break;
	}
	for(int i=0;i<B;i++){
		cout<<cur.solu[0+3*i]<<' '<<cur.solu[1+3*i]<<' '<<30*cur.solu[2+3*i]<<endl;
	}
}
