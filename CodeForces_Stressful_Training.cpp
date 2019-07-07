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
const ll inf = 1e16+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , k;
ll a[2*MAX] , b[2*MAX];
int cnt[2*MAX];
int check(ll x){
    mem(cnt , 0);
    int rem = k;
    for(int i = 0 ; i < n ; ++i){
        ll lst = 0;
        ll charge = a[i];
        while(1){
            ll t = charge / b[i];
            if(rem < 0){
                return 0;
            }
            if(lst + t >= k - 1)
                break;
            charge %= b[i];
            charge += x;
            lst += t;
            cnt[lst]++;
            rem--;
        }
    }

    ll c = 0;
    for(int i = 0 ; i < k ; ++i){
        if(!cnt[i])
            ++c;
        else
            c -= (cnt[i]-1);
        if(c < 0)
            return 0;
    }
    if(c < 0)
        return 0;
    return 1;
}


int main(){

    sc(n);sc(k);
    for(int i = 0 ; i < n; ++i){
        scanf("%I64d" , &a[i]);
    }
    for(int i = 0 ; i < n; ++i){
        scanf("%I64d" , &b[i]);
    }
    ll st = 0 , en = inf;
    ll res = -1;
    while(st <= en){
        ll md = (st+en)>>1ll;
        if(check(md)){
            en = md - 1;
            res = md;
        }
        else{
            st = md + 1;
        }
    }
    printf("%I64d" , res);

return 0;
}
