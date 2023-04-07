#pragma once
#include<iostream>
class CalendaristicDate {
public:
	friend std::ostream& operator<<(std::ostream& output, const  CalendaristicDate& c) {
		output << c.zi<<" " << c.luna<<" " << c.an;
		return output;
	}
	friend std::istream& operator>>(std::istream& input, CalendaristicDate& c) {
		input >> c.zi >>c.luna >> c.an;
		return input;
	}
	CalendaristicDate(int a, int b, int c);
	CalendaristicDate() = default;
	int zi;
	int luna;
	int an;
};