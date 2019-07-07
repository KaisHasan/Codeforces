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

int n , m , t;
//n choose k
ll C(int n , int k){
    vi a , b;
    int mx = max(k , n - k);
    for(int i = n ; i > mx ; --i)
        a.pb(i);
    int mn = min(k , n - k);
    for(int i = 2 ; i <= mn ; ++i)
        b.pb(i);
    for(int i = 0 ; i < (int)a.size() ; ++i){
        for(int j = 0 ; j < (int)b.size() ; ++j){
            int d = __gcd(a[i] , b[j]);
            a[i] /= d;
            b[j] /= d;
        }
    }
    ll res1 = 1;
    for(auto it : a)
        res1 *= (ll)it;
    ll res2 = 1;
    for(auto it : b)
        res2 *= (ll)it;
    return res1 / res2;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);sc(t);
    ll res = 0;
    for(int i = max(1 , t - 30) ; i <= min(30 , t - 4) ; ++i){
        if(t - i > n || i > m)
            continue;
        res += (C(m , i)*C(n , t - i));
    }
    printf("%I64d" , res);



return 0;
}
