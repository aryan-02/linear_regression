// Linear_Regression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Data {
private:
	std::vector<std::pair<double, double>> points;
	double _m{ 0 };
	double _c{ 0 };
public:
	std::vector<std::pair<double, double>> get_points()
	{
		return points;
	}
	void push(std::pair<double, double> point)
	{
		(this->points).push_back(point);
	}
	double predict(double x)
	{
		return ((_m) * (x)) + (_c);
	}
	double sigma_x()
	{
		double sum{ 0 };
		for (auto const& i : points)
		{
			sum += i.first;
		}
		return sum;
	}
	double sigma_y()
	{
		double sum{ 0 };
		for (auto const& i : points)
		{
			sum += i.second;
		}
		return sum;
	}
	double sigma_xy()
	{
		double sum{ 0 };
		for (auto const& i : points)
		{
			sum += ((i.first)*(i.second));
		}
		return sum;
	}
	double sigma_x_sq()
	{
		double sum{ 0 };
		for (auto const& i : points)
		{
			sum += (std::pow((i.first), 2.0f));
		}
		return sum;
	}
	void train()
	{
		double sum_x = sigma_x();
		double sum_y = sigma_y();
		double sum_xy = sigma_xy();
		double sum_x_sq = sigma_x_sq();
		double n = points.size();
		double m_num = (sum_xy - ((sum_x * sum_y)/n));
		double m_den = (sum_x_sq - ((pow((sum_x), 2.0f))/n));
		_m = m_num / m_den;
		_c = (sum_y - (_m * sum_x))/n;
	}
};

int main()
{
	Data dta;
	dta.push({ 0, 0 });
	dta.push({ 1, 1 });
	dta.push({ 2, 2 });
	dta.push({ 3, 3 });
	dta.train();
	double ans = dta.predict(11);
	std::cout << "The model predicted " << ans << std::endl;
}
