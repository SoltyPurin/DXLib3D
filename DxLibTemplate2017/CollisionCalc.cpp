#include "CollisionCalc.h"
bool CollisionCalc::BoxCalcAABB(AABB a, AABB b) {
    return a.min.x <= b.max.x && a.max.x >= b.min.x &&
        a.min.y <= b.max.y && a.max.y >= b.min.y &&
        a.min.z <= b.max.z && a.max.z >= b.min.z;
}

bool CollisionCalc::SphereCalcAABB(Sphere a, Sphere b) {
    float distance = VSize(VGet(a.center.x - b.center.x,a.center.y-b.center.y,a.center.z-b.center.z));
    return distance <= (a.radius + b.radius);
}