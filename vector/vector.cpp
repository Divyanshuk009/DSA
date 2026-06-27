#include <iostream>
#include <vector>
using namespace std;

template <class T>

void display(vector<T> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "d ";
    }
    cout << endl;
}

int main()
{
    int ele;
    vector<int> vec;   // zero length int vector
    vector<char> vec2; // 4 element character vector
    vec2.push_back('a');
    display(vec2);

    vector<char> vec3(vec2); // 4 element character vector from vec2
    vector<int> v(6, 3);     // 6 element vector of 3s
    display(v);

    // for (int i = 1; i <= 4; i++)
    // {
    //     // cin >> ele;
    //     vec.push_back(i);
    // }

    // vector<int>::iterator iter = vec.begin();
    // vec.insert(iter + 1, 30, 60);
    // vec.pop_back(); // -4
    // display(vec);
}