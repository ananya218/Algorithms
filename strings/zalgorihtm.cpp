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

void build(int zarray[], string str)
{
  int left, right;
  left = right = 0;
  zarray[0]=0;
  int n = str.length();
  fr(i,0,n)
  {
    if(i>right)
    {
      right = left = i;
      while(right < n && str[right] == str[right-left])
      right++;
      zarray[i]=right-left;
      right--;
    }
    else
    {
      int k = i-left;
      if(zarray[k] <= right - i)
      zarray[i]=zarray[k];
      else
      {
        left = i;
        while(right<n && str[right-left] == str[right])
        right++;
        zarray[i]=right-left;
        right--;
      }
      
    }
    
  }
}

int main()
{
   string text, pattern;
   cin>>text>>pattern;
   string str = pattern+'$'+text;
   int zarray[str.length()];
   build(zarray, str);
   fr(i,0,str.length())
   {
     if(zarray[i] == pattern.length())
     cout<<i - 1 - pattern.length()<<endl;
   }
}