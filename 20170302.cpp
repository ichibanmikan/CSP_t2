#include <iostream>

using namespace std;

int array[1005];
void qianyi(int pos, int n){
	int temp=array[pos];
	for (int i=pos; i>=pos-n+1; i--){
		array[i]=array[i-1];
	}
	array[pos-n]=temp;
}
void houyi(int pos, int n){
	int temp=array[pos];
	for (int i=pos; i<pos+n; i++){
		array[i]=array[i+1];
	}
	array[pos+n]=temp;
}

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		array[i]=i+1;
	}
	int m;
	cin >> m;
	int no, dis;
	for (int i=0; i<m; i++){
		cin >> no >> dis;
		int p;
		for (int j=0; j<n; j++){
			if(no==array[j]){
				p=j;
				break;
			}
		}
		if(dis<0){
			qianyi(p, -dis);
		}
		else{
			houyi(p, dis);
		}
	}
	for (int i=0; i<n; i++){
		cout << array[i] << ' ';
	}
	return 0;
}
