#include <iostream>
#include <string>

struct Student{
    std::string name_code;
    float s; 
    unsigned d; 
    unsigned int m; 
};

void InsertSort(Student *students, unsigned int n, char letters[]) {
    Student pom;
    int j, i;
    if (letters[0] == 'm') {
        if (letters[1] == 's' && letters[2] == 'd') {
            for (i = 1; i < n; i++) {
                pom = students[i];
                j = i - 1;
                while (j >= 0 && ((students[j].m < pom.m) || (students[j].m == pom.m && students[j].s < pom.s) ||
                                  (students[j].m == pom.m && students[j].s == pom.s && students[j].d < pom.d))) {

                    students[j + 1] = students[j];
                    j = j - 1;
                }
                students[j + 1] = pom;
            }
        } else if (letters[1] == 'd' && letters[2] == 's') {
            for (i = 1; i < n; i++) {
                pom = students[i];
                j = i - 1;
                while (j >= 0 && ((students[j].m < pom.m) || (students[j].m == pom.m && students[j].d < pom.d) ||
                                  (students[j].m == pom.m && students[j].d == pom.d && students[j].s < pom.s))) {

                    students[j + 1] = students[j];
                    j = j - 1;
                }
                students[j + 1] = pom;
            }
        }
    }else if (letters[0] == 'd') {
        if (letters[1] == 's' && letters[2] == 'm') {
            for (i = 1; i < n; i++) {
                pom = students[i];
                j = i - 1;
                while (j >= 0 && ((students[j].d < pom.d) || (students[j].d == pom.d && students[j].s < pom.s) ||
                                  (students[j].d == pom.d && students[j].s == pom.s &&
                                   students[j].m < pom.m))) {

                    students[j + 1] = students[j];
                    j = j - 1;
                }
                students[j + 1] = pom;
            }
        } else if (letters[1] == 'm' && letters[2] == 's') {
            for (i = 1; i < n; i++) {
                pom = students[i];
                j = i - 1;
                while (j >= 0 && ((students[j].d < pom.d) || (students[j].d == pom.d && students[j].m < pom.m) ||
                                  (students[j].d == pom.d && students[j].m == pom.m &&
                                   students[j].s < pom.s))) {


                    students[j + 1] = students[j];
                    j = j - 1;
                }
                students[j + 1] = pom;
            }
        }
    }else if (letters[0] == 's') {
                if (letters[1] == 'd' && letters[2] == 'm') {
                    for ( i = 1; i < n; i++) {
                        pom = students[i];
                        j = i - 1;
                        while (j >= 0 &&
                               ((students[j].s < pom.s) || (students[j].s == pom.s && students[j].d < pom.d) ||
                                (students[j].s == pom.s && students[j].d == pom.d &&
                                 students[j].m < pom.m))) {
                            students[j + 1] = students[j];
                            j = j - 1;
                        }
                        students[j + 1] = pom;
                    }
                } else if (letters[1] == 'm' && letters[2] == 'd') {
                    for ( i = 1; i < n; i++) {
                        pom = students[i];
                        j = i - 1;
                        while (j >= 0 &&
                               ((students[j].s < pom.s) || (students[j].s == pom.s && students[j].m < pom.m) ||
                                (students[j].s == pom.s && students[j].m == pom.m &&
                                 students[j].d < pom.d))) {

                            students[j + 1] = students[j];
                            j = j - 1;
                        }
                        students[j + 1] = pom;
                    }
                }
    }
}




int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    unsigned int n;
    std::cin >> n;

    char letters[3]; 
    for(int i = 0; i < 3; i++){
        std::cin >> letters[i];
    }
    std::cin.ignore();
    Student *girls = new Student[n];
    Student *boys = new Student[n];

    for(int i = 0; i < n; i++){
        std::cin >> girls[i].name_code >> girls[i].s >> girls[i].d >> girls[i].m >> boys[i].name_code >> boys[i].s >> boys[i].d >> boys[i].m;
    }

    InsertSort(girls, n, letters);
    InsertSort(boys, n, letters);

    for(int i = 0; i < n; i++){
        std::cout << girls[i].name_code << " ";
        std::cout << boys[i].name_code << " ";
    }

    delete[] girls;
    delete[] boys;

    return 0;
}
