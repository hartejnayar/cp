#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 
        if (n == 1 || n == 3) {
            cout << "-1\n";
        }
        else if (n % 2 == 0) {
            for (int i = 0; i < n - 2; i++) {
                cout << '3';
            }

            cout << "66\n";
        } 
        else {
            // Print '3' (n - 4) times
            for (int i = 0; i < n - 4; i++) {
                cout << '3';
            }
            // End with '6366'
            cout << "6366\n";
        }
    }

    return 0;
}
