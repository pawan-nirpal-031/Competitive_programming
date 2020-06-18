#include <iostream>
#include <cmath>
#include <cstring>
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

ll dp[2002][2002];
ll knpsck(vector<ll>&wt,vector<ll>&val,ll w,ll n){
    if(w==0 || n==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        return dp[n][w] = max((val[n-1]+knpsck(wt,val,w-wt[n-1],n-1)),(knpsck(wt,val,w,n-1)));
    }
    return dp[n][w] = knpsck(wt,val,w,n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,w;
    cin>>w>>n;
    vector<ll>wt;
    vector<ll>val;
    memset(dp,-1,sizeof(dp));
    for(ll i =0;i<n;i++){
        ll w,v;
        cin>>w>>v;
        wt.pub(w);
        val.pub(v);
    }
    knpsck(wt,val,w,n);
    cout<<dp[n][w];
    return 0;
}
