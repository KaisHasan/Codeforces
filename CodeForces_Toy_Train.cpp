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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 5005;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int dist[MAX][MAX];
vi adj[MAX];
int n , m;
int st;
bool cmp(int a , int b){
    return dist[st][a] < dist[st][b];
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < m ; ++i){
        int station , candy;
        sc(station);sc(candy);
        adj[station].pb(candy);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            dist[i][j] = j - i;
            dist[j][i] = n - dist[i][j];
        }
    }

    for(int i = 1 ; i <= n ; ++i){
        st = i;
        sort(all(adj[i]) , cmp);
    }

    int num = 0;
    for(int i = 1 ; i <= n ; ++i){
        num = max(num , (int)adj[i].size());
    }
    --num;
    ll res = num * n;
    for(int source = 1 ; source <= n ; ++source){
        int mx = -1;
        for(int node = 1 ; node <= n ;++node){
            if((int)adj[node].size() < 1)
                continue;
            int sink = adj[node][0];
            if((int)adj[node].size() <= num){
                if((int)adj[node].size() == num && dist[source][sink] < dist[node][sink]){
                    mx = max(mx , min(dist[source][sink],dist[node][sink]));
                }
                continue;
            }
            mx = max(mx , dist[source][node] + dist[node][sink]);
        }
        printf("%I64d " , res + mx);
    }




return 0;
}
