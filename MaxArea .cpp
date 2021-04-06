#include<iostream>
#include<vector>
using namespace std;
//暴力法，但是会超出时间限制
int maxArea(vector<int> &h)
{
	int maxArea = 0;
	int size = h.size();
	for(int i = 0;i < size-1;i++)
	{
		for(int j = i+1;j<size;j++)
		{
     		int area = min(h[i],h[j])*(j-i);
			if(area>maxArea)
				maxArea = area;
		}
	}
	return maxArea;
}
//左右指针法
int MaxArea(vector<int> &h)
{
	int left = 0;
	int right = h.size()-1;
	int max = 0;
	while(left <right)
	{
		int area = min(h[left],h[right])*(right-left);
		if(area>max)
			max =area;
		if(h[left] <= h[right])
			left++;
		else
			right--;
	}
	return max;
}


int main()
{
	int a[7] = {2,3,4,5,18,17,6};
	vector<int> h(a,a+7);
	int ret = MaxArea(h);

	cout<<"最大盛水量:"<<ret<<endl;
	return 0;
}

