#include <iostream>

using namespace std;

bool ju1(int k, int num){
	if(num%k==0||num-num/10*10==k){
		return true;		
	}
	return false;
}
struct litfri{
	int no;
	bool istaotai;
};
litfri la[1005];

int main(){
	int n, k;
	cin >> n >> k;
	int nf=n;
	for (int i=0; i<n; i++){
		la[i].no=i+1;
		la[i].istaotai=false;
	}
	int bs=0;
	while(nf!=1){
		for (int i=0; i<n; i++){
			if(la[i].istaotai==false){
				bs++;
				if(ju1(k, bs)){
					la[i].istaotai=true;
					nf--;
					if(nf==1){
						break;
					}
				}
			}
		}
	}
	for (int i=0; i<n; i++){
		if(la[i].istaotai==false){
			cout << la[i].no << endl;
			break;
		}
	}
	return 0;
}
