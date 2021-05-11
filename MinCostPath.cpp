/*
Given a Matrix of mxn , there is a Coast associated with
each cell of the Matrix.
Print the Minimum Cost and
Print All the Minumun Cost Paths
You can move only : Horizontal (H)
		    Vertical (V)
I/P:
	Matrix: 
		2 6 1 1 3
		9 1 1 0 5
		0 7 5 2 0
		4 3 0 4 7
		2 0 1 4 1
O/P:
	Path Cost : 20
	Paths : HVHHVHVV
		HHVHVHVV
		HHHVVVHV
TC : O(m * n)
SC : O(m * n)
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main(){

	int arr[5][5] = {
		{2, 6, 1, 1, 3},
		{9, 1, 1, 0, 5},
		{0, 7, 5, 2, 0},
		{4, 3, 0, 4, 7},
		{2, 0, 1, 4, 1}
	};
	int m, n;
	m = 5;
	n = 5;
	int dp[m+1][n+1];
	memset(dp,0,sizeof dp);
	dp[0][0] = arr[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 &&  j!=0){
				dp[i][j] = arr[i][j] + dp[i][j-1];
			}else if(j==0 && i!=0){
				dp[i][j] = arr[i][j] + dp[i-1][j];
			}else{
				dp[i][j] = arr[i][j] + min(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	cout << dp[m-1][n-1] << "\n" ;

	queue<pair<string,pair<int,int>> > q;	//{Path,{Row, Col}}

	q.push({"",{0,0}});
	
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		if(it.s.f == m-1 && it.s.s == n-1){
			cout << it.f << "\n";
		}else if(it.s.f == m-1){
			q.push({it.f+"H", {it.s.f, it.s.s+1}});
		}else if(it.s.s == n-1){
			q.push({it.f+"V", {it.s.f+1, it.s.s}});
		}else{
			if(dp[it.s.f][it.s.s+1] < dp[it.s.f+1][it.s.s]){
				q.push({it.f+"H", {it.s.f, it.s.s+1}});
			}
			else if(dp[it.s.f][it.s.s+1] > dp[it.s.f+1][it.s.s]){
				q.push({it.f+"V", {it.s.f+1, it.s.s}});
			}else{
				q.push({it.f+"H", {it.s.f, it.s.s+1}});
				q.push({it.f+"V", {it.s.f+1, it.s.s}});
			}
		}
	}

	return 0;
}
