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

int root[100005];
vector<int>sizeofcomponent(100005,1);

int findcomponent(int x)
{
  if(x == root[x])
  return x;
  //path compression
  return root[x] = findcomponent(root[x]);
}

void unionz(int x, int y)
{
  int a = findcomponent(x);
  int b = findcomponent(y);
  if(a == b)
  return;
  //path optimization using size as a rank
  if(sizeofcomponent[a]<sizeofcomponent[b])
  swap(a,b);
  sizeofcomponent[a]+=sizeofcomponent[b];
  sizeofcomponent[b]=0;
  root[b] = a;
}

int main()
{
   lli n,m;
   cin>>n>>m;

   fr(i,0,n)
   root[i]=i;

    for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      a--,b--;
      unionz(a,b);
    }
    for(int i=0;i<n;i++)
    cout<<sizeofcomponent[i]<<" ";
    cout<<endl;
}