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


vpi v;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    string s;
    cin>>s;
    int tot = 0;
    for(int i = 0 ; i < n ;){
        int j = i;
        pi x = MP(0,0);
        while(j < n && s[j] == 'G'){
            ++j;
            ++x.first;
            ++tot;
        }
        while(j < n && s[j] == 'S'){
            ++j;
            ++x.second;
        }
        v.pb(x);
        i = j;
    }
    int ans = 0;
    for(auto i : v)
        ans = max(ans , i.first);
    for(int i = 0 ; i < (int)v.size() - 1 ; ++i){
        int cnt = v[i].first;
        int dis = v[i].second;
        if(dis == 1){
            ans = max(ans , min(cnt + v[i+1].first + 1 , tot));
        }
        else
            ans = max(ans , min(cnt + 1  ,tot));
    }
    ans = max(ans , min(v[(int)v.size()-1].first + 1 , tot));

    printf("%d" , ans);


return 0;
}
