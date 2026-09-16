

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base,long long exp){
        long long res =1;
        base %= MOD;
        while(exp>0){
            if(exp % 2 ==1){
                res = (res*base) % MOD;
                 
            }
            base = (base*base) % MOD;  
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n){
        return power(n,MOD-2);
    }
    void factorial(int n,vector<long long>&fact , vector<long long>& invfact){
    fact[0] = 1;
    invfact[0] = 1;
  
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[n] = modInverse(fact[n]);
    for (int i = n - 1; i >= 1; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }

    }
    long long ncr(int n,int r,vector<long long>&fact , vector<long long>& invfact){
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    }
    int numberOfSets(int n, int k) {
        int y = 10000;
        vector<long long>fact(y+1);
        vector<long long>invfact(y+1);
        factorial(y,fact,invfact);

        return ncr(n+k-1,2*k,fact,invfact);
    }
};