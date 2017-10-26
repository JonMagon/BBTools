void __thiscall Objects::Handler(MapObject *this)
{
  unsigned __int8 v1; // al@1
  MapObject *object; // esi@1
  unsigned __int8 v3; // al@2
  unsigned __int8 v4; // al@4
  unsigned __int8 v5; // al@5
  unsigned __int8 v6; // al@7
  unsigned __int8 v7; // al@9
  unsigned __int8 v8; // al@11
  unsigned __int8 v9; // al@12
  unsigned __int8 v10; // al@18
  int v11; // ebx@18
  int *v12; // edi@25
  int v13; // eax@26
  int v14; // eax@27
  int v15; // eax@37
  int v16; // eax@39
  int v17; // ebp@39
  int v18; // ecx@39
  int v19; // eax@42
  int v20; // eax@47
  int v21; // ebp@47
  int v22; // edi@47
  unsigned __int8 v23; // al@50
  unsigned __int8 object_class_id_4; // al@56
  int v25; // edx@60
  int v26; // ecx@60
  int v27; // ecx@65
  int v28; // edx@65
  int v29; // edx@70
  int v30; // ecx@75
  int v31; // edi@76
  int v32; // eax@80
  int position; // ecx@85
  unsigned __int8 v34; // al@96
  unsigned __int8 v35; // al@99
  MapObject *v36; // eax@104
  __int64 v37; // rax@111
  int object_class_id_2; // ecx@111
  int v39; // eax@113
  unsigned __int8 v40; // cl@115
  unsigned __int8 v41; // al@116
  unsigned __int8 v42; // ST14_1@117
  unsigned __int8 v43; // ST10_1@117
  unsigned __int8 v44; // al@119
  unsigned __int8 object_class_id_1; // al@124
  int v46; // edx@127
  unsigned __int8 v47; // cl@129
  int v48; // eax@139
  int v49; // eax@142
  int v50; // eax@143
  unsigned __int8 v51; // al@155
  int v52; // eax@157
  int object_class_id; // ecx@159
  signed int v54; // eax@159
  unsigned int adr_mfb; // edx@162
  __int64 v56; // rax@168
  unsigned int v57; // edx@169
  int v58; // eax@170
  __int64 v59; // rax@172
  unsigned __int8 v60; // al@173
  unsigned __int8 v61; // al@175
  unsigned __int8 v62; // al@180
  unsigned __int8 v63; // cl@181
  unsigned __int8 v64; // al@186
  unsigned __int8 v65; // al@188
  int v66; // eax@193
  unsigned __int8 v67; // al@197
  unsigned __int8 v68; // al@199
  MapObject *v69; // eax@200
  unsigned int v70; // edx@202
  unsigned __int8 v71; // al@207
  int v72; // eax@208
  __int64 v73; // rax@211
  int v74; // eax@211
  unsigned int v75; // edx@216
  unsigned __int16 v76; // ax@218
  int v77; // eax@222
  unsigned __int8 v78; // al@228
  unsigned __int8 v79; // al@230
  int v80; // eax@231
  unsigned __int8 v81; // al@234
  int v82; // eax@236
  unsigned __int8 v83; // al@240
  unsigned __int8 v84; // al@243
  unsigned __int8 v85; // al@244
  signed int v86; // edi@246
  MapObject *i; // ebx@246
  int v88; // eax@248
  unsigned __int8 v89; // al@255
  unsigned __int8 v90; // al@261
  unsigned __int8 v91; // al@276
  int v92; // eax@277
  int v93; // eax@279
  unsigned __int8 v94; // al@282
  unsigned __int8 v95; // al@286
  unsigned __int8 v96; // al@293
  int v97; // ecx@295
  unsigned __int8 v98; // dl@295
  int v99; // eax@297
  int v100; // ecx@297
  unsigned __int8 v101; // cl@298
  unsigned __int8 v102; // al@299
  int v103; // eax@301
  int v104; // ecx@311
  unsigned __int8 v105; // dl@311
  int v106; // eax@313
  int v107; // ecx@313
  unsigned __int8 v108; // cl@314
  unsigned __int8 v109; // al@315
  __int64 v110; // rax@317
  __int64 v111; // rax@317
  int v112; // eax@317
  int v113; // eax@322
  char *v114; // ecx@325
  unsigned int v115; // edx@325
  unsigned __int8 v116; // al@327
  unsigned __int8 v117; // al@330
  unsigned __int8 v118; // al@332
  unsigned __int8 v119; // cl@334
  unsigned __int8 v120; // al@336
  unsigned __int8 v121; // cl@338
  unsigned __int8 v122; // cl@341
  unsigned __int8 v123; // al@343
  unsigned __int8 v124; // cl@345
  unsigned __int8 v125; // al@347
  unsigned __int8 v126; // al@350
  unsigned __int8 v127; // al@351
  int v128; // ST14_4@352
  int v129; // eax@352
  int v130; // ST10_4@352
  int v131; // eax@352
  unsigned __int8 v132; // al@353
  unsigned __int8 v133; // al@354
  unsigned __int8 v134; // al@359
  MapObject *v135; // eax@360
  int v136; // ecx@362
  int v137; // edi@362
  unsigned int v138; // edx@365
  unsigned __int8 v139; // al@370
  MapObject *v140; // eax@378
  int v141; // eax@382
  int v142; // eax@384
  unsigned __int8 v143; // al@388
  unsigned __int8 v144; // cl@388
  unsigned __int8 v145; // al@393
  unsigned __int8 v146; // al@394
  unsigned __int8 v147; // al@399
  char *v148; // ebp@400
  unsigned __int8 v149; // cl@402
  unsigned __int8 v150; // al@406
  int v151; // ebx@407
  MapObject *v152; // edi@407
  unsigned __int8 v153; // al@408
  unsigned __int8 v154; // al@409
  int v155; // ecx@409
  char v156; // bl@409
  char j; // al@409
  __int64 v158; // rax@410
  int v159; // ecx@410
  MapObject *v160; // eax@411
  unsigned __int8 v161; // cl@411
  unsigned __int8 v162; // cl@420
  unsigned __int8 v163; // cl@428
  unsigned __int8 v164; // cl@435
  unsigned __int8 v165; // cl@443
  MapObject *v166; // ecx@450
  unsigned __int8 v167; // al@452
  unsigned __int8 v168; // al@455
  __int64 v169; // rax@459
  __int64 v170; // rax@461
  __int64 v171; // rax@462
  __int64 v172; // rax@464
  __int64 v173; // rax@466
  unsigned __int8 v174; // cl@471
  unsigned __int8 v175; // cl@472
  int v176; // eax@473
  unsigned __int8 v177; // cl@476
  unsigned __int8 v178; // cl@477
  int v179; // edx@477
  unsigned int v180; // edx@479
  MapObject *v181; // eax@482
  int v182; // eax@482
  char v183; // al@482
  int v184; // eax@482
  unsigned int v185; // edx@483
  int v186; // eax@488
  int v187; // eax@488
  int v188; // eax@488
  unsigned int v189; // edx@489
  unsigned int v190; // edx@493
  unsigned __int8 v191; // al@494
  MapObject *v192; // ecx@495
  int v193; // eax@512
  int v194; // eax@514
  int v195; // eax@527
  int v196; // eax@529
  int v197; // eax@539
  int v198; // eax@541
  unsigned __int8 v199; // cl@549
  int v200; // edx@549
  __int64 v201; // rax@552
  unsigned __int8 v202; // cl@552
  int v203; // eax@552
  __int64 v204; // rax@553
  unsigned __int8 v205; // al@554
  unsigned __int8 v206; // al@555
  MapObject *v207; // ecx@556
  MapObject *v208; // eax@557
  MapObject *v209; // eax@558
  __int64 v210; // rax@564
  unsigned __int8 v211; // cl@564
  int v212; // eax@564
  __int64 v213; // rax@565
  unsigned __int8 v214; // al@567
  MapObject *v215; // ecx@568
  MapObject *v216; // eax@569
  __int64 v217; // rax@573
  unsigned __int8 v218; // cl@573
  int v219; // eax@573
  __int64 v220; // rax@574
  unsigned __int8 v221; // al@575
  unsigned __int8 v222; // al@576
  MapObject *v223; // ecx@577
  MapObject *v224; // eax@578
  MapObject *v225; // ecx@579
  unsigned int v226; // edx@583
  unsigned __int8 v227; // al@584
  unsigned __int8 v228; // al@587
  int v229; // ecx@588
  unsigned __int8 v230; // al@593
  unsigned int v231; // edx@595
  unsigned __int8 v232; // al@596
  MapObject *v233; // ecx@597
  unsigned __int8 v234; // al@602
  unsigned __int8 v235; // cl@603
  int v236; // eax@603
  signed int v237; // eax@607
  char v238[4]; // eax@616
  int v239; // eax@618
  char v240; // al@618
  char v241[4]; // eax@622
  char v242; // al@624
  char v243; // al@625
  int v244; // eax@627
  int v245; // eax@635
  char v246[4]; // eax@636
  __int64 v247; // rax@640
  int v248; // ecx@641
  MapObject *v249; // ecx@643
  int v250; // eax@643
  int v251; // ecx@643
  __int64 v252; // rax@648
  MapObject *v253; // ecx@649
  int v254; // ecx@650
  unsigned __int8 v255; // cl@656
  unsigned __int8 v256; // cl@657
  int v257; // edx@657
  int v258; // eax@665
  int v259; // eax@678
  int v260; // eax@680
  int v261; // eax@684
  int v262; // eax@686
  int v263; // eax@690
  int v264; // eax@692
  int v265; // eax@699
  int v266; // eax@701
  unsigned __int8 v267; // cl@722
  int v268; // edx@722
  unsigned __int8 v269; // al@725
  MapObject *v270; // eax@731
  unsigned __int8 v271; // al@739
  unsigned __int8 v272; // al@742
  unsigned __int8 v273; // al@745
  unsigned int v274; // edx@747
  MapObject *k; // edi@751
  unsigned __int8 v276; // cl@752
  signed int v277; // eax@753
  MapObject *v278; // ecx@759
  MapObject *v279; // edi@760
  MapObject *l; // edi@762
  MapObject *m; // edi@768
  unsigned __int8 v282; // al@774
  unsigned __int8 v283; // al@777
  MapObject *v284; // edi@787
  MapObject *v285; // eax@790
  MapObject *n; // edi@791
  MapObject *v287; // edi@796
  unsigned __int8 v288; // al@798
  unsigned __int8 v289; // al@799
  MapObject *ii; // edi@810
  signed int v291; // eax@812
  MapObject *v292; // ecx@818
  MapObject *v293; // edi@819
  MapObject *v294; // ecx@821
  MapObject *v295; // ecx@822
  MapObject *jj; // edi@824
  MapObject *kk; // edi@831
  int v298; // eax@837
  int v299; // edx@837
  int v300; // eax@837
  unsigned __int8 v301; // bl@837
  unsigned __int16 v302; // dx@837
  int v303; // eax@843
  int v304; // ecx@845
  unsigned __int8 v305; // dl@845
  int v306; // eax@847
  int v307; // ecx@847
  unsigned __int8 v308; // cl@848
  unsigned __int8 v309; // al@849
  __int64 v310; // rax@851
  __int64 v311; // rax@851
  int v312; // eax@851
  int v313; // edx@851
  unsigned __int8 v314; // al@852
  int v315; // eax@866
  int v316; // ecx@866
  int v317; // eax@866
  __int64 v318; // rax@866
  unsigned __int16 v319; // di@866
  unsigned __int8 x; // bl@866
  unsigned __int8 y; // al@866
  unsigned __int8 v322; // al@870
  int v323; // eax@873
  int v324; // ecx@873
  int v325; // eax@873
  unsigned __int16 v326; // di@873
  signed __int64 v327; // rax@873
  unsigned __int8 v328; // bl@873
  signed __int64 v329; // rt2@873
  unsigned __int8 v330; // al@873
  int v331; // eax@878
  int v332; // ecx@878
  int v333; // eax@878
  unsigned __int16 v334; // di@878
  signed __int64 v335; // rax@878
  unsigned __int8 v336; // bl@878
  signed __int64 v337; // rt2@878
  unsigned __int8 v338; // al@878
  unsigned __int8 v339; // al@884
  unsigned __int8 v340; // al@889
  unsigned __int8 v341; // al@890
  unsigned __int8 v342; // al@893
  unsigned __int8 v343; // al@895
  unsigned __int8 v344; // al@897
  unsigned __int8 v345; // al@899
  int v346; // eax@904
  int v347; // ecx@904
  int v348; // eax@904
  unsigned __int16 v349; // di@904
  signed __int64 v350; // rax@904
  unsigned __int8 v351; // bl@904
  signed __int64 v352; // rt2@904
  unsigned __int8 v353; // al@904
  int v354; // eax@908
  unsigned __int8 v355; // al@912
  unsigned __int8 v356; // al@913
  unsigned __int8 v357; // al@918
  unsigned __int8 v358; // al@919
  unsigned int v359; // edx@926
  unsigned int v360; // edx@928
  unsigned int v361; // edx@930
  unsigned __int16 v362; // ax@932
  int v363; // eax@934
  unsigned __int8 v364; // cl@934
  unsigned __int8 v365; // dl@934
  unsigned __int16 v366; // ax@934
  unsigned __int8 v367; // al@938
  int v368; // eax@941
  int v369; // ecx@941
  int v370; // eax@941
  unsigned __int16 v371; // di@941
  signed __int64 v372; // rax@941
  unsigned __int8 v373; // bl@941
  signed __int64 v374; // rt2@941
  unsigned __int8 v375; // al@941
  unsigned __int8 v376; // al@949
  unsigned __int8 v377; // al@950
  unsigned __int8 v378; // al@952
  unsigned __int8 v379; // al@953
  unsigned __int8 v380; // al@956
  unsigned __int8 v381; // cl@956
  unsigned __int8 v382; // al@958
  unsigned __int8 v383; // cl@965
  unsigned __int8 v384; // al@968
  unsigned __int8 v385; // al@969
  signed int v386; // ebp@973
  int v387; // edi@974
  int v388; // eax@974
  int v389; // ecx@974
  int v390; // edx@974
  MapObject *v391; // ebx@974
  int v392; // edi@974
  int v393; // edi@974
  int v394; // eax@976
  int v395; // ecx@976
  int v396; // eax@976
  unsigned __int16 v397; // di@976
  signed __int64 v398; // rax@976
  unsigned __int8 v399; // bl@976
  signed __int64 v400; // rt2@976
  unsigned __int8 v401; // al@976
  unsigned __int8 v402; // al@981
  unsigned int v403; // edx@983
  unsigned int v404; // edx@985
  unsigned __int8 v405; // al@986
  unsigned __int8 v406; // al@989
  bool v407; // zf@991
  unsigned __int8 object_class_id_3; // al@992
  unsigned __int8 v409; // dl@995

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
    if ( !(v19 & 0x40000) && (object->unk30 || object->unk31 || BYTE1(v19) & 0x40 || object->unk62) )
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
      if ( object_class_id_4 == Villager )
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
  if ( !*(_DWORD *)((char *)&unk_66358A + 914 * object->class_id) && MapTiles[object->x + 192 * object->y].mask1 & 4 )
    v11 = 0x10000;
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
    if ( unk_6A9092[2 * Tiles[position].texture] & 0x200 && !(MapTiles[position].mask1 & 4) )
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
  object->data8[2] = (BYTE4(v37) ^ ((BYTE4(v37) ^ v37) - BYTE4(v37))) - BYTE4(v37);
  if ( *(_DWORD *)((char *)&unk_6635A2 + 914 * object_class_id_2) )
  {
    if ( !object->is_fleeing )
    {
      v39 = object->unk32;
      if ( BYTE1(v39) & 0x40 )
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
  if ( (object_class_id_1 == Villager || object_class_id_1 == 104) && !object->field_F2 )
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
          if ( BYTE1(v49) & 0x20 )
            goto LABEL_154;
          sub_441710(object);
          v50 = object->unk32 | 0x2000;
LABEL_153:
          object->unk32 = v50;
          goto LABEL_154;
        }
        v48 = (int)object->unk113->field_28;
        if ( v48 )
        {
          sub_43F440(object, v48, 1, 1);
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
    case 2:
      if ( current_season == 3 )
        goto LABEL_988;
      goto LABEL_989;
    case 7:
      adr_mfb = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = adr_mfb;
      if ( !(_BYTE)adr_mfb )
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, 5);
      sub_437EE0(object);
      if ( !(object->unk32 & 0x800000) )
        --object->health;
      if ( object->health <= 0 )
      {
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCCu,
          object->unk5,
          object->unk7,
          object->unk29);
        sub_4342C0(&MapObjects, object);
      }
      goto LABEL_989;
    case 0x18:
      v56 = object->state_id + 1;
      object->state_id = (BYTE4(v56) ^ ((BYTE4(v56) ^ v56) - BYTE4(v56)) & 0xF) - BYTE4(v56);
      goto LABEL_989;
    case 0x19:
      v57 = ((unsigned int)object->frame + 1) % (4 * gasmold_mfb->numimages);
      object->frame = v57;
      if ( !(_BYTE)v57 )
      {
        v58 = object->y;
        object->frame = 16;
        sub_434E60(&MapObjects, object, 0, object->x, v58, 0, 5);
      }
      goto LABEL_988;
    case 0x1A:
      if ( object->unk32 & 0x10000 )
      {
        v59 = object->state_id + 1;
        LODWORD(v59) = (HIDWORD(v59) ^ ((BYTE4(v59) ^ (unsigned __int8)v59) - BYTE4(v59)) & 3) - HIDWORD(v59);
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
    case 0x1C:
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
    case 0x21:
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
            v69 = Objects::Create(&MapObjects, 4u, Villager, object->unk5, object->unk7 + 0x10000, object->unk29);
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
    case 0x22:
      v70 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v70;
      if ( (_BYTE)v70 == 10 )
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, 120);
      if ( !object->frame )
        goto LABEL_987;
      goto LABEL_988;
    case 0x24:
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
    case 0x25:
      v73 = object->frame + 1;
      v74 = (HIDWORD(v73) ^ ((BYTE4(v73) ^ (unsigned __int8)v73) - BYTE4(v73)) & 0x3F) - HIDWORD(v73);
      object->frame = v74;
      if ( (_BYTE)v74 == 60 || !(_BYTE)v74 )
        sub_437EE0(object);
      if ( object->field_F2 == 24 )
        sub_4508A0(object, 1, 0);
      goto LABEL_989;
    case 0x26:
      v75 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v75;
      if ( !(_BYTE)v75 )
        object->frame = 16;
      v76 = object->health - 1;
      object->health = v76;
      if ( (signed __int16)v76 <= 0 )
        goto LABEL_987;
      goto LABEL_988;
    case 0x29:
      object->unk63 = 0;
      object->unk64 = 0;
      if ( object->unk62 > 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, 200);
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCBu,
          object->unk5,
          object->unk7,
          object->unk29);
        Objects::Create(&MapObjects, object->owner_player, Fire, object->unk5, object->unk7, object->unk29);
        sub_453AB0(dword_4843A4);
        sub_453AB0(dword_484330);
      }
      goto LABEL_988;
    case 0x2A:
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
          Objects::Create(&MapObjects, object->owner_player, Fire, object->unk5, object->unk7, object->unk29);
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
    case 0x2B:
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
            if ( i->class_id == Fire )
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
    case 0x2C:
      if ( !(rand() % 3) )
        dword_4846B4 = (unsigned __int8)((char)rand() % -16);
      goto LABEL_989;
    case 0x32:
      object->frame = ((unsigned int)object->frame + 1) % (2 * object->mfb_file->numimages);
      goto LABEL_988;
    case 0x33:
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
            object->frame = (((unsigned __int64)v92 >> 32) ^ abs(v92) & 3) - ((unsigned __int64)v92 >> 32);
            sub_437EE0(object);
          }
          if ( object->unk225 == 36 )
          {
            v93 = rand();
            object->frame = (((unsigned __int64)v93 >> 32) ^ abs(v93) & 3) - ((unsigned __int64)v93 >> 32);
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
    case 0x36:
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
    case 0x37:
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
    case 0x38:
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
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCBu,
          object->unk5,
          object->unk7,
          object->unk29);
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
        v110 = object->gen_period + 16;
        v111 = ((BYTE4(v110) & 0x1F) + (signed int)v110) >> 5;
        object->state_id = (BYTE4(v111) ^ ((BYTE4(v111) ^ v111) - BYTE4(v111)) & 7) - BYTE4(v111);
        v112 = object->unk62;
        if ( v112 >= -16000 )
        {
          if ( v112 < -4096 )
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
    case 0x39:
      v113 = object->field_F2;
      if ( v113 == 55 )
      {
        v114 = (char *)&object->mfb_file->numimages;
        v115 = ((unsigned int)object->frame + 1) % (4 * *(_DWORD *)v114);
        object->frame = v115;
        if ( !(_BYTE)v115 )
        {
          object->frame = 4 * *(_DWORD *)v114 - 1;
          sub_454EC0(object);
          object->unk225 = 64;
        }
        goto LABEL_988;
      }
      if ( v113 != 56 )
        goto LABEL_989;
      v116 = object->frame - 1;
      object->frame = v116;
      if ( !v116 )
        goto LABEL_987;
      goto LABEL_988;
    case 0x3A:
      switch ( object->field_F2 )
      {
        case 0x1Bu:
          v117 = object->frame;
          if ( v117 < 0x13u )
          {
            object->frame = v117 + 1;
            goto LABEL_988;
          }
          break;
        case 0x1Cu:
          v118 = object->frame;
          if ( v118 < 0x27u )
          {
            object->frame = v118 + 1;
            goto LABEL_988;
          }
          break;
        case 0x1Fu:
          v119 = object->frame;
          if ( 4 * cowplode_mfb->numimages - 1 > (unsigned int)v119 )
          {
            object->unk225 = -1;
            object->frame = v119 + 1;
            goto LABEL_988;
          }
          v120 = object->unk225 - 1;
          object->unk225 = v120;
          if ( !v120 )
            sub_4342C0(&MapObjects, object);
          break;
        case 0x72u:
          v121 = object->frame;
          if ( 4 * vampdead_mfb->numimages - 1 <= (unsigned int)v121 )
            sub_4342C0(&MapObjects, object);
          else
            object->frame = v121 + 1;
          break;
        case 0x76u:
          v122 = object->frame;
          if ( 4 * cowkill_mfb->numimages - 1 > (unsigned int)v122 )
          {
            object->unk225 = -1;
            object->frame = v122 + 1;
            goto LABEL_988;
          }
          v123 = object->unk225 - 1;
          object->unk225 = v123;
          if ( !v123 )
            sub_4342C0(&MapObjects, object);
          break;
        case 0x77u:
          v124 = object->frame;
          if ( 4 * cowdie_mfb->numimages - 1 > (unsigned int)v124 )
          {
            object->unk225 = -1;
            object->frame = v124 + 1;
            goto LABEL_988;
          }
          v125 = object->unk225 - 1;
          object->unk225 = v125;
          if ( !v125 )
            sub_4342C0(&MapObjects, object);
          break;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case 0x3D:
      if ( object->unk32 & 0x80000 )
      {
        v126 = object->unk225;
        if ( v126 )
        {
          v127 = v126 - 1;
          object->unk225 = v127;
          if ( !v127 )
          {
            sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, 1);
            v128 = object->unk29;
            v129 = rand();
            v130 = (((unsigned __int64)v129 >> 32) ^ abs(v129)) - ((unsigned __int64)v129 >> 32) + object->unk7 - 0x8000;
            v131 = rand();
            Objects::Create(
              &MapObjects,
              object->owner_player,
              Fire,
              (((unsigned __int64)v131 >> 32) ^ abs(v131)) - ((unsigned __int64)v131 >> 32) + object->unk5 - 0x7FFF,
              v130,
              v128);
          }
        }
      }
      goto LABEL_989;
    case 0x43:
      v132 = object->unk225;
      if ( v132 )
      {
        v133 = v132 - 1;
        object->unk225 = v133;
        if ( !v133 )
        {
          object->field_10 = Objects::Create(
                               &MapObjects,
                               object->owner_player,
                               (ObjectClass)0x38u,
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
      v134 = object->frame + 1;
      object->frame = v134;
      if ( v134 == 1 )
      {
        v135 = object->field_10;
        if ( v135 )
        {
          if ( object->unk113 )
          {
            v136 = ((object->unk78 - object->y) << 6) - object->x + object->unk77;
            object->gen_period = unk_5FDA98[v136];
            v137 = unk_5FB2F0[v136];
            v135->unk62 = 0x20000;
            object->field_10->unk63 = sub_401D70(unk_5D1150[object->gen_period], v137);
            object->field_10->unk64 = sub_401D70(unk_5D1558[object->gen_period], v137);
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
    case 0x44:
      v138 = ((unsigned int)object->frame + 1) % (2 * object->mfb_file->numimages);
      object->frame = v138;
      if ( (_BYTE)v138 == 1 )
        sub_434E60(&MapObjects, object, 0, object->x, object->y, 0, 10);
      if ( !object->frame )
        goto LABEL_987;
      goto LABEL_988;
    case 0x45:
      if ( object->field_F2 == 88 )
      {
        v139 = object->unk225 + 1;
        object->unk225 = v139;
        switch ( v139 )
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
    case 0x46:
      if ( object->field_F2 != 21 )
        goto LABEL_989;
      v140 = object->field_10;
      if ( v140 )
      {
        v140->unk64 = 16536;
        object->field_10->unk31 = 16536;
        sub_454ED0(object->field_10, 23);
      }
      sub_454ED0(object, 22);
      goto LABEL_988;
    case 0x47:
      if ( object->field_F2 == 23 )
      {
        sub_437EE0(object);
        v141 = object->unk29 - 2048;
        object->unk29 = v141;
        if ( v11 >= v141 )
        {
          sub_4342C0(&MapObjects, object);
          sub_453AB0(dword_48434C);
        }
      }
      goto LABEL_989;
    case 0x4E:
      v142 = object->field_F2;
      if ( v142 == 3 )
      {
        v143 = object->state_id + 1;
        object->state_id = v143;
        v144 = 5 - v143 / 0x24u;
        object->frame = v144;
        if ( v144 < 3u )
LABEL_987:
          sub_4342C0(&MapObjects, object);
      }
      else
      {
        if ( v142 != 4 )
        {
          if ( v142 == 5 )
            object->frame = 0;
          goto LABEL_989;
        }
        if ( object->unk120 )
          goto LABEL_989;
        sub_454ED0(object, 0);
      }
      goto LABEL_988;
    case 0x51:
      v145 = object->unk225;
      if ( v145 )
      {
        v146 = v145 - 1;
        object->unk225 = v146;
        if ( !v146 )
        {
          object->frame = 0;
          sub_437EE0(object);
        }
      }
      else if ( object->unk77 || object->unk78 )
      {
        v54 = sub_454ED0(object, 59);
      }
      v147 = object->unk77;
      if ( v147 || (v148 = (char *)&object->unk78, object->unk78) )
      {
        v148 = (char *)&object->unk78;
        object->gen_type = *(&unk_5FDA98[((object->unk78 - object->y) << 6) - object->x] + v147);
      }
      v149 = object->gen_period;
      LOBYTE(v54) = object->gen_type;
      if ( v149 != (_BYTE)v54 )
      {
        object->gen_period = sub_4031A0(v149, v54);
        sub_437EE0(object);
      }
      if ( object->field_F2 != 59 || object->gen_period != object->gen_type )
        goto LABEL_989;
      v150 = object->frame + 1;
      object->frame = v150;
      if ( v150 == 1 )
      {
        v151 = 4 * unk_5FB2F0[object->unk77 + (((unsigned __int8)*v148 - object->y) << 6) - object->x];
        v152 = Objects::Create(
                 &MapObjects,
                 object->owner_player,
                 Fire|0x30,
                 object->unk5 - 0x8000,
                 object->unk7 + 0x8000,
                 object->unk29 + 0x40000);
        v152->unk63 = sub_401D70(unk_5D1150[object->gen_period], v151);
        v152->unk64 = sub_401D70(unk_5D1558[object->gen_period], v151);
        v152->unk30 = v152->unk63;
        v152->unk31 = v152->unk64;
        sub_453AB0(dword_48438C);
        object->unk225 = 36;
        sub_454EC0(object);
        object->unk77 = 0;
        *v148 = 0;
      }
      goto LABEL_988;
    case 0x54:
      v153 = object->unk225;
      if ( v153 )
      {
        object->unk225 = v153 - 1;
        goto LABEL_989;
      }
      v154 = object->gen_period;
      object->unk82 = v154;
      v155 = (v154 >> 1) & 0xFC;
      v156 = object->x + *(int *)((char *)&dword_484580 + v155);
      for ( j = object->y + *(int *)((char *)&dword_484600 + v155);
            MapTiles[(unsigned __int8)v156 + 192 * (unsigned __int8)j].road;
            j = object->y + *(int *)((char *)&dword_484600 + v159) )
      {
        v158 = object->gen_period + 64;
        LOBYTE(v158) = (BYTE4(v158) ^ ((BYTE4(v158) ^ v158) - BYTE4(v158))) - BYTE4(v158);
        object->gen_period = v158;
        v159 = ((unsigned __int8)v158 >> 1) & 0xFC;
        v156 = object->x + *(int *)((char *)&dword_484580 + v159);
      }
      sub_43F970(v156, j);
      v160 = Objects::Create(
               &MapObjects,
               object->owner_player,
               (ObjectClass)0x55u,
               object->unk5,
               object->unk7,
               object->unk29);
      v161 = object->gen_period;
      if ( v161 )
      {
        switch ( v161 )
        {
          case 0x40u:
            v160->frame = 3;
            break;
          case 0x80:
            v160->frame = 0;
            break;
          case 0xC0:
            v160->frame = 1;
            break;
        }
      }
      else
      {
        v160->frame = 2;
      }
      switch ( object->unk82 )
      {
        case 0u:
          v162 = object->gen_period;
          if ( v162 )
          {
            switch ( v162 )
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
          v163 = object->gen_period;
          if ( v163 )
          {
            if ( v163 == 64 )
              goto LABEL_449;
            if ( v163 == -128 )
            {
              object->frame = 8;
            }
            else if ( v163 == -64 )
            {
              goto LABEL_449;
            }
          }
          else
          {
            object->frame = 9;
          }
          goto LABEL_450;
        case 0x80u:
          v164 = object->gen_period;
          if ( v164 )
          {
            switch ( v164 )
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
          v165 = object->gen_period;
          if ( !v165 )
          {
            object->frame = 6;
            goto LABEL_450;
          }
          if ( v165 == 64 )
            goto LABEL_449;
          if ( v165 == -128 )
          {
            object->frame = 7;
          }
          else if ( v165 == -64 )
          {
LABEL_449:
            object->frame = 5;
          }
LABEL_450:
          v166 = object->field_10;
          if ( v166 )
            v166->frame = object->frame;
          object->unk225 = 4;
          object->field_10 = v160;
          v167 = object->unk83 - 1;
          object->unk83 = v167;
          if ( !v167 )
            sub_4342C0(&MapObjects, object);
LABEL_989:
          v406 = object->unk8 - 1;
          object->unk8 = v406;
          if ( !v406 )
          {
            sub_442F40(object);
            object->unk8 = -1;
          }
          v407 = object->unk26-- == 1;
          if ( v407 )
          {
            object_class_id_3 = object->class_id;
            if ( object_class_id_3 == Villager || object_class_id_3 == 104 || object_class_id_3 == 110 )
              v409 = rand() % 20 + 40;
            else
              v409 = rand() % 40 + 80;
            object->unk26 = v409;
            sub_444150(object);
          }
          return;
        default:
          goto LABEL_450;
      }
    case 0x55:
      v168 = object->unk225;
      if ( v168 )
        object->unk225 = v168 - 1;
      else
        sub_4342C0(&MapObjects, object);
      goto LABEL_989;
    case 0x5C:
      switch ( object->field_F2 )
      {
        case 0x2Du:
          v169 = object->frame + 1;
          LODWORD(v169) = (HIDWORD(v169) ^ ((BYTE4(v169) ^ (unsigned __int8)v169) - BYTE4(v169)) & 7) - HIDWORD(v169);
          object->frame = v169;
          if ( !(_BYTE)v169 )
            sub_454ED0(object, 46);
          goto LABEL_468;
        case 0x2Eu:
          v170 = object->frame + 1;
          object->frame = (BYTE4(v170) ^ ((BYTE4(v170) ^ v170) - BYTE4(v170)) & 7) - BYTE4(v170);
          goto LABEL_468;
        case 0x2Fu:
          v171 = object->frame + 1;
          LODWORD(v171) = (HIDWORD(v171) ^ ((BYTE4(v171) ^ (unsigned __int8)v171) - BYTE4(v171)) & 7) - HIDWORD(v171);
          object->frame = v171;
          if ( !(_BYTE)v171 )
            goto LABEL_467;
          goto LABEL_468;
        case 0x30u:
          v172 = object->frame + 1;
          LODWORD(v172) = (HIDWORD(v172) ^ ((BYTE4(v172) ^ (unsigned __int8)v172) - BYTE4(v172)) & 0xF) - HIDWORD(v172);
          object->frame = v172;
          if ( !(_BYTE)v172 )
            sub_454ED0(object, 49);
          goto LABEL_468;
        case 0x31u:
          v173 = object->frame + 1;
          LODWORD(v173) = (HIDWORD(v173) ^ ((BYTE4(v173) ^ (unsigned __int8)v173) - BYTE4(v173)) & 0x7F) - HIDWORD(v173);
          object->frame = v173;
          if ( !(_BYTE)v173 )
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
    case 0x5D:
      if ( object->field_F2 != 20 )
        goto LABEL_989;
      v174 = object->frame;
      if ( 2 * flamepit_mfb->numimages <= (unsigned int)v174 )
      {
        sub_454EC0(object);
        object->frame = 0;
      }
      else
      {
        v175 = v174 + 1;
        object->frame = v175;
        if ( v175 == 10 )
        {
          v176 = rand();
          sub_434E60(&MapObjects, object, 0, object->x, object->y, 1, v176 % 40 + 60);
        }
      }
      goto LABEL_988;
    case 0x67:
      switch ( object->field_F2 )
      {
        case 0u:
          v177 = object->unk225;
          if ( v177 )
          {
            v178 = v177 + 1;
            v179 = object->unk19;
            object->unk225 = v178;
            if ( (unsigned __int8)unk_6AFF88[35 * v179] <= v178 )
              object->unk225 = 0;
          }
          goto LABEL_989;
        case 3u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v180 = ((unsigned int)object->frame + 1) % (4 * cowchopm_mfb->numimages);
          object->frame = v180;
          if ( (_BYTE)v180 == 16 )
            sub_453AB0(dword_48436C);
          if ( !object->frame )
          {
            sub_454EC0(object);
            v181 = Objects::Create(&MapObjects, object->owner_player, Corpse, object->unk5, object->unk7, object->unk29);
            sub_454ED0(v181, 30);
            sub_453A80(unk_5C78E4);
            v182 = rand();
            sub_454280((((unsigned __int64)v182 >> 32) ^ abs(v182) & 0xF) - ((unsigned __int64)v182 >> 32) + 32);
            v183 = rand();
            sub_4542D0((unsigned __int8)(v183 % -16));
            v184 = rand();
            sub_4540A0((((unsigned __int64)v184 >> 32) ^ abs(v184) & 0xF) - ((unsigned __int64)v184 >> 32) + 4, 0);
          }
          goto LABEL_988;
        case 4u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v185 = ((unsigned int)object->frame + 1) % (4 * m_chkill_mfb->numimages);
          object->frame = v185;
          if ( (_BYTE)v185 == 8 )
            sub_453A80(unk_69E368);
          if ( object->frame == 16 )
            sub_453AB0(dword_48436C);
          if ( !object->frame )
          {
            sub_454EC0(object);
            object->unk32 &= 0xFFFFBFFF;
            sub_453A80(unk_5C78E4);
            v186 = rand();
            sub_454280((((unsigned __int64)v186 >> 32) ^ abs(v186) & 0xF) - ((unsigned __int64)v186 >> 32) + 16);
            v187 = rand();
            sub_4542D0(v187 % 12);
            v188 = rand();
            sub_4540A0(v188 % 12 + 4, 0);
          }
          goto LABEL_988;
        case 5u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v189 = ((unsigned int)object->frame + 1) % (4 * m_shaker_mfb->numimages);
          object->frame = v189;
          if ( !((unsigned __int8)v189 % 0x14u) )
            sub_453AB0(dword_484374);
          if ( !object->frame )
          {
            sub_454EC0(object);
            Objects::Create(
              &MapObjects,
              object->owner_player,
              (ObjectClass)0x83u,
              object->unk5,
              object->unk7,
              object->unk29);
          }
          goto LABEL_988;
        case 6u:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v190 = ((unsigned int)object->frame + 1) % (4 * mharvest_mfb->numimages);
          object->frame = v190;
          if ( !(_BYTE)v190 )
          {
            v191 = object->unk82 - 1;
            object->unk82 = v191;
            if ( !v191 )
            {
              sub_454EC0(object);
              v192 = object->unk120;
              if ( v192 )
                sub_454ED0(v192, 5);
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
                    v193 = object->gen_period;
                    object->frame = 1;
                    object->unk30 = 16 * unk_5D1150[v193];
                    object->unk31 = 16 * unk_5D1558[v193];
                    break;
                  case 4u:
                    object->frame = 2;
                    sub_44F900(object);
                    break;
                  case 6u:
                    v194 = object->gen_period;
                    object->unk30 = -16 * unk_5D1150[v194];
                    object->unk31 = -16 * unk_5D1558[v194];
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
                  case 0x10u:
                    object->frame = 4;
                    sub_44F900(object);
                    break;
                  case 0x14u:
                    object->frame = 5;
                    break;
                  case 0xCu:
                    goto LABEL_548;
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
                    v195 = object->gen_period;
                    object->frame = 3;
                    object->unk30 = 8 * unk_5D1150[v195];
                    object->unk31 = 8 * unk_5D1558[v195];
                    break;
                  case 8u:
                    object->frame = 4;
                    sub_44F900(object);
                    break;
                  case 0xAu:
                    v196 = object->gen_period;
                    object->frame = 5;
                    object->unk30 = -8 * unk_5D1150[v196];
                    object->unk31 = -8 * unk_5D1558[v196];
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
                    v197 = object->gen_period;
                    object->frame = 1;
                    object->unk30 = 8 * unk_5D1150[v197];
                    object->unk31 = 8 * unk_5D1558[v197];
                    break;
                  case 4u:
                    object->frame = 2;
                    sub_44F900(object);
                    break;
                  case 6u:
                    v198 = object->gen_period;
                    object->frame = 3;
                    object->unk30 = -8 * unk_5D1150[v198];
                    object->unk31 = -8 * unk_5D1558[v198];
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
            v199 = object->unk225 + 1;
            v200 = object->unk19;
            object->unk225 = v199;
            if ( (unsigned __int8)unk_6AFF88[35 * v200] <= v199 )
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
          v201 = object->frame + 1;
          v202 = object->sex;
          v203 = (HIDWORD(v201) ^ ((BYTE4(v201) ^ (unsigned __int8)v201) - BYTE4(v201)) & 0xF) - HIDWORD(v201);
          object->frame = v203;
          if ( v202 == 4 )
          {
            v204 = (unsigned __int8)v203 + 1;
            object->frame = (BYTE4(v204) ^ ((BYTE4(v204) ^ v204) - BYTE4(v204)) & 0xF) - BYTE4(v204);
          }
          v205 = object->frame;
          if ( v205 )
          {
            if ( v205 == 4 )
              sub_453AB0(dword_484360);
          }
          else
          {
            v206 = object->unk82 - 1;
            object->unk82 = v206;
            if ( !v206 )
            {
              sub_454EC0(object);
              v207 = object->unk99;
              if ( v207 )
              {
                sub_454ED0(v207, 61);
                v208 = object->unk99->unk116;
                if ( v208 )
                {
                  --v208->state_id;
                  v209 = object->unk99->unk116;
                  if ( !v209->state_id && v209->class_id != 122 )
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
          v210 = object->frame + 1;
          v211 = object->sex;
          v212 = (HIDWORD(v210) ^ ((BYTE4(v210) ^ (unsigned __int8)v210) - BYTE4(v210)) & 0xF) - HIDWORD(v210);
          object->frame = v212;
          if ( v211 == 4 )
          {
            v213 = (unsigned __int8)v212 + 1;
            object->frame = (BYTE4(v213) ^ ((BYTE4(v213) ^ v213) - BYTE4(v213)) & 0xF) - BYTE4(v213);
          }
          if ( !object->frame )
          {
            v214 = object->unk82 - 1;
            object->unk82 = v214;
            if ( v214 )
            {
              sub_453AB0(dword_484380);
            }
            else
            {
              sub_454EC0(object);
              v215 = object->unk99;
              if ( v215 )
              {
                sub_454ED0(v215, 63);
                v216 = object->unk99->unk116;
                if ( v216 )
                  --v216->state_id;
                object->unk99 = 0;
              }
            }
          }
          goto LABEL_988;
        case 0xBu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v217 = object->frame + 1;
          v218 = object->sex;
          v219 = (HIDWORD(v217) ^ ((BYTE4(v217) ^ (unsigned __int8)v217) - BYTE4(v217)) & 0xF) - HIDWORD(v217);
          object->frame = v219;
          if ( v218 == 4 )
          {
            v220 = (unsigned __int8)v219 + 1;
            object->frame = (BYTE4(v220) ^ ((BYTE4(v220) ^ v220) - BYTE4(v220)) & 0xF) - BYTE4(v220);
          }
          v221 = object->frame;
          if ( v221 )
          {
            if ( v221 == 8 )
              sub_453AB0(dword_48437C);
          }
          else
          {
            v222 = object->unk82 - 1;
            object->unk82 = v222;
            if ( !v222 )
            {
              sub_454EC0(object);
              v223 = object->unk99;
              if ( v223 )
              {
                sub_454ED0(v223, 66);
                v224 = object->unk99->unk116;
                if ( v224 )
                {
                  --v224->state_id;
                  v225 = object->unk99->unk116;
                  sub_43FB50(
                    object,
                    v225->x + *(_DWORD *)((char *)&unk_6638AE + 914 * v225->class_id),
                    v225->y + *(_DWORD *)((char *)&unk_6638B2 + 914 * v225->class_id));
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
          v226 = ((unsigned int)object->frame + 1) % (4 * m_chop_mfb->numimages);
          object->frame = v226;
          if ( !(_BYTE)v226 )
          {
            v227 = object->unk82 - 1;
            object->unk82 = v227;
            if ( v227 )
              sub_453AB0(dword_484360);
            else
              sub_454EC0(object);
          }
          goto LABEL_988;
        case 0xDu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v228 = object->frame + 1;
          object->frame = v228;
          if ( v228 == 32 )
          {
            v229 = (int)object->unk99;
            if ( v229 && *(_WORD *)(v229 + 160) < *(_WORD *)(v229 + 162) )
            {
              sub_450820(v229, 4);
              object->frame = 16;
            }
          }
          else if ( v228 == 44 )
          {
            sub_454EC0(object);
            object->frame = 0;
          }
          goto LABEL_988;
        case 0xEu:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v230 = object->frame + 1;
          object->frame = v230;
          if ( v230 == 32 )
          {
            sub_454EC0(object);
            object->frame = 0;
          }
          goto LABEL_988;
        case 0x5Du:
          object->unk30 = 0;
          object->unk31 = 0;
          object->unk32 |= 0x40000u;
          v231 = ((unsigned int)object->frame + 1) % (4 * milking_mfb->numimages);
          object->frame = v231;
          if ( (_BYTE)v231 )
          {
            if ( (_BYTE)v231 == 1 )
              sub_453AB0(dword_4843D0);
          }
          else
          {
            v232 = object->unk82 + 1;
            object->unk82 = v232;
            if ( v232 == 12 )
            {
              object->unk82 = 0;
              v233 = object->unk120;
              if ( v233 )
                sub_454EC0(v233);
              sub_454EC0(object);
            }
          }
          goto LABEL_988;
        case 0x73u:
          v234 = object->unk83 + 1;
          object->unk83 = v234;
          if ( v234 >= 0x24u )
          {
            v235 = object->data10[0] + 1;
            v236 = object->data9[0];
            object->data10[0] = v235;
            object->unk83 = 0;
            switch ( v236 )
            {
              case 0:
                if ( v235 == 1 )
                {
                  v237 = (unsigned __int8)((char)rand() % -2);
                  if ( v237 >= 0 && v237 <= 1 )
                    sub_453A80(unk_6034DC);
                }
                else if ( v235 == 4 )
                {
                  sub_453450((int)object, 250);
                  sub_454EC0(object);
                }
                break;
              case 1:
                switch ( v235 )
                {
                  case 1u:
                    sub_453A80(unk_6A8F10);
                    break;
                  case 4u:
                    *(_DWORD *)v238 = unk_60362C;
                    if ( !unk_60362C )
                      *(_DWORD *)v238 = byte_48481C;
                    sub_41E1F0(object, *(_DWORD *)v238);
                    v239 = rand();
                    sub_454140(
                      (((unsigned __int64)v239 >> 32) ^ abs(v239) & 0xF) - ((unsigned __int64)v239 >> 32) + 16,
                      0);
                    v240 = rand();
                    sub_4540A0((unsigned __int8)(v240 % -32), 0);
                    if ( object->spouse )
                      sub_4540A0(-32, 0);
                    break;
                  case 0x14u:
                    sub_454EC0(object);
                    break;
                }
                break;
              case 2:
                switch ( v235 )
                {
                  case 4u:
                    *(_DWORD *)v241 = unk_6038A0;
                    if ( !unk_6038A0 )
                      *(_DWORD *)v241 = byte_48481C;
                    sub_41E1F0(object, *(_DWORD *)v241);
                    v242 = rand();
                    sub_453A80(unk_662C88[(unsigned __int8)(v242 % -2)]);
                    break;
                  case 5u:
                    v243 = rand();
                    sub_453A80(unk_662C88[(unsigned __int8)(v243 % -2)]);
                    break;
                  case 6u:
                    sub_4508A0(object, object->health / 2, 0);
                    break;
                  case 7u:
                    sub_453A00(unk_63F048, 0, 0);
                    v244 = rand();
                    sub_454140(
                      (((unsigned __int64)v244 >> 32) ^ abs(v244) & 0x1F) - ((unsigned __int64)v244 >> 32) + 48,
                      0);
                    if ( object->spouse )
                      sub_4540A0(-64, 0);
                    sub_454EC0(object);
                    break;
                  default:
                    goto LABEL_989;
                }
                goto LABEL_989;
              case 3:
                switch ( v235 )
                {
                  case 1u:
                    sub_453A80(unk_600030);
                    break;
                  case 4u:
                    v245 = rand();
                    sub_453A80(unk_5E46F0[v245 % 6]);
                    break;
                  case 7u:
                    *(_DWORD *)v246 = unk_6038A4;
                    if ( !unk_6038A4 )
                      *(_DWORD *)v246 = byte_48481C;
                    sub_41E1F0(object, *(_DWORD *)v246);
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
          v247 = object->frame + 1;
          LODWORD(v247) = (HIDWORD(v247) ^ ((BYTE4(v247) ^ (unsigned __int8)v247) - BYTE4(v247)) & 0xF) - HIDWORD(v247);
          object->frame = v247;
          if ( !(_BYTE)v247 )
          {
            v248 = (int)object->unk99;
            if ( v248 )
            {
              sub_453EE0(v248, 20, 0);
              sub_437EE0(object->unk99);
              if ( object->unk99->health == object->unk99->health_max )
              {
                sub_454EC0(object);
                sub_453AB0(dword_48437C);
                sub_453A00(dword_554FA8, 0, 0);
                v249 = object->unk99;
                v250 = v249->unk32;
                v251 = (int)&v249->unk32;
                if ( v250 & 0x80000 )
                  *(_DWORD *)v251 = v250 & 0xFFF7FFFF;
                sub_43FB50(
                  object,
                  object->unk99->x + *(_DWORD *)((char *)&unk_6638AE + 914 * object->unk99->class_id),
                  object->unk99->y + *(_DWORD *)((char *)&unk_6638B2 + 914 * object->unk99->class_id));
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
          v252 = object->frame + 1;
          LODWORD(v252) = (HIDWORD(v252) ^ ((BYTE4(v252) ^ (unsigned __int8)v252) - BYTE4(v252)) & 0xF) - HIDWORD(v252);
          object->frame = v252;
          if ( !(_BYTE)v252 )
          {
            v253 = object->unk99;
            if ( !v253 || (sub_4508A0(v253, 30, 0), v254 = object->unk99->unk32, BYTE1(v254) & 0x10) )
              sub_454EC0(object);
            else
              sub_453AB0(dword_484360);
          }
          goto LABEL_988;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case 0x68:
      if ( !object->field_F2 )
      {
        v255 = object->unk225;
        if ( v255 )
        {
          v256 = v255 + 1;
          v257 = object->unk19;
          object->unk225 = v256;
          if ( (unsigned __int8)unk_6AFF88[35 * v257] <= v256 )
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
            v258 = object->unk225;
            if ( object->unk225 )
            {
              if ( v258 == 4 )
              {
                object->frame = 1;
                sub_44F900(object);
              }
              else if ( v258 == 8 )
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
                v259 = object->gen_period;
                object->frame = 0;
                object->unk30 = 8 * unk_5D1150[v259];
                object->unk31 = 8 * unk_5D1558[v259];
                break;
              case 2u:
                object->frame = 1;
                sub_44F900(object);
                break;
              case 4u:
                v260 = object->gen_period;
                object->unk30 = -8 * unk_5D1150[v260];
                object->unk31 = -8 * unk_5D1558[v260];
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
                v261 = object->gen_period;
                object->frame = 1;
                object->unk30 = 16 * unk_5D1150[v261];
                object->unk31 = 16 * unk_5D1558[v261];
                break;
              case 4u:
                object->frame = 2;
                sub_44F900(object);
                break;
              case 6u:
                v262 = object->gen_period;
                object->frame = 3;
                object->unk30 = -16 * unk_5D1150[v262];
                object->unk31 = -16 * unk_5D1558[v262];
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
                v263 = object->gen_period;
                object->frame = 0;
                object->unk30 = 16 * unk_5D1150[v263];
                object->unk31 = 16 * unk_5D1558[v263];
                break;
              case 2u:
                object->frame = 1;
                sub_44F900(object);
                break;
              case 4u:
                v264 = object->gen_period;
                object->frame = 0;
                object->unk30 = -16 * unk_5D1150[v264];
                object->unk31 = -16 * unk_5D1558[v264];
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
                v265 = object->gen_period;
                object->frame = 2;
                object->unk30 = 16 * unk_5D1150[v265];
                object->unk31 = 16 * unk_5D1558[v265];
                break;
              case 6u:
                object->frame = 3;
                sub_44F900(object);
                break;
              case 8u:
                v266 = object->gen_period;
                object->unk30 = -16 * unk_5D1150[v266];
                object->unk31 = -16 * unk_5D1558[v266];
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
        v267 = object->unk225 + 1;
        v268 = object->unk19;
        object->unk225 = v267;
        if ( (unsigned __int8)unk_6AFF88[35 * v268] <= v267 )
          object->unk225 = 0;
      }
      else
      {
        sub_454ED0(object, 0);
        sub_4473A0(object);
      }
      goto LABEL_988;
    case 0x6E:
      if ( object->field_F2 == 53 )
      {
        v269 = object->unk82 + 1;
        object->unk82 = v269;
        if ( v269 >= 0x34u )
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
        v270 = object->unk120;
        if ( !v270 )
          goto LABEL_1000;
        if ( v270->unk120 != object )
          object->unk120 = 0;
        if ( !object->unk120 )
LABEL_1000:
          sub_454ED0(object, 0);
      }
      if ( object->is_going )
        object->state_id = (object->state_id + 1) % 14;
      goto LABEL_989;
    case 0x72:
      if ( object->field_F2 != 60 )
        goto LABEL_989;
      v271 = object->unk225 + 1;
      object->unk225 = v271;
      if ( v271 <= 0xC8u )
        goto LABEL_989;
      sub_454ED0(object, 0);
      goto LABEL_988;
    case 0x73:
      if ( object->field_F2 != 62 )
        goto LABEL_989;
      v272 = object->unk225 + 1;
      object->unk225 = v272;
      if ( v272 <= 0xC8u )
        goto LABEL_989;
      sub_454ED0(object, 0);
      goto LABEL_988;
    case 0x74:
      if ( object->field_F2 != 65 )
        goto LABEL_989;
      v273 = object->unk225 + 1;
      object->unk225 = v273;
      if ( v273 <= 0xC8u )
        goto LABEL_989;
      sub_454ED0(object, 0);
      goto LABEL_988;
    case 0x84:
      v274 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v274;
      if ( !(_BYTE)v274 )
        goto LABEL_987;
      goto LABEL_988;
    case 0x8D:
      switch ( object->field_F2 )
      {
        case 0x47u:
          if ( object->unk99 )
          {
            Objects::Create(&MapObjects, object->owner_player, Flagpost|0x84, object->unk5, object->unk7, object->unk29);
            sub_453AB0(dword_4843A0);
            for ( k = sub_4340B0(&MapObjects, object->x, object->y, 8);
                  k;
                  k = sub_434120(&MapObjects, k, object->x, object->y, 8) )
            {
              v276 = object->owner_player;
              if ( k->owner_player != v276 )
              {
                v277 = k->class_id;
                if ( v277 >= 36 && (v277 <= 37 || v277 == 93) )
                  Objects::Create(&MapObjects, v276, (ObjectClass)0xC2u, k->unk5, k->unk7, k->unk29)->state_id = k->class_id;
              }
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x48u:
          v278 = object->unk99;
          if ( v278 )
          {
            object->gen_period = *(&unk_5FDA98[((object->y - v278->y) << 6) - v278->x] + object->x);
            v279 = Objects::Create(
                     &MapObjects,
                     object->owner_player,
                     (ObjectClass)0xC4u,
                     v278->unk5,
                     v278->unk7,
                     v278->unk29);
            v279->gen_period = object->gen_period;
            v279->unk63 = sub_401D70(2 * unk_5D1150[object->gen_period], 0x40000);
            v279->unk64 = sub_401D70(2 * unk_5D1558[object->gen_period], 0x40000);
            v279->unk30 = v279->unk63;
            v279->unk31 = v279->unk64;
            v279->unk77 = object->x;
            v279->unk78 = object->y;
            v279->unk99 = object;
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
          v282 = object->state_id;
          if ( !v282 || v282 == 40 )
            sub_453AB0(dword_484398);
          v283 = object->state_id;
          if ( v283 >= 0x24u )
          {
            if ( v283 >= 0x26u )
            {
              if ( v283 >= 0x28u )
              {
                if ( v283 >= 0x2Au )
                {
                  if ( v283 >= 0x3Au )
                  {
                    v284 = Objects::Create(
                             &MapObjects,
                             4u,
                             (ObjectClass)0x68u,
                             object->unk5,
                             object->unk7,
                             object->unk29);
                    sub_437F30(v284, 18);
                    v284->unk32 |= 0x80000000;
                    sub_4342C0(&MapObjects, object);
                  }
                  else
                  {
                    object->frame = ((unsigned __int8)(v283 & 2) >> 1) + 8;
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
            object->frame = (v283 >> 1) % 6u;
          }
          sub_437EE0(object);
          ++object->state_id;
          goto LABEL_989;
        case 0x4Cu:
          Objects::Create(
            &MapObjects,
            object->owner_player,
            (ObjectClass)0x2Au,
            object->unk5,
            object->unk7,
            object->unk29);
          sub_453AB0(dword_484398);
          sub_415730(unk_5F9158);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Du:
          v285 = Objects::Create(
                   &MapObjects,
                   object->owner_player,
                   (ObjectClass)0x2Bu,
                   object->unk5,
                   object->unk7,
                   object->unk29);
          sub_454ED0(v285, 17);
          sub_453AB0(dword_484338);
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x4Eu:
          Objects::Create(&MapObjects, object->owner_player, Villager|0x80, object->unk5, object->unk7, object->unk29);
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
          v287 = sub_4340B0(&MapObjects, object->x, object->y, 5);
          if ( !v287 )
            goto LABEL_809;
          break;
        case 0x50u:
          Objects::Create(&MapObjects, object->owner_player, Flagpost|0x84, object->unk5, object->unk7, object->unk29);
          Objects::Create(
            &MapObjects,
            object->owner_player,
            (ObjectClass)0xE0u,
            object->unk5,
            object->unk7,
            object->unk29);
          sub_453AB0(dword_48439C);
          for ( ii = sub_4340B0(&MapObjects, object->x, object->y, 5);
                ii;
                ii = sub_434120(&MapObjects, ii, object->x, object->y, 5) )
          {
            if ( ii->owner_player != object->owner_player )
            {
              v291 = ii->class_id;
              if ( v291 >= 103 && (v291 <= 104 || v291 == 110) )
                sub_455240(object);
            }
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x51u:
          v292 = object->unk99;
          if ( v292 )
          {
            object->gen_period = *(&unk_5FDA98[((object->y - v292->y) << 6) - v292->x] + object->x);
            v293 = Objects::Create(
                     &MapObjects,
                     object->owner_player,
                     Mushroom|0x8C,
                     v292->unk5,
                     v292->unk7,
                     v292->unk29);
            v293->gen_period = object->gen_period;
            v293->unk63 = sub_401D70(2 * unk_5D1150[object->gen_period], 0x40000);
            v293->unk64 = sub_401D70(2 * unk_5D1558[object->gen_period], 0x40000);
            v293->unk30 = v293->unk63;
            v293->unk31 = v293->unk64;
            v293->unk77 = object->x;
            v293->unk78 = object->y;
            v293->unk99 = object;
            sub_453AB0(dword_484390);
          }
          sub_4342C0(&MapObjects, object);
          goto LABEL_989;
        case 0x65u:
          v294 = object->unk99;
          if ( v294 )
          {
            Objects::Create(&MapObjects, object->owner_player, Flagpost|0x84, v294->unk5, v294->unk7, v294->unk29);
            sub_453AB0(dword_484348);
            sub_437EE0(object);
            v295 = object->unk99;
            sub_43F970(object->x, object->y);
            Objects::Create(
              &MapObjects,
              object->owner_player,
              Flagpost|0x84,
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
      goto LABEL_989;
    case 0x8E:
      v298 = object->gen_period;
      v299 = 4 * unk_5D1150[v298];
      object->unk63 = v299;
      v300 = 4 * unk_5D1558[v298];
      object->unk30 = v299;
      v301 = object->field_F2;
      v302 = object->health - 1;
      object->unk64 = v300;
      object->health = v302;
      object->unk31 = v300;
      if ( !v301 && unk_6635AE[457 * object_class_id] - 16 > (signed __int16)v302 )
        sub_454ED0(object, 69);
      if ( object->health <= 0 || MapTiles[object->x + 192 * object->y].road && object->field_F2 == 69 )
      {
        sub_4342C0(&MapObjects, object);
        v303 = rand();
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 1, v303 % 40 + 40);
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCBu,
          object->unk5,
          object->unk7,
          object->unk29);
      }
      goto LABEL_988;
    case 0x8F:
      object->frame = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      goto LABEL_988;
    case 0x93:
      v304 = object->unk64;
      v305 = object->field_F2;
      object->unk30 = object->unk63;
      object->unk31 = v304;
      if ( v305 == 70 && object->unk62 > 0 )
      {
        object->unk63 = 0;
        object->unk64 = 0;
        object->unk30 = 0;
        v306 = object->x;
        v307 = object->y << 6;
        object->unk62 = 0;
        object->unk31 = 0;
        object->unk29 = MapTiles[v306 + 3 * v307].texture << 16;
        sub_454ED0(object, 91);
        object->unk225 = 72;
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      v308 = object->field_F2;
      if ( v308 != 91 )
      {
        v310 = object->gen_period + 16;
        v311 = ((BYTE4(v310) & 0x1F) + (signed int)v310) >> 5;
        v312 = (HIDWORD(v311) ^ ((BYTE4(v311) ^ (unsigned __int8)v311) - BYTE4(v311)) & 7) - HIDWORD(v311);
        v313 = object->unk62;
        object->state_id = v312;
        if ( v313 >= 4294951296 )
        {
          if ( v313 < 4294963200 )
          {
            object->frame = byte_484683[5 * (unsigned __int8)v312];
            if ( !v308 )
              sub_454ED0(object, 70);
            goto LABEL_988;
          }
          if ( v313 < 4096 )
          {
            object->frame = byte_484682[5 * (unsigned __int8)v312];
            if ( !v308 )
              sub_454ED0(object, 70);
            goto LABEL_988;
          }
          if ( v313 < 0 )
          {
            object->frame = byte_484682[5 * (unsigned __int8)v312];
            if ( !v308 )
              sub_454ED0(object, 70);
            goto LABEL_988;
          }
          if ( v313 >= 16000 )
            v314 = byte_484680[5 * (unsigned __int8)v312];
          else
            v314 = byte_484681[5 * (unsigned __int8)v312];
        }
        else
        {
          v314 = byte_484684[5 * (unsigned __int8)v312];
        }
        object->frame = v314;
        goto LABEL_988;
      }
      v309 = object->unk225 - 1;
      object->unk225 = v309;
      if ( !v309 )
        sub_4342C0(&MapObjects, object);
      goto LABEL_988;
    case 0x94:
    case 0xA4:
      v315 = object->gen_period;
      v316 = 16 * unk_5D1150[v315];
      object->unk63 = v316;
      v317 = 16 * unk_5D1558[v315];
      object->unk30 = v316;
      object->unk64 = v317;
      object->unk31 = v317;
      v318 = object->frame + 1;
      v319 = object->health - 1;
      object->health = v319;
      x = object->x;
      object->frame = (BYTE4(v318) ^ ((BYTE4(v318) ^ v318) - BYTE4(v318)) & 0xF) - BYTE4(v318);
      y = object->y;
      if ( MapTiles[x + 192 * y].road || object->unk77 == x && object->unk78 == y || (signed __int16)v319 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        v322 = object->class_id;
        if ( v322 == -108 || v322 == -92 )
          sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case 0x95:
      v323 = object->gen_period;
      v324 = 16 * unk_5D1150[v323];
      object->unk63 = v324;
      v325 = 16 * unk_5D1558[v323];
      object->unk30 = v324;
      object->unk64 = v325;
      object->unk31 = v325;
      v326 = object->health - 1;
      v327 = object->frame + 1;
      object->health = v326;
      v328 = object->y;
      v329 = v327 % 12;
      v330 = object->x;
      object->frame = v329;
      if ( MapTiles[v330 + 192 * v328].road
        || object->unk77 == v330 && object->unk78 == v328
        || (signed __int16)v326 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case 0x9C:
      v331 = object->gen_period;
      v332 = 16 * unk_5D1150[v331];
      object->unk63 = v332;
      v333 = 16 * unk_5D1558[v331];
      object->unk30 = v332;
      object->unk64 = v333;
      object->unk31 = v333;
      v334 = object->health - 1;
      v335 = object->frame + 1;
      object->health = v334;
      v336 = object->y;
      v337 = v335 % 12;
      v338 = object->x;
      object->frame = v337;
      if ( MapTiles[v338 + 192 * v336].road
        || object->unk77 == v338 && object->unk78 == v336
        || (signed __int16)v334 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case 0xA9:
      if ( object->field_F2 == 97 )
      {
        v339 = object->unk225;
        if ( v339 )
        {
          object->unk225 = v339 - 1;
        }
        else if ( !(MapTiles[object->x + 192 * object->y].mask1 & 1) )
        {
          sub_454ED0(object, 95);
          sub_453AB0(dword_484324);
          sub_437EE0(object);
        }
      }
      if ( object->field_F2 != 95 )
        goto LABEL_1001;
      v340 = object->unk225;
      if ( v340 )
      {
        v341 = v340 - 1;
        object->unk225 = v341;
        if ( !v341 )
          MapTiles[object->x + 192 * object->y].road = 0;
      }
      if ( object->field_F2 != 95 )
      {
LABEL_1001:
        v343 = object->state_id;
        if ( v343 >= 2u )
          goto LABEL_989;
        object->state_id = v343 + 1;
      }
      else
      {
        v342 = object->state_id;
        if ( !v342 )
          goto LABEL_989;
        object->state_id = v342 - 1;
      }
      goto LABEL_988;
    case 0xC2:
    case 0xE3:
      v344 = object->unk225 - 1;
      object->unk225 = v344;
      if ( !v344 )
        goto LABEL_987;
      goto LABEL_988;
    case 0xC3:
      v345 = object->frame + 1;
      object->frame = v345;
      if ( v345 == 24 && object->unk99 )
      {
        sub_43F970(object->data3[1], object->data3[2]);
        sub_43FAE0(object->unk99, object->data3[1] + 1, object->data3[2] + 1, 0);
      }
      if ( object->frame == 48 )
        goto LABEL_987;
      goto LABEL_988;
    case 0xC4:
      v346 = object->gen_period;
      v347 = 16 * unk_5D1150[v346];
      object->unk63 = v347;
      v348 = 16 * unk_5D1558[v346];
      object->unk30 = v347;
      object->unk64 = v348;
      object->unk31 = v348;
      v349 = object->health - 1;
      v350 = object->frame + 1;
      object->health = v349;
      v351 = object->y;
      v352 = v350 % 12;
      v353 = object->x;
      object->frame = v352;
      if ( MapTiles[v353 + 192 * v351].road
        || object->unk77 == v353 && object->unk78 == v351
        || (signed __int16)v349 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        v354 = rand();
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, v354 % 60 + 60);
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCBu,
          object->unk5,
          object->unk7,
          object->unk29);
        Objects::Create(&MapObjects, object->owner_player, Fire, object->unk5, object->unk7, object->unk29)->health = 10;
      }
      goto LABEL_988;
    case 0xC7:
      switch ( object->field_F2 )
      {
        case 0u:
          object->frame = 0;
          break;
        case 0x6Au:
          object->frame = 5;
          break;
        case 0x6Cu:
          v355 = object->state_id + 1;
          object->state_id = v355;
          if ( v355 >= 4u )
          {
            object->state_id = 0;
            v356 = object->frame + 1;
            object->frame = v356;
            if ( v356 == 1 )
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
          v357 = object->state_id + 1;
          object->state_id = v357;
          if ( v357 >= 4u )
          {
            object->state_id = 0;
            v358 = object->frame;
            if ( v358 )
              object->frame = v358 - 1;
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
    case 0xCA:
      v359 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v359;
      if ( !(_BYTE)v359 )
        goto LABEL_987;
      goto LABEL_988;
    case 0xCB:
      v360 = ((unsigned int)object->frame + 1) % (2 * object->mfb_file->numimages);
      object->frame = v360;
      if ( !(_BYTE)v360 )
        goto LABEL_987;
      goto LABEL_988;
    case 0xCC:
      v361 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v361;
      if ( !(_BYTE)v361 )
        object->frame = 16;
      v362 = object->health - 1;
      object->health = v362;
      if ( (signed __int16)v362 <= 0 )
        goto LABEL_987;
      goto LABEL_988;
    case 0xCD:
      v363 = object->gen_period;
      object->unk30 = 16 * unk_5D1150[v363];
      v364 = object->x;
      v365 = object->data3[1];
      object->unk31 = 16 * unk_5D1558[v363];
      v366 = object->health - 1;
      object->health = v366;
      if ( v365 == v364 && object->data3[2] == object->y || (signed __int16)v366 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, 40);
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCAu,
          object->unk5,
          object->unk7,
          object->unk29);
        sub_453AB0(dword_4843A4);
      }
      v367 = object->unk225;
      if ( v367 )
        object->unk225 = v367 - 1;
      else
        object->unk225 = 4;
      goto LABEL_988;
    case 0xD1:
      v368 = object->gen_period;
      v369 = 16 * unk_5D1150[v368];
      object->unk63 = v369;
      v370 = 16 * unk_5D1558[v368];
      object->unk30 = v369;
      object->unk64 = v370;
      object->unk31 = v370;
      v371 = object->health - 1;
      v372 = object->frame + 1;
      object->health = v371;
      v373 = object->y;
      v374 = v372 % 12;
      v375 = object->x;
      object->frame = v374;
      if ( MapTiles[v375 + 192 * v373].road
        || object->unk77 == v375 && object->unk78 == v373
        || (signed __int16)v371 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 0, object->unk83);
      }
      goto LABEL_988;
    case 0xD2:
      switch ( object->field_F2 )
      {
        case 0u:
          object->frame = 0;
          break;
        case 0x6Eu:
          object->frame = 2;
          break;
        case 0x6Fu:
          v376 = object->gen_period + 1;
          object->gen_period = v376;
          if ( v376 >= 4u )
          {
            object->gen_period = 0;
            v377 = object->frame + 1;
            object->frame = v377;
            if ( v377 >= 2u )
              sub_454ED0(object, 110);
            goto LABEL_988;
          }
          break;
        case 0x70u:
          v378 = object->gen_period + 1;
          object->gen_period = v378;
          if ( v378 >= 4u )
          {
            object->gen_period = 0;
            v379 = object->frame;
            if ( !v379 || (object->frame = v379 - 1) == 0 )
              sub_454ED0(object, 0);
            goto LABEL_988;
          }
          break;
        default:
          goto LABEL_989;
      }
      goto LABEL_989;
    case 0xDD:
      v380 = object->gen_period;
      v381 = object->gen_max;
      if ( v380 >= v381 )
      {
        if ( v380 <= v381 )
          goto LABEL_965;
        if ( v380 - v381 >= 128 )
          v382 = v380 + 4;
        else
          v382 = v380 - 4;
      }
      else if ( v381 - v380 >= 128 )
      {
        v382 = v380 - 4;
      }
      else
      {
        v382 = v380 + 4;
      }
      object->gen_period = v382;
      sub_437EE0(object);
LABEL_965:
      v383 = object->gen_period;
      if ( object->gen_max == v383 )
        object->frame = (unsigned __int8)(v383 & 0xDF) >> 5;
      else
        object->frame = 2
                      * ((((unsigned __int64)((v383 + 32) / 64) >> 32) ^ abs((v383 + 32) / 64) & 3)
                       - ((unsigned __int64)((v383 + 32) / 64) >> 32))
                      + 1;
      sub_437EE0(object);
      v384 = object->unk225;
      if ( !v384 )
        goto LABEL_989;
      v385 = v384 - 1;
      object->unk225 = v385;
      if ( !v385 && object->owner_player == cur_player )
        --dword_484410;
      goto LABEL_988;
    case 0xDE:
      if ( object->unk62 > 0 )
      {
        sub_434E60(&MapObjects, object, object->unk99, object->x, object->y, 3, 1000);
        v386 = 3;
        Objects::Create(
          &MapObjects,
          object->owner_player,
          (ObjectClass)0xCBu,
          object->unk5,
          object->unk7,
          object->unk29);
        do
        {
          v387 = (unsigned __int8)((char)rand() % -4) + 1;
          v388 = rand();
          v387 <<= 16;
          v389 = object->unk7;
          v390 = object->unk5;
          object->gen_period = (((unsigned __int64)v388 >> 32) ^ abs(v388)) - ((unsigned __int64)v388 >> 32);
          v391 = Objects::Create(&MapObjects, object->owner_player, (ObjectClass)0x38u, v390, v389, object->unk29);
          v391->unk62 = 0x10000;
          v391->gen_period = object->gen_period;
          v391->frame = 1;
          v391->unk63 = sub_401D70(2 * unk_5D1150[object->gen_period], v387);
          v391->unk64 = sub_401D70(2 * unk_5D1558[object->gen_period], v387);
          v392 = (unsigned __int16)((signed __int16)rand() % -2048);
          v391->unk63 = sub_401D90(v391->unk63, 0x10000) + v392 - 1024;
          v393 = (unsigned __int16)((signed __int16)rand() % -2048);
          --v386;
          v391->unk64 = sub_401D90(v391->unk64, 0x10000) + v393 - 1024;
          v391->unk30 = v391->unk63;
          v391->unk31 = v391->unk64;
          v391->unk99 = object;
          v391->unk83 = -1;
        }
        while ( v386 );
        sub_415860(dword_484390);
        dword_4846B4 = 32;
        sub_4342C0(&MapObjects, object);
      }
      goto LABEL_989;
    case 0xDF:
      v394 = object->gen_period;
      v395 = 16 * unk_5D1150[v394];
      object->unk63 = v395;
      v396 = 16 * unk_5D1558[v394];
      object->unk30 = v395;
      object->unk64 = v396;
      object->unk31 = v396;
      v397 = object->health - 1;
      v398 = object->frame + 1;
      object->health = v397;
      v399 = object->x;
      v400 = v398 % 12;
      v401 = object->y;
      object->frame = v400;
      if ( MapTiles[v399 + 192 * v401].road
        || object->unk77 == v399 && object->unk78 == v401
        || (signed __int16)v397 <= 0 )
      {
        sub_4342C0(&MapObjects, object);
        Objects::Create(&MapObjects, object->owner_player, Flagpost|0x84, object->unk5, object->unk7, object->unk29);
      }
      goto LABEL_988;
    case 0xE0:
      v402 = object->unk225 + 1;
      object->unk225 = v402;
      if ( v402 > 0x78u )
        goto LABEL_987;
      goto LABEL_988;
    case 0xE6:
      v403 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v403;
      if ( !(_BYTE)v403 )
        goto LABEL_987;
      goto LABEL_988;
    case 0xE7:
      v404 = ((unsigned int)object->frame + 1) % (4 * object->mfb_file->numimages);
      object->frame = v404;
      if ( !(_BYTE)v404 )
      {
        v405 = object->unk82 + 1;
        object->unk82 = v405;
        if ( v405 > 4u )
          goto LABEL_987;
      }
      goto LABEL_988;
    case 0x35:
    case 0x50:
    case 0x62:
    case 0x9F:
    case 0xA0:
    case 0xAC:
    case 0xAD:
    case 0xAE:
    case 0xB0:
    case 0xB1:
    case 0xB2:
    case 0xC0:
    case 0xC1:
    case 0xC6:
    case 0xC8:
    case 0xD3:
    case 0xD4:
      goto LABEL_988;
    default:
      goto LABEL_989;
  }
  while ( 1 )
  {
    if ( object->owner_player == v287->owner_player )
    {
      v288 = v287->class_id;
      if ( v288 == 78 )
      {
        v289 = v287->field_F2;
        if ( v289 && v289 != 1 )
          goto LABEL_808;
        sub_454ED0(v287, 2);
        v287->frame = 2;
        sub_437EE0(v287);
        goto LABEL_807;
      }
      if ( v288 != 94 )
      {
        if ( v288 != 110 && v288 != 111 )
          goto LABEL_808;
        v287->unk225 = 1;
LABEL_807:
        Objects::Create(&MapObjects, object->owner_player, Flagpost|0x81, v287->unk5, v287->unk7, v287->unk29);
        goto LABEL_808;
      }
      sub_4342C0(&MapObjects, v287);
      Objects::Create(&MapObjects, v287->owner_player, Wheat|0x1, v287->unk5, v287->unk7, v287->unk29);
      Objects::Create(&MapObjects, object->owner_player, Flagpost|0x81, v287->unk5, v287->unk7, v287->unk29);
    }
LABEL_808:
    v287 = sub_434120(&MapObjects, v287, object->x, object->y, 5);
    if ( !v287 )
    {
LABEL_809:
      sub_4342C0(&MapObjects, object);
      goto LABEL_989;
    }
  }
}