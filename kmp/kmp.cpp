#include<bits/stdc++.h>
using namespace std;

#define v32 vector<int>
//pattern matching 
//finding the occurence of a pattern in a string

//Complexity : O(n)

v32 prefix_function(string s){
    int n=(int)s.length();
    v32 pi(n);
    pi[0]=0;
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

v32 kmp(string p,string t){
    string v=p;
    v.push_back('#');
    for(char ch: t){
        v.push_back(ch);
    } 
    v32 pi = prefix_function(v);
    v32 index;
    for(int i=p.size()+1;i<v.size();i++){
        if(pi[i]==p.size()) index.push_back(i-2*p.size());
    }
    return index;
}

int32_t main(){
    string p,t;
    cin>>p>>t;
    v32 ans=kmp(p,t);
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
    cout<<ans.size()<<endl;
}