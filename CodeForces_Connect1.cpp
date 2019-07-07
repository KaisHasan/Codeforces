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

int grid[55][55];
int n;
int vis1[55][55];
int vis2[55][55];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0;
}
vpi st , en;
void dfs1(int x , int y){
    vis1[x][y] = 1;
    st.pb(MP(x,y));
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny) && !vis1[nx][ny])
            dfs1(nx,ny);
    }
}

void dfs2(int x , int y){
    vis2[x][y] = 1;
    en.pb(MP(x,y));
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx , ny) && !vis2[nx][ny])
            dfs2(nx,ny);
    }
}
int dist(int x , int y){
    return (x*x) + (y*y);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


sc(n);
    int stx , sty;
    sc(stx);sc(sty);
    stx--;sty--;
    int enx,eny;
    sc(enx);sc(eny);
    enx--;eny--;
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < n ; ++j){
            grid[i][j] = (s[j] - '0');
        }
    }
    dfs1(stx,sty);
    dfs2(enx , eny);
    int mn = inf;
    for(auto i : st){
        for(auto j : en){
            mn = min(mn , dist(abs(i.first-j.first) , abs(i.second-j.second)));
        }
    }
    cout<<mn;

return 0;
}
