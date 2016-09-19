// FINDING THE NUMBER OF DISTINCT SUBSEQUENCES WHICH CAN BE FORMED FROM A GIVEN STRING

#include<bits/stdc++.h>
using namespace std;
int countSub(string s)
{
	int l=s.length();
	int dp[l];
	vector<int>last(256,-1);
	dp[0]=1;
	for(int i=1;i<=l;i++)
	{
		dp[i]=2*dp[i-1];
		if(last[s[i-1]]!=-1)
		{
			dp[i]=dp[i]-dp[last[s[i-1]]];
		}
		last[s[i-1]]=i-1;
	}
	return dp[l];
}
int main()
{
	string s;
	cout<<"enter the string \n";
	cin>>s;
	cout<<countSub(s);
}
