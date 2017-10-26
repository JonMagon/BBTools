char __thiscall Objects::DrawObject(MapObject *this)
{
  MapObject *object; // edi@1
  MapObject *v2; // eax@3
  int v3; // ebx@6
  MFBEntry *v4; // ecx@18
  MFBEntry *v5; // ecx@20
  unsigned __int8 v6; // al@24
  unsigned __int8 v7; // al@30
  unsigned __int8 v8; // al@35
  int v9; // eax@48
  unsigned __int8 v10; // cl@53
  int v11; // edx@55
  unsigned __int8 v12; // cl@64
  MFBEntry *v13; // eax@73
  int v14; // eax@78
  int v15; // eax@85
  unsigned __int8 v16; // al@102
  MFBEntry *v17; // ecx@104
  MFBEntry *v18; // ecx@118
  MFBEntry *v19; // ecx@125
  unsigned __int8 v20; // cl@130
  unsigned __int8 v21; // al@136
  MFBEntry *v22; // eax@139
  MFBEntry *v23; // ecx@180
  MFBEntry *v24; // eax@187
  MFBEntry *v25; // ecx@249
  signed int v26; // eax@255
  unsigned __int8 v27; // al@317
  __int64 v28; // rax@325
  MFBEntry *v29; // ecx@325
  __int64 v30; // rax@328
  __int64 v31; // rax@330
  ObjectSex sex; // al@331
  __int64 v33; // rax@335
  __int64 v34; // rax@343
  __int64 v35; // rax@350
  __int64 v36; // rax@355
  __int64 v37; // rax@359
  __int64 v38; // rax@367
  __int64 v39; // rax@371
  __int64 v40; // rax@379
  __int64 v41; // rax@383
  MFBEntry *v42; // ecx@388
  __int64 v43; // rax@391
  MFBEntry *v44; // ecx@396
  __int64 v45; // rax@399
  __int64 v46; // rax@406
  __int64 v47; // rax@410
  __int64 v48; // rax@415
  __int64 v49; // rax@423
  __int64 v50; // rax@431
  __int64 v51; // rax@439
  __int64 v52; // rax@447
  __int64 v53; // rax@455
  __int64 v54; // rax@463
  __int64 v55; // rax@471
  __int64 v56; // rax@479
  __int64 v57; // rax@487
  __int64 v58; // rax@494
  __int64 v59; // rax@498
  __int64 v60; // rax@501
  __int64 v61; // rax@534
  __int64 v62; // rax@537
  __int64 v63; // rax@543
  __int64 v64; // rax@547
  __int64 v65; // rax@550
  __int64 v66; // rax@557
  __int64 v67; // rax@563
  __int64 v68; // rax@563
  int v69; // eax@595
  int v70; // ecx@607
  __int64 v71; // rax@627
  __int64 v72; // rax@630
  __int64 v73; // rax@631
  MFBEntry *v74; // ecx@631
  __int64 v75; // rax@634
  __int64 v76; // rax@638
  __int64 v77; // rax@641
  __int64 v78; // rax@644
  __int64 v79; // rax@647
  __int64 v80; // rax@655
  __int64 v81; // rax@659
  __int64 v82; // rax@664
  __int64 v83; // rax@668
  int v84; // eax@668
  __int64 v85; // rax@671
  __int64 v86; // rax@676
  __int64 v87; // rax@685
  __int64 v88; // rax@688
  __int64 v89; // rax@691
  __int64 v90; // rax@695
  int v91; // eax@695
  __int64 v92; // rax@698
  __int64 v93; // rax@703
  __int64 v94; // rax@706
  __int64 v95; // rax@713
  __int64 v96; // rax@716
  __int64 v97; // rax@720
  __int64 v98; // rax@723
  __int64 v99; // rax@727
  __int64 v100; // rax@730
  __int64 v101; // rax@734
  int v102; // eax@734
  __int64 v103; // rax@737
  __int64 v104; // rax@742
  __int64 v105; // rax@745
  unsigned __int8 v106; // al@746
  MFBEntry *v107; // ecx@762
  __int64 v108; // rax@767
  unsigned __int8 v109; // al@776
  unsigned __int8 v110; // al@780
  MFBEntry *v111; // eax@785
  MFBEntry *v112; // ecx@802
  __int64 v113; // rax@821
  unsigned __int8 v114; // al@835
  char *v115; // esi@836
  unsigned __int8 v116; // al@842
  MFBEntry *v117; // eax@862
  __int64 v118; // rax@867
  __int64 v119; // rax@867
  MFBEntry *v120; // eax@871
  unsigned __int8 v121; // al@876
  __int64 v122; // rax@889
  __int64 v123; // rax@889
  char *v124; // esi@903
  char *v125; // ebx@903
  __int64 v126; // rax@907
  __int64 v127; // rax@907
  int v128; // eax@926
  unsigned __int8 v129; // al@931
  unsigned __int8 v130; // al@945
  unsigned __int8 v131; // cl@950
  int v132; // ecx@965
  int x; // [sp-10h] [bp-20h]@12
  int v135; // [sp-10h] [bp-20h]@20
  int v136; // [sp-10h] [bp-20h]@104
  int v137; // [sp-10h] [bp-20h]@118
  int v138; // [sp-10h] [bp-20h]@125
  int v139; // [sp-10h] [bp-20h]@177
  int v140; // [sp-10h] [bp-20h]@249
  int v141; // [sp-10h] [bp-20h]@325
  int v142; // [sp-10h] [bp-20h]@627
  int v143; // [sp-10h] [bp-20h]@802
  int y; // [sp-Ch] [bp-1Ch]@11
  int v145; // [sp-Ch] [bp-1Ch]@20
  int v146; // [sp-Ch] [bp-1Ch]@104
  int v147; // [sp-Ch] [bp-1Ch]@118
  int v148; // [sp-Ch] [bp-1Ch]@125
  int v149; // [sp-Ch] [bp-1Ch]@177
  int v150; // [sp-Ch] [bp-1Ch]@249
  int v151; // [sp-Ch] [bp-1Ch]@325
  int v152; // [sp-Ch] [bp-1Ch]@627
  int v153; // [sp-Ch] [bp-1Ch]@802
  int frame_id; // [sp-8h] [bp-18h]@11
  int v155; // [sp-8h] [bp-18h]@20
  int v156; // [sp-8h] [bp-18h]@104
  int v157; // [sp-8h] [bp-18h]@118
  signed int v158; // [sp-8h] [bp-18h]@177
  int v159; // [sp-8h] [bp-18h]@249
  int v160; // [sp-8h] [bp-18h]@325
  signed int v161; // [sp-8h] [bp-18h]@627

  object = this;
  if ( !this->mfb_file )
    Objects::GetMFB(this);
  LOBYTE(v2) = object->field_F8;
  byte_4842BC = object->field_F8;
  if ( object->field_128 )
  {
    v2 = object->field_28;
    if ( !v2 )
    {
      v2 = (MapObject *)object->unk32;
      if ( !((unsigned int)v2 & 0x1000000) )
      {
        v2 = (MapObject *)object->x;
        v3 = MapTiles[(_DWORD)((char *)v2 + 192 * object->y)].mask1;
        if ( !(BYTE1(v3) & 0x40) )
        {
          sub_43F310(object);
          if ( object->unk32 & 0x2000000 )
            byte_4842C0 = 2;
          switch ( object->class_id )
          {
            case 0u:
              if ( current_season == 3 )
              {
                frame_id = 255;
                object->mfb_file->frame_id = 1;
                y = object->draw_y;
                goto LABEL_916;
              }
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 1u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
              {
                DrawTexture(l_holy01_mfb, object->draw_x, object->draw_y, 255, 1);
                DrawTexture(l_holy02_mfb, object->draw_x, object->draw_y, 255, 1);
              }
              if ( object->unk32 & 0x20000 )
                DrawTexture(churover_mfb, object->draw_x, object->draw_y, 0, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 2u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
              {
                v155 = 255;
                v145 = object->draw_y;
                v135 = object->draw_x;
                v5 = l_peas01_mfb;
              }
              else
              {
                if ( !(object->unk32 & 0x20000) )
                  goto LABEL_24;
                v155 = 0;
                v145 = object->draw_y;
                v135 = object->draw_x;
                v5 = peasover_mfb;
              }
              DrawTexture(v5, v135, v145, v155, 1);
LABEL_24:
              v6 = object->frame;
              if ( v6 )
                DrawTexture(baby_mfb, object->draw_x - 145, object->draw_y, v6 - 1, 1);
              if ( current_season == 3 )
                DrawTexture(hutsmoke_mfb, object->draw_x, object->draw_y, object->data8[2] >> 2, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 5u:
              v7 = object->frame;
              if ( v7 )
              {
                frame_id = 255;
                tree02_mfb->frame_id = v7;
                y = object->draw_y;
                x = object->draw_x;
                v4 = tree02_mfb;
                goto LABEL_918;
              }
              if ( current_season == 3 )
              {
                frame_id = 255;
                tree04_mfb->frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
                v4 = tree04_mfb;
                goto LABEL_918;
              }
              frame_id = 255;
              object->mfb_file->frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 6u:
              v8 = object->frame;
              if ( v8 )
              {
                frame_id = 255;
                tree02_mfb->frame_id = v8;
                y = object->draw_y;
                x = object->draw_x;
                v4 = tree02_mfb;
              }
              else
              {
                frame_id = 255;
                y = object->draw_y;
                x = object->draw_x;
                if ( current_season != 3 )
                  goto LABEL_917;
                v4 = tree11_mfb;
              }
              goto LABEL_918;
            case 0xAu:
              if ( !is_night )
                DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
              DrawTexture((MFBEntry *)unk_6634E8, object->draw_x + 54, object->draw_y + 8, 255, 1);
              *((_DWORD *)unk_6634E8 + 20) = (unsigned int)(*((_DWORD *)unk_6634E8 + 20) + 1)
                                           % *((_DWORD *)unk_6634E8 + 19);
              goto LABEL_919;
            case 0x10u:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x18u:
              frame_id = 255;
              object->mfb_file->frame_id = object->state_id >> 1;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x19u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              frame_id = object->frame >> 2;
              y = object->draw_y - 10;
              x = object->draw_x;
              v4 = gasmold_mfb;
              goto LABEL_918;
            case 0x1Au:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x1Cu:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame >> 1;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x1Du:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x21u:
              v9 = object->field_F2;
              if ( !object->field_F2 )
              {
                frame_id = object->frame >> 2;
                y = object->draw_y;
                v4 = egg_mfb;
                x = object->draw_x;
                goto LABEL_918;
              }
              if ( v9 == 25 )
              {
                v10 = object->frame;
                if ( v10 <= 5u )
                {
                  frame_id = 255;
                  object->mfb_file->frame_id = v10 >> 2;
                  y = object->draw_y;
                  goto LABEL_916;
                }
                switch ( object->gen_period >> 6 )
                {
                  case 0:
                    v11 = v10 >> 2;
                    goto LABEL_59;
                  case 1:
                    v11 = (v10 >> 2) + 24;
                    goto LABEL_59;
                  case 2:
                    v11 = (v10 >> 2) + 48;
                    goto LABEL_59;
                  case 3:
                    v11 = (v10 >> 2) + 72;
LABEL_59:
                    object->mfb_file->frame_id = v11;
                    break;
                  default:
                    break;
                }
                frame_id = 255;
                y = object->draw_y;
                x = object->draw_x;
              }
              else
              {
                if ( v9 != 26 )
                  goto LABEL_919;
                frame_id = 27;
                y = object->draw_y;
                x = object->draw_x;
              }
              goto LABEL_917;
            case 0x22u:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame >> 2;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x24u:
              v12 = object->field_F2;
              if ( !v12 && object->owner_player != cur_player )
                goto LABEL_919;
              if ( !v12 )
              {
                frame_id = 255;
                object->mfb_file->frame_id = 0;
                y = object->draw_y;
                goto LABEL_916;
              }
              if ( v12 != 18 )
                goto LABEL_919;
              frame_id = 255;
              object->mfb_file->frame_id = object->frame >> 1;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x25u:
              if ( !object->state_id && object->owner_player != cur_player )
                goto LABEL_919;
              v13 = object->mfb_file;
              v13->frame_id = object->frame >= 0x3Cu;
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x29u:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x2Au:
              v14 = object->state_id;
              if ( object->state_id )
              {
                if ( v14 == 1 )
                {
                  blkcloud_mfb->frame_id = 3;
                  cloud_mfb->frame_id = 3;
                  lgtning_mfb->frame_id = object->frame;
                  DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                  DrawTexture(lgtning_mfb, object->draw_x, object->draw_y - 80, 255, 1);
                  frame_id = 255;
                  y = object->draw_y - 80;
                  x = object->draw_x;
                  v4 = cloud_mfb;
                }
                else
                {
                  if ( v14 != 2 )
                    goto LABEL_919;
                  blkcloud_mfb->frame_id = object->frame >> 2;
                  cloud_mfb->frame_id = object->frame >> 2;
                  DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                  frame_id = 255;
                  y = object->draw_y - 80;
                  x = object->draw_x;
                  v4 = cloud_mfb;
                }
              }
              else
              {
                blkcloud_mfb->frame_id = object->frame >> 2;
                cloud_mfb->frame_id = object->frame >> 2;
                DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                frame_id = 255;
                y = object->draw_y - 80;
                x = object->draw_x;
                v4 = cloud_mfb;
              }
              goto LABEL_918;
            case 0x2Bu:
              v15 = object->state_id;
              if ( object->state_id )
              {
                if ( v15 == 1 )
                {
                  blkcloud_mfb->frame_id = 3;
                  cloud_mfb->frame_id = 3;
                  DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                  if ( object->field_F2 == 17 )
                  {
                    rain_mfb->frame_id = object->frame >> 2;
                    DrawTexture(rain_mfb, object->draw_x, object->draw_y - 80, 255, 1);
                  }
                  frame_id = 255;
                  y = object->draw_y - 80;
                  x = object->draw_x;
                  v4 = cloud_mfb;
                }
                else
                {
                  if ( v15 != 2 )
                    goto LABEL_919;
                  blkcloud_mfb->frame_id = object->frame >> 2;
                  cloud_mfb->frame_id = object->frame >> 2;
                  DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                  frame_id = 255;
                  y = object->draw_y - 80;
                  x = object->draw_x;
                  v4 = cloud_mfb;
                }
              }
              else
              {
                blkcloud_mfb->frame_id = object->frame >> 2;
                cloud_mfb->frame_id = object->frame >> 2;
                DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                frame_id = 255;
                y = object->draw_y - 80;
                x = object->draw_x;
                v4 = cloud_mfb;
              }
              goto LABEL_918;
            case 0x2Cu:
              frame_id = 12;
              y = object->draw_y;
              x = object->draw_x;
              v4 = equake_mfb;
              goto LABEL_918;
            case 0x2Eu:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x2Fu:
              object->mfb_file->frame_id = 0;
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
              if ( is_night )
              {
                frame_id = 255;
                y = object->draw_y;
                x = object->draw_x;
                v4 = l_well01_mfb;
                goto LABEL_918;
              }
              if ( !(object->unk32 & 0x20000) )
                goto LABEL_919;
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              v4 = wellover_mfb;
              goto LABEL_918;
            case 0x30u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x31u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x32u:
              v16 = object->frame >> 1;
              goto LABEL_915;
            case 0x33u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
              {
                v156 = 255;
                v146 = object->draw_y;
                v136 = object->draw_x;
                v17 = l_farm01_mfb;
              }
              else
              {
                if ( !(object->unk32 & 0x20000) )
                  goto LABEL_108;
                v156 = 0;
                v146 = object->draw_y;
                v136 = object->draw_x;
                v17 = farmover_mfb;
              }
              DrawTexture(v17, v136, v146, v156, 1);
LABEL_108:
              if ( object->unk32 & 0x80000 )
              {
                aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
                DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
                DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
                DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
              }
              if ( object->state_id != 1 )
                DrawTexture(cocker_mfb, object->draw_x, object->draw_y, 0, 1);
              switch ( object->state_id )
              {
                case 1u:
                  frame_id = object->frame;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = feed_mfb;
                  goto LABEL_918;
                case 2u:
                  frame_id = object->frame;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = cocker_mfb;
                  goto LABEL_918;
                case 3u:
                  frame_id = 0;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = cowshed_mfb;
                  goto LABEL_918;
                case 4u:
                  frame_id = 0;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = pigsy_mfb;
                  goto LABEL_918;
                default:
                  goto LABEL_919;
              }
              goto LABEL_919;
            case 0x35u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
              {
                v157 = 255;
                v147 = object->draw_y;
                v137 = object->draw_x;
                v18 = l_bake01_mfb;
              }
              else
              {
                if ( !(object->unk32 & 0x20000) )
                  goto LABEL_122;
                v157 = 0;
                v147 = object->draw_y;
                v137 = object->draw_x;
                v18 = bakeover_mfb;
              }
              DrawTexture(v18, v137, v147, v157, 1);
LABEL_122:
              DrawTexture(
                bakeanim_mfb,
                object->draw_x,
                object->draw_y,
                (unsigned __int8)(object->data8[2] & 0xC) >> 2,
                1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0x36u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
              {
                v148 = object->draw_y;
                v138 = object->draw_x;
                v19 = l_brew01_mfb;
              }
              else
              {
                if ( !(object->unk32 & 0x20000) )
                  goto LABEL_129;
                v148 = object->draw_y;
                v138 = object->draw_x;
                v19 = brewover_mfb;
              }
              DrawTexture(v19, v138, v148, 255, 1);
LABEL_129:
              if ( object->field_F2 == 100 )
              {
                v20 = object->frame;
                if ( v20 >= 3u )
                  DrawTexture(brewsmal_mfb, object->draw_x, object->draw_y, v20 - 3, 1);
                else
                  DrawTexture(brewbig_mfb, object->draw_x, object->draw_y, v20, 1);
              }
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0x37u:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x38u:
              DrawTexture(fireball_mfb, object->draw_x, object->draw_y, 0, 1);
              v21 = object->data8[2];
              goto LABEL_914;
            case 0x3Au:
              switch ( object->field_F2 )
              {
                case 0x1Bu:
                  switch ( object->state_id )
                  {
                    default:
                      v22 = d_male_mfb;
                      if ( object->mfb_file != d_male_mfb )
                        goto LABEL_176;
                      break;
                    case 1u:
                      v22 = d_male_mfb;
                      if ( object->mfb_file != d_male_mfb )
                        goto LABEL_176;
                      break;
                    case 2u:
                      v22 = d_fema_mfb;
                      if ( object->mfb_file != d_fema_mfb )
                        goto LABEL_176;
                      break;
                    case 3u:
                      v22 = d_prie_mfb;
                      if ( object->mfb_file != d_prie_mfb )
                        goto LABEL_176;
                      break;
                    case 4u:
                      v22 = d_buil_mfb;
                      if ( object->mfb_file != d_buil_mfb )
                        goto LABEL_176;
                      break;
                    case 5u:
                      v22 = d_taxm_mfb;
                      if ( object->mfb_file != d_taxm_mfb )
                        goto LABEL_176;
                      break;
                    case 6u:
                      v22 = d_pike_mfb;
                      if ( object->mfb_file != d_pike_mfb )
                        goto LABEL_176;
                      break;
                    case 7u:
                      v22 = d_foot_mfb;
                      if ( object->mfb_file != d_foot_mfb )
                        goto LABEL_176;
                      break;
                    case 8u:
                      v22 = d_knig_mfb;
                      if ( object->mfb_file != d_knig_mfb )
                        goto LABEL_176;
                      break;
                    case 9u:
                      v22 = d_wiza_mfb;
                      if ( object->mfb_file != d_wiza_mfb )
                        goto LABEL_176;
                      break;
                    case 0xBu:
                      v22 = d_oldm_mfb;
                      if ( object->mfb_file != d_oldm_mfb )
                        goto LABEL_176;
                      break;
                    case 0xCu:
                      v22 = d_oldw_mfb;
                      if ( object->mfb_file != d_oldw_mfb )
                        goto LABEL_176;
                      break;
                    case 0xDu:
                      v22 = d_kidm_mfb;
                      if ( object->mfb_file != d_kidm_mfb )
                        goto LABEL_176;
                      break;
                    case 0xEu:
                      v22 = d_kidf_mfb;
                      if ( object->mfb_file != d_kidf_mfb )
                        goto LABEL_176;
                      break;
                    case 0x10u:
                      v22 = d_cava_mfb;
                      if ( object->mfb_file != d_cava_mfb )
                        goto LABEL_176;
                      break;
                    case 0x13u:
                      v22 = d_arch_mfb;
                      if ( object->mfb_file != d_arch_mfb )
                        goto LABEL_176;
                      break;
                    case 0x14u:
                      v22 = d_jest_mfb;
                      if ( object->mfb_file != d_jest_mfb )
                        goto LABEL_176;
                      break;
                    case 0x20u:
                      v22 = d_groom_mfb;
                      if ( object->mfb_file != d_groom_mfb )
                        goto LABEL_176;
                      break;
                    case 0x21u:
                      v22 = d_bride_mfb;
                      if ( object->mfb_file != d_bride_mfb )
LABEL_176:
                        SetObjectMFBFile(object, v22);
                      break;
                  }
                  v158 = object->frame >> 2;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  goto LABEL_230;
                case 0x1Cu:
                  if ( object->mfb_file != murd_wst_mfb )
                    SetObjectMFBFile(object, murd_wst_mfb);
                  v158 = 255;
                  murd_wst_mfb->frame_id = 0;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  v23 = murd_wst_mfb;
                  goto LABEL_231;
                case 0x1Du:
                  if ( object->mfb_file != zombdead_mfb )
                    SetObjectMFBFile(object, zombdead_mfb);
                  v158 = 255;
                  v149 = object->draw_y;
                  goto LABEL_229;
                case 0x1Eu:
                  if ( object->mfb_file != cowchopm_mfb )
                    SetObjectMFBFile(object, cowchopm_mfb);
                  v158 = 255;
                  cowchopm_mfb->frame_id = cowchopm_mfb->numimages - 1;
                  v23 = cowchopm_mfb;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  goto LABEL_231;
                case 0x1Fu:
                  v24 = cowplode_mfb;
                  if ( object->mfb_file != cowplode_mfb )
                    goto LABEL_227;
                  goto LABEL_228;
                case 0x21u:
                  if ( object->mfb_file != pikedie_mfb )
                    SetObjectMFBFile(object, pikedie_mfb);
                  v158 = 255;
                  pikedie_mfb->frame_id = object->frame >> 2;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  v23 = pikedie_mfb;
                  goto LABEL_231;
                case 0x22u:
                  if ( object->mfb_file != footdie_mfb )
                    SetObjectMFBFile(object, footdie_mfb);
                  v158 = 255;
                  footdie_mfb->frame_id = object->frame >> 2;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  v23 = footdie_mfb;
                  goto LABEL_231;
                case 0x23u:
                  if ( object->mfb_file != flagdie_mfb )
                    SetObjectMFBFile(object, flagdie_mfb);
                  v158 = 255;
                  flagdie_mfb->frame_id = object->frame >> 2;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  v23 = flagdie_mfb;
                  goto LABEL_231;
                case 0x24u:
                  if ( object->mfb_file != wizadie_mfb )
                    SetObjectMFBFile(object, wizadie_mfb);
                  v158 = 255;
                  wizadie_mfb->frame_id = object->frame >> 2;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  v23 = wizadie_mfb;
                  goto LABEL_231;
                case 0x25u:
                  if ( object->mfb_file != skeleton_mfb )
                    SetObjectMFBFile(object, skeleton_mfb);
                  v158 = 255;
                  v149 = object->draw_y;
                  v139 = object->draw_x;
                  v23 = skeleton_mfb;
                  goto LABEL_231;
                case 0x62u:
                  if ( object->state_id == 23 )
                  {
                    v24 = wolfdead_mfb;
                    if ( object->mfb_file == wolfdead_mfb )
                      goto LABEL_228;
                  }
                  else
                  {
                    v24 = darkdead_mfb;
                    if ( object->mfb_file == darkdead_mfb )
                      goto LABEL_228;
                  }
                  goto LABEL_227;
                case 0x63u:
                  if ( object->state_id == 24 )
                  {
                    v24 = waspdead_mfb;
                    if ( object->mfb_file == waspdead_mfb )
                      goto LABEL_228;
                  }
                  else
                  {
                    v24 = bloodead_mfb;
                    if ( object->mfb_file == bloodead_mfb )
                      goto LABEL_228;
                  }
LABEL_227:
                  SetObjectMFBFile(object, v24);
LABEL_228:
                  v158 = 255;
                  object->mfb_file->frame_id = object->frame >> 2;
                  v149 = object->draw_y;
LABEL_229:
                  v139 = object->draw_x;
LABEL_230:
                  v23 = object->mfb_file;
LABEL_231:
                  DrawTexture(v23, v139, v149, v158, 1);
LABEL_232:
                  if ( object->disease )
                  {
                    buzz_mfb->frame_id = object->data8[2] % 0x12u / 3;
                    DrawTexture(buzz_mfb, object->draw_x, object->draw_y, 255, 1);
                  }
                  if ( !(object->unk32 & 0x80000) )
                    goto LABEL_919;
                  frame_id = 255;
                  aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = aargh_mfb;
                  break;
                case 0x68u:
                  v24 = deadbat_mfb;
                  if ( object->mfb_file != deadbat_mfb )
                    goto LABEL_227;
                  goto LABEL_228;
                case 0x69u:
                  if ( object->mfb_file != giandead_mfb )
                    SetObjectMFBFile(object, giandead_mfb);
                  v158 = 255;
                  v149 = object->draw_y;
                  goto LABEL_229;
                case 0x71u:
                  if ( object->mfb_file != ogredead_mfb )
                    SetObjectMFBFile(object, ogredead_mfb);
                  v158 = 255;
                  v149 = object->draw_y;
                  goto LABEL_229;
                case 0x72u:
                  v24 = vampdead_mfb;
                  if ( object->mfb_file != vampdead_mfb )
                    goto LABEL_227;
                  goto LABEL_228;
                case 0x76u:
                  v24 = cowkill_mfb;
                  if ( object->mfb_file != cowkill_mfb )
                    goto LABEL_227;
                  goto LABEL_228;
                case 0x77u:
                  v24 = cowdie_mfb;
                  if ( object->mfb_file != cowdie_mfb )
                    goto LABEL_227;
                  goto LABEL_228;
                default:
                  goto LABEL_232;
              }
              goto LABEL_918;
            case 0x3Cu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x3Du:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x3Eu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x42u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
                DrawTexture(l_tax01_mfb, object->draw_x, object->draw_y, 255, 1);
              else
                DrawTexture(ticktock_mfb, object->draw_x, object->draw_y, 0, 1);
              if ( object->unk32 & 0x20000 )
                DrawTexture(taxover_mfb, object->draw_x, object->draw_y, 0, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0x43u:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame >> 1;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x44u:
              v16 = object->frame >> 1;
              goto LABEL_915;
            case 0x45u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              DrawTexture(sign_mfb, object->draw_x, object->draw_y, object->frame, 1);
              if ( is_night )
              {
                v159 = 255;
                v150 = object->draw_y;
                v140 = object->draw_x;
                v25 = l_work01_mfb;
              }
              else
              {
                if ( !(object->unk32 & 0x20000) )
                  goto LABEL_253;
                v159 = 0;
                v150 = object->draw_y;
                v140 = object->draw_x;
                v25 = workover_mfb;
              }
              DrawTexture(v25, v140, v150, v159, 1);
LABEL_253:
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 25, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x + 10;
              goto LABEL_918;
            case 0x46u:
              v26 = object->field_F2;
              if ( !object->field_F2 )
              {
                frame_id = 255;
                object->mfb_file->frame_id = object->gen_period >> 6;
                y = object->draw_y;
                x = object->draw_x;
                goto LABEL_917;
              }
              if ( v26 < 21 || v26 > 22 )
                goto LABEL_919;
              frame_id = 255;
              fired_mfb->frame_id = object->gen_period >> 6;
              y = object->draw_y;
              x = object->draw_x;
              v4 = fired_mfb;
              goto LABEL_918;
            case 0x47u:
              frame_id = 255;
              object->mfb_file->frame_id = object->gen_period >> 6;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x48u:
              if ( object->owner_player != cur_player )
                goto LABEL_919;
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x49u:
              frame_id = 255;
              object->mfb_file->frame_id = 0;
              y = object->draw_y;
              goto LABEL_916;
            case 0x4Au:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x4Bu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x4Cu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x4Du:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x4Eu:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, object->frame, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              frame_id = 255;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              y = object->draw_y + 20;
              x = object->draw_x;
              v4 = aargh_mfb;
              goto LABEL_918;
            case 0x4Fu:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x50u:
              frame_id = 255;
              object->mfb_file->frame_id = object->data8[2] >> 2;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x51u:
              object->mfb_file->frame_id = 0;
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
              frame_id = 255;
              towout_mfb->frame_id = (object->gen_period + 8) / 16;
              v4 = towout_mfb;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_918;
            case 0x52u:
              frame_id = 255;
              snicket_mfb->frame_id = 3 * object->frame;
              y = object->draw_y;
              x = object->draw_x;
              v4 = snicket_mfb;
              goto LABEL_918;
            case 0x53u:
              frame_id = 255;
              object->mfb_file->frame_id = object->state_id;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x54u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              v4 = worm_mfb;
              goto LABEL_918;
            case 0x55u:
              frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              v4 = turf_mfb;
              goto LABEL_918;
            case 0x56u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( !is_night )
                goto LABEL_919;
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              v4 = l_wiz01_mfb;
              goto LABEL_918;
            case 0x57u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x58u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x59u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x5Au:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x5Cu:
              switch ( object->field_F2 )
              {
                case 0u:
                  DrawTexture(bushman_mfb, object->draw_x, object->draw_y, 0, 1);
                  frame_id = 2;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = busheyes_mfb;
                  goto LABEL_918;
                case 0x2Cu:
                  DrawTexture(bushman_mfb, object->draw_x, object->draw_y, 0, 1);
                  frame_id = object->data8[2] >> 7;
                  y = object->draw_y;
                  v4 = busheyes_mfb;
                  x = object->draw_x;
                  goto LABEL_918;
                case 0x2Du:
                  frame_id = ((unsigned __int8)(object->frame & 4) >> 2) + 1;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = bushman_mfb;
                  goto LABEL_918;
                case 0x2Eu:
                  frame_id = ((unsigned __int8)(object->frame & 4) >> 2) + 3;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = bushman_mfb;
                  goto LABEL_918;
                case 0x2Fu:
                  frame_id = 2 - ((unsigned __int8)(object->frame & 4) >> 2);
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = bushman_mfb;
                  goto LABEL_918;
                case 0x30u:
                  DrawTexture(shaker_mfb, object->draw_x, object->draw_y, 0, 1);
                  switch ( object->sex )
                  {
                    case 1u:
                      frame_id = object->frame >> 2;
                      y = object->draw_y;
                      v4 = bushk_ml_mfb;
                      x = object->draw_x;
                      goto LABEL_918;
                    case 2u:
                      frame_id = object->frame >> 2;
                      y = object->draw_y;
                      v4 = bushk_fl_mfb;
                      x = object->draw_x;
                      goto LABEL_918;
                    case 3u:
                      frame_id = object->frame >> 2;
                      y = object->draw_y;
                      v4 = bushk_pr_mfb;
                      x = object->draw_x;
                      goto LABEL_918;
                    case 4u:
                      frame_id = object->frame >> 2;
                      y = object->draw_y;
                      v4 = bushk_rp_mfb;
                      x = object->draw_x;
                      goto LABEL_918;
                    default:
                      goto LABEL_919;
                  }
                  goto LABEL_919;
                case 0x31u:
                  frame_id = (object->data8[2] >> 2) % 3u;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = shaker_mfb;
                  goto LABEL_918;
                default:
                  goto LABEL_919;
              }
              goto LABEL_919;
            case 0x5Du:
              if ( object->field_F2 != 20 && object->owner_player != cur_player )
                goto LABEL_919;
              if ( object->mfb_file != flamedev_mfb )
                SetObjectMFBFile(object, flamedev_mfb);
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( object->field_F2 != 20 )
                goto LABEL_919;
              if ( object->mfb_file != flamepit_mfb )
                SetObjectMFBFile(object, flamepit_mfb);
              v16 = object->frame >> 1;
              goto LABEL_915;
            case 0x5Eu:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x5Fu:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x60u:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x62u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              frame_id = object->data8[2] >> 1;
              y = object->draw_y;
              v4 = flag_mfb;
              x = object->draw_x;
              goto LABEL_918;
            case 0x63u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x64u:
              frame_id = 255;
              object->mfb_file->frame_id = (object->gen_period + 8) / 16;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x66u:
              frame_id = 255;
              object->mfb_file->frame_id = (object->gen_period + 4) / 8;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x67u:
              switch ( object->field_F2 )
              {
                case 0u:
                  if ( is_night && object->owner_player == cur_player )
                    DrawTexture(lantern_mfb, object->draw_x, object->draw_y, 255, 1);
                  if ( object->data8[0] == 15 )
                    DrawTexture(flag_mfb, object->draw_x, object->draw_y, object->data8[2] >> 1, 1);
                  v27 = object->data8[0];
                  if ( v27 == 6 || v27 == 2 || v27 == 4 || v27 == 10 )
                  {
                    if ( object->sex == 1 )
                    {
                      if ( object->mfb_file != sackmale_mfb )
                        SetObjectMFBFile(object, sackmale_mfb);
                      v59 = object->gen_period + 16;
                      v160 = 255;
                      sackmale_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v59) & 0x1F) + (signed int)v59) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = sackmale_mfb;
                    }
                    else
                    {
                      if ( object->mfb_file != sackfema_mfb )
                        SetObjectMFBFile(object, sackfema_mfb);
                      v60 = object->gen_period + 16;
                      v160 = 255;
                      sackfema_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v60) & 0x1F) + (signed int)v60) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = sackfema_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( v27 == 8 )
                  {
                    if ( object->sex == 1 )
                    {
                      if ( object->mfb_file != m_barrel_mfb )
                        SetObjectMFBFile(object, m_barrel_mfb);
                      v28 = object->gen_period + 16;
                      v160 = 255;
                      m_barrel_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v28) & 0x1F) + (signed int)v28) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = m_barrel_mfb;
                    }
                    else
                    {
                      if ( object->mfb_file != barlfema_mfb )
                        SetObjectMFBFile(object, barlfema_mfb);
                      v30 = object->gen_period + 16;
                      v160 = 255;
                      barlfema_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v30) & 0x1F) + (signed int)v30) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = barlfema_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( v27 == 19 )
                  {
                    v31 = object->gen_period + 16;
                    v160 = 255;
                    f_milk_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v31) & 0x1F) + (signed int)v31) >> 5);
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = f_milk_mfb;
                    goto LABEL_616;
                  }
                  sex = object->sex;
                  if ( sex == 4 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != reparman_mfb )
                        SetObjectMFBFile(object, reparman_mfb);
                      v33 = object->gen_period + 16;
                      v160 = 255;
                      reparman_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v33) & 0x1F) + (signed int)v33) >> 5);
                      v29 = reparman_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != rp_still_mfb )
                        SetObjectMFBFile(object, rp_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = rp_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 5 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != taxman_mfb )
                        SetObjectMFBFile(object, taxman_mfb);
                      v34 = object->gen_period + 16;
                      v160 = 255;
                      taxman_mfb->frame_id = (object->state_id >> 1)
                                           + 6 * (((BYTE4(v34) & 0x1F) + (signed int)v34) >> 5);
                      v29 = taxman_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != tx_still_mfb )
                        SetObjectMFBFile(object, tx_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = tx_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 17 )
                  {
                    if ( object->mfb_file != bombman_mfb )
                      SetObjectMFBFile(object, bombman_mfb);
                    v35 = object->gen_period + 16;
                    v160 = 255;
                    bombman_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v35) & 0x1F) + (signed int)v35) >> 5);
                    v29 = bombman_mfb;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    goto LABEL_616;
                  }
                  if ( sex == 3 )
                  {
                    if ( object->is_fleeing )
                    {
                      if ( object->mfb_file != fleeprie_mfb )
                        SetObjectMFBFile(object, fleeprie_mfb);
                      v36 = object->gen_period + 16;
                      v160 = 255;
                      fleeprie_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v36) & 0x1F) + (signed int)v36) >> 5);
                      v29 = fleeprie_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else if ( object->is_going )
                    {
                      if ( object->mfb_file != priest_mfb )
                        SetObjectMFBFile(object, priest_mfb);
                      v37 = object->gen_period + 16;
                      v160 = 255;
                      priest_mfb->frame_id = (object->state_id >> 1)
                                           + 6 * (((BYTE4(v37) & 0x1F) + (signed int)v37) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = priest_mfb;
                    }
                    else
                    {
                      if ( object->mfb_file != pr_still_mfb )
                        SetObjectMFBFile(object, pr_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = pr_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 2 )
                  {
                    if ( object->is_fleeing )
                    {
                      if ( object->mfb_file != fleefema_mfb )
                        SetObjectMFBFile(object, fleefema_mfb);
                      v38 = object->gen_period + 16;
                      v160 = 255;
                      fleefema_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v38) & 0x1F) + (signed int)v38) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = fleefema_mfb;
                    }
                    else if ( object->is_going )
                    {
                      if ( object->mfb_file != woman_mfb )
                        SetObjectMFBFile(object, woman_mfb);
                      v39 = object->gen_period + 16;
                      v160 = 255;
                      woman_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v39) & 0x1F) + (signed int)v39) >> 5);
                      v29 = woman_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != f_still_mfb )
                        SetObjectMFBFile(object, f_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = f_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 1 )
                  {
                    if ( object->is_fleeing )
                    {
                      if ( object->mfb_file != fleemale_mfb )
                        SetObjectMFBFile(object, fleemale_mfb);
                      v40 = object->gen_period + 16;
                      v160 = 255;
                      fleemale_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v40) & 0x1F) + (signed int)v40) >> 5);
                      v29 = fleemale_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else if ( object->is_going )
                    {
                      if ( object->mfb_file != villager_mfb )
                        SetObjectMFBFile(object, villager_mfb);
                      v41 = object->gen_period + 16;
                      v160 = 255;
                      villager_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v41) & 0x1F) + (signed int)v41) >> 5);
                      v29 = villager_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != m_still_mfb )
                        SetObjectMFBFile(object, m_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = m_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 32 )
                  {
                    v42 = object->mfb_file;
                    if ( object->is_going )
                    {
                      if ( v42 != m_weddin_mfb )
                        SetObjectMFBFile(object, m_weddin_mfb);
                      v43 = object->gen_period + 16;
                      v160 = 255;
                      object->mfb_file->frame_id = (object->state_id >> 1)
                                                 + 6 * (((BYTE4(v43) & 0x1F) + (signed int)v43) >> 5);
                      v29 = object->mfb_file;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( v42 != m_weddin_mfb )
                        SetObjectMFBFile(object, m_weddin_mfb);
                      v160 = 255;
                      object->mfb_file->frame_id = 42;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 33 )
                  {
                    v44 = object->mfb_file;
                    if ( object->is_going )
                    {
                      if ( v44 != f_weddin_mfb )
                        SetObjectMFBFile(object, f_weddin_mfb);
                      v45 = object->gen_period + 16;
                      v160 = 255;
                      object->mfb_file->frame_id = (object->state_id >> 1)
                                                 + 6 * (((BYTE4(v45) & 0x1F) + (signed int)v45) >> 5);
                      v29 = object->mfb_file;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( v44 != f_weddin_mfb )
                        SetObjectMFBFile(object, f_weddin_mfb);
                      v160 = 255;
                      object->mfb_file->frame_id = 42;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 11 )
                  {
                    if ( object->mfb_file != elderm_mfb )
                      SetObjectMFBFile(object, elderm_mfb);
                    v46 = object->gen_period + 16;
                    v160 = 255;
                    elderm_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v46) & 0x1F) + (signed int)v46) >> 5);
                    v29 = elderm_mfb;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    goto LABEL_616;
                  }
                  if ( sex == 12 )
                  {
                    if ( object->mfb_file != elderf_mfb )
                      SetObjectMFBFile(object, elderf_mfb);
                    v47 = object->gen_period + 16;
                    v160 = 255;
                    elderf_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v47) & 0x1F) + (signed int)v47) >> 5);
                    v29 = elderf_mfb;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    goto LABEL_616;
                  }
                  if ( sex == 13 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != kidm_mfb )
                        SetObjectMFBFile(object, kidm_mfb);
                      v48 = object->gen_period + 16;
                      v160 = 255;
                      kidm_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v48) & 0x1F) + (signed int)v48) >> 5);
                      v29 = kidm_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != boystill_mfb )
                        SetObjectMFBFile(object, boystill_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = boystill_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 14 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != kidf_mfb )
                        SetObjectMFBFile(object, kidf_mfb);
                      v49 = object->gen_period + 16;
                      v160 = 255;
                      kidf_mfb->frame_id = (object->state_id >> 1) + 6 * (((BYTE4(v49) & 0x1F) + (signed int)v49) >> 5);
                      v29 = kidf_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != girlstil_mfb )
                        SetObjectMFBFile(object, girlstil_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = girlstil_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 7 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != footwalk_mfb )
                        SetObjectMFBFile(object, footwalk_mfb);
                      v50 = object->gen_period + 16;
                      v160 = 255;
                      footwalk_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v50) & 0x1F) + (signed int)v50) >> 5);
                      v29 = footwalk_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != ft_still_mfb )
                        SetObjectMFBFile(object, ft_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = ft_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 8 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != knigwalk_mfb )
                        SetObjectMFBFile(object, knigwalk_mfb);
                      v51 = object->gen_period + 16;
                      v160 = 255;
                      knigwalk_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v51) & 0x1F) + (signed int)v51) >> 5);
                      v29 = knigwalk_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != kn_still_mfb )
                        SetObjectMFBFile(object, kn_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = kn_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 19 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != archer_mfb )
                        SetObjectMFBFile(object, archer_mfb);
                      v52 = object->gen_period + 16;
                      v160 = 255;
                      archer_mfb->frame_id = (object->state_id >> 1)
                                           + 6 * (((BYTE4(v52) & 0x1F) + (signed int)v52) >> 5);
                      v29 = archer_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != arc_stil_mfb )
                        SetObjectMFBFile(object, arc_stil_mfb);
                      v160 = 255;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = arc_stil_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 20 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != minstrel_mfb )
                        SetObjectMFBFile(object, minstrel_mfb);
                      v53 = object->gen_period + 16;
                      v160 = 255;
                      minstrel_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v53) & 0x1F) + (signed int)v53) >> 5);
                      v29 = minstrel_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != minjuggl_mfb )
                        SetObjectMFBFile(object, minjuggl_mfb);
                      v160 = 255;
                      object->mfb_file->frame_id = object->data8[2] >> 2;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 21 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != monkwalk_mfb )
                        SetObjectMFBFile(object, monkwalk_mfb);
                      v54 = object->gen_period + 16;
                      v160 = 255;
                      object->mfb_file->frame_id = (object->state_id >> 1)
                                                 + 6 * (((BYTE4(v54) & 0x1F) + (signed int)v54) >> 5);
                      v29 = object->mfb_file;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != mk_stil_mfb )
                        SetObjectMFBFile(object, mk_stil_mfb);
                      v160 = 255;
                      object->mfb_file->frame_id = object->data8[2] >> 2;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 9 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != wizwalk_mfb )
                        SetObjectMFBFile(object, wizwalk_mfb);
                      v55 = object->gen_period + 16;
                      v160 = 255;
                      wizwalk_mfb->frame_id = (object->state_id >> 1)
                                            + 6 * (((BYTE4(v55) & 0x1F) + (signed int)v55) >> 5);
                      v29 = wizwalk_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != wz_still_mfb )
                        SetObjectMFBFile(object, wz_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = wz_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 6 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != pikewalk_mfb )
                        SetObjectMFBFile(object, pikewalk_mfb);
                      v56 = object->gen_period + 16;
                      v160 = 255;
                      pikewalk_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v56) & 0x1F) + (signed int)v56) >> 5);
                      v29 = pikewalk_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != pk_still_mfb )
                        SetObjectMFBFile(object, pk_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = pk_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 10 )
                  {
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != flagwalk_mfb )
                        SetObjectMFBFile(object, flagwalk_mfb);
                      v57 = object->gen_period + 16;
                      v160 = 255;
                      flagwalk_mfb->frame_id = (object->state_id >> 1)
                                             + 6 * (((BYTE4(v57) & 0x1F) + (signed int)v57) >> 5);
                      v29 = flagwalk_mfb;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                    }
                    else
                    {
                      if ( object->mfb_file != fg_still_mfb )
                        SetObjectMFBFile(object, fg_still_mfb);
                      v160 = object->state_id;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = fg_still_mfb;
                    }
                    goto LABEL_616;
                  }
                  if ( sex == 16 )
                  {
                    if ( object->mfb_file != cavalier_mfb )
                      SetObjectMFBFile(object, cavalier_mfb);
                    v58 = object->gen_period + 16;
                    v160 = 255;
                    object->mfb_file->frame_id = (object->state_id / 3u & 3)
                                               + 4 * (((BYTE4(v58) & 0x1F) + (signed int)v58) >> 5);
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = object->mfb_file;
                    goto LABEL_616;
                  }
                  goto LABEL_617;
                case 3u:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != cowchopm_mfb )
                      SetObjectMFBFile(object, cowchopm_mfb);
                    v160 = 255;
                    cowchopm_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = cowchopm_mfb;
                  }
                  else
                  {
                    if ( object->mfb_file != cowchopf_mfb )
                      SetObjectMFBFile(object, cowchopf_mfb);
                    v160 = 255;
                    cowchopf_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = cowchopf_mfb;
                  }
                  goto LABEL_616;
                case 4u:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != m_chkill_mfb )
                      SetObjectMFBFile(object, m_chkill_mfb);
                    v160 = 255;
                    m_chkill_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = m_chkill_mfb;
                  }
                  else
                  {
                    if ( object->mfb_file != f_chkill_mfb )
                      SetObjectMFBFile(object, f_chkill_mfb);
                    v160 = 255;
                    f_chkill_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = f_chkill_mfb;
                  }
                  goto LABEL_616;
                case 5u:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != m_shaker_mfb )
                      SetObjectMFBFile(object, m_shaker_mfb);
                    v160 = 255;
                    m_shaker_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = m_shaker_mfb;
                  }
                  else
                  {
                    if ( object->mfb_file != f_shaker_mfb )
                      SetObjectMFBFile(object, f_shaker_mfb);
                    v160 = 255;
                    f_shaker_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = f_shaker_mfb;
                  }
                  goto LABEL_616;
                case 6u:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != mharvest_mfb )
                      SetObjectMFBFile(object, mharvest_mfb);
                    v160 = 255;
                    mharvest_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = mharvest_mfb;
                  }
                  else
                  {
                    if ( object->mfb_file != fharvest_mfb )
                      SetObjectMFBFile(object, fharvest_mfb);
                    v160 = 255;
                    fharvest_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = fharvest_mfb;
                  }
                  goto LABEL_616;
                case 7u:
                  switch ( object->sex )
                  {
                    default:
                      v160 = 255;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                      break;
                    case 1u:
                      if ( object->mfb_file != mthrow_mfb )
                        SetObjectMFBFile(object, mthrow_mfb);
                      v61 = object->gen_period + 16;
                      v160 = 255;
                      object->mfb_file->frame_id = object->frame + 5 * (((BYTE4(v61) & 0x1F) + (signed int)v61) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                      break;
                    case 2u:
                      if ( object->mfb_file != fthrow_mfb )
                        SetObjectMFBFile(object, fthrow_mfb);
                      v62 = object->gen_period + 16;
                      v160 = 255;
                      object->mfb_file->frame_id = object->frame + 5 * (((BYTE4(v62) & 0x1F) + (signed int)v62) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = object->mfb_file;
                      break;
                    case 6u:
                      if ( object->mfb_file != pikeatta_mfb )
                        SetObjectMFBFile(object, pikeatta_mfb);
                      v160 = 255;
                      pikeatta_mfb->frame_id = (object->state_id >> 2) + 6 * (object->gen_period >> 6);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = pikeatta_mfb;
                      break;
                    case 7u:
                      if ( object->mfb_file != footatta_mfb )
                        SetObjectMFBFile(object, footatta_mfb);
                      v63 = object->gen_period + 16;
                      v160 = 255;
                      footatta_mfb->frame_id = object->frame + 6 * (((BYTE4(v63) & 0x1F) + (signed int)v63) >> 5);
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = footatta_mfb;
                      break;
                    case 8u:
                      if ( object->frame >= 7u )
                      {
                        if ( object->mfb_file != knigwalk_mfb )
                          SetObjectMFBFile(object, knigwalk_mfb);
                        v65 = object->gen_period + 16;
                        v160 = 255;
                        object->mfb_file->frame_id = 6 * (((BYTE4(v65) & 0x1F) + (signed int)v65) >> 5);
                        v29 = object->mfb_file;
                        v151 = object->draw_y;
                        v141 = object->draw_x;
                      }
                      else
                      {
                        if ( object->mfb_file != knigatta_mfb )
                          SetObjectMFBFile(object, knigatta_mfb);
                        v64 = object->gen_period + 16;
                        v160 = 255;
                        object->mfb_file->frame_id = object->frame + 7 * (((BYTE4(v64) & 0x1F) + (signed int)v64) >> 5);
                        v151 = object->draw_y;
                        v141 = object->draw_x;
                        v29 = object->mfb_file;
                      }
                      break;
                    case 9u:
                      if ( object->mfb_file != wizaim_mfb )
                        SetObjectMFBFile(object, wizaim_mfb);
                      v160 = 255;
                      object->mfb_file->frame_id = (object->gen_period + 16) / 32;
                      v29 = object->mfb_file;
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      break;
                    case 0x10u:
                      if ( object->frame >= 5u )
                      {
                        if ( object->mfb_file != cavalier_mfb )
                          SetObjectMFBFile(object, cavalier_mfb);
                        v160 = 255;
                        object->mfb_file->frame_id = 4 * ((object->gen_period + 16) / 32);
                        v29 = object->mfb_file;
                        v151 = object->draw_y;
                        v141 = object->draw_x;
                      }
                      else
                      {
                        if ( object->mfb_file != cavatta_mfb )
                          SetObjectMFBFile(object, cavatta_mfb);
                        v66 = object->gen_period + 16;
                        v160 = 255;
                        object->mfb_file->frame_id = object->frame + 5 * (((BYTE4(v66) & 0x1F) + (signed int)v66) >> 5);
                        v151 = object->draw_y;
                        v141 = object->draw_x;
                        v29 = object->mfb_file;
                      }
                      break;
                    case 0x13u:
                      if ( object->mfb_file != archshoo_mfb )
                        SetObjectMFBFile(object, archshoo_mfb);
                      v67 = object->gen_period + 16;
                      v68 = ((BYTE4(v67) & 0x1F) + (signed int)v67) >> 5;
                      v160 = 255;
                      archshoo_mfb->frame_id = object->frame
                                             + 4
                                             * ((HIDWORD(v68) ^ ((BYTE4(v68) ^ (unsigned __int8)v68) - BYTE4(v68)) & 7)
                                              - HIDWORD(v68));
                      v151 = object->draw_y;
                      v141 = object->draw_x;
                      v29 = archshoo_mfb;
                      break;
                  }
                  goto LABEL_616;
                case 9u:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != vpick_mfb )
                      SetObjectMFBFile(object, vpick_mfb);
                    v160 = 255;
                    object->mfb_file->frame_id = object->frame >> 2;
                    v151 = object->draw_y - 20;
                    v141 = object->draw_x;
                    v29 = object->mfb_file;
                  }
                  else
                  {
                    if ( object->mfb_file != pick_mfb )
                      SetObjectMFBFile(object, pick_mfb);
                    v160 = 255;
                    object->mfb_file->frame_id = (object->frame >> 2) + 1;
                    v151 = object->draw_y - 20;
                    v141 = object->draw_x;
                    v29 = object->mfb_file;
                  }
                  goto LABEL_616;
                case 0xAu:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != vsaw_mfb )
                      SetObjectMFBFile(object, vsaw_mfb);
                    v160 = 255;
                    object->mfb_file->frame_id = object->frame >> 2;
                    v151 = object->draw_y - 20;
                    v141 = object->draw_x;
                    v29 = object->mfb_file;
                  }
                  else
                  {
                    if ( object->mfb_file != saw_mfb )
                      SetObjectMFBFile(object, saw_mfb);
                    v160 = 255;
                    object->mfb_file->frame_id = (object->frame >> 2) + 1;
                    v151 = object->draw_y - 20;
                    v141 = object->draw_x;
                    v29 = object->mfb_file;
                  }
                  goto LABEL_616;
                case 0xBu:
                  if ( object->sex == 4 )
                  {
                    if ( object->mfb_file != hammer_mfb )
                      SetObjectMFBFile(object, hammer_mfb);
                    v160 = 255;
                    hammer_mfb->frame_id = (object->frame >> 2) + ((object->gen_period >> 4) & 0xFC);
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = hammer_mfb;
                  }
                  else
                  {
                    if ( object->mfb_file != manham_mfb )
                      SetObjectMFBFile(object, manham_mfb);
                    v160 = 255;
                    manham_mfb->frame_id = (object->frame >> 2) + ((object->gen_period >> 4) & 0xFC);
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = manham_mfb;
                  }
                  goto LABEL_616;
                case 0xCu:
                  if ( object->sex == 1 )
                  {
                    if ( object->mfb_file != m_chop_mfb )
                      SetObjectMFBFile(object, m_chop_mfb);
                    v160 = 255;
                    m_chop_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = m_chop_mfb;
                  }
                  else
                  {
                    if ( object->mfb_file != f_chop_mfb )
                      SetObjectMFBFile(object, f_chop_mfb);
                    v160 = 255;
                    f_chop_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = f_chop_mfb;
                  }
                  goto LABEL_616;
                case 0xDu:
                  if ( object->mfb_file != pri_heal_mfb )
                    SetObjectMFBFile(object, pri_heal_mfb);
                  pri_heal_mfb->frame_id = object->frame >> 2;
                  DrawTexture(pri_heal_mfb, object->draw_x, object->draw_y, 255, 1);
                  v160 = 255;
                  healovr_mfb->frame_id = pri_heal_mfb->frame_id;
                  v151 = object->draw_y;
                  v141 = object->draw_x;
                  v29 = healovr_mfb;
                  goto LABEL_616;
                case 0xEu:
                  v69 = object->sex;
                  if ( v69 == 3 )
                  {
                    if ( object->mfb_file != pri_heal_mfb )
                      SetObjectMFBFile(object, pri_heal_mfb);
                    pri_heal_mfb->frame_id = object->frame >> 2;
                    DrawTexture(pri_heal_mfb, object->draw_x, object->draw_y, 255, 1);
                    v160 = 255;
                    healovr_mfb->frame_id = pri_heal_mfb->frame_id;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = healovr_mfb;
                  }
                  else
                  {
                    if ( v69 != 9 )
                      goto LABEL_617;
                    if ( object->mfb_file != wizcast_mfb )
                      SetObjectMFBFile(object, wizcast_mfb);
                    v160 = 255;
                    wizcast_mfb->frame_id = object->frame >> 2;
                    v151 = object->draw_y;
                    v141 = object->draw_x;
                    v29 = wizcast_mfb;
                  }
LABEL_616:
                  DrawTexture(v29, v141, v151, v160, 1);
LABEL_617:
                  if ( object->disease )
                  {
                    buzz_mfb->frame_id = object->data8[2] % 0x12u / 3;
                    DrawTexture(buzz_mfb, object->draw_x, object->draw_y, 255, 1);
                  }
                  if ( !(object->unk32 & 0x80000) )
                    goto LABEL_919;
                  frame_id = 255;
                  aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
                  y = object->draw_y;
                  x = object->draw_x;
                  v4 = aargh_mfb;
                  break;
                case 0x10u:
                  if ( object->mfb_file != dword_6033CC )
                    SetObjectMFBFile(object, dword_6033CC);
                  switch ( object->sex )
                  {
                    default:
                      v70 = (object->gen_period >> 7) + 6;
                      break;
                    case 1u:
                      v70 = (object->gen_period >> 7) + 6;
                      break;
                    case 2u:
                      v70 = (object->gen_period >> 7) + 8;
                      break;
                    case 4u:
                      v70 = object->gen_period >> 7;
                      break;
                    case 5u:
                      v70 = (object->gen_period >> 7) + 2;
                      break;
                  }
                  v160 = 255;
                  object->mfb_file->frame_id = v70;
                  v151 = object->draw_y;
                  v141 = object->draw_x;
                  v29 = object->mfb_file;
                  goto LABEL_616;
                case 0x5Du:
                  if ( object->mfb_file != milking_mfb )
                    SetObjectMFBFile(object, milking_mfb);
                  v160 = 255;
                  milking_mfb->frame_id = object->frame >> 2;
                  v151 = object->draw_y;
                  v141 = object->draw_x;
                  v29 = milking_mfb;
                  goto LABEL_616;
                default:
                  goto LABEL_617;
              }
              goto LABEL_918;
            case 0x68u:
              if ( object->field_F2 )
              {
                if ( object->field_F2 != 7 )
                  goto LABEL_758;
                switch ( object->sex )
                {
                  case 0xFu:
                    if ( object->mfb_file != catfire_mfb )
                      SetObjectMFBFile(object, catfire_mfb);
                    v87 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->frame + 2 * (((BYTE4(v87) & 0x1F) + (signed int)v87) >> 5);
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    goto LABEL_756;
                  case 0x12u:
                    if ( object->mfb_file != zombatta_mfb )
                      SetObjectMFBFile(object, zombatta_mfb);
                    v88 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->frame + 4 * (((BYTE4(v88) & 0x1F) + (signed int)v88) >> 5);
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    goto LABEL_756;
                  case 0x16u:
                    if ( object->mfb_file != crossbow_mfb )
                      SetObjectMFBFile(object, crossbow_mfb);
                    v89 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->frame + 2 * (((BYTE4(v89) & 0x1F) + (signed int)v89) >> 5);
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    goto LABEL_756;
                  case 0x17u:
                    if ( object->frame )
                    {
                      if ( object->mfb_file != wolfatta_mfb )
                        SetObjectMFBFile(object, wolfatta_mfb);
                      v90 = object->gen_period + 16;
                      v91 = ((BYTE4(v90) & 0x1F) + (signed int)v90) >> 5;
                    }
                    else
                    {
                      if ( object->mfb_file != wolf_mfb )
                        SetObjectMFBFile(object, wolf_mfb);
                      v92 = object->gen_period + 16;
                      v91 = 4 * (((BYTE4(v92) & 0x1F) + (signed int)v92) >> 5);
                    }
                    object->mfb_file->frame_id = v91;
                    goto LABEL_754;
                  case 0x18u:
                    if ( object->state_id < 0xCu )
                    {
                      if ( object->mfb_file != waspat_mfb )
                        SetObjectMFBFile(object, waspat_mfb);
                      v93 = object->gen_period + 16;
                      v161 = 255;
                      object->mfb_file->frame_id = object->frame + 6 * (((BYTE4(v93) & 0x1F) + (signed int)v93) >> 5);
                      v152 = object->draw_y;
                      v142 = object->draw_x;
                      goto LABEL_756;
                    }
                    if ( object->mfb_file != wasp_mfb )
                      SetObjectMFBFile(object, wasp_mfb);
                    v94 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v94) & 0x1F) + (signed int)v94) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x19u:
                    if ( object->frame == 1 )
                    {
                      if ( object->mfb_file != bat_mfb )
                        SetObjectMFBFile(object, bat_mfb);
                      v161 = 255;
                      object->mfb_file->frame_id = (object->gen_period + 16) / 32;
                      v152 = object->draw_y;
                      v142 = object->draw_x;
                      goto LABEL_756;
                    }
                    if ( object->mfb_file != bat_mfb )
                      SetObjectMFBFile(object, bat_mfb);
                    v95 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v95) & 0x1F) + (signed int)v95) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x1Au:
                    if ( object->mfb_file != fiend_mfb )
                      SetObjectMFBFile(object, fiend_mfb);
                    v96 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = (object->data8[2] >> 1) % 6u
                                               + 6 * (((BYTE4(v96) & 0x1F) + (signed int)v96) >> 5);
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    goto LABEL_756;
                  case 0x1Bu:
                    if ( object->frame < 4u )
                    {
                      if ( object->mfb_file != gianatt_mfb )
                        SetObjectMFBFile(object, gianatt_mfb);
                      v97 = object->gen_period + 16;
                      v161 = 255;
                      object->mfb_file->frame_id = object->frame + 4 * (((BYTE4(v97) & 0x1F) + (signed int)v97) >> 5);
                      v152 = object->draw_y;
                      v142 = object->draw_x;
                      goto LABEL_756;
                    }
                    if ( object->mfb_file != giant_mfb )
                      SetObjectMFBFile(object, giant_mfb);
                    v98 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v98) & 0x1F) + (signed int)v98) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x1Cu:
                    if ( object->state_id < 0xCu )
                    {
                      if ( object->mfb_file != bldsting_mfb )
                        SetObjectMFBFile(object, bldsting_mfb);
                      v99 = object->gen_period + 16;
                      v161 = 255;
                      object->mfb_file->frame_id = object->frame + 6 * (((BYTE4(v99) & 0x1F) + (signed int)v99) >> 5);
                      v152 = object->draw_y;
                      v142 = object->draw_x;
                      goto LABEL_756;
                    }
                    if ( object->mfb_file != bloodwsp_mfb )
                      SetObjectMFBFile(object, bloodwsp_mfb);
                    v100 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v100) & 0x1F) + (signed int)v100) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x1Du:
                    if ( object->frame )
                    {
                      if ( object->mfb_file != dw_attak_mfb )
                        SetObjectMFBFile(object, dw_attak_mfb);
                      v101 = object->gen_period + 16;
                      v102 = ((BYTE4(v101) & 0x1F) + (signed int)v101) >> 5;
                    }
                    else
                    {
                      if ( object->mfb_file != dw_walk_mfb )
                        SetObjectMFBFile(object, dw_walk_mfb);
                      v103 = object->gen_period + 16;
                      v102 = 4 * (((BYTE4(v103) & 0x1F) + (signed int)v103) >> 5);
                    }
                    object->mfb_file->frame_id = v102;
                    goto LABEL_754;
                  case 0x1Eu:
                    if ( object->frame >= 7u )
                    {
                      if ( object->mfb_file != ogrewalk_mfb )
                        SetObjectMFBFile(object, ogrewalk_mfb);
                      v105 = object->gen_period + 16;
                      object->mfb_file->frame_id = 6 * (((BYTE4(v105) & 0x1F) + (signed int)v105) >> 5);
                    }
                    else
                    {
                      if ( object->mfb_file != ogreatta_mfb )
                        SetObjectMFBFile(object, ogreatta_mfb);
                      v104 = object->gen_period + 16;
                      object->mfb_file->frame_id = object->frame + 7 * (((BYTE4(v104) & 0x1F) + (signed int)v104) >> 5);
                    }
                    goto LABEL_754;
                  case 0x1Fu:
                    v106 = object->frame;
                    if ( v106 < 1u || v106 > 7u )
                    {
                      if ( object->mfb_file != vampstil_mfb )
                        SetObjectMFBFile(object, vampstil_mfb);
                      object->mfb_file->frame_id = 0;
                    }
                    else
                    {
                      if ( object->mfb_file != vampbat_mfb )
                        SetObjectMFBFile(object, vampbat_mfb);
                      object->mfb_file->frame_id = object->frame - 1;
                    }
                    goto LABEL_754;
                  default:
                    goto LABEL_758;
                }
              }
              else
              {
                switch ( object->sex )
                {
                  case 0xFu:
                    if ( object->mfb_file != catapult_mfb )
                      SetObjectMFBFile(object, catapult_mfb);
                    v71 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                                               + 4 * (((BYTE4(v71) & 0x1F) + (signed int)v71) >> 5);
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    goto LABEL_756;
                  case 0x12u:
                    if ( object->mfb_file != zombie_mfb )
                      SetObjectMFBFile(object, zombie_mfb);
                    v72 = object->gen_period + 16;
                    object->mfb_file->frame_id = (object->state_id >> 2) % 6u
                                               + 6 * (((BYTE4(v72) & 0x1F) + (signed int)v72) >> 5);
                    DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    if ( !is_night )
                      goto LABEL_758;
                    v73 = object->gen_period + 16;
                    v161 = ((BYTE4(v73) & 0x1F) + (signed int)v73) >> 5;
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    v74 = zombglow_mfb;
                    goto LABEL_757;
                  case 0x16u:
                    if ( object->mfb_file != crossbow_mfb )
                      SetObjectMFBFile(object, crossbow_mfb);
                    v75 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                                               + 4 * (((BYTE4(v75) & 0x1F) + (signed int)v75) >> 5);
                    v152 = object->draw_y;
                    v142 = object->draw_x;
                    goto LABEL_756;
                  case 0x17u:
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != wolf_mfb )
                        SetObjectMFBFile(object, wolf_mfb);
                      v76 = object->gen_period + 16;
                      object->mfb_file->frame_id = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                                                 + 4 * (((BYTE4(v76) & 0x1F) + (signed int)v76) >> 5);
                    }
                    else
                    {
                      if ( object->mfb_file != wolfstil_mfb )
                        SetObjectMFBFile(object, wolfstil_mfb);
                      v77 = object->gen_period + 16;
                      object->mfb_file->frame_id = ((BYTE4(v77) & 0x1F) + (signed int)v77) >> 5;
                    }
                    goto LABEL_754;
                  case 0x18u:
                    if ( object->mfb_file != wasp_mfb )
                      SetObjectMFBFile(object, wasp_mfb);
                    v78 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v78) & 0x1F) + (signed int)v78) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x19u:
                    if ( object->mfb_file != bat_mfb )
                      SetObjectMFBFile(object, bat_mfb);
                    v79 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v79) & 0x1F) + (signed int)v79) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x1Au:
                    if ( object->mfb_file != fiend_mfb )
                      SetObjectMFBFile(object, fiend_mfb);
                    if ( object->unk30 || object->unk31 )
                    {
                      v80 = object->gen_period + 16;
                      object->mfb_file->frame_id = (object->data8[2] >> 1) % 6u
                                                 + 6 * (((BYTE4(v80) & 0x1F) + (signed int)v80) >> 5);
                    }
                    else if ( object->unk32 & 0x10000 )
                    {
                      object->mfb_file->frame_id = 54;
                    }
                    else
                    {
                      object->mfb_file->frame_id = (object->data8[2] >> 1) % 6u + 48;
                    }
                    goto LABEL_754;
                  case 0x1Bu:
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != giant_mfb )
                        SetObjectMFBFile(object, giant_mfb);
                      v81 = object->gen_period + 16;
                      v161 = 255;
                      object->mfb_file->frame_id = (object->state_id >> 1) % 6u
                                                 + 6 * (((BYTE4(v81) & 0x1F) + (signed int)v81) >> 5);
                      v152 = object->draw_y;
                      v142 = object->draw_x;
                      goto LABEL_756;
                    }
                    if ( object->mfb_file != gianstil_mfb )
                      SetObjectMFBFile(object, gianstil_mfb);
                    goto LABEL_754;
                  case 0x1Cu:
                    if ( object->mfb_file != bloodwsp_mfb )
                      SetObjectMFBFile(object, bloodwsp_mfb);
                    v82 = object->gen_period + 16;
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id % 6u
                                               + 6 * (((BYTE4(v82) & 0x1F) + (signed int)v82) >> 5);
                    v152 = object->draw_y;
                    break;
                  case 0x1Du:
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != dw_walk_mfb )
                        SetObjectMFBFile(object, dw_walk_mfb);
                      v83 = object->gen_period + 16;
                      v84 = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                          + 4 * (((BYTE4(v83) & 0x1F) + (signed int)v83) >> 5);
                    }
                    else
                    {
                      if ( object->mfb_file != dw_still_mfb )
                        SetObjectMFBFile(object, dw_still_mfb);
                      v85 = object->gen_period + 16;
                      v84 = ((BYTE4(v85) & 0x1F) + (signed int)v85) >> 5;
                    }
                    object->mfb_file->frame_id = v84;
                    goto LABEL_754;
                  case 0x1Eu:
                    if ( object->is_going )
                    {
                      if ( object->mfb_file != ogrewalk_mfb )
                        SetObjectMFBFile(object, ogrewalk_mfb);
                      v86 = object->gen_period + 16;
                      v161 = 255;
                      object->mfb_file->frame_id = object->state_id % 6u
                                                 + 6 * (((BYTE4(v86) & 0x1F) + (signed int)v86) >> 5);
                      v152 = object->draw_y;
                    }
                    else
                    {
                      if ( object->mfb_file != ogrestil_mfb )
                        SetObjectMFBFile(object, ogrestil_mfb);
LABEL_754:
                      v161 = 255;
                      v152 = object->draw_y;
                    }
                    break;
                  case 0x1Fu:
                    if ( object->mfb_file != vampstil_mfb )
                      SetObjectMFBFile(object, vampstil_mfb);
                    v161 = 255;
                    object->mfb_file->frame_id = object->state_id;
                    v152 = object->draw_y;
                    break;
                  default:
                    goto LABEL_758;
                }
              }
              v142 = object->draw_x;
LABEL_756:
              v74 = object->mfb_file;
LABEL_757:
              DrawTexture(v74, v142, v152, v161, 1);
LABEL_758:
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              frame_id = 255;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              y = object->draw_y;
              x = object->draw_x;
              v4 = aargh_mfb;
              goto LABEL_918;
            case 0x6Au:
              object->mfb_file->frame_id = (object->gen_period + 4) / 8;
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
              frame_id = 255;
              *(_DWORD *)(unk_6A9948 + 80) = (object->unk82 + 4) / 8;
              v4 = (MFBEntry *)unk_6A9948;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_918;
            case 0x6Eu:
              if ( object->field_F2 == 94 )
                goto LABEL_768;
              v107 = object->mfb_file;
              if ( object->is_going )
              {
                if ( v107 == cowwalk_mfb )
                  goto LABEL_767;
              }
              else if ( v107 == cowwalk_mfb )
              {
                goto LABEL_767;
              }
              SetObjectMFBFile(object, cowwalk_mfb);
LABEL_767:
              v108 = object->gen_period + 16;
              object->mfb_file->frame_id = (object->state_id >> 1)
                                         + 7 * (((BYTE4(v108) & 0x1F) + (signed int)v108) >> 5);
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
LABEL_768:
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              frame_id = 255;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              y = object->draw_y;
              x = object->draw_x;
              v4 = aargh_mfb;
              goto LABEL_918;
            case 0x6Fu:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
              chicken_mfb->frame_id = object->state_id + ((object->gen_period >> 5) & 0xFE);
              DrawTexture(chicken_mfb, object->draw_x, object->draw_y + 20, 255, 1);
              if ( object->field_F2 == 92 )
                DrawTexture(chickegg_mfb, object->draw_x + 12, object->draw_y + 20, 0, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              frame_id = 255;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              y = object->draw_y + 20;
              x = object->draw_x;
              v4 = aargh_mfb;
              goto LABEL_918;
            case 0x71u:
            case 0x75u:
            case 0x76u:
            case 0x77u:
            case 0x7Bu:
            case 0x7Cu:
            case 0x7Eu:
            case 0x7Fu:
            case 0x92u:
            case 0x97u:
            case 0x99u:
            case 0x9Bu:
            case 0x9Eu:
            case 0xAFu:
            case 0xD0u:
            case 0xE1u:
              if ( object->field_F2 != 67 )
                goto LABEL_919;
              frame_id = 1;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x72u:
              v109 = object->field_F2;
              if ( !v109 )
              {
                frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
                goto LABEL_917;
              }
              if ( v109 != 61 )
                goto LABEL_919;
              frame_id = 5;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x73u:
              v110 = object->field_F2;
              if ( !v110 )
              {
                frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
                goto LABEL_917;
              }
              if ( v110 != 63 )
                goto LABEL_919;
              frame_id = 5;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x81u:
              if ( current_season == 3 )
              {
                v111 = snwfence_mfb;
                if ( object->mfb_file == snwfence_mfb )
                  goto LABEL_789;
              }
              else
              {
                v111 = fence_mfb;
                if ( object->mfb_file == fence_mfb )
                  goto LABEL_789;
              }
              SetObjectMFBFile(object, v111);
LABEL_789:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x83u:
              frame_id = 1;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x84u:
              frame_id = object->frame >> 2;
              y = object->draw_y;
              goto LABEL_916;
            case 0x86u:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x87u:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x88u:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x8Au:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x8Du:
              if ( object->field_F2 != 75 )
                goto LABEL_919;
              if ( object->mfb_file != s_summon_mfb )
                SetObjectMFBFile(object, s_summon_mfb);
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x8Eu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0x91u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( is_night )
              {
                v153 = object->draw_y;
                v143 = object->draw_x;
                v112 = l_arch01_mfb;
              }
              else
              {
                if ( !(object->unk32 & 0x20000) )
                  goto LABEL_806;
                v153 = object->draw_y;
                v143 = object->draw_x;
                v112 = archdoor_mfb;
              }
              DrawTexture(v112, v143, v153, 255, 1);
LABEL_806:
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 25, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x + 10;
              goto LABEL_918;
            case 0x93u:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0x94u:
              v16 = object->frame >> 1;
              goto LABEL_915;
            case 0x95u:
              v16 = object->frame >> 1;
              goto LABEL_915;
            case 0x96u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0x98u:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( object->unk32 & 0x20000 )
                DrawTexture(keepdoor_mfb, object->draw_x, object->draw_y, 255, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0x9Au:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( object->unk32 & 0x20000 )
                DrawTexture(jaildoor_mfb, object->draw_x, object->draw_y, 255, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 10, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 35, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              x = object->draw_x;
              v4 = aargh_mfb;
              goto LABEL_918;
            case 0x9Cu:
              v113 = object->gen_period + 16;
              frame_id = ((BYTE4(v113) & 0x1F) + (signed int)v113) >> 5;
              y = object->draw_y;
              goto LABEL_916;
            case 0x9Du:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( object->unk32 & 0x20000 )
                DrawTexture(stabdoor_mfb, object->draw_x, object->draw_y, 255, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0x9Fu:
            case 0xA0u:
            case 0xACu:
            case 0xAEu:
            case 0xB1u:
            case 0xB2u:
            case 0xC0u:
            case 0xC1u:
            case 0xC6u:
            case 0xC8u:
            case 0xD3u:
            case 0xD4u:
              v21 = object->data8[2];
              goto LABEL_914;
            case 0xA1u:
              v21 = object->data8[2];
              goto LABEL_914;
            case 0xA2u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xA3u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xA4u:
              v16 = object->frame >> 1;
              goto LABEL_915;
            case 0xA9u:
              frame_id = 255;
              object->mfb_file->frame_id = object->state_id + 3 * object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xABu:
              if ( byte_4843E8 != 1 )
                goto LABEL_919;
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xADu:
              v16 = object->data8[2] >> 1;
              goto LABEL_915;
            case 0xB0u:
              v114 = object->state_id;
              if ( v114 > 6u )
              {
                if ( v114 < 0x10u || v114 > 0x16u )
                {
                  v115 = (char *)&object->frame;
                  object->frame = 32;
                }
                else
                {
                  v115 = (char *)&object->frame;
                  object->frame = v114 - 9;
                }
              }
              else
              {
                object->frame = v114;
                v115 = (char *)&object->frame;
              }
              frame_id = 255;
              if ( (unsigned __int8)*v115 >= 0x20u )
              {
                y = object->draw_y;
                x = object->draw_x;
                v4 = crate_mfb;
                goto LABEL_918;
              }
              DrawTexture(shadow_mfb, object->draw_x, object->draw_y + 6, 255, 1);
              v116 = (unsigned __int8)(object->data8[2] & 0x1C) >> 2;
              object->gen_period = v116;
              if ( !v116 )
              {
                frame_id = (unsigned __int8)*v115;
                y = object->draw_y - 5;
                x = object->draw_x;
                goto LABEL_917;
              }
              if ( v116 == 1 || v116 == 7 )
              {
                frame_id = (unsigned __int8)*v115;
                y = object->draw_y - 3;
                x = object->draw_x;
              }
              else
              {
                if ( v116 == 2 || v116 == 6 )
                {
                  frame_id = (unsigned __int8)*v115;
                  y = object->draw_y;
                  goto LABEL_916;
                }
                if ( v116 == 3 || v116 == 5 )
                {
                  frame_id = (unsigned __int8)*v115;
                  y = object->draw_y + 3;
                  x = object->draw_x;
                }
                else
                {
                  if ( v116 != 4 )
                    goto LABEL_919;
                  frame_id = (unsigned __int8)*v115;
                  y = object->draw_y + 5;
                  x = object->draw_x;
                }
              }
              goto LABEL_917;
            case 0xB3u:
              if ( current_season == 3 )
              {
                frame_id = 1;
                y = object->draw_y;
                x = object->draw_x;
              }
              else
              {
                frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
              }
              goto LABEL_917;
            case 0xBEu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xBFu:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xC2u:
              if ( object->state_id == 36 )
              {
                v117 = d_spike_mfb;
                if ( object->mfb_file == d_spike_mfb )
                  goto LABEL_866;
              }
              else
              {
                v117 = d_flame_mfb;
                if ( object->mfb_file == d_flame_mfb )
                  goto LABEL_866;
              }
              SetObjectMFBFile(object, v117);
LABEL_866:
              v21 = object->data8[2];
LABEL_914:
              v16 = v21 >> 2;
LABEL_915:
              frame_id = v16;
              y = object->draw_y;
              goto LABEL_916;
            case 0xC4u:
              v118 = object->gen_period + 16;
              v119 = (HIDWORD(v118) ^ (unsigned __int8)((BYTE4(v118) ^ v118) - BYTE4(v118))) - HIDWORD(v118);
              frame_id = ((unsigned __int8)(object->data8[2] & 0xC) >> 2)
                       + 4 * (((BYTE4(v119) & 0x1F) + (signed int)v119) >> 5);
              y = object->draw_y;
              goto LABEL_916;
            case 0xC5u:
              if ( !object->state_id )
              {
                v120 = shadow_mfb;
                if ( object->mfb_file == shadow_mfb )
                  goto LABEL_875;
                goto LABEL_874;
              }
              if ( object->state_id == 1 )
              {
                v120 = rockshad_mfb;
                if ( object->mfb_file != rockshad_mfb )
                {
LABEL_874:
                  SetObjectMFBFile(object, v120);
                  goto LABEL_875;
                }
              }
LABEL_875:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
LABEL_917:
              v4 = object->mfb_file;
LABEL_918:
              DrawTexture(v4, x, y, frame_id, 1);
LABEL_919:
              if ( object->unk32 & 0x2000000 )
                byte_4842C0 = 0;
              if ( object->is_speaking )
                DrawTexture(speech_mfb, object->draw_x, object->draw_y, 255, 1);
              if ( object->unk235235 )
              {
                if ( object->unk32 & 0x40000000 )
                {
                  artminis_mfb->frame_id = 12;
                }
                else
                {
                  v128 = object->data7[1];
                  if ( v128 == 1 )
                  {
                    artminis_mfb->frame_id = 13;
                  }
                  else if ( v128 == 2 )
                  {
                    artminis_mfb->frame_id = 11;
                  }
                }
              }
              else
              {
                v129 = object->data9[5];
                if ( !v129 )
                  goto LABEL_945;
                switch ( v129 )
                {
                  case 0x9Fu:
                    artminis_mfb->frame_id = 6;
                    break;
                  case 0xACu:
                    artminis_mfb->frame_id = 5;
                    break;
                  case 0xAEu:
                    artminis_mfb->frame_id = 9;
                    break;
                  case 0xB1u:
                    artminis_mfb->frame_id = 7;
                    break;
                  case 0xB2u:
                    artminis_mfb->frame_id = 3;
                    break;
                  case 0xC0u:
                    artminis_mfb->frame_id = 0;
                    break;
                  case 0xC1u:
                    artminis_mfb->frame_id = 1;
                    break;
                  case 0xC6u:
                    artminis_mfb->frame_id = 2;
                    break;
                  case 0xC8u:
                    artminis_mfb->frame_id = 4;
                    break;
                  case 0xD3u:
                    artminis_mfb->frame_id = 10;
                    break;
                  case 0xD4u:
                    artminis_mfb->frame_id = 8;
                    break;
                  default:
                    break;
                }
              }
              DrawTexture(artminis_mfb, object->draw_x, object->draw_y - 34, 255, 1);
LABEL_945:
              v130 = object->unk13;
              if ( v130 && v130 & (1 << cur_player) )
                sub_43F170((int)object);
              LOBYTE(v2) = Player->player_id_2;
              byte_4842BC = Player->player_id_2;
              if ( object == cur_object )
              {
                LOBYTE(v2) = byte_5F746C[0];
                switch ( byte_5F746C[0] )
                {
                  case 0x20u:
                    v131 = object->class_id;
                    if ( *(_DWORD *)((char *)&unk_663578 + 914 * v131) )
                    {
                      LOBYTE(v2) = DrawTexture(
                                     magnify_mfb,
                                     object->field_C2 / 2 + object->field_BE / 2,
                                     object->field_C0 / 2 + object->field_C4 / 2,
                                     255,
                                     1);
                    }
                    else if ( v131 == 70 )
                    {
                      urotate_mfb->frame_id = dword_48445C;
                      LOBYTE(v2) = DrawTexture(
                                     urotate_mfb,
                                     object->field_C2 / 2 + object->field_BE / 2,
                                     object->field_C0 / 2 + object->field_C4 / 2,
                                     255,
                                     1);
                    }
                    else
                    {
                      hand_mfb->frame_id = dword_48445C;
                      LOBYTE(v2) = DrawTexture(
                                     hand_mfb,
                                     object->field_C2 / 2 + object->field_BE / 2,
                                     object->field_C0 / 2 + object->field_C4 / 2,
                                     255,
                                     1);
                    }
                    break;
                  case 0x22u:
                    capture_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   capture_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x23u:
                    if ( *(_DWORD *)((char *)&unk_663578 + 914 * object->class_id) )
                    {
                      torch_mfb->frame_id = dword_484460;
                      LOBYTE(v2) = DrawTexture(
                                     torch_mfb,
                                     object->field_C2 / 2 + object->field_BE / 2,
                                     object->field_C0 / 2 + object->field_C4 / 2,
                                     255,
                                     1);
                    }
                    else
                    {
                      ufight_mfb->frame_id = 0;
                      LOBYTE(v2) = DrawTexture(
                                     ufight_mfb,
                                     object->field_C2 / 2 + object->field_BE / 2,
                                     object->field_C0 / 2 + object->field_C4 / 2,
                                     255,
                                     1);
                    }
                    break;
                  case 0x24u:
                    LOBYTE(v2) = DrawTexture(
                                   uguild_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   dword_484464,
                                   1);
                    break;
                  case 0x25u:
                    utame_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   utame_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x26u:
                    urotate_mfb->frame_id = dword_48445C;
                    LOBYTE(v2) = DrawTexture(
                                   urotate_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x27u:
                    capture_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   capture_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x28u:
                    ueat_mfb->frame_id = dword_484468;
                    LOBYTE(v2) = DrawTexture(
                                   ueat_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x29u:
                    capture_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   capture_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x2Au:
                    v132 = object->class_id;
                    LOBYTE(v2) = -55 * v132;
                    if ( *(_DWORD *)((char *)&unk_663578 + 914 * v132) )
                      LOBYTE(v2) = DrawTexture(
                                     magnify_mfb,
                                     object->field_C2 / 2 + object->field_BE / 2,
                                     object->field_C0 / 2 + object->field_C4 / 2,
                                     255,
                                     1);
                    break;
                  case 0x2Bu:
                    hand_mfb->frame_id = dword_48445C;
                    LOBYTE(v2) = DrawTexture(
                                   hand_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x2Cu:
                    LOBYTE(v2) = DrawTexture(
                                   uleave_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   dword_484464,
                                   1);
                    break;
                  case 0x2Du:
                    LOBYTE(v2) = DrawTexture(
                                   unoguild_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   dword_484464,
                                   1);
                    break;
                  case 0x2Eu:
                    urepair_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   urepair_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x2Fu:
                    ufight_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   ufight_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  case 0x30u:
                    capture_mfb->frame_id = dword_484464;
                    LOBYTE(v2) = DrawTexture(
                                   capture_mfb,
                                   object->field_C2 / 2 + object->field_BE / 2,
                                   object->field_C0 / 2 + object->field_C4 / 2,
                                   255,
                                   1);
                    break;
                  default:
                    return (char)v2;
                }
              }
              return (char)v2;
            case 0xC7u:
              v121 = object->field_F2;
              if ( v121 == 106 )
              {
                frame_id = 5;
                y = object->draw_y;
                x = object->draw_x;
              }
              else if ( v121 == 108 || v121 == 109 )
              {
                frame_id = object->frame;
                y = object->draw_y;
LABEL_916:
                x = object->draw_x;
              }
              else
              {
                frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
              }
              goto LABEL_917;
            case 0xC9u:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xCBu:
              frame_id = object->frame >> 1;
              y = object->draw_y;
              goto LABEL_916;
            case 0xCDu:
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xCFu:
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
              if ( object->unk32 & 0x20000 )
                DrawTexture(footdoor_mfb, object->draw_x, object->draw_y, 255, 1);
              if ( !(object->unk32 & 0x80000) )
                goto LABEL_919;
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              frame_id = 255;
              y = object->draw_y - 40;
              v4 = aargh_mfb;
              x = object->draw_x - 40;
              goto LABEL_918;
            case 0xD1u:
              v122 = object->gen_period + 16;
              v123 = (HIDWORD(v122) ^ (unsigned __int8)((BYTE4(v122) ^ v122) - BYTE4(v122))) - HIDWORD(v122);
              frame_id = ((unsigned __int8)(object->data8[2] & 0xC) >> 2)
                       + 4 * (((BYTE4(v123) & 0x1F) + (signed int)v123) >> 5);
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xD2u:
              frame_id = object->frame;
              y = object->draw_y;
              goto LABEL_916;
            case 0xD5u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xD6u:
              if ( current_season == 3 )
              {
                frame_id = 2;
                y = object->draw_y;
                x = object->draw_x;
              }
              else
              {
                frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
              }
              goto LABEL_917;
            case 0xD7u:
              frame_id = object->state_id;
              y = object->draw_y;
              goto LABEL_916;
            case 0xD8u:
              frame_id = object->state_id;
              y = object->draw_y;
              goto LABEL_916;
            case 0xD9u:
              if ( current_season == 3 )
              {
                frame_id = 1;
                y = object->draw_y;
                x = object->draw_x;
              }
              else
              {
                frame_id = 0;
                y = object->draw_y;
                x = object->draw_x;
              }
              goto LABEL_917;
            case 0xDAu:
              frame_id = object->state_id;
              y = object->draw_y;
              goto LABEL_916;
            case 0xDBu:
              frame_id = 255;
              object->mfb_file->frame_id = object->frame;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xDCu:
              frame_id = object->state_id;
              y = object->draw_y;
              goto LABEL_916;
            case 0xDDu:
              v124 = (char *)&object->draw_y;
              v125 = (char *)&object->draw_x;
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, current_season == 3, 1);
              if ( object->unk225 )
              {
                frame_id = 255;
                bellring_mfb->frame_id = (unsigned __int8)(object->data8[2] & 0xC) >> 2;
                y = *(_DWORD *)v124;
                x = *(_DWORD *)v125;
                v4 = bellring_mfb;
              }
              else
              {
                frame_id = object->frame;
                y = *(_DWORD *)v124;
                x = *(_DWORD *)v125;
                v4 = look_ov_mfb;
              }
              goto LABEL_918;
            case 0xDEu:
              DrawTexture(fireball_mfb, object->draw_x, object->draw_y, 0, 1);
              v21 = object->data8[2];
              goto LABEL_914;
            case 0xDFu:
              v126 = object->gen_period + 16;
              v127 = (HIDWORD(v126) ^ (unsigned __int8)((BYTE4(v126) ^ v126) - BYTE4(v126))) - HIDWORD(v126);
              frame_id = ((BYTE4(v127) & 0x1F) + (signed int)v127) >> 5;
              y = object->draw_y;
              goto LABEL_916;
            case 0xE0u:
              v21 = object->data8[2];
              goto LABEL_914;
            case 0xE2u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xE3u:
              frame_id = object->data8[2] >> 2;
              y = object->draw_y;
              goto LABEL_916;
            case 0xE4u:
              frame_id = 255;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_917;
            case 0xE5u:
              frame_id = object->state_id;
              y = object->draw_y;
              goto LABEL_916;
            case 7u:
            case 0x26u:
            case 0x39u:
            case 0x8Fu:
            case 0xC3u:
            case 0xCAu:
            case 0xCCu:
            case 0xE6u:
            case 0xE7u:
              v21 = object->frame;
              goto LABEL_914;
            default:
              goto LABEL_919;
          }
        }
      }
    }
  }
  return (char)v2;
}