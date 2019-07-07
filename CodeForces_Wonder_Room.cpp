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
const ll inf = 1e18+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll n, a , b;
ll m;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>n>>a>>b;
    m = 6 * n;
    if(a * b >= m){
        cout<<a*b<<endl;
        cout<<a<<' '<<b;
        return 0;
    }
    ll mn = inf;
    ll ansx = -1 , ansy = -1;
    for(ll i = a ; i < MAX ; ++i){
        ll x = i;
        ll y = m / i + ((m%i)? 1 :0);
        if(y < b)
            continue;
        if(mn > x * y){
            mn = x * y;
            ansx = x;
            ansy = y;
        }
    }
    for(ll i = b ; i < MAX ; ++i){
        ll x = m / i + ((m%i)?1:0);
        ll y = i;
        if(x < a)
            continue;
        if(mn > x * y){
            mn = x * y;
            ansx = x;
            ansy = y;
        }
    }
    cout<<ansx * ansy<<endl;
    cout<<ansx << ' '<<ansy;
return 0;
}
