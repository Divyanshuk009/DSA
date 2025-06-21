#include <iostream>
#include <vector>

using namespace std;

void zero(vector<int> &arr)
{

    int i = 0;

    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(3);

    zero(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}