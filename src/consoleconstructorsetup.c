void ConsoleConstructor::setup()
{
  int i; // ebx@1
  const char *v1; // eax@3
  _StringTable **v2; // esi@4
  Namespace *v3; // eax@4
  int v4; // edi@4
  const char *v5; // eax@5
  const char *(__cdecl *v6)(SimObject *, int, const char **); // ebp@7
  int (__cdecl *v7)(SimObject *, int, const char **); // ebp@8
  const char *v8; // eax@9
  _StringTable **v9; // esi@10
  Namespace *v10; // eax@10
  int v11; // edi@10
  const char *v12; // eax@11
  float (__cdecl *v13)(SimObject *, int, const char **); // ebp@14
  const char *v14; // eax@15
  _StringTable **v15; // esi@16
  Namespace *v16; // eax@16
  int v17; // edi@16
  const char *v18; // eax@17
  const char *v19; // ebp@20
  const char *v20; // eax@20
  _StringTable **v21; // esi@21
  Namespace *v22; // eax@21
  int v23; // edi@21
  const char *v24; // eax@22
  const char *v25; // ebp@26
  const char *v26; // eax@26
  _StringTable **v27; // esi@27
  Namespace *v28; // eax@27
  int v29; // edi@27
  const char *v30; // eax@28
  const char *v31; // edi@30
  const char *v32; // esi@30
  const char *v33; // eax@30
  Namespace *v34; // eax@31
  int v35; // eax@31
  const char *v36; // edi@35
  const char *v37; // esi@35
  const char *v38; // eax@35
  Namespace *v39; // eax@36
  int v40; // eax@36
  void (__cdecl *v41)(SimObject *, int, const char **); // [sp+40h] [bp-6Ch]@19
  bool (__cdecl *v42)(SimObject *, int, const char **); // [sp+44h] [bp-68h]@25
  int v43; // [sp+48h] [bp-64h]@3
  int v44; // [sp+4Ch] [bp-60h]@3
  char *v45; // [sp+50h] [bp-5Ch]@3
  char *v46; // [sp+54h] [bp-58h]@3
  int v47; // [sp+58h] [bp-54h]@9
  int v48; // [sp+5Ch] [bp-50h]@9
  char *v49; // [sp+60h] [bp-4Ch]@9
  char *v50; // [sp+64h] [bp-48h]@9
  int v51; // [sp+68h] [bp-44h]@15
  int v52; // [sp+6Ch] [bp-40h]@15
  char *v53; // [sp+70h] [bp-3Ch]@15
  char *v54; // [sp+74h] [bp-38h]@15
  int v55; // [sp+78h] [bp-34h]@20
  int v56; // [sp+7Ch] [bp-30h]@20
  char *v57; // [sp+80h] [bp-2Ch]@20
  int v58; // [sp+84h] [bp-28h]@26
  int v59; // [sp+88h] [bp-24h]@26
  char *v60; // [sp+8Ch] [bp-20h]@26

  for ( i = ConsoleConstructor::first; i; i = *(_DWORD *)(i + 44) )
  {
    while ( 1 )
    {
      v6 = *(const char *(__cdecl **)(SimObject *, int, const char **))i; // seems to be the actual sub_
      if ( !*(_DWORD *)i )
        break;
      v43 = *(_DWORD *)(i + 28); // idk
      v44 = *(_DWORD *)(i + 24); // something to do with descirptions/names
      v45 = *(char **)(i + 32); // idk
      v46 = *(char **)(i + 36); // idk
      v1 = *(const char **)(i + 40); // probably the namespace
      
      // namespace lookup
      if ( v1 )
      {
        v2 = (_StringTable **)StringTable_ptr;
        v3 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v1, 0);
        v4 = Namespace::find(v3, 0);
      }
      else
      {
        v4 = Namespace::global();
        v2 = (_StringTable **)StringTable_ptr;
      }
      v5 = _StringTable::insert(*v2, v46, 0);
      Namespace::addCommand((Namespace *)v4, v5, v6, v45, v44, v43);
LABEL_6:
      i = *(_DWORD *)(i + 44); // get ->next
      if ( !i )
        return;
    }
    v7 = *(int (__cdecl **)(SimObject *, int, const char **))(i + 4);
    if ( !v7 )
    {
      v13 = *(float (__cdecl **)(SimObject *, int, const char **))(i + 8);
      if ( v13 )
      {
        v51 = *(_DWORD *)(i + 28);
        v52 = *(_DWORD *)(i + 24);
        v53 = *(char **)(i + 32);
        v54 = *(char **)(i + 36);
        v14 = *(const char **)(i + 40);
        if ( v14 )
        {
          v15 = (_StringTable **)StringTable_ptr;
          v16 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v14, 0);
          v17 = Namespace::find(v16, 0);
        }
        else
        {
          v17 = Namespace::global();
          v15 = (_StringTable **)StringTable_ptr;
        }
        v18 = _StringTable::insert(*v15, v54, 0);
        Namespace::addCommand((Namespace *)v17, v18, v13, v53, v52, v51);
      }
      else
      {
        v41 = *(void (__cdecl **)(SimObject *, int, const char **))(i + 12);
        if ( v41 )
        {
          v55 = *(_DWORD *)(i + 28);
          v56 = *(_DWORD *)(i + 24);
          v57 = *(char **)(i + 32);
          v19 = *(const char **)(i + 36);
          v20 = *(const char **)(i + 40);
          if ( v20 )
          {
            v21 = (_StringTable **)StringTable_ptr;
            v22 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v20, 0);
            v23 = Namespace::find(v22, 0);
          }
          else
          {
            v23 = Namespace::global();
            v21 = (_StringTable **)StringTable_ptr;
          }
          v24 = _StringTable::insert(*v21, v19, 0);
          Namespace::addCommand((Namespace *)v23, v24, v41, v57, v56, v55);
        }
        else
        {
          v42 = *(bool (__cdecl **)(SimObject *, int, const char **))(i + 16);
          if ( v42 )
          {
            v58 = *(_DWORD *)(i + 28);
            v59 = *(_DWORD *)(i + 24);
            v60 = *(char **)(i + 32);
            v25 = *(const char **)(i + 36);
            v26 = *(const char **)(i + 40);
            if ( v26 )
            {
              v27 = (_StringTable **)StringTable_ptr;
              v28 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v26, 0);
              v29 = Namespace::find(v28, 0);
            }
            else
            {
              v29 = Namespace::global();
              v27 = (_StringTable **)StringTable_ptr;
            }
            v30 = _StringTable::insert(*v27, v25, 0);
            Namespace::addCommand((Namespace *)v29, v30, v42, v60, v59, v58);
          }
          else if ( *(_BYTE *)(i + 20) )
          {
            v31 = *(const char **)(i + 32);
            v32 = *(const char **)(i + 36);
            v33 = *(const char **)(i + 40);
            if ( v33 )
            {
              v34 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v33, 0);
              v35 = Namespace::find(v34, 0);
            }
            else
            {
              v35 = Namespace::global();
            }
            Namespace::markGroup((Namespace *)v35, v32, v31);
          }
          else if ( *(_BYTE *)(i + 21) )
          {
            v36 = *(const char **)(i + 32);
            v37 = *(const char **)(i + 36);
            v38 = *(const char **)(i + 40);
            if ( v38 )
            {
              v39 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v38, 0);
              v40 = Namespace::find(v39, 0);
            }
            else
            {
              v40 = Namespace::global();
            }
            Namespace::addOverload((Namespace *)v40, v37, v36);
          }
        }
      }
      goto LABEL_6;
    }
    v47 = *(_DWORD *)(i + 28);
    v48 = *(_DWORD *)(i + 24);
    v49 = *(char **)(i + 32);
    v50 = *(char **)(i + 36);
    v8 = *(const char **)(i + 40);
    if ( v8 )
    {
      v9 = (_StringTable **)StringTable_ptr;
      v10 = (Namespace *)_StringTable::insert((_StringTable *)*StringTable_ptr, v8, 0);
      v11 = Namespace::find(v10, 0);
    }
    else
    {
      v11 = Namespace::global();
      v9 = (_StringTable **)StringTable_ptr;
    }
    v12 = _StringTable::insert(*v9, v50, 0);
    Namespace::addCommand((Namespace *)v11, v12, v7, v49, v48, v47);
  }
}