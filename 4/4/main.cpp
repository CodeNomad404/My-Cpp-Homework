#include<iostream>
#include"RationalNumber.h"
using namespace std;
int main() {
	RationalNumber a(1,1),b(1,1);
	cin >> a>>b;
	char c='0';
	cout << "你想要对这两个数做什么：(+-*/)" << endl;
	cin >> c;
	while (c != '@') {
		switch (c) {
		case '+': {
			RationalNumber res = a + b;
			cout << res<<endl;
			break;
		}
		case '-': {
			RationalNumber res = a - b;
			cout << res << endl;
			break;
		}
		case '*': {
			RationalNumber res = a * b;
			cout << res << endl;
			break;
		}
		case '/': {
			RationalNumber res = a / b;
			cout << res << endl;
			break;
		}
		}
		cout << "你想要对这两个数做什么(+-*/,输入@结束进程)：" << endl;
		cin >> c;
	}
}