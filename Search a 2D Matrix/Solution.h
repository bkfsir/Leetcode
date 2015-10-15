class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(0 == row)
            return false;
        int rank = matrix[0].size();
        if(0 == rank)
            return false;
        
        int left = 0, right = row - 1;
        int middle = 0;
        while(left <= right)
        {
            middle = (left + right) / 2;
            if(matrix[middle][0] < target)
                left = middle + 1;
            else if(matrix[middle][0] > target)
                right = middle - 1;
            else
                return true;
        }
        
        if(0 > right)
            return false;
        int tarRow = right;
        left = 0;
        right = rank - 1;
        while(left <= right)
        {
            middle = (left + right) / 2;
            if(matrix[tarRow][middle] < target)
                left = middle + 1;
            else if(matrix[tarRow][middle] > target)
                right = middle - 1;
            else
                return true;
        }
        if(0 > right)
            return false;
            
        if(matrix[tarRow][right] == target)
            return true;
        else
            return false;
    }
};