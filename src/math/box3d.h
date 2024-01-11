#ifndef _MATH_BOX3D_H
#define _MATH_BOX3D_H

#include "vector3.h"

struct Box3D {
    struct Vector3 min;
    struct Vector3 max;
};

int box3DContainsPoint(struct Box3D* box, struct Vector3* point);

int box3DHasOverlap(struct Box3D* a, struct Box3D* b);
void box3DUnion(struct Box3D* a, struct Box3D* b, struct Box3D* out);

#endif