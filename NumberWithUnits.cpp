#include "NumberWithUnits.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace ariel
{

    void NumberWithUnits::read_units(ifstream &units_file)
    {
        cout << "";
    }

    //6 math opertaors
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &x)const
    {
        return {0, ""};
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &x)
    {
        return *this;
    }
     NumberWithUnits NumberWithUnits::operator+()const
    {
        return {x, ""};
    }
     NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &x)const
    {
   
        NumberWithUnits a(2, "km");
                return a;
    }    
     
     NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &x)
    {
        return *this;
    }
     NumberWithUnits NumberWithUnits::operator-()const
    {
        return {-x, ""};
    }

    //6 comparison operators
    bool NumberWithUnits::operator>(const NumberWithUnits &x)const
    {
        return true;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &x)const
    {
        return false;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &x)const
    {
        return true;
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &x)const
    {
        return false;
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &x)const
    {
        return true;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &x1)const
    {
        return true;
    }

    //Magnification by 1

    NumberWithUnits NumberWithUnits::operator++(int z)
    {
        return {0, ""};
    }
    //The smaller in 1
    NumberWithUnits NumberWithUnits::operator--(int z)
    {
        return {0, ""};
    }

    //Multiplication

    NumberWithUnits operator*(double y, NumberWithUnits &x)
    {
        return {0, ""};
    }

    //operator input
    istream &operator>>(std::istream &ins, NumberWithUnits &h)
    {
        return ins >> h.units >> h.x;
    }

    //operator output
    ostream &operator<<(ostream &outs, const NumberWithUnits &h)
    {
        return outs << h.x << h.units;
    }

}