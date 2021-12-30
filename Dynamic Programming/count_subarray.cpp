//Given an array A1,A2,...,AN, count the number of subarrays of array A which are non-decreasing.
//A subarray A[i,j], where 1≤i≤j≤N is a sequence of integers Ai,Ai+1,...,Aj.

//A subarray A[i,j] is non-decreasing if Ai≤Ai+1≤Ai+2≤...≤Aj. You have to count the total number of such subarrays


#include <iostream>
#include<vector>
typedef long long int ll;
using namespace std;

int main() 
{
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        ll n;
        cin>>n;
        ll count;
        vector<ll> store;
        vector<ll> st;
        for(ll j=0;j<n;j++)
        {
            ll a;
            cin>>a;
            store.push_back(a);    
        }
        count =0;
        for(ll j=0;j<n-1;j++)
        {
            if(store[j]<=store[j+1])
            { 
                count++;
            }
            else
            {
                st.push_back(count);
                count=0;
            }
        }
        if(count)
        {
            st.push_back(count);
            count=0;   
        }
        ll count2 = n;
        
        for(auto e: st)
        {
            count2 = count2 + ((e*(e+1))/2);
        }
        cout<<count2<<endl;
    }
	return 0;
}
