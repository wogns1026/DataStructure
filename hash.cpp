/*
해시 함수는 임의의 길이의 데이터를 고정된 길이의 데이터(해시 값)로 맵핑해주는 함수이다.
해시 함수를 이용하여 해시 테이블을 구축할 수 있고, 
이 해시 테이블을 통해 매우 빠른 데이터 검색이 가능하다.
=> 빠른 시간 내에 찾기가 필요할 때 사용

***해시 함수의 질은 해시 충돌 확률에 따라 결정된다.***
키 값이 충돌하면 인덱스를 하나씩 늘리면서 비어있는 곳을 찾아 값을 넣는다.
따라서 키 값이 충돌하지 않도록 해시 함수를 구현하는 것이 중요하다.
또 해시 함수 값이 해시 테이블의 주소 영역 내에서 고르게 분포되는 것이 좋다.

open addressing 방식과 close addressing 방식이 있다.
open addressing은 배열을 이용한 방식이고, 
close addressing은 리스트를 이용한 방식이다.
open addressing은 보통 n의 4배 정도의 크기가 필요 
close addressing은 보통 n의 2배 정도의 크기가 필요

이번 구현은 open addressing 방식을 이용하여 간단하게 수를 찾도록 구현하였다.
*/

#include <iostream>

#define a 4578369
#define b 1657043
#define tblsz 400007
#define maxval 30000000000

using namespace std;

long long hashtable[tblsz]; // 해시 테이블

void init() { 
	// 해시 테이블 초기화(문제가 0이 나올수도 있는 문제여서 나올 수 없는 값으로 초기화 시킴)
	for (int i = 0; i < tblsz; i++) {
		hashtable[i] = maxval;
	}
}

int hash_func(int num) {
	int hashval = (a*num + b) % tblsz;
	if (hashval < 0) // 문제에서 해시 값이 음수가 나올 수도 있기 때문에 양수로 바꿔줌
		hashval = -hashval;
	return hashval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, num = 0, idx = 0;
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		cin >> num;

		// 해시 테이블에 값 넣음
		idx = hash_func(num);
		while (hashtable[idx] != maxval) {
			idx++;
			if (idx == tblsz)
				idx = 0;
		}
		hashtable[idx] = num;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		idx = hash_func(num);
		// 해시 테이블에서 값을 찾음
		while (1) {
			if (hashtable[idx] == num) {
				cout << 1 << '\n';
				break;
			}
			else if (hashtable[idx] == maxval) {
				cout << 0 << '\n';
				break;
			}
			else {
				idx++;
			}
		}
	}

	return 0;
}