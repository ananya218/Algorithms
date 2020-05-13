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

struct hash_pair {
template <class T1, class T2> 
size_t operator()(const pair<T1, T2>& p) const {
   auto hash1 = hash<T1>{}(p.first); 
   auto hash2 = hash<T2>{}(p.second);
   return hash1 ^ hash2;}
};

lli query(lli segment[], lli ql, lli qr, lli l, lli r, lli i)
{
  if(qr < l || ql>r)
  {
    return 0;
  }
  else if(l>=ql && r<=qr)
  {
    return segment[i];
  }

  lli mid = (l+r)/2;
  lli a = query(segment, ql, qr, l, mid, 2*i);
  lli b = query(segment, ql, qr, mid+1, r, 2*i+1);
  return a+b;
}

void update(lli segment[], lli l, lli r, lli i, lli p, lli val)
{
  if(l==r)
  {
    segment[i]+=val;
    return ;
  }

  lli mid = (l+r)/2;
  if(p<=mid)
  {
    update(segment, l, mid, 2*i, p, val);
  }
  else
  {
    update(segment, mid+1, r, 2*i+1, p, val);
  }
  segment[i] = segment[2*i] + segment[2*i+1];
} 


int main()
{
   lli n, q;
   cin>>n>>q;
   lli segmenttree[4*n];
   fr(i,0,4*n)
   segmenttree[i] = 0;

   while(q--)
   {
     string s;
     cin>>s;
     if(s == "find")
     {
       lli ql, qr;
       cin>>ql>>qr;
       cout << query(segmenttree,ql-1,qr-1,0,n-1,1)<<endl;
     }
     else
     {
       lli p,val;
       cin>>p>>val;
       update(segmenttree, 0, n-1, 1, p-1, val);
     }
     
   }

}