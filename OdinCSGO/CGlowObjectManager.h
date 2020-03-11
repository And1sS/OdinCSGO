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
	class IClientEntity* m_pEntity;    //0x0000
	Color	m_vGlowColor;			   //0x0004

private:
	uint8_t pad_0014[4];               //0x0014
	float   m_flSomeFloat;             //0x0018

public:
	float   m_flBloomAmount;           //0x001C

private:
	float   m_flAnotherFloat;          //0x0020

public:
	bool    m_bRenderWhenOccluded;     //0x0024
	bool    m_bRenderWhenUnoccluded;   //0x0025
	bool    m_bFullBloomRender;        //0x0026

private:
	uint8_t pad_0027[5];               //0x0027

public:
	int32_t m_nGlowStyle;              //0x002C
	int32_t m_nSplitScreenSlot;        //0x0030
	int32_t m_nNextFreeSlot;           //0x0034

	bool isUnused() const { return m_nNextFreeSlot != GlowObjectDefinition_t::ENTRY_IN_USE; }

	void setColor(Color color) { m_vGlowColor = color; }

	static const int END_OF_FREE_LIST = -1;
	static const int ENTRY_IN_USE = -2;
}; //Size: 0x0038 (56)

class CGlowObjectManager
{
public:
	GlowObjectDefinition_t* m_GlowObjectDefinitions;	//0x0000
	int max_size;										//0x0004
private:
	int pad;											//0x0008

public:
	int size;											//0x000C
	GlowObjectDefinition_t* m_GlowObjectDefinitions2;	//0x0010
	int currentObjects;									//0x0014

	void setRenderFlags(int nGlowObjectHandle, bool bRenderWhenOccluded, bool bRenderWhenUnoccluded)
	{
		m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenOccluded = bRenderWhenOccluded;
		m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenUnoccluded = bRenderWhenUnoccluded;
	}

	bool isRenderingWhenOccluded(int nGlowObjectHandle)
	{
		return m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenOccluded;
	}

	bool isRenderingWhenUnoccluded(int nGlowObjectHandle)
	{
		return m_GlowObjectDefinitions[nGlowObjectHandle].m_bRenderWhenUnoccluded;
	}
}; //Size: 0x0018 (24)