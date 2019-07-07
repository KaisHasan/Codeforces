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


int n , p;
int cnt[3];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(p);
    cnt[2] = n;
    ll id = 0;
    int tot = 2 * p;
    cnt[1] += cnt[2] - (cnt[2]%tot);
    id += cnt[2] / tot;
    if(cnt[2]%tot){
        int mn = min(cnt[1] , tot - cnt[2] % tot);
        cnt[1] -= mn;
        cnt[1] += cnt[2] % tot;
        id++;
    }
    id += cnt[1] / tot + (cnt[1]%tot > 0);
    ll ans = id * 5ll;
    printf("%I64d" , ans);



return 0;
}
