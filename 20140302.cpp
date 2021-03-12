#include <iostream>

using namespace std;

struct st{
	int xzx;
	int yzx;
	int xys;
	int yys;
	int no;
};
st wins[15];
void swap(int x, int y){
	st temp=wins[x];
	wins[x]=wins[y];
	wins[y]=temp;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i=n-1; i>=0; i--){
		cin >> wins[i].xzx >> wins[i].yzx >> wins[i].xys >> wins[i].yys;
		wins[i].no=n-i;
	}
	int x1, y1;
	int dc=0;
	for (int i=0; i<m; i++){
		int ju=0;
		cin >> x1 >> y1;
		for (int j=0; j<n; j++){
			if(wins[j].xzx<=x1&&wins[j].xys>=x1&&wins[j].yzx<=y1&&wins[j].yys>=y1){
				cout << wins[j].no << endl;
				swap(dc, j);
				ju=1;
				break;
			}
		}
		if(ju==0){
			cout << "IGNORED" << endl;
		}
	}
	return 0;
}
