#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);

ll const N = 100005;
ll primes[N];
bool isKp[5][N];
ll dp[5][N];
void build(){
   for(ll i =1;i<=N;i++){
       primes[i]=-1;
    }
   for(ll i =2;i<=N;i++){
       if(primes[i]==-1){
           for(ll j = i;j<=N;j+=i){
               if(primes[j]==-1){
                   primes[j]=i;
               }
           }
       }
   }  
}

ll get(ll n){
    set<ll>st;
    while(n>1){
        st.insert(primes[n]);
        n/=primes[n];
    }
    return st.size();
}

void setup(){
    for(ll k=0;k<5;k++){
        for(ll i = 2;i<N;i++){
            if((k+1)==(get(i))){
                isKp[k][i]=1;
            }else{
                isKp[k][i]=0;
            }
        }
        for(ll i =2;i<N;i++){
            dp[k][i] = isKp[k][i]+dp[k][i-1];
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin>>q;
    build();
    setup();
    while (q--){
        ll a,b,k;
        cin>>a>>b>>k;
        cout<<dp[k-1][b]-dp[k-1][a-1]<<'\n';
    }
    

    return 0;
}
