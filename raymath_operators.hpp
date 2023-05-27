#pragma once
#include <raymath.h>

inline Vector3 operator+(const Vector3& veca, const Vector3& vecb) {
        Vector3 res;
        res.x = veca.x + vecb.x;
        res.y = veca.y + vecb.y;
        res.z = veca.z + vecb.z;
        return res;
}
inline Vector2 operator+(const Vector2& veca, const Vector2& vecb) {
        Vector2 res;
        res.x = veca.x + vecb.x;
        res.y = veca.y + vecb.y;
        return res;
}
inline bool operator!=(const Vector2& veca, const Vector2& vecb) {
        return veca.x!=vecb.x || veca.y!=vecb.y;
}
