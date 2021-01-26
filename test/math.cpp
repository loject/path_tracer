

#define BOOST_TEST_MODULE math
#include <string>
#include <boost/test/unit_test.hpp>
#include "math.hpp"

const float eps = 1e-4;

BOOST_AUTO_TEST_SUITE(math)

    BOOST_AUTO_TEST_CASE(convertToSpherical1)
    {
        vec3f vec(3, 4, 5);
        vec3f actual = vec3f::convertToSpherical(vec);
        vec3f expect = vec3f(7.0710678118655, 0.78539816339745, 0.92729521800161);
        BOOST_TEST(vec3f::AreEqual(actual, expect, eps), actual << " != " << expect << " with eps = " << eps);
    }
    BOOST_AUTO_TEST_CASE(convertToSpherical2)
    {
        vec3f vec(5, 4, 3);
        vec3f actual = vec3f::convertToSpherical(vec);
        vec3f expect = vec3f(7.0710678118655, 1.1326472962107, 0.67474094222355);
        BOOST_TEST(vec3f::AreEqual(actual, expect, eps), actual << " != " << expect << " with eps = " << eps);
    }
    BOOST_AUTO_TEST_CASE(ToDescartes1)
    {
        vec3f vec(7.0710678118655, 0.78539816339745, 0.92729521800161);
        vec3f actual = vec3f::convertToDescartes(vec);
        vec3f expect = vec3f(3, 4, 5);
        BOOST_TEST(vec3f::AreEqual(actual, expect, eps), actual << " != " << expect << " with eps = " << eps);
    }
    BOOST_AUTO_TEST_CASE(ToDescartes2)
    {
        vec3f vec(7.0710678118655, 1.1326472962107, 0.67474094222355);
        vec3f actual = vec3f::convertToDescartes(vec);
        vec3f expect = vec3f(5, 4, 3);
        BOOST_TEST(vec3f::AreEqual(actual, expect, eps), actual << " != " << expect << " with eps = " << eps);
    }
    BOOST_AUTO_TEST_CASE(complex)
    {
        vec3f vec(3, 4, 5);
        vec3f actual = vec3f::convertToDescartes(vec3f::convertToSpherical(vec));
        BOOST_TEST(vec3f::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }
BOOST_AUTO_TEST_SUITE_END();
