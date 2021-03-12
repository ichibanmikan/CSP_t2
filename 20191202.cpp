#include <iostream>
#include <algorithm>

using namespace std;

struct ljzb{
	long long x;
	long long y;
	long long score;
};

bool cmp(ljzb l1, ljzb l2){
	if(l1.x!=l2.x){
		return l1.x<l2.x;
	}
	return l1.y<l2.y;
}

int main(){
	long long n;
	ljzb la[2005];
	cin >> n;
	for (long long i=0; i<n; i++){
		cin >> la[i].x >> la[i].y;
		la[i].score=-1;
	}
	sort(la, la+n, cmp);
	long long temp=la[0].x;
	long long tempi;
	long long ju0=0;
	for (long long i=1; i<n; i++){
//		cout << '*' << 1 << endl;
		if(la[i].x!=temp){
			ju0=1;
			tempi=i;
		}
//		cout << "+++" << tempi << ' ' << ju0 << endl;
		if(ju0==1&&(la[i-1].x==la[i].x&&la[i+1].x==la[i].x)&&(la[i-1].y==la[i].y-1&&la[i+1].y==la[i].y+1)){
			long long j=tempi-1;
			long long ju1=0;
			while(j>=0){
				if(la[j].x==la[i].x-1&&la[j].y==la[i].y){
					ju1=1;
					break;
				}
				j--;
			}//
//			cout << "***" << j << endl;
			long long ju2=0;
			long long tempk;
			if(ju1==1){
				for (long long k=i+1; k<n; k++){
					if(la[k].x==la[i].x+1&&la[k].y==la[i].y){
						ju2=1;
						tempk=k;
						break;
					}
				}
			}
//			cout << "***" << tempk << endl;
			if(ju1==1&&ju2==1){
				la[i].score=0;
//				cout << "()()" << i << endl;
				if(la[tempk-1].x==la[i].x+1&&la[tempk-1].y==la[i].y-1){
//					cout << "++" << la[tempk].x << ' ' << la[tempk].y << endl;
					la[i].score++;
				}
				if(la[tempk+1].x==la[i].x+1&&la[tempk+1].y==la[i].y+1){
//					cout << "--" << tempk << endl;
					la[i].score++;
				}
				if(la[j-1].x==la[i].x-1&&la[j-1].y==la[i].y-1){
//					cout << "**" << j << endl;
					la[i].score++;
				}
				if(la[j+1].x==la[i].x-1&&la[j+1].y==la[i].y+1){
//					cout << "//" << j << endl;
					la[i].score++;
				}
//				cout << '*' << la[i].x << ' ' << la[i].y << endl;
//				cout << '*' << la[tempk-1].x << ' ' << la[tempk-1].y << endl;
			}
		}
		temp=la[i].x;
	}
	long long asc[5];
	for (long long i=0; i<5; i++){
		asc[i]=0;
	}
	for (long long i=0; i<n; i++){
		if(la[i].score==0){
			asc[0]++;
		}
		if(la[i].score==1){
			asc[1]++;
		}
		if(la[i].score==2){
			asc[2]++;
		}
		if(la[i].score==3){
			asc[3]++;
		}
		if(la[i].score==4){
			asc[4]++;
		}
	}
	for (long long i=0; i<5; i++){
		cout << asc[i] << endl;
	}
	return 0;
}
