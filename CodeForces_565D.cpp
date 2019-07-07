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

//seive
// O(n log log n)
ll SIZE;
bitset<3000010> isprime;
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


ll g(ll n){
    ll i;
    ll mx = 0;
    if(!n)
        return 0;
    for( i = 2 ; i * i < n ; ++i){
        if(n%i == 0){
            mx = max(mx , i);
            mx = max(mx , n/i);
        }
    }

    if(i * i == n)
        mx = max(mx , i);

return mx;
}

int a[4*MAX] , exist[30*MAX];
vi res;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive(2750132);
    int n;
    sc(n);
    for(int i =0 ; i < 2*n ; ++i){
        sc(a[i]);
        exist[a[i]]++;
    }
    sort(a , a+ 2*n , greater<int>() );
    for(int i = 0 ; i < 2 * n ; ++i){
        int v = a[i];
        if(!exist[v])
            continue;
        if(v < 200001 && !isprime[v]){
            int k = g(v);
            if(exist[k]){
                exist[k]--;
                exist[v]--;
                res.pb(v);
            }
        }
    }
    sort(a , a + 2*n);

    for(int i = 0; i < 2*n ; ++i){
        int v = a[i];
        if(!exist[v])
            continue;
        if(v < 200001 && isprime[v]){
            int p = primes[v-1];
            if(exist[p]){
                exist[p]--;
                exist[v]--;
                res.pb(v);
            }
        }
    }


    for(int i = 0 ; i < n ; ++i)
        printf("%d " , res[i]);


return 0;
}
