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

int n;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int grid[55][55];
ll dist(ll x , ll y){
    return (x*x) + (y*y);
}
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0;
}
int enx , eny;
ll dp[55][55][2];
ll solve(int x , int y , int flg){
    if(x == enx && y == eny){
        return 0;
    }
    ll &res = dp[x][y][flg];
    if(res != -1)
        return res;
    res = inf;
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny)){
            res = min(res , solve(nx , ny , flg));
        }
    }
    for(int i = 0 ; i < n && !flg ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(valid(i , j)){
//                printf("i == %d , j == %d\n" , i + 1, j+1);
                res = min(res , solve(i , j , 1) + dist(abs(x-i),abs(y-j)));
            }
        }
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    int stx , sty;
    sc(stx);sc(sty);
    stx--;sty--;
    sc(enx);sc(eny);
    enx--;eny--;
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < n ; ++j){
            grid[i][j] = (s[j] - '0');
        }
    }
    mem(dp,-1);
    ll res = solve(stx,sty,0);
    cout<<res;

return 0;
}
