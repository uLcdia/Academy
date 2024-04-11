// swap column and row for 3x3 array

#include <iostream>
#include <vector>


template <int length>
class Array
{
public:
    void run()
    {
        array_m.resize(length);
        for(auto &inner: array_m)
        {
            inner.reserve(length);
        }   
        input();
        swap();
        print();
    }
private:
    std::vector<std::vector<int>> array_m {};

    void input()
    {
        int temp {};
        for (int i {0}; i < length; i++)
        {
            for (int j {0}; j < length; j++)
            {
                std::cin >> temp;
                array_m[i].emplace_back(temp);
            }
        }
    }

    void print() const
    {
        for (std::vector<int> i : array_m)
        {
            for (int item : i)
            {
                std::cout << item << ' ';
            }
            std::cout << std::endl;
        }
    }

    void swap()
    {
        int exchangeTemp {};
        for (int i {0}; i < length; i++)
        {
            for (int j {i + 1}; j < length; j++)
            {
                exchangeTemp = array_m[j][i];
                array_m[j][i] = array_m[i][j];
                array_m[i][j] = exchangeTemp;
            }
        }
    }
};

int main()
{
    Array<3> array3 {};
    array3.run();

    return 0;
}