#include <iostream>
#include <string>

using namespace std;

string generateSurname(int first_o, int second_o, int third_o,  int fourth_o, string tab[]) {
    return tab[first_o%1500].substr(0, 3) + tab[second_o%1500].substr(3, 3) + tab[third_o%1500].substr(6, 3) + tab[fourth_o%1500].substr(9, 3);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string generations[1500];
    for(int i = 0; i < m; i++){
        cin >> generations[i%1500];
    }
    int first_o, second_o, third_o, fourth_o;
    for(int i = m; i <  n; i++){
        cin >> first_o >> second_o >> third_o >> fourth_o;
        generations[i%1500] = generateSurname(first_o, second_o, third_o, fourth_o, generations);
    }

    cout << generations[(n-1)%1500] << endl;
    return 0;
}
