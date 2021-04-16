#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//双指针法

//三数相加
vector <vector<int>>threesum(vector<int>& nums, int target)
{
	vector<vector<int>>ret;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] == target)
			{
				ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
				while (left < right && nums[left] == nums[left+1]) left++;
				while (left < right && nums[right] == nums[right-1]) right--;
				left++;
				right--;
			}
			else if(nums[i] + nums[left] + nums[right] < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return ret;
}
//四数相加
vector<vector<int>>foursum(vector<int>& nums, int target)
{
	vector<vector<int>> ret;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		for (int j = i+1; j < nums.size(); j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int left = j + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[j] + nums[left] + nums[right] == target)
				{
					ret.push_back(vector<int>{ nums[i] ,nums[j],nums[left],nums[right] });
					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right-1]) right--;
					left++;
					right--;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
	}
	return ret;
}
//测试三数相加
void test_threesum()
{
	cout << "三数相加等于0" << endl;
	int a[6] = { 1,0,-1,0,-2,2 };
	vector<int> nums(a, a + 6);
	int target = 0;
	vector<vector<int>>ret = threesum(nums, target);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}
//测试四数相加
void test_foursum()
{
	cout << "四数相加等于0" << endl;
	int a[18] = { 4, -9, -2, -2, -7, 9, 9, 5, 10, -10, 4, 5, 2, -4, -2, 4, -9, 5 };

	vector<int> nums(a, a + 18);
	int target = -13;
	vector<vector<int>>ret = foursum(nums, target);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	test_threesum();
	test_foursum();
	return 0;
}