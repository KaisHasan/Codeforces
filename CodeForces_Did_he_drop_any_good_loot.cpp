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
const int MAX = 1e4+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
struct node{
    int p , w , d;
    node(int _p = 0 , int _w = 0 , int _d = 0){
        p = _p;
        w = _w;
        d = _d;
    }
    node(const node& t){
        p = t.p;
        w = t.w;
        d = t.d;
    }
    friend bool operator<(node &a , node &b){
        if(a.d != b.d)
            return a.d > b.d;
        if(a.w != b.w)
            return a.w < b.w;
        return a.p > b.p;
    }
};

node a[MAX];
int dp[MAX][750][3];

int solve(int id , int rem , int cnt){
    if(id == n)
        return 0;
    int &res = dp[id][rem][cnt];
    if(res != -1)
        return res;
    res = 0;
    res = max(res , solve(id + 1 , rem , cnt));
    if(rem >= a[id].w){
        res = max(res , solve(id + 1 , rem - a[id].w , cnt) + a[id].p);
    }
    if(cnt < 2){
        if(rem + a[id].d >= a[id].w){
            res = max(res , solve(id + 1 , rem + a[id].d - a[id].w , cnt + 1) + a[id].p);
        }
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    int m;
    sc(m);
    for(int i = 0 ; i < n ; ++i){
        int p , w , d;
        sc(p);sc(w);sc(d);
        a[i] = node(p ,w , d);
    }
    sort(a , a + n);
//    for(int i = 0 ; i < n ; ++i)
//        printf("%d %d %d\n" , a[i].p , a[i].w , a[i].d);
    mem(dp,-1);
    int res = solve(0 , m , 0);
    printf("%d" , res);


return 0;
}
