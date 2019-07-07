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
string s , t;

int solve(int l1 , int r1 , int l2 , int r2){
    int test = true;
    for(int i = l1 , j = l2 ; i <= r1 && j <= r2 ; ++i , ++j){
        if(s[i] != t[j]){
            test = false;
            break;
        }
    }
    if(test)
        return 1;
    if((r1-l1+1) & 1)
        return 0;
    if((r2-l2+1) & 1)
        return 0;
    int md1 = (l1 + r1)>>1;
    int md2 = (l2 + r2)>>1;
    return (solve(l1 , md1 , l2 , md2) && solve(md1 + 1 , r1, md2 + 1 , r2)) || (solve(l1 , md1 , md2 + 1 , r2) && solve(md1 + 1 , r1 , l2 , md2));
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>s>>t;
    int n = s.size();

    int res = solve(0 , n - 1 , 0 , n - 1);
    if(res)
        printf("YES");
    else
        printf("NO");


return 0;
}
