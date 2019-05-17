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
typedef pair<double, pair<double, double>> Pa;

// distance, x좌표, y좌표, id, name

P arr[5001];
P start, destination;
priority_queue<Pa> pq;
bool visit[5001];
vector<P> route;

void makeCandidate(P curPoint, int midsize);
double calculateDist(P a, P b);

int dataSetting(vector<P> data);

int main() {
	vector<P> ret;

	int midsize = dataSetting(ret);
	int sum = 0;

	// arr[0]가 시작점이라고 가정
	start = arr[0];
	destination = arr[midsize - 1];

	pq.push({ calculateDist(start, destination), {start.first, start.second} });
	visit[0] = 1;

	while (1) {
		Pa cur;
		cur.first = pq.top().first; // 현재까지 누적된 거리
		cur.second.first = pq.top().second.first; // x
		cur.second.second = pq.top().second.second; // y

		while (!pq.empty())
			pq.pop();

		route.push_back({ cur.second.first, cur.second.second }); // 경로 저장

		P ptr = { cur.second.first, cur.second.second };

		if (calculateDist(ptr, destination) < ENERGY) {
			break;
		}
		else {
			makeCandidate(ptr, midsize);
		}
	}
	route.push_back({ destination.first, destination.second });

	
	// url 제작
	string naverUrl = "http://map.naver.com/?menu=route&";
	naverUrl = naverUrl + "&slng=" + std::to_string(route.front().first) + "&slat=" + std::to_string(route.front().second);

	for (int i = 1; i + 1 < route.size(); ++i) {
		string varCoordStr = "&t" + std::to_string(i) + "lng=" + to_string(route[i].first) + "&t" + std::to_string(i) + "lat=" + to_string(route[i].second);
		naverUrl = naverUrl + varCoordStr;
	}

	naverUrl = naverUrl + "&" + "elng=" + to_string(route.back().first) + "&elat=" + to_string(route.back().second);
	
	const char *resUrl = naverUrl.c_str();

	ShellExecute(NULL, NULL, "C:\Program Files (x86)\Google\Chrome\Application/chrome.exe", resUrl, NULL, SW_HIDE);

	return 0;
}

double calculateDist(P a, P b) {
	return sqrt((a.first - b.first) * (a.first - b.first)
		+ (a.second - b.second) * (a.second - b.second));
}

void makeCandidate(P curPoint, int midsize) {
	for (int i = 1; i < midsize - 1; i++) {
		if (!visit[i]) {
			double val = calculateDist(curPoint, arr[i]);
			if (val < ENERGY) {
				visit[i] = 1;
				pq.push({ val, {arr[i].first, arr[i].second} });
			}
		}
	}
}

int dataSetting(vector<P> data) {
	int datasize = data.size();
	for (int i = 0; i < datasize; i++) {
		arr[i].first = data[i].first;
		arr[i].second = data[i].second;
	}
	return datasize;
}