class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int middle = 0;
        bool gotTarget = false;
        while(left <= right)
        {
            middle = (left + right) / 2;
            if(nums[middle] < target)
                left = middle + 1;
            else if(nums[middle] > target)
                right = middle - 1;
            else
            {
                gotTarget = true;
                break;
            }
        }
        
        vector<int> ret;
        if(!gotTarget)
        {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int pre = middle, post = middle;
        int size = nums.size();
        while(pre >= 0 && nums[pre] == target)
            pre--;
        while(post < size && nums[post] == target)
            post++;
        ret.push_back(pre+1);
        ret.push_back(post-1);
        return ret;
    }
};