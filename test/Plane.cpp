
#define BOOST_TEST_MODULE Plane
#include <string>
#include <boost/test/unit_test.hpp>
#include "Scene/Plane.hpp"

BOOST_AUTO_TEST_SUITE(Plane_intersect)

    BOOST_AUTO_TEST_CASE(alsdkfjlsafd)
    {
        Plane plane(vec3f(0, -1, 0), vec3f(0, 1, 0));
        Ray ray(vec3f(0, 0, 0), vec3f(0, -1, -1));
        Hit hit;

        
        bool res = plane.intersect(ray, hit);
        BOOST_REQUIRE_EQUAL(res, true);
        BOOST_REQUIRE_EQUAL(hit.point, vec3f(0, -1, -1));
        BOOST_REQUIRE_EQUAL(hit.normal, vec3f(0, 1, 0));
    }
    BOOST_AUTO_TEST_CASE(alsdkfjlsafdnegative)
    {
        Plane plane(vec3f(0, 1, 0), vec3f(0, 1, 0));
        Ray ray(vec3f(0, 0, 0), vec3f(0, 1, 1));
        Hit hit;

        
        bool res = plane.intersect(ray, hit);
        BOOST_REQUIRE_EQUAL(res, true);
        BOOST_REQUIRE_EQUAL(hit.point, vec3f(0, 1, 1));
        BOOST_REQUIRE_EQUAL(hit.normal, vec3f(0, -1, 0));
    }
BOOST_AUTO_TEST_SUITE_END();
