//solution:
//use set to store previous seen to reduce runtime;
class Solution {
public:
    
    int getNext(int n){
        int totalSum = 0;
        while(n > 0){
            int d = n % 10;
            n /= 10;
            totalSum += d*d;
        }
        return totalSum;
    }
    
    bool isHappy(int n) {
        set<int> seen;
        while(n != 1 && (seen.find(n) == seen.end())){
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
