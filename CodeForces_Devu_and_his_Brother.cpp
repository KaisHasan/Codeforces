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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
ll a[MAX], b[MAX];
ll mn;
ll f(ll x){
    ll resa = 0;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] >= x)
            continue;
        resa += x - a[i];
    }
    ll resb = 0;
    for(int i = 0 ; i < m ; ++i){
        if(b[i] <= x)
            continue;
        resb += b[i] - x;
    }

    return resa + resb;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i)
        cin>>a[i];
    for(int i = 0 ; i < m ; ++i)
        cin>>b[i];
    ll mna = inf;
    for(int i = 0 ; i < n ; ++i)
        mna = min(mna , a[i]);
    ll st = 0 , en = inf;
    mn = (ll)1e18;
    while (en - st > 1){
        int mid = (en + st)>>1;
        if (f(mid) < f(mid + 1))
             en = mid;
        else
             st = mid;
    }
    cout<<f(st + 1);


return 0;
}
