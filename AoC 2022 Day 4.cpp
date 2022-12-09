#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

bool checkRangeContainment(std::vector<int> range1, std::vector<int> range2) //part 1
{
	std::vector<int> intersection{};

	if (range1.size() < range2.size())			//sets size of range intersection to the smaller range
		intersection.resize(range1.size());
	else
		intersection.resize(range2.size());

	std::set_intersection(range1.begin(), range1.end(), range2.begin(), range2.end(), intersection.begin());
	
	if (intersection == range1 || intersection == range2)
		return true;							//one of the ranges contains the other
	else
		return false;							//no containment
}

bool checkRangeOverlap(std::vector<int> range1, std::vector<int> range2) //part 2
{
	std::vector<int> intersection{};

	if (range1.size() < range2.size())			//sets size of range intersection to the smaller range
		intersection.resize(range1.size());
	else
		intersection.resize(range2.size());

	std::set_intersection(range1.begin(), range1.end(), range2.begin(), range2.end(), intersection.begin());

	if (intersection[0]==0)
		return false;							//no overlap, vector elements are 0
	else
		return true;							//overlap
}

std::vector<int> getRange(int start, int end)
{
	std::vector<int> range{};
	for (int i = start; i <= end; i++)
	{
		range.push_back(i);
	}
	return range;
}

int main()
{
	std::string s1{},e1{},s2{},e2{};
	int count1{},count2{};
	std::ifstream input{ "input.txt" };
	std::vector<int> range1{}, range2{};
	for (int i = 0; i < 1000; i++)
	{
		std::getline(input, s1, '-');
		std::getline(input, e1, ',');
		std::getline(input, s2, '-');
		std::getline(input, e2, '\n');
		range1 = getRange(stoi(s1), stoi(e1));
		range2 = getRange(stoi(s2), stoi(e2));
		if (checkRangeContainment(range1, range2))
			++count1;
		if (checkRangeOverlap(range1, range2))
			++count2;
	}
	std::cout << "The number of assignment pairs where one range fully contains the other is: " << count1 << '\n';
	std::cout << "The number of overlapping ranges is: " << count2 << '\n';
	system("pause");
	return 0;
}