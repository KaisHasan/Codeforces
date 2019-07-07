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

int n;
int f[2*MAX];



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int a , b;
    sc(n);sc(b);sc(a);
    for(int i = 0 ; i < n ; ++i){
        sc(f[i]);
    }
    int bat = b;
    int acc = a;
    int i = 0;
    for(; i < n; ++i){
        if(!f[i]){
            if(acc)
                --acc;
            else
                --bat;
        }
        else{
            if(bat > 0 && acc < a){
                bat--;++acc;
            }
            else
                acc--;
        }
        if(acc < 0 || bat < 0)
            break;
    }
    int res = i;
    printf("%d" , res);


return 0;
}
