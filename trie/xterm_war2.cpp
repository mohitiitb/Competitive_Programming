#include<bits/stdc++.h>
using namespace std;
int n,q,i,w,L,R,cur,mx;
string s;
struct node{
	int child[26];
	vector<pair<int,int> > P;
	node (){
		//P.clear();
		memset (child, NULL, sizeof(child));
	}
};
vector<node> v;
void insert(int numb){
	cur = 0;
	v[0].P.push_back({numb,s.size()});
	for (w = 0; w < s.size(); w++){
		int index = s[w] - 'a';
		if (v[cur].child[index] == NULL)
			v[cur].child[index] = v.size(),
			v.push_back(node());
		cur = v[cur].child[index];
		v[cur].P.push_back({numb,s.size() - w - 1});		
    }
}
void search(){
	cur = 0,mx =INT_MAX;
	for (auto j:v[cur].P)
			if (j.first >= L && j.first <= R){
				if (s.size()  + j.second < mx)
					mx = s.size() + j.second; 
			}
	for (w = 0; w < s.size(); w++){
		int index = s[w] - 'a';
		   if (v[cur].child[index] == NULL)
		   	return;
		cur = v[cur].child[index];
		for (auto j:v[cur].P){
			if (j.first >= L && j.first <= R){
				if (s.size() - w - 1 + j.second < mx)
					mx = s.size() - w - 1 + j.second; 
			}
		}	
	}
}
main(){ ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	   v.push_back(node());
	   cin >> n;
	   for (i = 1; i <= n; i++){
	   	cin >> s;
	   	insert(i);
	   }
	   cin >> q;
	   while (q--){
		 cin >> L >> R >> s;
		 search();
		 cout << mx <<'\n';
	   }
}