class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        unsigned int bitmask = 1;
        while(bitmask < num){
            if(!(bitmask & num)){
                res += bitmask;
            }
            bitmask <<= 1;
        }
        return res;
    }
};