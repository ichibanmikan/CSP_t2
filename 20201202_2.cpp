#include <iostream>
#include <algorithm>

using namespace std;

int meigua[100005];
int guale[100005];
int main(){
	int n;
	cin >> n;
	int tempgua, tempaqxs;
	int ju0=0, ju1=0;
	for (int i=0; i<n; i++){
		cin >> tempaqxs >> tempgua;
		if(tempgua==0){
			guale[ju0]=tempaqxs;
			ju0++;
		}
		else{
			meigua[ju1]=tempaqxs;
			ju1++;
		}
	}
	sort(guale, guale+ju0);
	sort(meigua, meigua+ju1);
	int result=100005;
	
	return 0;
}
