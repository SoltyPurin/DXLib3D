#include "CollisionCalc.h"
bool CollisionCalc::BoxCalcAABB(const AABB& a, const AABB& b) {
    return a.min.x <= b.max.x && a.max.x >= b.min.x &&
        a.min.y <= b.max.y && a.max.y >= b.min.y &&
        a.min.z <= b.max.z && a.max.z >= b.min.z;
}

bool CollisionCalc::SphereCalcAABB(const SphereAABB& a, const SphereAABB& b) {
    float distance = VSize(VGet(a.center.x - b.center.x,a.center.y-b.center.y,a.center.z-b.center.z));
    return distance <= (a.radius + b.radius);
}

bool CollisionCalc::BSCalcAABB(const AABB& a, const SphereAABB& b) {
    float centerX = (a.min.x + a.max.x) / 2;
    float centerY = (a.min.y + a.max.y) / 2;
    float centerZ = (a.min.z + a.max.z) / 2;
    VECTOR aCenter = VGet(centerX, centerY, centerZ);

    float abDistance = VSize(VGet(aCenter.x - b.center.x, aCenter.y - b.center.y, aCenter.z - b.center.z));
    float aRadius = VSize(VGet(aCenter.x - a.min.x, aCenter.y - a.min.y, aCenter.z - a.min.z));
    return abDistance <= (aRadius + b.radius);
}