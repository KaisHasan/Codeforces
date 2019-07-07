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

int n , m;
char grid[1005][1005];
int stx , sty , enx , eny;
struct node{
    int x , y , rot , w;
    node(int _x = 0 , int _y = 0 , int _rot = 0 , int _w = 0){
        x = _x;
        y = _y;
        rot = _rot;
        w = _w;
    }
    node(const node& t){
        x = t.x;
        y = t.y;
        rot = t.rot;
        w = t.w;
    }
    friend bool operator>(node a , node b){
        return a.w > b.w;
    }
};
char d1[] = {'-','|'};
char d2[] = {'^' , '>' , 'v' , '<'};
char d3[] = {'L' , 'U' , 'R' , 'D'};

vector<char> adj[4];

void build(){
    adj[0] = {'|' , '+' , '^' , 'L' , 'D' , 'R'};
    adj[1] = {'|' , '+' , 'v' , 'U' , 'L' , 'R'};
    adj[2] = {'+' , '-' , '<' , 'R' , 'D' , 'U'};
    adj[3] = {'+' , '-' , '>' , 'L' , 'D' , 'U'};
}

char _rotate(char c , int cnt){
    if(cnt == 0)
        return c;
    if(c == '+')
        return c;
    for(int i = 0 ; i < 2 ; ++i){
        if(c == d1[i]){
            i = (i + cnt)%2;
            return d1[i];
        }
    }
    for(int i =0 ; i < 4 ; ++i){
        if(c == d2[i]){
            i = (i + cnt)%4;
            return d2[i];
        }
    }
    for(int i =0  ; i < 4 ; ++i){
        if(c == d3[i]){
            i = (i + cnt)%4;
            return d3[i];
        }
    }
}

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
bool valid(int x , int y , int nx , int ny , int k , int cnt){
    bool ret =  ((nx >= 0) && (ny >= 0) && (nx < n) && (ny < m) && grid[nx][ny] != '*');
    if(!ret)
        return 0;
    int nk = k^1;
    bool t1 = false , t2 = false;
    char c1 = _rotate(grid[x][y] , cnt);
    char c2 = _rotate(grid[nx][ny] , cnt);
    for(auto i : adj[k])
        if(c1 == i)
            t1 = true;
    for(auto i : adj[nk])
        if(c2 == i)
            t2 = true;
    return (t1 & t2);
}

int dist[1001][1001][5];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = s[j];
        }
    }
    build();
    sc(stx);sc(sty);
    sc(enx);sc(eny);
    --stx;--sty;
    --enx;--eny;
    mem(dist, inf);
    dist[stx][sty][0] = 0;
    priority_queue<node , vector<node> , greater<node> > pq;
    pq.push(node(stx , sty , 0 , 0));
    while(!pq.empty()){
        int x = pq.top().x;
        int y = pq.top().y;
        int rot = pq.top().rot;
        int w = pq.top().w;
        pq.pop();

        if(w > dist[x][y][rot])
            continue;
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(x , y , nx , ny , i , rot)){
                if(w + 1 < dist[nx][ny][rot]){
                    dist[nx][ny][rot] = w + 1;
                    pq.push(node(nx , ny , rot , w + 1));
                }
            }
        }
        for(int i = 1 ; i < 4 ; ++i){
            int nRot = (rot + i)%4;
            if(w + i < dist[x][y][nRot]){
                dist[x][y][nRot] = w + i;
                pq.push(node(x,y,nRot , w + i));
            }
        }
    }

    int mn = inf;
    for(int i = 0 ; i < 4 ; ++i){
        mn = min(mn , dist[enx][eny][i]);
    }
    if(mn == inf)
        mn = -1;
    printf("%d" , mn);



return 0;
}
