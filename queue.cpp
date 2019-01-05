/*
배열로 Queue를 구현(환형 큐) => 링크드 리스트로 구현 가능(스택은 링크드 리스트로 구현해보겠음!)
최대 크기를 100000 이라 했을 때
Queue는 먼저 들어가는 데이터가 먼저 나오는 FIFO 구조
선형 큐와 환형 큐 2가지 종류가 있음
*/

#include <iostream>

using namespace std;

template <typename T> // 어떤 type으로도 선언 가능하게 해줌
class Queue {
private : 
	T *arr; // 선언한 type 배열
	int cnt; // queue의 크기
	int front_idx; // queue의 맨 앞 index
	int back_idx; // queue의 맨 뒤 index
public : 
	Queue(); // 생성자
	bool empty(); // queue가 비어있는지 확인 => O(1)
	int size(); // queue의 크기를 리턴 => O(1)
	T& front(); // queue의 맨 앞의 값을 리턴 => O(1)
	T& back(); // queue의 맨 뒤의 값을 리턴 => O(1)
	void push(T); // queue에 데이터 값을 삽입(맨 뒤에 삽입) => O(1)
	void pop(); // queue의 데이터 값을 삭제(맨 앞의 데이터 삭제) => O(1)
	~Queue(); // 소멸자
};

template <typename T>
Queue<T>::Queue() : arr(new T(100000)), cnt(0), front_idx(0), back_idx(-1) { // 배열의 최대 사이즈를 100000으로 정함
	// back_idx는 -1로 초기화 해야됨 => 데이터를 추가하고 그곳을 가리키고 있어야하므로 +1 한 뒤 데이터 추가
}
template <typename T>
bool Queue<T>::empty() {
	if (cnt == 0)
		return true;
	return false;
}
template <typename T>
int Queue<T>::size() {
	return cnt;
}
template <typename T>
T& Queue<T>::front() {
	if (cnt == 0) {
		cout << "Queue is empty\n";
	}
	else
		return arr[front_idx];
}
template <typename T>
T& Queue<T>::back() {
	if (cnt == 0) {
		cout << "Queue is empty\n";	
	}
	else
		return arr[back_idx];
}
template <typename T>
void Queue<T>::push(T val) {
	if (cnt == 100000)
		cout << "Size is over! Maximum size is 100000!\n";
	else{
		back_idx++;
		// 환형 큐이므로 사이즈는 최대 사이즈가 아닌데 index가 최대 사이즈까지 커졌을 때 다시 0으로 초기화 해줌
		if (back_idx == 100000)
			back_idx = 0;
		arr[back_idx] = val;
		cnt++;
	}
}
template <typename T>
void Queue<T>::pop() {
	if (cnt == 0)
		cout << "Queue is empty!\n";
	else {
		arr[front_idx] = NULL;
		front_idx++;
		if (front_idx == 100000)
			front_idx = 0;
		cnt--;
	}
}
template <typename T>
Queue<T>::~Queue() {

}

int main() {
	Queue<int> q;
	cout << q.empty() << '\n';
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << '\n';
	cout << q.back() << '\n';
	q.pop();
	cout << q.front() << '\n';
	cout << q.size() << '\n';
	cout << q.empty() << '\n';
	q.push(7);
	cout << q.front() << '\n';
	cout << q.back() << '\n';

	return 0;
}