#ifndef __HASH_HPP__
#define __HASH_HPP__

#include <cstddef>
#include <string>

class Hash
{
public:
  Hash( std::size_t length, bool digit, bool upper, bool lower );

  std::string hash( const std::string &text ) const;

  std::string hash_chars( void ) const;
  std::size_t modulus( void ) const;

private:
  std::size_t length_;
  std::size_t modulus_;
  std::string hash_chars_;
};

#endif
