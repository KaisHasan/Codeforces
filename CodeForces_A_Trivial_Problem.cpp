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

int check(int n){
    int res = 0;
    for(int i = 5 ; i <= n ; i *= 5){
        res += (n / i);
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    int st = 5 , en = 500000;
    int res = -1;
    while(st <= en){
        int md = (st + en)>>1;
        int c = check(md);
        if(c > n){
            en = md - 1;
        }
        else if(c < n)
            st = md + 1;
        else{
            en = md - 1;
            res = md;
        }
    }
    if(res == -1){
        printf("0");
        return 0;
    }
    printf("5\n");
    printf("%d" , res);
    for(int i = res + 1 ; i % 5 != 0 ; ++i)
        printf(" %d" , i);


return 0;
}
