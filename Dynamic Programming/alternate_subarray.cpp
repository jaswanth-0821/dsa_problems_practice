There is an array A consisting of N non-zero integers A1..N.
A subarray of A is called alternating if any two adjacent elements in it have different signs 
(i.e. one of them should be negative and the other should be positive).
For each x from 1 to N, compute the length of the longest alternating subarray that starts at x - that is,
a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray is y-x+1.

'https://www.codechef.com/problems/ALTARAY'


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
        // cerr<<1;
        ll n;
        cin>>n;
        vector<ll> store;
        vector<ll> st;
        for(ll j=0;j<n;j++)
        {
            // cerr<<2;
            ll a;
            cin>>a;
            store.push_back(a);    
        }
        for(ll j=0;j<n-1;j++)
        {
            st.push_back(0);
        }
        st.push_back(1);

        for(ll j=n-2;j>=0;j--)
        // for(ll j=0;j<n-1;j++)
        {
            // cerr<<3;
            if(((store[j]>0)&&(store[j+1]<0))|| ((store[j]<0)&&(store[j+1]>0)))
            {
                st[j] =st[j+1]+1;
            }
            else
            {
                st[j]=1;
            }
        }
        for(ll j=0;j<n;j++)
        {
            cout<<st[j]<<" ";
        }
        cout<<endl;
    }
	// your code goes here
	return 0;
}
