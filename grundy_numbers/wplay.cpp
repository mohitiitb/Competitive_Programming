// By Mohit Gupta
#include <bits/stdc++.h>
using namespace std;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define all(v) (v).begin(), (v).end()
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (for ints only diff for ll)
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html for other in built
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
const int LIM = 5e5+5, MOD = 998244353;
int t,n,m,k,x,y;
int d;
int r,c;
map<string,bool> mp;
const int N = (1ll << 16);
bool inD[N];
int memo[N];


bool solve(int state){
	if(memo[state]!=-1) return memo[state];
	if(state==0) return 0;

	bool res=1;
	for(int x=state;x;x=(x-1)&state){
		if(inD[x] && (!solve(state^x))) res=0;
	}
	return memo[state]=!res;
}

int32_t main()
{
	IOS;
	cin>>d;
	forn(i,d){
		string s;
		cin>>s;
		sort(all(s));
		mp[s]=1;
	}
	cin>>r>>c>>t;
	while(t--){
		string s="";
		forn(i,r){
			string t;
			cin>>t;
			s+=t;
		}
		sort(all(s));
		int n=r*c;
		for(int x=0;x<(1<<n);x++){
			string tem="";
			forn(i,n) if(x&(1<<i)) tem+=s[i];
			sort(all(tem));
			if(mp[tem]) inD[x]=1;
			else inD[x]=0;
			memo[x]=-1;
		}
		bool ans=solve((1<<n)-1);
		if(ans) cout<<"Alice"<<ln;
		else cout<<"Bob"<<ln;
	}
}
