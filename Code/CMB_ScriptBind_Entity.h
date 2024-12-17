#ifndef __CCMB_ScriptBind_Entity_H__
#define __CCMB_ScriptBind_Entity_H__
#include "Plugin.h"
#include <CrySystem/ISystem.h>
#include <CryScriptSystem/IScriptSystem.h>
#include <CryEntitySystem/IEntity.h>
#include <CryEntitySystem/IEntitySystem.h>
struct IGameFramework;
//struct ITimer;
//struct IScriptSystem;
struct IEntity;
struct IEntitySystem;

//struct IEntityClass;
//struct IFunctionHandler;
//struct SEntityPhysicalizeParams;
//struct SFogVolumeProperties;
//struct GoalParams;

//class CEntity;

class CCMB_ScriptBind_Entity : public CScriptableBase
{
	public:
		CCMB_ScriptBind_Entity(ISystem* pSystem, IGameFramework* pGameFramework);
		virtual ~CCMB_ScriptBind_Entity() {};

		virtual void GetMemoryUsage(ICrySizer* pSizer) const
		{
			pSizer->AddObject(this, sizeof(*this));
		}

		int SetHelperPos(IFunctionHandler* pH, Vec3 vPos);
		//int SetHelperAngles(IFunctionHandler* pH, Ang3 aAngle);
		//int SetHelperScale(IFunctionHandler* pH, float vScale);

		void RegisterGlobals();
		void RegisterMethods();

	protected:
		void LogString(IFunctionHandler* pH, bool bToConsoleOnly);

	private:
		friend class CEntityComponentLuaScript;

		// Helper function to get IEntity pointer from IFunctionHandler
		IEntity* GetScriptEntityID(IFunctionHandler* pH);

		ISystem			*m_pSystem;
		ILog			*m_pLog;
		IConsole		*m_pConsole;
		IGameFramework	*m_pGameFW;

		static struct
		{
			Vec3  position;
			Vec3  v0, v1, v2;
			Vec2  uv0, uv1, uv2;
			Vec3  baricentric;
			float distance;
			bool  backface;
			char  material[256];
		};
};

#endif //__CCMB_ScriptBind_Entity_H__