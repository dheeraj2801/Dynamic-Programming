/* Envelope Problem OR Russian Doll Model
You are given n Boxes and their sizes [Height, Width]
Find tha Maximum no of enevelopes that can be nested inside each other
I/P : {{17,5}, {26,18}, {25,34}, {48,84}, {63,72}, {42,86}}
O/P : 3
TC : O(n * n)
SC : O(n * n)
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main(){

	vector<pair<int,int>> Envelope = {{17,5}, {26,18}, {25,34}, {48,84}, {63,72}, {42,86}};
	sort(Envelope.begin(), Envelope.end());
	int n = Envelope.size();
	int dp[n];
	int max=0;
	for(int i=0;i<n;i++){
		int cmax=0;
		for(int j=0;j<i;j++){
			if(Envelope[j].s < Envelope[i].s && Envelope[j].f < Envelope[i].f){
				if(dp[j]>cmax){
					cmax=dp[j];
				}
			}
		}
		dp[i]=cmax+1;
		if(dp[i]>max){
			max=dp[i];
		}
	}
	cout << max << "\n";
	return 0;
}