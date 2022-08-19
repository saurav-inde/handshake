#include <iostream>

#include <string>
using namespace std;

int main()
{

    string a, b;
    int n, tc;
    int changes;

    cin >> tc;
    while (tc--)
    {
        cin >> n;
        cin >> a >> b;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            changes++;
        }
        cout << ((changes % 2) ? 0 : 1);
    }

    return 0;
}