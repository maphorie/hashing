#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "../src/Hash.hpp"

BOOST_AUTO_TEST_SUITE( HashModulusTest )

BOOST_AUTO_TEST_CASE( HashModulus3 )
{
  Hash sut( 3, true, false, false );

  BOOST_CHECK_EQUAL( sut.modulus(), 1000 );
}

BOOST_AUTO_TEST_CASE( HashModulusDigit )
{
  Hash sut( 8, true, false, false );

  BOOST_CHECK_EQUAL( sut.modulus(), 100000000 );
}

BOOST_AUTO_TEST_CASE( HashModulusUpper )
{
  Hash sut( 8, false, true, false );

  BOOST_CHECK_EQUAL( sut.modulus(), 208827064576 );
}

BOOST_AUTO_TEST_CASE( HashModulusLower )
{
  Hash sut( 8, false, false, true );

  BOOST_CHECK_EQUAL( sut.modulus(), 208827064576 );
}

BOOST_AUTO_TEST_CASE( HashModulusAll )
{
  Hash sut( 8, true, true, true );

  BOOST_CHECK_EQUAL( sut.modulus(), 218340105584896 );
}

BOOST_AUTO_TEST_SUITE_END()
