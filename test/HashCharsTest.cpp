#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "../src/Hash.hpp"

BOOST_AUTO_TEST_SUITE( HashCharsTest )

BOOST_AUTO_TEST_CASE( HashCharsDigit )
{
  Hash sut( 1, true, false, false );

  BOOST_CHECK_EQUAL( sut.hash_chars(), "0123456789" );
}

BOOST_AUTO_TEST_CASE( HashCharsUpper )
{
  Hash sut( 1, false, true, false );

  BOOST_CHECK_EQUAL( sut.hash_chars(), "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
}

BOOST_AUTO_TEST_CASE( HashCharsLower )
{
  Hash sut( 1, false, false, true );

  BOOST_CHECK_EQUAL( sut.hash_chars(), "abcdefghijklmnopqrstuvwxyz" );
}

BOOST_AUTO_TEST_CASE( HashCharsAll )
{
  Hash sut( 1, true, true, true );

  BOOST_CHECK_EQUAL( sut.hash_chars(), "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" );
}

BOOST_AUTO_TEST_SUITE_END()
