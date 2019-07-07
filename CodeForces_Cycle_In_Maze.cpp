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
const int MAX = 1005;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n,m,k;
int grid[MAX][MAX];
int dx[] = {1 , 0 , 0 , -1};
int dy[] = {0 , -1 , 1 , 0};
bool valid(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '*';
}


map<pi , char> trans;
string res;
bool test;
int stx , sty;
int dis[MAX][MAX];

void dfs(int x , int y , int depth){
    if(x == stx && y == sty && depth == k){
        test = true;
        return;
    }
    if(test)
        return;
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nDis = depth + 1;
        if(nDis + dis[nx][ny] <= k && valid(nx , ny)){
            dfs(nx , ny , nDis);
            if(test)
                res = trans[MP(dx[i],dy[i])] + res;
        }
        if(test)
            break;
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(n);sc(m);sc(k);
    trans[MP(1,0)] = 'D';
    trans[MP(0,-1)] = 'L';
    trans[MP(0,1)] = 'R';
    trans[MP(-1,0)] = 'U';
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = s[j];
            if(s[j] == 'X'){
                stx = i;
                sty = j;
            }
        }
    }
    if(k & 1){
        printf("IMPOSSIBLE");
        return 0;
    }
    mem(dis,-1);
    queue<pi> q;
    q.push(MP(stx,sty));
    dis[stx][sty] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dis[nx][ny] == -1 && valid(nx , ny)){
                dis[nx][ny] = dis[x][y] + 1;
                q.push(MP(nx,ny));
            }
        }
    }
    test = false;
    res = "";
    dfs(stx , sty , 0);
    if(test)
        cout<<res;
    else
        printf("IMPOSSIBLE");



return 0;
}
