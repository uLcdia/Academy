#include <iostream>
#include <vector>
#include <algorithm>

class Matrix
{
public:
    // constructor
    Matrix(int row, int col)
        : m_row {row}, m_col {col}
    {
        m_vector.reserve(row * col); // flatten the matrix
    }

    // move constructor
    Matrix(Matrix&& other) noexcept
        : m_row {other.m_row}, m_col {other.m_col}, m_vector {std::move(other.m_vector)}
    {
        other.m_row = 0;
        other.m_col = 0;
    }


    // get Num from flattened matrix
    int getNum(int index) const
    {
        return m_vector[index];
    }

    int getRow() const
    {
        return m_row;
    }

    int getCol() const
    {
        return m_col;
    }

    // input the matrix
    void input();


    // get Num using matrix(i, j)
    double operator() (int i, int j) const;

    // return true if lhs == rhs, false otherwise
    friend bool operator== (const Matrix& lhs, const Matrix& rhs);
    
    // ostream << matrix
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);

    friend Matrix operator+ (const Matrix& lhs, const Matrix& rhs);

private:
    [[maybe_unused]] int m_row {};
    [[maybe_unused]] int m_col {};

    std::vector<double> m_vector {};
};

void Matrix::input()
{
    double value {};
    auto size {m_col * m_row};
    for (int i {}; i < size; ++i)
    {
        std::cin >> value;
        m_vector.emplace_back(value);
    }
}

double Matrix::operator() (int i, int j) const
{
    return m_vector[i * m_col + j];
}

bool operator== (const Matrix& lhs, const Matrix& rhs)
{
    return std::ranges::equal(lhs.m_vector, rhs.m_vector);

    /*
    // if the row and col are not the same, return false
    if ((lhs.m_col != rhs.m_col) || (lhs.m_row != rhs.m_row))
    {
        return false;
    }

    auto size {std::ssize(lhs.m_vector)};

    for (int i {}; i < size; ++i)
    {
        if (lhs.getNum(i) != rhs.getNum(i))
        {
            return false;
        }
    }

    return true;
    */
}

std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
    int rows = matrix.getRow();
    int cols = matrix.getCol();

    for (int i {}; i < rows; ++i)
    {
        for (int j {}; j < cols; ++j)
        {
            out << matrix(i, j) << ' ';
        }

        out << '\n';
    }
    
    return out;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs)
{
    Matrix sum {lhs.getRow(), lhs.getCol()};

    auto size {std::ssize(lhs.m_vector)};

    for (int index {}; index < size; ++index)
    {
        sum.m_vector[index] += lhs.getNum(index);
        sum.m_vector[index] += rhs.getNum(index);
    }

    return sum; // Return Value Optimization triggers here
}

int main()
{
    int row1 {};
    int col1 {};
    std::cin >> row1 >> col1;
    Matrix table1 {row1, col1};
    table1.input();

    int row2 {};
    int col2 {};
    std::cin >> row2 >> col2;
    Matrix table2 {row2, col2};
    table2.input();


    std::cout << table1(row1 / 2, col1 / 2) << '\n';

    std::cout << (table1 + table2);

    std::cout << ((table1 == table2) ? "两个矩阵相等！" : "两个矩阵不相等！");

    return 0;
}