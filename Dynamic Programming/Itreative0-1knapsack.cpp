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

ll dp[2002][2002];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,w;
    cin>>w>>n;
    ll wt[n];
    ll val[n];
    for(ll i =0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    for(ll i =0;i<=n;i++){
        for(ll j =0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    
    for(ll i =1;i<=n;i++){
        for(ll j =1;j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w];
    return 0;
}
