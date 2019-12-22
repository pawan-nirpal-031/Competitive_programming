#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
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
#define pub(a) push_back(a);
#define mp(a,b) make_pair(a,b);
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro only
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

ull Mod_exp(ull a, ull b, ull m)//function to compute (a power b)mod(m)
{
    a %= m;
    ull res = 1;
    while (b > 0) {
        if (b & 1){
            res = (res * a) % m;
        }
           
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ull gcd_euclid(ull a, ull b)// Important : [ make sure function call for this function is made like this : gcd_euclid( min(a,b) , max(a,b) ) ]
{ if(b%a==0){return a;}else{return gcd_euclid(b%a,a);} }

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
/*
To understand why the solution works, one needs to notice the following:

When making a new move, the gcd of the old coordinates is equal to the gcd of the new coordinates, because we know that if m is any integer, then gcd(a + m*b, b) = gcd(a, b).
In our case, gcd(a,b) = gcd(a+b,b) = gcd(a,a+b) = gcd(a-b,b) = gcd(a,a-b).
If we make several moves, then it can be seen that we can ONLY visit points whose coordinates have the same gcd.
All moves are reversible (through one or more "reversal" moves). Like this:
(a+b,b) --> (a,b), by applying the 3rd operation;
(a,a+b) --> (a,-b) --> (a,a-b) --> (a,b), by applying the 4th, 2nd and 4th operations, respectively;
(a-b,b) --> (a,b), by applying the 1st operation;
(a,a-b) --> (a,2a-b) --> (a,b-a) --> (a,b), by applying the 2nd, 4th and 2nd operations, respectively.
Every point (a, b) can be routed to point (gcd(a,b), gcd(a,b)). This is because the moves (subtractions) made by Euclid's Algorithm (subtraction method) can be simulated by using the operations presented in the problem.
If a > b, we have gcd(a,b) = gcd(a-b,b). This move can be simulated like this: (a,b) --> (a-b,b), by applying the 3rd operation.
If a < b, we have gcd(a,b) = gcd(a,b-a). This move can be simulated like this: (a,b) --> (a,a-b) --> (a,2a-b) --> (a,b-a), by applying the 4th, 2nd, and 4th operations, respectively.
If a == b, then they are the gcd.
So if two points (a,b) and (x,y) can be routed to the same gcd point, then they are connected.

All of the above indicates that there is a route between (a,b) and (x,y) if-and-only-if gcd(a,b) == gcd(x,y).
*/

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ull a,b,x,y;
        cin>>a>>b>>x>>y;
        if (gcd_euclid(min(a,b),max(a,b))==gcd_euclid(min(x,y),max(x,y)))
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<'\n';
        }
        
        
        
    }
    
   return 0;
}