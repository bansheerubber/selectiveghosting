
#pragma once

typedef unsigned char BYTE;
typedef unsigned int ADDR;
typedef unsigned int U32;
typedef unsigned int UINT;
typedef signed int S32;

#define rbh_DEBUG true

#define BlFunctionDef(returnType, convention, name, ...) \
	typedef returnType (convention *rbh_##name##FnT)(__VA_ARGS__); \
	rbh_##name##FnT name;

#define BlFunctionDefExtern(returnType, convention, name, ...) \
	typedef returnType (convention *rbh_##name##FnT)(__VA_ARGS__); \
	extern rbh_##name##FnT name;

#define BlFunctionDefIntern(name) \
	rbh_##name##FnT name;

#define BlFunctionScan(target, pattern, mask) \
	target = (rbh_##target##FnT)rbh_ScanFunction((char*)pattern, (char*)mask); \
	if(target == NULL){ \
		rbh_BlPrintf("RedoBlHooks | Cannot find function "#target"!"); \
		return false; \
	}else{ \
		if(rbh_DEBUG) rbh_BlPrintf("RedoBlHooks | Found function "#target" at %08x", (int)target); \
	}

#define BlFunctionScanHex(target, text) \
	target = (rbh_##target##FnT)rbh_ScanFunctionHex((char*)text); \
	if(target == NULL){ \
		rbh_BlPrintf("RedoBlHooks | Cannot find function "#target"!"); \
		return false; \
	}else{ \
		if(rbh_DEBUG) rbh_BlPrintf("RedoBlHooks | Found function "#target" at %08x", (int)target); \
	}

#define BlScan(target, pattern, mask) \
	ADDR target = rbh_ScanFunction((char*)pattern, (char*)mask); \
	if(target == NULL){ \
		rbh_BlPrintf("RedoBlHooks | Cannot find pattern "#target"!"); \
		return false; \
	}else{ \
		if(rbh_DEBUG) rbh_BlPrintf("RedoBlHooks | Found "#target" at %08x", (int)target); \
	}

#define BlScanHex(target, text) \
	ADDR target = rbh_ScanFunctionHex((char*)text); \
	if(target == NULL){ \
		rbh_BlPrintf("RedoBlHooks | Cannot find "#target"!"); \
		return false; \
	}else{ \
		if(rbh_DEBUG) rbh_BlPrintf("RedoBlHooks | Found "#target" at %08x", (int)target); \
	}

#define BlFunctionHookDef(func) \
	BYTE rbh_BlFunctionHook##func##Data[6]; \
	void func##HookOn(){ rbh_HookFunction((ADDR)func, (ADDR)func##Hook, rbh_BlFunctionHook##func##Data); } \
	void func##HookOff(){ rbh_UnhookFunction((ADDR)func, rbh_BlFunctionHook##func##Data); }

#define BlPatchAllMatches(len, patt, mask, repl) \
	rbh_PatchAllMatches(len, (char*)patt, (char*)mask, (char*)repl);

#define BlPatchByte(addr, byte) \
	rbh_PatchByte((ADDR)addr, (BYTE)byte);

#define BlPatchBytes(len, addr, repl) \
	rbh_PatchBytes(len, (ADDR)addr, (BYTE*)repl);

#define BlInit if(!rbh_InitInternal()) return false;

#define BlPrintf rbh_BlPrintf

bool rbh_InitInternal();
ADDR rbh_ScanFunction(char*, char*);
ADDR rbh_ScanFunctionHex(char*);
void rbh_HookFunction(ADDR, ADDR, BYTE*);
void rbh_UnhookFunction(ADDR, BYTE*);
int rbh_PatchAllMatches(UINT, char*, char*, char*);
void rbh_PatchByte(ADDR, BYTE);
void rbh_PatchBytes(int, ADDR, BYTE*);
void rbh_PatchInt(ADDR, U32);

BlFunctionDefExtern(void, , rbh_BlPrintf, const char*, ...);


// stuff i ported from torque.h
/*typedef const char* (*StringCallback)(DWORD* obj, int argc, const char* argv[]);
typedef int(*IntCallback)(DWORD* obj, int argc, const char* argv[]);
typedef float(*FloatCallback)(DWORD* obj, int argc, const char* argv[]);
typedef void(*VoidCallback)(DWORD* obj, int argc, const char* argv[]);
typedef bool(*BoolCallback)(DWORD* obj, int argc, const char* argv[]);

BlFunctionDefExtern(ADDR*, , LookupNamespace, const char* ns);
BlFunctionDefExtern(const char*, __thiscall, StringTableInsert, DWORD stringTablePtr, const char* val, const bool caseSensitive)
BlFunctionDefExtern(void, __thiscall, AddStringCommand, DWORD* nameSpace, const char* name, StringCallback callback, const char* description, int minArgs, int maxArgs);
BlFunctionDefExtern(void, __thiscall, AddIntCommand, DWORD* nameSpace, const char* name, IntCallback callback, const char* description, int minArgs, int maxArgs);
BlFunctionDefExtern(void, __thiscall, AddFloatCommand, DWORD* nameSpace, const char* name, FloatCallback callback, const char* description, int minArgs, int maxArgs);
BlFunctionDefExtern(void, __thiscall, AddVoidCommand, DWORD* nameSpace, const char* name, VoidCallback callback, const char* description, int minArgs, int maxArgs);
BlFunctionDefExtern(void, __thiscall, AddBoolCommand, DWORD* nameSpace, const char* name, BoolCallback callback, const char* description, int minArgs, int maxArgs);
BlFunctionDefExtern(void, __thiscall, AddVariable, DWORD dictionaryPtr, const char* name, int type, void* data);
BlFunctionDefExtern(const char*, , Evaluate, const char* string, bool echo, const char* fileName);

void ConsoleFunction(const char* nameSpace, const char* name, StringCallback callBack, const char* usage, int minArgs, int maxArgs);
void ConsoleFunction(const char* nameSpace, const char* name, IntCallback callBack, const char* usage, int minArgs, int maxArgs);
void ConsoleFunction(const char* nameSpace, const char* name, FloatCallback callBack, const char* usage, int minArgs, int maxArgs);
void ConsoleFunction(const char* nameSpace, const char* name, VoidCallback callBack, const char* usage, int minArgs, int maxArgs);
void ConsoleFunction(const char* nameSpace, const char* name, BoolCallback callBack, const char* usage, int minArgs, int maxArgs);*/