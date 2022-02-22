//============================================================================
// Name        : Two.cpp
// Author      : Abhishek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> twoSumBruteForce(vector<int> nums, int target)
	  {
		  std::vector<int> result;
		  for(size_t i = 0; i < nums.size(); i++)
		  {
			  //fix one of the indexes
			  for(size_t j = i+1; j < nums.size(); j++)
			  {
				  if(target < nums[i] && target < nums[j] && (nums[i] + nums[j] == target))
				  {
					  result.push_back(nums[i]);
					  result.push_back(nums[j]);
					  return result;
				  }
			  }
		  }

		  return result;
	  }

	  vector<int> twoSumOptimized(vector<int>& nums, int target) {
	      std::cout<<"Two sum" << std::endl;

		  std::unordered_map<int, int> imap;

	      vector<int> output;
	      for (size_t i = 0; i < nums.size(); ++i) {
	          auto it = imap.find(target - nums[i]);

	          if (it != imap.end())
	          {
	        	  output.push_back(it->second);
	              output.push_back(i);
	          }

	          imap[nums[i]] = i;
	      }

	      return output;
	  }
};



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	size_t maxArraySize = 0;
	int targetSum = 0;
	vector<int> input, result;
	int value;

	std::cout<<"Enter Max size of array" << std::endl;
	std::cin >> maxArraySize;
	std::cout<< "Enter the target sum value" << std::endl;
	std::cin >> targetSum;

	for(size_t i=0;i<maxArraySize;i++) {
	        cout << "Please Enter value into array at index:" << i << endl;
	        cin >> value;
	        if(value > 9999)
	            value = 0;
	        input.push_back(value);
	    }

	Solution sol;
	result = sol.twoSumOptimized(input,targetSum);
	    if(!result.empty())
	        cout<< "Sum of :" << targetSum << "is achieved by indices present at: " << result[0] << " and " << result[1] << endl;
	    else
	        cout << "Target not found in vector" << endl;


	return 0;
}
