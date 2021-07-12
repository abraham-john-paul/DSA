#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t; // no. of test cases
	int d, x, y, z;
	while(t--) {
	    cin >> d;
        cin >> x;
        cin >> y >> z;
        cout << max(7 * x, (y * d + (7 - d) * z)) << "\n";
	}
	return 0;
}
