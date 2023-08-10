//https://www.youtube.com/watch?v=awxaRgUB4Kw
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> mem(num+1);
        mem[0] = 0;
        for(int i=1;i<=num;i++){
            mem[i] = mem[i/2] + i%2; //i%2 = 1 if i is odd i%2 = 0 if i is even
        }
        return mem;
    }
};