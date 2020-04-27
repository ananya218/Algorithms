#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

struct TrieNode
{ 
    TrieNode *character[26];
    bool endofword;
    int child; 
};

TrieNode * getnode(void)
{
    TrieNode *node=new TrieNode;
    node->endofword=false;
    node->child=0;
    for(int j=0;j<26;j++)
    {
        node->character[j]=NULL;
    }
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
            current->child++;
        }

        current=current->character[index];
    }

}

int main()
{
    cout<<"enter the size of the array"<<'\n';
    int size;
    cin>>size;
    for(int j=0;j<size;j++)
    {
        
    }
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        
    }
}