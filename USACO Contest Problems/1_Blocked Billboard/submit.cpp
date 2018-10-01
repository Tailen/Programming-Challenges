/*
ID: wuximei1
PROG: billboard
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;



int main()
{
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	vector<int> x(6);
	vector<int> y(6);
	for (int i = 0; i < 6; i++) {
		fin >> x[i] >> y[i];
	}
	int x1 = max(x[0], x[4]);
	int y1 = max(y[0], y[4]);
	int x2 = min(x[1], x[5]);
	int y2 = min(y[1], y[5]);
	int x3 = max(x[2], x[4]);
	int y3 = max(y[2], y[4]);
	int x4 = min(x[3], x[5]);
	int y4 = min(y[3], y[5]);
	
	int result = (x[1] - x[0]) * (y[1] - y[0]) + (x[3] - x[2]) * (y[3] - y[2]);
	if ((x1 < x2) && (y1 < y2)) {
		result -= (x2 - x1) * (y2 - y1);
	}
	if ((x3 < x4) && (y3 < y4)) {
		result -= (x4 - x3) * (y4 - y3);
	}

	fout << result << endl;

    return 0;
}

