#include <bits/stdc++.h>
using namespace std;
int mat[1000][1000];
//IMPLEMENTATION OF KADANE'S ALGORITHM.
int kadane(int arr[],int*start ,int*last ,int n)
{

    *last=-1;   // JUST TO CHECK IF ALL THE ELEMENTS ARE NEGATIVE
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

    // TO HANDLE THE CASE IF ALL THE NUMBERS IN THE ARRAY ARE NEGATIVE

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
int LargestSumRect(int row ,int col)
{
    int temp[100000];
    int maxsum=INT_MIN;
    int left,right,top,bottom,ftop,fbottom;;
    for(int i=0;i<col;i++)
    {
        memset(temp,0,sizeof(temp));
        for(int j=i;j<col;j++)
        {
            for(int k=0;k<row;k++)
                temp[k]+=mat[k][j];
            int sum=kadane(temp,&top,&bottom,row);
            if(sum>maxsum)
            {
                maxsum=sum;
                left=i;
                right=j;
                ftop=top;
                fbottom=bottom;
            }
        }
    }

    cout<<"maxsum   :"<<maxsum<<"\n";
    cout<<"left :"<<left<<"\n";
    cout<<"right    :"<<right<<"\n";
    cout<<"top  :"<<ftop<<"\n";
    cout<<"bottom   :"<<fbottom<<"\n";
}
int main()
{
    int row,col;
    cout<<"ENTER THE NO OF ROWS AND COLUMN\n";
    cin>>row >>col;
    cout<<"ENTER THE VALUE IN THE MATRIX\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
         cin>>mat[i][j];
        }
    }

    LargestSumRect(row,col);

}


