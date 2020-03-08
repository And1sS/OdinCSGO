#include "Vector.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector Vector::normaliseAngles()
{
    if (x < -89)
        x = -89;

    if (x > 89)
        x = 89;

    if (y < -180)
        y += 360;

    if (y > 180)
        y -= 360;

    z = 0;

    return *this;
}

float Vector::distance(Vector a, Vector b)
{  return (a - b).getLength(); }

Vector Vector::getDirectionFromAngles(Vector angles)
{
    return Vector(cosf(angles.x) * cosf(angles.y),
                cosf(angles.x) * sinf(angles.y),
                sinf(angles.x));
}

float Vector::getAngleRad(Vector a, Vector b)
{ return acosf( a * b / (a.getLength() * b.getLength()) ); }

float Vector::getAngleDeg(Vector a, Vector b)
{ return getAngleRad(a, b) * 180.0f / M_PI; }

Vector Vector::getRelativeAnglesDeg(Vector src, Vector dst, Vector viewAngles)
{
    Vector delta = dst - src;
    
    Vector angles { radToDeg(atan2f(-delta.z, std::hypotf(delta.x, delta.y))),
                  radToDeg(atan2f(delta.y, delta.x)), 0 };
    
    return angles - viewAngles;
}