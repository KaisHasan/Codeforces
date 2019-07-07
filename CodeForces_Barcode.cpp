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

int n, m , x , y;
int cs[2][1001];
int dp[1001][1001][2];
int solve(int id , int cnt , int lst){
    if(id == m){
        if(cnt >= x && cnt <= y)
            return 0;
        return inf;
    }
    int &res = dp[id][cnt][lst];
    if(res != -1)
        return res;
    res = inf;
    if(lst == 2){
        res = min(solve(id + 1 , 1 , 0) + cs[0][0] , solve(id + 1 , 1 , 1) + cs[1][0]);
    }
    else{
        if(cnt < x){
            res = min(res , solve(id + 1 , cnt +1 , lst) + cs[lst][id]);
        }
        else if(cnt < y){
            res = min(res , solve(id + 1 , cnt + 1 , lst) + cs[lst][id]);
            res = min(res , solve(id + 1 , 1 , !lst) + cs[!lst][id]);
        }
        else
            res = min(res , solve(id + 1 , 1 , !lst) + cs[!lst][id]);
    }
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);sc(x);sc(y);
    for(int i = 0; i < n ; ++i){
        string s;cin>>s;
        for(int j = 0 ; j < m ;++j){
            if(s[j] == '#'){
                cs[0][j]++;
            }
            else
                cs[1][j]++;
        }
    }
    mem(dp , -1);
    cout<<solve(0 , 0 , 2);


return 0;
}
