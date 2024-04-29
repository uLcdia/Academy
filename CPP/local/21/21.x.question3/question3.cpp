// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/

#include <iostream>
#include <cassert>

class IntArray
{
public:
    IntArray(const IntArray& source)
        : m_size {source.m_size}
        , m_pArray {new int[source.m_size] {}}
    {}

    explicit IntArray(const int size)
        : m_size {size}
        , m_pArray {new int[size] {}}
    {
        assert(size > 0);
    }

    ~IntArray()
    {
        delete[] m_pArray;
    }

    int& operator[] (const int index) const
    {
        assert(index >= 0);
        assert(index < m_size);
        return m_pArray[index];
    }

    IntArray& operator= (const IntArray& source)
    {
        // assert(m_size == source.m_size);

        if (this == &source)
        {
            return *this;
        }

        delete[] m_pArray;

        m_size = source.m_size;
        m_pArray = new int[m_size] {};

        for (int i {0}; i < source.m_size; ++i)
        {
            m_pArray[i] = source.m_pArray[i];
        }

        return *this;
    }

    friend std::ostream& operator<< (std::ostream& out, const IntArray& source)
    {
        for (int i {0}; i < source.m_size; ++i)
        {
            out << source.m_pArray[i];
        }

        return out;
    }
private:
    int m_size {};
    int* m_pArray {};
};

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}