// CODE FOR OPTIMAL BINARY SEARCH TREE 

#include<bits/stdc++.h>
using namespace std;
int OBST(int freq[], int n)
{
    int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (int L=2; L<=n; L++)
    {
        for (int i=0; i<=n-L; i++)
        {
            int j = i+L-1;
            cost[i][j] = INT_MAX;
            for (int r=i; r<=j; r++)
            {
               int c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + accumulate(freq+i,freq+j+1,0);
               if (c < cost[i][j])
                  cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}
int main()
{
    int keys[] = {10, 12, 16, 21};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d ", OBST(freq, n));
    return 0;
}
