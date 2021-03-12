#include <iostream>

using namespace std;

struct zw{
	int no;
	bool issold;
};

zw array[105];

int judgetp(int a){
	for (int i=0; i<20; i++){
		int numkzw=0;
		for (int j=0; j<5; j++){
			if(array[i*5+j].issold==false){
				numkzw++;
				if(numkzw==a){
					for (int k=i*5+j-a+1; k<=i*5+j; k++){
						array[k].issold=true;
					}
					return i*5+j;
				}
			}
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	int num;
	for (int i=0; i<100; i++){
		array[i].no=i+1;
		array[i].issold=false;
	}
	for (int i=0; i<n; i++){
		cin >> num;
		int ju1=judgetp(num);
		if(ju1!=-1){
			for (int j=ju1-num+1; j<=ju1; j++){
				cout << array[j].no << ' ';
			}
		}
		if(ju1==-1){
			for(int j=0; j<100; j++){
				if(array[j].issold==false){
					array[j].issold=true;
					cout << array[j].no << ' ';
					num--;
				}
				if(num==0){
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
} 
