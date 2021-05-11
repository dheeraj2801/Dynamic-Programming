/*
You are given array, find the Maximum Sum Increasing Subsequence
I/P : 10 22 9 33 21 50 41 60 80 3
O/P : 255
TC : O(n * n)
SC : O(n * n)
*/
#include<bits/stdc++.h>
using namespace std;

int Maximum_Sum(int arr[], int n){
	int dp[n];
	int maxval=INT_MIN;
	for(int i=0;i<n;i++){
		int max=INT_MIN;
		for(int j=0;j<i;j++){
			if(arr[j]<=arr[i]){
				if(max==INT_MIN){
					max=dp[j];
				}else if(dp[j]>max){
					max=dp[j];
				}
			}
		}
		if(max==INT_MIN){
			dp[i]=arr[i];
		}else{
			dp[i]=max+arr[i];
		}
		if(dp[i]>maxval){
			maxval=dp[i];
		}
	}
	return maxval;
}

int main(){

	int arr[] = {10,22,9,33,21,50,41,60,80,3};
	int n = 10;
	cout << Maximum_Sum(arr, n) << "\n" ;

	return 0;
}