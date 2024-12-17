#include "StdAfx.h"
#include "CMB_ScriptBind_Entity.h"

CCMB_ScriptBind_Entity::CCMB_ScriptBind_Entity(ISystem* pSystem, IGameFramework* pGameFramework): m_pSystem(pSystem), m_pGameFW(pGameFramework)
{	
	m_pLog = gEnv->pLog;
	m_pConsole = gEnv->pConsole;
	
	CScriptableBase::Init(pSystem->GetIScriptSystem(), m_pSystem);
	SetGlobalName("CMBEntity");

	RegisterGlobals();
	RegisterMethods();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fundamental functions the creation of the rest of the other Script Binds ahead.So don't mess around!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CCMB_ScriptBind_Entity::RegisterGlobals()
{
	
}

void CCMB_ScriptBind_Entity::RegisterMethods()
{
	// For Xennon.
	#undef SCRIPT_REG_CLASSNAME
	#define SCRIPT_REG_CLASSNAME &CCMB_ScriptBind_Entity::

		SCRIPT_REG_TEMPLFUNC(SetHelperPos, "vPos");
		//SCRIPT_REG_TEMPLFUNC(SetHelperAngles, "aAngle");
		//SCRIPT_REG_TEMPLFUNC(SetHelperScale, "vScale");
		
}

IEntity* CCMB_ScriptBind_Entity::GetScriptEntityID(IFunctionHandler* pH)
{
	void* pThis = pH->GetThis();

	if (pThis)
	{
		auto pEntity = gEnv->pEntitySystem->GetEntity((EntityId)(UINT_PTR)pThis);
		if (pEntity)
			return pEntity;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Importing functions from .h files Entity and IEntity.So don't stir, just add more!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void IEntity::SetWorldTM(Matrix34 const&, EntityTransformationFlagsMask) {};
void IEntity::SetPos(Vec3 const&, EntityTransformationFlagsMask, bool, bool) {};
void CCMB_ScriptBind_Entity::LogString(IFunctionHandler* pH, bool bToConsoleOnly) {};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Start creating your new Script Binds from here.Good fight in creativity!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CCMB_ScriptBind_Entity::SetHelperPos(IFunctionHandler* pH, Vec3 vPos)
{
	//float m_SetHelperPos;
	//m_SetHelperPos = (1.0f);
	//REGISTER_CVAR2("g_SetHelperPos", &m_SetHelperPos, m_SetHelperPos, VF_NULL, "CommentTest");
	
	//string eMessage = "CMB_ScriptBind_Entity: 'SetHelperPos' executed successfully!";
	//m_pLog->LogToConsole("%s", eMessage);
	//CryLog(eMessage);
	//CryLogAlways(eMessage);
	//CryComment(eMessage);
	
	IEntity* pEntity = GetScriptEntityID (pH);

	//Matrix34 tm = pEntity->GetWorldTM();
	//tm.SetTranslation(vPos);
	//pEntity->SetWorldTM(tm);

	//HPi: use bellow code for Entity POs. 
	pEntity->SetPos(vPos);//this

	//HPi:Bellow Codes is useless.
	Vec3 tm = pEntity->GetWorldPos();
	tm.Set(vPos.x, vPos.y, vPos.z);//useless
	pEntity->SetPos(Vec3(vPos.x, vPos.y, vPos.z));//useless
	////////////
	//HPi: use Bellow Code If You Want Move Entity etc 1 meter from its current position.
	pEntity->SetPos(vPos + tm);//Adds Two vec3.

	return pH->EndFunction();
}