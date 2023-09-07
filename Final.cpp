//1.1
#include <iostream>

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) std::cin >> arr[i];
}

bool isPrime(int number) {
    if (number == 2) return 1;
    if (number % 2 == 0 || number == 1) return 0;

    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) return 0;
    }

    return 1;
}

int countPrimes(int *arr, int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) res += isPrime(arr[i]);
    return res;
}

int main() {
    int n;
    std::cin >> n;
    int a[n];
    inputArray(a, n);
    std::cout << countPrimes(a, n);
}
//1.2
#include <algorithm>
#include <iostream>

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) std::cin >> arr[i];
}

void outputArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) std::cout << arr[i] << ' ';
}

void inputMatrix(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) inputArray(arr[i], m);
}
void outputMatrix(int **arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        outputArray(arr[i], m);
        std::cout << '\n';
    }
}

void sortArr(int *arr, int size) { std::sort(arr, arr + size); }

bool isPrime(int number) {
    if (number == 2) return 1;
    if (number % 2 == 0 || number == 1) return 0;

    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) return 0;
    }

    return 1;
}

int countPrimes(int *arr, int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) res += isPrime(arr[i]);
    return res;
}

int findRowIndWithMaxPrimesCount(int **arr, int n, int m) {
    int ans = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        int primes = countPrimes(arr[i], m);
        if (res < primes) res = primes, ans = i;
    }
    return ans;
}

int **dynamicMatrix(int n, int m) {
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) arr[i] = new int[m];
    return arr;
}

void deleteMatrix(int **arr, int n) {
    for (int i = 0; i < n; ++i) delete [] arr[i];
    delete [] arr;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int **a = dynamicMatrix(n, m);
    inputMatrix(a, n, m);
    int id = findRowIndWithMaxPrimesCount(a, n, m);
    sortArr(a[id], m);
    outputMatrix(a, n, m);
    deleteMatrix(a, n);
}
//2.1
#include <algorithm>
#include <cstring>
#include <iostream>

struct Student {
    int id, n;
    char *name, *surname;
    double *grades;

    Student(int new_id, const char *new_name, const char *new_surname, int new_n,
            double *new_grades) {
        id = new_id;

        name = new char[256];
        for (int i = 0; i < 255; ++i) {
            name[i] = new_name[i];
            if (name[i] == '\0') break;
        }
        name[255] = '\0';

        surname = new char[256];
        for (int i = 0; i < 255; ++i) {
            surname[i] = new_surname[i];
            if (surname[i] == '\0') break;
        }
        surname[255] = '\0';

        n = new_n;
        grades = new double[n];
        for (int i = 0; i < n; ++i) {
            grades[i] = new_grades[i];
        }

        std::sort(grades, grades + n);
    }

    ~Student() {
        delete[] name;
        delete[] surname;
        delete[] grades;
    }

    void print() {
        std::cout << id << ' ' << name << ' ' << surname << " : ";
        for (int i = 0; i < n; ++i)
            std::cout << grades[i] << ' ';
        std::cout << '\n';
    }
};

int main() {
    int id, n;
    std::string name, surname;
    std::cin >> id >> name >> surname >> n;
    double grades[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> grades[i];
    }

    Student student(id, name.c_str(), surname.c_str(), n, grades);

    student.print();
}
//2.2
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

struct Student {
    int id, n;
    char *name, *surname;
    double *grades, avg;

    Student(int new_id, const char *new_name, const char *new_surname,
            int new_n, double *new_grades) {
        id = new_id;

        name = new char[256];
        for (int i = 0; i < 255; ++i) {
            name[i] = new_name[i];
            if (name[i] == '\0') break;
        }
        name[255] = '\0';

        surname = new char[256];
        for (int i = 0; i < 255; ++i) {
            surname[i] = new_surname[i];
            if (surname[i] == '\0') break;
        }
        surname[255] = '\0';

        n = new_n;
        grades = new double[n];
        for (int i = 0; i < n; ++i) {
            grades[i] = new_grades[i];
            avg += grades[i];
        }

        avg /= n;

        std::sort(grades, grades + n);
    }

    static bool compareStudents(const Student *f, const Student *s) {
        return (f->avg > s->avg);
    }

    ~Student() {
        delete[] name;
        delete[] surname;
        delete[] grades;
    }

    const void print() {
        std::cout << id << ' ' << name << ' ' << surname << " : ";
        for (int i = 0; i < n; ++i) std::cout << grades[i] << ' ';
        std::cout << '\n';
    }
};

int main() {
    int t;
    std::cin >> t;
    std::vector<Student *> students;

    for (int i = 0; i < t; ++i) {
        int id, n;
        std::string name, surname;
        std::cin >> id >> name >> surname >> n;
        double grades[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> grades[i];
        }
        students.push_back(
            new Student(id, name.c_str(), surname.c_str(), n, grades));
    }
    std::sort(students.begin(), students.end(), Student::compareStudents);

    for (int i = 0; i < t; ++i) {
        students[i]->print();
        delete students[i];
    }
}
