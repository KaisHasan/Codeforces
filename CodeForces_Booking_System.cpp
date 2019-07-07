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
const int MAX = 2000;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

struct node{
    int c , p , id;
    node(int a = 0 , int b = 0 , int d = -1){
        c = a;
        p = b;
        id = d;
    }
    node(const node& temp){
        c = temp.c;
        p = temp.p;
        id = temp.id;
    }
};

int n;
node vis[MAX];
int k;
pi tables[MAX];
int used[MAX];

bool cmp(node a , node b){
    if(a.p != b.p){
        return a.p > b.p;
    }
    return a.c < b.c;
}

int bin(int x){
    int st = 0 , en = k - 1;
    int res = -1;
    while(st <= en){
        int md = (st + en)>>1;
        if(tables[md].first >= x){
            res = md;
            en = md - 1;
        }
        else
            st = md + 1;
    }
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i= 0 ; i <n ; ++i){
        int x , y;
        sc(x);sc(y);
        vis[i] = node(x , y , i + 1);
    }
    sc(k);
    for(int i = 0 ; i < k ; ++i){
        sc(tables[i].first);
        tables[i].second = i + 1;
    }
    sort(vis , vis + n ,  cmp);
    sort(tables , tables + k);
    int mxMoney = 0;
    int numTables = 0;
    vector<pi> res;
    for(int i = 0; i < n ; ++i){
        int pos = bin(vis[i].c);
        if(pos == -1)
            continue;
        while(used[pos])
            ++pos;
        if(pos == k)
            continue;
        mxMoney += vis[i].p;
        numTables++;
        used[pos] = 1;
        res.pb(MP(vis[i].id , tables[pos].second));
    }

    printf("%d %d\n" , numTables , mxMoney);
    for(auto i : res){
        printf("%d %d\n" , i.first , i.second);
    }



return 0;
}
