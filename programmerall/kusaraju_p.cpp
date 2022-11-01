#include<iostream>
#include<cstring>
using namespace std;
int map[100][100],nmap[100][100];
int visit[100];
int time1[100];
int post[100];
int n,m,num=0,postid=0;
void dfs(int id);
void ndfs(int id);
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
      {
          int x,y;
          cin>>x>>y;
          map[x][y]=1;
          nmap[y][x]=1;
      }
    for(int i=1;i<=n;i++)
      if(visit[i]==0)
        dfs(i);
    for(int i=n;i>=1;i--)
      if(visit[post[i]]==1)
        {
          ndfs(post[i]);
          num++;
        }
    cout<<num<<endl;
    return 0;      
}
void dfs(int id)
{
    visit[id]=1;
    for(int i=1;i<=n;i++)
     if(visit[i]==0 && map[id][i])
       dfs(i);
     postid++;
     post[postid]=id;     
}
void ndfs(int id)
{
    visit[id]=0;
    for(int i=1;i<=n;i++)
     if(visit[i]==1 && nmap[id][i])
       ndfs(i);
}
//Kosaraju algorithm template