#include "sorts.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
	srand(time(nullptr));
	vector<int> m;
	for (int i = 0; i < 1000; ++i)
		m.push_back(rand());
	my_sort<int>(m);
	for (int i = 0; i < m.size(); ++i) 
		cout << m[i] << " ";
	cout << endl << "-----------------------------------" << endl;
	vector<char> r;
	for (char c = 40; c < 100; ++c)
		r.push_back(c);
	my_sort<char>(r);
	for (int i = 0; i < r.size(); ++i)
		cout << r[i] << " ";
	return 0;
}