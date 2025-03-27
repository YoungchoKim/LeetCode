struct _node{
    int num;
    int cnt;
};

struct _map{
    vector<_node> m[10000];
    void push(int num){
        int idx = num % 10000;
        for(int i = 0 ; i < m[idx].size(); i++){
            if(m[idx][i].num == num){
                m[idx][i].cnt++;
                return;
            }
        }
        m[idx].push_back({num, 1});
    }
    int getCnt(int num){
        int idx = num % 10000;
        for(int i = 0 ; i < m[idx].size(); i++){
            if(m[idx][i].num == num){
                return m[idx][i].cnt;
            }
        }
        return -1;
    }
    void pop(int num){
        int idx = num% 10000;
        for(int i = 0 ; i < m[idx].size(); i++){
            if(m[idx][i].num == num){
                m[idx][i].cnt--;
                if(m[idx][i].cnt == 0){
                    m[idx][i] = m[idx][m[idx].size() - 1];
                    m[idx].pop_back();
                }
            }
        }
    }
};

class Solution {
public:
    _map left;
    _map right;
    int minimumIndex(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            right.push(nums[nums.size() - i - 1]);
        }
        for(int i = 0 ; i < nums.size(); i++){
            left.push(nums[i]);
            right.pop(nums[i]);
            int n = left.getCnt(nums[i]);
            if(n * 2 <= (i + 1)){
                continue;
            }
            n = right.getCnt(nums[i]);
            if(n == -1) continue;
            if((n * 2) > (nums.size() - i - 1)){
                return i;
            }
        }
        return -1;
    }
};