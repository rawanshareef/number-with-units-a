#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};

TEST_CASE("all the first operators")
{
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a(3, "m");
    NumberWithUnits b(40, "cm");
    CHECK_EQ(a + b, NumberWithUnits{3.4, "km"});
    CHECK_THROWS(a + b);

    NumberWithUnits c(1, "hour");
    NumberWithUnits d(40, "min");
    CHECK_EQ(c + d, NumberWithUnits{100, "min"});
    CHECK_THROWS(c + d);

    CHECK_EQ(c - d, NumberWithUnits{20, "min"});
    CHECK_THROWS(c - d);

    NumberWithUnits c2(0.5, "hour");
    NumberWithUnits d2(30, "min");
    CHECK_EQ(c2 + d2, NumberWithUnits{1, "hour"});
    CHECK_THROWS(c2 + d2);

    CHECK_EQ(c2 + d2, NumberWithUnits{60, "min"});
    CHECK_THROWS(c2 + d2);

    CHECK_EQ(c2 - d2, NumberWithUnits{0, "min"});
    CHECK_THROWS(c2 + d2);

    NumberWithUnits e(1, "ton");
    NumberWithUnits f(1000, "kg");
    CHECK_EQ(e + f, NumberWithUnits{2000, "kg"});
    CHECK_THROWS(e + f);

    CHECK_EQ(e - f, NumberWithUnits{0, "kg"});
    CHECK_THROWS(e - f);
}

TEST_CASE("all the second operators")
{

    NumberWithUnits a(1, "m");
    NumberWithUnits b(100, "cm");
    CHECK_THROWS(a.operator==(b));

    NumberWithUnits c(1, "hour");
    NumberWithUnits d(40, "min");
    CHECK_THROWS(c.operator>(d));
    CHECK_THROWS(c.operator>=(d));
    CHECK_THROWS(c.operator!=(d));
    CHECK_THROWS(d.operator<(c));
    CHECK_THROWS(d.operator<=(c));

    NumberWithUnits c2(0.5, "hour");
    NumberWithUnits d2(30, "min");
    CHECK_THROWS(c.operator==(d));
    CHECK_THROWS(c.operator>=(d));
    CHECK_THROWS(c.operator<=(d));

    NumberWithUnits e(1, "ton");
    NumberWithUnits f(1000, "kg");
    CHECK_THROWS(e.operator==(f));
    CHECK_THROWS(e.operator<=(f));
    CHECK_THROWS(e.operator>=(f));

}