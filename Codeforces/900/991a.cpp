#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,n;
    cin >> a >>b >>c >> n;
    if (c>a || c>b){
    	cout << -1 << "\n";
   		return 0;
    }

    int total_visited = a + b -c;
    int fail  = n - total_visited;

    if(fail >=1){
    	cout << fail << "\n";
    } else{
    	cout << -1 << "\n";
    	return 0;
    }
    return 0;
}