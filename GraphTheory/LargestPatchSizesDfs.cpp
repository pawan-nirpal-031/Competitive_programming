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


#define N 1005
#define M 1005
ll a[N][M];
bool vis[N][M];
ll gmax_st=mod;
ll gmax_size=0;
ll c_st=0;
ll c_size=0;
void dfs(ll a[][M],ll i,ll j){
   if(vis[i][j]==0){
        vis[i][j]=1;
        c_st=a[i][j];
        c_size+=1;
        if(a[i][j+1]==a[i][j]){
            dfs(a,i,j+1);
        }
        if(a[i+1][j]==a[i][j]){
            dfs(a,i+1,j);
        }
        if(a[i][j-1]==a[i][j]){
            dfs(a,i,j-1);
        }
        if(a[i-1][j]==a[i][j]){
            dfs(a,i-1,j);
        }
   }  
   
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for (ll i = 0; i <=n+1; i++){
        for(ll j =0;j<=m+1;j++){
            a[i][j]=0;
            vis[i][j]=0;
        }
    }
    for (ll i = 1; i <=n; i++){
        for(ll j =1;j<=m;j++){
            cin>>a[i][j];
        }
    }
   for(ll i =1;i<=n;i++){
       for(ll j =1;j<=m;j++){
            c_st=0;
            c_size=0;
           if(vis[i][j]==0){
               dfs(a,i,j);
               if(c_size>=gmax_size){
                   if(c_size==gmax_size && gmax_size!=0 && (c_st<gmax_st)){
                       gmax_st= c_st;
                   }
                   if(c_size>gmax_size){
                       gmax_size=c_size;
                       gmax_st = c_st;
                   }
               }
           }
       }
   }
    cout<<gmax_st<<" "<<gmax_size;
    
    
    return 0;
}
