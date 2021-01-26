#pragma once
#include <type_traits>
#include <math.h>
#include <cassert>
#include <iostream>

template<typename T> inline T clamp(T val, T minVal, T maxVal) { return val < minVal ? minVal : val > maxVal ? maxVal : val; }

template<typename T, std::enable_if_t<std::is_trivial_v<T>, int> = 0>
struct vec2
{
    union
    {
        struct { T x, y; };
        struct { T r, g; };
        struct { T X, Y; };
        struct { T R, G; };
        T raw[2];
    };
    
    vec2() {}
    vec2(T f): x(f), y(f) {}
    vec2(T x, T y): x(x), y(y) {}


    vec2 operator+(const vec2& t) const { return vec2(x + t.x, y + t.y); }
    vec2 operator-(const vec2& t) const { return vec2(x - t.x, y - t.y); }
    vec2 operator*(const vec2& t) const { return vec2(x * t.x, y * t.y); }
    vec2 operator*(T t) const { return vec2(x * t, y * t); }
    friend vec2 operator*(T l, const vec2& r) { return vec2(r.x * l, r.y * l); }
    vec2 operator/(T t) const { return vec2(x / t, y / t); }
    vec2 operator-() const { return vec2(-x, -y); }

    bool operator==(const vec2 r) const { return x == r.x && y == r.y; }


    T dot(const vec2& t) const { return dot(*this, t); }
    double length() const { return length(*this); }
    vec2 unit() const {return unit(*this); }
    double distance(const vec2& t) const { return length(*this - t); }
    vec2 clamp(T minVal, T maxVal) { return clamp(*this, minVal, maxVal); }
    vec2 clamp(const vec2& minVal, const vec2& maxVal) { return clamp(*this, minVal, maxVal); }


    static T dot(const vec2& l, const vec2& r) { return l.x * r.x + l.y * r.y; }
    static double length(const vec2& t) { return sqrt(t.x * t.x + t.y * t.y); }
    static vec2 unit(const vec2& t) { auto len = length(t); return vec2(t.x / len, t.y / len); }
    static double distance(const vec2& l, const vec2 r) { return length(r - l); }
    static vec2 clamp(const vec2& v, T minVal, T maxVal) { return clamp(v, vec2(minVal), vec2(maxVal)); }
    static vec2 clamp(const vec2& v, const vec2& minVal, const vec2& maxVal) { return vec2(::clamp(v.x, minVal.x, maxVal.x), ::clamp(v.y, minVal.y, maxVal.y)); }

    friend std::ostream& operator<<(std::ostream& st, const vec2& v) { return st << "vec2(" << +v.x << ", " << + v.y << ")"; }
};

template<typename T, std::enable_if_t<std::is_trivial_v<T>, int> = 0>
struct vec3
{
    union
    {
        struct { T x, y, z; };
        struct { T r, g, b; };
        struct { T X, Y, Z; };
        struct { T R, G, B; };
        struct { T R, theta, phi; };
        T raw[3];
    };
    
    vec3() {}
    vec3(T f): x(f), y(f), z(f) {}
    vec3(vec2<T> v, T z): x(v.x), y(v.y), z(z) {}
    vec3(T x, T y, T z): x(x), y(y), z(z) {}


    vec3 operator+(const vec3& t) const { return vec3(x + t.x, y + t.y, z + t.z); }
    vec3 operator-(const vec3& t) const { return vec3(x - t.x, y - t.y, z - t.z); }
    vec3 operator*(const vec3& t) const { return vec3(x * t.x, y * t.y, z * t.z); }
    vec3 operator*(T t) const { return vec3(x * t, y * t, z * t); }
    friend vec3 operator*(T l, const vec3& r) { return vec3(l * r.x, l * r.y, l * r.z); }
    vec3 operator/(T t) const { return vec3(x / t, y / t, z / t); }
    vec3 operator-() const { return vec3(-x, -y, -z); }

    bool operator==(const vec3 r) const { return x == r.x && y == r.y && z == r.z; }


    T dot(const vec3& t) const { return dot(*this, t); }
    vec3 cross(const vec3& t) const { return cross(*this, t); }
    double length() const { return length(*this); }
    vec3 unit() const { return unit(*this); }
    double distance(const vec3& t) const { return length(*this - t); }
    vec3 clamp(T minVal, T maxVal) { return clamp(*this, vec3(minVal), vec3(maxVal)); }
    vec3 clamp(const vec3& minVal, const vec3& maxVal) { return clamp(*this, minVal, maxVal); }


    static T dot(const vec3& l, const vec3& r) { return l.x * r.x + l.y * r.y + l.z * r.z; }
    static vec3 cross(const vec3& l, const vec3& r) { return vec3(l.y * r.z - l.z * r.y, l.z * r.x - l.x * r.z, l.x * r.y - l.y * r.x); }
    static double length(const vec3& t) { return sqrt(dot(t, t)); }
    static vec3 unit(const vec3& t) { auto len = length(t); return vec3(t.x / len, t.y / len, t.z / len); }
    static double distance(const vec3& l, const vec3 r) { return length(r - l); }
    static vec3 clamp(const vec3& v, T minVal, T maxVal) { return clamp(v, vec3(minVal), vec3(maxVal)); }
    static vec3 clamp(const vec3& v, const vec3& minVal, const vec3& maxVal) { return vec3(::clamp(v.x, minVal.x, maxVal.x), ::clamp(v.y, minVal.y, maxVal.y), ::clamp(v.z, minVal.z, maxVal.z)); }
    static vec3 convertToSpherical(const vec3 v) { return vec3(length(v), atan(sqrt(v.x * v.x + v.y * v.y) / v.z), atan(v.y / v.x)); }
    static vec3 convertToDescartes(const vec3 v) { return vec3(v.R * sin(v.theta) * cos(v.phi), v.R * sin(v.theta) * sin(v.phi), v.R * cos(v.theta)); }

    friend std::ostream& operator<<(std::ostream& st, const vec3& v) { return st << "vec3(" << +v.x << ", " << + v.y << ", " << + v.z << ")"; }
};

template<typename T, std::enable_if_t<std::is_trivial_v<T>, int> = 0>
struct vec4
{
    union
    {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        struct { T X, Y, Z, W; };
        struct { T R, G, B, A; };
        T raw[4];
    };
    
    vec4() {}
    vec4(T f): x(f), y(f), z(f), w(f) {}
    vec4(vec3<T> v, T w): x(v.x), y(v.y), z(v.z), w(w) {}
    vec4(vec2<T> v, T z, T w): x(v.x), y(v.y), z(z), w(w) {}
    vec4(T x, T y, T z, T w): x(x), y(y), z(z), w(w) {}


    vec4 operator+(const vec4& t) const { return vec4(x + t.x, y + t.y, z + t.z, w + t.w); }
    vec4 operator-(const vec4& t) const { return vec4(x - t.x, y - t.y, z - t.z, w - t.w); }
    vec4 operator*(const vec4& t) const { return vec4(x * t.x, y * t.y, z * t.z, w * t.w); }
    vec4 operator*(T t) const { return vec4(x * t, y * t, z * t, w * t); }
    friend vec4 operator*(T l, const vec4& r) { return vec4(l * r.x, l * r.y, l * r.z, l * r.w); }
    vec4 operator/(T t) const { return vec4(x / t, y / t, z / t, w / t); }
    vec4 operator-() const { return vec4(-x, -y, -z, -w); }

    bool operator==(const vec4 r) const { return x == r.x && y == r.y && z == r.z && w == r.w; }


    T dot(const vec4& t) const { return dot(*this, t); }
    double length() const { return length(*this); }
    vec4 unit() const { return unit(*this); }
    double distance(const vec4& t) const { return length(*this - t); }
    vec4 clamp(T minVal, T maxVal) { return clamp(*this, minVal, maxVal); }
    vec4 clamp(const vec4& minVal, const vec4& maxVal) { return clamp(*this, minVal, maxVal); }


    static T dot(const vec4& l, const vec4& r) { return l.x * r.x + l.y * r.y + l.z * r.z + l.w * r.w; }
    static double length(const vec4& t) { return sqrt(t.x * t.x + t.y * t.y + t.z * t.z + t.w * t.w); }
    static vec4 unit(const vec4& t) { auto len = length(t); return vec4(t.x / len, t.y / len, t.z / len, t.w / len); }
    static double distance(const vec4& l, const vec4 r) { return length(r - l); }
    static vec4 clamp(const vec4& v, T minVal, T maxVal) { return clamp(v, vec4(minVal), vec4(maxVal)); }
    static vec4 clamp(const vec4& v, const vec4& minVal, const vec4& maxVal) { return vec4(::clamp(v.x, minVal.x, maxVal.x), ::clamp(v.y, minVal.y, maxVal.y), ::clamp(v.z, minVal.z, maxVal.z), ::clamp(v.z, minVal.z, maxVal.z)); }

    friend std::ostream& operator<<(std::ostream& st, const vec4& v) { return st << "vec4(" << +v.x << ", " << + v.y << ", " << + v.z << ", " << + v.w << ")"; }
};

template<typename T, std::enable_if_t<std::is_trivial_v<T>, int> = 0>
struct mat4
{
    union
    {
        struct 
        {
            T a00, a01, a02, a03;
            T a10, a11, a12, a13;
            T a20, a21, a22, a23;
            T a30, a31, a32, a33;
        };
        T raw[16];
    };

    mat4(T v = 0) { for (size_t i = 0; i < 16; ++i) raw[i] = v; }
    mat4(T a00, T a01, T a02, T a03,
         T a10, T a11, T a12, T a13,
         T a20, T a21, T a22, T a23,
         T a30, T a31, T a32, T a33) { for (size_t i = 0; i < 16; ++i) raw[i] = v; }
    
    mat4 operator+(const mat4& t) const { mat4 res; for (size_t i = 0; i < 16; ++i) res.raw[i] = raw[i] + t.raw[i]; return res; }
    mat4 operator-(const mat4& t) const { mat4 res; for (size_t i = 0; i < 16; ++i) res.raw[i] = raw[i] - t.raw[i]; return res; }
    mat4 operator*(T t) const  { mat4 res; for (size_t i = 0; i < 16; ++i) res.raw[i] = raw[i] * t; return res; }
    vec4<T> operator*(const vec4<T>& t) const  { return vec4<T>(a00 * t.x + a01 * t.y + a02 * t.z + a03 * t.w,
                                                        a10 * t.x + a11 * t.y + a12 * t.z + a13 * t.w,
                                                        a20 * t.x + a21 * t.y + a22 * t.z + a23 * t.w,
                                                        a30 * t.x + a31 * t.y + a32 * t.z + a33 * t.w); }


    /* create a rotation matrix around a vector 
    https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle */
    static mat4 rotateMatrix(const vec3<T> v, float angle)
    {
        mat4 res;
        auto cosa = cos(angle);
        auto sina = sin(angle);
        res.a00 = cosa + (1 - cosa) * v.x * v.x;
        res.a01 = (1 - cosa) * v.x * v.y - sina * v.z;
        res.a02 = (1 - cosa) * v.x * v.z + sina * v.y;
        
        res.a10 = (1 - cosa) * v.y * v.z + sina * v.z;
        res.a11 = cosa + (1 - cosa) * v.y * v.y;
        res.a12 = (1 - cosa) * v.y * v.z - sina * v.x;
        
        res.a20 = (1 - cosa) * v.z * v.x - sina * v.y;
        res.a21 = (1 - cosa) * v.z * v.y - sina * v.x;
        res.a22 = cosa + (1 - cosa) * v.z * v.z;

        res.a33 = 1;
        return res;
    }
};


typedef vec2<float> vec2f;
typedef vec2<double> vec2d;
typedef vec2<char> vec2b;
typedef vec2<unsigned char> vec2ub;
typedef vec2<int> vec2i;
typedef vec2<unsigned int> vec2ui;

typedef vec3<float> vec3f;
typedef vec3<double> vec3d;
typedef vec3<char> vec3b;
typedef vec3<unsigned char> vec3ub;
typedef vec3<int> vec3i;
typedef vec3<unsigned int> vec3ui;

typedef vec4<float> vec4f;
typedef vec4<double> vec4d;
typedef vec4<char> vec4b;
typedef vec4<unsigned char> vec4ub;
typedef vec4<int> vec4i;
typedef vec4<unsigned int> vec4ui;







/* TODO(loject) 

uint64_t xorshf96(void)
{
    static uint64_t x = 123456789, y = 362436069, z = 521288629;
    uint64_t t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;

    return z;
}
*/