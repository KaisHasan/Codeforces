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

map<char ,int> cnt;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int turns;
    sc(turns);
    string s;
    cin>>s;
    int n = s.size();
    int mx = 0;
    for(int i = 0 ; i < n ; ++i){
        cnt[s[i]]++;
        mx = max(mx , cnt[s[i]]);
    }
    int res1 = min(mx + turns , n);
    if(mx == n && turns == 1)
        res1--;
    /////
    cin>>s;
    n = s.size();
    cnt.clear();
    mx = 0;
    for(int i = 0 ; i < n ; ++i){
        cnt[s[i]]++;
        mx = max(mx , cnt[s[i]]);
    }
    int res2 = min(mx + turns , n);
    if(mx == n && turns == 1)
        res2--;
    /////
    cin>>s;
    n = s.size();
    cnt.clear();
    mx = 0;
    for(int i = 0 ; i < n ; ++i){
        cnt[s[i]]++;
        mx = max(mx , cnt[s[i]]);
    }
    int res3 = min(mx + turns , n);
    if(mx == n && turns == 1)
        res3--;
    if(res1 > res2 && res1 > res3){
        printf("Kuro");
    }
    else if(res2 > res1 && res2 > res3)
        printf("Shiro");
    else if(res3 > res1 && res3 > res2)
        printf("Katie");
    else
        printf("Draw");


return 0;
}
