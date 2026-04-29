#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix
{
private:
    int rows, cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(const int r, const int c)
        : rows(r), cols(c), data(r, std::vector<double>(c, 0.0))
    {}

    [[nodiscard]] int get_rows() const
    {
        return rows;
    }

    void set_rows(const int rows)
    {
        this->rows = rows;
    }

    [[nodiscard]] int get_cols() const
    {
        return cols;
    }

    void set_cols(const int cols)
    {
        this->cols = cols;
    }

    [[nodiscard]] std::vector<std::vector<double>> get_data() const
    {
        return data;
    }

    void set_data(const std::vector<std::vector<double>>& data)
    {
        this->data = data;
    }

    double& operator()(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range(" Index out of bounds ");
        return data[r][c];
    }

    const double& operator()(int r, int c) const {
        return data[r][c];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument(" Matrix dimensions must match for addition ");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] * scalar;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                os << m.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }
};