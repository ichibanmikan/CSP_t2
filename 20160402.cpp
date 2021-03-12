#include <iostream>

using namespace std;

int array[15][10];
int jbx[5][5];
int temp[15][10];
bool ju1(int a, int b){
	if(temp[a][b]==1&&temp[a+1][b]==1){
		return true;
	}
	return false;
} 
int main(){
	for (int i=0; i<15; i++){
		for (int j=0; j<10; j++){
			cin >> array[i][j];
			temp[i][j]=array[i][j];
		}
	}
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			cin >> jbx[i][j];
		}
	}
	int num;
	cin >> num;
	
	int allju1=0, allju2=0, allju3=0;
	
	for (int i=num-1; i<num+3; i++){
		if(temp[0][i]!=1){
			temp[0][i]=jbx[3][i-num+1];
		}
	}
	int ja1=0;
	for (int i=num-1; i<num+3; i++){
		if(ju1(0, i)){
			ja1=1;
			allju1=1;
			break;
		}
	}
	if(ja1!=1){
		for (int i=num-1; i<num+3; i++){
			temp[0][i]=array[0][i];
		}
	}
	
	if(allju1==0){
		for (int i=0; i<2; i++){
			for (int j=num-1; j<num+3; j++){
				temp[i][j]=jbx[2+i][j-num+1];
			}
		}
		int ja2=0;
		for (int i=0; i<2; i++){
			for (int j=num-1; j<num+3; j++){
				if(ju1(i, j)&&(i!=1&&!(jbx[2+i][j-num+1]==1&&jbx[3+i][j+1-num]==1))){
					ja2=1;
					allju2=1;
					break;
				}
			}
			if(ja2==1){
				break;
			}
		}
		if(ja2!=1){
			for (int i=0; i<2; i++){
				for (int j=num-1; j<num+3; j++){
					temp[i][j]=array[i][j];
				}
			}
		}
	}
	
	if(allju1==0&&allju2==0){
		for (int i=0; i<3; i++){
			for (int k=num-1; k<num+3; k++){
				temp[i][k]=jbx[i+1][k-num+1];
			}
		}
		int ja3=0;
		for (int i=0; i<3; i++){
			for (int k=num-1; k<num+3; k++){
				if(ju1(i, k)&&(i!=2&&!(jbx[i+1][k-num+1]==1&&jbx[i+2][k-num+1]==1))){
					ja3=1;
					allju3=1;
					break;
				}
			}
			if(ja3==1){
				break;
			}
		}
		if(ja3!=1){
			for (int i=0; i<3; i++){
				for (int k=num-1; k<num+3; k++){
					temp[i][k]=array[i][k];
				}
			}
		}
	}
	
	if(allju1==0&&allju2==0&&allju3==0){
		for (int i=0; i<13; i++){
			for (int k=i; k<i+4; k++){
				for (int j=num-1; j<num+3; j++){
					if(temp[k][j]!=1){
						temp[k][j]=jbx[k-i][j-num+1];
					}
				}	
			}
			int jp=0;
			for (int k=i; k<i+4; k++){
				for (int j=num-1; j<num+3; j++){
					if(ju1(k, j)&&(k!=i+3&&!(jbx[k-i][j-num+1]==1&&jbx[k-i+1][j-num+1]==1))){
						jp=1;
						break;
					}
				}
				if(jp==1){
					break;
				}
			}
			if(jp==1){
				break;
			}
			else if(i!=12){
				for (int p=0; p<15; p++){
					for (int q=0; q<10; q++){
						temp[p][q]=array[p][q];
					}
				}
			}
		}
	}
	for (int i=0; i<15; i++){
		for (int j=0; j<10; j++){
			cout << temp[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
