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
const int MAX = 1e6+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vi v;
int exist[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        v.clear();
        int n;
        sc(n);
        mem(exist,0);
        for(int i = 0 ; i < n ;++i){
            int x;sc(x);
            v.pb(x);
            exist[x] = 1;
        }
        sort(all(v));
        ll res = (ll)v[0] * (ll)v[n-1];
        for(int i = 0 ; i < n ; ++i){
            if(res % (ll)v[i]){
                res = -1;
                break;
            }
        }
        if(res != -1){
            ll i = 2;
            for(; i * i < res ; ++i){
                if(res % i == 0){
                    if(!exist[i] || !exist[res/i]){
                        res = -1;
                        break;
                    }
                }

            }
            if(res != -1 && i * i == res){
                if(!exist[i]){
                    res = -1;
                }
            }
        }
        printf("%I64d\n" , res);
    }



return 0;
}
