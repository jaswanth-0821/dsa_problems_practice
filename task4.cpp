// Task-4:
//  We would like  to get change for m rupees using the minimum number of coins.
//  We have n types of coins whose values are c1, c2, … cn, and enough coins of each type. 
//  Given an array C[ ] of n numbers and value m, write a program to find the minimum -
//  number of coins, whose total worth is m. Assume that c1=1. 




#include <iostream>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;

int find_min_coins(int arr[],int n,int m)
{
    sort(arr,arr+n);
    int count[m+1];
    for(int i=0;i<arr[n-1];i++)
    {
        count[i]= -1;
    }
    count[0]=0;
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(count[i]==-1 && i-arr[j]>=0)
            {
                count[i] = 1+count[i-arr[j]];
                
            }
            else if(i-arr[j]>=0)
            {
                count[i] = min(count[i],count[i-arr[j]]+1);
            }
        }
        
    }
    return count[m];
    
}

int main() 
{
    int m,n;
    cin>>m>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<find_min_coins(arr,n,m);
	return 0;
}



// Given a set S of n number positive integers, and a value m, does there exist a subset X in S,
//  such that the sum of elements in X equals to m. 



#include <iostream>
using namespace std;

int check(int arr[],int n,int m)
{
    int flag[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(j==0)
            {
                flag[i][j]=1;
            }
            else
            {
                flag[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for( int j=1;j<m+1;j++)
        {
            if(j<arr[i-1])
            {
                flag[i][j] = flag[i-1][j];
            }
            else
            {
                flag[i][j] = flag[i-1][j] || flag[i-1][j-arr[i-1]];
            }
        }
    }
    for(int i=0;i<n+1;i++)
    {
        for( int j=0;j<m+1;j++)
        {
            cout<<flag[i][j]<<" ";
        }
        cout<<endl;
    }
    return flag[n][m];
    
}
int main() 
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<check(arr,n,m);
    
    // your code goes here
    return 0;
}
