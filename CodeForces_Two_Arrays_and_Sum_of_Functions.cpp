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
const int MOD = 998244353;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int a[2*MAX] , b[2*MAX] , nb[2*MAX];
ll cnt[2*MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    for(int i = 0 ; i < n ; ++i)
        sc(b[i]);

    ll res = 0;
    ll add = n - 2;
    cnt[0] = n;
    for(int i = 1 ; i < n ; ++i , add -= 2){
        cnt[i] = cnt[i-1] + add;
    }
    vector<pair<ll ,int> > temp;
    for(int i = 0 ; i < n ; ++i){
        temp.emplace_back((ll)a[i]*cnt[i],i);
    }
    sort(all(temp));
    sort(b , b + n , greater<int>() );
    for(int i = 0 ; i < n ; ++i){
        int id = temp[i].second;
        int v = b[i];
        nb[id] = v;
    }
    for(int i = 0 ; i < n ;++i)
        b[i] = nb[i];

    for(int i = 0 ; i < n ; ++i){
        res = (res + ((((ll)a[i]*(ll)b[i])%MOD) * (cnt[i]%MOD))%MOD)%MOD;
    }

    cout<<res;

return 0;
}
