#include <iostream>
using namespace std;

void reachHome(int src, int desti)
{

    cout << "source " << src << " destination " << desti << endl;

    if (src == desti)
    {
        cout << "pahuch gya " << endl;
        return;
    }
    reachHome(src + 1, desti);
}

int main()
{

    int desti = 10;
    int src = 1;

    reachHome(src, desti);
}