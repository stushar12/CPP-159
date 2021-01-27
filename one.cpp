#include <bits/stdc++.h>
using namespace std;
# define N 1000
vector<int> gr[N];
int n = 6;
// Function to add edge
void Add_edge(int x, int y)
{
	gr[x].push_back(y);
    gr[y].push_back(x);
}


map<int,int> bfs(int source,map<int,int> distance)
{	
    for(int i=0;i<n;i++)
    {
        distance.insert({i,INT_MAX});
    }
    distance[source]=0;

    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int x: gr[node])
        {
            if(distance[x]==INT_MAX)
            {
                q.push(x);
                distance[x]=distance[node]+1;
            }

        }
    }
return distance;
}

int main()
{
map<int,int> distance;
	// Add edges
	Add_edge(0, 3);
    Add_edge(0,1);
	Add_edge(1, 2);
	Add_edge(2, 3);
	Add_edge(4,5);
	Add_edge(3,4);

int source=2;

distance=bfs(source,distance);

for(auto x:distance)
{
    cout<<"Distance of "<<x.first<<" from "<<source<<" is : "<<x.second<<endl;
}

}