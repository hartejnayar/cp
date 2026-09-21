#include <iostream>
#include <algorithm>
using namespace std;

int b[200005];
int unique_b[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Step 1: Magic number = height − position
        for (int i = 0; i < n; i++) {
            int height;
            cin >> height;
            b[i] = height - (i + 1);
        }

        // Step 2: Sort
        sort(b, b + n);

        // Step 3: Remove duplicates
        int unique_count = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || b[i] != b[i - 1]) {
                unique_b[unique_count] = b[i];
                unique_count++;
            }
        }

        // Step 4: Longest consecutive chain
        int max_len = 0, current_len = 0;
        for (int i = 0; i < unique_count; i++) {
            if (i == 0 || unique_b[i] == unique_b[i - 1] + 1) {
                current_len++;
            } else {
                if (current_len > max_len) max_len = current_len;
                current_len = 1;
            }
        }
        if (current_len > max_len) max_len = current_len;

        cout << max_len << "\n";
    }
    return 0;
}