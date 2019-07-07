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

int n , k;
int a[MAX] , lst[MAX] , num[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(k);
    for(int i = 0 ; i < n ; ++i){
        sc(a[i]);
    }
    priority_queue<pair<double , int> , vector<pair<double,int> > , greater<pair<double,int> > > pq;
    for(int i = 1 ; i <= min(k,n) ; ++i){
        lst[i] = a[i-1];
        printf("%d " , i);
        num[i] = 1;
        pq.push(MP(lst[i] , i));
    }

    for(int i = k ; i < n ; ++i){
        double avg = ((double)lst[pq.top().second] + (double)a[i])/2.0;
        int id = pq.top().second;
        num[id]++;
        lst[id] = a[i];
        printf("%d " , id);
        pq.pop();
        pq.push(MP((double)num[id]*avg , id));
    }



return 0;
}
