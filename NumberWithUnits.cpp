/**
 * Author: Mayan Bashan
 */

#include "NumberWithUnits.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <exception>
using namespace std;

namespace ariel{

        // Do notice - the functions' implementation will be done correctly in part b

        bool can_be_converted(string nwu_1_unit, string nwu_2_unit){
          return true;
        }

        long long converted(string unit, const NumberWithUnits &nwu){
            return 1;
        }

         void ariel::NumberWithUnits::read_units(std::ifstream &ufile){
            int amount;
            long long num;
            string unit1;
            string unit2;

            if (ufile.is_open()){
                while(ufile >> amount >> unit1 >> num >> unit2){
                    std::cout<<amount << unit1 << num << unit2 << '\n';
                }
                ufile.close();
            }
            else{
                std::cout << "File is not open" << '\n';
            }
         }

        NumberWithUnits& ariel::NumberWithUnits::operator +(const NumberWithUnits& nwu) const{
            return *(new NumberWithUnits(5,"m"));
        }

        NumberWithUnits& ariel::NumberWithUnits::operator +=(const NumberWithUnits& nwu) const{ //"=+ ???"
            return *(new NumberWithUnits(5,"m"));
        }
        NumberWithUnits& ariel::NumberWithUnits::operator -(const NumberWithUnits& nwu) const{
            return *(new NumberWithUnits(5,"m"));
        }
        NumberWithUnits& ariel::NumberWithUnits::operator -=(const NumberWithUnits& nwu) const{
            if (this->unit == nwu.unit){
                return *(new NumberWithUnits(this->number - nwu.number, this->unit));
            }
            return *(new NumberWithUnits(this->number - nwu.number, this->unit)); // continue
        }

        bool ariel::NumberWithUnits::operator >(const NumberWithUnits& nwu) const{
            if (this->unit == nwu.unit){
                return (this->number > nwu.number);
            }
            else if (can_be_converted(this->unit, nwu.unit)){
                long long nwu_number_converted = converted(this->unit, nwu);
                return (this->number > nwu_number_converted);
            }
            else{
                throw std::exception(); //EXCEPTION ??
                return false;
            }
        }
        
        bool ariel::NumberWithUnits::operator >=(const NumberWithUnits& nwu) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator <(const NumberWithUnits& nwu) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator <=(const NumberWithUnits& nwu) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator ==(const NumberWithUnits& nwu) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator !=(const NumberWithUnits& nwu) const{
            return true;
        }

        NumberWithUnits& ariel::NumberWithUnits::operator ++(){ //x++ 
            NumberWithUnits& new_nwu = *(new NumberWithUnits(this->number,this->unit));
            this->number = this->number + 1;
            return new_nwu;
        }
        NumberWithUnits& ariel::NumberWithUnits::operator --(){ //x-- 
            NumberWithUnits& new_nwu = *(new NumberWithUnits(this->number,this->unit));
            this->number = this->number - 1;
            return new_nwu;
        }

        NumberWithUnits& operator +(NumberWithUnits& nwu){
            return nwu; //*(new NumberWithUnits(nwu.number,nwu.unit));
        }
        NumberWithUnits& operator -(NumberWithUnits& nwu){
            return *(new NumberWithUnits(-nwu.number,nwu.unit));
        }
        NumberWithUnits& operator ++(NumberWithUnits& nwu){ //++x 
            nwu.number = nwu.number + 1;
            return nwu;
        }
        NumberWithUnits& operator --(NumberWithUnits& nwu){ //--x 
            nwu.number = nwu.number - 1;
            return nwu;        
        }
        NumberWithUnits& operator *(double d, NumberWithUnits& nwu){
            return *(new NumberWithUnits(d*nwu.number,nwu.unit));
        }
        ostream& operator <<(ostream& output, NumberWithUnits& nwu){
            output << nwu.number << "[" << nwu.unit << "]";
            return output;
        }
        istream& operator >>(istream& input, NumberWithUnits& nwu){
            return input;
        }
}
