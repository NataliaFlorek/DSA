#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int howManyPossibilities(int arr[], int size, int caloriesJanushWantsToDevour, int index, int sum) {
    if (sum == caloriesJanushWantsToDevour) {
        return 1;
    }
    if (sum > caloriesJanushWantsToDevour || index >= size) {
        return 0;
    }
    int possibilities = 0;
    possibilities += howManyPossibilities(arr, size, caloriesJanushWantsToDevour, index + 1, sum + arr[index]);
    possibilities += howManyPossibilities(arr, size, caloriesJanushWantsToDevour, index + 1, sum);
    return possibilities;
}

int main() {
    int sets;
    cin >> sets;
    for (int i = 0; i < sets; i++) {
        int productNumber;
        cin >> productNumber;
        int productTable[productNumber];
        for (int j = 0; j < productNumber; j++) {
            cin >> productTable[j];
        }
        int caloriesJanushWantsToDevour;
        cin >> caloriesJanushWantsToDevour;
        sort(productTable, productTable + productNumber, compare);
        int result = howManyPossibilities(productTable, productNumber, caloriesJanushWantsToDevour, 0, 0);
        cout << result << endl;
    }
    return 0;
}
