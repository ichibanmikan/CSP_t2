#include <iostream>

using namespace std;

int main(){
	int result=0;
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		int sc, w;
		cin >> sc >> w;
		result+=(w*sc);
	}
	if(result<=0){
		result=0;
	}
	cout << result << endl;
	return 0;
}
