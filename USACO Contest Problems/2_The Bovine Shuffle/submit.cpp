/*
ID: wuximei1
PROG: shuffle
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;



int main() {
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int num;
	fin >> num;
	vector<int> order(num);
	vector<int> id(num + 1);
	vector<int> output(num + 1);
	id[0] = 0;
	output[0] = 0;
	for (int i = 0; i < num; i++) {
		fin >> order[i];
	}
	for (int i = 1; i < num + 1; i++) {
		fin >> id[i];
	}
	for (int i = 1; i < num + 1; i++) {
		output[i] = id[order[i-1]];
	}
	for (int i = 1; i < num + 1; i++) {
		id[i] = output[order[i-1]];
	}
	for (int i = 1; i < num + 1; i++) {
		output[i] = id[order[i-1]];
	}
	//output
	for (int i = 1; i <= num; i++) {
		fout << output[i] << endl;
	}

	return 0;
}

