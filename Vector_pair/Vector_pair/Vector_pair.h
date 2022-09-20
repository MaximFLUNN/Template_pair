#pragma once

#include "Menu.h"

enum class state : int { _public, _protected, _private };

template <class T>
struct states {
	int _public;
	int _protected;
	int _private;
	T min_value;
	T max_value;
	int size;
};

template <class T>
class Vector_pair {
private:
	states<T> answer;
	std::vector <std::pair<state, T>> arr;

public:
	Vector_pair() {
		arr.resize(50);
		generation();
	}

	Vector_pair(int size) {
		arr.resize(0);
		arr.resize(size);
		generation();
	}

	Vector_pair(const Vector_pair& vec) {
		answer = vec.answer;
		arr = vec.arr;
	}

	void generation() {
		for (auto it = begin(arr); it != end(arr); it++) {
			int rand_choose = rand() % 3 + 1;
			rand_choose == 2 || rand_choose == 3 ? rand_choose == 2 ? (*it).first = state::_protected : (*it).first = state::_private : (*it).first = state::_public;
			(*it).second = static_cast<T>((rand() % 500 + 1) * 0.1);
		}
	}

	void resize(int size) {
		arr.resize(0);
		arr.resize(size);
	}

	states<T> return_short_info() {
		answer = states<T>();
		if (arr.size() > 0) {
			answer.min_value = arr[0].second;
			answer.max_value = arr[0].second;
		}
		for (const auto& elem : arr) {
			elem.first == state::_public ? answer._public++ : elem.first == state::_protected ? answer._protected++ : answer._private++;
			if (elem.second > answer.max_value) { answer.max_value = elem.second; }
			if (elem.second < answer.min_value) { answer.min_value = elem.second; }
		}
		answer.size = arr.size();
		return answer;
	}

	void print_table() {
		for (const auto& elem : arr) {
			std::cout << typeName(elem.first) << " | " << elem.second << "\n";
		}
	}

	std::string typeName(enum state table) {
		return table == state::_public ? "public" : table == state::_protected ? "protected" : "private";
	}

	void search(int iterator) {
		int count = 0;
		auto replace = [&count, &iterator](auto &elem) {
			if (elem.first == state::_public && iterator == 0) { 
				elem.second = 0;
				count++;
			}
			else if (elem.first == state::_protected && iterator == 1) {
				elem.first = state::_private;
				count++;
			}
			else if (elem.first == state::_private && iterator == 2) {
				elem.second = static_cast<T>((rand() % 500 + 1) * 0.1);
				count++;
			}
		};
		for (auto& elem : arr) {
			replace(elem);
		}
		std::cout << "Найдено: " << count << " шт";
	}
};
