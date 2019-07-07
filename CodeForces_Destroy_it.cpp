#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const ll inf = 1e17;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
vll adj[4];
vector<pair<ll,ll> > temp;
ll dp[2*MAX][11];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < 2*MAX ; ++i)
        fill(dp[i] , dp[i] + 11 , -inf);
    dp[0][0] = 0;
    for(int i = 0 ; i < n ; ++i){
        int k;
        sc(k);
        for(int j = 1 ; j <= 3 ; ++j)
            adj[j].clear();
        while(k--){
            int c , d;
            sc(c);sc(d);
            adj[c].pb(d);
        }
        for(int j = 1 ; j <= 3 ; ++j)
            sort(all(adj[j]) , greater<ll>() );
        temp.clear();
        for(int j = 1 ; j <= 3 ; ++j){
            for(int id = 1 ; id <= (int)adj[j].size() && id * j <= 3 ; ++id){
                temp.pb(pair<ll,ll>(j , adj[j][id-1]));
            }
        }
        for(int mask = 0 ; mask < (1<<(int)temp.size()) ; ++mask){
            int cnt = 0, cost = 0;
            ll tot = 0 , mx = 0;
            for(int j = 0 ; j < (int)temp.size() ; ++j){
                if(mask & (1<<j)){
                    ++cnt;
                    mx = max(mx , temp[j].second);
                    cost += temp[j].first;
                    tot += temp[j].second;
                }
            }
            if(cost > 3)
                continue;
            for(int j = 0 ; j < 10 ; ++j){
                if(j + cnt >= 10){
                    dp[i+1][j+cnt-10] = max(dp[i+1][j+cnt - 10] , dp[i][j] + tot + mx);
                }
                else{
                    dp[i+1][j+cnt] = max(dp[i+1][j+cnt] , dp[i][j] + tot);
                }
            }
        }
    }
    ll mx = -1;
    for(int i = 0 ; i < 10 ; ++i){
        mx = max(mx , dp[n][i]);
    }
    printf("%I64d" , mx);



return 0;
}
