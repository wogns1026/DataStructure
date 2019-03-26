/*

문자열을 복사하는 strcpy 함수를 직접 구현해보았다.

<기존 strcpy stl 사용방법>
char a[10], b[10];
strcpy(a, b); => b의 문자열을 a로 복사

*/

#include <iostream>

using namespace std;

void _strcpy(char *dest, char *source) {
	int i = 0;
	while (source[i] != '\0') {
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	
	char a[256];
	char b[256] = "hello";
	_strcpy(a, b);
	cout << a << '\n';

	return 0;
}