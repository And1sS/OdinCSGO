#include "CBaseEntity.h"

CBaseEntity::CBaseEntity(uintptr_t base, uint32_t id) : base(base), id(id) {};

bool CBaseEntity::operator==(CBaseEntity other)
{
    return base == other.base;
}

uintptr_t CBaseEntity::getBase()
{
    return base;
}

uint32_t CBaseEntity::getId()
{
    return id;
}

uint32_t CBaseEntity::getHealth()
{
	return *reinterpret_cast<uint32_t*>(base + hazedumper::netvars::m_iHealth);
};

uint32_t CBaseEntity::getTeam()
{
	return *reinterpret_cast<uint32_t*>(base + hazedumper::netvars::m_iTeamNum);
}

Vector CBaseEntity::getViewPunchAngle()
{
    return *reinterpret_cast<Vector*>(base + hazedumper::netvars::m_aimPunchAngle);
}

uint32_t CBaseEntity::getGlowIndex()
{
	return *reinterpret_cast<uint32_t*>(base + hazedumper::netvars::m_iGlowIndex);
}

Vector CBaseEntity::getOrigin()
{
	return *reinterpret_cast<Vector*>(base + hazedumper::netvars::m_vecOrigin);
}

uint32_t CBaseEntity::getSpottedByMask()
{
   return *reinterpret_cast<uint32_t*>(base + hazedumper::netvars::m_bSpottedByMask);
}

bool CBaseEntity::isDormant()
{
	return *reinterpret_cast<bool*>(base + hazedumper::signatures::m_bDormant);
}

bool CBaseEntity::isAlive()
{
    return getHealth() > 0;
}

bool CBaseEntity::isValid()
{
	return base != NULL;
}

Vector CBaseEntity::getBoneOrigin(uint32_t index)
{
	uintptr_t pBoneMatrix = *reinterpret_cast<uintptr_t*>(base + hazedumper::netvars::m_dwBoneMatrix);
	mat3x4 bone = *reinterpret_cast<mat3x4*>(pBoneMatrix + index * sizeof(mat3x4));

	return Vector(bone.mat[0][3], bone.mat[1][3], bone.mat[2][3]);
}

void CBaseEntity::printInfo()
{
    std::cout
        << "base address: " << std::hex << getBase()
        << " health: " << std::dec << getHealth()
        << " x: " << getOrigin().getX()
        << " y: " << getOrigin().getY()
        << " z: " << getOrigin().getZ()
        << " team: " << (getTeam() == 2 ? "T" : "CT")
        << " id: " << getId();
}
