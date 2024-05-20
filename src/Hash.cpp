#include "Hash.hpp"
#include <cmath>
#include <cstddef>
#include <functional>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

static const char * const DigitChars = "0123456789";
static const char * const UpperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char * const LowerChars = "abcdefghijklmnopqrstuvwxyz";

Hash::Hash( size_t length, bool digit, bool upper, bool lower )
{
  if ( length == 0 ) {
    throw invalid_argument( "length is 0" );
  }

  if ( ( digit || upper || lower ) != true ) {
    throw invalid_argument( "hash chars list is empty" );
  }

  length_ = length;

  ostringstream ss;
  if ( digit ) {
    ss << DigitChars;
  }
  if ( upper ) {
    ss << UpperChars;
  }
  if ( lower ) {
    ss << LowerChars;
  }
  hash_chars_ = ss.str();

  size_t max_length = ::log( numeric_limits<size_t>::max() ) / ::log( hash_chars_.length() );
  if ( length > max_length ) {
    throw invalid_argument( "length is too long" );
  }

  modulus_ = ::pow( hash_chars_.length(), length );
}

string Hash::hash( const string &text ) const
{
  size_t value   = std::hash<string>()( text );
  size_t modulus = modulus_;

  ostringstream ss;

  for ( size_t i = 0; i < length_; ++i ) {
    value   %= modulus;
    modulus /= hash_chars_.length();

    ss << hash_chars_.at( value / modulus );
  }

  return ss.str();
}

string Hash::hash_chars( void ) const
{
  return hash_chars_;
}

size_t Hash::modulus( void ) const
{
  return modulus_;
}
