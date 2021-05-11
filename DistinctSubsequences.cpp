/* 
You are given a String str (of length n) and You have to find all the no of distinct Subsequences
I/P : abcbac
O/P : 50
TC : O(n)
SC : O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int count(string str){
	int n=str.length();
	int dp[n+1];
	memset(dp,0,sizeof dp);
	dp[0]=1;
	unordered_map<char,int> mp;
	for(int i=1;i<=n;i++){
		char ch=str[i-1];
		dp[i]=2*dp[i-1];

		if(mp.find(ch)!=mp.end()){
			int j=mp[ch];
			dp[i]=dp[i]-dp[j-1];
		}
		mp[ch]=i;
	}
	return dp[n];
}

int main(){

	string s="abcbac";
	cout << count(s) << "\n" ;

	return 0;
}