#include<bits/stdc++.h>

using namespace std;
typedef long l;
typedef long long ll;
typedef unsigned long long ull;

int main(void){


    int n;
    int r;
    cin>>n>>r;
    for(int i = 1 ; i < 1000000 ; ++i){
           if(((i*n)%10)-r == 0 || ((i*n)%10) == 0){
            cout<<i;
            break;
           }

    }
}
