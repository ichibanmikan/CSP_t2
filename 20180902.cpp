#include <iostream>
#include <algorithm>

using namespace std;

struct st{
	int time;
	int peo;//0H 1W
	int isqu;//1qu 0hui
};

bool cmp(st s1, st s2){
	if(s1.time!=s2.time){
		return s1.time<s2.time;
	}
	return s1.isqu>s2.isqu;
}

int main(){
	int n;
	cin >> n;
	st sta[10005];
	int ju=0;
	for (int i=0; i<n; i++){
		cin >> sta[ju].time;
		sta[ju].peo=0;
		sta[ju].isqu=1;
		ju++;
		cin >> sta[ju].time;
		sta[ju].peo=0;
		sta[ju].isqu=0;
		ju++;
	}
	for (int i=0; i<n; i++){
		cin >> sta[ju].time;
		sta[ju].peo=1;
		sta[ju].isqu=1;
		ju++;
		cin >> sta[ju].time;
		sta[ju].peo=1;
		sta[ju].isqu=0;
		ju++;
	}
	sort(sta, sta+ju, cmp);
	int result=0;
	int i=0;
	int j=sta[0].time;
	int temp1=-1, temp2=-1;
//	while(i<ju){
//		if(sta[i].isqu==1&&sta[i].peo==0){
//			temp=i;
//			break;
//		}
//	}
//	i=0;
	while(i<ju){
		if(sta[i].isqu==1&&sta[i].peo==0){
			temp1=i;
		}
		if(sta[i].isqu==0&&sta[i].peo==0){
			temp2=i;
		}
		if(temp1!=-1&&temp2!=-1){
			int m1=0, m2=0;
			int t1=0, t2=0, t3=0;
			for (int k=temp1; k<=temp2; k++){
				if(sta[k].isqu==1&&sta[k].peo==1){
					m1=k;
				}
				else if(sta[k].isqu==0&&sta[k].peo==1){
					m2=k;
				}
				if(m1==0&&m2!=0){
//					cout << '*' << 1 << ' ' << m2 << ' ' << temp1 << ' ' << temp2 << endl;
					result+=(sta[m2].time-sta[temp1].time);
					m2=0;
					t1++;
				}
				else if(m1!=0&&m2!=0){
					result+=(sta[m2].time-sta[m1].time);
//					cout << '*' << 2 << ' ' << m1 << ' ' << m2 <<' ' << temp1 << ' ' << temp2 << endl;
					m1=0;
					m2=0;
					t2++;
				}
				else if(m1!=0&&m2==0&&k==temp2){
					result+=(sta[temp2].time-sta[m1].time);
//					cout << '*' << 3 << ' ' << m1 << ' ' << temp1 << ' ' << temp2 << endl;
					m1=0;
					t3++;
				}
				else if(t1==0&&t2==0&&t3==0&&k==temp2){
					int ap=temp1;
					while(ap>=0){
						if(sta[ap].peo==1){
							if(sta[ap].isqu==1){
								result+=sta[temp2].time-sta[temp1].time;
							}
							break;
						}
						ap--;
					}
				}
			}
//			cout << result << endl;
			temp1=-1;
			temp2=-1;
		}
		i++;
	}
	cout << result << endl;
	return 0;
}
