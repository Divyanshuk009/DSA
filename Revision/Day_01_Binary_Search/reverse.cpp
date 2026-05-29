#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v)
{

    int s = 0;
    int e = v.size() - 1;

    while (s <= e)
    {
        swap(v[s], v[e]);

        s++;
        e--;
    }
    return v;
}

void print(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> v;

    // v.push_back(7);
    // v.push_back(4);
    // v.push_back(0);
    // v.push_back(2);

    for (int i = 0; i <= 10; i++)
    {
        v.push_back(i);
      }

    print(v);

    vector<int> ans = reverse(v);

    print(ans);
}