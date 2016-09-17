#include<iostream>
using namespace std;
int a[100000];		//ends in 1
int b[100000];		//ends in 0
void func()
{
	a[0]=b[0]=1;
	for(int i=1;i<100000;i++)
	{
		b[i]=a[i-1]+b[i-1];
		a[i]=b[i-1];
	}

}
int main()
{
	func();
	int n;
	cin>>n;
	cout<<a[n-1]+b[n-1];
}
