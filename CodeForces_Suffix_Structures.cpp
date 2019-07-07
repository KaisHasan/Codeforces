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

int cnt1[31];
int cnt2[31];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    string s;cin>>s;
    int n = s.size();
    string t;cin>>t;
    int m = t.size();
    for(int i = 0 ; i < n ; ++i){
        int temp = s[i] - 'a';
        cnt1[temp]++;
    }
    for(int i = 0 ; i < m ; ++i){
        int temp = t[i] - 'a';
        cnt2[temp]++;
    }

    int res = 0;
    int test = false;
    for(int i = 0 ; i < 26 ; ++i){
        if(cnt2[i] > cnt1[i])
            test = true;
        res += abs(cnt1[i] - cnt2[i]);
    }

    if(test){
        printf("need tree");
        return 0;
    }

    if(!res){
        printf("array");
        return 0;
    }
    int i = 0 , j = 0;
    while(1){
        if(j == m){
            printf("automaton");
            return 0;
        }
        if(i == n)
            break;
        if(s[i] == t[j])
            ++j;
        ++i;
    }

    printf("both");





return 0;
}
