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

int n , r , avg;
pi a[MAX];
bool cmp(pi a , pi b){
    return a.second < b.second;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(r);sc(avg);
    ll sum = 0;
    for(int i = 0; i < n ; ++i){
        int x , y;
        sc(x);sc(y);
        sum += x;
        a[i] = MP(x,y);
    }
    sort(a , a + n , cmp);
    int curAvg = sum / n;
    ll res = 0;
    ll need = (ll)(avg - curAvg)* n - (sum % n);
    if(need <= 0){
        printf("0");
        return 0;
    }
    for(int i = 0; i < n ; ++i){
        res += (ll)(min(need , (ll)r - a[i].first)) * (ll)a[i].second;
        need -= min(need , (ll)r - a[i].first);
    }
    printf("%I64d",res);



return 0;
}
