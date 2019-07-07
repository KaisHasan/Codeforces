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

int SIZE;
bitset<2000> isprime;
vi primes;
void seive(int n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(int i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(int j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb(i);
        }
    }
}
vi res;
void solve(int n){
    for(int i = 0 ; i < (int)primes.size() ; ++i){
        for(int j = primes[i] ; j <= n ; j *= primes[i])
            res.pb(j);
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    seive(n);
    solve(n);
    printf("%d\n" , res.size());
    for(auto it : res)
        printf("%d " , it);

return 0;
}
