#include <iostream>

using namespace std;

struct gz{
	int no;
	bool isdis;
};

gz array[35][35];

bool shujbx(int a, int b){
	if(array[a][b].no==array[a-1][b].no&&array[a][b].no==array[a+1][b].no){
		return true;
	}
	return false;
}

bool hengjbx(int a, int b){
	if(array[a][b].no==array[a][b-1].no&&array[a][b].no==array[a][b+1].no){
		return true;
	}
	return false;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> array[i][j].no;
			array[i][j].isdis=false;
		}
	}
	for (int i=1; i<n-1; i++){
		for (int j=1; j<m-1; j++){
			if(shujbx(i, j)){
				array[i][j].isdis=true;
				array[i-1][j].isdis=true;
				array[i+1][j].isdis=true;
			}
			if(hengjbx(i, j)){
				array[i][j].isdis=true;
				array[i][j-1].isdis=true;
				array[i][j+1].isdis=true;
			}
		}
	}
	for (int i=1; i<m-1; i++){
		if(hengjbx(0, i)){
			array[0][i].isdis=true;
			array[0][i-1].isdis=true;
			array[0][i+1].isdis=true;			
		}
		if(hengjbx(n-1, i)){
			array[n-1][i].isdis=true;
			array[n-1][i-1].isdis=true;
			array[n-1][i+1].isdis=true;			
		}
	}
	for (int i=1; i<n-1; i++){
		if(shujbx(i, 0)){
			array[i][0].isdis=true;
			array[i-1][0].isdis=true;
			array[i+1][0].isdis=true;			
		}
		if(shujbx(i, m-1)){
			array[i+1][m-1].isdis=true;
			array[i-1][m-1].isdis=true;
			array[i][m-1].isdis=true;			
		}
	}
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(array[i][j].isdis==true){
				cout << 0 << ' ';
			}
			else{
				cout << array[i][j].no << ' ';
			}
		}
		cout << endl;
	}
	return 0;
} 
