#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

vector<int>merge(vector<int>f1,vector<int>f2)
{
    vector<int>retrn;
    int i=0,j=0;
    while(i<f1.size()&&j<f2.size())
    {
        if(f1[i]==f2[j])
        {
            retrn.push_back(f1[i]);
            retrn.push_back(f2[j]);
            i++;
            j++;
        }

        else if(f1[i]<f2[j])
        {
            retrn.push_back(f1[i]);
            i++;
        }

        else
        {
            retrn.push_back(f2[j]);
            j++;
        }
        
    }

    if(i==f1.size())
    {
        while(j<f2.size())
        {
            retrn.push_back(f2[j]);
            j++;
        }
    }

    else 
    {
        while(i<f1.size())
        {
            retrn.push_back(f1[i]);
            i++;
        }
    }

    return retrn;

}

void split(vector<int>&A,vector<int>&f1,vector<int>&f2)
{
    if(A.size()<2)
    return;

    int half=A.size()/2;
    for(int i=0;i<half;i++)
    {
        f1.push_back(A[i]);
    }

    for(int i=half;i<A.size();i++)
    {
        f2.push_back(A[i]);
    }
}

void mergesort(vector<int>&A)
{
    vector<int>f1,f2;
    split(A,f1,f2);
    if(f1.size()>1)
    mergesort(f1);
    if(f2.size()>1)
    mergesort(f2);
    A=merge(f1,f2);
}

int main()
{
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        cout<<"enter the size of the array"<<endl;
        int size;
        cin>>size;
        cout<<"enter the elements in the array"<<endl;
        vector<int>A;
        for(int j=0;j<size;j++)
        {
            int temp;
            cin>>temp;
            A.push_back(temp);
        }

        mergesort(A);
        for(int j=0;j<A.size();j++)
        {
            cout<<A[j]<<" ";
        }
        cout<<endl;
    }
}/* code */