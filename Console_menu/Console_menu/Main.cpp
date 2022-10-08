#include "Menu.h"

int main() {
	Menu menu = Menu(
			Board({
				Button(TYPE::common_value, "First", {}, Board({
					Button(TYPE::common_value, "First1", {}, Board({
						Button(TYPE::common_choose, "aFirst11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "aFirst22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "aFirst33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_choose, "First2", {"111", "222", "333", "444"}, Board({
						Button(TYPE::common_choose, "bFirst11", {"11", "22", "33", "444", "5555", "66666", "777777", "8888888", "9999999"}, Board()),
						Button(TYPE::common_choose, "bFirst22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "bFirst33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_choose, "First3", {"1111", "2222", "3333", "4444", "5555"}, Board({
						Button(TYPE::common_choose, "cFirst11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "cFirst22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "cFirst33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_end, "Exit from menu", {}, Board()),
				})),
				Button(TYPE::common_choose, "Second", {"1", "2", "3"}, Board({
					Button(TYPE::common_choose, "Second1", {"11", "22", "33"}, Board({
						Button(TYPE::common_choose, "aSecond11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "aSecond22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "aSecond33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_choose, "Second2", {"111", "222", "333"}, Board({
						Button(TYPE::common_choose, "bSecond11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "bSecond22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "bSecond33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_choose, "Second3", {"1111", "2222", "3333"}, Board({
						Button(TYPE::common_choose, "cSecond11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "cSecond22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "cSecond33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_end, "Exit from menu", {}, Board()),
				})),
				Button(TYPE::common_choose, "Three", {"1", "2", "3"}, Board({
					Button(TYPE::common_choose, "Three1", {"11", "22", "33"}, Board({
						Button(TYPE::common_choose, "aThree11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "aThree22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_value, "aThree33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_choose, "Three2", {"111", "222", "333"}, Board({
						Button(TYPE::common_choose, "bThree11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "bThree22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "bThree33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_choose, "Three3", {"1111", "2222", "3333"}, Board({
						Button(TYPE::common_choose, "cThree11", {"11", "22", "33"}, Board()),
						Button(TYPE::common_choose, "cThree22", {"111", "222", "333"}, Board()),
						Button(TYPE::common_choose, "cThree33", {"1111", "2222", "3333"}, Board()),
						Button(TYPE::common_end, "Exit from menu", {}, Board()),
					})),
					Button(TYPE::common_end, "Exit from menu", {}, Board()),
				})),
				Button(TYPE::common_end, "Exit from program", {}, Board()),
			}
		)
	);	
	menu.change_clear_method(CLEAR::_auto);
	menu.change_return_every_iteration(false);
	menu.change_switch_time(15);
	menu.enable();
	return 0;
}