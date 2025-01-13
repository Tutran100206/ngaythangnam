#include<iostream>
using namespace std;
void nhap(int& day, int& month, int& year);
bool hople(int day, int month, int year);
int  songaytrongthang(int month, int year);
bool ktranamnhuan(int year);
void ktraquy(int month);
void xuatngaytanggiam(int day, int month, int year);
int main() {
	int day, month, year;
	nhap(day, month, year);
	if (hople(day, month, year)) {
		xuatngaytanggiam(day, month, year);
	}
	else {
		cout << "KHONG HOP LE";
	}
	return 0;
}
void nhap(int& day, int& month, int& year) {
	cin >> day >> month >> year;
}
bool hople(int day, int month, int year) {
	if (day > 0 && month > 0 && year > 0 && month <= 12 && day <= songaytrongthang(month, year)) {
		return true;
	}
	else {
		return false;
	}
}
int  songaytrongthang(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else if (month == 2){
		if (ktranamnhuan(year)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else {
		return 31;
	}
}
bool ktranamnhuan(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}
void ktraquy(int month) {
	if (month == 1 || month == 2 || month == 3) {
		cout << 1;
	}
	else if (month == 4 || month == 5 || month == 6) {
		cout << 2;
	}
	else if (month == 7 || month == 8 || month == 9) {
		cout << 3;
	}
	else {
		cout << 4;
	}
}
void xuatngaytanggiam(int day, int month, int year) {
	cout << "HOP LE\n";
	ktraquy(month);
	cout << endl;
	int k = songaytrongthang(month, year);
	cout << k << endl;
	if (day < k && month < 12) {
		cout << day + 1 << " " << month << " " << year << endl;
	}
	else if (day < k && month == 12) {
		cout << day + 1 << " " << month << " " << year << endl;
	}
	else if (day == k && month < 12) {
		cout << 1 << " " << month + 1 << " " << year << endl;
	}
	else {
		cout << 1 << " " << 1 << " " << year + 1 << endl;
	}
	if (day > 1 && day <= k) {
		cout << day - 1 << " " << month << " " << year;
	}
	else if (day == 1 && month > 1) {
		int m = songaytrongthang(month - 1, year);
		cout << m << " " << month - 1 << " " << year;
	}
	else if (day == 1 && month == 1) {
		cout << 31 << " " << 12 << " " << year - 1;
	}
}
