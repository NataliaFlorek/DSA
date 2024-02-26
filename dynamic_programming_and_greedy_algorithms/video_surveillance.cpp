#include <iostream>
#include <algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool compareInterval(Interval i1, Interval i2) {
    return (i1.end < i2.end);
}

void canCameraBePlacedHere(Interval intervals[], int n ) {
    int *cameras = new int[n];
    fill(cameras, cameras + n, 0);
    for (int i = 0; i < n; i++) {
        bool canBePlaced = false;
        int start = intervals[i].start;
        int end = intervals[i].end;
        for (int j = start; j <= end; j++) {
            if (cameras[j] == 0) {
                canBePlaced = true;
                cameras[j] = 1;
                break;
            }
        }
        if (canBePlaced == false){
            delete[] cameras;
            cout << "NIE" << endl;
            return;
        }
    }
    delete[] cameras;
    cout << "TAK" << endl;
}

int main() {
    int t, n, a, b; 
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        Interval intervals[n];
        for (int j = 0; j < n; j++) {
            cin >> a >> b;
            intervals[j].start = a;
            intervals[j].end = b;
        }
        sort(intervals, intervals + n, compareInterval);
        canCameraBePlacedHere(intervals, n);
    }
    return 0;
}
