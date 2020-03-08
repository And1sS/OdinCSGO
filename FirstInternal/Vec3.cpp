#include "Vec3.h"

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::normaliseAngles()
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

float Vec3::distance(Vec3 a, Vec3 b)
{  return (a - b).getLength(); }

Vec3 Vec3::getDirectionFromAngles(Vec3 angles)
{
    return Vec3(cosf(angles.x) * cosf(angles.y),
                cosf(angles.x) * sinf(angles.y),
                sinf(angles.x));
}

float Vec3::getAngleRad(Vec3 a, Vec3 b)
{ return acosf( a * b / (a.getLength() * b.getLength()) ); }

float Vec3::getAngleDeg(Vec3 a, Vec3 b)
{ return getAngleRad(a, b) * 180.0f / M_PI; }

Vec3 Vec3::getRelativeAnglesDeg(Vec3 src, Vec3 dst, Vec3 viewAngles)
{
    Vec3 delta = dst - src;
    
    Vec3 angles { radToDeg(atan2f(-delta.z, std::hypotf(delta.x, delta.y))),
                  radToDeg(atan2f(delta.y, delta.x)), 0 };
    
    return angles - viewAngles;
}