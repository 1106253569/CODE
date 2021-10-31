#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <vector>
class Metix
{
    //矩阵相加
    friend Metix& operator+(const Metix&, const Metix&);
    //矩阵相减
    friend Metix& operator-(const Metix&, const Metix&);
    //矩阵相乘
    friend Metix& operator*(const Metix&, const Metix&);
    //矩阵相除
    friend Metix& operator/(const Metix&, const Metix&);

public:
    Metix() = default;                  
    Metix(std::istream&);
    Metix(std::string&);
    bool operator==(const Metix&) const;
    Metix& operator*(int) const;
    void check() const;
    int Max_line() const { return A.size(); }
    int Max_row() const { return A[0].size(); }
    void push_back(const std::vector<double>& V) { A.push_back(V); }
    const std::vector<double>& operator[](int i) const { return this->A[i]; }
private:
    std::vector<std::vector<double>> A;
    //矩阵下标取值
    
};



