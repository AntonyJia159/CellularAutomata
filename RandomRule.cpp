#include<iostream>
#include<cstdio>
#include<cmath> 
#include<string>
#include<windows.h>
#include<time.h>

using namespace std;

int main(){
	srand((int)time(0)+156);
	for(int j=0;j<100;j++) {
		for(int i=0;i<8;i++){
		    cout<<rand()%8192<<' ';
		}
	cout<<endl;
	}
    return 0; 
}
