#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,w;
    cin>>w>>n;
    ll wt[n],val[n];
    for(ll i =0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    ll dp[2][w+1];
    memset(dp,0,sizeof(dp));
    for(ll i =0 ;i<n;i++){
        for(ll j =0;j<=w;j++){
            if(i&1){
                if(wt[i]<=j){
                    dp[1][j] = max(val[i]+dp[0][j-wt[i]],dp[0][j]);
                }else{
                    dp[1][j] = dp[0][j];
                }
            }else{
                if(wt[i]<=j){
                    dp[0][j] = max(val[i]+dp[1][j-wt[i]],dp[1][j]);
                }else{
                    dp[0][j] = dp[1][j];
                }
            }
        }
    }
    if(n&1){
        cout<<dp[0][w];
    }else{
        cout<<dp[1][w];
    }
    return 0;
}
