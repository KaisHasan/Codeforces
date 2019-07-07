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
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll SIZE;
bitset<2000010> isprime;
vector<ll> primes;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb(i);
        }
    }
}
vector<ll> ppp;
void fact(ll n){
    int id = 0;
    int pf = primes[id];
    while((ll)pf * (ll)pf <= n){
        if(n % (ll)pf == 0)
            ppp.pb((ll)pf);
        while(n % (ll)pf == 0){
            n /= pf;
        }
        pf = primes.at(++id);
    }
    if(n != 1){
        ppp.pb(n);
    }
}




int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    ll n;
    scanf("%I64d" , &n);
    seive(min(n , (ll)1000010));
    fact(n);
    ll res = 1;
    for(auto it : ppp){
        res *= it;
    }
    printf("%I64d" , res);

return 0;
}
