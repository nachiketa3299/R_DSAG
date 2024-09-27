#include <cmath>
#include <cassert>

#include "Vector2.h"

namespace r_dsag {

Vector2::Vector2(float x, float y) : x(x), y(y) { }

Vector2 Vector2::operator+(Vector2 const& r) const {
    return Vector2(x + r.x, y + r.y);
}

Vector2 Vector2::operator-(Vector2 const& r) const {
    return Vector2(x - r.x, y - r.y);
}

bool Vector2::operator==(Vector2 const& r) const {
    return x == r.x && y == r.y;
}

bool Vector2::operator!=(Vector2 const& r) const {
    return !(*this == r);
}

Vector2 Vector2::Normalized() const {
    auto const length = Length();

    if (length > Vector2::Normalize_Tolerance) {
        return Vector2::Zero();
    }

    return Vector2(x / length, y / length);
}

void Vector2::Normalize() {
    *this = Normalized();
}

Vector2 Vector2::Cross(Vector2 const& r) const {
    return Vector2(x * r.y, y * r.x);
}

float Vector2::Dot(Vector2 const& r) const {
    return x * r.x + y * r.y;
}

Vector2 operator*(float c, Vector2 const& r) {
    return Vector2(c * r.x, c * r.y);
}

Vector2 operator/(Vector2 const& r, float c) {
    return Vector2(r.x / c, r.y / c);
}

float Vector2::DistanceSquared(Vector2 const& r) const {
    auto const dx = r.x - x;
    auto const dy = r.y - y;

    return dx * dx + dy * dy;
}

float Vector2::Distance(Vector2 const& r) const {
    return std::sqrt(DistanceSquared(r));
}

float Vector2::LengthSquared() const {
    return x * x + y * y;
}

float Vector2::Length() const {
    return std::sqrt(LengthSquared());
}

Vector2 Vector2::Zero() {
    return Vector2(0.0f, 0.0f);
}

}
