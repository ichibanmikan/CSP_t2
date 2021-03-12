#include <iostream>

using namespace std;

//struct jx{
//	bool isfind;
//	int xzb;
//	int yzb;
//};

int main(){
	int n;
	bool barray[105][105];
//	jx array[105];
//	for(int i=0; i<100; i++){
//		for (int j=0; j<100; j++){
//			isfind=false;
//			xzb=i;
//			yzb=j;			
//		}
//	}
	for(int i=0; i<100; i++){
		for (int j=0; j<100; j++){
			barray[i][j]=false;
		}
	}
	cin >> n;
	int azb[5];
	int result=0;
	for (int i=0; i<n; i++){
		cin >> azb[0] >> azb[1] >> azb[2] >> azb[3];
		for (int j=azb[0]; j<azb[2]; j++){
			for (int k=azb[1]; k<azb[3]; k++){
				if(barray[j][k]==false){
					barray[j][k]=true;
					result++;
				}
			}
		}
	}
	cout << result << endl;
	return 0;
} 
