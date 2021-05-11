/*
You are given array, find the Maximum no of Non - Overlapping Bridges
Given North and South Poles 
I/P : {{6,4}, {4,3}, {2,6}, {1,5}}
O/P : 2
TC : O(n * n)
SC : O(n * n)
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main(){

	vector<pair<int,int>> Bridges = {{6,4}, {4,3}, {2,6}, {1,5}};
	sort(Bridges.begin(), Bridges.end());
	int n = Bridges.size();
	int dp[n];
	int max=0;
	for(int i=0;i<n;i++){
		int cmax=0;
		for(int j=0;j<i;j++){
			if(Bridges[j].s <= Bridges[i].s){
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