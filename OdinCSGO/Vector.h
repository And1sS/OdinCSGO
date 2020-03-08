#pragma once
#include <cmath>
#include <ostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#define radToDeg(x) x * 180.0f / M_PI
#define degToRad(x) x * M_PI / 180.0f 

class Vector
{
private:
    float x;
    float y;
    float z;

public:
    static float   distance(Vector a, Vector b);
    static float   getAngleRad(Vector a, Vector b);
    static float   getAngleDeg(Vector a, Vector b);

    static Vector    getDirectionFromAngles(Vector angles);
    static Vector    getRelativeAnglesDeg(Vector source, Vector dest, Vector viewAngles);
   
    Vector() = default;
    Vector(float x, float y, float z);

    Vector normaliseAngles();

    inline float getLength()
    { return sqrtf(x * x + y * y + z * z); }

    inline float getX()
    { return x; }

    inline float getY()
    { return y; }

    inline float getZ()
    { return z; }

    inline Vector operator*(float value)
    { return Vector(value * x, value * y, value * z); }

    inline float operator*(const Vector& other)
    { return x * other.x + y * other.y + z * other.z; }

    inline Vector operator-(const Vector& other)
    { return Vector(x - other.x, y - other.y, z - other.z); }

    inline Vector operator+(const Vector& other)
    { return Vector(x + other.x, y + other.y, z + other.z); }

    inline friend std::ostream& operator<<(std::ostream& stream, Vector vec)
    {
        stream << "x: " << vec.x << " y: " << vec.y << " z: " << vec.z;
        return stream;
    }
};

