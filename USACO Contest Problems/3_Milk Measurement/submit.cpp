/*
ID: wuximei1
PROG: measurement
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;



int main() {
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int num;
	fin >> num;
	vector<int> milk = { 7, 7, 7 }; //Bessie, Elsie, Mildred
	vector<int> date(num);
	vector<int> order(num);
	vector<string> name(num);
	vector<int> id(num);
	vector<int> change(num);
	vector<bool> winner = { false, false, false };
	for (int i = 0; i < num; i++) {
		fin >> date[i] >> name[i] >> change[i];
	}
	//record order of dates
	int current_min = 101;
	int current_index;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (date[j] < current_min) {
				current_min = date[j];
				current_index = j;
			}
		}
		order[i] = current_index;
		date[current_index] = 101;
		current_min = 101;
	}
	//name to id of cows
	for (int i = 0; i < num; i++) {
		if (name[i] == "Bessie") {
			id[i] = 0;
		}
		if (name[i] == "Elsie") {
			id[i] = 1;
		}
		if (name[i] == "Mildred") {
			id[i] = 2;
		}
	}

	int max, output = 0;
	bool temp;
	bool changed = false;
	for (int i = 0; i < num; i++) {
		//update milk
		milk[id[order[i]]] += change[order[i]];
		//check winner
		max = *max_element(milk.begin(), milk.end());
		for (int j = 0; j < 3; j++) {
			if (milk[j] == max) {
				temp = true;
			}
			if (temp != winner[j]) {
				changed = true;
			}
			temp = false;
		}
		for (int j = 0; j < 3; j++) {
			if (milk[j] == max) {
				winner[j] = true;
			} else {
				winner[j] = false;
			}
		}

		if (changed) {
			output++;
		}
		changed = false;
	}
	
	fout << output << endl;

	return 0;
}