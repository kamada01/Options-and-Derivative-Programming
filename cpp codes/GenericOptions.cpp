#include "GenericOption.h"
#include <iostream>
#include <string>
using namespace std;

GenericOption::GenericOption(double strike, OptionType type, double cost) //constructor for class
: m_strike(strike),
  m_type(type),
  m_cost(cost)
{
}

GenericOption::GenericOption(const GenericOption &p)
: m_strike(p.m_strike),
m_type(p.m_type),
m_cost(p.m_cost)
{
}

GenericOption::~GenericOption()
{
}

GenericOption &GenericOption::operator=(const GenericOption &p)
{
    if (this != &p)
    {
        m_type = p.m_type;
        m_strike = p.m_strike;
        m_cost = p.m_cost;
    }
    return *this;
}

// calculates valu of option at time of expiration i.e. same as intrinsic val
double GenericOption::valueAtExpiration(double underlyingAtExpiration)
{
    double value = 0.0; //no negative value

    if (m_type == OptionType_Call){
        if (underlyingAtExpiration > m_strike){
            value = underlyingAtExpiration - m_strike;
        }
    }
    else{
        if (m_strike > underlyingAtExpiration){
            value = m_strike - underlyingAtExpiration;
        }
    }
    return value;
}

// takes into account price paid by option
double GenericOption::profitAtExpiration(double underlyingAtExpiration)
{
    double value = 0.0;
    double finalValue = valueAtExpiration(underlyingAtExpiration);
    if (finalValue > m_cost)
    {
        value = finalValue - m_cost;
    }
    return value;
}
int main()
{
    GenericOption option(100.0, OptionType_Put, 1.1);
    double price1 = 120.0;
    double value = option.valueAtExpiration(price1);
    cout << "For 100PUT, value at expiration for price ";
    cout << price1;
    cout << " is ";
    cout << value;
    cout << endl;
}