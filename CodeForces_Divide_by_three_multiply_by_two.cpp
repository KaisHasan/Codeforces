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
#define scl(a) scanf("%I64d",&a)
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

int n;
map<ll , ll> son , par;
ll a[200];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        scl(a[i]);
    for(int i = 0 ; i < n ; ++i){
        ll v = a[i];
        par[v] = v;
    }
    for(int i = 0 ; i < n ; ++i){
        ll v = a[i];
        if(par.find(v*2ll) != par.end()){
            par[v*2ll] = v;
            son[v] = v * 2ll;
        }
        if(v % 3ll)
            continue;
        if(par.find(v / 3ll) == par.end())
            continue;
        par[v/3ll] = v;
        son[v] = v / 3ll;
    }
    ll st = -1;
    for(int i =0 ; i < n ; ++i){
        ll v = a[i];
        if(par[v] == v){
            st = v;
            break;
        }
    }
    while(1){
        printf("%I64d " , st);
        if(son.find(st) == son.end())
            break;
        st = son[st];
    }



return 0;
}
