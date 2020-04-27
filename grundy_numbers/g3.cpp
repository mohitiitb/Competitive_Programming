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
 
 
int32_t main()
{
	IOS;
	cin>>t;
	while(t--){
		cin>>n;
		v32 pos(n+1,0);
		forsn(i,1,n+1) cin>>pos[i];
		int res=0;
		v32 diff;
		for(int i=n;i>0;i-=2){
			res^=(pos[i]-pos[i-1]-1);
			diff.pb(pos[i]-pos[i-1]-1);
		}
		if(res==0) cout<<"Johnny wins"<<ln;
		else{
			cout<<"Mary wins"<<ln;
			int a=diff.size()-1;
			while(true){
				int d=res^diff[a];
				int b=n-2*a;
				if(d<=diff[a]){
					//make diff[a]=d by decreasing move the second element
					cout<<"Move "<<pos[b]<<" to "<<pos[b]-(diff[a]-d)<<ln;
					break;
				}
				else if(d-diff[a]<=pos[b-1]-pos[b-2]-1){
					//increase diff[a] : move the first element
					cout<<"Move "<<pos[b-1]<<" to "<<pos[b-1]-(d-diff[a])<<ln;
					break;
				}
				a--;
			}
		}
	}
}
