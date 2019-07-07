#include<bits/stdc++.h>

using namespace std;
typedef long l;
typedef long long ll;
typedef unsigned long long ull;

int main(void){


      int n;
      cin>>n;
      int x[n];
      for(int i = 0 ; i < n ; ++i)
        cin>>x[i];
      int en = 0;
      int pay = x[0];
      for(int i = 0 ; i < n - 1 ; ++i){
        en = en + (x[i] - x[i+1]);
        if(en < 0){
            pay =  pay + (-en);
            en = 0;
        }

      }



cout<<pay;


}
