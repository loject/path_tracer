

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
        
    BOOST_AUTO_TEST_CASE(complex0)
    {
        vec3d vec(6334, 18467, 41);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex1)
    {
        vec3d vec(15724, 19169, 26500);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex2)
    {
        vec3d vec(26962, 29358, 11478);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex3)
    {
        vec3d vec(28145, 5705, 24464);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex4)
    {
        vec3d vec(9961, 16827, 23281);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex5)
    {
        vec3d vec(11942, 2995, 491);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex6)
    {
        vec3d vec(32391, 5436, 4827);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex7)
    {
        vec3d vec(153, 3902, 14604);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex8)
    {
        vec3d vec(17421, 12382, 292);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex9)
    {
        vec3d vec(19895, 19718, 18716);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex10)
    {
        vec3d vec(14771, 21726, 5447);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex11)
    {
        vec3d vec(19912, 1869, 11538);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex12)
    {
        vec3d vec(17035, 26299, 25667);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex13)
    {
        vec3d vec(23811, 28703, 9894);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex14)
    {
        vec3d vec(17673, 30333, 31322);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex15)
    {
        vec3d vec(7711, 15141, 4664);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex16)
    {
        vec3d vec(25547, 6868, 28253);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex17)
    {
        vec3d vec(32757, 32662, 27644);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex18)
    {
        vec3d vec(8723, 12859, 20037);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex19)
    {
        vec3d vec(778, 27529, 9741);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex20)
    {
        vec3d vec(22190, 3035, 12316);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex21)
    {
        vec3d vec(30106, 288, 1842);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex22)
    {
        vec3d vec(19264, 8942, 9040);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex23)
    {
        vec3d vec(23805, 27446, 22648);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex24)
    {
        vec3d vec(24370, 6729, 15890);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex25)
    {
        vec3d vec(31101, 15006, 15350);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex26)
    {
        vec3d vec(19629, 3548, 24393);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex27)
    {
        vec3d vec(19954, 24084, 12623);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex28)
    {
        vec3d vec(4966, 11840, 18756);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex29)
    {
        vec3d vec(26308, 13931, 7376);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex30)
    {
        vec3d vec(24626, 32439, 16944);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex31)
    {
        vec3d vec(21538, 5537, 11323);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex32)
    {
        vec3d vec(22929, 2082, 16118);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex33)
    {
        vec3d vec(31115, 4833, 16541);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex34)
    {
        vec3d vec(22704, 29658, 4639);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex35)
    {
        vec3d vec(2306, 13977, 9930);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex36)
    {
        vec3d vec(5021, 22386, 31673);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex37)
    {
        vec3d vec(19072, 26924, 28745);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex38)
    {
        vec3d vec(26777, 5829, 6270);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex39)
    {
        vec3d vec(16512, 5097, 15573);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex40)
    {
        vec3d vec(9161, 13290, 23986);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex41)
    {
        vec3d vec(24767, 22355, 18636);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex42)
    {
        vec3d vec(4031, 15574, 23655);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex43)
    {
        vec3d vec(1150, 27350, 12052);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex44)
    {
        vec3d vec(13966, 21724, 16941);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex45)
    {
        vec3d vec(30191, 31107, 3430);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex46)
    {
        vec3d vec(15457, 11337, 18007);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex47)
    {
        vec3d vec(10383, 27753, 12287);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex48)
    {
        vec3d vec(32209, 8909, 14945);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex49)
    {
        vec3d vec(18588, 24221, 9758);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex50)
    {
        vec3d vec(27506, 24946, 6422);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex51)
    {
        vec3d vec(29168, 16413, 13030);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex52)
    {
        vec3d vec(18762, 32591, 900);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex53)
    {
        vec3d vec(6359, 17410, 1655);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex54)
    {
        vec3d vec(21548, 20537, 27624);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex55)
    {
        vec3d vec(4041, 27595, 6483);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex56)
    {
        vec3d vec(10291, 24350, 3602);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex57)
    {
        vec3d vec(11020, 9374, 30836);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex58)
    {
        vec3d vec(27348, 24021, 4596);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex59)
    {
        vec3d vec(24484, 19668, 23199);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex60)
    {
        vec3d vec(53, 4734, 8281);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex61)
    {
        vec3d vec(27938, 26418, 1999);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex62)
    {
        vec3d vec(18127, 3788, 6900);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex63)
    {
        vec3d vec(14893, 3728, 467);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex64)
    {
        vec3d vec(17807, 22483, 24648);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex65)
    {
        vec3d vec(6617, 14310, 2421);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex66)
    {
        vec3d vec(14309, 9514, 22813);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex67)
    {
        vec3d vec(17451, 18935, 7616);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex68)
    {
        vec3d vec(16519, 5249, 20600);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex69)
    {
        vec3d vec(30303, 22798, 31556);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex70)
    {
        vec3d vec(5844, 11008, 6224);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex71)
    {
        vec3d vec(32702, 14989, 32609);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex72)
    {
        vec3d vec(3093, 20485, 3195);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex73)
    {
        vec3d vec(1587, 30523, 14343);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex74)
    {
        vec3d vec(7448, 9503, 29314);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex75)
    {
        vec3d vec(6618, 13458, 25200);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex76)
    {
        vec3d vec(14798, 19796, 20580);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex77)
    {
        vec3d vec(20798, 19589, 15281);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex78)
    {
        vec3d vec(20472, 27157, 28009);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex79)
    {
        vec3d vec(12292, 18538, 23622);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex80)
    {
        vec3d vec(18190, 24179, 6038);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex81)
    {
        vec3d vec(6191, 7958, 29657);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex82)
    {
        vec3d vec(19156, 22888, 19815);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex83)
    {
        vec3d vec(2634, 16202, 11511);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex84)
    {
        vec3d vec(20328, 20055, 24272);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex85)
    {
        vec3d vec(4886, 26362, 22646);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex86)
    {
        vec3d vec(29869, 28433, 18875);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex87)
    {
        vec3d vec(1416, 23844, 20142);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex88)
    {
        vec3d vec(10322, 31998, 21881);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex89)
    {
        vec3d vec(5699, 10021, 18651);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex90)
    {
        vec3d vec(27892, 28476, 3557);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex91)
    {
        vec3d vec(10712, 5075, 24389);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex92)
    {
        vec3d vec(21003, 2510, 2600);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex93)
    {
        vec3d vec(14688, 17861, 26869);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex94)
    {
        vec3d vec(15255, 9789, 13401);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex95)
    {
        vec3d vec(10585, 5002, 16423);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex96)
    {
        vec3d vec(27088, 10285, 24182);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex97)
    {
        vec3d vec(23757, 28617, 31426);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex98)
    {
        vec3d vec(4169, 30932, 9832);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }        
    BOOST_AUTO_TEST_CASE(complex99)
    {
        vec3d vec(17189, 25721, 2154);
        vec3d actual = vec3d::convertToDescartes(vec3d::convertToSpherical(vec));
        BOOST_TEST(vec3d::AreEqual(actual, vec, eps), actual << " != " << vec << " with eps = " << eps);
    }
BOOST_AUTO_TEST_SUITE_END();
