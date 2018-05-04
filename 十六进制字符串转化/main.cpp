#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;



string HTOA(string &h) {
	int a;
	string out;
	for (int i = 0; i < h.length(); i += 2) {
		sscanf_s(h.c_str() + i, "%2X", &a);
		out += a;
	}
	return out;
}

string ATOH(string &in) {
	char *H = new char[in.length()*2+1];
	for (int i = 0; i < in.length(); i++) {
		sprintf_s(H + i * 2, 3, "%02X", in[i]);
	}
	string out(H, in.length() * 2);
	delete[]H;
	return out;
}


void main() {

	string hex = "01222324";
	cout << HTOA(hex).c_str() << endl;
	system("pause");

	string s = "!\"#$"; s[0] = 0x01;

	cout << ATOH(s).c_str() << endl;
	system("pause");
}