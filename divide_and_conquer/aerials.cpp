#include <iostream>
#include <cmath>

using namespace std;



double binarySearch(int low, int high, int m){
    while (low <= high) {
        int mid = low + (high - low) / 2;
        double max = P(mid, 0);
        int current = 0;
        for (int i = 0; i < m; i++) {
            if (P(mid, i) > max) {
                max = P(mid, i);
                current = i;

            }
        }
        if ((mid > 0) && (P(mid, current) < P(mid - 1, current))) {
            return binarySearch(low, mid + 1, m);
        } else if ((mid < high - 1) && (P(mid, current) < P(mid + 1, current)) ) {
            return binarySearch(mid - 1, high, m);
        } else {
            return max;
        }
    }
    return -1;

}


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int n, m;
    cin >> n >> m;

    cout << (int)binarySearch(0, n - 1 ,m);

    return 0;
}
