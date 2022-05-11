#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Vector3D.cpp"
#include "Vector3D.hpp"

TEST_CASE( "Arguments initialized") {
    Vector3D a;
    a.SetX(5);
    double b = a.GetX();
    double c = 5;
    REQUIRE( b == c);
}
