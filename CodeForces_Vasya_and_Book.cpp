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


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    int n , d , x, y;
    sc(n);sc(d);sc(x);sc(y);
    if(d > n){
        printf("-1\n");
        continue;
    }
    if(abs(d-x) % y == 0){
        printf("%d\n" , abs(d-x)/y);
    }
    else{
        int test = 0;
        int ans1 = (d / y) + ((d%y)?1:0);
        if(abs(1-x) % y == 0){
            ans1 += (x-1)/y;
            test = 1;
        }
        int ans2 = ((n-d)/y) +(((n-d)%y)?1:0);
        if(abs(n-x) % y == 0){
            ans2 += (n-x)/y;
            test += 2;
        }
        if(!test){
            printf("-1\n");
        }
        else if(test == 1){
            printf("%d\n" , ans1);
        }
        else if(test == 2){
            printf("%d\n" , ans2);
        }
        else
            printf("%d\n" , min(ans1 , ans2));

    }
}

return 0;
}
