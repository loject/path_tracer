#pragma once
#include <type_traits>
#include <math.h>

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
    vec2 operator/(T t) const { return vec2(x / t, y / t); }

    T dot(const vec2& t) const { return dot(*this, t); }
    double length() const { return length(*this); }

    friend T dot(const vec2& l, const vec2& r) { return l.x * r.x + l.y * r.y; }
    friend double length(const vec2& t) { return sqrt(t.x * t.x + t.y * t.y); }
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
        T raw[3];
    };
    
    vec3() {}
    vec3(T f): x(f), y(f), z(f) {}
    vec3(T x, T y, T z): x(x), y(y), z(z) {}


    vec3 operator+(const vec3& t) const { return vec3(x + t.x, y + t.y, z + t.z); }
    vec3 operator-(const vec3& t) const { return vec3(x - t.x, y - t.y, z - t.z); }
    vec3 operator*(const vec3& t) const { return vec3(x * t.x, y * t.y, z * t.z); }
    vec3 operator*(T t) const { return vec3(x * t, y * t, z * t); }
    vec3 operator/(T t) const { return vec3(x / t, y / t, z / t); }

    T dot(const vec3& t) const { return dot(*this, t); }
    vec3 cross(const vec3& t) const { return cross(*this, t); }
    double length() const { return length(*this); }


    friend T dot(const vec3& l, const vec3& r) { return l.x * r.x + l.y * r.y + l.z * r.z; }
    friend vec3 cross(const vec3& l, const vec3& r) { return vec3(l.y * r.z - l.z * l.y, l.x * r.z - l.z * l.x, l.x * r.y - l.y * l.x); }
    friend double length(const vec3& t) { return sqrt(t.x * t.x + t.y * t.y + t.z * t.z); }
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
    vec4(T x, T y, T z, T w): x(x), y(y), z(z), w(w) {}


    vec4 operator+(const vec4& t) const { return vec4(x + t.x, y + t.y, z + t.z, w + t.w); }
    vec4 operator-(const vec4& t) const { return vec4(x - t.x, y - t.y, z - t.z, w - t.w); }
    vec4 operator*(const vec4& t) const { return vec4(x * t.x, y * t.y, z * t.z, w * t.w); }
    vec4 operator*(T t) const { return vec4(x * t, y * t, z * t, w * t); }
    vec4 operator/(T t) const { return vec4(x / t, y / t, z / t, w / t); }

    T dot(const vec4& t) const { return dot(*this, t); }
    double length() const { return length(*this); }


    friend T dot(const vec4& l, const vec4& r) { return l.x * r.x + l.y * r.y + l.z * r.z + l.w * r.w; }
    friend double length(const vec4& t) { return sqrt(t.x * t.x + t.y * t.y + t.z * t.z + t.w * t.w); }
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