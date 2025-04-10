// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.2.0+

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;

DO_APP_FUNC(0x0087BA70, void, GameFrameWork_Update, (void/*GameFrameWork*/* __this, MethodInfo* method));

DO_APP_FUNC(0x0319B630, String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method));
DO_APP_FUNC(0x0319B650, String*, Marshal_PtrToStringUni, (void* ptr, MethodInfo* method));

// FovChanger
DO_APP_FUNC(0x042B77E0, void, Camera_set_fieldOfView, (void* __this, float value, MethodInfo* method));

// C# methods
DO_APP_FUNC(0x032D8E80, Type*, Type_GetType_3, (String* typeName, MethodInfo* method));
//"Signature": "System_Type_o* System_Type__GetType (System_String_o* typeName, const MethodInfo* method);",
DO_APP_FUNC(0x031AF670, Type*, Assembly_GetType, (Assembly* __this, String* name, MethodInfo* method));
//"Signature": "System_Type_o* System_Reflection_Assembly__GetType (System_Reflection_Assembly_o* __this, System_String_o* name, const MethodInfo* method);",
DO_APP_FUNC(0x031AFB90, Assembly*, Assembly_LoadWithPartialName, (String* partialName, MethodInfo* method));
//"Signature": "System_Reflection_Assembly_o* System_Reflection_Assembly__LoadWithPartialName (System_String_o* partialName, const MethodInfo* method);",
// Unity methods
DO_APP_FUNC(0x042B0670, int32_t, Application_get_targetFrameRate, (MethodInfo* method));
// "Signature": "int32_t UnityEngine_Application__get_targetFrameRate (const MethodInfo* method);",
DO_APP_FUNC(0x042B0D90, void, Application_set_targetFrameRate, (int32_t value, MethodInfo* method));
//"Signature": "void UnityEngine_Application__set_targetFrameRate (int32_t value, const MethodInfo* method);",
DO_APP_FUNC(0x043113B0, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo* method));
//"Signature": "UnityEngine_Vector3_o UnityEngine_Vector3__Lerp (UnityEngine_Vector3_o a, UnityEngine_Vector3_o b, float t, const MethodInfo* method);",
DO_APP_FUNC(0x04311150, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo* method));
//"Signature": "float UnityEngine_Vector3__Distance (UnityEngine_Vector3_o a, UnityEngine_Vector3_o b, const MethodInfo* method);",
DO_APP_FUNC(0x042FC060, Transform*, GameObject_get_transform, (GameObject* __this, MethodInfo* method));
//"Signature": "UnityEngine_Transform_o* UnityEngine_GameObject__get_transform (UnityEngine_GameObject_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x042FB010, GameObject*, GameObject_Find, (String* name, MethodInfo* method));
//"Signature": "UnityEngine_GameObject_o* UnityEngine_GameObject__Find (System_String_o* name, const MethodInfo* method);",
DO_APP_FUNC(0x04300CB0, String*, Object_1_get_name, (Object_1* __this, MethodInfo* method));
//"Signature": "System_String_o* UnityEngine_Object__get_name (UnityEngine_Object_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x04309130, void, Time_4_set_timeScale, (float value, MethodInfo* method));
//"Signature": "void UnityEngine_Time__set_timeScale (float value, const MethodInfo* method);",
DO_APP_FUNC(0x0430D440, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method));
//"Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_position (UnityEngine_Transform_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x0430E020, void, Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method));
//"Signature": "void UnityEngine_Transform__set_position (UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method);",
DO_APP_FUNC(0x0430D490, Vector3, Transform_get_right, (Transform* __this, MethodInfo* method));
//"Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_right (UnityEngine_Transform_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x0430E070, void, Transform_set_right, (Transform* __this, Vector3 value, MethodInfo* method));
//"Signature": "void UnityEngine_Transform__set_right (UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method);",
DO_APP_FUNC(0x0430D760, Vector3, Transform_get_up, (Transform* __this, MethodInfo* method));
//"Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_up (UnityEngine_Transform_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x0430E1F0, void, Transform_set_up, (Transform* __this, Vector3 value, MethodInfo* method));
//"Signature": "void UnityEngine_Transform__set_up (UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method);",
DO_APP_FUNC(0x0430CCB0, Vector3, Transform_get_forward, (Transform* __this, MethodInfo* method));
//"Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_forward (UnityEngine_Transform_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x0430DB40, void, Transform_set_forward, (Transform* __this, Vector3 value, MethodInfo* method));
//"Signature": "void UnityEngine_Transform__set_forward (UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method);",
DO_APP_FUNC(0x0430CB50, int32_t, Transform_get_childCount, (Transform* __this, MethodInfo* method));
//"Signature": "int32_t UnityEngine_Transform__get_childCount (UnityEngine_Transform_o* __this, const MethodInfo* method);",
DO_APP_FUNC(0x043274D0, String*, Scene_GetNameInternal, (int32_t sceneHandle, MethodInfo* method));
//"Signature": "System_String_o* UnityEngine_SceneManagement_Scene__GetNameInternal (int32_t sceneHandle, const MethodInfo* method);",
DO_APP_FUNC(0x04325EA0, Scene, SceneManager_GetActiveScene, (MethodInfo* method));
//"Signature": "UnityEngine_SceneManagement_Scene_o UnityEngine_SceneManagement_SceneManager__GetActiveScene (const MethodInfo* method);",

// No Cooldown
DO_APP_FUNC(0x00E2D6C0, void/*KAAIFMKPKAG*/*, KAAIFMKPKAG_IOFMGMJCCFO, (KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method)); 
// Damage Hack
DO_APP_FUNC(0x00E088F0, void, PIPHNBOBFEF_KBCIIEFLPGB, (PIPHNBOBFEF* __this, ESpecialState__Enum OCKAHFDGNEL, int64_t MGFPJFANLBG, int64_t DIACKALMMKH, int64_t PBAPBJGDAPJ, String* DLOACPLHGMP, MethodInfo* method));
//"TypeSignature": "viijjjii"
// God Mode
DO_APP_FUNC(0x011B18D0, int32_t, GHINOEFFMPN_EKHGIHBHEPL, (SkillIdentity* EKPKPIJBPKE, void/*IEnumerable_1_UnityEngine_Component_*/* FKJDKGJBGOD, TargetHitData* COFCDKGCOGJ, MethodInfo* method)); 
// Dumb Enemies
DO_APP_FUNC(0x012456A0, void, EvadeProxy_Init, (EvadeProxy* __this, ENNEJEPMJLJ* IGBKKNODEGM, EvadePenetration* DHPMEMDBDMC, MethodInfo* method));

// EntityManager
DO_APP_FUNC(0x00E3EEE0, void, ENHPKNIEKMI_MIFDFEHDDDD, (ENHPKNIEKMI* __this, MethodInfo* method));
DO_APP_FUNC(0x00A33C40, ENHPKNIEKMI*, ENNEJEPMJLJ_FIGHFBNIDJA, (ENNEJEPMJLJ* __this, MethodInfo* method));
DO_APP_FUNC(0x012024B0, bool, PCILGJOEPJM_PPAKPBOJLIP, (ENNEJEPMJLJ* IGBKKNODEGM, MethodInfo* method)); 

// Mission Time
DO_APP_FUNC(0x008BA070, void, StageReadyPage_EnterUI, (StageReadyPage* __this, MethodInfo* method));
DO_APP_FUNC(0x008C2180, void, StoryQuestChapterPage_EnterUI, (StoryQuestChapterPage* __this, MethodInfo* method));
// Intro Movie
DO_APP_FUNC(0x01340290, void, IntroMovie_Update, (IntroMovie* __this, MethodInfo* method));
// Disable Web View
DO_APP_FUNC(0x03468860, void, WebViewDialog_Show, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x0347E620, void, WebViewUI_RefreshSize, (void* __this, MethodInfo* method));

//DO_APP_FUNC(0x00430040, EGLGAPIAANF__Enum, JIBDAHKJHOG_PCLINKFFGNE, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837FE0, void, JIBDAHKJHOG_KPDGECAFJKA, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837510, void, JIBDAHKJHOG_HLLNLMAECBD, (JIBDAHKJHOG* __this, void* JONOLJGMLBE, void* BHMPNNCBFGN, MethodInfo* method)); // EnterBattleReq
//DO_APP_FUNC(0x00836650, void, JIBDAHKJHOG_EJLDBPGJGPN, (JIBDAHKJHOG* __this, MethodInfo* method)); // NextStageBattle
//DO_APP_FUNC(0x00836410, void, JIBDAHKJHOG_COLDHPFDOHG, (JIBDAHKJHOG* __this, MethodInfo* method)); // StageStart

// Shadow Cooldown And Limit
DO_APP_FUNC(0x0120B170, void, JLLMICINIDA_LFCGJLAFFOM, (JLLMICINIDA* __this, MethodInfo* method));

// Singletons
// DO_APP_FUNC(0x00384E60, void*, TSingleton_GetInstance, (MethodInfo* method)); // Search for this in IDA. Seems to be Singleton<T> class
DO_APP_FUNC(0x004A6B80, Object*, TSingleton_1_System_Object__get_Instance, (MethodInfo* method)); 
// DO_APP_FUNC_METHODINFO(0x04038380, TSingleton_1_JIBDAHKJHOG__get_Instance__MethodInfo);
// DO_APP_FUNC_METHODINFO(0x0403AC70, TSingleton_1_PJKMAOEINNH__get_Instance__MethodInfo); // Probably EntityManager or something similar