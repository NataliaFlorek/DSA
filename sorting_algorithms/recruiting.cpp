#include <iostream>
#include <string>

struct Person{
    std::string last_name;
    unsigned int x; 
};



void InsertSort(Person arr[], int n) {
    int i, j;
    Person pom;

    for (i = 1; i < n; i++) {

        pom = arr[i];
        j = i - 1;

        while (j >= 0 && (arr[j].x < pom.x || (arr[j].x == pom.x && arr[j].last_name.compare(pom.last_name) > 0))){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = pom;
    }
}


unsigned long int neededTime(Person arr[], int n){
    unsigned long int result = 0;
    for(int i = 0; i < n; i++){
        result = result + 1+i*arr[i].x;
    }
    result = result % 1000003;
    return result;
}



int main() {
    unsigned short int t;//liczba zestawów
    std::cin >> t;

    unsigned long int result;
    for(int i = 0; i < t; i++){
        int n = 0; 
        int p = 0; 
        std::cin >> n >> p;
        Person persons[n];

        for(int j = 0; j < n; j++) {
            Person person;
            std::cin >> persons[j].last_name;
            std::cin >> persons[j].x;
        }
        InsertSort(persons, n);
        result = neededTime(persons, n);
        for(int j = 0; j < p; j++){
            std::cout << persons[j].last_name << " ";
        }
        std::cout << '\n';
        std::cout << result << '\n';
    }
    return 0;
}
