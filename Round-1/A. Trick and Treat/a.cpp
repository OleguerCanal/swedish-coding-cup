#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> kids(n);
    for (int i = 0; i < n; i++)
        cin >> kids[i];

    int min_rolls = n;

    for (int k = max(0, m-10); k <= m; k++) {
        int i = 0;
        int candy_left = k;
        int happy_gorups = 0;
        while(candy_left > 0 and i < n) {
            if (candy_left >= kids[i]) {
                candy_left -= kids[i];
                happy_gorups++;
            }
            i++;
        }
        min_rolls = min(min_rolls, n - happy_gorups);
    }

    cout << min_rolls << endl;
}
