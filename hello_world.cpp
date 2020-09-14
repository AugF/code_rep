#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    for (int i = 11; i <= 14; i ++) {
        int x = 2 * i * i + 6 * i + 3, y = 9 * i * i + 8 * i, z = 2 * i * i * i * i * i + 4 * i * i * i + 5 * i * i;
        cout << x * y << ' ' << z << endl;
    }
    system("pause");
}