#pragma once
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <vector>
class Matrix
{
    friend Matrix &operator+(const Matrix &, const Matrix &);
    friend Matrix &operator-(const Matrix &, const Matrix &);
    friend Matrix &operator*(const Matrix &, const Matrix &);
    friend Matrix &operator/(const Matrix &, const Matrix &);

public:
    Matrix() = default;
    Matrix(std::istream &);
    
    Matrix &operator*(int) const;
    virtual ~Matrix() = default;
    //行数
    int Max_line() const { return A.size(); }
    //列数
    int Max_row() const { return A[0].size(); }
    //加入一行
    void push_back(const std::vector<double> &V) { A.push_back(V); }
    //取下标
    const std::vector<double> &operator[](int i) const { return this->A[i]; }
    //计算行列式
    double Dterminant() const;
    bool operator==(const Matrix &) const;

protected:
    std::vector<std::vector<double>> A;
    //判断行列相等
    void check() const;
};