#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
struct DATE
{
	int ngay, thang, nam;
};
void nhap(string& t);
void chuyendoiso(string t, DATE& s);
bool namnhuan(int year);
bool hople(DATE s);
int songaytrongthang(int month, int year);
int songaycacthang(DATE s);
int songaycacnam(DATE s);
void khoangcach(DATE s, DATE s1);
int main() {
	DATE s, s1;
	string t, t1;
	nhap(t);
	nhap(t1);
	chuyendoiso(t,s);
	chuyendoiso(t1,s1);
	if (hople(s) && hople(s1)) {
		khoangcach(s, s1);
	}
	else {
		cout << -1;
	}
	return 0;
}
void nhap(string &t) {
	getline(cin, t);
}
void chuyendoiso(string t, DATE &s) {
	stringstream ss(t);
	string tam;
	vector<string>v;
	while (getline(ss, tam, '/')) {
		v.push_back(tam);
	}
	s.ngay = stoi(v[0]);
	s.thang = stoi(v[1]);
	s.nam = stoi(v[2]);
}
bool hople(DATE s) {
	if (s.ngay > 0 && s.thang > 0 && s.nam > 0 && s.thang <= 12 && s.ngay <= songaytrongthang(s.thang, s.nam)) {
		return true;
	}
	else {
		return false;
	}
}
bool namnhuan(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}
int songaytrongthang(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else if (month == 2) {
		if (namnhuan(year)) {
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
int songaycacthang(DATE s) {
	int kc = 0;
	for (int i = 1; i < s.thang; i++) {
		kc += songaytrongthang(i, s.nam);
	}
	kc += s.ngay;
	return kc;
}
int songaycacnam(DATE s) {
	int kc = 0;
	for (int i = 1; i < s.nam; i++) {
		if (namnhuan(i)) {
			kc += 366;
		}
		else {
			kc += 365;
		}
	}
	return kc;
}
void khoangcach(DATE s, DATE s1) {
	int r = songaycacthang(s) + songaycacnam(s);
	int u = songaycacthang(s1) + songaycacnam(s1);
	cout << abs(r - u);
}
/*
*input 9/12/2008 1/3/2027
*output 6656
*note: full 39/39 testcase uteoj, full 390/390
*/