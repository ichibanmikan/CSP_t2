#include <iostream>

using namespace std;

int array[505][505];
int n;
void print_xie(int t){
	if(t%2==1){
		for (int i=0; i<=t; i++){
			cout << array[i][t-i] << ' ';
		}
	}
	if(t%2==0){
		for (int i=0; i<=t; i++){
			cout << array[t-i][i] << ' ';
		}
	}
}

void print_xiehou(int sum){
	if((sum-n-1)%2==0){
		if((n-1)%2==0){
			for (int i=n-1; i>=sum-n+1; i--){
				cout << array[i][sum-i] << ' ';
			}
		}
		else{
			for (int i=n-1; i>=sum-n+1; i--){
				cout << array[sum-i][i] << ' ';
			}
		}
	}
	else{
		if((n-1)%2==0){
			for (int i=n-1; i>=sum-n+1; i--){
				cout << array[sum-i][i] << ' ';
			}
		}
		else{
			for (int i=n-1; i>=sum-n+1; i--){
				cout << array[i][sum-i] << ' ';
			}
		}
	}
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> array[i][j];
		}
	}
	for (int i=0; i<n; i++){
		print_xie(i);
	}
	for (int i=n; i<=2*(n-1); i++){
		print_xiehou(i);
	}
	return 0;
}
