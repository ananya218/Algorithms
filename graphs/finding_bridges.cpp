#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

vector<int>vect[100005];
bool visited[100005];
int in[100005];
int low[100005];
int timer;

void dfs(int root, int parent = -1)
{
  visited[root]=true;
  in[root] = low[root] = timer++;
  for(int child : vect[root])
  {
    if(child == parent) continue;
    else if(visited[child]) low[root] = min(low[root], in[child]);
    else{
      dfs(child,root);
      if(in[root] < low[child]) cout<<"the edge "<<root<<" -> "<<child<<" is a bridge."<<endl;
      low[root] = min(low[root], low[child]);
    }
  }
}

int main()
{
   lli n,m;
   cin>>n>>m;
   fr(i, 0, m)
   {
     int a, b;
     cin>>a>>b;
     vect[a].pb(b);
     vect[b].pb(a);
   }
   fr(i,0,n)
   {
     if(!visited[i])
     dfs(i);
   }
}
