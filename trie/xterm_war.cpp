#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
int n;

struct trie{
    trie *next[26];
    set<pair<int,int> > s;
};

trie *root = new trie();

void insert(string str,int ind){
    trie* curr = root;
    root->s.insert({ind,str.length()});
    int len=1;
    for(char ch: str){
        if(curr->next[ch-'a']==NULL)
            curr->next[ch - 'a'] = new trie();
        curr=curr->next[ch-'a'];
        curr->s.insert({ind,str.length()-len});
        len++;
    }
}

int query(int l,int r,string str){
    int mx=INT_MAX;
    trie* curr= root;
    for(auto ele: curr->s){
        if(ele.first>= l && ele.first<=r){
            mx=min(mx,(int)str.size()+ele.second);
        }
    }
    // cout<<"Mx till now : "<<mx<<ln;
    int depth=1;
    for(char ch: str){
        if(curr->next[ch-'a']==NULL) break;
        curr=curr->next[ch-'a'];
        for(auto ele: curr->s){
            if(ele.first>= l && ele.first<=r){
                mx=min(mx,(int)str.size()+ele.second-depth);
            }            
        }
        depth++;
    }
    return mx;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        insert(str,i);
    } 
    int q;
    cin>>q;
    while(q--){
        int l,r;
        string str;
        cin>>l>>r>>str;
        cout<<query(l,r,str)<<ln;
    }
}