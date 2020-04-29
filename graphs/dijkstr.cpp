#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

unordered_map<lli, lli> mp;
bool visited[100005];
vector<pair<lli, lli>> vect[100005];
int dist[100005];
typedef pair<lli, lli> pl;

void dikestra(lli a)
{
  priority_queue<pl, vector<pl>, greater<pl>> pq;
  dist[a] = 0;
  pq.push({0, 1});
  while (!pq.empty())
  {
    pl t1 = pq.top();
    pq.pop();
    visited[t1.second] = 1;
    for (pair<int, int> child : vect[t1.second])
    {
      if (!visited[child.first])
      {
        if (dist[t1.second] + child.second < dist[child.first])
        {
          dist[child.first] = dist[t1.second] + child.second;
          pq.push({dist[child.first], child.first});
        }
      }
    }
  }
}

int main()
{
  lli tc;
  cin >> tc;
  while (tc--)
  {
    lli n, m, a, b, c;
    cin >> n >> m;
    fr(i, 0, m)
    {
      int a, b, c;
      cin >> a >> b >> c;
      vect[a].push_back({b, c});
      vect[b].push_back({a, c});
    }
    fr(i, 0, n + 1)
        dist[i] = pow(10,9);
    dikestra(1);
    fr(i,2,n+1)
    cout<<dist[i]<<" ";
  }
}
