class Solution {
public:
    vector<int> answer;
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int m = abs(nums[i]) - 1;
            if (nums[m] < 0) answer.push_back(m + 1);
            nums[m] = -nums[m];
        }
        return answer;
    }
};
