#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;
        ll lower = 1000;
        ll comma = 1;

        while(lower <= n){
            ll upper = (lower * 1000) - 1;

            if(upper > n)
                upper = n;

            ll countNum = (upper - lower) + 1;
            result += (countNum * comma);

            lower *= 1000;
            comma++;
        }
        return result;
    }
};