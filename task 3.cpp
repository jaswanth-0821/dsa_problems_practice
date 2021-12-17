// Task-3:
//     Write a program to implement Kruskal’s algorithm to find the cost of a 
//     minimum weight spanning tree of a given graph. Implement Kruskal’s algorithm
//     using set-disjoint algorithm. Hint: Path compression can be implemented using recursion


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> parent;

bool sortsec(const pair<pair<int,int>,int> &a,
              const pair<pair<int,int>,int> &b)
{
    return (a.second < b.second);
}
int find(unordered_map<int, int> parent,int x)
{
    if (parent[x] == x) 
    {
        return x;
    }
    return find(parent,parent[x]);
}
vector<pair<pair<int,int>,int>> min_spanning_tree(vector<pair<pair<int,int>,int>> edge,int n,int v)
{
    vector<pair<pair<int,int>,int>> mst;
    
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    sort(edge.begin(), edge.end(), sortsec);
    int count=0;
    int j=0;
    while(count!=v && j<n)
    {
        int x = find(parent,edge[j].first.first);
        int y = find(parent,edge[j].first.second);
        // cout<<x<<" "<<y<<endl;
        if(x!=y)
        {
            mst.push_back(edge[j]);
            parent[y] = find(parent,x);
            count++;
        }
        j++;
        
        
    }
    // for(int i=0;i<v;i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    // for(auto e:edge)
    // {
    //     cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<endl;
    // }
    // for(auto e:mst)
    // {
    //     cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<endl;
    // }
    // return mst;
    
    
    
}


int main() 
{
    int n,v;
    cin>>n>>v;
    vector<pair<pair<int,int>,int>> edge;
    int a,b,c;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        edge.push_back(make_pair(make_pair(a,b),c));
    }
    vector<pair<pair<int,int>,int>> mst(v-1);
    mst = min_spanning_tree(edge,n,v);
    // for(auto e:mst)
    // {
    //     cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<endl;
    // }
 
	// your code goes here
	return 0;
}
