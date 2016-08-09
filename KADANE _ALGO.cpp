#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int*start ,int*last ,int n)
{
    *last=-1;
    int curr_sum=0,largest_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum=curr_sum+arr[i];
        if(curr_sum<0)
        {
             curr_sum=0;
             *start=i+1;
        }

        else if(curr_sum>largest_sum)
        {
            largest_sum=curr_sum;
            *last=i;
        }
    }
    if(*last!=-1)
        return largest_sum;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest_sum)
        {
            largest_sum=arr[i];
            *start=*last=i;
        }
    }
    return largest_sum;
}
int main()
{
    int arr[]={-1,-2,3,4};
    int start,last;
    cout<<func(arr,&start,&last,4);
    cout<<"\n";
    cout<<start<<"    "<<last;
}


