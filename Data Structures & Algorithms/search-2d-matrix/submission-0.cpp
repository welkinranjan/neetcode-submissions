class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        //finding row number
        int low=0,high=row-1,row_no=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=matrix[mid][0];
            if(val==target)
                return 1;
            if(val>target){
                high=mid-1;
            }
            else{
                row_no=mid;
                low=mid+1;
            }
        }
        low=0,high=col-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=matrix[row_no][mid];
            if(val==target)
                return 1;
            if(val>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0;
    }
};
