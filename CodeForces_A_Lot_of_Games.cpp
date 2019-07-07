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


struct node{
    bool isword;
    int cnt;
    node* child[26];
    node(){
        isword = 0;
        memset(child , 0 , sizeof(child));
        cnt = 0;
    }
}*head;

void _insert(string &s){
    node* it = head;
    for(int i = 0 ; i < s.size() ; ++i){
        int let = s[i] - 'a';
        if(!it->child[let]){
            it->child[let] = new node();
            it->cnt++;
        }
        it = it->child[let];
    }
it->isword = 1;
}

int _query(node * it){
    if(it->cnt == 0)
        return 0;
    for(int i = 0  ; i < 26 ; ++i){
        if(it->child[i])
            if(!_query(it->child[i]))
                return 1;
    }
    return 0;
}

int _query1(node * it){
    if(it->cnt == 0)
        return 1;
    for(int i = 0  ; i < 26 ; ++i){
        if(it->child[i])
            if(!_query1(it->child[i]))
                return 1;
    }
    return 0;
}


int main(){


    int n , k;
    sc(n);sc(k);
    head = new node();
    while(n--){
        string s;
        s.clear();
        cin>>s;
        _insert(s);
    }
    int res = _query(head);
    if(res == 1){
        ++k;
        if(!_query1(head)){
            if(k & 1)
                res = 0;
        }
    }
    if(res == 1)
        printf("First");
    else
        printf("Second");


return 0;
}
