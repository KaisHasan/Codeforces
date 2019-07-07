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

int a[105];
int cnt[4];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        ll add = 0;
        for(int i = 0 ; i < n ; ++i){
            sc(a[i]);
        }
        for(int i = 0 ; i < n ; ++i){
            a[i] %= 3;
            if(!a[i])
                ++add;
        }
        mem(cnt,0);
        for(int i = 0 ; i < n ; ++i)
            ++cnt[a[i]];
        ll res1 = 0;
        res1 = min(cnt[2] , cnt[1]);
        cnt[2] -= res1;
        res1 += (cnt[1] - res1)/3ll;
        res1 += cnt[2]/3ll;
        cout<<res1+add<<endl;
    }


return 0;
}
