
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

#include "doctest.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

    TEST_CASE("Wrong Values")
    {
        CHECK_THROWS(Fraction(7,0));
    }

    TEST_CASE("Values Test")
    {
        Fraction a(10,7);
        CHECK(a.getN() == 10);
        CHECK(a.getD() == 7);
    }

    TEST_CASE(" + / += / - / -= / * / div Test")
    {
        Fraction a(5,3), b(14,21);
        CHECK((a+b).getN() == 7);
        CHECK((a+b).getD() == 3);

        CHECK((b+a).getN() == 7);
        CHECK((b+a).getD() == 3);

        CHECK((a+b) == Fraction(7,3));

        CHECK((a-b) == Fraction(1,1));

        CHECK((Fraction(10,2)-Fraction(6,2)+Fraction(1,1)) == Fraction(3,1));

        CHECK((Fraction(10,2)*Fraction(6,2)+Fraction(1,1)) == Fraction(16,1));

        CHECK((Fraction(10,2)/Fraction(4,2)+Fraction(1,1)) == Fraction(7,2));

    }
    TEST_CASE(" pre and post fix Test")
    {
        Fraction a(5,3), b(14,21);

        CHECK((++a) == Fraction(8,3));
        CHECK((a++) == Fraction(8,3));
        CHECK(a == Fraction(11,3));

        CHECK((--b) == Fraction(-1,3));
        CHECK((b--) == Fraction(-1,3));
        CHECK(b == Fraction(-4,3));
    }
    TEST_CASE(" > / >= / < / <= Test")
    {
        Fraction a(5,3), b(14,21);
        CHECK((a>b) == true);
        CHECK((b<a) == true);
        Fraction c(5,3);
        CHECK((a<=c )== true);
        CHECK((a == c) == true);
        CHECK((c > a) == false);
    }

    TEST_CASE(" incoding demo test")
    {
        Fraction a(5,3), b(14,21),c(2,4);
        CHECK( a+2.421 == Fraction(12263,3000));
        CHECK( a+c == Fraction(13,6));
        CHECK( b+1.12 == Fraction(134,75));
        CHECK( 1.12+b == Fraction(134,75));

        CHECK( a-2.421 == Fraction(-2263,3000));
        CHECK( a-c == Fraction(7,6));
        CHECK( c-a == Fraction(-7,6));

        CHECK( a*2.421 == Fraction(807,200));
        CHECK( a*c == Fraction(5,6));

        CHECK( a/2.421 == Fraction(5000,7263));
        CHECK( a/c == Fraction(10,3));

        CHECK( a++ == Fraction(5,3));
        CHECK( ++a == Fraction(11,3));

        CHECK( c-- == Fraction(1,2));
        CHECK( --c == Fraction(-3,2));

        stringstream stream1("7/5");
        Fraction temp1;
        stream1 >> temp1;

        CHECK( temp1 == Fraction(7,5));

        stringstream stream2("a/5");
        Fraction temp2;
        CHECK_THROWS(stream2 >> temp2);
    }
    