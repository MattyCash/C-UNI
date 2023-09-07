#include <bits/stdc++.h>
using namespace std;
int m;

void inputArray(int** arr, int size) { 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void outputArray(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << '\n';
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
	}
}

int isPrime(int number) {
	if (number > 1) {
		int a = number % 10;
		if (number == 2 || number == 5)
			return 1;
		else if (a == 1 || a == 3 || a == 7 || a == 9) {
			a = 2;
			while (a < sqrt(number)) {
				if (number % a == 0)
					return 0;
				++a;
			}
			return 1;
		}
		return 0;
	}
	else
		return 0;
}

int countPrimer(int** arr, int size) {
	int count = 0;
	for (int j = 0; j < m; j++) {
		if (isPrime(arr[size][j]) == 1)
			count++;
	}
	return count;
}

int findRowIndWithMaxPrimesCount(int** arr, int n, int m) {
	int max=0 , point1 , count;
	for (int i = 0; i < n; i++) {
		count = countPrimer(arr, i);
		if (max < count) {
			max = count;
			point1 = i;
		}
	}
	return point1;
}

void sortArr(int** arr, int size) {
	int max = 0;
	for (int i = 0; i < m; i++) {// зачем два цикла? первый, чтобы 3 в конце массива из 10 чисел точно оказалась в начале массива а не помен€лась только 1 раз
		// ƒопустим: 1 3 5 6 3 5 когда i=0 будет выгл€деть как: 1 3 5 3 5 6  когда i =1 будет выгл€деть как: 1 3 3 5 5 6 . ѕонадобитс€ повтор€ть процесс, чтоб наверн€ка
		for (int b = 0; b < m - 1; b++) {// оно сдвинет числа на 1 влево , если оно меньше . ƒругими словами:≈сли a[n]<a[n-1] , то они помен€ютс€ местами
			if (arr[size][b] > arr[size][b + 1]) {// 73-76 строки процес замены местами
				max = arr[size][b];
				arr[size][b] = arr[size][b + 1];
				arr[size][b + 1] = max;
			}
		}
	}
}

int main() {
	int n;
	cin >> n >> m;
	int** a = new int* [n]; 
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	inputArray(a, n);
	sortArr(a, findRowIndWithMaxPrimesCount(a, n, m)); //вернЄт номер строки в которой будет больше всего простых чисел, а дальше пойдЄт сортировка этой строки
	outputArray(a, n);
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
}

