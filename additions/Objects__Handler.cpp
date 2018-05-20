void __thiscall Objects::Handler(MapObject *this)
{
  unsigned __int8 v1; // al
  MapObject *object; // esi
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al
  int v11; // ebx
  int *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ebp
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // ebp
  int v22; // edi
  unsigned __int8 v23; // al
  unsigned __int8 object_class_id_4; // al
  int v25; // edx
  int v26; // ecx
  int v27; // ecx
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // edi
  int v32; // eax
  int position; // ecx
  unsigned __int8 v34; // al
  unsigned __int8 v35; // al
  MapObject *v36; // eax
  __int64 v37; // rax
  int object_class_id_2; // ecx
  int v39; // eax
  unsigned __int8 v40; // cl
  unsigned __int8 v41; // al
  unsigned __int8 v42; // ST14_1
  unsigned __int8 v43; // ST10_1
  unsigned __int8 v44; // al
  unsigned __int8 object_class_id_1; // al
  int v46; // edx
  unsigned __int8 v47; // cl
  MapObject *v48; // eax
  int v49; // eax
  int v50; // eax
  unsigned __int8 v51; // al
  int v52; // eax
  int object_class_id; // ecx
  signed int v54; // eax
  unsigned int adr_mfb; // edx
  __int64 v56; // rax
  unsigned int v57; // edx
  int v58; // eax
  __int64 v59; // rax
  unsigned __int8 v60; // al
  unsigned __int8 v61; // al
  unsigned __int8 v62; // al
  unsigned __int8 v63; // cl
  unsigned __int8 v64; // al
  unsigned __int8 v65; // al
  int v66; // eax
  unsigned __int8 v67; // al
  unsigned __int8 v68; // al
  MapObject *v69; // eax
  unsigned int v70; // edx
  unsigned __int8 v71; // al
  int v72; // eax
  __int64 v73; // rax
  int v74; // eax
  unsigned int v75; // edx
  unsigned __int16 v76; // ax
  int v77; // eax
  unsigned __int8 v78; // al
  unsigned __int8 v79; // al
  int v80; // eax
  unsigned __int8 v81; // al
  int v82; // eax
  unsigned __int8 v83; // al
  unsigned __int8 v84; // al
  unsigned __int8 v85; // al
  signed int v86; // edi
  MapObject *i; // ebx
  int v88; // eax
  unsigned __int8 v89; // al
  unsigned __int8 v90; // al
  unsigned __int8 v91; // al
  int v92; // eax
  int v93; // eax
  unsigned __int8 v94; // al
  unsigned __int8 v95; // al
  unsigned __int8 v96; // al
  int v97; // ecx
  unsigned __int8 v98; // dl
  int v99; // eax
  int v100; // ecx
  unsigned __int8 v101; // cl
  unsigned __int8 v102; // al
  int v103; // eax
  int v104; // ecx
  unsigned __int8 v105; // dl
  int v106; // eax
  int v107; // ecx
  unsigned __int8 v108; // cl
  unsigned __int8 v109; // al
  __int64 v110; // rax
  int v111; // eax
  int v112; // eax
  int *v113; // ecx
  unsigned int v114; // edx
  unsigned __int8 v115; // al
  unsigned __int8 v116; // al
  unsigned __int8 v117; // al
  unsigned __int8 v118; // cl
  unsigned __int8 v119; // al
  unsigned __int8 v120; // cl
  unsigned __int8 v121; // cl
  unsigned __int8 v122; // al
  unsigned __int8 v123; // cl
  unsigned __int8 v124; // al
  unsigned __int8 v125; // al
  unsigned __int8 v126; // al
  int v127; // ST14_4
  int v128; // eax
  int v129; // ST10_4
  int v130; // eax
  unsigned __int8 v131; // al
  unsigned __int8 v132; // al
  unsigned __int8 v133; // al
  MapObject *v134; // eax
  int v135; // ecx
  int v136; // edi
  unsigned int v137; // edx
  unsigned __int8 v138; // al
  MapObject *v139; // eax
  int v140; // eax
  int v141; // eax
  unsigned __int8 v142; // al
  unsigned __int8 v143; // cl
  unsigned __int8 v144; // al
  unsigned __int8 v145; // al
  unsigned __int8 v146; // al
  unsigned __int8 *v147; // ebp
  unsigned __int8 v148; // cl
  unsigned __int8 v149; // al
  int v150; // ebx
  MapObject *v151; // edi
  unsigned __int8 v152; // al
  unsigned __int8 v153; // al
  int v154; // ecx
  unsigned __int8 v155; // bl
  unsigned __int8 j; // al
  __int64 v157; // rax
  int v158; // ecx
  MapObject *v159; // eax
  unsigned __int8 v160; // cl
  unsigned __int8 v161; // cl
  unsigned __int8 v162; // cl
  unsigned __int8 v163; // cl
  unsigned __int8 v164; // cl
  MapObject *v165; // ecx
  unsigned __int8 v166; // al
  unsigned __int8 v167; // al
  __int64 v168; // rax
  __int64 v169; // rax
  __int64 v170; // rax
  __int64 v171; // rax
  __int64 v172; // rax
  unsigned __int8 v173; // cl
  unsigned __int8 v174; // cl
  int v175; // eax
  unsigned __int8 v176; // cl
  unsigned __int8 v177; // cl
  int v178; // edx
  unsigned int v179; // edx
  MapObject *v180; // eax
  int v181; // eax
  int v182; // eax
  int v183; // eax
  unsigned int v184; // edx
  int v185; // eax
  int v186; // eax
  int v187; // eax
  unsigned int v188; // edx
  unsigned int v189; // edx
  unsigned __int8 v190; // al
  MapObject *v191; // ecx
  int v192; // eax
  int v193; // eax
  int v194; // eax
  int v195; // eax
  int v196; // eax
  int v197; // eax
  unsigned __int8 v198; // cl
  int v199; // edx
  __int64 v200; // rax
  unsigned __int8 v201; // cl
  int v202; // eax
  __int64 v203; // rax
  unsigned __int8 v204; // al
  unsigned __int8 v205; // al
  MapObject *v206; // ecx
  MapObject *v207; // eax
  MapObject *v208; // eax
  __int64 v209; // rax
  unsigned __int8 v210; // cl
  int v211; // eax
  __int64 v212; // rax
  unsigned __int8 v213; // al
  MapObject *v214; // ecx
  MapObject *v215; // eax
  __int64 v216; // rax
  unsigned __int8 v217; // cl
  int v218; // eax
  __int64 v219; // rax
  unsigned __int8 v220; // al
  unsigned __int8 v221; // al
  MapObject *v222; // ecx
  MapObject *v223; // eax
  MapObject *v224; // ecx
  unsigned int v225; // edx
  unsigned __int8 v226; // al
  unsigned __int8 v227; // al
  MapObject *v228; // ecx
  unsigned __int8 v229; // al
  unsigned int v230; // edx
  unsigned __int8 v231; // al
  MapObject *v232; // ecx
  unsigned __int8 v233; // al
  unsigned __int8 v234; // cl
  int v235; // eax
  int v236; // eax
  char *v237; // eax
  int v238; // eax
  int v239; // eax
  char *v240; // eax
  int v241; // eax
  int v242; // eax
  int v243; // eax
  int v244; // eax
  char *v245; // eax
  __int64 v246; // rax
  MapObject *v247; // ecx
  MapObject *v248; // ecx
  int v249; // eax
  _DWORD *v250; // ecx
  __int64 v251; // rax
  MapObject *v252; // ecx
  int v253; // ecx
  unsigned __int8 v254; // cl
  unsigned __int8 v255; // cl
  int v256; // edx
  int v257; // eax
  int v258; // eax
  int v259; // eax
  int v260; // eax
  int v261; // eax
  int v262; // eax
  int v263; // eax
  int v264; // eax
  int v265; // eax
  unsigned __int8 v266; // cl
  int v267; // edx
  unsigned __int8 v268; // al
  MapObject *v269; // eax
  unsigned __int8 v270; // al
  unsigned __int8 v271; // al
  unsigned __int8 v272; // al
  unsigned int v273; // edx
  MapObject *k; // edi
  unsigned __int8 v275; // cl
  signed int v276; // eax
  MapObject *v277; // ecx
  MapObject *v278; // edi
  MapObject *l; // edi
  MapObject *m; // edi
  unsigned __int8 v281; // al
  unsigned __int8 v282; // al
  MapObject *v283; // edi
  MapObject *v284; // eax
  MapObject *n; // edi
  MapObject *v286; // edi
  unsigned __int8 v287; // al
  unsigned __int8 v288; // al
  MapObject *ii; // edi
  signed int v290; // eax
  MapObject *v291; // ecx
  MapObject *v292; // edi
  MapObject *v293; // ecx
  MapObject *v294; // ecx
  MapObject *jj; // edi
  MapObject *kk; // edi
  int v297; // eax
  int v298; // edx
  int v299; // eax
  unsigned __int8 v300; // bl
  signed __int16 v301; // dx
  int v302; // eax
  int v303; // ecx
  unsigned __int8 v304; // dl
  int v305; // eax
  int v306; // ecx
  unsigned __int8 v307; // cl
  unsigned __int8 v308; // al
  __int64 v309; // rax
  int v310; // eax
  int v311; // edx
  unsigned __int8 v312; // al
  int v313; // eax
  int v314; // ecx
  int v315; // eax
  __int64 v316; // rax
  unsigned __int16 v317; // di
  unsigned __int8 x; // bl
  unsigned __int8 y; // al
  unsigned __int8 v320; // al
  int v321; // eax
  int v322; // ecx
  int v323; // eax
  unsigned __int16 v324; // di
  __int64 v325; // rax
  unsigned __int8 v326; // bl
  signed __int64 v327; // rt2
  unsigned __int8 v328; // al
  int v329; // eax
  int v330; // ecx
  int v331; // eax
  unsigned __int16 v332; // di
  __int64 v333; // rax
  unsigned __int8 v334; // bl
  signed __int64 v335; // rt2
  unsigned __int8 v336; // al
  unsigned __int8 v337; // al
  unsigned __int8 v338; // al
  unsigned __int8 v339; // al
  unsigned __int8 v340; // al
  unsigned __int8 v341; // al
  unsigned __int8 v342; // al
  unsigned __int8 v343; // al
  int v344; // eax
  int v345; // ecx
  int v346; // eax
  unsigned __int16 v347; // di
  __int64 v348; // rax
  unsigned __int8 v349; // bl
  signed __int64 v350; // rt2
  unsigned __int8 v351; // al
  int v352; // eax
  unsigned __int8 v353; // al
  unsigned __int8 v354; // al
  unsigned __int8 v355; // al
  unsigned __int8 v356; // al
  unsigned int v357; // edx
  unsigned int v358; // edx
  unsigned int v359; // edx
  unsigned __int16 v360; // ax
  int v361; // eax
  unsigned __int8 v362; // cl
  unsigned __int8 v363; // dl
  unsigned __int16 v364; // ax
  unsigned __int8 v365; // al
  int v366; // eax
  int v367; // ecx
  int v368; // eax
  unsigned __int16 v369; // di
  __int64 v370; // rax
  unsigned __int8 v371; // bl
  signed __int64 v372; // rt2
  unsigned __int8 v373; // al
  unsigned __int8 v374; // al
  unsigned __int8 v375; // al
  unsigned __int8 v376; // al
  unsigned __int8 v377; // al
  unsigned __int8 v378; // al
  unsigned __int8 v379; // cl
  unsigned __int8 v380; // al
  unsigned __int8 v381; // cl
  unsigned __int8 v382; // al
  unsigned __int8 v383; // al
  signed int v384; // ebp
  int v385; // edi
  int v386; // eax
  int v387; // ecx
  int v388; // edx
  MapObject *v389; // ebx
  int v390; // edi
  int v391; // edi
  int v392; // eax
  int v393; // ecx
  int v394; // eax
  unsigned __int16 v395; // di
  __int64 v396; // rax
  unsigned __int8 v397; // bl
  signed __int64 v398; // rt2
  unsigned __int8 v399; // al
  unsigned __int8 v400; // al
  unsigned int v401; // edx
  unsigned int v402; // edx
  unsigned __int8 v403; // al
  unsigned __int8 v404; // al
  bool v405; // zf
  unsigned __int8 object_class_id_3; // al
  unsigned __int8 v407; // dl

  v1 = this->is_speaking;
  object = this;
  if ( v1 )
  {
    v3 = v1 - 1;
    this->is_speaking = v3;
    if ( !v3 )
      sub_437EE0(this);
  }
  v4 = object->unk235235;
  if ( v4 )
  {
    v5 = v4 - 1;
    object->unk235235 = v5;
    if ( !v5 )
    {
      object->unk32 &= 0xBFFFFFFF;
      sub_437EE0(object);
    }
  }
  v6 = object->data7[10];
  if ( v6 )
    object->data7[10] = v6 - 1;
  v7 = object->fertility_max;
  if ( v7 )
    object->fertility_max = v7 - 1;
  v8 = object->data1[0];
  if ( v8 )
  {
    v9 = v8 - 1;
    object->data1[0] = v9;
    if ( !v9 )
      sub_453A00(object->unk131, 0, 0);
  }
  if ( object->unk32 & 0x80000 )
    sub_437EE0(object);
  if ( object->disease )
    sub_437EE0(object);
  v10 = object->sex;
  v11 = MapTiles[object->x + 192 * object->y].texture << 16;
  if ( v10 == 20 || v10 == 21 )
    sub_437EE0(object);
  if ( object->sex == 26 )
  {
    if ( object->unk30 || object->unk31 || object->unk113 )
    {
      v12 = &object->unk29;
      object->state_id = (object->state_id + 1) % 12;
      sub_437EE0(object);
      if ( object->unk29 < 1310720 )
      {
        v13 = object->unk62;
        if ( v13 < 0x8000 )
          goto LABEL_33;
      }
    }
    else
    {
      v12 = &object->unk29;
      if ( object->unk29 <= v11 )
      {
        object->unk62 = 0;
        *v12 = v11;
      }
      else
      {
        v13 = object->unk62;
        if ( v13 > -32768 )
        {
          v14 = v13 + 2048;
LABEL_34:
          object->unk62 = v14;
          goto LABEL_35;
        }
        if ( v13 < -32768 )
        {
LABEL_33:
          v14 = v13 + 0x2000;
          goto LABEL_34;
        }
      }
    }
LABEL_35:
    if ( object->unk30 || object->unk31 || (v15 = object->unk32, BYTE1(v15) & 0x40) || object->unk62 )
    {
      sub_448890(object);
      v16 = object->unk62;
      v17 = object->unk31 + object->unk7;
      object->unk5 += object->unk30;
      v18 = *v12;
      object->unk7 = v17;
      *v12 = v16 + v18;
LABEL_48:
      sub_449A70(object);
      sub_448490(object);
      sub_433D50(&MapObjects, object);
      sub_437F10(object);
      goto LABEL_49;
    }
    goto LABEL_49;
  }
  if ( object->data8[8] )
  {
LABEL_54:
    sub_437EE0(object);
    goto LABEL_55;
  }
  if ( !object->data10[1] )
  {
    v19 = object->unk32;
    if ( !(v19 & 0x40000) && (object->unk30 || object->unk31 || v19 & 0x4000 || object->unk62) )
    {
      sub_448890(object);
      v20 = object->unk62;
      v21 = object->unk31 + object->unk7;
      v22 = object->unk29;
      object->unk5 += object->unk30;
      object->unk7 = v21;
      object->unk29 = v20 + v22;
      goto LABEL_48;
    }
  }
LABEL_49:
  if ( object->data8[8] )
    goto LABEL_54;
  v23 = object->sex;
  if ( v23 == 24 || v23 == 28 || v23 == 25 || v23 == 26 )
    goto LABEL_54;
LABEL_55:
  if ( unk_6A9092[2 * Tiles[object->x + 192 * object->y].texture] & 0x10 )
  {
    object_class_id_4 = object->class_id;
    if ( !*(_DWORD *)((char *)&unk_663592 + 914 * object_class_id_4) )
    {
      if ( object_class_id_4 == villager )
        sub_451B90(object);
      else
        sub_4508A0(object, 1, 0);
    }
  }
  v25 = object->unk63;
  v26 = object->unk30;
  if ( v25 - 256 < v26 )
  {
    if ( v25 + 256 > v26 )
      object->unk30 = v25;
    else
      object->unk30 = v26 - 256;
  }
  else
  {
    object->unk30 = v26 + 256;
  }
  v27 = object->unk64;
  v28 = object->unk31;
  if ( v27 - 256 < v28 )
  {
    if ( v27 + 256 > v28 )
      object->unk31 = v27;
    else
      object->unk31 = v28 - 256;
  }
  else
  {
    object->unk31 = v28 + 256;
  }
  v29 = 914 * object->class_id;
  if ( !*(_DWORD *)((char *)&unk_66358A + 914 * object->class_id)
    && MapTiles[object->x + 192 * object->y].mask_manstand & 4 )
  {
    v11 = 0x10000;
  }
  if ( object->class_id == 74 )
    object->unk29 = v11;
  v30 = object->unk32 & 0xFFFEFFFF;
  object->unk32 = v30;
  if ( !*(_DWORD *)((char *)&unk_66357C + v29) )
  {
    v31 = object->unk29;
    if ( v11 + 4096 >= v31 )
    {
      if ( v11 - 4096 <= v31 )
      {
        v32 = object->unk62;
        object->unk29 = v11;
        object->unk32 = v30 | 0x10000;
        if ( v32 < 4096 && v32 > -4096 )
          object->unk62 = 0;
      }
      else
      {
        object->unk62 += 4096;
      }
    }
    else
    {
      object->unk62 -= 4096;
    }
  }
  if ( object->unk29 < v11 && object->unk62 < 0 )
  {
    position = object->x + 192 * object->y;
    if ( unk_6A9092[2 * Tiles[position].texture] & 0x200 && !(MapTiles[position].mask_manstand & 4) )
    {
      sub_4342C0(&MapObjects, object);
      sub_453AB0(dword_484370);
    }
    if ( object->class_id == 55 )
    {
      if ( object->unk62 >= -32768 )
      {
        object->unk62 = 0;
      }
      else
      {
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
        object->unk63 = 0;
        object->unk64 = 0;
        object->unk30 = 0;
        object->unk31 = 0;
      }
    }
    if ( *(_DWORD *)((char *)&unk_663580 + 914 * object->class_id) )
      object->unk62 = sub_401D70(-object->unk62, 0x8000);
    else
      object->unk62 = 0;
  }
  if ( object->unk32 & 0x80000 )
  {
    sub_4508A0(object, 1, 0);
    v34 = object->data9[5];
    if ( v34 == -78 || v34 == -64 )
      object->unk32 &= 0xFFF7FFFF;
  }
  v35 = object->data8[0];
  if ( v35 == 14 || v35 == 13 )
  {
    if ( object->unk99 )
      sub_43FA30(object->unk5, object->unk7);
    else
      object->data8[0] = 0;
  }
  v36 = object->field_10;
  if ( v36 && v36->class_id == -59 )
  {
    v36->unk5 = object->unk5;
    object->field_10->unk7 = object->unk7;
    sub_437EE0(object->field_10);
    sub_433D50(&MapObjects, object->field_10);
  }
  if ( object->data9[5] )
  {
    if ( object->unk117 )
      sub_43FA30(object->unk5, object->unk7);
    else
      object->data9[5] = 0;
  }
  v37 = object->data8[2] + 1;
  object_class_id_2 = object->class_id;
  object->data8[2] = (BYTE4(v37) ^ abs(object->data8[2] + 1)) - BYTE4(v37);
  if ( *(_DWORD *)((char *)&unk_6635A2 + 914 * object_class_id_2) )
  {
    if ( !object->is_fleeing )
    {
      v39 = object->unk32;
      if ( v39 & 0x4000 )
      {
        v40 = object->data6_1[3];
        if ( v40 < 3u )
        {
          v41 = object->data6_1[2];
          if ( v41 )
          {
            object->data6_1[2] = v41 - 1;
          }
          else
          {
            v42 = object->goto_y;
            v43 = object->goto_x;
            object->data6_1[3] = v40 + 1;
            object->data6_1[2] = 72;
            sub_43FB50(object, v43, v42);
          }
        }
      }
      else
      {
        object->data6_1[2] = 72;
      }
    }
    v44 = object->is_going;
    if ( v44 == 1 )
    {
      sub_4503C0(object);
    }
    else if ( v44 == 3 )
    {
      sub_450660(object);
    }
    else
    {
      object->unk63 = 0;
      object->unk64 = 0;
    }
  }
  object_class_id_1 = object->class_id;
  if ( (object_class_id_1 == villager || object_class_id_1 == 104) && !object->field_F2 )
  {
    v46 = object->unk30;
    object->unk32 &= 0xFFFBFFFF;
    if ( v46 || object->unk31 || (v47 = object->sex, v47 == 24) || v47 == 28 || v47 == 25 )
      ++object->state_id;
    if ( object_class_id_1 == 103 )
      object->state_id %= 0xCu;
    if ( object->unk113 && object->unk19 )
    {
      sub_4559C0(object);
      if ( sub_455C10((int)object) )
      {
        if ( object->is_going )
        {
          v49 = object->unk32;
          if ( v49 & 0x2000 )
            goto LABEL_154;
          sub_441710(object);
          v50 = object->unk32 | 0x2000;
LABEL_153:
          object->unk32 = v50;
          goto LABEL_154;
        }
        v48 = object->unk113->field_28;
        if ( v48 )
        {
          sub_43F440(object, (int)v48, 1, 1);
          goto LABEL_154;
        }
        sub_454ED0(object, 7);
        object->frame = 0;
        object->state_id = 0;
      }
      else
      {
        if ( !object->unk113 || !sub_455D50(object) && object->is_going )
          goto LABEL_154;
        if ( object->unk32 & 0x8000001 )
        {
          sub_4559C0(object);
          sub_43FD10(object->unk113, 0);
          if ( !object->unk3_size && object->owner_player != cur_player )
            sub_446DC0((int)object);
        }
        else
        {
          sub_43F440(object, 0, 1, 1);
        }
      }
      v50 = object->unk32 & 0xFFFFDFFF;
      goto LABEL_153;
    }
  }
LABEL_154:
  if ( *(_DWORD *)((char *)&unk_663578 + 914 * object->class_id) )
  {
    v51 = object->unk82;
    if ( v51 )
    {
      object->unk82 = v51 - 1;
    }
    else
    {
      v52 = object->unk32;
      if ( v52 & 0x20000 )
      {
        object->unk32 = v52 & 0xFFFDFFFF;
        sub_453AB0(dword_484324);
        sub_437EE0(object);
      }
    }
  }
  object_class_id = object->class_id;
  v54 = 0;
  switch ( object_class_id )                    // обработка по классам объектов
  {
    case peasant_hut:
      if ( current_season == 3 )
        goto LABEL_988;
      goto LABEL_989;
    case fire:
      adr_mfb = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = adr_mfb;
      if ( !(_BYTE)adr_mfb )
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, 5);
      sub_437EE0(object);
      if ( !(object->unk32 & 0x800000) )
        --object->health;
      if ( object->health <= 0 )
      {
        Objects::Create(&MapObjects, object->owner_player, smoke1, object->unk5, object->unk7, object->unk29);
        sub_4342C0(&MapObjects, object);
      }
      goto LABEL_989;
    case none_18:
      v56 = object->state_id + 1;
      object->state_id = (BYTE4(v56) ^ abs(object->state_id + 1) & 0xF) - BYTE4(v56);
      goto LABEL_989;
    case crate:
      v57 = ((unsigned int)object->frame + 1) % (4 * gasmold_mfb->numimages);
      object->frame = v57;
      if ( !(_BYTE)v57 )
      {
        v58 = object->y;
        object->frame = 16;
        sub_434E60(&MapObjects, object, 0, object->x, v58, 0, 5);
      }
      goto LABEL_988;
    case none_1A:
      if ( object->unk32 & 0x10000 )
      {
        v59 = object->state_id + 1;
        LODWORD(v59) = (HIDWORD(v59) ^ abs(object->state_id + 1) & 3) - HIDWORD(v59);
        object->state_id = v59;
        if ( !(_BYTE)v59 )
        {
          v60 = object->frame + 1;
          object->frame = v60;
          if ( v60 > 4u )
            object->frame = 1;
        }
        v61 = object->unk225;
        if ( v61 )
          object->unk225 = v61 - 1;
        else
          sub_4342C0(&MapObjects, object);
      }
      goto LABEL_989;
    case none_1C:
      if ( !object->unk225 )
        object->unk225 = -1;
      v62 = object->unk225;
      if ( v62 > 1u )
      {
        object->unk225 = v62 - 1;
      }
      else
      {
        v63 = object->state_id;
        object->unk225 = -1;
        object->state_id = 1 - v63;
      }
      if ( object->state_id )
      {
        if ( object->state_id == 1 )
        {
          v65 = object->frame;
          if ( v65 <= 0x18u )
          {
            if ( v65 < 0x18u )
              object->frame = v65 + 1;
          }
          else
          {
            object->frame = v65 - 1;
          }
        }
      }
      else
      {
        v64 = object->frame;
        if ( v64 )
          object->frame = v64 - 1;
      }
      goto LABEL_989;
    case none_21:
      if ( object->unk225 )
        goto LABEL_989;
      v66 = object->field_F2;
      if ( object->field_F2 )
      {
        if ( v66 == 25 )
        {
          v68 = object->frame + 1;
          object->frame = v68;
          if ( v68 == 36 )
          {
            object->frame = 0;
            sub_454ED0(object, 26);
            v69 = Objects::Create(&MapObjects, 4u, villager, object->unk5, object->unk7 + 0x10000, object->unk29);
            sub_437F30(v69, 18);
          }
        }
        else if ( v66 == 26 )
        {
          object->frame = 0;
        }
      }
      else
      {
        v67 = object->frame + 1;
        object->frame = v67;
        if ( v67 == 32 )
        {
          object->frame = 0;
          sub_454ED0(object, 25);
        }
      }
      goto LABEL_988;
    case none_22:
      v70 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v70;
      if ( (_BYTE)v70 == 10 )
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, 120);
      if ( !object->frame )
        goto LABEL_987;
      goto LABEL_988;
    case spike_trap:
      if ( object->field_F2 != 18 )
        goto LABEL_989;
      v71 = object->frame + 1;
      object->frame = v71;
      if ( !(v71 & 0xF) )
      {
        v72 = rand();
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, v72 % 20 + 10);
      }
      if ( !object->frame )
        sub_454EC0(object);
      goto LABEL_988;
    case mine:
      v73 = object->frame + 1;
      v74 = (HIDWORD(v73) ^ abs(object->frame + 1) & 0x3F) - HIDWORD(v73);
      object->frame = v74;
      if ( (_BYTE)v74 == 60 || !(_BYTE)v74 )
        sub_437EE0(object);
      if ( object->field_F2 == 24 )
        sub_4508A0(object, 1, 0);
      goto LABEL_989;
    case none_26:
      v75 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v75;
      if ( !(_BYTE)v75 )
        object->frame = 16;
      v76 = object->health - 1;
      object->health = v76;
      if ( (signed __int16)v76 <= 0 )
        goto LABEL_987;
      goto LABEL_988;
    case none_29:
      object->unk63 = 0;
      object->unk64 = 0;
      if ( object->unk62 > 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, 200);
        Objects::Create(&MapObjects, object->owner_player, explosion, object->unk5, object->unk7, object->unk29);
        Objects::Create(&MapObjects, object->owner_player, fire, object->unk5, object->unk7, object->unk29);
        sub_453AB0(dword_4843A4);
        sub_453AB0(dword_484330);
      }
      goto LABEL_988;
    case none_2A:
      v77 = object->state_id;
      if ( !object->state_id )
      {
        if ( !object->frame )
          sub_453AB0(dword_4843C8);
        v78 = object->frame + 1;
        object->frame = v78;
        if ( v78 == 16 )
        {
          object->frame = 0;
          object->state_id = 1;
        }
        goto LABEL_988;
      }
      if ( v77 == 1 )
      {
        v79 = object->frame + 1;
        object->frame = v79;
        if ( v79 == 5 )
        {
          Objects::Create(&MapObjects, object->owner_player, fire, object->unk5, object->unk7, object->unk29);
          sub_453AB0(dword_484330);
          v80 = rand();
          sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, v80 % 100 + 100);
        }
        if ( object->frame == 10 )
        {
          object->frame = 15;
          object->state_id = 2;
        }
        goto LABEL_988;
      }
      if ( v77 != 2 )
        goto LABEL_988;
      v81 = object->frame - 1;
      object->frame = v81;
      if ( v81 )
        goto LABEL_988;
      goto LABEL_987;
    case none_2B:
      v82 = object->state_id;
      if ( !object->state_id )
      {
        v83 = object->frame + 1;
        object->frame = v83;
        if ( v83 == 16 )
        {
          object->frame = 0;
          object->state_id = 1;
          object->unk225 = 20;
        }
        goto LABEL_988;
      }
      if ( v82 == 1 )
      {
        if ( object->field_F2 != 17 )
          goto LABEL_989;
        v84 = object->frame + 1;
        object->frame = v84;
        if ( v84 >= 0x17u )
        {
          object->frame = 0;
          v85 = object->unk225 - 1;
          object->unk225 = v85;
          if ( !v85 )
          {
            sub_454EC0(object);
            object->state_id = 2;
            object->frame = 15;
          }
          v86 = 0;
          for ( i = sub_4340B0(&MapObjects, object->x, object->y, 5);
                i;
                i = sub_434120(&MapObjects, i, object->x, object->y, 5) )
          {
            if ( i->owner_player == object->owner_player )
            {
              v88 = i->unk32;
              if ( v88 & 0x80000 )
              {
                v86 = 1;
                i->unk32 = v88 & 0xFFF7FFFF;
                sub_437EE0(i);
              }
            }
            if ( i->class_id == fire )
            {
              v86 = 1;
              sub_4508A0(i, 1000, 0);
            }
          }
          if ( v86 )
            sub_453AB0(dword_484318);
        }
        goto LABEL_988;
      }
      if ( v82 != 2 )
        goto LABEL_989;
      v89 = object->frame - 1;
      object->frame = v89;
      if ( v89 )
        goto LABEL_988;
      goto LABEL_987;
    case none_2C:
      if ( !(rand() % 3) )
        dword_4846B4 = rand() % -16;
      goto LABEL_989;
    case none_32:
      object->frame = ((unsigned int)object->frame + 1) % (2 * object->mfb_file->numimages);
      goto LABEL_988;
    case farm:
      switch ( object->state_id )
      {
        case 1u:
          v90 = object->unk225 + 1;
          object->unk225 = v90;
          if ( v90 >= 0x10u )
          {
            if ( v90 >= 0x20u )
            {
              if ( v90 >= 0x30u )
              {
                if ( v90 >= 0x80u )
                {
                  if ( v90 >= 0xC4u )
                  {
                    if ( v90 >= 0xD2u )
                    {
                      if ( v90 >= 0xFAu )
                        object->state_id = 0;
                      else
                        object->frame = 8;
                    }
                    else
                    {
                      object->frame = 7;
                    }
                  }
                  else
                  {
                    object->frame = ((unsigned __int8)(v90 & 4) >> 2) + 5;
                  }
                }
                else
                {
                  object->frame = ((unsigned __int8)(v90 & 4) >> 2) + 3;
                }
              }
              else
              {
                object->frame = 2;
              }
            }
            else
            {
              object->frame = 1;
            }
          }
          else
          {
            object->frame = 0;
          }
          goto LABEL_988;
        case 2u:
          v91 = object->unk225 + 1;
          object->unk225 = v91;
          if ( v91 == 1 )
          {
            v92 = rand();
            object->frame = ((v92 >> 31) ^ abs((_BYTE)v92) & 3) - (v92 >> 31);
            sub_437EE0(object);
          }
          if ( object->unk225 == 36 )
          {
            v93 = rand();
            object->frame = ((v93 >> 31) ^ abs((_BYTE)v93) & 3) - (v93 >> 31);
            sub_437EE0(object);
          }
          if ( object->unk225 != 80 )
            goto LABEL_989;
          object->state_id = 0;
          goto LABEL_988;
        case 3u:
          v94 = object->unk225 + 1;
          object->unk225 = v94;
          if ( v94 == 50 )
            sub_453AB0(dword_484334);
          if ( object->unk225 <= 0x64u )
            goto LABEL_989;
          object->state_id = 0;
          goto LABEL_988;
        case 4u:
          v95 = object->unk225 + 1;
          object->unk225 = v95;
          if ( v95 == 50 )
            sub_453A80(unk_6AFF5C);
          if ( object->unk225 <= 0x64u )
            goto LABEL_989;
          object->state_id = 0;
          goto LABEL_988;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case bakery:
    case none_50:
    case flagpost:
    case silver_goblet:
    case potion:
    case gold_goblet:
    case none_AD:
    case holy_sword:
    case magic_scroll:
    case helmet_of_strength:
    case ring_of_fire_protection:
    case shield_of_the_gods:
    case crucifix:
    case magic_key:
    case shovel:
    case cloak_of_invisibility:
    case ring_of_absolute_power:
      goto LABEL_988;
    case brewery:
      if ( object->field_F2 != 100 )
        goto LABEL_989;
      if ( !object->gen_period )
        sub_453AB0(dword_4843CC);
      v96 = object->gen_period++ >> 2;
      object->frame = v96;
      if ( v96 == 5 )
      {
        object->frame = 0;
        object->gen_period = 0;
        object->field_F2 = 0;
      }
      goto LABEL_988;
    case none_37:
      v97 = object->unk64;
      v98 = object->field_F2;
      object->unk30 = object->unk63;
      object->unk31 = v97;
      if ( v98 == 70 && object->unk62 >= 0 )
      {
        object->unk63 = 0;
        object->unk64 = 0;
        object->unk30 = 0;
        v99 = object->x;
        v100 = object->y << 6;
        object->unk62 = 0;
        object->unk31 = 0;
        object->unk29 = MapTiles[v99 + 3 * v100].texture << 16;
        sub_454ED0(object, 91);
        object->unk225 = 72;
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      v101 = object->field_F2;
      if ( v101 == 91 )
      {
        v102 = object->unk225 - 1;
        object->unk225 = v102;
        if ( !v102 )
          sub_4342C0(&MapObjects, object);
        goto LABEL_988;
      }
      v103 = object->unk62;
      if ( v103 < -16000 )
        goto LABEL_988;
      if ( v103 >= -4096 )
      {
        if ( v103 >= 4096 )
        {
          if ( v103 >= 0 || v101 )
          {
LABEL_988:
            sub_437EE0(object);
            goto LABEL_989;
          }
        }
        else if ( v101 )
        {
          goto LABEL_988;
        }
      }
      else if ( v101 )
      {
        goto LABEL_988;
      }
      sub_454ED0(object, 70);
      goto LABEL_988;
    case none_38:
      v104 = object->unk64;
      v105 = object->field_F2;
      object->unk30 = object->unk63;
      object->unk31 = v104;
      if ( v105 == 70 && object->unk62 > 0 )
      {
        object->unk63 = 0;
        object->unk64 = 0;
        object->unk30 = 0;
        v106 = object->x;
        v107 = object->y << 6;
        object->unk62 = 0;
        object->unk31 = 0;
        object->unk29 = MapTiles[v106 + 3 * v107].texture << 16;
        sub_454ED0(object, 91);
        object->unk225 = 72;
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
        Objects::Create(&MapObjects, object->owner_player, explosion, object->unk5, object->unk7, object->unk29);
      }
      v108 = object->field_F2;
      if ( v108 == 91 )
      {
        v109 = object->unk225 - 1;
        object->unk225 = v109;
        if ( !v109 )
          sub_4342C0(&MapObjects, object);
      }
      else
      {
        v110 = (object->gen_period + 16) / 32;
        object->state_id = (BYTE4(v110) ^ abs((_BYTE)v110) & 7) - BYTE4(v110);
        v111 = object->unk62;
        if ( v111 >= -16000 )
        {
          if ( v111 < -4096 )
          {
            object->frame = 0;
            if ( !v108 )
              sub_454ED0(object, 70);
          }
        }
        else
        {
          object->frame = 0;
        }
      }
      goto LABEL_988;
    case none_39:
      v112 = object->field_F2;
      if ( v112 == 55 )
      {
        v113 = &object->mfb_file->numimages;
        v114 = ((unsigned int)object->frame + 1) % (4 * *v113);
        object->frame = v114;
        if ( !(_BYTE)v114 )
        {
          object->frame = 4 * *v113 - 1;
          sub_454EC0(object);
          object->unk225 = 64;
        }
        goto LABEL_988;
      }
      if ( v112 != 56 )
        goto LABEL_989;
      v115 = object->frame - 1;
      object->frame = v115;
      if ( !v115 )
        goto LABEL_987;
      goto LABEL_988;
    case corpse:
      switch ( object->field_F2 )
      {
        case 0x1Bu:
          v116 = object->frame;
          if ( v116 < 0x13u )
          {
            object->frame = v116 + 1;
            goto LABEL_988;
          }
          break;
        case 0x1Cu:
          v117 = object->frame;
          if ( v117 < 0x27u )
          {
            object->frame = v117 + 1;
            goto LABEL_988;
          }
          break;
        case 0x1Fu:
          v118 = object->frame;
          if ( 4 * cowplode_mfb->numimages - 1 > (unsigned int)v118 )
          {
            object->unk225 = -1;
            object->frame = v118 + 1;
            goto LABEL_988;
          }
          v119 = object->unk225 - 1;
          object->unk225 = v119;
          if ( !v119 )
            sub_4342C0(&MapObjects, object);
          break;
        case 0x72u:
          v120 = object->frame;
          if ( 4 * vampdead_mfb->numimages - 1 <= (unsigned int)v120 )
            sub_4342C0(&MapObjects, object);
          else
            object->frame = v120 + 1;
          break;
        case 0x76u:
          v121 = object->frame;
          if ( 4 * cowkill_mfb->numimages - 1 > (unsigned int)v121 )
          {
            object->unk225 = -1;
            object->frame = v121 + 1;
            goto LABEL_988;
          }
          v122 = object->unk225 - 1;
          object->unk225 = v122;
          if ( !v122 )
            sub_4342C0(&MapObjects, object);
          break;
        case 0x77u:
          v123 = object->frame;
          if ( 4 * cowdie_mfb->numimages - 1 > (unsigned int)v123 )
          {
            object->unk225 = -1;
            object->frame = v123 + 1;
            goto LABEL_988;
          }
          v124 = object->unk225 - 1;
          object->unk225 = v124;
          if ( !v124 )
            sub_4342C0(&MapObjects, object);
          break;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case oil:
      if ( object->unk32 & 0x80000 )
      {
        v125 = object->unk225;
        if ( v125 )
        {
          v126 = v125 - 1;
          object->unk225 = v126;
          if ( !v126 )
          {
            sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, 1);
            v127 = object->unk29;
            v128 = rand();
            v129 = ((v128 >> 31) ^ (unsigned __int16)abs((_WORD)v128)) - (v128 >> 31) + object->unk7 - 0x8000;
            v130 = rand();
            Objects::Create(
              &MapObjects,
              object->owner_player,
              fire,
              ((v130 >> 31) ^ (unsigned __int16)abs((_WORD)v130)) - (v130 >> 31) + object->unk5 - 0x7FFF,
              v129,
              v127);
          }
        }
      }
      goto LABEL_989;
    case none_43:
      v131 = object->unk225;
      if ( v131 )
      {
        v132 = v131 - 1;
        object->unk225 = v132;
        if ( !v132 )
        {
          object->field_10 = Objects::Create(
                               &MapObjects,
                               object->owner_player,
                               none_38,
                               object->unk5 + 1024,
                               object->unk7 + 1024,
                               object->unk29 + 0x7FFF);
          object->frame = 0;
          sub_437EE0(object);
        }
      }
      else if ( object->unk113 )
      {
        sub_454ED0(object, 58);
      }
      if ( object->field_F2 != 58 )
        goto LABEL_989;
      v133 = object->frame + 1;
      object->frame = v133;
      if ( v133 == 1 )
      {
        v134 = object->field_10;
        if ( v134 )
        {
          if ( object->unk113 )
          {
            v135 = ((object->unk78 - object->y) << 6) - object->x + object->unk77;
            object->gen_period = byte_5FDA98[v135];
            v136 = dword_5FB2F0[v135];
            v134->unk62 = 0x20000;
            object->field_10->unk63 = sub_401D70(dword_5D1150[object->gen_period], v136);
            object->field_10->unk64 = sub_401D70(dword_5D1558[object->gen_period], v136);
            object->field_10->unk30 = object->field_10->unk63;
            object->field_10->unk31 = object->field_10->unk64;
            sub_453AB0(dword_484388);
          }
        }
      }
      if ( 2 * object->mfb_file->numimages - object->frame == 1 )
      {
        object->unk225 = -1;
        sub_454EC0(object);
        object->unk77 = 0;
        object->unk78 = 0;
      }
      goto LABEL_988;
    case none_44:
      v137 = ((unsigned int)object->frame + 1) % (2 * object->mfb_file->numimages);
      object->frame = v137;
      if ( (_BYTE)v137 == 1 )
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, 10);
      if ( !object->frame )
        goto LABEL_987;
      goto LABEL_988;
    case builders_guild:
      if ( object->field_F2 == 88 )
      {
        v138 = object->unk225 + 1;
        object->unk225 = v138;
        switch ( v138 )
        {
          case 1u:
            object->frame = 0;
            goto LABEL_988;
          case 9u:
            object->frame = 1;
            goto LABEL_988;
          case 0x11u:
            object->frame = 2;
            goto LABEL_988;
          case 0x19u:
            object->frame = 3;
            goto LABEL_988;
          case 0x21u:
            object->frame = 0;
            goto LABEL_988;
          case 0x29u:
            sub_454EC0(object);
            object->unk225 = 0;
            object->frame = 1;
            goto LABEL_988;
          default:
            goto LABEL_989;
        }
      }
      goto LABEL_989;
    case none_46:
      if ( object->field_F2 != 21 )
        goto LABEL_989;
      v139 = object->field_10;
      if ( v139 )
      {
        v139->unk64 = 16536;
        object->field_10->unk31 = 16536;
        sub_454ED0(object->field_10, 23);
      }
      sub_454ED0(object, 22);
      goto LABEL_988;
    case none_47:
      if ( object->field_F2 == 23 )
      {
        sub_437EE0(object);
        v140 = object->unk29 - 2048;
        object->unk29 = v140;
        if ( v11 >= v140 )
        {
          sub_4342C0(&MapObjects, object);
          sub_453AB0(dword_48434C);
        }
      }
      goto LABEL_989;
    case wheat:
      v141 = object->field_F2;
      if ( v141 == 3 )
      {
        v142 = object->state_id + 1;
        object->state_id = v142;
        v143 = 5 - v142 / 0x24u;
        object->frame = v143;
        if ( v143 < 3u )
LABEL_987:
          sub_4342C0(&MapObjects, object);
      }
      else
      {
        if ( v141 != 4 )
        {
          if ( v141 == 5 )
            object->frame = 0;
          goto LABEL_989;
        }
        if ( object->unk120 )
          goto LABEL_989;
        sub_454ED0(object, 0);
      }
      goto LABEL_988;
    case none_51:
      v144 = object->unk225;
      if ( v144 )
      {
        v145 = v144 - 1;
        object->unk225 = v145;
        if ( !v145 )
        {
          object->frame = 0;
          sub_437EE0(object);
        }
      }
      else if ( object->unk77 || object->unk78 )
      {
        v54 = sub_454ED0(object, 59);
      }
      v146 = object->unk77;
      if ( v146 || (v147 = &object->unk78, object->unk78) )
      {
        v147 = &object->unk78;
        object->gen_type = byte_5FDA98[((object->unk78 - object->y) << 6) - object->x + object->unk77];
      }
      v148 = object->gen_period;
      LOBYTE(v54) = object->gen_type;
      if ( v148 != (_BYTE)v54 )
      {
        object->gen_period = sub_4031A0(v148, v54);
        sub_437EE0(object);
      }
      if ( object->field_F2 != 59 || object->gen_period != object->gen_type )
        goto LABEL_989;
      v149 = object->frame + 1;
      object->frame = v149;
      if ( v149 == 1 )
      {
        v150 = 4 * dword_5FB2F0[object->unk77 + ((*v147 - object->y) << 6) - object->x];
        v151 = Objects::Create(
                 &MapObjects,
                 object->owner_player,
                 none_37,
                 object->unk5 - 0x8000,
                 object->unk7 + 0x8000,
                 object->unk29 + 0x40000);
        v151->unk63 = sub_401D70(dword_5D1150[object->gen_period], v150);
        v151->unk64 = sub_401D70(dword_5D1558[object->gen_period], v150);
        v151->unk30 = v151->unk63;
        v151->unk31 = v151->unk64;
        sub_453AB0(dword_48438C);
        object->unk225 = 36;
        sub_454EC0(object);
        object->unk77 = 0;
        *v147 = 0;
      }
      goto LABEL_988;
    case none_54:
      v152 = object->unk225;
      if ( v152 )
      {
        object->unk225 = v152 - 1;
        goto LABEL_989;
      }
      v153 = object->gen_period;
      object->unk82 = v153;
      v154 = (v153 >> 1) & 0xFC;
      v155 = object->x + *(int *)((char *)&dword_484580 + v154);
      for ( j = object->y + *(int *)((char *)&dword_484600 + v154);
            MapTiles[v155 + 192 * j].road;
            j = object->y + *(int *)((char *)&dword_484600 + v158) )
      {
        v157 = object->gen_period + 64;
        LOBYTE(v157) = (BYTE4(v157) ^ abs(object->gen_period + 64)) - BYTE4(v157);
        object->gen_period = v157;
        v158 = ((unsigned __int8)v157 >> 1) & 0xFC;
        v155 = object->x + *(int *)((char *)&dword_484580 + v158);
      }
      sub_43F970(v155, j);
      v159 = Objects::Create(&MapObjects, object->owner_player, none_55, object->unk5, object->unk7, object->unk29);
      v160 = object->gen_period;
      if ( v160 )
      {
        switch ( v160 )
        {
          case 0x40u:
            v159->frame = 3;
            break;
          case 0x80:
            v159->frame = 0;
            break;
          case 0xC0:
            v159->frame = 1;
            break;
        }
      }
      else
      {
        v159->frame = 2;
      }
      switch ( object->unk82 )
      {
        case 0u:
          v161 = object->gen_period;
          if ( v161 )
          {
            switch ( v161 )
            {
              case 0x40u:
                object->frame = 7;
                break;
              case 0x80:
                object->frame = 4;
                break;
              case 0xC0:
                object->frame = 8;
                break;
            }
          }
          else
          {
            object->frame = 4;
          }
          goto LABEL_450;
        case 0x40u:
          v162 = object->gen_period;
          if ( v162 )
          {
            switch ( v162 )
            {
              case 0x40u:
                goto LABEL_449;
              case 0x80:
                object->frame = 8;
                break;
              case 0xC0:
                goto LABEL_449;
            }
          }
          else
          {
            object->frame = 9;
          }
          goto LABEL_450;
        case 0x80u:
          v163 = object->gen_period;
          if ( v163 )
          {
            switch ( v163 )
            {
              case 0x40u:
                object->frame = 6;
                break;
              case 0x80:
                object->frame = 4;
                break;
              case 0xC0:
                object->frame = 9;
                break;
            }
          }
          else
          {
            object->frame = 4;
          }
          goto LABEL_450;
        case 0xC0u:
          v164 = object->gen_period;
          switch ( v164 )
          {
            case 0u:
              object->frame = 6;
              break;
            case 0x40u:
              goto LABEL_449;
            case 0x80:
              object->frame = 7;
              break;
            case 0xC0:
LABEL_449:
              object->frame = 5;
              break;
          }
LABEL_450:
          v165 = object->field_10;
          if ( v165 )
            v165->frame = object->frame;
          object->unk225 = 4;
          object->field_10 = v159;
          v166 = object->unk83 - 1;
          object->unk83 = v166;
          if ( !v166 )
            sub_4342C0(&MapObjects, object);
LABEL_989:
          v404 = object->unk8 - 1;
          object->unk8 = v404;
          if ( !v404 )
          {
            sub_442F40(object);
            object->unk8 = -1;
          }
          v405 = object->unk26-- == 1;
          if ( v405 )
          {
            object_class_id_3 = object->class_id;
            if ( object_class_id_3 == villager || object_class_id_3 == 104 || object_class_id_3 == 110 )
              v407 = rand() % 20 + 40;
            else
              v407 = rand() % 40 + 80;
            object->unk26 = v407;
            sub_444150(object);
          }
          return;
        default:
          goto LABEL_450;
      }
    case none_55:
      v167 = object->unk225;
      if ( v167 )
        object->unk225 = v167 - 1;
      else
        sub_4342C0(&MapObjects, object);
      goto LABEL_989;
    case none_5C:
      switch ( object->field_F2 )
      {
        case 0x2Du:
          v168 = object->frame + 1;
          LODWORD(v168) = (HIDWORD(v168) ^ abs(object->frame + 1) & 7) - HIDWORD(v168);
          object->frame = v168;
          if ( !(_BYTE)v168 )
            sub_454ED0(object, 46);
          goto LABEL_468;
        case 0x2Eu:
          v169 = object->frame + 1;
          object->frame = (BYTE4(v169) ^ abs(object->frame + 1) & 7) - BYTE4(v169);
          goto LABEL_468;
        case 0x2Fu:
          v170 = object->frame + 1;
          LODWORD(v170) = (HIDWORD(v170) ^ abs(object->frame + 1) & 7) - HIDWORD(v170);
          object->frame = v170;
          if ( !(_BYTE)v170 )
            goto LABEL_467;
          goto LABEL_468;
        case 0x30u:
          v171 = object->frame + 1;
          LODWORD(v171) = (HIDWORD(v171) ^ abs(object->frame + 1) & 0xF) - HIDWORD(v171);
          object->frame = v171;
          if ( !(_BYTE)v171 )
            sub_454ED0(object, 49);
          goto LABEL_468;
        case 0x31u:
          v172 = object->frame + 1;
          LODWORD(v172) = (HIDWORD(v172) ^ abs(object->frame + 1) & 0x7F) - HIDWORD(v172);
          object->frame = v172;
          if ( !(_BYTE)v172 )
LABEL_467:
            sub_454EC0(object);
LABEL_468:
          sub_437EE0(object);
          break;
        default:
          break;
      }
      sub_4503C0(object);
      goto LABEL_989;
    case flame_trap:
      if ( object->field_F2 != 20 )
        goto LABEL_989;
      v173 = object->frame;
      if ( 2 * flamepit_mfb->numimages <= (unsigned int)v173 )
      {
        sub_454EC0(object);
        object->frame = 0;
      }
      else
      {
        v174 = v173 + 1;
        object->frame = v174;
        if ( v174 == 10 )
        {
          v175 = rand();
          sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, v175 % 40 + 60);
        }
      }
      goto LABEL_988;
    case villager:
      switch ( object->field_F2 )
      {
        case 0u:
          v176 = object->unk225;
          if ( v176 )
          {
            v177 = v176 + 1;
            v178 = object->unk19;
            object->unk225 = v177;
            if ( (unsigned __int8)unk_6AFF88[35 * v178] <= v177 )
              object->unk225 = 0;
          }
          goto LABEL_989;
        case 3u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v179 = ((unsigned int)object->frame + 1) % (4 * cowchopm_mfb->numimages);
          object->frame = v179;
          if ( (_BYTE)v179 == 16 )
            sub_453AB0(dword_48436C);
          if ( !object->frame )
          {
            sub_454EC0(object);
            v180 = Objects::Create(&MapObjects, object->owner_player, corpse, object->unk5, object->unk7, object->unk29);
            sub_454ED0(v180, 30);
            sub_453A80(unk_5C78E4);
            v181 = rand();
            sub_454280(((v181 >> 31) ^ abs((_BYTE)v181) & 0xF) - (v181 >> 31) + 32);
            v182 = rand();
            sub_4542D0(v182 % -16);
            v183 = rand();
            sub_4540A0(((v183 >> 31) ^ abs((_BYTE)v183) & 0xF) - (v183 >> 31) + 4, 0);
          }
          goto LABEL_988;
        case 4u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v184 = ((unsigned int)object->frame + 1) % (4 * m_chkill_mfb->numimages);
          object->frame = v184;
          if ( (_BYTE)v184 == 8 )
            sub_453A80(unk_69E368);
          if ( object->frame == 16 )
            sub_453AB0(dword_48436C);
          if ( !object->frame )
          {
            sub_454EC0(object);
            object->unk32 &= 0xFFFFBFFF;
            sub_453A80(unk_5C78E4);
            v185 = rand();
            sub_454280(((v185 >> 31) ^ abs((_BYTE)v185) & 0xF) - (v185 >> 31) + 16);
            v186 = rand();
            sub_4542D0(v186 % 12);
            v187 = rand();
            sub_4540A0(v187 % 12 + 4, 0);
          }
          goto LABEL_988;
        case 5u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v188 = ((unsigned int)object->frame + 1) % (4 * m_shaker_mfb->numimages);
          object->frame = v188;
          if ( !((unsigned __int8)v188 % 0x14u) )
            sub_453AB0(dword_484374);
          if ( !object->frame )
          {
            sub_454EC0(object);
            Objects::Create(&MapObjects, object->owner_player, none_83, object->unk5, object->unk7, object->unk29);
          }
          goto LABEL_988;
        case 6u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v189 = ((unsigned int)object->frame + 1) % (4 * mharvest_mfb->numimages);
          object->frame = v189;
          if ( !(_BYTE)v189 )
          {
            v190 = object->unk82 - 1;
            object->unk82 = v190;
            if ( !v190 )
            {
              sub_454EC0(object);
              v191 = object->unk120;
              if ( v191 )
                sub_454ED0(v191, 5);
            }
          }
          if ( object->frame == 1 )
            sub_453AB0(dword_484378);
          goto LABEL_988;
        case 7u:
          if ( object->unk113 )
          {
            if ( !object->unk225 )
              sub_44F880(object);
            switch ( object->sex )
            {
              case 1u:
              case 2u:
                switch ( object->unk225 )
                {
                  case 0u:
                    object->frame = 0;
                    break;
                  case 4u:
                    object->frame = 1;
                    break;
                  case 8u:
                    object->frame = 2;
                    break;
                  case 0xCu:
                    object->frame = 3;
                    sub_44F900(object);
                    break;
                  case 0x10u:
                    object->frame = 4;
                    break;
                  case 0x14u:
                    object->frame = 0;
                    break;
                  default:
                    goto LABEL_549;
                }
                break;
              case 6u:
                switch ( object->unk225 )
                {
                  case 0u:
                    object->frame = 0;
                    break;
                  case 2u:
                    v192 = object->gen_period;
                    object->frame = 1;
                    object->unk30 = 16 * dword_5D1150[v192];
                    object->unk31 = 16 * dword_5D1558[v192];
                    break;
                  case 4u:
                    object->frame = 2;
                    sub_44F900(object);
                    break;
                  case 6u:
                    v193 = object->gen_period;
                    object->unk30 = -16 * dword_5D1150[v193];
                    object->unk31 = -16 * dword_5D1558[v193];
                    goto LABEL_548;
                  case 8u:
                    object->frame = 4;
                    break;
                  case 0xAu:
                    object->frame = 5;
                    object->unk30 = 0;
                    object->unk31 = 0;
                    sub_454ED0(object, 0);
                    break;
                  default:
                    goto LABEL_549;
                }
                break;
              case 7u:
                switch ( object->unk225 )
                {
                  case 0u:
                    object->frame = 0;
                    break;
                  case 4u:
                    object->frame = 1;
                    break;
                  case 8u:
                    object->frame = 2;
                    break;
                  case 0xCu:
                    goto LABEL_548;
                  case 0x10u:
                    object->frame = 4;
                    sub_44F900(object);
                    break;
                  case 0x14u:
                    object->frame = 5;
                    break;
                  default:
                    goto LABEL_549;
                }
                break;
              case 8u:
                switch ( object->unk225 )
                {
                  case 0u:
                    object->frame = 0;
                    sub_453AB0(dword_484384);
                    break;
                  case 2u:
                    object->frame = 1;
                    break;
                  case 4u:
                    object->frame = 2;
                    break;
                  case 6u:
                    v194 = object->gen_period;
                    object->frame = 3;
                    object->unk30 = 8 * dword_5D1150[v194];
                    object->unk31 = 8 * dword_5D1558[v194];
                    break;
                  case 8u:
                    object->frame = 4;
                    sub_44F900(object);
                    break;
                  case 0xAu:
                    v195 = object->gen_period;
                    object->frame = 5;
                    object->unk30 = -8 * dword_5D1150[v195];
                    object->unk31 = -8 * dword_5D1558[v195];
                    break;
                  case 0xCu:
                    object->frame = 6;
                    break;
                  case 0xEu:
                    object->unk30 = 0;
                    object->unk31 = 0;
                    object->frame = 7;
                    break;
                  default:
                    goto LABEL_549;
                }
                break;
              case 9u:
                if ( object->unk225 )
                {
                  if ( object->unk225 == 12 )
                    sub_44F900(object);
                }
                else
                {
                  object->frame = 0;
                }
                break;
              case 0x10u:
                switch ( object->unk225 )
                {
                  case 0u:
                    sub_453AB0(dword_484384);
                    object->frame = 0;
                    break;
                  case 2u:
                    v196 = object->gen_period;
                    object->frame = 1;
                    object->unk30 = 8 * dword_5D1150[v196];
                    object->unk31 = 8 * dword_5D1558[v196];
                    break;
                  case 4u:
                    object->frame = 2;
                    sub_44F900(object);
                    break;
                  case 6u:
                    v197 = object->gen_period;
                    object->frame = 3;
                    object->unk30 = -8 * dword_5D1150[v197];
                    object->unk31 = -8 * dword_5D1558[v197];
                    break;
                  case 8u:
                    object->frame = 4;
                    break;
                  case 0xAu:
                    object->frame = 5;
                    object->unk30 = 0;
                    object->unk31 = 0;
                    break;
                  default:
                    goto LABEL_549;
                }
                break;
              case 0x13u:
                switch ( object->unk225 )
                {
                  case 0u:
                    object->frame = 0;
                    break;
                  case 4u:
                    object->frame = 1;
                    break;
                  case 8u:
                    object->frame = 2;
                    sub_44F900(object);
                    break;
                  case 0xCu:
LABEL_548:
                    object->frame = 3;
                    break;
                  default:
                    goto LABEL_549;
                }
                break;
              default:
                break;
            }
LABEL_549:
            v198 = object->unk225 + 1;
            v199 = object->unk19;
            object->unk225 = v198;
            if ( (unsigned __int8)unk_6AFF88[35 * v199] <= v198 )
              object->unk225 = 0;
          }
          else
          {
            sub_454ED0(object, 0);
            sub_4473A0(object);
          }
          goto LABEL_988;
        case 9u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v200 = object->frame + 1;
          v201 = object->sex;
          v202 = (HIDWORD(v200) ^ abs(object->frame + 1) & 0xF) - HIDWORD(v200);
          object->frame = v202;
          if ( v201 == 4 )
          {
            v203 = (unsigned __int8)v202 + 1;
            object->frame = (BYTE4(v203) ^ ((BYTE4(v203) ^ v203) - BYTE4(v203)) & 0xF) - BYTE4(v203);
          }
          v204 = object->frame;
          if ( v204 )
          {
            if ( v204 == 4 )
              sub_453AB0(dword_484360);
          }
          else
          {
            v205 = object->unk82 - 1;
            object->unk82 = v205;
            if ( !v205 )
            {
              sub_454EC0(object);
              v206 = object->unk99;
              if ( v206 )
              {
                sub_454ED0(v206, 61);
                v207 = object->unk99->unk116;
                if ( v207 )
                {
                  --v207->state_id;
                  v208 = object->unk99->unk116;
                  if ( !v208->state_id && v208->class_id != 122 )
                    sub_453A00(dword_554FA8, 0, 0);
                }
                object->unk99 = 0;
              }
            }
          }
          goto LABEL_988;
        case 0xAu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v209 = object->frame + 1;
          v210 = object->sex;
          v211 = (HIDWORD(v209) ^ abs(object->frame + 1) & 0xF) - HIDWORD(v209);
          object->frame = v211;
          if ( v210 == 4 )
          {
            v212 = (unsigned __int8)v211 + 1;
            object->frame = (BYTE4(v212) ^ ((BYTE4(v212) ^ v212) - BYTE4(v212)) & 0xF) - BYTE4(v212);
          }
          if ( !object->frame )
          {
            v213 = object->unk82 - 1;
            object->unk82 = v213;
            if ( v213 )
            {
              sub_453AB0(dword_484380);
            }
            else
            {
              sub_454EC0(object);
              v214 = object->unk99;
              if ( v214 )
              {
                sub_454ED0(v214, 63);
                v215 = object->unk99->unk116;
                if ( v215 )
                  --v215->state_id;
                object->unk99 = 0;
              }
            }
          }
          goto LABEL_988;
        case 0xBu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v216 = object->frame + 1;
          v217 = object->sex;
          v218 = (HIDWORD(v216) ^ abs(object->frame + 1) & 0xF) - HIDWORD(v216);
          object->frame = v218;
          if ( v217 == 4 )
          {
            v219 = (unsigned __int8)v218 + 1;
            object->frame = (BYTE4(v219) ^ ((BYTE4(v219) ^ v219) - BYTE4(v219)) & 0xF) - BYTE4(v219);
          }
          v220 = object->frame;
          if ( v220 )
          {
            if ( v220 == 8 )
              sub_453AB0(dword_48437C);
          }
          else
          {
            v221 = object->unk82 - 1;
            object->unk82 = v221;
            if ( !v221 )
            {
              sub_454EC0(object);
              v222 = object->unk99;
              if ( v222 )
              {
                sub_454ED0(v222, 66);
                v223 = object->unk99->unk116;
                if ( v223 )
                {
                  --v223->state_id;
                  v224 = object->unk99->unk116;
                  sub_43FB50(
                    object,
                    v224->x + *(unsigned int *)((char *)&unk_6638AE + 914 * v224->class_id),
                    v224->y + *(unsigned int *)((char *)&unk_6638B2 + 914 * v224->class_id));
                }
                object->unk99 = 0;
              }
            }
          }
          goto LABEL_988;
        case 0xCu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v225 = ((unsigned int)object->frame + 1) % (4 * m_chop_mfb->numimages);
          object->frame = v225;
          if ( !(_BYTE)v225 )
          {
            v226 = object->unk82 - 1;
            object->unk82 = v226;
            if ( v226 )
              sub_453AB0(dword_484360);
            else
              sub_454EC0(object);
          }
          goto LABEL_988;
        case 0xDu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v227 = object->frame + 1;
          object->frame = v227;
          if ( v227 == 32 )
          {
            v228 = object->unk99;
            if ( v228 && (signed __int16)v228->health < (signed __int16)v228->health_max )
            {
              sub_450820((int)v228, 4);
              object->frame = 16;
            }
          }
          else if ( v227 == 44 )
          {
            sub_454EC0(object);
            object->frame = 0;
          }
          goto LABEL_988;
        case 0xEu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v229 = object->frame + 1;
          object->frame = v229;
          if ( v229 == 32 )
          {
            sub_454EC0(object);
            object->frame = 0;
          }
          goto LABEL_988;
        case 0x5Du:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v230 = ((unsigned int)object->frame + 1) % (4 * milking_mfb->numimages);
          object->frame = v230;
          if ( (_BYTE)v230 )
          {
            if ( (_BYTE)v230 == 1 )
              sub_453AB0(dword_4843D0);
          }
          else
          {
            v231 = object->unk82 + 1;
            object->unk82 = v231;
            if ( v231 == 12 )
            {
              object->unk82 = 0;
              v232 = object->unk120;
              if ( v232 )
                sub_454EC0(v232);
              sub_454EC0(object);
            }
          }
          goto LABEL_988;
        case 0x73u:
          v233 = object->unk83 + 1;
          object->unk83 = v233;
          if ( v233 >= 0x24u )
          {
            v234 = object->data10[0] + 1;
            v235 = object->data9[0];
            object->data10[0] = v234;
            object->unk83 = 0;
            switch ( v235 )
            {
              case 0:
                if ( v234 == 1 )
                {
                  v236 = rand() % -2;
                  if ( v236 >= 0 && v236 <= 1 )
                    sub_453A80(unk_6034DC);
                }
                else if ( v234 == 4 )
                {
                  sub_453450((int)object, 250);
                  sub_454EC0(object);
                }
                break;
              case 1:
                switch ( v234 )
                {
                  case 1u:
                    sub_453A80(unk_6A8F10);
                    break;
                  case 4u:
                    v237 = (char *)unk_60362C;
                    if ( !unk_60362C )
                      v237 = byte_48481C;
                    sub_41E1F0(object, v237);
                    v238 = rand();
                    sub_454140(((v238 >> 31) ^ abs((_BYTE)v238) & 0xF) - (v238 >> 31) + 16, 0);
                    v239 = rand();
                    sub_4540A0(v239 % -32, 0);
                    if ( object->spouse )
                      sub_4540A0(-32, 0);
                    break;
                  case 0x14u:
                    sub_454EC0(object);
                    break;
                }
                break;
              case 2:
                switch ( v234 )
                {
                  case 4u:
                    v240 = (char *)unk_6038A0;
                    if ( !unk_6038A0 )
                      v240 = byte_48481C;
                    sub_41E1F0(object, v240);
                    v241 = rand();
                    sub_453A80(dword_662C88[v241 % -2]);
                    break;
                  case 5u:
                    v242 = rand();
                    sub_453A80(dword_662C88[v242 % -2]);
                    break;
                  case 6u:
                    sub_4508A0(object, object->health / 2, 0);
                    break;
                  case 7u:
                    sub_453A00(unk_63F048, 0, 0);
                    v243 = rand();
                    sub_454140(((v243 >> 31) ^ abs((_BYTE)v243) & 0x1F) - (v243 >> 31) + 48, 0);
                    if ( object->spouse )
                      sub_4540A0(-64, 0);
                    sub_454EC0(object);
                    break;
                  default:
                    goto LABEL_989;
                }
                break;
              case 3:
                switch ( v234 )
                {
                  case 1u:
                    sub_453A80(unk_600030);
                    break;
                  case 4u:
                    v244 = rand();
                    sub_453A80(dword_5E46F0[v244 % 6]);
                    break;
                  case 7u:
                    v245 = (char *)unk_6038A4;
                    if ( !unk_6038A4 )
                      v245 = byte_48481C;
                    sub_41E1F0(object, v245);
                    sub_453AB0(dword_484384);
                    sub_453AB0(dword_4843C0);
                    sub_4508A0(object, 1000, 0);
                    sub_454EC0(object);
                    if ( object->spouse )
                      sub_4540A0(-100, 0);
                    break;
                }
                break;
              default:
                goto LABEL_989;
            }
          }
          goto LABEL_989;
        case 0x74u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v246 = object->frame + 1;
          LODWORD(v246) = (HIDWORD(v246) ^ abs(object->frame + 1) & 0xF) - HIDWORD(v246);
          object->frame = v246;
          if ( !(_BYTE)v246 )
          {
            v247 = object->unk99;
            if ( v247 )
            {
              sub_453EE0((int)v247, 20, 0);
              sub_437EE0(object->unk99);
              if ( object->unk99->health == object->unk99->health_max )
              {
                sub_454EC0(object);
                sub_453AB0(dword_48437C);
                sub_453A00(dword_554FA8, 0, 0);
                v248 = object->unk99;
                v249 = v248->unk32;
                v250 = &v248->unk32;
                if ( v249 & 0x80000 )
                  *v250 = v249 & 0xFFF7FFFF;
                sub_43FB50(
                  object,
                  object->unk99->x + *(unsigned int *)((char *)&unk_6638AE + 914 * object->unk99->class_id),
                  object->unk99->y + *(unsigned int *)((char *)&unk_6638B2 + 914 * object->unk99->class_id));
              }
              else
              {
                sub_453AB0(dword_48437C);
              }
            }
            else
            {
              sub_454EC0(object);
            }
          }
          goto LABEL_988;
        case 0x75u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v251 = object->frame + 1;
          LODWORD(v251) = (HIDWORD(v251) ^ abs(object->frame + 1) & 0xF) - HIDWORD(v251);
          object->frame = v251;
          if ( !(_BYTE)v251 )
          {
            v252 = object->unk99;
            if ( !v252 || (sub_4508A0(v252, 30, 0), v253 = object->unk99->unk32, BYTE1(v253) & 0x10) )
              sub_454EC0(object);
            else
              sub_453AB0(dword_484360);
          }
          goto LABEL_988;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case creature:
      if ( !object->field_F2 )
      {
        v254 = object->unk225;
        if ( v254 )
        {
          v255 = v254 + 1;
          v256 = object->unk19;
          object->unk225 = v255;
          if ( (unsigned __int8)unk_6AFF88[35 * v256] <= v255 )
            object->unk225 = 0;
        }
        goto LABEL_989;
      }
      if ( object->field_F2 != 7 )
        goto LABEL_989;
      if ( object->unk113 || object->unk225 < 0x14u )
      {
        if ( !object->unk225 )
          sub_44F880(object);
        switch ( object->sex )
        {
          case 0xFu:
          case 0x16u:
            v257 = object->unk225;
            if ( object->unk225 )
            {
              if ( v257 == 4 )
              {
                object->frame = 1;
                sub_44F900(object);
              }
              else if ( v257 == 8 )
              {
                object->frame = 0;
              }
            }
            else
            {
              object->frame = 0;
            }
            break;
          case 0x12u:
            switch ( object->unk225 )
            {
              case 0u:
                object->frame = 0;
                break;
              case 4u:
                object->frame = 1;
                break;
              case 8u:
                object->frame = 2;
                sub_44F900(object);
                break;
              case 0xCu:
                object->frame = 3;
                break;
              default:
                goto LABEL_722;
            }
            break;
          case 0x17u:
          case 0x1Du:
            switch ( object->unk225 )
            {
              case 0u:
                v258 = object->gen_period;
                object->frame = 0;
                object->unk30 = 8 * dword_5D1150[v258];
                object->unk31 = 8 * dword_5D1558[v258];
                break;
              case 2u:
                object->frame = 1;
                sub_44F900(object);
                break;
              case 4u:
                v259 = object->gen_period;
                object->unk30 = -8 * dword_5D1150[v259];
                object->unk31 = -8 * dword_5D1558[v259];
                break;
              case 8u:
                object->frame = 0;
                object->unk30 = 0;
                object->unk31 = 0;
                break;
              default:
                goto LABEL_722;
            }
            break;
          case 0x18u:
          case 0x1Cu:
            switch ( object->unk225 )
            {
              case 0u:
                object->frame = 0;
                break;
              case 2u:
                v260 = object->gen_period;
                object->frame = 1;
                object->unk30 = 16 * dword_5D1150[v260];
                object->unk31 = 16 * dword_5D1558[v260];
                break;
              case 4u:
                object->frame = 2;
                sub_44F900(object);
                break;
              case 6u:
                v261 = object->gen_period;
                object->frame = 3;
                object->unk30 = -16 * dword_5D1150[v261];
                object->unk31 = -16 * dword_5D1558[v261];
                break;
              case 8u:
                object->frame = 4;
                break;
              case 0xAu:
                object->frame = 5;
                object->unk30 = 0;
                object->unk31 = 0;
                break;
              default:
                goto LABEL_722;
            }
            break;
          case 0x19u:
            switch ( object->unk225 )
            {
              case 0u:
                v262 = object->gen_period;
                object->frame = 0;
                object->unk30 = 16 * dword_5D1150[v262];
                object->unk31 = 16 * dword_5D1558[v262];
                break;
              case 2u:
                object->frame = 1;
                sub_44F900(object);
                break;
              case 4u:
                v263 = object->gen_period;
                object->frame = 0;
                object->unk30 = -16 * dword_5D1150[v263];
                object->unk31 = -16 * dword_5D1558[v263];
                break;
              case 8u:
                object->unk30 = 0;
                object->unk31 = 0;
                break;
              default:
                goto LABEL_722;
            }
            break;
          case 0x1Au:
            if ( !object->unk225 )
              sub_44F900(object);
            break;
          case 0x1Bu:
            switch ( object->unk225 )
            {
              case 0u:
                object->frame = 0;
                break;
              case 2u:
                object->frame = 1;
                break;
              case 4u:
                v264 = object->gen_period;
                object->frame = 2;
                object->unk30 = 16 * dword_5D1150[v264];
                object->unk31 = 16 * dword_5D1558[v264];
                break;
              case 6u:
                object->frame = 3;
                sub_44F900(object);
                break;
              case 8u:
                v265 = object->gen_period;
                object->unk30 = -16 * dword_5D1150[v265];
                object->unk31 = -16 * dword_5D1558[v265];
                break;
              case 0xCu:
                object->frame = 4;
                object->unk30 = 0;
                object->unk31 = 0;
                break;
              default:
                goto LABEL_722;
            }
            break;
          case 0x1Eu:
            switch ( object->unk225 )
            {
              case 0u:
                object->frame = 0;
                break;
              case 2u:
                object->frame = 1;
                break;
              case 4u:
                object->frame = 2;
                break;
              case 6u:
                object->frame = 3;
                break;
              case 8u:
                object->frame = 4;
                break;
              case 0xAu:
                object->frame = 5;
                sub_44F900(object);
                break;
              case 0xCu:
                object->frame = 6;
                break;
              case 0xEu:
                object->frame = 7;
                break;
              default:
                goto LABEL_722;
            }
            break;
          case 0x1Fu:
            switch ( object->unk225 )
            {
              case 0u:
                object->frame = 0;
                break;
              case 2u:
                object->frame = 1;
                break;
              case 4u:
                object->frame = 2;
                break;
              case 6u:
                object->frame = 3;
                break;
              case 8u:
                object->frame = 4;
                break;
              case 0xAu:
                object->frame = 5;
                sub_44F900(object);
                break;
              case 0xCu:
                object->frame = 6;
                break;
              case 0xEu:
                object->frame = 7;
                break;
              case 0x10u:
                object->frame = 8;
                break;
              default:
                goto LABEL_722;
            }
            break;
          default:
            break;
        }
LABEL_722:
        v266 = object->unk225 + 1;
        v267 = object->unk19;
        object->unk225 = v266;
        if ( (unsigned __int8)unk_6AFF88[35 * v267] <= v266 )
          object->unk225 = 0;
      }
      else
      {
        sub_454ED0(object, 0);
        sub_4473A0(object);
      }
      goto LABEL_988;
    case cow:
      if ( object->field_F2 == 53 )
      {
        v268 = object->unk82 + 1;
        object->unk82 = v268;
        if ( v268 >= 0x34u )
        {
          object->unk82 = 0;
          sub_454ED0(object, 0);
        }
        sub_437EE0(object);
      }
      if ( object->field_F2 == 54 )
      {
        ++object->frame;
        sub_454ED0(object, 0);
        sub_437EE0(object);
      }
      if ( object->field_F2 == 94 )
      {
        v269 = object->unk120;
        if ( !v269 )
          goto LABEL_1000;
        if ( v269->unk120 != object )
          object->unk120 = 0;
        if ( !object->unk120 )
LABEL_1000:
          sub_454ED0(object, 0);
      }
      if ( object->is_going )
        object->state_id = (object->state_id + 1) % 14;
      goto LABEL_989;
    case rockpile:
      if ( object->field_F2 != 60 )
        goto LABEL_989;
      v270 = object->unk225 + 1;
      object->unk225 = v270;
      if ( v270 <= 0xC8u )
        goto LABEL_989;
      sub_454ED0(object, 0);
      goto LABEL_988;
    case woodpile:
      if ( object->field_F2 != 62 )
        goto LABEL_989;
      v271 = object->unk225 + 1;
      object->unk225 = v271;
      if ( v271 <= 0xC8u )
        goto LABEL_989;
      sub_454ED0(object, 0);
      goto LABEL_988;
    case hammer_point:
      if ( object->field_F2 != 65 )
        goto LABEL_989;
      v272 = object->unk225 + 1;
      object->unk225 = v272;
      if ( v272 <= 0xC8u )
        goto LABEL_989;
      sub_454ED0(object, 0);
      goto LABEL_988;
    case none_84:
      v273 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v273;
      if ( !(_BYTE)v273 )
        goto LABEL_987;
      goto LABEL_988;
    case none_8D:
      switch ( object->field_F2 )
      {
        case 0x47u:
          if ( object->unk99 )
          {
            Objects::Create(&MapObjects, object->owner_player, none_E6, object->unk5, object->unk7, object->unk29);
            sub_453AB0(dword_4843A0);
            for ( k = sub_4340B0(&MapObjects, object->x, object->y, 8);
                  k;
                  k = sub_434120(&MapObjects, k, object->x, object->y, 8) )
            {
              v275 = object->owner_player;
              if ( k->owner_player != v275 )
              {
                v276 = k->class_id;
                if ( v276 >= 36 && (v276 <= 37 || v276 == 93) )
                  Objects::Create(&MapObjects, v275, trap_detected, k->unk5, k->unk7, k->unk29)->state_id = k->class_id;
              }
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x48u:
          v277 = object->unk99;
          if ( v277 )
          {
            object->gen_period = byte_5FDA98[((object->y - object->unk99->y) << 6) - object->unk99->x + object->x];
            v278 = Objects::Create(&MapObjects, object->owner_player, none_C4, v277->unk5, v277->unk7, v277->unk29);
            v278->gen_period = object->gen_period;
            v278->unk63 = sub_401D70(2 * dword_5D1150[object->gen_period], 0x40000);
            v278->unk64 = sub_401D70(2 * dword_5D1558[object->gen_period], 0x40000);
            v278->unk30 = v278->unk63;
            v278->unk31 = v278->unk64;
            v278->unk77 = object->x;
            v278->unk78 = object->y;
            v278->unk99 = object;
            sub_453AB0(dword_484390);
          }
          sub_453A80(unk_6A9938);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x49u:
          for ( l = sub_4340B0(&MapObjects, object->x, object->y, 5);
                l;
                l = sub_434120(&MapObjects, l, object->x, object->y, 5) )
          {
            if ( l->class_id == 103 && l->owner_player != object->owner_player )
              l->disease = rand() % 3;
          }
          sub_453AB0(dword_484394);
          sub_415730(unk_5F9150);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Au:
          for ( m = sub_4340B0(&MapObjects, object->x, object->y, 5);
                m;
                m = sub_434120(&MapObjects, m, object->x, object->y, 5) )
          {
            if ( m->owner_player == object->owner_player && m->class_id == 103 )
            {
              m->unk32 |= 0x40000000u;
              m->unk235235 = -1;
              sub_437EE0(m);
            }
          }
          sub_453AB0(dword_484398);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Bu:
          v281 = object->state_id;
          if ( !v281 || v281 == 40 )
            sub_453AB0(dword_484398);
          v282 = object->state_id;
          if ( v282 >= 0x24u )
          {
            if ( v282 >= 0x26u )
            {
              if ( v282 >= 0x28u )
              {
                if ( v282 >= 0x2Au )
                {
                  if ( v282 >= 0x3Au )
                  {
                    v283 = Objects::Create(&MapObjects, 4u, creature, object->unk5, object->unk7, object->unk29);
                    sub_437F30(v283, 18);
                    v283->unk32 |= 0x80000000;
                    sub_4342C0(&MapObjects, object);
                  }
                  else
                  {
                    object->frame = ((unsigned __int8)(v282 & 2) >> 1) + 8;
                  }
                }
                else
                {
                  object->frame = 8;
                }
              }
              else
              {
                object->frame = 7;
              }
            }
            else
            {
              object->frame = 6;
            }
          }
          else
          {
            object->frame = (v282 >> 1) % 6u;
          }
          sub_437EE0(object);
          ++object->state_id;
          goto LABEL_989;
        case 0x4Cu:
          Objects::Create(&MapObjects, object->owner_player, none_2A, object->unk5, object->unk7, object->unk29);
          sub_453AB0(dword_484398);
          sub_415730(unk_5F9158);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Du:
          v284 = Objects::Create(&MapObjects, object->owner_player, none_2B, object->unk5, object->unk7, object->unk29);
          sub_454ED0(v284, 17);
          sub_453AB0(dword_484338);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Eu:
          Objects::Create(&MapObjects, object->owner_player, none_E7, object->unk5, object->unk7, object->unk29);
          sub_453AB0(dword_484338);
          for ( n = sub_4340B0(&MapObjects, object->x, object->y, 5);
                n;
                n = sub_434120(&MapObjects, n, object->x, object->y, 5) )
          {
            if ( n->disease )
            {
              n->disease = 0;
              n->unk235235 = 36;
              n->data7[1] = 1;
              sub_437EE0(n);
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Fu:
          sub_453AB0(dword_484338);
          v286 = sub_4340B0(&MapObjects, object->x, object->y, 5);
          if ( !v286 )
            goto LABEL_809;
          break;
        case 0x50u:
          Objects::Create(&MapObjects, object->owner_player, none_E6, object->unk5, object->unk7, object->unk29);
          Objects::Create(&MapObjects, object->owner_player, none_E0, object->unk5, object->unk7, object->unk29);
          sub_453AB0(dword_48439C);
          for ( ii = sub_4340B0(&MapObjects, object->x, object->y, 5);
                ii;
                ii = sub_434120(&MapObjects, ii, object->x, object->y, 5) )
          {
            if ( ii->owner_player != object->owner_player )
            {
              v290 = ii->class_id;
              if ( v290 >= 103 && (v290 <= 104 || v290 == 110) )
                sub_455240(object);
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x51u:
          v291 = object->unk99;
          if ( v291 )
          {
            object->gen_period = byte_5FDA98[((object->y - object->unk99->y) << 6) - object->unk99->x + object->x];
            v292 = Objects::Create(&MapObjects, object->owner_player, none_DF, v291->unk5, v291->unk7, v291->unk29);
            v292->gen_period = object->gen_period;
            v292->unk63 = sub_401D70(2 * dword_5D1150[object->gen_period], 0x40000);
            v292->unk64 = sub_401D70(2 * dword_5D1558[object->gen_period], 0x40000);
            v292->unk30 = v292->unk63;
            v292->unk31 = v292->unk64;
            v292->unk77 = object->x;
            v292->unk78 = object->y;
            v292->unk99 = object;
            sub_453AB0(dword_484390);
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x65u:
          v293 = object->unk99;
          if ( v293 )
          {
            Objects::Create(&MapObjects, object->owner_player, none_E6, v293->unk5, v293->unk7, v293->unk29);
            sub_453AB0(dword_484348);
            sub_437EE0(object);
            v294 = object->unk99;
            sub_43F970(object->x, object->y);
            Objects::Create(
              &MapObjects,
              object->owner_player,
              none_E6,
              object->unk99->unk5,
              object->unk99->unk7,
              object->unk99->unk29);
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x66u:
          sub_453AB0(dword_484338);
          for ( jj = sub_4340B0(&MapObjects, object->x, object->y, 5);
                jj;
                jj = sub_434120(&MapObjects, jj, object->x, object->y, 5) )
          {
            if ( jj->owner_player == object->owner_player
              && jj->class_id == 103
              && (signed __int16)jj->health < (signed __int16)jj->health_max )
            {
              sub_453EE0((int)jj, 100, 0);
              sub_437EE0(jj);
              jj->unk235235 = 36;
              jj->data7[1] = 1;
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x67u:
          sub_453AB0(dword_484338);
          for ( kk = sub_4340B0(&MapObjects, object->x, object->y, 1);
                kk;
                kk = sub_434120(&MapObjects, kk, object->x, object->y, 1) )
          {
            if ( kk->owner_player == object->owner_player && kk->class_id == 103 )
            {
              sub_453EE0((int)kk, 64, 0);
              sub_454280(32);
              sub_4542D0(32);
              sub_4540A0(64, 0);
              sub_454320(32);
              kk->unk235235 = 36;
              kk->data7[1] = 2;
              sub_437EE0(kk);
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        default:
          goto LABEL_989;
      }
      break;
    case none_8E:
      v297 = object->gen_period;
      v298 = 4 * dword_5D1150[v297];
      object->unk63 = v298;
      v299 = 4 * dword_5D1558[v297];
      object->unk30 = v298;
      v300 = object->field_F2;
      v301 = object->health - 1;
      object->unk64 = v299;
      object->health = v301;
      object->unk31 = v299;
      if ( !v300 && unk_6635AE[457 * object_class_id] - 16 > v301 )
        sub_454ED0(object, 69);
      if ( object->health <= 0 || MapTiles[object->x + 192 * object->y].road && object->field_F2 == 69 )
      {
        sub_4342C0(&MapObjects, object);
        v302 = rand();
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 1, v302 % 40 + 40);
        Objects::Create(&MapObjects, object->owner_player, explosion, object->unk5, object->unk7, object->unk29);
      }
      goto LABEL_988;
    case campfire:
      object->frame = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      goto LABEL_988;
    case none_93:
      v303 = object->unk64;
      v304 = object->field_F2;
      object->unk30 = object->unk63;
      object->unk31 = v303;
      if ( v304 == 70 && object->unk62 > 0 )
      {
        object->unk63 = 0;
        object->unk64 = 0;
        object->unk30 = 0;
        v305 = object->x;
        v306 = object->y << 6;
        object->unk62 = 0;
        object->unk31 = 0;
        object->unk29 = MapTiles[v305 + 3 * v306].texture << 16;
        sub_454ED0(object, 91);
        object->unk225 = 72;
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      v307 = object->field_F2;
      if ( v307 != 91 )
      {
        v309 = (object->gen_period + 16) / 32;
        v310 = (HIDWORD(v309) ^ abs((_BYTE)v309) & 7) - HIDWORD(v309);
        v311 = object->unk62;
        object->state_id = v310;
        if ( v311 >= 4294951296 )
        {
          if ( v311 < 4294963200 )
          {
            object->frame = byte_484683[5 * (unsigned __int8)v310];
            if ( !v307 )
              sub_454ED0(object, 70);
            goto LABEL_988;
          }
          if ( v311 < 4096 )
          {
            object->frame = byte_484682[5 * (unsigned __int8)v310];
            if ( !v307 )
              sub_454ED0(object, 70);
            goto LABEL_988;
          }
          if ( v311 < 0 )
          {
            object->frame = byte_484682[5 * (unsigned __int8)v310];
            if ( !v307 )
              sub_454ED0(object, 70);
            goto LABEL_988;
          }
          if ( v311 >= 16000 )
            v312 = byte_484680[5 * (unsigned __int8)v310];
          else
            v312 = byte_484681[5 * (unsigned __int8)v310];
        }
        else
        {
          v312 = byte_484684[5 * (unsigned __int8)v310];
        }
        object->frame = v312;
        goto LABEL_988;
      }
      v308 = object->unk225 - 1;
      object->unk225 = v308;
      if ( !v308 )
        sub_4342C0(&MapObjects, object);
      goto LABEL_988;
    case none_94:
    case none_A4:
      v313 = object->gen_period;
      v314 = 16 * dword_5D1150[v313];
      object->unk63 = v314;
      v315 = 16 * dword_5D1558[v313];
      object->unk30 = v314;
      object->unk64 = v315;
      object->unk31 = v315;
      v316 = object->frame + 1;
      v317 = object->health - 1;
      LOBYTE(v316) = abs(object->frame + 1);
      object->health = v317;
      x = object->x;
      object->frame = (BYTE4(v316) ^ v316 & 0xF) - BYTE4(v316);
      y = object->y;
      if ( MapTiles[x + 192 * y].road || object->unk77 == x && object->unk78 == y || (signed __int16)v317 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        v320 = object->class_id;
        if ( v320 == -108 || v320 == -92 )
          sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case none_95:
      v321 = object->gen_period;
      v322 = 16 * dword_5D1150[v321];
      object->unk63 = v322;
      v323 = 16 * dword_5D1558[v321];
      object->unk30 = v322;
      object->unk64 = v323;
      object->unk31 = v323;
      v324 = object->health - 1;
      v325 = object->frame + 1;
      object->health = v324;
      v326 = object->y;
      v327 = v325 % 12;
      v328 = object->x;
      object->frame = v327;
      if ( MapTiles[v328 + 192 * v326].road
        || object->unk77 == v328 && object->unk78 == v326
        || (signed __int16)v324 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case none_9C:
      v329 = object->gen_period;
      v330 = 16 * dword_5D1150[v329];
      object->unk63 = v330;
      v331 = 16 * dword_5D1558[v329];
      object->unk30 = v330;
      object->unk64 = v331;
      object->unk31 = v331;
      v332 = object->health - 1;
      v333 = object->frame + 1;
      object->health = v332;
      v334 = object->y;
      v335 = v333 % 12;
      v336 = object->x;
      object->frame = v335;
      if ( MapTiles[v336 + 192 * v334].road
        || object->unk77 == v336 && object->unk78 == v334
        || (signed __int16)v332 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case gate:
      if ( object->field_F2 == 97 )
      {
        v337 = object->unk225;
        if ( v337 )
        {
          object->unk225 = v337 - 1;
        }
        else if ( !(MapTiles[object->x + 192 * object->y].mask_manstand & 1) )
        {
          sub_454ED0(object, 95);
          sub_453AB0(dword_484324);
          sub_437EE0(object);
        }
      }
      if ( object->field_F2 != 95 )
        goto LABEL_1001;
      v338 = object->unk225;
      if ( v338 )
      {
        v339 = v338 - 1;
        object->unk225 = v339;
        if ( !v339 )
          MapTiles[object->x + 192 * object->y].road = 0;
      }
      if ( object->field_F2 != 95 )
      {
LABEL_1001:
        v341 = object->state_id;
        if ( v341 >= 2u )
          goto LABEL_989;
        object->state_id = v341 + 1;
      }
      else
      {
        v340 = object->state_id;
        if ( !v340 )
          goto LABEL_989;
        object->state_id = v340 - 1;
      }
      goto LABEL_988;
    case trap_detected:
    case none_E3:
      v342 = object->unk225 - 1;
      object->unk225 = v342;
      if ( !v342 )
        goto LABEL_987;
      goto LABEL_988;
    case none_C3:
      v343 = object->frame + 1;
      object->frame = v343;
      if ( v343 == 24 && object->unk99 )
      {
        sub_43F970(object->data3[1], object->data3[2]);
        sub_43FAE0(object->unk99, object->data3[1] + 1, object->data3[2] + 1, 0);
      }
      if ( object->frame == 48 )
        goto LABEL_987;
      goto LABEL_988;
    case none_C4:
      v344 = object->gen_period;
      v345 = 16 * dword_5D1150[v344];
      object->unk63 = v345;
      v346 = 16 * dword_5D1558[v344];
      object->unk30 = v345;
      object->unk64 = v346;
      object->unk31 = v346;
      v347 = object->health - 1;
      v348 = object->frame + 1;
      object->health = v347;
      v349 = object->y;
      v350 = v348 % 12;
      v351 = object->x;
      object->frame = v350;
      if ( MapTiles[v351 + 192 * v349].road
        || object->unk77 == v351 && object->unk78 == v349
        || (signed __int16)v347 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        v352 = rand();
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, v352 % 60 + 60);
        Objects::Create(&MapObjects, object->owner_player, explosion, object->unk5, object->unk7, object->unk29);
        Objects::Create(&MapObjects, object->owner_player, fire, object->unk5, object->unk7, object->unk29)->health = 10;
      }
      goto LABEL_988;
    case magic_gate:
      switch ( object->field_F2 )
      {
        case 0u:
          object->frame = 0;
          break;
        case 0x6Au:
          object->frame = 5;
          break;
        case 0x6Cu:
          v353 = object->state_id + 1;
          object->state_id = v353;
          if ( v353 >= 4u )
          {
            object->state_id = 0;
            v354 = object->frame + 1;
            object->frame = v354;
            if ( v354 == 1 )
              sub_453AB0(dword_4842DC);
            if ( object->frame >= 5u )
            {
              sub_454ED0(object, 106);
              if ( MapTiles[object->x + 192 * object->y].road )
                sub_448890(object);
            }
            goto LABEL_988;
          }
          break;
        case 0x6Du:
          v355 = object->state_id + 1;
          object->state_id = v355;
          if ( v355 >= 4u )
          {
            object->state_id = 0;
            v356 = object->frame;
            if ( v356 )
              object->frame = v356 - 1;
            if ( object->frame == 4 && !MapTiles[object->x + 192 * object->y].road )
              sub_448490(object);
            if ( !object->frame )
              sub_454ED0(object, 0);
            goto LABEL_988;
          }
          break;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case smoke:
      v357 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v357;
      if ( !(_BYTE)v357 )
        goto LABEL_987;
      goto LABEL_988;
    case explosion:
      v358 = ((unsigned int)object->frame + 1) % (2 * object->mfb_file->numimages);
      object->frame = v358;
      if ( !(_BYTE)v358 )
        goto LABEL_987;
      goto LABEL_988;
    case smoke1:
      v359 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v359;
      if ( !(_BYTE)v359 )
        object->frame = 16;
      v360 = object->health - 1;
      object->health = v360;
      if ( (signed __int16)v360 <= 0 )
        goto LABEL_987;
      goto LABEL_988;
    case none_CD:
      v361 = object->gen_period;
      object->unk30 = 16 * dword_5D1150[v361];
      v362 = object->x;
      v363 = object->data3[1];
      object->unk31 = 16 * dword_5D1558[v361];
      v364 = object->health - 1;
      object->health = v364;
      if ( v363 == v362 && object->data3[2] == object->y || (signed __int16)v364 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, 40);
        Objects::Create(&MapObjects, object->owner_player, smoke, object->unk5, object->unk7, object->unk29);
        sub_453AB0(dword_4843A4);
      }
      v365 = object->unk225;
      if ( v365 )
        object->unk225 = v365 - 1;
      else
        object->unk225 = 4;
      goto LABEL_988;
    case none_D1:
      v366 = object->gen_period;
      v367 = 16 * dword_5D1150[v366];
      object->unk63 = v367;
      v368 = 16 * dword_5D1558[v366];
      object->unk30 = v367;
      object->unk64 = v368;
      object->unk31 = v368;
      v369 = object->health - 1;
      v370 = object->frame + 1;
      object->health = v369;
      v371 = object->y;
      v372 = v370 % 12;
      v373 = object->x;
      object->frame = v372;
      if ( MapTiles[v373 + 192 * v371].road
        || object->unk77 == v373 && object->unk78 == v371
        || (signed __int16)v369 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case lever:
      switch ( object->field_F2 )
      {
        case 0u:
          object->frame = 0;
          break;
        case 0x6Eu:
          object->frame = 2;
          break;
        case 0x6Fu:
          v374 = object->gen_period + 1;
          object->gen_period = v374;
          if ( v374 >= 4u )
          {
            object->gen_period = 0;
            v375 = object->frame + 1;
            object->frame = v375;
            if ( v375 >= 2u )
              sub_454ED0(object, 110);
            goto LABEL_988;
          }
          break;
        case 0x70u:
          v376 = object->gen_period + 1;
          object->gen_period = v376;
          if ( v376 >= 4u )
          {
            object->gen_period = 0;
            v377 = object->frame;
            if ( !v377 || (object->frame = v377 - 1) == 0 )
              sub_454ED0(object, 0);
            goto LABEL_988;
          }
          break;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case lookout_post:
      v378 = object->gen_period;
      v379 = object->gen_max;
      if ( v378 >= v379 )
      {
        if ( v378 <= v379 )
          goto LABEL_965;
        if ( v378 - v379 >= 128 )
          v380 = v378 + 4;
        else
          v380 = v378 - 4;
      }
      else if ( v379 - v378 >= 128 )
      {
        v380 = v378 - 4;
      }
      else
      {
        v380 = v378 + 4;
      }
      object->gen_period = v380;
      sub_437EE0(object);
LABEL_965:
      v381 = object->gen_period;
      if ( object->gen_max == v381 )
        object->frame = (unsigned __int8)(v381 & 0xDF) >> 5;
      else
        object->frame = 2
                      * ((((v381 + 32) / 64 >> 31) ^ abs((unsigned __int8)((v381 + 32) / 64)) & 3)
                       - ((v381 + 32) / 64 >> 31))
                      + 1;
      sub_437EE0(object);
      v382 = object->unk225;
      if ( !v382 )
        goto LABEL_989;
      v383 = v382 - 1;
      object->unk225 = v383;
      if ( !v383 && object->owner_player == cur_player )
        --dword_484410;
      goto LABEL_988;
    case none_DE:
      if ( object->unk62 > 0 )
      {
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 3, 1000);
        v384 = 3;
        Objects::Create(&MapObjects, object->owner_player, explosion, object->unk5, object->unk7, object->unk29);
        do
        {
          v385 = rand() % -4 + 1;
          v386 = rand();
          v385 <<= 16;
          v387 = object->unk7;
          v388 = object->unk5;
          object->gen_period = ((v386 >> 31) ^ abs((_BYTE)v386)) - (v386 >> 31);
          v389 = Objects::Create(&MapObjects, object->owner_player, none_38, v388, v387, object->unk29);
          v389->unk62 = 0x10000;
          v389->gen_period = object->gen_period;
          v389->frame = 1;
          v389->unk63 = sub_401D70(2 * dword_5D1150[object->gen_period], v385);
          v389->unk64 = sub_401D70(2 * dword_5D1558[object->gen_period], v385);
          v390 = rand() % -2048;
          v389->unk63 = sub_401D90(v389->unk63, 0x10000) + v390 - 1024;
          v391 = rand() % -2048;
          --v384;
          v389->unk64 = sub_401D90(v389->unk64, 0x10000) + v391 - 1024;
          v389->unk30 = v389->unk63;
          v389->unk31 = v389->unk64;
          v389->unk99 = object;
          v389->unk83 = -1;
        }
        while ( v384 );
        sub_415860(dword_484390);
        dword_4846B4 = 32;
        sub_4342C0(&MapObjects, object);
      }
      goto LABEL_989;
    case none_DF:
      v392 = object->gen_period;
      v393 = 16 * dword_5D1150[v392];
      object->unk63 = v393;
      v394 = 16 * dword_5D1558[v392];
      object->unk30 = v393;
      object->unk64 = v394;
      object->unk31 = v394;
      v395 = object->health - 1;
      v396 = object->frame + 1;
      object->health = v395;
      v397 = object->x;
      v398 = v396 % 12;
      v399 = object->y;
      object->frame = v398;
      if ( MapTiles[v397 + 192 * v399].road
        || object->unk77 == v397 && object->unk78 == v399
        || (signed __int16)v395 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        Objects::Create(&MapObjects, object->owner_player, none_E6, object->unk5, object->unk7, object->unk29);
      }
      goto LABEL_988;
    case none_E0:
      v400 = object->unk225 + 1;
      object->unk225 = v400;
      if ( v400 > 0x78u )
        goto LABEL_987;
      goto LABEL_988;
    case none_E6:
      v401 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v401;
      if ( !(_BYTE)v401 )
        goto LABEL_987;
      goto LABEL_988;
    case none_E7:
      v402 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v402;
      if ( !(_BYTE)v402 )
      {
        v403 = object->unk82 + 1;
        object->unk82 = v403;
        if ( v403 > 4u )
          goto LABEL_987;
      }
      goto LABEL_988;
    default:
      goto LABEL_989;
  }
  while ( 1 )
  {
    if ( object->owner_player == v286->owner_player )
    {
      v287 = v286->class_id;
      if ( v287 == 78 )
      {
        v288 = v286->field_F2;
        if ( v288 && v288 != 1 )
          goto LABEL_808;
        sub_454ED0(v286, 2);
        v286->frame = 2;
        sub_437EE0(v286);
        goto LABEL_807;
      }
      if ( v287 != 94 )
      {
        if ( v287 != 110 && v287 != 111 )
          goto LABEL_808;
        v286->unk225 = 1;
LABEL_807:
        Objects::Create(&MapObjects, object->owner_player, none_E3, v286->unk5, v286->unk7, v286->unk29);
        goto LABEL_808;
      }
      sub_4342C0(&MapObjects, v286);
      Objects::Create(&MapObjects, v286->owner_player, apple_tree, v286->unk5, v286->unk7, v286->unk29);
      Objects::Create(&MapObjects, object->owner_player, none_E3, v286->unk5, v286->unk7, v286->unk29);
    }
LABEL_808:
    v286 = sub_434120(&MapObjects, v286, object->x, object->y, 5);
    if ( !v286 )
    {
LABEL_809:
      sub_4342C0(&MapObjects, object);
      goto LABEL_989;
    }
  }
}