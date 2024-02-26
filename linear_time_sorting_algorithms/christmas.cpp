#include <iostream>
#include <string>

using namespace std;

struct Meal {
    string name;
    int calories;
};

void counting_sort_modulo(Meal meals[], int n) {
    int counting[n];
    for (int i = 0; i < n; i++) {
        counting[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        counting[meals[i].calories % n]++;
    }
    for (int i = 1; i < n; i++) {
        counting[i] += counting[i - 1];
    }
    Meal sorted_meals[n];
    for (int i = n - 1; i >= 0; i--) {
        sorted_meals[counting[meals[i].calories % n] - 1] = meals[i];
        counting[meals[i].calories % n]--;
    }
    for (int i = 0; i < n; i++) {
        meals[i] = sorted_meals[i];
    }
}

void counting_sort_dividing(Meal meals[], int n) {
    int counting[n];
    for (int i = 0; i < n; i++) {
        counting[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        counting[meals[i].calories / n]++;
    }
    for (int i = 1; i < n; i++) {
        counting[i] += counting[i - 1];
    }
    Meal sorted_meals[n];
    for (int i = n - 1; i >= 0; i--) {
        sorted_meals[counting[meals[i].calories / n] - 1] = meals[i];
        counting[meals[i].calories / n]--;
    }
    for (int i = 0; i < n; i++) {
        meals[i] = sorted_meals[i];
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int n;
    cin >> n;
    Meal *meals = new Meal[n];
    for (int i = 0; i < n; i++) {
        cin >> meals[i].name >> meals[i].calories;
    }
    counting_sort_modulo(meals, n);
    counting_sort_dividing(meals, n);

    for (int i = 0; i < n; i++) {
        cout << meals[i].name << " ";
    }

    delete[] meals;
    return 0;
}
