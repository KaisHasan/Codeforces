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

int n , m , k;
int a[MAX];
int ID[MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);sc(k);
    for(int i =0 ; i < n; ++i){
        sc(a[i]);
        ID[a[i]] = i;
    }
    ll res = 0;
    while(m--){
        int x;
        sc(x);
        res += ((ID[x] / k) + 1);
        int i = ID[x];
        if(i == 0)
            continue;
        int j = i - 1;
        ID[x]--;
        ID[a[j]]++;
        swap(a[i] , a[j]);
    }
    printf("%I64d" ,res);


return 0;
}
