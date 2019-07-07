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
#define X first
#define Y second

struct node{
    int x1 , x2 , y1 , y2;
    node(int _x1 = 1 , int _y1 = 1 , int _x2 = 1 , int _y2 = 1){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
    node(const node& temp){
        x1 = temp.x1;
        y1 = temp.y1;
        x2 = temp.x2;
        y2 = temp.y2;
    }
};

node res[2];
bool in(int p , char c){
    if(c == 'x')
        return (p < res[0].x2 && p > res[0].x1);
    else
        return (p < res[0].y2 && res[0].y1);
}

bool inside(int x1 , int y1 , int x2 , int y2){
    if(in(x1 , 'x') && in(y1 , 'y'))
        return 1;
    if(in(x2 , 'x') && in(y2 , 'y'))
        return 1;
    return 0;
}


void get(int x1 , int y1 , int x2 , int y2 , int id){
    int cx1 , cy1 , cx2 , cy2;
    cx1 = x1 , cx2 = x2 , cy2 = y2;
    int sty = y1 , eny = y2;
    while(sty <= eny){
        int md = (sty+eny)>>1;
        printf("? %d %d %d %d\n" , cx1 , md , cx2 , cy2);
        fflush(stdout);
        int ans;
        sc(ans);
        if(!ans){
            eny = md - 1;
        }
        else{
            sty = md + 1;
            res[id].y1 = md;
        }
    }

    cy1 = res[id].y1 , cx2 = x2 , cy2 = y2;
    int stx = x1 , enx = x2;
    while(stx <= enx){
        int md = (stx+enx)>>1;
        printf("? %d %d %d %d\n" , md , cy1 , cx2 , cy2);
        fflush(stdout);
        int ans;
        sc(ans);
        if(!ans)
            enx = md - 1;
        else{
            stx = md + 1;
            res[id].x1 = md;
        }
    }

    cx1 = res[id].x1 , cy1 = res[id].y1 , cx2 = x2;
    sty = cy1 , eny = y2;
    while(sty <= eny){
        int md = (sty+eny)>>1;
        printf("? %d %d %d %d\n" , cx1 , cy1 , cx2 , md);
        fflush(stdout);
        int ans;
        sc(ans);
        if(!ans){
            sty = md + 1;
        }
        else{
            eny = md - 1;
            res[id].y2 = md;
        }
    }

    cx1 = res[id].x1 , cy1 = res[id].y1 , cy2 = res[id].y2;
    stx = cx1 , enx = x2;
    while(stx <= enx){
        int md = (stx + enx)>>1;
        printf("? %d %d %d %d\n" , cx1 , cy1 , md , cy2);
        fflush(stdout);
        int ans;
        sc(ans);
        if(!ans)
            stx = md + 1;
        else{
            enx = md - 1;
            res[id].x2 = md;
        }
    }
}

node a[4];

void build(int n){
    a[0] = node(1 ,1 , n , res[0].y1-1);
    a[1] = node(1 ,1 , res[0].x1 -1, n);
    a[2] = node(1 , res[0].y2 +1, n , n);
    a[3] = node(res[0].x2 +1, 1 , n , n);
}

int main(){

    int n;
    sc(n);
    get(1 , 1 , n , n , 0);
    int ans = 0;
    node RECT;
    build(n);
    int id = 0;
    while(id < 4 && !ans){
        RECT.x1 = a[id].x1;
        RECT.x2 = a[id].x2;
        RECT.y1 = a[id].y1;
        RECT.y2 = a[id].y2;
        if(RECT.x1 == 0 || RECT.y1 == 0 || RECT.x2 == 0 || RECT.y2 == 0){
            ++id;
            continue;
        }
        printf("? %d %d %d %d\n" , RECT.x1 ,RECT.y1 , RECT.x2 , RECT.y2);
        fflush(stdout);
        sc(ans);
        ++id;
    }
    get(RECT.x1 , RECT.y1 , RECT.x2 ,RECT.y2 , 1);

    printf("! %d %d %d %d %d %d %d %d\n" , res[0].x1 , res[0].y1 , res[0].x2 , res[0].y2 , res[1].x1 , res[1].y1 , res[1].x2 , res[1].y2);
    fflush(stdout);


return 0;
}
