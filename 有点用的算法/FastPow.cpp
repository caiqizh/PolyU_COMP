#include <iostream>

//Binary Exponentiation
namespace FastPow{

    // compute a^b
    long long pow(long long a, long long b) {
        long long ans = 1;
        while (b>0)
        {
            if(b&1) ans = ans * a;
            a = a * a;
            b = b>>1;
        }
        return ans;
}


    // compute (a^b)%m
    long long powMod(long long a, long long b, long long m){
        a%=m;
        long long ans = 1;
        while (b>0)
        {
            if(b&1) ans = ans * a % m;
            a = a * a % m;
            b = b>>1;
        }
        return ans;
    }

}

int main(){
    std::cout<< "(123456789 ^ 123456789) \% 1e9+7 = " << FastPow::powMod(123456789,123456789,1000000007);
    return 0;
}
