#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> indx;
        for (size_t i = 0; i < nums.size(); i++)
        {
            indx[i] = i;
        }

        for (int min, i = 0; i < nums.size() - 1; i++)
        {
            min = i;
            for (size_t j = i; j < nums.size(); j++)
            {
                if (nums[i] > nums[min])
                {
                    min = i;
                }
            }
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;

            temp = indx[min];
            indx[min] = indx[i];
            indx[i] = temp;
        }

        for (size_t i = 0; i < nums.size()-1; i++)
        {

            for (size_t j = 0; j < nums.size(); j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    // cout<< "[" << indx[i] << "," << indx[j] << "]" ;
                    vector<int> x ={indx[i], indx[j]};
                    return x;
                }
                
                
            }
        }
        return nums;
    }
};