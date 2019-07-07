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

int n ,m;
char grid[505][505];
int row[505] , col[505];
int vis[505][505];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i){
        string s;cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = s[j];
        }
    }
    for(int i = 0 ; i < n ; ++i){
        row[i] = 0;
        for(int j = 0 ; j < m ; ++j){
            row[i] += (grid[i][j] == '*');
        }
    }
    for(int j = 0 ; j < m ; ++j){
        col[j] = 0;
        for(int i = 0 ; i < n ; ++i){
            col[j] += (grid[i][j] == '*');
        }
    }

    int x = -1 , y = -1;
    for(int i = 0 ; i < n ; ++i){
        if(row[i] > 1){
            x = i;
            break;
        }
    }
    for(int j = 0 ; j < m ; ++j){
        if(col[j] > 1){
            y = j;
            break;
        }
    }
    if(x == -1 || y == -1){
        printf("NO");
        return 0;
    }

    vis[x][y] = 1;
    int cnt = 0;
    for(int i = x ; i < n ; ++i){
        if(grid[i][y] == '*'){
            vis[i][y] = 1;
            ++cnt;
        }
        else
            break;
    }
    if(cnt < 2){
        printf("NO");
        return 0;
    }
    cnt = 0;
    for(int i = x ; i >= 0 ; --i){
        if(grid[i][y] == '*'){
            vis[i][y] = 1;
            ++cnt;
        }
        else
            break;
    }
    if(cnt < 2){
        printf("NO");
        return 0;
    }
    cnt = 0;
    for(int j = y ; j < m ; ++j){
        if(grid[x][j] == '*'){
            vis[x][j] = 1;
            ++cnt;
        }
        else
            break;
    }
    if(cnt < 2){
        printf("NO");
        return 0;
    }
    cnt = 0;
    for(int j = y ; j >= 0 ; --j){
        if(grid[x][j] == '*'){
            vis[x][j] = 1;
            ++cnt;
        }
        else
            break;
    }
    if(cnt < 2){
        printf("NO");
        return 0;
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(vis[i][j])
                continue;
            if(grid[i][j] == '*'){
                printf("NO");
                return 0;
            }
        }

    }

    printf("YES");

return 0;
}
