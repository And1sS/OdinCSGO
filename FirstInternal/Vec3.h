#pragma once
#include <cmath>
#include <ostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#define radToDeg(x) x * 180.0f / M_PI
#define degToRad(x) x * M_PI / 180.0f 

class Vec3
{
private:
    float x;
    float y;
    float z;

public:
    static float   distance(Vec3 a, Vec3 b);
    static float   getAngleRad(Vec3 a, Vec3 b);
    static float   getAngleDeg(Vec3 a, Vec3 b);

    static Vec3    getDirectionFromAngles(Vec3 angles);
    static Vec3    getRelativeAnglesDeg(Vec3 source, Vec3 dest, Vec3 viewAngles);
   
    Vec3() = default;
    Vec3(float x, float y, float z);

    Vec3 normaliseAngles();

    inline float getLength()
    { return sqrtf(x * x + y * y + z * z); }

    inline float getX()
    { return x; }

    inline float getY()
    { return y; }

    inline float getZ()
    { return z; }

    inline Vec3 operator*(float value)
    { return Vec3(value * x, value * y, value * z); }

    inline float operator*(const Vec3& other)
    { return x * other.x + y * other.y + z * other.z; }

    inline Vec3 operator-(const Vec3& other)
    { return Vec3(x - other.x, y - other.y, z - other.z); }

    inline Vec3 operator+(const Vec3& other)
    { return Vec3(x + other.x, y + other.y, z + other.z); }

    inline friend std::ostream& operator<<(std::ostream& stream, Vec3 vec)
    {
        stream << "x: " << vec.x << " y: " << vec.y << " z: " << vec.z;
        return stream;
    }
};

