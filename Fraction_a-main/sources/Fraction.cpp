#include "Fraction.hpp"

namespace ariel
{

    int findGCD(int num1, int num2)
    {
        int gcd;
        for(int i=1; i <= num1 && i <= num2; i++)
        {
            if(num1%i==0 && num2%i==0)
                gcd = i;
        }
        return gcd;
    }

    Fraction floatToFraction(float f) {
        
        int precision = 1000;               // adjust the precision as 3 numbers after decimal point
        int num = round(f * precision);     // multiplying the float by a precision value
        int den = precision;
        int gcdVal = findGCD(num, den);     // reduces the resulting numerator and denominator to their lowest terms using gcd
        num /= gcdVal;
        den /= gcdVal;

        return Fraction(num,den);
    }


    
    Fraction::Fraction(int n,int d){
        if(d == 0){
            throw invalid_argument("Denominator cannot be zero!");
        }
        int gcd = findGCD(abs(n),abs(d));
        
        this->numerator = n/gcd;
        this->denominator = d/gcd;
    }

    Fraction::Fraction(){}

    /* + */
    Fraction operator+(const Fraction& a, const Fraction& b){

        int den = a.denominator * b.denominator;
        int num = ( ((den/a.denominator)*a.numerator) + ((den/b.denominator)*b.numerator) );
        int gcdNumDen = findGCD(num, den);
        num /= gcdNumDen;
        den /= gcdNumDen;
        return Fraction(num , den);
    }
    Fraction operator+(const Fraction& a, float b){
    /* convert the flaot number into a fraction and use the above funtion to make the add */
        return (a+(floatToFraction(b)));
    }

    Fraction operator+(float a, const Fraction& b){
    /* same as above */
        return ((floatToFraction(a))+ b);
    }

    /* - */
    Fraction operator-(const Fraction& a, const Fraction& b){
        int den = a.denominator * b.denominator;
        int num = ( ((den/a.denominator)*a.numerator) - ((den/b.denominator)*b.numerator) );
        int gcdNumDen = findGCD(abs(num), abs(den));
        num /= gcdNumDen;
        den /= gcdNumDen;

        return Fraction(num , den);
    }
    Fraction operator-(const Fraction& a, float b){
        /* convert the flaot number into a fraction and use the above funtion to make the sub */
        return (a - (floatToFraction(b)));
    }
    Fraction operator-(float a, const Fraction& b){
        /* same as above */
        return ((floatToFraction(a)) - b);
    }

    /* * */
    Fraction operator*(const Fraction& a, const Fraction& b){
        int den = a.denominator * b.denominator;
        int num = a.numerator * b.numerator;
        int gcdNumDen = findGCD(abs(num), abs(den));
        num /= gcdNumDen;
        den /= gcdNumDen;

        return Fraction(num , den);
    }
    Fraction operator*(const Fraction& a, float b){
        /* convert the flaot number into a fraction and use the above funtion to make the mul */
        return (a * (floatToFraction(b)));
    }
    Fraction operator*(float a, const Fraction& b){
        /* same as above */
        return ((floatToFraction(a)) * b);
    }

    /* / */
    Fraction operator/(const Fraction& a, const Fraction& b){
        int den = a.denominator * b.numerator;
        int num = a.numerator * b.denominator;
        int gcdNumDen = findGCD(num, den);
        num /= gcdNumDen;
        den /= gcdNumDen;
        return Fraction(num , den);
    }
    Fraction operator/(const Fraction& a, float b){
        /* convert the flaot number into a fraction and use the above funtion to make the div */
        return (a / (floatToFraction(b)));
    }
    Fraction operator/(float a, const Fraction& b){
        /* same as above */
        return ((floatToFraction(a)) / b);
    }
    
    /* > */
    bool operator >(const Fraction& a, const Fraction& b){ return ((static_cast<float>(a.numerator/a.denominator)) > ((static_cast<float>(b.numerator/b.denominator))));}
    bool operator >(const Fraction& a, float b){return ((static_cast<float>(a.numerator/a.denominator)) > b);}
    bool operator >(float a, const Fraction& b){return (a > (static_cast<float>(b.numerator/b.denominator)));}

    /* >= */
    bool operator >=(const Fraction& a, const Fraction& b){return ((static_cast<float>(a.numerator/a.denominator)) >= (static_cast<float>(b.numerator/b.denominator)));}
    bool operator >=(const Fraction& a, float b){return ((static_cast<float>(a.numerator/a.denominator)) >= b);}
    bool operator >=(float a, const Fraction& b){return (a >= (static_cast<float>(b.numerator/b.denominator)));}

    /* < */
    bool operator <(const Fraction& a, const Fraction& b){return ((static_cast<float>(a.numerator/a.denominator)) < (static_cast<float>(b.numerator/b.denominator)));}
    bool operator <(const Fraction& a, float b){return ((static_cast<float>(a.numerator/a.denominator)) < b);}
    bool operator <(float a, const Fraction& b){return (a < (static_cast<float>(b.numerator/b.denominator)));}

    /* <= */
    bool operator <=(const Fraction& a, const Fraction& b){return ((static_cast<float>(a.numerator/a.denominator)) <= (static_cast<float>(b.numerator/b.denominator)));}
    bool operator <=(const Fraction& a, float b){return ((static_cast<float>(a.numerator/a.denominator)) <= b);}
    bool operator <=(float a, const Fraction& b){return (a <= (static_cast<float>(b.numerator/b.denominator)));}
    
    /* == */
    bool operator ==(const Fraction& a, const Fraction& b){return ((static_cast<float>(a.numerator/a.denominator)) == (static_cast<float>(b.numerator/b.denominator)));}
    bool operator ==(const Fraction& a, float b){return ((static_cast<float>(a.numerator/a.denominator)) == b);}
    bool operator ==(float a, const Fraction& b){return (a == (static_cast<float>(b.numerator/b.denominator)));}

    // overloaded prefix ++ operator
    Fraction& Fraction::operator++(){
        this->numerator+=this->denominator;
        return *this;
    }

    // overloaded postfix ++ operator
    Fraction Fraction::operator++(int){
        Fraction temp = *this;
        ++*this;
        return temp;
    }

    // overloaded prefix -- operator
    Fraction& Fraction::operator--(){
        this->numerator-=this->denominator;
        return *this;
    }

    // overloaded postfix -- operator
    Fraction Fraction::operator--(int){
        Fraction temp = *this;
        --*this;
        return temp;
    }

    ostream& operator<<(ostream& output, const Fraction& fracture){
        return output << fracture.numerator << "/" << fracture.denominator;
    }
    istream& operator>>(istream& is, Fraction& fracture){
        int num , den;
        //save numerator and denominator values
        string input;
        is >> input;
        int slashPosition=input.find('/');
        if(!(input.find('/') != string::npos)){
            throw invalid_argument("Invalid input!");
        }
        try
        {
            num = stoi(input.substr(0,static_cast<string::size_type>(slashPosition)));
            den = stoi(input.substr(static_cast<string::size_type>(slashPosition) + 1 ));
        }
        catch(const exception& e)
        {
            throw invalid_argument("Invalid input!");
        }
        fracture.numerator = num;
        fracture.denominator = den;

        return is;
    }

    int Fraction::getN() const {return numerator;}
    int Fraction::getD() const{return denominator;}

}