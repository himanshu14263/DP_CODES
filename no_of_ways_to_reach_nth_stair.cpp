// A C program to count number of ways to reach n't stair when
// a person can climb 1, 2, ..m stairs at a time.
#include<stdio.h>
 
// A simple recursive program to find n'th fibonacci number
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}
 
// Returns number of ways to reach s'th stair
int countWays(int s)
{
    return fib(s + 1);
}
 
// Driver program to test above functions
int main ()
{
  int s = 4;
  printf("Number of ways = %d", countWays(s));
  getchar();
  return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////


// A C program to count number of ways to reach n't stair when
// a person can climb 1, 2, ..m stairs at a time
#include<stdio.h>
 
// A recursive function used by countWays
int countWaysUtil(int n, int m)
{
    int res[n];
    res[0] = 1; res[1] = 1;
    for (int i=2; i<n; i++)
    {
       res[i] = 0;
       for (int j=1; j<=m && j<=i; j++)
         res[i] += res[i-j];
    }
    return res[n-1];
}
 
// Returns number of ways to reach s'th stair
int countWays(int s, int m)
{
    return countWaysUtil(s+1, m);
}
 
// Driver program to test above functions
int main ()
{
    int s = 4, m = 2;
    printf("Nuber of ways = %d", countWays(s, m));
    return 0;
}



//////////////   MY CODE FOR " number of ways to reach n't stair when a person can climb 1, 2, ..m stairs at a time"///////////////////////////////////////////////////////////////


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100000];
void fact()
{
	a[0]=0;a[1]=1;
	for(int i=2;i<=100000;i++)
		a[i]=a[i-1]+a[i-2];
}
ll calc(int n,int m)
{
	ll ans=0;
	for(int i=1;i<=m && i<=n;i++)
	{
		ans+=a[n-i];
	}
	return ans;
}
int main()
{
	fact();
	int n,m;
	cin>>n>>m;
	cout<<calc(n+1,m);
}
