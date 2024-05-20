#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "../src/Hash.hpp"

BOOST_AUTO_TEST_SUITE( HashConstructTest )

BOOST_AUTO_TEST_CASE( HashConstructZeroLength )
{
  BOOST_CHECK_THROW(
    Hash sut( 0, true, true, true ),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE( HashConstructEmptyHashChars )
{
  BOOST_CHECK_THROW(
    Hash sut( 1, false, false, false ),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE( HashConstructLongLengthDigit )
{
  BOOST_CHECK_THROW(
    Hash sut( 20, true, false, false ),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE( HashConstructLongLengthUpper )
{
  BOOST_CHECK_THROW(
    Hash sut( 14, false, true, false ),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE( HashConstructLongLengthLower )
{
  BOOST_CHECK_THROW(
    Hash sut( 14, false, false, true ),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_SUITE_END()
