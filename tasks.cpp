I have done some tasks that you gave in assignment

finding distance
```
#include <iostream>
#include<vector>
#include <limits>
#include <climits>
using namespace std;

int find_distance(vector<vector<int>> graph,int src ,int des,int v,int e)
{

    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(auto ele: graph[j])
            {
                if((dist[ele]>dist[j]+1) && (dist[j]!=INT_MAX) )
                {
                    dist[ele]=dist[j]+1;
                }
            }
        }
    }
    for(auto ele: dist)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return dist[des];
    
}

int main() 
{

    int n,m;
    cin>>m>>n;
    vector<vector<int>> graph(m);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    int src,des;
    cin>>src>>des;

    find_distance(graph,0,3,4,5);
 
    
	// your code goes here
	return 0;
}
```
finding path
```
#include <iostream>
#include<vector>
#include<stack>
#include <limits>
#include <climits>
using namespace std;

void printpath( vector<pair<int,int>> dist ,int n)
{
    int t = n;
    stack<int> array;
    array.push(n);
    while(t!=0)
    {
        array.push(dist[t].second);
        t = dist[t].second;
        
    }
    
     while (!array.empty()) 
    {
        cout<<"->"<< array.top();
        array.pop();
    }
    return ;
}

int find_distance(vector<vector<pair<int,int>>> graph,int src ,int des,int v,int e)
{

    vector<pair<int,int>> dist(v,{INT_MAX,0});
    dist[src].first=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(auto ele: graph[j])
            {
                if((dist[ele.first].first > dist[j].first + ele.second )  &&  ( dist[j].first != INT_MAX) )
                {
                    dist[ele.first].first = dist[j].first + ele.second ;
                    dist[ele.first].second = j;
                }
            }
        }
    }
    for(auto ele: dist)
    {
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    cout<<endl;
    printpath(dist,des);
    return dist[des].first;
    
}

int main() 
{

    int n,m;
    cin>>m>>n;
    vector<vector<pair<int,int>>> graph(m);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
        
    }
    int src,des;
    cin>>src>>des;

    find_distance(graph,0,3,4,5);
 
    
	// your code goes here
	return 0;
}
```
no of edges
```
#include <iostream>
#include<vector>
#include <limits>
#include <climits>
using namespace std;

int components(vector<vector<int>> graph1,int n)
{
    static vector<vector<int>> graph = graph1;
    

    static int count =0;
    int i= n;
    for(int j=0;j<graph[i].size();j++)
    {
        if(graph[i][j] == -1 )
        {
            return count;
        }
        else
        {
            int x = graph[i][j];
            graph[i][j] =-1;
            if(x != -1)
            {
                components(graph,x);
                count = count+1;
            }
            
        }
        
    }

    return count;
}

int main() 
{
    int n,m;
    cin>>m>>n;
    vector<vector<int>> graph(m);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    cout<<components(graph,0);
	return 0;
}
```
no of components
```
#include <iostream>
#include<vector>
#include <limits>
#include <climits>
#include<queue>
using namespace std;


vector<int> countf( vector<vector<int>> graph, vector<int> check,int i)
{
    queue<int> que;
    que.push(i);
    while(!que.empty())
    {
        int p = que.front();
        que.pop();
        for(int j=0;j<graph[p].size();j++)
        {
            if(check[graph[p][j]] == 0)
            {
                que.push(graph[p][j]);
                
            }
            check[graph[p][j]]=1;
        }
    }
    return check;
    

}

int main() 
{
    int n,m;
    
    cin>>m>>n;
    vector<int> check(m,0);
    vector<vector<int>> graph(m);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    } 
    int count=0;
    
    for(int i=0;i<m ; i++)
    {
        if(check[i]==0)
        {
            check = countf(graph,check,i);
            count++;
        }
      
    }
    cout<<count;
	// your code goes here
	return 0;
}
```
detecting cycle
```
#include <iostream>
#include<vector>
#include <limits>
#include <climits>
#include<queue>
using namespace std;

void findcicle( vector<vector<int>> graph,int m)
{
    
    vector<int> check(m,0);
    check[0]=1;
    int cont=1;
    queue<int> que;
    que.push(0);
    while((!que.empty()) && cont)
    {
        
        int p = que.front();
        que.pop();
        for(int j=0;j<graph[p].size();j++)
        {
            if( check[graph[p][j]]==1)
            {
                cont=0;
                break;
            }
            if(check[graph[p][j]] == 0)
            {
                que.push(graph[p][j]);
                
            }
         
            check[graph[p][j]]=1;
        }
    }
    if(cont==0)
    {
        cout<<"cycle is present";
    }
    return ;
    

}

int main() 
{
    int n,m;
    
    cin>>m>>n;

    vector<vector<int>> graph(m);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    } 
    findcicle(graph,4);
    

   
	// your code goes here
	return 0;
}
```

