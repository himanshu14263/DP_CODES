////////// CODE FOR KNACKSAP PROBLEM  ////////////
//for more doubts clearance refer ur notebook or g4g.


#include<bits/stdc++.h>
using namespace std;
int wt[100000];
int val[100000];
int mat[1000][1000];
/////////////// DP SOLUTION  ////////////////
int func(int W,int n)
{
	memset(mat,0,sizeof(mat));
	//memset(val,0,sizeof(val));
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0||w==0)mat[i][w]=0;
			else if(wt[i-1]<=w)mat[i][w]=max(mat[i-1][w],val[i-1]+mat[i-1][w-wt[i-1]]);
			else mat[i][w]=mat[i-1][w];
		}
	}
	return mat[n][W];
}
///////////////// RECURCIVE FUNCTION ///////////////////////////////
int func2(int W,int n)
{
	if(n==0||W==0)return 0;
	else if(wt[n-1]>W)return func2(W,n-1);
	else return (max(func2(W,n-1),val[n-1]+func2(W-wt[n-1],n-1)));
}
int main()
{
	int W,n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>wt[i];
	for(int i=0;i<n;i++)cin>>val[i];
	cin>>W;
	cout<<func2(W,n);
}
