/*
You are given a Matrix of size mxn and ,You are at the first column 
you need to reach the last column and each cell contains gold, you need to pick the maximum Gold
You can move only Right, Top Right, Bottom Right
(i,j) => (i+1,j) or (i-1,j+1) or (i+1,j+1)
Find maximum amount of Gold that can be collected and All Possible Paths

d1 = (i+1,j)
d2 = (i-1,j+1)
d3 = (i+1,j+1)

I/P : 	3 2 3 1
	  	2 4 6 0
	  	5 0 1 3
	  	9 1 5 1

O/P : 	18
		5  d1 d2 d3
		9  d2 d2 d1
		9  d1 d1 d3

TC : O(m * n)
SC : O(m * n)
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

void find(int arr[4][4],int m,int n){
	int dp[m][n];
	memset(dp,0,sizeof dp);
	for(int j=n-1;j>=0;j--){
		for(int i=0;i<m;i++){
			if(j==n-1){
				dp[i][j] = arr[i][j];
			}
			else if(i==0){
				dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
			}
			else if(i==m-1){
				dp[i][j] = arr[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
			}
			else{
				dp[i][j] = arr[i][j] + max(dp[i][j+1], max(dp[i-1][j+1], dp[i+1][j+1]));
			}
		}
	}
	int ma=INT_MIN;
	for(int i=0;i<n;i++){
		if(dp[i][0]>ma){
			ma=dp[i][0];
		}
	}

	cout << ma << "\n";

	queue<pair<string,pair<int,int>>> q;			// {psf,{i,j}} => psf:PathSoFar, i:Row, j:Column

	for(int i=0;i<n;i++){
		if(dp[i][0] == ma){
			q.push({to_string(arr[i][0])+" ",{i,0}});
		}
	}
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		if(it.s.s == n-1){
			cout << it.f << "\n";
		}else if(it.s.f == 0){
			int g = max(dp[it.s.f][it.s.s+1], dp[it.s.f+1][it.s.s+1]);
			if(g == dp[it.s.f][it.s.s+1]){
				q.push({it.f+" d2",{it.s.f, it.s.s+1}});
			}
			if(g == dp[it.s.f+1][it.s.s+1]){
				q.push({it.f+" d3",{it.s.f+1,it.s.s+1}});
			}
		}else if(it.s.f == n-1){
			int g = max(dp[it.s.f][it.s.s+1], dp[it.s.f-1][it.s.s+1]);
			if(g == dp[it.s.f][it.s.s+1]){
				q.push({it.f+" d2",{it.s.f, it.s.s+1}});
			}
			if(g == dp[it.s.f-1][it.s.s+1]){
				q.push({it.f+" d1",{it.s.f-1,it.s.s+1}});
			}
		}else{
			int g =max(dp[it.s.f][it.s.s+1], max(dp[it.s.f-1][it.s.s+1], dp[it.s.f+1][it.s.s+1]));
			if(g == dp[it.s.f][it.s.s+1]){
				q.push({it.f+" d2",{it.s.f, it.s.s+1}});
			}
			if(g == dp[it.s.f+1][it.s.s+1]){
				q.push({it.f+" d3",{it.s.f+1,it.s.s+1}});
			}
			if(g == dp[it.s.f-1][it.s.s+1]){
				q.push({it.f+" d1",{it.s.f-1,it.s.s+1}});
			}

		}
	}
}

int main(){

	int arr[4][4] = {{3, 2, 3, 1},
					 {2, 4, 6, 0},
					 {5, 0, 1, 3},
					 {9, 1, 5, 1}
					};
	int m=4,n=4;
	find(arr,m,n);
	return 0;
}