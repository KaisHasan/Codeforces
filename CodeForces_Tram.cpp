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
const double eps = 1e-7;

//5 4 0
//
//5 14
//
//1 -1

int s , x1 , x2;
int t1 , t2;
int p , d , igor;
double temp;
int check(double md){
//    cout<<setprecision(6)<<"md == "<<md<<endl;
    double person = fabs((double)x1 - md)*(double)t2;
    double tram;
    double dis;
    if(d + igor == 0){
        if(d == -1)
            dis = (double)p + md;
        else
            dis = (double)s - (double)p + ((double)s - md);
    }
    else{
        if(d == -1){
            if(md - (double)p > eps)
                dis = (double)p + (double)s + ((double)s - md);
            else
                dis = fabs(md - (double)p);
        }
        else{
            if((double)p - md > eps)
                dis = (double)s - (double)p + (double)s + md;
            else
                dis = fabs(md - (double)p);
        }
    }
    tram = dis *(double)t1;
//    cout<<"person == "<<person<<'\t'<<"tram == "<<tram<<endl;
    if(person - tram > eps)
        return -1;
    if(tram - person > eps)
        return 1;
//    pla;
    temp = fabs((double)x1 - md)*(double)t2 + fabs((double)x2 - md)*(double)t1;
    return 0;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(s);sc(x1);sc(x2);
    sc(t1);sc(t2);
    sc(p);sc(d);
    if(t1 >= t2){
        ll res = abs(x2 - x1) * t2;
        printf("%I64d" , res);
    }
    else{
        if(x2 < x1){
            igor = -1;
        }
        else
            igor = 1;
        double st = min(x1,x2) , en = max(x1 , x2);
        double res = abs(x2-x1)*t2;
        while(en - st > eps){
            double md = (st + en) / 2;
            int ans = check(md);
            if(ans == 1){
                if(igor == -1)
                    en = md;
                else
                    st = md;
            }
            else if(ans == -1){
                if(igor == -1)
                    st = md;
                else
                    en = md;
            }
            else{
                res = min(res , temp);
                break;
            }
        }
        cout<<setprecision(6)<<res;
    }



return 0;
}
