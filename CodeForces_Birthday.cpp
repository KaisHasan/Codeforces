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

int a[MAX];
int res[MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        sc(a[i]);
    }
    sort(a , a + n);
    int l = 0 , r = n - 1;
    int i = 0;
    int j = 1;
    while(l <= r){
        if(i < n)
            res[l] = a[i];
        if(j < n)
            res[r] = a[j];
        i += 2;
        j += 2;
        ++l;
        --r;
    }

    for(int i = 0 ; i < n ; ++i)
        cout<<res[i]<< ' ';



return 0;
}
