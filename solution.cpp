#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>

#define MINUS_INT_MAX INT_MAX * (-1)

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if(nums.size() <= 0){
            return MINUS_INT_MAX;
        }

        for(int i = 0 ; i < nums.size(); i++) {
            printf("%d\t", nums[i]);
        }
        printf("\n");

        // initialize the variable
        std::vector<int> max_array(nums.size(), 0); // if the value is the maximum value, push into max array
        std::vector<int> min_array(nums.size(), 0); // if the value is the minimum value, push into min array
        int max_value = nums[0];
        max_array[0] = nums[0];
        min_array[0] = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            int max_candidate = max_array[i - 1] * nums[i];
            int min_candidate = min_array[i - 1] * nums[i];
            printf("max_candidate:%d * %d = %d\n", max_array[i - 1], nums[i], max_array[i - 1]* nums[i]);
            printf("min_candidate:%d * %d = %d\n", min_array[i - 1], nums[i], min_array[i - 1]* nums[i]);

            /*
                example: min_array[i - 1] = -9, max_array[i - 1] = 5, nums[i] = -1
                new maximum number will be -9 * -1 = 9
            */

            max_array[i] = std::max( std::max(max_candidate, min_candidate), nums[i]);
            min_array[i] = std::min( std::min(max_candidate, min_candidate), nums[i]);
            max_value = std::max(max_value, max_array[i]);
            printf("max_array[i]:%d  \t min_array[i]:%d  \t nums[%d]:%d  \t max_value:%d\n", max_array[i], min_array[i], i, nums[i], max_value);
        }
        return max_value;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> prices{ 2,3,-2,4 };
    printf("output:%d\n", s -> maxProduct(prices));
}
