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

ll cs[MAX];
int a[MAX];
int S;
int n;
ll sum_seq(ll n){
    return ((n) * (n+1))/2;
}
ll b[MAX];

ll sum = 0;
bool check(ll d){
    for(int i = 1 ; i <= n ; ++i){
        b[i] = (ll)a[i] + (ll)i * d;
    }
    sort(b + 1, b + n + 1);
    ll temp = 0;
    for(int i = 1 ; i <= d ; ++i)
        temp += b[i];
    if(temp <= S)
    {
        sum = temp;
        return 1;
    }
    return 0;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(S);
    for(int i = 1 ; i <= n ; ++i)
        sc(a[i]);
    int st = 0 , en = n;
    int res = 0;
    while(st <= en){
        int md = (st+en)>>1;
        if(check(md)){
            res = md;
            st = md + 1;
        }
        else
            en = md - 1;
    }

    cout<<res<<' '<<sum;


return 0;
}
