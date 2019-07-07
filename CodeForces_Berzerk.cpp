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
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

#define W 2
#define L 1
#define F 0

int n;
int dp[7005][2];
int cnt[7005][2];
int k[2];
vi adj[2];
int nxt(int x){
    if(x <= n)
        return x;
    x %= n;
    return x;
}




int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    int k1,k2;
    sc(k[0]);
    for(int i = 0 ; i < k[0] ; ++i){
        int x;sc(x);
        adj[0].pb(x);
    }
    sc(k[1]);
    for(int i = 0 ; i < k[1] ; ++i){
        int x;sc(x);
        adj[1].pb(x);
    }
    mem(dp,-1);

    queue<pi> q;
    // first is node
    //second is flag
    q.push(MP(1 , 0));
    q.push(MP(1 , 1));
    dp[1][0] = F;
    dp[1][1] = F;
    while(!q.empty()){
        int u = q.front().first;
        int flg = q.front().second;
        q.pop();
        for(auto i : adj[!flg]){
            int v = nxt(u + i);
            if(dp[v][!flg] != -1)
                continue;
            if(dp[u][flg] == F){
                dp[v][!flg] = W;
                q.push(MP(v , !flg));
            }
            else{
                cnt[v][!flg]++;
                if(cnt[v][!flg] == k[!flg]){
                    dp[v][!flg] = F;
                    q.push(MP(v,!flg));
                }
            }
        }
    }


    for(int i = n ; i >= 2 ; --i){
        int res = dp[i][0];
        if(res == W){
            printf("Win ");
        }
        else if(res == -1)
            printf("Loop ");
        else
            printf("Lose ");
    }
    blank;
    for(int i = n ; i >= 2 ; --i){
        int res =  dp[i][1];
        if(res == W){
            printf("Win ");
        }
        else if(res == -1)
            printf("Loop ");
        else
            printf("Lose ");
    }


return 0;
}
