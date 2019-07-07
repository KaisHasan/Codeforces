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

int n;
int col[111];
int stx , sty , enx , eny;
bool dist[101][1000001];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
queue<pi> q;


int main(){
freopen("output.txt" , "w" , stdout);
freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 1 ; i <= n  ;++i){
        sc(col[i]);
        col[i]++;
    }
    sc(stx);sc(sty);sc(enx);sc(eny);
    dist[stx][sty] = 0;
    q.push(MP(stx,sty));
    bool test = false;
    int res = 0;
    while(!q.empty()){
        int s = q.size();
        if(test)
            break;
        while(s--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == enx && y == eny){
                test = true;
                break;
            }
            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 1 || nx > n)
                    continue;
                if(ny < 1 || ny > col[x])
                    continue;
                ny = min(ny , col[nx]);
                if(!dist[nx][ny]){
                    dist[nx][ny] = 1;
                    q.push(MP(nx,ny));
                }
            }
        }
        ++res;
    }
    printf("%d" , res - 1);




return 0;
}
