#include<bits/stdc++.h>

using namespace std;

char grid[1000][1000];
int num[1000][1000];
int dist[1000],dist_jerry[1000],dist_tom[1000];
vector<int> exits;
vector<int> graph[1000];
int n,m;
int tom,jerry;
int cnt;

void fill_grid()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='E' || grid[i][j]=='T' || grid[i][j]=='J')
            {
                num[i][j]=++cnt;
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    exits.push_back(cnt);
                }
                if (grid[i][j]=='J')
                    jerry=cnt;
                if (grid[i][j]=='T')
                    tom=cnt;
            }
        }
    }
}

void make_graph()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(num[i][j]!=0)
            {
                if(i-1>=0 && num[i-1][j]!=0)
                    graph[num[i][j]].push_back(num[i-1][j]);

                if(i+1<n && num[i+1][j]!=0)
                    graph[num[i][j]].push_back(num[i+1][j]);

                if(j-1>=0 && num[i][j-1]!=0)
                    graph[num[i][j]].push_back(num[i][j-1]);

                if(j+1<m && num[i][j+1]!=0)
                    graph[num[i][j]].push_back(num[i][j+1]);
            }
        }
    }
}

void bfs(int v)
{
    queue<int>q;
    dist[v]=0;
    q.push(v);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=0; i<graph[temp].size(); i++)
        {
            if(dist[temp]+1 < dist[graph[temp][i]])
            {
                dist[graph[temp][i]]=dist[temp]+1;
                q.push(graph[temp][i]);
            }
        }
    }
}

void fill_distances()
{
    bfs(jerry);
    for(int i=0; i<=cnt; i++)
    {
        dist_jerry[i]=dist[i];
        dist[i]=1000;
    }
    bfs(tom);
    for(int i=0; i<=cnt; i++)
    {
        dist_tom[i]=dist[i];
    }
}

void check_winner()
{
    for(int i=0; i<exits.size(); i++)
    {
        if(dist_jerry[exits[i]]<dist_tom[exits[i]])
        {
            cout<<endl<<"Jerry";
            return;
        }
    }
    cout<<endl<<"Tom";
    return;
}

int main()
{
    fill_grid();
    for(int i=0; i<=cnt; i++)
    {
        dist_jerry[i]=1000;
        dist_tom[i]=1000;
        dist[i]=1000;
    }
    make_graph();
    fill_distances();
    check_winner();
    return 0;
}
