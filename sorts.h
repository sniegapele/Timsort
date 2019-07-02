#pragma once

#include <vector>
#include <algorithm>

const int SIZE = 32;

template<typename T>
void insertion_sort(std::vector<T> &values, int left, int right) {
	for (int i = left; i <= right; ++i) {
		T temp = values[i];
		int j;
		for (j = i - 1; j >= left; --j) {
			if (values[j] > temp)
				values[j + 1] = values[j];
			else break;
		}
		values[j + 1] = temp;
	}
}

template<typename T>
void merge(std::vector<T>& values, std::vector<T>& first, std::vector<T>& second, int start_position) {
	int i = start_position;
	int j = 0; //first
	int k = 0; //second

	while (j < first.size() && k < second.size()) {
		if (first[j] <= second[k]) {
			values[i] = first[j];
			++i;
			++j;
		}
		else {
			values[i] = second[k];
			++i;
			++k;
		}
	}

	while (j < first.size()) {
		values[i] = first[j];
		++i;
		++j;
	}

	while (k < second.size()) {
		values[i] = second[k];
		++i;
		++k;
	}
}

template<typename T>
void merge_sort(std::vector<T>& values, int first_first, int second_first, int second_last) {
	std::vector<T> first;
	std::vector<T> second;
	for (int i = first_first; i < second_first; ++i)
		first.push_back(values[i]);
	for (int i = second_first; i <= second_last; ++i)
		second.push_back(values[i]);
	merge(values, first, second, first_first);
}

template<typename T>
void my_sort(std::vector<T>& values) {
	int n = values.size();
	for (int i = 0; i < n; i += SIZE)
		insertion_sort(values, i, std::min((i + SIZE - 1), (n - 1)));
	
	if (n > SIZE) {
		for (int size = SIZE; size < n; size *= 2) {
			for (int i = 0; i < n; i += 2 * size) {
				if (n - i > size)
					merge_sort(values, i, i + size, std::min((i + 2 * size - 1), (n - 1)));
			}
		}
	}
}
