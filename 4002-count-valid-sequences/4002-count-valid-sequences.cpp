class Solution {
public:
    const int MOD =1e9+7;
    vector<long long>fact;
    vector<long long>invfact;
    long long power(long long base,long long exp){
        long long res =1;
        while(exp>0){
            if(exp%2==1){
                res = (res*base) % MOD;
            }
            exp /= 2;
            base = (base*base) % MOD;
        }
        return res;
    }
    void factorial(int n){
        fact.resize(n+1);
        invfact.resize(n+1);
        fact[0] =1;
        for(int i=1;i<=n;i++){
            fact[i] = (fact[i-1] * i)%MOD;
        }
        invfact[n] = power(fact[n],MOD-2);
        for(int i=n;i>=1;i--){
            invfact[i-1] = (invfact[i]*i)%MOD;
        }
    }

    

    long long ncr(int n,int r){
        if(r<0 || r>n){
            return 0;
        }
        long long ans = fact[n];
        ans = (ans*invfact[r]) % MOD;
        ans = (ans*invfact[n-r]) % MOD;

        return ans;
    }
    int countValidSequences(int n, int k) {
        factorial(n);

        long long totalways = ncr(n-1,k-1);
        if((n-k)%2 != 0){
            return totalways;
        }
        int remaining = (n-k) / 2;
        long long oddway = ncr(remaining+k-1,k-1);
        long long ans =  (totalways - oddway + MOD) % MOD;
        if(ans<0){
            ans+= MOD;
        }
        return ans;
    }
};