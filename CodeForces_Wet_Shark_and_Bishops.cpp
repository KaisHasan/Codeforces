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
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

map<pi , int> d;
map<pi , int> cd;
//ll fact[50];
//void f(){
//    fact[0] = 1;
//    for(int i = 1 ; i < 20 ; ++i)
//        fact[i] = (ll)i * fact[i-1];
//}

ll c(ll n){
    return (n*(n-1)) / 2;
}
int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        int x , y;
        sc(x);sc(y);
        int mn = min(x  ,y);
        int mx = max(x , y);
        int dif = 1001 - mx;
        d[MP(x - mn + 1 , y - mn + 1)]++;
        //d[MP(x + dif , y + dif)]++;
        dif = 1001 - y;
        cd[MP(x - min(x - 1 , dif) , y + min(x-1,dif))]++;
    }
    ll res = 0;
    //f();
    for(auto node : d){
        res += c(node.second);
    }
    for(auto node : cd){
        res += c(node.second);
    }
    cout<<res;



return 0;
}
