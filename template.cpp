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
ull Fast_Exp(ull a,ull n) // O(log(n)) time 
{
    ull x =0;
    if (n==0)
    {
       return  1;
    }
    else if (n==1)
    {
        return  a;
    }
    else
    {
        x = Fast_Exp(a,n/2);
        if (n%2==0)
        {
            return x*x;
        }
        else
        {
            return x*a*x;
        }  
    }
    
}

ull binpow(ull a,ull b)//binary exponentaion (O(log(d))) where d is no of bits in base 2 represenation of power
{
   ull res = 1;
   while (b>0)
   {
     if (b&1)
     {
       res = res*a;
     }
     a = a*a;
     b = b>>1;
   }
   return res;
}
ull mod_exp_r(ull x,ull n, ull m)//O(log(power)) time and space
{
    if (n==0)
    {
        return 1;
    }
    else if (n%2==0)
    {
        return mod_exp_r((x*x)%m,n/2,m);
    }
    else
    {
        return (x*mod_exp_r((x*x)%m,n/2,m))%m;
    }
}

ull mod_exp(ull x,ull n,ull m)//O(log(power)) time, O(1)-> space
{
    ull res = 1;
    while (n>0)
    {
        if(n%2==1)
        {
            res = (res*x)%m;
        }
        x = (x*x)%m;
        n=n/2;
    }
    return res;
}
ull gcd_euclid(ull a, ull b)// Important : [ make sure function call for this function is made like this : gcd_euclid( min(a,b) , max(a,b) ) ]
{ if(b%a==0){return a;}else{return gcd_euclid(b%a,a);} }

ll gcd = 0,x = 0,y =0;// x,y are integers such that (Ax+By = gcd(A,B)) for(A>B)
void extended_euclid(ll A,ll B)// use this function like this : extended_euclid(max(A,B),min(A,B))
{
    if(B==0)
    {
        gcd = A;
        x = 1;
        y = 0;
    }
    else
    {
        extended_euclid(B,A%B);
        ll t = x;
        x = y;
        y = t - (A/B)*y;
    }
    
}

ll mod_inv_prime_mod(ll a,ll m)//fermat's lil therom use this only when m is prime
{
    return (mod_exp(a,m-2,m));//a-1 = (a^m-2)%m
}
ll mod_inv(ll a,ll m)
{
    extended_euclid(a,m);
    return (x%m + m)%m;
}

inline ull lcm(ull a,ull b)
{ return (a*b)/(gcd_euclid(min(a,b),max(a,b))); }

bool is_Prime(ull x)
{
    bool yes = true;
    for (ull i = 2; i <= sqrt(x); i++)
    {
        if (x%i==0)
        {
            yes = false;
            break;
        }
            
    }
  if (x!=1)
  {
      return yes;
  }
  else
  {
    return !yes;
  }
  
   
    
}

ll max_subarray_sum(ll a[],ll  n)//kadane's algo
{

    ll current_max = a[0];
    ll global_max = a[0];
    for (ll i = 1; i < n; i++)
    {
        current_max = max(a[i],current_max+a[i]);
        if (current_max>global_max)
        {
            global_max = current_max;
        }
        
    }
    return global_max;
}
ull fib(ull n,vector<ull>a){
   
    if(a[n]==0){
        for (ull i = 2; i <=n; i++)
        {
            a[i] = a[i-1] + a[i-2];
        }
    }
    return a[n];
}
pair<ll,ll> count_case(string s){
    pair<ll,ll>ans;
    ans.first = 0;
    ans.second =0;
    for (char x : s)
    {
        if((int)x>=65 && (int)(x)<=90){
            ans.first+=1;
        }
        if((int)x>=97 && (int)(x)<=122){
            ans.second+=1;
        }
    }
    return ans;
}
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
   
    
    return 0;
}
