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

vi a , b;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    int s1 , e1;
    sc(s1);sc(e1);
    --s1;--e1;
    int s2 , e2;
    sc(s2);sc(e2);
    --s2;--e2;
    for(int i = s1 ; i != e1 ; i = (i+1)%(n))
        a.pb(i);
    a.pb(e1);
    for(int i = s2 ; i != e2 ;){
        b.pb(i);
        i--;
        if(i < 0)
            i = n-1;
    }
    b.pb(e2);
    int mn = (a.size() , b.size());
    for(int i = 0 ; i < mn ; ++i){
        if(a[i] == b[i]){
            printf("YES");
            return 0;
        }
    }

    printf("NO");

return 0;
}
