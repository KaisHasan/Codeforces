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
const int inf = 1e9;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int people[2*MAX] , saves[2*MAX];
int n , m ,k, t;

int binL(int x){
    int st = 0 , en = n - 1;
    int res = -1;
    while(st <= en){
        int md = (st+en)>>1;
        if(people[md] >= x){
            res = md;
            en = md - 1;
        }
        else
            st = md + 1;
    }
    return res;
}

int binR(int x , int temp){
    int st = 0 , en = n - 1;
    int res = temp;
    while(st <= en){
        int md = (st+en)>>1;
        if(people[md] <= x){
            res = md;
            st = md + 1;
        }
        else
            en = md - 1;
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(n);sc(m);sc(k);sc(t);
    for(int i  =0 ; i < n ; ++i)
        sc(people[i]);
    for(int i = 0 ; i < m ; ++i)
        sc(saves[i]);
    sort(people , people + n);
    sort(saves , saves + m);
    int id = 0;
    int ans = 0;
    for(int i = 0 ; i < m ; ++i){
        int l = binL(saves[i] - t);
        if(l == -1)
            break;
        l = max(l , id);
        if(id == n)
            break;
        if(abs(people[l] - saves[i]) > t)
            continue;
        int r = binR(saves[i] + t , l);
        int c = k;
        int j;
        for(j = l ; j <= r && c; ++j , --c){
            ans++;
        }
        id = j;
    }
    printf("%d" , ans);


return 0;
}
