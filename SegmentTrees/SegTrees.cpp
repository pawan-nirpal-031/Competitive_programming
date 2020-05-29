// problem link : https://cses.fi/problemset/task/1646

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>//O(log(n)) time per operation on avg a binary search tree with node having key value pairs sorted according to keys 
#include<unordered_map>// O(1) time per operation on avg  basically a hash table
#include <iterator>
#include <stack>
#include <queue>
#include <set>// a binary search tree with O(log(n)) time per opeartion with node having only value
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a);
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 1;}
#define aout(a) for(auto x : a){cout<<x;} // array output macro only
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);

const ll n = 200005;
ll a[n];
ll st[4*n];

void build(ll si,ll ss,ll se){
   if(ss==se){
      st[si]=a[ss];
      return;
   }
   ll mid = (ss + (se-ss)/2);
   build(2*si,ss,mid);
   build(2*si+1,mid+1,se);
   st[si]=(st[2*si]+st[2*si+1]);
}

ll query(ll si,ll ss,ll se,ll qs,ll qe){
   if(qs>se || qe<ss){
      return 0;
   }
   if(ss>=qs&&se<=qe){
      return st[si];
   }
   ll mid = (ss + (se-ss)/2);
   ll l = query(2*si,ss,mid,qs,qe);
   ll r = query(2*si+1,mid+1,se,qs,qe);
   return (l+r);
}


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll m,q;
   cin>>m>>q;
   for(ll i =1;i<=m;i++){
      cin>>a[i];
   }
   build(1,1,m);
   while(q--){
      ll qs,qe;
      cin>>qs>>qe;
      cout<<query(1,1,m,qs,qe)<<'\n';
   }
   return 0;
}
