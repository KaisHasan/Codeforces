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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-4;

struct point{
    int x , y;
    point(){x = y = 0;}
    point(int _x , int _y){
        x = _x;
        y = _y;
    }
    point(const point& p){
        x = p.x;
        y = p.y;
    }
};

double dist(point a , point b){
    return hypot(a.x - b.x , a.y - b.y);
}

double triangleArea(point p0 , point p1 , point p2){
    double a = dist(p0 , p1);
    double b = dist(p0 , p2);
    double c = dist(p1 , p2);
    double s = (a+b+c)/2;
    return sqrt((s-a)*(s-b)*(s-c)*s);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n , dd;
    sc(n);sc(dd);
    point a(0 , dd) , b(n - dd , n) , c(n , n - dd) , d(dd , 0);
    double rec_area = dist(a , b) * dist(a , d);
    int m;
    sc(m);
    while(m--){
        int x , y;sc(x);sc(y);
        point p(x , y);
        double area = 0;
        area += triangleArea(p , a , b);
        area += triangleArea(p , b , c);
        area += triangleArea(p , c , d);
        area += triangleArea(p , d , a);
        if(area - rec_area > eps)
            printf("NO");
        else
            printf("YES");
        blank;
    }



return 0;
}
