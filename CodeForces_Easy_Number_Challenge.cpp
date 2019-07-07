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
const int MAX = 1e6+55;
const int inf = 1e9+77;
const int MOD = 1073741824;
const double PI = acos(-1.0);
const double eps = 1e-7;

vector<bool> isprime(MAX+1,true);
vector<int> prime;

void seive(){
     isprime[0] = isprime[1] = 0;
     for(int i = 2 ; i*i < MAX ; ++i){
        if(isprime[i]){
            prime.pb(i);
            for(int j = i * 2 ; j <= MAX ; j+=i){
                isprime[j] = 0;
            }
        }
     }
}

ll res[MAX];

ll numDiv(ll n){
    if(res[n] != -1)
        return res[n];
    int m = n;
    ll id = 0 , pf = prime[id] , ans = 1;
    while(pf * pf <= n){
        ll power = 0 ;
        while(n % pf == 0){
            n /= pf;
            power++;
        }
        ans *= (power+1);
        pf = prime[++id];
    }
    if(n != 1)
        ans *= 2;
    return res[m] = ans;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive();
    mem(res, -1);
    int a, b, c ;
    sc(a);sc(b);sc(c);
    ll res = 0;
    for(int i = 1 ; i <= a ; ++i){
        for(int j = 1 ; j <= b ; ++j){
            for(int k = 1 ; k <= c ; ++k){
                res = (res + numDiv(i * j * k))%MOD;
            }
        }
    }
    cout<<res;

return 0;
}
