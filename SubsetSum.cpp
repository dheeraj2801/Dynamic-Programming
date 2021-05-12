/*
Given an array of integers, print all subsets which add upto target
and print whether it is possible or not
I/P :  4 2 7 1 3
	   10
	   
O/P : 	1(True)
		2 4 
		1 2 3 
		0 1 3 4 


TC : O(m * n)
SC : O(m * n)
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second


void find(int arr[5],int target){
	bool dp[5+1][target+1];
	memset(dp,0,sizeof dp);
	for(int i=0;i<6;i++){
		for(int j=0;j<target+1;j++){
			if(j==0){
				dp[i][j]=true;
			}else if(i==0){
				dp[i][j]=false;
			}else{
				if(dp[i-1][j]){
					dp[i][j]=true;
				}else if(j>=arr[i-1]){
					if(dp[i-1][j-arr[i-1]] == true){
						dp[i][j]=true;
					}
				}
			}
		}
	}
	cout << dp[5][target] << "\n";

	queue<pair<string,pair<int,int>>> q;					// {psf,{i,j}} => psf:PathSoFar, i:Arr Length, j:Target

	q.push({"",{5,target}});
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		if(it.s.f == 0 || it.s.s ==0){
			cout << it.f << "\n";
		}else{
			if(it.s.s >= arr[it.s.f - 1]){
				bool inc = dp[it.s.f-1][it.s.s-arr[it.s.f-1]];
				if(inc){
					q.push({to_string(it.s.f-1)+" "+it.f,{it.s.f-1,it.s.s - arr[it.s.f-1]}});
				}
			}
			bool exc = dp[it.s.f-1][it.s.s];
			if(exc){
				q.push({it.f,{it.s.f-1,it.s.s}});
			}
		}
	}
}

int main(){

	int arr[5] = {4,2,7,1,3};
	find(arr,10);
	return 0;
}