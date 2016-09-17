
// longest common subsequence problem //
#include<bits/stdc++.h>
using namespace std;
int mat[1000][1000];
int lcs(string a,string b,int n,int m)
{
	for(int i=0;i<=n;i++)mat[0][i]=0;
	for(int i=0;i<=m;i++)mat[i][0]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i-1]==a[j-1])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
		}
	}

return mat[m][n];
}
int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.size();
	int m=b.size();
	int length=lcs(a,b,n,m);
	cout<<length;
}
