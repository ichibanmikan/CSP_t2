#include <iostream>
#include <algorithm>

using namespace std;

struct stu{
	int no;
	int aqxs;
	int isgua;
};
stu array[100005];
int guale[100005];
int meigua[100005];
bool cmp(stu s1, stu s2){
	if(s1.aqxs!=s2.aqxs){
		return s1.aqxs<s2.aqxs;
	}
	return s1.isgua<s2.isgua;
}

int main(){
	int n;
	cin >> n;
	int ju0=0, ju1=0;
	for (int i=0; i<n; i++){
		cin >> array[i].aqxs >> array[i].isgua;
		array[i].no=i;
		if(array[i].isgua==0){
			guale[ju0]=array[i].aqxs;
			ju0++;
		}
		if(array[i].isgua==1){
			meigua[ju1]=array[i].aqxs;
			ju1++;
		}
	}
	sort(array, array+n, cmp);
	sort(meigua, meigua+ju1);
	sort(guale, guale+ju0);
	int temp;
	int tempcw=100005;
	int tempaqxs=-1;
	for (int i=0; i<n; i++){
		int cw=0;
		int ju=0;
		if(array[i].aqxs!=tempaqxs){
			ju=1;
			for (int j=0; j<ju1; j++){
				if(array[i].aqxs>meigua[j]){
					cw++;
				}
				if(array[i].aqxs<=meigua[j]){
					break;
				}
			}
			for (int j=ju0-1; j>=0; j--){
				if(array[i].aqxs<=guale[j]){
					cw++;
				}
				if(array[i].aqxs>guale[j]){
					break;
				}
			}		
		}
		if(cw<=tempcw&&ju==1){
			tempcw=cw;
			temp=i;
		}
		tempaqxs=array[i].aqxs;
	}
	cout << array[temp].aqxs << endl;
	return 0;
}
