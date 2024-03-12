#include <iostream>
#include <string>
#include <vector>

using namespace std;

const static int MAX_NUMBER_OF_OBJECTS = 100;

void add_object_to_game(vector<int>& coordinates_x, vector<int>& coordinates_y, const string& object_name)
{
	if (coordinates_x.size() > MAX_NUMBER_OF_OBJECTS)
	{
		cout << "Maximum number of " << object_name << " exceeded." << endl;
	}
	else
	{
		int new_x, new_y;
		cin >> new_x >> new_y;
		coordinates_x.push_back(new_x);
		coordinates_y.push_back(new_y);
	}
}
