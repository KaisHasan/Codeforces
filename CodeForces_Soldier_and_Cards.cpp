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
int k[3];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    sc(k[1]);
    queue<int> q1;
    for(int i =0  ; i < k[1]; ++i){
        int x;sc(x);
        q1.push(x);
    }
    sc(k[2]);
    queue<int> q2;
    for(int i =0  ; i < k[2]; ++i){
        int x;sc(x);
        q2.push(x);
    }
    int dis = 0;
    while(!q1.empty() && !q2.empty() && dis < MAX){
        int p1 = q1.front();
        int p2 = q2.front();
        q1.pop();
        q2.pop();
        if(p1 > p2){
            q1.push(p2);
            q1.push(p1);
        }
        else{
            q2.push(p1);
            q2.push(p2);
        }
        ++dis;
    }
    int res = dis;
    if(dis == MAX)
        res = -1;
    printf("%d " , res);
    if(res != -1){
        if(!q1.empty())
            printf("1");
        else
            printf("2");
    }



return 0;
}
