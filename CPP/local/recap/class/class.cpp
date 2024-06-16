#include <iostream>

template <typename T>
class Goo
{
public:
    static void increseValue(T value)
    {
        s_inline += value;
    }

    static T getValue()
    {
        return s_inline;
    }
private:
    static inline T s_inline {10}; // preferred
    static constexpr int s_constexpr {5}; // preferred
    // static int s_value; // "declare" static int
    // static const int s_const {20};
};

// int Goo<int>::s_value {15}; // define static int

class Bar;

class Foo
{
public:
    // Default constructor
    explicit Foo(int value, int allocated)
        : m_value {value}
        , m_allocated {new int {allocated}}
    {}

    // copy constructor (deep copy)
    Foo(const Foo& other)
        : m_value {other.m_value}
        , m_allocated {new int {*other.m_allocated}}
    {}

    // move constructor
    Foo(Foo&& other) noexcept
        : m_value {other.m_value}
        , m_allocated {other.m_allocated}
    {
        other.m_allocated = nullptr;
    }

    // copy assignment
    Foo& operator=(const Foo& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        m_value = rhs.m_value;
        delete m_allocated;
        m_allocated = new int {*rhs.m_allocated};

        return *this;
    }

    // move assignment
    Foo& operator=(Foo&& rhs) noexcept
    {
        if (this == &rhs)
        {
            return *this;
        }

        m_value = rhs.m_value;
        delete m_allocated;
        m_allocated = rhs.m_allocated;
        rhs.m_allocated = nullptr;

        return *this;
    }

    int getBarMValue(const Bar& source) const;

private:
    int m_value {};
    int* m_allocated {};
};

class Bar
{
public:
    // Bar() = default;
    // Bar() = delete; // error: the default constructor of "Bar" cannot be referenced -- it is a deleted function
    Bar(int value)
        : m_value {value}
    {
        std::cout << "default constructor";
    }

    // arithmetic +
    friend Bar operator+(const Bar& lhs, const Bar& rhs)
    {
        return Bar(lhs.m_value + rhs.m_value);
    }

    // stream <<
    friend std::ostream& operator<<(std::ostream& out, const Bar& rhs)
    {
        out << rhs.m_value;
        return out;
    }

    // increment ++ prefix
    Bar& operator++()
    {
        ++m_value;
        return *this;
    }

    // increment ++ postfix
    Bar operator++(int) // int serves as a dummy parameter to differentiate between prefix and postfix
    {
        Bar temp {*this};
        ++(*this);
        return temp;
    }

    // subscript []
    int& operator[]([[maybe_unused]] int value)
    {
        ++value; // not an array, value is just a dummy
        return m_value;
    }

    // parenthesis ()
    int& operator()(int value)
    {
        return (m_value += value);
    }

    // typecast int
    explicit operator int() const
    {
        return m_value;
    }

    friend int friendBar(const Bar& source);

    // friend class Foo;
    friend int Foo::getBarMValue(const Bar& source) const;

private:
    int m_value {};
};

int friendBar(const Bar& source)
{
    return source.m_value;
}

int Foo::getBarMValue(const Bar& source) const
{
    return source.m_value;
}

int main()
{
    std::cout << "Goo<int> value: " << Goo<int>::getValue() << std::endl;
    Goo<int>::increseValue(10);
    std::cout << "Goo<int> value: " << Goo<int>::getValue() << std::endl;

    std::cout << "Goo<double> value: " << Goo<double>::getValue() << std::endl;
    Goo<double>::increseValue(-10);
    std::cout << "Goo<double> value: " << Goo<double>::getValue() << std::endl;

    Goo<int> goo {};
    std::cout << "goo value: " << goo.getValue() << std::endl;

    return 0;
}