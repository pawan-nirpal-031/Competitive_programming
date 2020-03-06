#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
#define MOD 1000000007;
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);
string to_upper(string s){
    transform(s.begin(),s.end(),s.begin(),::toupper);
    return s;
}
string to_lower(string s){
    transform(s.begin(),s.end(),s.begin(),::tolower);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
     ll n,m;
    cin>>n>>m;
    unordered_multimap<ll,ll>ump;
    ll a[n];
    ll b[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for (ll i = 0; i < n; i++){
        ll vi=a[i];
        ll pi=b[i];
        if(ump.find(vi)==ump.end()){
            ump.insert(mp(vi,pi));
        }else{
          ll x =   ump.find(vi)->second;
          x+=pi;
          auto it = ump.find(vi);
          it->second = x;
        }
    }
    ll min = MOD;
    for(auto x : ump){
        if(x.second<min){
            min = x.second;
        }
    }
    cout<<min<<'\n';   
        
    }
    return 0;
}
