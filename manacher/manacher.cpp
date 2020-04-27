#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" "<<x<<endl;

void manacher(string s){
    string t;
    int n=s.size();
    for(int i=0;i<n-1;i++){
        t.push_back(s[i]);
        t.push_back('#');
    }
    t.push_back(s.back());
    // dbg(t);
    vector<int> d(2*n-1);
    int l=0,r=-1;
    for(int i=0;i<t.size();i++){
        int k=(i>r)?1:min(d[l+r-i],r-i+1);
        while(i-k>=0 && i+k<2*n-1 && t[i-k]==t[i+k])
            k++;
        d[i]=k--;
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
    }
    // for(int x: d) dbg(x);

    //points to note
    //an odd length palindrome starts at t[i]!='#'
    //its length is (d[i]-1) if ends are '#', otherwise its d[i]

    //even length palindrome starts at t[i]=='#'
    //its length is (d[i]-1) if ends are '#', otherwise its d[i]

    // following is for a specific problem
    // https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2470

    int len=-1;
    int end=-1;
    for(int i=0;i<t.size();i++){
        if(i-d[i]+1 == 0 && len<d[i]){
            len=d[i];
            end=0;
        }
        if(i+d[i]-1 == t.size()-1 && len<d[i]){
            len=d[i]; 
            end=1;
        }
    }
    // dbg(len);
    // dbg(end);
    string res; 
    if(end==0){
        for(int i=s.size()-1;i>=len;i--){
            res.push_back(s[i]);
        }
        for(auto ch : s) res.push_back(ch);

    }
    else if(end==1){
        for(auto ch: s) res.push_back(ch);
        int start=n-len-1;
        for(int i=start;i>=0;i--) res.push_back(s[i]);
    }
    cout<<res<<endl;
}

int32_t main(){//
    char s[100005];
    // cin>>s;
    while(scanf("%s",s)==1)
        manacher(string(s));
}