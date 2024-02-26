#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const double PI = 3.141593;

struct Car{
    std::string name;
    double p = 0;
    unsigned long int d = 0;
    unsigned long result = 0;
};

unsigned long int rotations(double  p, unsigned long int d){
    unsigned long int result;
    result = (unsigned long int)((p*1000.0)/(d*0.0254*PI));
    return result;
}

bool sorting (Car &result1, Car &result2){
    if(result1.result == result2.result){
        return (result1.name < result2.name);
    }
    return (result1.result < result2.result);
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Car> cars;
    cars.reserve(3);

    for(int i = 0; i < n; i++){
        Car car;
        std::getline(std::cin, car.name);
        std::getline(std::cin, car.name);
        std::cin >> car.p;
        std::cin.ignore();
        std::cin >> car.d;
        car.result = rotations(car.p, car.d);
        cars.push_back(car);
        if (cars.size() > 3) {
            std::sort(cars.begin(), cars.end(), sorting);
            cars.erase(cars.begin() + 3, cars.end());
        }
    }

    std::sort(cars.begin(), cars.end(), sorting);


    for(int i = 0; i < 3;i++ ){
        std::cout << cars[i].name << '\n';
        std::cout << cars[i].result << '\n';
    }

    cars.clear();

    return 0;
}

