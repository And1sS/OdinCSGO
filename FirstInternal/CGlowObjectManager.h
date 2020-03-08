#pragma once

#include "definitions.h"
#include "Vector.h"

struct Color
{
	float r, g, b, a;
};

class GlowObjectDefinition_t
{
public:
	GlowObjectDefinition_t() { memset(this, 0, sizeof(*this)); }


	class IClientEntity* m_pEntity;    //0x0000
	Color	m_vGlowColor;			   //0x0004
	uint8_t pad_0014[4];               //0x0014
	float   m_flSomeFloat;             //0x0018
	uint8_t pad_001C[4];               //0x001C
	float   m_flAnotherFloat;          //0x0020
	bool    m_bRenderWhenOccluded;     //0x0024
	bool    m_bRenderWhenUnoccluded;   //0x0025
	bool    m_bFullBloomRender;        //0x0026
	uint8_t pad_0027[5];               //0x0027
	int32_t m_nGlowStyle;              //0x002C
	int32_t m_nSplitScreenSlot;        //0x0030
	int32_t m_nNextFreeSlot;           //0x0034

	bool IsUnused() const { return m_nNextFreeSlot != GlowObjectDefinition_t::ENTRY_IN_USE; }

	static const int END_OF_FREE_LIST = -1;
	static const int ENTRY_IN_USE = -2;
}; //Size: 0x0038 (56)

class CGlowObjectManager
{
public:
	

	void UnregisterGlowObject(int nGlowObjectHandle)
	{
		m_GlowObjectDefinitions[nGlowObjectHandle].m_nNextFreeSlot = m_nFirstFreeSlot;
		m_GlowObjectDefinitions[nGlowObjectHandle].m_pEntity = NULL;
		m_nFirstFreeSlot = nGlowObjectHandle;
	}


	void SetRenderFlags(int nGlowObjectHandle, bool bRenderWhenOccluded, bool bRenderWhenUnoccluded)
	{
		m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenOccluded = bRenderWhenOccluded;
		m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenUnoccluded = bRenderWhenUnoccluded;
	}

	bool IsRenderingWhenOccluded(int nGlowObjectHandle)
	{
		return m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenOccluded;
	}

	bool IsRenderingWhenUnoccluded(int nGlowObjectHandle)
	{
		return m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenUnoccluded;
	}

	SDK::CUtlVector<GlowObjectDefinition_t> m_GlowObjectDefinitions; //0x0000
	int m_nFirstFreeSlot;                                       //0x000C
};