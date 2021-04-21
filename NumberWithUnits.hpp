#pragma once
#include <iostream>
#include <string>

namespace ariel
{

    class NumberWithUnits
    {

    private:
        //because in demo --> NumberWithUnits a{2, "km"};   // 2 kilometers
        double x;
        std::string units;

    public:
        //constructor
        NumberWithUnits(double num, const std::string &unitnum) : x(num), units(unitnum) {}
        static void read_units(std::ifstream &units_file);

        //6 math opertaors
        NumberWithUnits operator+(const NumberWithUnits &x)const;
        NumberWithUnits &operator+=(const NumberWithUnits &x);
         NumberWithUnits operator+()const;
         NumberWithUnits operator-(const NumberWithUnits &x)const;
         NumberWithUnits &operator-=(const NumberWithUnits &x);
         NumberWithUnits operator-()const; //minus of the number

        //6 comparison operators
        bool operator>(const NumberWithUnits &x)const;
        bool operator>=(const NumberWithUnits &x)const;
        bool operator<(const NumberWithUnits &x)const;
        bool operator<=(const NumberWithUnits &x)const;
        bool operator==(const NumberWithUnits &x)const;
        bool operator!=(const NumberWithUnits &x1)const ;

        //Magnification by 1

        NumberWithUnits operator++(int z);
        NumberWithUnits &operator++();

        //The smaller in 1
        NumberWithUnits operator--(int z);
        NumberWithUnits &operator--();

        //Multiplication

        friend NumberWithUnits operator*(double y, NumberWithUnits &x);

        //----------------------------------
        // friend global IO operators
        //----------------------------------
        //operator input
        friend std::istream &operator>>(std::istream &ins, NumberWithUnits &h);

        //operator output
        friend std::ostream &operator<<(std::ostream &outs, const NumberWithUnits &h);
    };
}