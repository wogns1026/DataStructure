#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <string>
#include <fstream>
#include <json/json.h>
#include <curl/curl/curl.h>
#include <functional>
#include <cmath>

#define ENERGY 1

using namespace std;

typedef pair<double, double> P;
typedef pair<double, int> Pa;

// distance, x좌표, y좌표, id, name

struct Node {
	P xy;
	int idx;
	Node *prev;

	Node() {
		idx = 0;
		xy.first = 0, xy.second = 0;
	}
};

Node arr[5001];
Node start, destination;
int visit[5001];
priority_queue<Pa, vector<Pa>, greater<Pa>> pq;

double calculateDist(Node a, Node b) {
	return sqrt((a.xy.first - b.xy.first) * (a.xy.first - b.xy.first)
		+ (a.xy.second - b.xy.second) * (a.xy.second - b.xy.second));
}
void makeCandidate(int curPoint, int midsize) {
	vector<int> candi;
	for (int i = 1; i < midsize - 1; i++) {
		if (!visit[i]) {

			// 평가함수는 시작점부터 경유지를 거쳐 도착지까지 가는 거리(좌표값에 대한 값이라 오차가 있는듯)

			double val = calculateDist(arr[curPoint], arr[i]); // 현재에서 다음후보까지의 거리
			double dist = 0; 
			// 시작점부터 현재점까지의 거리
			for (Node *ptr = &arr[curPoint]; ; ptr = ptr->prev) {
				if (ptr->prev == nullptr) {
					break;
				}
				else {
					dist += calculateDist(arr[ptr->idx], arr[ptr->prev->idx]);
				}
			}
			// 다음 후보에서 도착점까지의 거리
			dist += calculateDist(arr[i], destination);

			if (val < ENERGY) {
				visit[i] = 1;
				pq.push({ val + dist, i });
				arr[i].prev = &arr[curPoint];
			}
		}
	}
}

int dataSetting(vector<P> data) {
	int datasize = data.size();
	for (int i = 0; i < datasize; i++) {
		arr[i].xy.first = data[i].first;
		arr[i].xy.second = data[i].second;
	}

	return datasize;
}

int main() {
	/*ifstream stream;
	stream.open("Test.json");
	Json::Value root;
	stream >> root;

	Json::Value item = root["id"];*/
	
	vector<P> ret;
	int midsize = dataSetting(ret);// item.size();

	// arr[0]가 시작점이라고 가정
	start = arr[0];
	destination = arr[midsize - 1];

	pq.push({ calculateDist(start, destination), 0 });
	visit[0] = 1;

	vector<P> route;

	while (1) {
		Pa cur;
		cur.first = pq.top().first; // 이전 거리
		cur.second = pq.top().second; // 인덱스
		pq.pop();

		double res = calculateDist(arr[cur.second], destination);
		if (res < ENERGY) {
			arr[midsize - 1].prev = &arr[cur.second];
			break;
		}
		else {
			makeCandidate(cur.second, midsize);
		}
	}

	for (Node *ptr = &arr[n-1]; ; ptr = ptr->prev) {
		if (ptr == nullptr) {
			break;
		}
		else {
			route.push_back(ptr->xy);
		}
	}
	reverse(route.begin(), route.end());

	// url 제작
	string naverUrl = "http://map.naver.com/?menu=route&";
	naverUrl = naverUrl + "&slng=" + std::to_string(route.front().first) + "&slat=" + std::to_string(route.front().second);

	for (int i = 1; i + 1 < route.size(); ++i) {
		string varCoordStr = "&t" + std::to_string(i) + "lng=" + to_string(route[i].first) + "&t" + std::to_string(i) + "lat=" + to_string(route[i].second);
		naverUrl = naverUrl + varCoordStr;
	}

	naverUrl = naverUrl + "&" + "elng=" + to_string(route.back().first) + "&elat=" + to_string(route.back().second);

	return 0;
}

