#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxsubwindow(vector<int> nums, int k)
{
       if (nums.size() < k)
              return -1;
       int windowState = 0;
       int result = 0;

       for (int i = 0; i < k; i++)
       {
              windowState += nums[i];
       }
       result = windowState;

       for (int i = k; i < nums.size(); i++)
       {
              windowState += nums[i];
              windowState -= nums[i - k];

              result = max(result, windowState);
       }
       return result;
}

int main()
{
}