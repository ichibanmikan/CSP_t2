#include <iostream>
#include <algorithm>

using namespace std;

struct stball{
	int no;
	int zb;
	int v;
};

bool cmp1(stball s1, stball s2){
	return s1.zb<s2.zb;
}

bool cmp2(stball s1, stball s2){
	return s1.no<s2.no;
}

int main(){
	int n, l, t;
	cin >> n >> l >> t;
	stball sba[105];
	for (int i=0; i<n; i++){
		cin >> sba[i].zb;
		sba[i].v=1;
		sba[i].no=i;
	}//
	sort(sba, sba+n, cmp1);
	for (int i=0; i<t; i++){
		for (int j=0; j<n; j++){
			sba[j].zb+=sba[j].v;
		}
		for (int j=0; j<n; j++){
			if(j!=n-1){
				if(sba[j].zb==sba[j+1].zb){
					sba[j].v=(-sba[j].v);
					sba[j+1].v=(-sba[j+1].v);
				}
			}
			if(j==n-1){
				if(sba[j].zb==l){
					sba[j].v=(-sba[j].v);
				}
			}
			if(j==0){
				if(sba[j].zb==0){
					sba[j].v=(-sba[j].v);
				}
			}
//			cout << '*' << sba[j].zb << ' ';
		}
//		cout << endl;
	}
	sort(sba, sba+n, cmp2);
	for (int i=0; i<n; i++){
		cout << sba[i].zb << ' ';
	}
	return 0;
}
