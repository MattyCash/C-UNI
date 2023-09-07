#include <bits/stdc++.h>
using namespace std;
struct Student {
	int id;
	char* name;
	char* surname;
	int num;
	double* grades;
};

void sort(Student* a, int n) {
	for (int c = 0; c < n; c++) {
		double max;
		for (int i = 0; i < n; i++) {
			for (int b = 0; b < n - 1; b++) {
				if (a[c].grades[b] > a[c].grades[b + 1]) {
					max = a[c].grades[b];
					a[c].grades[b] = a[c].grades[b + 1];
					a[c].grades[b + 1] = max;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	Student* st = new Student[n];
	
	for (int i = 0; i < n; i++) {
		st[i].name = new char[21];
		st[i].surname = new char[21];
		cin >> st[i].id >> st[i].name >> st[i].surname >> st[i].num;
		st[i].grades = new double[st[i].num];
		for (int j = 0; j < st[i].num; j++) {
			cin >> st[i].grades[j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << '\n' << st[i].id << ' ' << st[i].name << ' ' << st[i].surname << " : ";
		for (int j = 0; j < st[i].num; j++) {
			cout << st[i].grades[j] << ' ';
		}
	}
	
	sort(st, n);
	
	for (int i = 0; i < n; i++) {
		cout << '\n' << st[i].id << ' ' << st[i].name << ' ' << st[i].surname << " : ";
		for (int j = 0; j < st[i].num; j++) {
			cout << st[i].grades[j] << ' ';
		}
	}
	delete[] st;
}



