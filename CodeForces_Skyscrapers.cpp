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
const int MAX = 1055;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
int mxRow[MAX] , mxCol[MAX];
int a[MAX][MAX];
vpi Row[MAX] , Col[MAX];
int locRow[MAX][MAX] , locCol[MAX][MAX];

int main(){

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            sc(a[i][j]);
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            Row[i].pb(MP(a[i][j] , j));
        }
        sort(all(Row[i]));
    }

    for(int j = 0 ; j < m ; ++j){
        for(int i = 0 ; i < n ; ++i){
            Col[j].pb(MP(a[i][j] , i));
        }
        sort(all(Col[j]));
    }
    for(int i = 0 ; i < n ; ++i){
        int loc = 0;
        int lst = -1;
        for(int k = 0 ; k < (int)Row[i].size() ; ++k){
            if(Row[i][k].first != lst)
                ++loc;
            int j = Row[i][k].second;
            locRow[i][j] = loc;
            lst = Row[i][k].first;
        }
        mxRow[i] = loc;
    }
    for(int j = 0 ; j < m ; ++j){
        int loc = 0;
        int lst = -1;
        for(int k = 0 ; k < (int)Col[j].size() ; ++k){
            if(Col[j][k].first != lst)
                ++loc;
            int i = Col[j][k].second;
            locCol[j][i] = loc;
            lst = Col[j][k].first;
        }
        mxCol[j] = loc;
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            int res = max(mxRow[i] , mxCol[j]);
            if(locRow[i][j] > locCol[j][i])
                res = max(res , mxCol[j] + (locRow[i][j] - locCol[j][i]));
            if(locCol[j][i] > locRow[i][j])
                res = max(res , mxRow[i] + (locCol[j][i] - locRow[i][j]));
            printf("%d " , res);
        }
        blank;
    }


return 0;
}
