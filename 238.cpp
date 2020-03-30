class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer = vector(nums.size(), 1);
        for(int i=1; i<nums.size(); i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int tmp = 1;
        for(int i=0; i<nums.size(); i++) {
            answer[nums.size() - 1 - i] =  tmp * answer[nums.size() - 1 - i];
            tmp *= nums[nums.size() - 1 - i];
        }
        return answer;
    }
};
