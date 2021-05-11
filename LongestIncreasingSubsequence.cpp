/*
You are given array, find the Longest Increasing Subsequence
I/P : 10 22 9 33 21 50 41 60 80
O/P : 6
TC : O(n * n)
SC : O(n * n)
*/
#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[],int n){
	int max=0;
	int dp[n];
	for(int i=0;i<n;i++){
		int cmax=0;
		for(int j=0;j<i;j++){
			if(arr[j]<=arr[i]){
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
	return max;
}

int main(){

	int arr[] = {10,22,9,33,21,50,41,60,80};
	int n = 9;
	cout << LIS(arr, n) << "\n" ;

	return 0;
}