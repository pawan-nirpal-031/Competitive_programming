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
#define MOD 1000000007;
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);
ll nofz(ll n){
    ll c =0;
    while (n)
    {
        n = n&(n-1);
        c+=1;
    }
    return c;
}
class node{
  public:
  pair<ll,ll>nd;
  node*r;
  node *l;
  node(ll x,ll y){
    nd.first = x;
    nd.second = y;
    r = l = NULL;
  }

};
class tree{
  node *root;
  public:
  tree(){
    root = NULL;
  }
  void create(ll x,ll y){
    if(root==NULL){
      node *nn = new node(x,y);
      root = nn;
    }
    else{
      node *t = root;
      node *par = root;
      while(t!=NULL){
        par = t;
        if(x>t->nd.first){
          t = t->l;
        }else{
          t = t->r;
        }
      }
      if(x>par->nd.first){
        node*nn = new node(x,y);
        par->l = nn;
      }else{
        node*nn = new node(x,y);
        par->r = nn;
      }
    }
  }
  ll find(ll x){
    node*t = root;
    while(t!=NULL || t->nd.first!=x){
      if(x<t->nd.first){
        t = t->l;
      }else{
        t = t->r;
      }
    }
    if(t!=NULL){
      return t->nd.second;
    }
    return -1;
  }

};
int main(){
   ll n;
   cin>>n;
   for (ll i = 0; i < n; i++)
   {
     
   }
   
   
   
  
  
  
 return 0;
}
