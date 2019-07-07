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

int n , k;
int a[2*MAX];
vpi rnk;
int taken[2*MAX];
int par[2*MAX] , bot[2*MAX];
int cnt;
int c;
int up(int x){
    if(!cnt)
        return x;
    if(par[x] == x){
        if(taken[x] == -1)
            taken[x] = c;
        return x;
    }
    if(taken[x] == -1){
        taken[x] = c;
        --cnt;
    }
    return par[x] = up(par[x]);
}

int down(int x){
    if(!cnt)
        return x;
    if(bot[x] == x){
        if(taken[x] == -1)
            taken[x] = c;
        return x;
    }
    if(taken[x] == -1){
        taken[x] = c;
        --cnt;
    }
    return bot[x] = down(bot[x]);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(k);
    for(int i = 0 ; i < n ; ++i){
        sc(a[i]);
        rnk.pb(MP(a[i] , i));
    }
    for(int i = 0 ; i < n ; ++i)
        par[i] = i + 1;
    par[n-1] = n-1;
    for(int i = 0 ; i < n ; ++i)
        bot[i] = i - 1;
    bot[0] = 0;
    sort(all(rnk) , greater<pi>() );
    int id = 0;
    c = 1;
    mem(taken , -1);
    while(1){
        int mx = -1;
        c = 1 - c;
        for(int i = id ; i < n ; ++i , ++id){
            int x = rnk[i].second;
            if(taken[x] == -1){
                mx = x;
                break;
            }
        }
        if(mx == -1)
            break;
        taken[mx] = c;
        cnt = k;
        if(mx != n - 1)
            up(mx + 1);
        cnt = k;
        if(mx != 0)
            down(mx - 1);
    }

    for(int i = 0 ;i < n ; ++i){
        printf("%d" , taken[i] + 1);
    }



return 0;
}
