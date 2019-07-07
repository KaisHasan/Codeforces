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


int n , m;
char grid1[505][505] , grid2[505][505];
int dx[] = {1 , 0 , -1 , 0};
int dy[] = {0 , 1 , 0 , -1};
bool valid1(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid1[x][y] == '.';
}
bool valid2(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid2[x][y] == '.';
}
int dis[505][505];
int BFS(pi st , pi en,int id){
    mem(dis , -1);
    dis[st.first][st.second] = 0;
    queue<pi> q;
    q.push(st);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x == en.first && y == en.second)
            break;
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            bool test;
            if(id == 1){
                test = valid1(nx,ny);
            }
            else if(id == 2)
                test = valid2(nx,ny);
            else
                test = valid1(nx,ny) && valid2(nx,ny);
            if(test && dis[nx][ny] == -1){
                dis[nx][ny] = dis[x][y] + 1;
                q.push(MP(nx,ny));
            }
        }
    }
    return dis[n-1][m-1];
}

int vis[505][505];
void dfs(int x , int y , int rem){
    if(x == n - 1 && y == m - 1){
        printf("YES");
        exit(0);
    }
    vis[x][y] = 1;
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid1(nx,ny) && valid2(nx,ny) && !vis[nx][ny] && rem > 0 && dis[nx][ny] <= rem){
            dfs(nx , ny , rem - 1);
        }
    }
    vis[x][y] = 0;
}


int main(){

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid1[i][j] = s[j];
        }
    }

    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid2[i][j] = s[j];
        }
    }
    int shortest1 = BFS(MP(0,0) , MP(n-1,m-1) , 1);
    int shortest2 = BFS(MP(0,0) , MP(n-1,m-1) , 2);
    if(shortest1 == -1 || shortest2 == -1 || shortest1 != shortest2){
        printf("NO");
        return 0;
    }
    mem(vis , 0);
    BFS(MP(n-1,m-1),MP(0,0) , 3);
    dfs(0 , 0 , shortest1);
    printf("NO");

return 0;
}
