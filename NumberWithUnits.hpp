/**
 * Author: Mayan Bashan
 */

#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

namespace ariel{
    class NumberWithUnits{
        
        long long number;
        string unit;

        public:
            NumberWithUnits(){
                number = 0;
                unit = "";
            }
            NumberWithUnits(long long x, string y){
                number = x;
                unit = y;
            }

            long long get_number(){
                return number;
            }

            string get_unit(){
                return unit;
            }

            friend bool can_be_converted(string nwu_1_unit, string nwu_2_unit);
            friend long long converted(string unit, const NumberWithUnits &nwu);
            static void read_units(std::ifstream &ufile);

            NumberWithUnits& operator +(const NumberWithUnits& nwu) const;
            NumberWithUnits& operator +=(const NumberWithUnits& nwu) const; //"=+ ???"
            NumberWithUnits& operator -(const NumberWithUnits& nwu) const;
            NumberWithUnits& operator -=(const NumberWithUnits& nwu) const;

            bool operator >(const NumberWithUnits& nwu) const;
            bool operator >=(const NumberWithUnits& nwu) const;
            bool operator <(const NumberWithUnits& nwu) const;
            bool operator <=(const NumberWithUnits& nwu) const;
            bool operator ==(const NumberWithUnits& nwu) const;
            bool operator !=(const NumberWithUnits& nwu) const;

            NumberWithUnits& operator ++(); //++x pre-increment
            NumberWithUnits& operator --(); //--x pre-decrement

            friend NumberWithUnits& operator *(double d, NumberWithUnits& nwu);

            friend NumberWithUnits& operator +(NumberWithUnits& nwu);
            friend NumberWithUnits& operator -(NumberWithUnits& nwu);

            friend ostream& operator <<(ostream& output, NumberWithUnits& nwu);
            friend istream& operator >>(istream& input, NumberWithUnits& nwu);
            
            friend NumberWithUnits& operator ++(NumberWithUnits& nwu); //++x post-increment
            friend NumberWithUnits& operator --(NumberWithUnits& nwu); //--x post-decrement

    };
}