// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4412);

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[1];
        int digit3 = bi[2];
        int digit4 = bi[3];

        // Verify
        assert(bi    == 4412); 
        assert(digit1 == 2);
        assert(digit2 == 1);
        assert(digit3 == 4);
        assert(digit4 == 4);
    }
    {
        // Setup
        bigint bi(4412);

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[-2];
        int digit3 = bi[2000];
        int digit4 = bi[32];

        // Verify
        assert(bi    == 4412); 
        assert(digit1 == 2);
        assert(digit2 == 0);
        assert(digit3 == 0);
        assert((digit4 == 0));
    }
    {
        // Setup
        bigint bi(4412);

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[-2];
        int digit3 = bi[2];
        int digit4 = bi[3];

        // Verify
        assert(bi    == 4412); 
        assert(digit1 == 2);
        assert(digit2 == 0);
        assert(digit3 == 4);
        assert(digit4 == 4);
    }
    {
        // Setup
        bigint bi(4412);

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[1222];
        int digit3 = bi[2];
        int digit4 = bi[3];

        // Verify
        assert(bi    == 4412); 
        assert(digit1 == 2);
        assert(digit2 == 0);
        assert(digit3 == 4);
        assert(digit4 == 4);
    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

