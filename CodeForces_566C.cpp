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
string a[MAX];

struct node{
    int id , cnt;
    char lst;
    node(int _id = 0 , int _cnt = 0 , char _lst = 'a'){
        id = _id;
        cnt = _cnt;
        lst = _lst;
    }
    node(const node& t){
        id = t.id;
        cnt = t.cnt;
        lst = t.lst;
    }
};

vector<node> v;
string vo = "aeoiu";

bool cmp(node a ,node b){
    if(a.cnt != b.cnt){
        return a.cnt > b.cnt;
    }
    return a.lst > b.lst;
}

vector<pi> st ,en;
vi rem;
vector<pair<pi,pi> > res;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }
    for(int i = 0 ; i < n; ++i){
        string s = a[i];
        int m = s.size();
        char lst;
        int cnt = 0;
        int id = i;
        for(int j = 0 ; j < m ; ++j){
            if(vo.find(s[j]) != -1){
                lst = s[j];
                ++cnt;
            }
        }
        v.pb(node(id , cnt , lst));
    }

    sort(all(v) , cmp);
    bool t = false;
    for(int i = 0 ; i < (int)v.size() - 1; ++i){
        int cnt1 = v[i].cnt;
        int cnt2 = v[i+1].cnt;
        if(cnt1 != cnt2){
            rem.pb(i);
            if(i == (int)v.size() - 1)
                t = true;
            continue;
        }
        if(v[i].lst != v[i+1].lst){
            rem.pb(i);
            if(i == (int)v.size() - 1)
                t = true;
            continue;
        }
        en.pb(MP(i, i + 1));
        if(i + 1 == (int)v.size() - 1)
                t = true;
        ++i;
    }
    if(!t){
        rem.pb((int)v.size() - 1);
    }
    for(int i = 0 ; i < (int)rem.size() - 1 ; i++){
        int id1 = rem[i];
        int id2 = rem[i+1];
        int cnt1 = v[id1].cnt;
        int cnt2 = v[id2].cnt;
        if(cnt1 != cnt2){
            continue;
        }
        st.pb(MP(id1,id2));
        ++i;
    }
    int mn = min(en.size() , st.size());
    for(int i = 0; i < mn ; ++i){
        pi l1 = MP(v[st[i].first].id , v[en[i].first].id);
        pi l2 = MP(v[st[i].second].id , v[en[i].second].id);
        res.pb(MP(l1,l2));
    }
    for(int i = mn ; i < (int)en.size() - 1 ; i += 2){
        pi l1 = MP(v[en[i].first].id , v[en[i+1].first].id);
        pi l2 = MP(v[en[i].second].id , v[en[i+1].second].id);
        res.pb(MP(l1,l2));
    }

    printf("%d\n" , (int)res.size());
    for(int i = 0 ; i < (int)res.size() ; ++i){
        pi l1 = res[i].first;
        pi l2 = res[i].second;
        cout<<a[l1.first]<<' '<<a[l1.second]<<endl;
        cout<<a[l2.first]<<' '<<a[l2.second]<<endl;
    }


return 0;
}
