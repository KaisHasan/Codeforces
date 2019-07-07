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


vector<pi> MST[3*MAX];
int rnk[3*MAX];
int par[3*MAX];
pi lpath[3*MAX];

pi un(pi a , pi b){
    int arr[] = {a.first , a.second , b.first , b.second};
    sort(arr , arr + 4 , greater<int>());
    return MP(arr[0],arr[1]);
}

void initi(int n){
    for(int i = 1 ; i <= n ; ++i){
        par[i] = i;
        lpath[i] = MP(0, 0);
    }
    memset(rnk , 1 , sizeof(rnk));
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

void _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return;
    if(rnk[paru] < rnk[parv]){
        par[paru] = parv;
        if(lpath[paru].first)
            lpath[paru].first++;
        if(lpath[paru].second)
            lpath[paru].second = 0;
        if(lpath[paru].first + lpath[paru].second == 0)
            ++lpath[paru].first;
        lpath[parv] = un(lpath[paru] , lpath[parv]);
        return;
    }
    else if(rnk[paru] > rnk[parv])
    {
        par[parv] = paru;
        if(lpath[parv].first)
            lpath[parv].first++;
        if(lpath[parv].second)
            lpath[parv].second = 0;
        if(lpath[parv].first + lpath[parv].second == 0)
            ++lpath[parv].first;
        lpath[paru] = un(lpath[paru] , lpath[parv]);
        return;
    }
    else{
        par[parv] = paru;
        rnk[paru]++;
        if(lpath[parv].first)
            lpath[parv].first++;
        if(lpath[parv].second)
            lpath[parv].second = 0;
        if(lpath[parv].first + lpath[parv].second == 0)
            ++lpath[parv].first;
        lpath[paru] = un(lpath[paru] , lpath[parv]);
        return;
    }
}

bool _merge1(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return ;
    par[parv] = paru;
    rnk[paru]++;
}

int dis1[3*MAX];
int dis2[3*MAX];



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int n , m , q;
    sc(n);sc(m);sc(q);
    initi(n);
    while(m--){
        int u, v;
        sc(u);sc(v);
        _merge1(u,v);
    }


    while(q--){
        int choice;
        sc(choice);
        if(choice == 1){
            int x;
            sc(x);
            int parx = parent(x);
            printf("%d\n" , lpath[parx].first + lpath[parx].second);
        }
        else{
            int u , v;
            sc(u);sc(v);
            _merge(u,v);
        }
    }



return 0;
}
