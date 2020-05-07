#include <windows.h>
#include <psapi.h>

#include "RedoBlHooks.hpp"

BlFunctionDef(ADDR, __thiscall, Sim_findObject, const char* self);
BlFunctionDef(void, __thiscall, NetConnection_detachObject, DWORD conn, DWORD obj);
BlFunctionDef(void, __cdecl, NetObject_clearScopeToClientCaster, ADDR* a1, int argc, const char* argv[]);
BlFunctionDef(void*, __cdecl, __RTDynamicCast, void*, int delta, void* srcClass, void* targetClass, bool isReference); // :frog:

void __cdecl NetObject_clearScopeToClientCasterHook(ADDR* a1, int argc, const char* argv[]);
BlFunctionHookDef(NetObject_clearScopeToClientCaster);

/*void __fastcall Hooked__clearLocalScopeAlways( DWORD conn, void* blank, DWORD obj )
{
	if( !*(DWORD *)(conn + 492) )
		return;

	DWORD hash = 4 * (*(DWORD *)(obj + 32) & (*(DWORD*)0x0071FB6C - 1));

	for( DWORD ref = *(DWORD *)(*(DWORD *)(conn + 524) + hash); ref; ref = *(DWORD *)(ref + 32) )
	{
		if( *(DWORD *)ref != obj )
			continue;

		if( *(DWORD *)(obj + 68) & ~0xFFFFFFBF )
		{
			//If this is a manually scope object, remove it instantly
			NetConnection__detachObject( conn, ref );
		}
		else
		{
			//Otherwise just remove the scope flag like normal
			*(BYTE *)(ref + 11) &= 0xFEu;
		}

		return;
	}
}*/

void __cdecl NetObject_clearScopeToClientCasterHook(ADDR* a1, int argc, const char* argv[]) {
	const char* thisId = argv[1]; // get TS %this parameter
	const char* clientId = argv[2]; // get TS first argument
	ADDR conn = Sim_findObject(clientId); // convert TS object id to pointer to said object
	ADDR obj = Sim_findObject(thisId); // convert TS object id to pointer to said object
	if(conn && obj) {
		void* simObjectReference = (void*)0x7D297C;
		void* netConnectionReference = (void*)0x7D2CB0;

		ADDR conn2 = *(ADDR*)__RTDynamicCast((void*)conn, 0, simObjectReference, netConnectionReference, 0); // we need to dynamically cast from simobject to netconnection

		if(!*(ADDR *)(conn + 492 + 28)) { // isGhostingFrom()
			return;
		}

		ADDR hash = 4 * (*(DWORD *)(obj + 32) & (*(DWORD*)0x80C2DC - 1));
		for(ADDR ref = *(ADDR *)(*(ADDR *)(conn2 + 520 + 28) + hash); ref; ref = *(ADDR *)(ref + 32)) { // walk through mGhostLookupTable
			if(*(ADDR *)ref != obj) {
				continue;
			}

			if(*(ADDR *)(obj + 68) & ~0xFFFFFFBF) {
				//If this is a manually scope object, remove it instantly
				NetConnection_detachObject(conn2, ref);
			}
			else {
				//Otherwise just remove the scope flag like normal
				*(BYTE *)(ref + 11) &= 0xFEu;
			}
			return;
		}
	}
	else {
		BlPrintf("NetObject::clearScopeToClient: Couldn't find connection %s", clientId);
	}
}

/*void NetObject_clearScopeAlways(ADDR* obj, int argc, const char* argv[]) {
	DWORD object = (DWORD)obj;

	if(!(*(DWORD *)(object + 68) & 2)) {
		*(DWORD *)(object + 68) &= 0xFFFFFFBF;

		//Remove from GhostAlwaysSet
		//Cannot figure out how to do in c++
		char buffer[ 128 ];
		sprintf_s(buffer, "GhostAlwaysSet.remove(%d);", *(DWORD*)(object + 32));
		Eval(buffer);

		//Remove from all scoped connections
		for(DWORD ref = *(DWORD *)(object + 76); ref; ref = *(DWORD *)(object + 76)) {
			NetConnection_detachObject(*(DWORD *)(ref + 28), ref);
		}
	}
}

void NetObject_setNetFlag(ADDR* obj, int argc, const char* argv[]) {
	DWORD object = (DWORD)obj;

	//Crazy conversion of ts -> c++ boolean
	if(!_stricmp( argv[ 3 ], "true" ) || !_stricmp( argv[ 3 ], "1" ) || (0 != atoi( argv[ 3 ] ))) {
		*(DWORD *)(object + 68) |= 1 << atoi( argv[ 2 ] );
	}
	else {
		*(DWORD *)(object + 68) &= ~(1 << atoi( argv[ 2 ] ));
	}
}*/

bool deinit() {
	NetObject_clearScopeToClientCasterHookOff(); // disable the hook(?)
	
	return true;
}

bool init() {
	BlInit;

	BlFunctionScanHex(NetConnection_detachObject, "56 8B 74 24 ? 57 8B F9 66 83 4E ? ?");
	BlFunctionScanHex(Sim_findObject, "53 8B D9 56 57 8A 13");
	BlFunctionScanHex(NetObject_clearScopeToClientCaster, "56 57 8B 7C 24 ? 6A ? 68 ? ? ? ? 68 ? ? ? ? 8B 4F ? 6A ? E8 ? ? ? ? 50 E8 ? ? ? ? 8B F0 83 C4 ? 85 F6 75 ? FF 77 ? 68 ? ? ? ? 50");
	__RTDynamicCast = (rbh___RTDynamicCastFnT)0x703E3B;
	
	NetObject_clearScopeToClientCasterHookOn(); // enable the hook(?)

	BlPrintf("\x06Welcome to Frog Country.");
	
	return true;
}

int __stdcall DllMain( HINSTANCE hInstance,  unsigned long reason,  void *reserved ){
	switch(reason){
		case DLL_PROCESS_ATTACH:
			return init();
		case DLL_PROCESS_DETACH:
			return deinit();
		default:
			return true;
	}
}

// sub_4AED80 is add string command (in old)


// sub_43B230 eval?




// sub_43B3C0 probably Con::executef

// sub_456AB0 StringTableInsert (83 EC ? 80 3D ? ? ? ? ? 53 55 8B 2D ? ? ? ?)
// sub_443860 Namespace::Find (best i can do for LookupNamespace) (55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 56 57 A1 ? ? ? ? 33 C5 50 8D 45 ? 64 A3 ? ? ? ? 8B DA 8B D1)
// sub_439AF0 is ConsoleConstructor::setup (does it iterate through everything and add functions?) (81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 55 56 8B 35 ? ? ? ?)