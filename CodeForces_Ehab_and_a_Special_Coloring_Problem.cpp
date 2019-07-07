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
bitset<200010> isprime;
int a[MAX];
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    int cnt = 0;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            ++cnt;
            a[i] = cnt;
            for(ll j = i * 2 ; j <= SIZE ; j += i){
                isprime[j] = 0;
                a[j] = cnt;
            }
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;sc(n);
    seive(n + 1);
    int cnt = 0;
    for(int i = 2 ; i <= n ; ++i){
        printf("%d " , a[i]);
    }



return 0;
}
