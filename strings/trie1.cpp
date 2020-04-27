#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;


struct TrieNode
{
    TrieNode *character[26];
    bool Endofword;
};

TrieNode* getnode(void)
{
    TrieNode * node=new TrieNode;
    node->Endofword=false;
    for(int j=0;j<26;j++)
    {
        node->character[j]=NULL;
    }
    return node;

}

string search(TrieNode *root,string a)
{
    string ans="";
    string prevans="";
    bool prefix=false;
    TrieNode *current=root;
    for(int j=0;j<a.length();j++)
    {
        int index=a[j]-'a';
        cout<<"yoo"<<endl;
        if(current->character[index]==NULL)
        {
            cout<<"ind "<<index<<endl;
            break;
        }
        else
        {
            ans+=a[j];
            if(current->character[index]->Endofword)
            {
                cout<<"hey"<<endl;
                prevans=ans;
                prefix=true;
            }

            current=current->character[index];
        } 

    }

    if(prefix)
    return prevans;

    return "-1";
}

void insert(TrieNode *root,string a)
{
    TrieNode *current=root;
    for(int j=0;j<a.length();j++)
    {
        int index=a[j]-'a';
        if(current->character[index]==NULL)
        {
            current->character[index]=getnode();
        }

        current=current->character[index];
    }

    current->Endofword=true;
}

int main()
{
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 

        TrieNode *root=getnode();
        cout<<"enter the size of array"<<endl;
        int size;
        cin>>size;

        
        for(int j=0;j<size;j++)
        {
           string a;
           cin>>a;
           insert(root,a);
        }

        int q;
        cin>>q;
        for(int j=0;j<q;j++)
        {
            string a;
            cin>>a;
            cout<<search(root,a)<<endl;
        }
    }
}