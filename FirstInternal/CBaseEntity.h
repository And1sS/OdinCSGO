#pragma once

#include <Windows.h>
#include <tlhelp32.h>
#include <cstdint>
#include <iostream>

#include "Utilities.h"
#include "hazedumper.h"
#include "Vector.h"

struct mat3x4
{
    float mat[3][4];
};

class CBaseEntity
{
protected:
    uintptr_t        base;
    uint32_t         id;

public:
    CBaseEntity() = default;
    CBaseEntity(uintptr_t base, uint32_t id);

    uintptr_t        getBase();

    uint32_t         getId();
    uint32_t         getHealth();
    uint32_t         getArmorValue();
    uint32_t         getTeam();
    uint32_t         getGlowIndex();
    uint32_t         getSpottedByMask();

    bool             isValid();
    bool             isDormant();
    bool             isAlive();

    Vector             getOrigin();
    Vector             getViewPunchAngle();
    Vector             getBoneOrigin(uint32_t BoneIndex);

    virtual void     printInfo();

    bool             operator==(CBaseEntity other);   
};