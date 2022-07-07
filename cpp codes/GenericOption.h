#ifndef __CppOptions__GenericOption__
#define __CppOptions__GenericOption__

#include <stdio.h>

// create framework for options value calculation

enum OptionType {OptionType_Call,
                 OptionType_Put };

class GenericOption
{
    public:
        GenericOption(double strike, OptionType, double cost); //default constructor
        GenericOption(const GenericOption &p); //copy constructor
        ~GenericOption(); //destructor
        GenericOption &operator = (const GenericOption &p); //assignment operator

        double valueAtExpiration(double underlyingAtExpiration); //calc val. of option at time of expiration (intrinsic val)
        double profitAtExpiration(double underlyingAtExpiration); 
    
    private:
        OptionType m_type;
        double m_strike;
        double m_cost; //calculated
};
#endif