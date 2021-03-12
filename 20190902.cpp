#include <iostream>

using namespace std;

struct apa{
	int num;
	bool isdiaoluo;
};

int main(){
	int n;
	cin >> n;
	int m;
	apa ap[1005];
	for (int i=0; i<n; i++){
		cin >> m;
		int p;
		ap[i].num=0;
		ap[i].isdiaoluo=false;
		for (int j=0; j<m; j++){
			cin >> p;
			if(p>0){
				if(ap[i].num!=p&&ap[i].num!=0){
					ap[i].isdiaoluo=true;
				}
				ap[i].num=p;
			}
			else{
				ap[i].num+=p;
			}
		}
	}
	int t=0, d=0, e=0, temp=0;
	for (int i=0; i<n; i++){
		t+=ap[i].num;
		if(ap[i].isdiaoluo==true){
			d++;
			temp++;
		}
		else{
			temp=0;
		}
		if(temp==3){
			temp--;
			e++;
		}
	}
	if(ap[n-2].isdiaoluo==true&&ap[n-1].isdiaoluo==true&&ap[0].isdiaoluo==true){
		e++;
	}
	if(ap[n-1].isdiaoluo==true&&ap[0].isdiaoluo==true&&ap[1].isdiaoluo==true){
		e++;
	}
	cout << t  << ' ' << d << ' ' << e << endl;
	return 0;
} 
