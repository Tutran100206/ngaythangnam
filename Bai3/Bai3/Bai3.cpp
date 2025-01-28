#include<iostream>
#include<cmath>
using namespace std;
struct THOIGIAN
{
	int gio, phut, giay;
};
void nhap(THOIGIAN& t, THOIGIAN& t1);
bool hople(THOIGIAN t);
void khoangcach(THOIGIAN t, THOIGIAN t1);
int main() {
	THOIGIAN t,t1;
	nhap(t,t1);
	if (hople(t) && hople(t1)) {
		khoangcach(t, t1);
	}
	else {
		cout << "KHONG HOP LE";
	}
	return 0;
}
void nhap(THOIGIAN& t, THOIGIAN &t1) {
	cin >> t.gio >> t.phut >> t.giay;
	cin >> t1.gio >> t1.phut >> t1.giay;
}
bool hople(THOIGIAN t) {
	if (t.gio >= 0 && t.phut >= 0 && t.giay >= 0 && t.gio < 24 && t.phut < 60 && t.giay < 60) {
		return true;
	}
	else {
		return false;
	}
}
void khoangcach(THOIGIAN t, THOIGIAN t1) {
	int x = t.gio * 60 * 60 + t.phut * 60 + t.giay;
	int y = t1.gio * 60 * 60 + t1.phut * 60 + t1.giay;
	int w = abs(x - y);
	t.gio = w / 3600;
	w = w -  t.gio*3600;
	t.phut = w / 60;
	t.giay = w - t.phut * 60;
	cout << t.gio << " " << t.phut << " " << t.giay;
}


