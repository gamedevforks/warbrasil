//=========================================================================
//	Module: ApexWorld.h
//	Copyright (C) 2011.
//=========================================================================

#pragma once

#if APEX_ENABLED

//////////////////////////////////////////////////////////////////////////

#include "ApexActor.h"
//	Comment this define, to turn off apex completely

//////////////////////////////////////////////////////////////////////////

namespace physx
{
	namespace apex
	{
		class NxApexSDK;
		class NxApexScene;
		class NxModuleDestructible;
	}
}

//-------------------------------------------------------------------------
//	Apex SDK wrapper
//-------------------------------------------------------------------------

class ApexWorld: public r3dIResource
{
	friend class ApexActorBase;
	/**	Array of all destructible objects in scene. */
	typedef r3dTL::TArray<ApexActorBase*> ActorsArray;
	ActorsArray actors;

public:
	physx::apex::NxApexSDK *apexSDK;
	physx::apex::NxApexScene *apexScene;
	physx::apex::NxModuleDestructible *apexDestructibleModule;

	ApexWorld();
	~ApexWorld();
	void Init();
	void Destroy();
	void StartSimulation();
	void EndSimulation();
	void ApplyAreaDamage(float damage, float momentum, const r3dPoint3D& position, float radius, bool falloff);
	void ApplyDamage(float damage, float momentum, const r3dPoint3D &pos, const r3dPoint3D &direction);
	/**	r3dIResource overrides. */
	virtual void D3DCreateResource();
	virtual void D3DReleaseResource() {}

	/**	Convert all objects to destructible mode. */
	void ConvertAllToDestructibles();
	/**	Convert all objects to preview mode. */
	void ConvertAllToPreview();
};

extern ApexWorld *g_pApexWorld;

#endif