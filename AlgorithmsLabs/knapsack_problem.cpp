#include <iostream>
#include <vector>
#include <map>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void backpack()
{
    using namespace std;
    int times;
    std::cin >> times;

    std::vector<int> values {0};

    for (int i = 0; i < times; i++)
    {
        int value;
        std::cin >> value;
        values.push_back(value);
    }

    std::vector<int> weights {0};
    for (int i = 0; i < times; i++)
    {
        int weight;
        std::cin >> weight;
        weights.push_back(weight);
    }

    int capacity;
    std::cin >> capacity;
    
    int** array = new int*[values.size()];
    for (int i = 0; i < values.size(); i++)
        array[i] = new int[capacity+1];

    // First row full of zeros
    for (int i = 0; i <= capacity; i++) array[0][i] = 0;   
    for (int row = 1; row < values.size(); row++)
    {
        for (int column = 0; column <= capacity; column++)
        {
            if (weights[row] > column)
                array[row][column] = array[row - 1][column];
            else
            {
                array[row][column] = max(values[row] + array[row - 1][column - weights[row]], array[row - 1][column]);
            }
        }
    }

    int row = values.size() - 1, column = capacity;
    int maxValue = array[row][column];
    std::cout << maxValue << std::endl;
    for (int i = 0; i < values.size(); i++)
        delete[] array[i];
    delete[] array;
}

int main()
{
    for (int k = 0; k < 500; k++)
        backpack();
}
