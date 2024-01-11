#ifndef __COLLISION_OBJECT_H__
#define __COLLISION_OBJECT_H__

#include "rigid_body.h"
#include "collision.h"
#include "../math/box3d.h"

#define COLLISION_LAYERS_STATIC             (1 << 0)
#define COLLISION_LAYERS_TRANSPARENT        (1 << 1)
#define COLLISION_LAYERS_TANGIBLE           (1 << 2)
#define COLLISION_LAYERS_GRABBABLE          (1 << 3)
#define COLLISION_LAYERS_FIZZLER            (1 << 4)
#define COLLISION_LAYERS_BLOCK_PORTAL       (1 << 5)

typedef void (*TriggerCallback)(void* data, struct CollisionObject* objectEnteringTrigger);

struct CollisionObject {
    struct ColliderTypeData *collider;
    struct RigidBody* body;
    struct Box3D boundingBox;
    int collisionLayers;
    void* data;
    TriggerCallback trigger;
};

int collisionObjectIsActive(struct CollisionObject* object);
int collisionObjectShouldGenerateConctacts(struct CollisionObject* object);

void collisionObjectInit(struct CollisionObject* object, struct ColliderTypeData *collider, struct RigidBody* body, float mass, int collisionLayers);

void collisionObjectCollideWithQuad(struct CollisionObject* object, struct CollisionObject* quad, struct ContactSolver* contactSolver);
void collisionObjectCollideTwoObjects(struct CollisionObject* a, struct CollisionObject* b, struct ContactSolver* contactSolver);

void collisionObjectUpdateBB(struct CollisionObject* object);

// data should be of type struct CollisionQuad
int minkowsiSumAgainstQuad(void* data, struct Vector3* direction, struct Vector3* output);

// data should be of type struct CollisionObject
int minkowsiSumAgainstObject(void* data, struct Vector3* direction, struct Vector3* output);

void collisionObjectLocalRay(struct CollisionObject* cylinderObject, struct Ray* ray, struct Ray* localRay);

#endif