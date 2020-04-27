#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

void aprint(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  cout << endl;
}

void buildlps(vector<int> &lps, string str)
{
  int len = str.length();
  lps[0] = 0;
  int j = 0, i = 1;
  while (i < len)
  {
    if (str[i] == str[j])
    {
      lps[i] = j + 1;
      j++;
      i++;
    }
    else
    {
      if (j == 0)
      {
        lps[i] = 0;
        i++;
      }
      else
        j = lps[j - 1];
    }
  }
}

int main()
{
  string text, pattern;
  cin >> text >> pattern;
  int len1 = text.length();
  int len2 = pattern.length();
  vector<int> lps;
  lps.assign(len2, 0);
  buildlps(lps, pattern);
  int i = 0, j = 0;
  while (i < len1)
  {
    if (text[i] == pattern[j])
    {
      j++;
      i++;
    }
    else
    {
      if (j == 0)
        i++;
      else
        j = lps[j - 1];
    }

    if (j == len2)
    {
      cout << i - j << endl;
      j = 0;
    }
  }
}