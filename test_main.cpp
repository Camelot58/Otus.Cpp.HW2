#include "lib.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_version_valid)
{
	BOOST_CHECK( version() > version_info() );
}

BOOST_AUTO_TEST_SUITE_END()
