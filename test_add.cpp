// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1421321);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1421321);
      assert(right  == 1);
      assert(result == 1421322);
    }
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(-1);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }
                    //You need to add more test cases here. Remove this assert.

    
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

