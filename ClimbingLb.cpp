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
    ll n;
    cin>>n;
    pair<ll,ll>a[n];
    for (ll i = 0; i < n; i++){
        ll sc =0;
        cin>>sc;
        if(i==0){
            a[0].first = sc;
            a[0].second = 1;
        }
        else{
            a[i].first = sc;
            if(a[i-1].first==sc){
                a[i].second = a[i-1].second;
            }else{
                a[i].second = a[i-1].second+1;
            }
        }
    }
    ll m;
    cin>>m;
    
    while (m--){
        ll asc =0;
        cin>>asc;
        
    }
    
    
    return 0;
}