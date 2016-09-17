
// longest increasing subsequence using n^2 approach


#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)b[i]=1;
	for(int i=1;i<n;i++)
	{
		int j=0;
		for(;j<i;j++)
		{
			if(a[j]<a[i])
			{
				b[i]=max(b[j]+1,b[i]);
			}
		}
	}


	int *max=max_element(b,b+n);
	cout<<*max<<"\n";


}
