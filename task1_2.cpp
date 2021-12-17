// Task-1:
// Given a graph G, a source vertex s and a target vertex t, write a program to find the distance between s and t.


#include <iostream>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;

void find_distance(vector<vector<int>>graph,int m,int n,int s,int d)
{
    vector<bool>flag(m+1,true);
    queue<int>lis;
    vector<int>dis(5,0);
    lis.push(s);
    flag[s]= false;
    while(!lis.empty())
    {
        int x = lis.front();
        for(int i=0;i<graph[x].size();i++)
        {
            if(flag[graph[x][i]])
            {
                lis.push(graph[x][i]);
            }
            if(dis[graph[x][i]]==0 && graph[x][i]!=s)
            {
                dis[graph[x][i]] = dis[x] + 1;
            }
            else if(dis[graph[x][i]]>0)
            {
                dis[graph[x][i]] = min(dis[graph[x][i]],dis[x] + 1);
            }
        }
        flag[x] = false;
        lis.pop();
    }
    for(auto e:dis)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return;
    
}

int main() 
{
    int a,b;
    vector<vector<int>>graph(5);
    for(int i=0;i<5;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    find_distance(graph,4,5,2,4);
	return 0;
}


// Task-2:


// Variant: Write a program to print the shortest path between s and d.


#include <iostream>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;

int find_distance(vector<vector<int>>graph,int m,int n,int s,int d)
{
    vector<bool>flag(m+1,true);
    queue<int>lis;
    vector<int>dis(5,0);
    lis.push(s);
    flag[s]= false;
    while(!lis.empty())
    {
        int x = lis.front();
        for(int i=0;i<graph[x].size();i++)
        {
            if(flag[graph[x][i]])
            {
                lis.push(graph[x][i]);
            }
            if(dis[graph[x][i]]==0 && graph[x][i]!=s)
            {
                dis[graph[x][i]] = dis[x] + 1;
            }
            else if(dis[graph[x][i]]>0)
            {
                dis[graph[x][i]] = min(dis[graph[x][i]],dis[x] + 1);
            }
        }
        flag[x] = false;
        lis.pop();
    }
    return dis[d];
    
}

int main() 
{
    int a,b;
    int v,e,s,d;
    cin>>v>>e;
    vector<vector<int>>graph(v+1);
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin>>s>>d;
    for(int i=0;i<v+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<find_distance(graph,v,e,s,d)<<endl;
    return 0;
}



// Variant: Write a program to find the number of components in a graph G.


#include <iostream>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;



void check(vector<vector<int>>graph,vector<bool>&flag,int t)
{
    queue<int>lis;
    lis.push(t);
    while(!lis.empty())
    {
        int x = lis.front();
        for(int i=0;i<graph[x].size();i++)
        {
            if(!(flag[graph[x][i]]))
            {
                lis.push(graph[x][i]);
            }
            
        }
        flag[x]=true;
        lis.pop();
    }
    return;
        
    
}
int main() 
{
    int a,b;
    int e;
    int v;
    cin>>v>>e;
    vector<vector<int>>graph(v+1);
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // for(int i=0;i<v+1;i++)
    // {
    //     for(int j=0;j<graph[i].size();j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int count =0;
    
    vector<bool>flag(v+1,false);
    for(int i=1;i<v+1;i++)
    {
        if(!flag[i])
        {
            count++;
            check(graph,flag,i);
        }
        for(auto e:flag)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<count;
    
    return 0;
}

// Variant: Write a program to find whether there exists a cycle in the input graph or not.



#include <iostream>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;



bool find_circle(vector<vector<int>>graph,vector<bool>&flag,int t)
{
    queue<int>lis;
    lis.push(t);
    while(!lis.empty())
    {
        int x = lis.front();
        for(int i=0;i<graph[x].size();i++)
        {
            if(!(flag[graph[x][i]]))
            {
                lis.push(graph[x][i]);
            }
            if(flag[x])
            {
                return true;
            }
            
        }
        flag[x]=true;
        lis.pop();
    }
    return false;
        
    
}
int main() 
{
    int a,b;
    int e;
    int v;
    cin>>v>>e;
    vector<vector<int>>graph(v+1);
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=0;i<v+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    bool check = false;
    
    vector<bool>flag(v+1,false);
    for(int i=1;i<v+1;i++)
    {
        if(!flag[i] && !check)
        {
            
            check = find_circle(graph,flag,i);
        }
    }
    cout<<check;
    
    return 0;
}