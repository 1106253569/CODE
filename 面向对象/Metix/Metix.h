#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <vector>
class Metix
{
    //¾ØÕóÏà¼Ó
    friend Metix& operator+(const Metix&, const Metix&);
    //¾ØÕóÏà¼õ
    friend Metix& operator-(const Metix&, const Metix&);
    //¾ØÕóÏà³Ë
    friend Metix& operator*(const Metix&, const Metix&);
    //¾ØÕóÏà³ı
    friend Metix& operator/(const Metix&, const Metix&);

public:
    Metix() = default;                  
    Metix(std::istream&);
    Metix(std::string&);
    bool operator==(const Metix&) const;
    Metix& operator*(int) const;
    
    int Max_line() const { return A.size(); }
    int Max_row() const { return A[0].size(); }
    void push_back(const std::vector<double>& V) { A.push_back(V); }
    const std::vector<double>& operator[](int i) const { return this->A[i]; }
    double Dterminant() const;
    virtual ~Metix()=default;
protected:
    std::vector<std::vector<double>> A;
    void check() const;
};