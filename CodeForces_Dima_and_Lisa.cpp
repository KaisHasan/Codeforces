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
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll SIZE;
bitset<20000010> isprime;
vi primes;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb((int)i);
        }
    }
}

bool is_prime(ll n){
    if(n <= SIZE)
        return isprime[n];
    int id = 0;
    ll p = primes[0];
    while(p * p <= n){
        if(n % p == 0)
            return 0;
        p = primes[++id];
    }
    return 1;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    seive((int)1e5);
    ll n;
    cin>>n;
    if(is_prime(n)){
        printf("1\n%d" , n);
        return 0;
    }
    vi res;
    res.pb(3);
    n -= 3;
    if(is_prime(n)){
        printf("2\n");
        printf("3 %d" , n);
        return 0;
    }
    for(int i = 0 ; i < (int)primes.size() ; ++i){
        int x = n - primes[i];
        if(is_prime(x)){
            res.pb(primes[i]);
            res.pb(x);
            break;
        }
    }
    printf("3\n");
    for(int i = 0 ; i < 3 ; ++i)
        printf("%d " , res[i]);


return 0;
}
