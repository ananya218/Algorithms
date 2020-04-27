#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

struct TrieNode 
{ 
    struct TrieNode *children[26]; 
    bool isEndOfWord; 
    int count=0;
};


TrieNode* getnode(void)
{
    TrieNode *node=new TrieNode;
    node->isEndOfWord=false;
    for(int j=0;j<26;j++)
    {
        node->children[j]=NULL;
    }

    return node;
}


void insert(TrieNode *root,string a)
{
    TrieNode *current=root;
    for(int j=0;j<a.length();j++)
    {
        int index=a[j]-'a';
        if(current->children[index]==NULL){
        current->children[index]=getnode();
        current->children[index]->count++;
        }
        else
        {
            current->children[index]->count++;
        }
        

        current=current->children[index];
    }

    current->isEndOfWord=true;
}


int search(TrieNode *root,string a)
{
    TrieNode *current=root;

    for(int j=0;j<a.length();j++)
    {
        int index=a[j]-'a';

        if(current->children[index]==NULL)
        return 0;

        current=current->children[index];

    }
    return current->count;
}


int main()
{
    lli t;
    cin>>t;
    TrieNode *root=getnode();
    for(lli i=0;i<t;i++)
    { 
        string a;
        cin>>a;
        insert(root,a);
    }

    int q;
    cin>>q;

    for(lli i=0;i<t;i++)
    { 
        string a;
        cin>>a;
        cout<<search(root,a)<<endl;
    }



}