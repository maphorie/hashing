#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <boost/program_options.hpp>
#include "Hash.hpp"

using namespace std;

namespace po = boost::program_options;

static const char * const OPTION_HELP   = "help";
static const char * const OPTION_LENGTH = "length";
static const char * const OPTION_DIGIT  = "digit";
static const char * const OPTION_UPPER  = "upper";
static const char * const OPTION_LOWER  = "lower";
static const char * const OPTION_PREFIX = "prefix";
static const char * const OPTION_SUFFIX = "suffix";

int main( int argc, char **argv )
{
  po::options_description options( "options" );
  options.add_options()
    ( OPTION_HELP,                                             "show help"              )
    ( OPTION_LENGTH, po::value<size_t>()->default_value( 3 ),  "hash length"            )
    ( OPTION_DIGIT,                                            "use decimal digit"      )
    ( OPTION_UPPER,                                            "use uppercase alphabet" )
    ( OPTION_LOWER,                                            "use lowercase alphabet" )
    ( OPTION_PREFIX, po::value<string>()->default_value( "" ), "prefix string"          )
    ( OPTION_SUFFIX, po::value<string>()->default_value( "" ), "suffix string"          );

  po::variables_map variables;

  try {
    po::command_line_parser parser( argc, argv );

    parser.options( options );

    po::store( parser.run(), variables );
  }
  catch ( po::invalid_option_value &e ) {
    cerr << options << endl;
    return -1;
  }

  po::notify( variables );

  if ( variables.count( OPTION_HELP ) > 0 ) {
    cerr << options << endl;
    return 1;
  }

  size_t length = variables[OPTION_LENGTH].as<size_t>();
  bool   digit  = ( variables.count( OPTION_DIGIT ) > 0 );
  bool   upper  = ( variables.count( OPTION_UPPER ) > 0 );
  bool   lower  = ( variables.count( OPTION_LOWER ) > 0 );
  string prefix = variables[OPTION_PREFIX].as<string>();
  string suffix = variables[OPTION_SUFFIX].as<string>();

  try {
    Hash hash( length, digit, upper, lower );

    string text;
    while ( getline( cin, text ) ) {
      string result = hash.hash( text );

      cout << prefix << result << suffix << endl;
    }
  }
  catch ( invalid_argument &e ) {
    cerr << e.what() << endl;
    return -1;
  }

  return 0;
}
