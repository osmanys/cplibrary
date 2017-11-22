#include <bits/stdc++.h>

using namespace std;

class Point{
	public:
		int label;
		int x;
		int y;
};

bool compare(Point a, Point b){ return (a.x > b.x) || ((a.x == b.x) && (a.y > b.y)); }

int main(){
	int n, u, v, x, y;
	scanf("%d", &n);
	vector<Point> points(n);
	for(int i = 0; i < n - 1; i++)
		scanf("%d %d", &u, &v);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		points[i].label = i + 1;
		points[i].x = x;
		points[i].y = y;
	}
	sort(points.begin(), points.end(), compare);
	for(int i = 0; i < n; i++){
		printf("%d ", points[i].label);
	}
	
	return 0;
}
