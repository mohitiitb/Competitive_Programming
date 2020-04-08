#include<bits/stdc++.h>
using namespace std;
#define v32 vector<int>
//https://cp-algorithms.com/string/prefix-function.html

//given an array a
//for each i : pi[i]=max_{k=0..i} (k: s[0,..,k-1]=s[i-(k-1),...,i])
//Complexity : O(n)
//using in pattern matching 

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

int32_t main(){
    string p,t;
    cin>>p>>t;
    string v=p;
    v.push_back('#');
    for(char ch: t){
        v.push_back(ch);
    } 
    v32 pi = prefix_function(v);
    int ans=0;
    for(int i=p.size()+1;i<v.size();i++){
        if(pi[i]==p.size()) ans++;
    }
    cout<<ans<<endl;
}