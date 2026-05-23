// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 0);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(25);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 2500);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(-125);

        // Test 
        bi = bi.times10(4);

        // Verify
        assert(bi == 0);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(314);

        // Test 
        bi = bi.times10(2333);

        // Verify
        assert(bi == 0);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(314);

        // Test 
        bi = bi.times10(-2);

        // Verify
        assert(bi == 0);  
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

