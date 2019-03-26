/*

���ڿ��� �����ϴ� strcpy �Լ��� ���� �����غ��Ҵ�.

<���� strcpy stl �����>
char a[10], b[10];
strcpy(a, b); => b�� ���ڿ��� a�� ����

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