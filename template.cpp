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
typedef long double ld;
#define MOD 1000000007;
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
            res = res * a % m;
        }
           
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ull gcd_euclid(ull a, ull b)// Important : [ make sure function call for this function is made like this : gcd_euclid( min(a,b) , max(a,b) ) ]
{
    if (b%a==0)
    {
        return a;
    }
    else
    {
        return gcd_euclid(b%a,a);
    }
    
    
}
ull lcm(ull a,ull b)
{
    return (a*b)/(gcd_euclid(min(a,b),max(a,b)));
}
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
int main()
{
  ios_base::sync_with_stdio(false);
  
  
   return 0;
}
