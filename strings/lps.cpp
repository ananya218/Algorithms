#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        cout<<"enter a string"<<'\n';
        string a;
        cin>>a;

        int j=0,k=1;

        int lps[100];
        lps[0]=0;

        while(k<a.length())
        {
            if(a[k]==a[j])
            {
                lps[k]=j+1;
                k++;
                j++;
            }

            else
            {
                if(j==0)
                {
                    lps[k]=j;
                    k++;
                }

                else
                {
                    j=lps[j-1];
                }
                
            }
            
        }

        cout<<"The lps array is :-"<<endl;

        for(int j=0;j<a.length();j++)
        {
            cout<<"j= "<<j<<" "<<lps[j]<<endl;
        }
    }
}