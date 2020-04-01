// 448. Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> v;
    set<int> s;
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        for(int i=1; i<=nums.size(); i++) {
            if(s.find(i) != s.end()) continue;
            else v.push_back(i);
        }
        return v;
    }
};