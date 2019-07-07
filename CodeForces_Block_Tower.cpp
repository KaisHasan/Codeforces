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

struct node{
    char c;
    int x ,  y;
    node(char _c = 'B' , int _x = 0 , int _y = 0){
        c = _c;
        x = _x;
        y = _y;
    }
    node(const node& t){
        c = t.c;
        x = t.x;
        y = t.y;
    }
};

int n , m;
vector<node> res;
char grid[505][505];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}
int dist[505][505];
vpi lvl[MAX];

void BFS(int stx , int sty){
    dist[stx][sty] = 0;
    queue<pi> q;
    q.push((MP(stx, sty)));
    int depth = 0;
    while(!q.empty()){
        int cnt = 0;
        lvl[depth].clear();
        while(!q.empty()){
            lvl[depth].pb(q.front());
            q.pop();
            ++cnt;
        }
        for(int i = 0 ; i < cnt ; ++i){
            int x = lvl[depth][i].first;
            int y = lvl[depth][i].second;
            res.pb(node('B' , x + 1, y+1));
            for(int k = 0 ; k < 4 ; ++k){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(valid(nx , ny) && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(MP(nx,ny));
                }
            }

        }
        ++depth;
    }
//    printf("depth == %d\n" , depth);
    for(int i = depth - 1; i > 0 ; --i){
        int cnt = lvl[i].size();
//        printf("i == %d , cnt == %d\n" , i , cnt);
        for(int j = 0 ; j < cnt; ++j){
            int x = lvl[i][j].first;
            int y = lvl[i][j].second;
            res.pb(node('D' , x + 1 ,y + 1));
            res.pb(node('R' , x + 1 ,y + 1));
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i){
        string s;cin>>s;
        for(int j = 0 ; j < m ; ++j)
            grid[i][j] = s[j];
    }
    mem(dist , -1);
    for(int i = 0 ;i < n ;++i){
        for(int j = 0 ; j < m ; ++j){
            if(grid[i][j] == '#')
                continue;
            if(dist[i][j] != -1)
                continue;
            BFS(i , j);
        }
    }

    int k = res.size();
    printf("%d\n" , k);
    for(auto it : res){
        printf("%c %d %d\n" , it.c , it.x, it.y);
    }


return 0;
}
