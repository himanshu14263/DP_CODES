// Q: You have been given a rod of length(l) and u have to find how to cut the rod in pieces such that
//    sum of cost of such pieces is maximum.
//    INPUT GIVEN : Array of size(l-1) which contains the cost of all the pieces of size less than l.
//              eg:- len=5
/*                   given array is :- 2,5,7,8
for all size of pieces less than len:- 1,2,3,4
*/
#include <bits/stdc++.h>
using namespace std;
int mat[1000][1000];
int price[100000];
int func(int len)
{
	for(int i=0;i<=len-1;i++)
	{
		for(int j=0;j<=len;j++)
		{
			if(i==0||j==0)mat[i][j]=0;
			else if(i>j)mat[i][j]=mat[i-1][j];
			else mat[i][j]=max(mat[i-1][j],price[i-1]+mat[i][j-i]);
		}
	}
	// REMOVE THE COMMENT TO PRINT THE DP MATRIX
	/*for(int i=0;i<=len-1;i++)
    {
        for(int j=0;j<=len;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }*/
	return mat[len-1][len];
}
int main()
{
	int len;
	cin>>len;
	for(int i=0;i<len-1;i++)cin>>price[i];

		cout<<func(len);
}
