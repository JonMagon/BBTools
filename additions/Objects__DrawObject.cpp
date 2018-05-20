void __thiscall Objects::DrawObject(MapObject *this)
{
  MapObject *object; // edi
  int mask1; // ebx
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al
  unsigned __int8 v5; // al
  MFBEntry *v6; // ecx
  int v7; // eax
  unsigned __int8 v8; // cl
  int v9; // edx
  unsigned __int8 v10; // cl
  MFBEntry *v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned __int8 v14; // al
  unsigned __int8 v15; // cl
  unsigned __int8 v16; // al
  MFBEntry *v17; // eax
  MFBEntry *v18; // eax
  signed int v19; // eax
  unsigned __int8 v20; // al
  ObjectSex sex; // al
  MFBEntry *v22; // ecx
  MFBEntry *v23; // ecx
  __int64 v24; // rax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  unsigned __int8 v30; // al
  MFBEntry *v31; // ecx
  unsigned __int8 v32; // al
  unsigned __int8 v33; // al
  MFBEntry *v34; // eax
  unsigned __int8 v35; // al
  unsigned __int8 *v36; // esi
  unsigned __int8 v37; // al
  MFBEntry *v38; // eax
  __int64 v39; // rax
  MFBEntry *v40; // eax
  unsigned __int8 v41; // al
  __int64 v42; // rax
  int *v43; // esi
  int *v44; // ebx
  __int64 v45; // rax
  int v46; // eax
  unsigned __int8 v47; // al
  unsigned __int8 v48; // al
  unsigned __int8 v49; // cl
  int x; // [esp-10h] [ebp-20h]
  int v51; // [esp-10h] [ebp-20h]
  int v52; // [esp-10h] [ebp-20h]
  int y; // [esp-Ch] [ebp-1Ch]
  int v54; // [esp-Ch] [ebp-1Ch]
  int v55; // [esp-Ch] [ebp-1Ch]
  int frame_id; // [esp-8h] [ebp-18h]
  signed int v57; // [esp-8h] [ebp-18h]

  object = this;
  if ( !this->mfb_file )
    Objects::GetMFB(this);
  byte_4842BC = object->field_F8;
  if ( object->field_128 )
  {
    if ( !object->field_28 && !(object->unk32 & 0x1000000) )
    {
      mask1 = MapTiles[object->x + 192 * object->y].mask_manstand;
      if ( !(mask1 & 0x4000) )
      {
        sub_43F310(object);
        if ( object->unk32 & 0x2000000 )
          byte_4842C0 = 2;
        switch ( object->class_id )
        {
          case tree:
            if ( current_season == 3 )
            {
              frame_id = 255;
              object->mfb_file->frame_id = 1;
              y = object->draw_y;
              goto LABEL_904;
            }
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case church:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
            {
              DrawTexture(l_holy01_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(l_holy02_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            if ( object->unk32 & 0x20000 )
              DrawTexture(churover_mfb, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case peasant_hut:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
            {
              DrawTexture(l_peas01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(peasover_mfb, object->draw_x, object->draw_y, 0, 1);
            }
            v3 = object->frame;
            if ( v3 )
              DrawTexture(baby_mfb, object->draw_x - 145, object->draw_y, v3 - 1, 1);
            if ( current_season == 3 )
              DrawTexture(hutsmoke_mfb, object->draw_x, object->draw_y, object->data8[2] >> 2, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case tree1:
            v4 = object->frame;
            if ( v4 )
            {
              tree02_mfb->frame_id = v4;
              DrawTexture(tree02_mfb, object->draw_x, object->draw_y, 255, 1);
              goto LABEL_907;
            }
            if ( current_season == 3 )
            {
              tree04_mfb->frame_id = 0;
              DrawTexture(tree04_mfb, object->draw_x, object->draw_y, 255, 1);
              goto LABEL_907;
            }
            frame_id = 255;
            object->mfb_file->frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case tree2:
            v5 = object->frame;
            if ( v5 )
            {
              tree02_mfb->frame_id = v5;
              DrawTexture(tree02_mfb, object->draw_x, object->draw_y, 255, 1);
              goto LABEL_907;
            }
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            if ( current_season != 3 )
              goto LABEL_905;
            v6 = tree11_mfb;
            goto LABEL_906;
          case fire:
          case none_26:
          case none_39:
          case campfire:
          case none_C3:
          case smoke:
          case smoke1:
          case none_E6:
          case none_E7:
            v16 = object->frame;
            goto LABEL_902;
          case none_0A:
            if ( !is_night )
              DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
            DrawTexture((MFBEntry *)unk_6634E8, object->draw_x + 54, object->draw_y + 8, 255, 1);
            *((_DWORD *)unk_6634E8 + 20) = (unsigned int)(*((_DWORD *)unk_6634E8 + 20) + 1)
                                         % *((_DWORD *)unk_6634E8 + 19);
            goto LABEL_907;
          case none_10:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_18:
            frame_id = 255;
            object->mfb_file->frame_id = object->state_id >> 1;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case crate:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            DrawTexture(gasmold_mfb, object->draw_x, object->draw_y - 10, object->frame >> 2, 1);
            goto LABEL_907;
          case none_1A:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case none_1C:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame >> 1;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case stone_wall:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_21:
            v7 = object->field_F2;
            if ( !object->field_F2 )
            {
              DrawTexture(egg_mfb, object->draw_x, object->draw_y, object->frame >> 2, 1);
              goto LABEL_907;
            }
            if ( v7 == 25 )
            {
              v8 = object->frame;
              if ( v8 <= 5u )
              {
                frame_id = 255;
                object->mfb_file->frame_id = v8 >> 2;
                y = object->draw_y;
                goto LABEL_904;
              }
              switch ( object->gen_period >> 6 )
              {
                case 0:
                  v9 = v8 >> 2;
                  goto LABEL_58;
                case 1:
                  v9 = (v8 >> 2) + 24;
                  goto LABEL_58;
                case 2:
                  v9 = (v8 >> 2) + 48;
                  goto LABEL_58;
                case 3:
                  v9 = (v8 >> 2) + 72;
LABEL_58:
                  object->mfb_file->frame_id = v9;
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
              if ( v7 != 26 )
                goto LABEL_907;
              frame_id = 27;
              y = object->draw_y;
              x = object->draw_x;
            }
            goto LABEL_905;
          case none_22:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame >> 2;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case spike_trap:
            v10 = object->field_F2;
            if ( !v10 && object->owner_player != cur_player )
              goto LABEL_907;
            if ( !v10 )
            {
              frame_id = 255;
              object->mfb_file->frame_id = 0;
              y = object->draw_y;
              goto LABEL_904;
            }
            if ( v10 != 18 )
              goto LABEL_907;
            frame_id = 255;
            object->mfb_file->frame_id = object->frame >> 1;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case mine:
            if ( !object->state_id && object->owner_player != cur_player )
              goto LABEL_907;
            v11 = object->mfb_file;
            v11->frame_id = object->frame >= 0x3Cu;
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_29:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_2A:
            v12 = object->state_id;
            if ( object->state_id )
            {
              if ( v12 == 1 )
              {
                blkcloud_mfb->frame_id = 3;
                cloud_mfb->frame_id = 3;
                lgtning_mfb->frame_id = object->frame;
                DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                DrawTexture(lgtning_mfb, object->draw_x, object->draw_y - 80, 255, 1);
                DrawTexture(cloud_mfb, object->draw_x, object->draw_y - 80, 255, 1);
              }
              else if ( v12 == 2 )
              {
                blkcloud_mfb->frame_id = object->frame >> 2;
                cloud_mfb->frame_id = object->frame >> 2;
                DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                DrawTexture(cloud_mfb, object->draw_x, object->draw_y - 80, 255, 1);
              }
            }
            else
            {
              blkcloud_mfb->frame_id = object->frame >> 2;
              cloud_mfb->frame_id = object->frame >> 2;
              DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(cloud_mfb, object->draw_x, object->draw_y - 80, 255, 1);
            }
            goto LABEL_907;
          case none_2B:
            v13 = object->state_id;
            if ( object->state_id )
            {
              if ( v13 == 1 )
              {
                blkcloud_mfb->frame_id = 3;
                cloud_mfb->frame_id = 3;
                DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                if ( object->field_F2 == 17 )
                {
                  rain_mfb->frame_id = object->frame >> 2;
                  DrawTexture(rain_mfb, object->draw_x, object->draw_y - 80, 255, 1);
                }
                DrawTexture(cloud_mfb, object->draw_x, object->draw_y - 80, 255, 1);
              }
              else if ( v13 == 2 )
              {
                blkcloud_mfb->frame_id = object->frame >> 2;
                cloud_mfb->frame_id = object->frame >> 2;
                DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
                DrawTexture(cloud_mfb, object->draw_x, object->draw_y - 80, 255, 1);
              }
            }
            else
            {
              blkcloud_mfb->frame_id = object->frame >> 2;
              cloud_mfb->frame_id = object->frame >> 2;
              DrawTexture(blkcloud_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(cloud_mfb, object->draw_x, object->draw_y - 80, 255, 1);
            }
            goto LABEL_907;
          case none_2C:
            DrawTexture(equake_mfb, object->draw_x, object->draw_y, 12, 1);
            goto LABEL_907;
          case none_2E:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case well:
            object->mfb_file->frame_id = 0;
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
            if ( is_night )
            {
              DrawTexture(l_well01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(wellover_mfb, object->draw_x, object->draw_y, 0, 1);
            }
            goto LABEL_907;
          case none_30:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_31:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_32:
            v14 = object->frame >> 1;
            goto LABEL_903;
          case farm:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
            {
              DrawTexture(l_farm01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(farmover_mfb, object->draw_x, object->draw_y, 0, 1);
            }
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
                DrawTexture(feed_mfb, object->draw_x, object->draw_y, object->frame, 1);
                break;
              case 2u:
                DrawTexture(cocker_mfb, object->draw_x, object->draw_y, object->frame, 1);
                break;
              case 3u:
                DrawTexture(cowshed_mfb, object->draw_x, object->draw_y, 0, 1);
                break;
              case 4u:
                DrawTexture(pigsy_mfb, object->draw_x, object->draw_y, 0, 1);
                break;
              default:
                goto LABEL_907;
            }
            goto LABEL_907;
          case bakery:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
            {
              DrawTexture(l_bake01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(bakeover_mfb, object->draw_x, object->draw_y, 0, 1);
            }
            DrawTexture(bakeanim_mfb, object->draw_x, object->draw_y, (unsigned __int8)(object->data8[2] & 0xC) >> 2, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case brewery:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
            {
              DrawTexture(l_brew01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(brewover_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            if ( object->field_F2 == 100 )
            {
              v15 = object->frame;
              if ( v15 >= 3u )
                DrawTexture(brewsmal_mfb, object->draw_x, object->draw_y, v15 - 3, 1);
              else
                DrawTexture(brewbig_mfb, object->draw_x, object->draw_y, v15, 1);
            }
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case none_37:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case none_38:
            DrawTexture(fireball_mfb, object->draw_x, object->draw_y, 0, 1);
            v16 = object->data8[2];
            goto LABEL_902;
          case corpse:
            switch ( object->field_F2 )
            {
              case 0x1Bu:
                switch ( object->state_id )
                {
                  case 1u:
                    v17 = d_male_mfb;
                    if ( object->mfb_file != d_male_mfb )
                      goto LABEL_172;
                    break;
                  case 2u:
                    v17 = d_fema_mfb;
                    if ( object->mfb_file != d_fema_mfb )
                      goto LABEL_172;
                    break;
                  case 3u:
                    v17 = d_prie_mfb;
                    if ( object->mfb_file != d_prie_mfb )
                      goto LABEL_172;
                    break;
                  case 4u:
                    v17 = d_buil_mfb;
                    if ( object->mfb_file != d_buil_mfb )
                      goto LABEL_172;
                    break;
                  case 5u:
                    v17 = d_taxm_mfb;
                    if ( object->mfb_file != d_taxm_mfb )
                      goto LABEL_172;
                    break;
                  case 6u:
                    v17 = d_pike_mfb;
                    if ( object->mfb_file != d_pike_mfb )
                      goto LABEL_172;
                    break;
                  case 7u:
                    v17 = d_foot_mfb;
                    if ( object->mfb_file != d_foot_mfb )
                      goto LABEL_172;
                    break;
                  case 8u:
                    v17 = d_knig_mfb;
                    if ( object->mfb_file != d_knig_mfb )
                      goto LABEL_172;
                    break;
                  case 9u:
                    v17 = d_wiza_mfb;
                    if ( object->mfb_file != d_wiza_mfb )
                      goto LABEL_172;
                    break;
                  case 0xBu:
                    v17 = d_oldm_mfb;
                    if ( object->mfb_file != d_oldm_mfb )
                      goto LABEL_172;
                    break;
                  case 0xCu:
                    v17 = d_oldw_mfb;
                    if ( object->mfb_file != d_oldw_mfb )
                      goto LABEL_172;
                    break;
                  case 0xDu:
                    v17 = d_kidm_mfb;
                    if ( object->mfb_file != d_kidm_mfb )
                      goto LABEL_172;
                    break;
                  case 0xEu:
                    v17 = d_kidf_mfb;
                    if ( object->mfb_file != d_kidf_mfb )
                      goto LABEL_172;
                    break;
                  case 0x10u:
                    v17 = d_cava_mfb;
                    if ( object->mfb_file != d_cava_mfb )
                      goto LABEL_172;
                    break;
                  case 0x13u:
                    v17 = d_arch_mfb;
                    if ( object->mfb_file != d_arch_mfb )
                      goto LABEL_172;
                    break;
                  case 0x14u:
                    v17 = d_jest_mfb;
                    if ( object->mfb_file != d_jest_mfb )
                      goto LABEL_172;
                    break;
                  case 0x20u:
                    v17 = d_groom_mfb;
                    if ( object->mfb_file != d_groom_mfb )
                      goto LABEL_172;
                    break;
                  case 0x21u:
                    v17 = d_bride_mfb;
                    if ( object->mfb_file != d_bride_mfb )
                      goto LABEL_172;
                    break;
                  default:
                    v17 = d_male_mfb;
                    if ( object->mfb_file != d_male_mfb )
LABEL_172:
                      SetObjectMFBFile(object, v17);
                    break;
                }
                v57 = object->frame >> 2;
                v54 = object->draw_y;
                v51 = object->draw_x;
                goto LABEL_226;
              case 0x1Cu:
                if ( object->mfb_file != murd_wst_mfb )
                  SetObjectMFBFile(object, murd_wst_mfb);
                murd_wst_mfb->frame_id = 0;
                DrawTexture(murd_wst_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x1Du:
                if ( object->mfb_file != zombdead_mfb )
                  SetObjectMFBFile(object, zombdead_mfb);
                v57 = 255;
                v54 = object->draw_y;
                goto LABEL_225;
              case 0x1Eu:
                if ( object->mfb_file != cowchopm_mfb )
                  SetObjectMFBFile(object, cowchopm_mfb);
                cowchopm_mfb->frame_id = cowchopm_mfb->numimages - 1;
                DrawTexture(cowchopm_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x1Fu:
                v18 = cowplode_mfb;
                if ( object->mfb_file != cowplode_mfb )
                  goto LABEL_223;
                goto LABEL_224;
              case 0x21u:
                if ( object->mfb_file != pikedie_mfb )
                  SetObjectMFBFile(object, pikedie_mfb);
                pikedie_mfb->frame_id = object->frame >> 2;
                DrawTexture(pikedie_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x22u:
                if ( object->mfb_file != footdie_mfb )
                  SetObjectMFBFile(object, footdie_mfb);
                footdie_mfb->frame_id = object->frame >> 2;
                DrawTexture(footdie_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x23u:
                if ( object->mfb_file != flagdie_mfb )
                  SetObjectMFBFile(object, flagdie_mfb);
                flagdie_mfb->frame_id = object->frame >> 2;
                DrawTexture(flagdie_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x24u:
                if ( object->mfb_file != wizadie_mfb )
                  SetObjectMFBFile(object, wizadie_mfb);
                wizadie_mfb->frame_id = object->frame >> 2;
                DrawTexture(wizadie_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x25u:
                if ( object->mfb_file != skeleton_mfb )
                  SetObjectMFBFile(object, skeleton_mfb);
                DrawTexture(skeleton_mfb, object->draw_x, object->draw_y, 255, 1);
                goto LABEL_227;
              case 0x62u:
                if ( object->state_id == 23 )
                {
                  v18 = wolfdead_mfb;
                  if ( object->mfb_file == wolfdead_mfb )
                    goto LABEL_224;
                }
                else
                {
                  v18 = darkdead_mfb;
                  if ( object->mfb_file == darkdead_mfb )
                    goto LABEL_224;
                }
                goto LABEL_223;
              case 0x63u:
                if ( object->state_id == 24 )
                {
                  v18 = waspdead_mfb;
                  if ( object->mfb_file == waspdead_mfb )
                    goto LABEL_224;
                }
                else
                {
                  v18 = bloodead_mfb;
                  if ( object->mfb_file == bloodead_mfb )
                    goto LABEL_224;
                }
LABEL_223:
                SetObjectMFBFile(object, v18);
LABEL_224:
                v57 = 255;
                object->mfb_file->frame_id = object->frame >> 2;
                v54 = object->draw_y;
LABEL_225:
                v51 = object->draw_x;
LABEL_226:
                DrawTexture(object->mfb_file, v51, v54, v57, 1);
LABEL_227:
                if ( object->disease )
                {
                  buzz_mfb->frame_id = object->data8[2] % 0x12u / 3;
                  DrawTexture(buzz_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                if ( object->unk32 & 0x80000 )
                {
                  aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
                  DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 0x68u:
                v18 = deadbat_mfb;
                if ( object->mfb_file != deadbat_mfb )
                  goto LABEL_223;
                goto LABEL_224;
              case 0x69u:
                if ( object->mfb_file != giandead_mfb )
                  SetObjectMFBFile(object, giandead_mfb);
                v57 = 255;
                v54 = object->draw_y;
                goto LABEL_225;
              case 0x71u:
                if ( object->mfb_file != ogredead_mfb )
                  SetObjectMFBFile(object, ogredead_mfb);
                v57 = 255;
                v54 = object->draw_y;
                goto LABEL_225;
              case 0x72u:
                v18 = vampdead_mfb;
                if ( object->mfb_file != vampdead_mfb )
                  goto LABEL_223;
                goto LABEL_224;
              case 0x76u:
                v18 = cowkill_mfb;
                if ( object->mfb_file != cowkill_mfb )
                  goto LABEL_223;
                goto LABEL_224;
              case 0x77u:
                v18 = cowdie_mfb;
                if ( object->mfb_file != cowdie_mfb )
                  goto LABEL_223;
                goto LABEL_224;
              default:
                goto LABEL_227;
            }
            goto LABEL_907;
          case none_3C:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case oil:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_3E:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case town_hall:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
              DrawTexture(l_tax01_mfb, object->draw_x, object->draw_y, 255, 1);
            else
              DrawTexture(ticktock_mfb, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x20000 )
              DrawTexture(taxover_mfb, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case none_43:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame >> 1;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_44:
            v14 = object->frame >> 1;
            goto LABEL_903;
          case builders_guild:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            DrawTexture(sign_mfb, object->draw_x, object->draw_y, object->frame, 1);
            if ( is_night )
            {
              DrawTexture(l_work01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(workover_mfb, object->draw_x, object->draw_y, 0, 1);
            }
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 25, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x + 10, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case none_46:
            v19 = object->field_F2;
            if ( !object->field_F2 )
            {
              frame_id = 255;
              object->mfb_file->frame_id = object->gen_period >> 6;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_905;
            }
            if ( v19 >= 21 && v19 <= 22 )
            {
              fired_mfb->frame_id = object->gen_period >> 6;
              DrawTexture(fired_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            goto LABEL_907;
          case none_47:
            frame_id = 255;
            object->mfb_file->frame_id = object->gen_period >> 6;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_48:
            if ( object->owner_player != cur_player )
              goto LABEL_907;
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_49:
            frame_id = 255;
            object->mfb_file->frame_id = 0;
            y = object->draw_y;
            goto LABEL_904;
          case none_4A:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case tower:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_4C:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_4D:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case wheat:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, object->frame, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y + 20, 255, 1);
            }
            goto LABEL_907;
          case apple_tree:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_50:
            frame_id = 255;
            object->mfb_file->frame_id = object->data8[2] >> 2;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_51:
            object->mfb_file->frame_id = 0;
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
            towout_mfb->frame_id = (object->gen_period + 8) / 16;
            DrawTexture(towout_mfb, object->draw_x, object->draw_y, 255, 1);
            goto LABEL_907;
          case none_52:
            snicket_mfb->frame_id = 3 * object->frame;
            DrawTexture(snicket_mfb, object->draw_x, object->draw_y, 255, 1);
            goto LABEL_907;
          case _mushroom:
            frame_id = 255;
            object->mfb_file->frame_id = object->state_id;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_54:
            DrawTexture(worm_mfb, object->draw_x, object->draw_y, 255, 1);
            goto LABEL_907;
          case none_55:
            DrawTexture(turf_mfb, object->draw_x, object->draw_y, object->frame, 1);
            goto LABEL_907;
          case wizards_guild:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
              DrawTexture(l_wiz01_mfb, object->draw_x, object->draw_y, 255, 1);
            goto LABEL_907;
          case none_57:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_58:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_59:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_5A:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_5C:
            switch ( object->field_F2 )
            {
              case 0u:
                DrawTexture(bushman_mfb, object->draw_x, object->draw_y, 0, 1);
                DrawTexture(busheyes_mfb, object->draw_x, object->draw_y, 2, 1);
                break;
              case 0x2Cu:
                DrawTexture(bushman_mfb, object->draw_x, object->draw_y, 0, 1);
                DrawTexture(busheyes_mfb, object->draw_x, object->draw_y, object->data8[2] >> 7, 1);
                break;
              case 0x2Du:
                DrawTexture(
                  bushman_mfb,
                  object->draw_x,
                  object->draw_y,
                  ((unsigned __int8)(object->frame & 4) >> 2) + 1,
                  1);
                break;
              case 0x2Eu:
                DrawTexture(
                  bushman_mfb,
                  object->draw_x,
                  object->draw_y,
                  ((unsigned __int8)(object->frame & 4) >> 2) + 3,
                  1);
                break;
              case 0x2Fu:
                DrawTexture(
                  bushman_mfb,
                  object->draw_x,
                  object->draw_y,
                  2 - ((unsigned __int8)(object->frame & 4) >> 2),
                  1);
                break;
              case 0x30u:
                DrawTexture(shaker_mfb, object->draw_x, object->draw_y, 0, 1);
                switch ( object->sex )
                {
                  case 1u:
                    DrawTexture(bushk_ml_mfb, object->draw_x, object->draw_y, object->frame >> 2, 1);
                    break;
                  case 2u:
                    DrawTexture(bushk_fl_mfb, object->draw_x, object->draw_y, object->frame >> 2, 1);
                    break;
                  case 3u:
                    DrawTexture(bushk_pr_mfb, object->draw_x, object->draw_y, object->frame >> 2, 1);
                    break;
                  case 4u:
                    DrawTexture(bushk_rp_mfb, object->draw_x, object->draw_y, object->frame >> 2, 1);
                    break;
                  default:
                    goto LABEL_907;
                }
                break;
              case 0x31u:
                DrawTexture(shaker_mfb, object->draw_x, object->draw_y, (object->data8[2] >> 2) % 3u, 1);
                break;
              default:
                goto LABEL_907;
            }
            goto LABEL_907;
          case flame_trap:
            if ( object->field_F2 != 20 && object->owner_player != cur_player )
              goto LABEL_907;
            if ( object->mfb_file != flamedev_mfb )
              SetObjectMFBFile(object, flamedev_mfb);
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( object->field_F2 != 20 )
              goto LABEL_907;
            if ( object->mfb_file != flamepit_mfb )
              SetObjectMFBFile(object, flamepit_mfb);
            v14 = object->frame >> 1;
            goto LABEL_903;
          case apple_tree1:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case chick:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case baby_cow:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case flagpost:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            DrawTexture(flag_mfb, object->draw_x, object->draw_y, object->data8[2] >> 1, 1);
            goto LABEL_907;
          case none_63:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_64:
            frame_id = 255;
            object->mfb_file->frame_id = (object->gen_period + 8) / 16;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_66:
            frame_id = 255;
            object->mfb_file->frame_id = (object->gen_period + 4) / 8;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case villager:
            switch ( object->field_F2 )
            {
              case 0u:
                if ( is_night && object->owner_player == cur_player )
                  DrawTexture(lantern_mfb, object->draw_x, object->draw_y, 255, 1);
                if ( object->data8[0] == 15 )
                  DrawTexture(flag_mfb, object->draw_x, object->draw_y, object->data8[2] >> 1, 1);
                v20 = object->data8[0];
                switch ( v20 )
                {
                  case 6u:
                  case 2u:
                  case 4u:
                  case 0xAu:
                    if ( object->sex == 1 )
                    {
                      if ( object->mfb_file != sackmale_mfb )
                        SetObjectMFBFile(object, sackmale_mfb);
                      sackmale_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                      DrawTexture(sackmale_mfb, object->draw_x, object->draw_y, 255, 1);
                    }
                    else
                    {
                      if ( object->mfb_file != sackfema_mfb )
                        SetObjectMFBFile(object, sackfema_mfb);
                      sackfema_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                      DrawTexture(sackfema_mfb, object->draw_x, object->draw_y, 255, 1);
                    }
                    break;
                  case 8u:
                    if ( object->sex == 1 )
                    {
                      if ( object->mfb_file != m_barrel_mfb )
                        SetObjectMFBFile(object, m_barrel_mfb);
                      m_barrel_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                      DrawTexture(m_barrel_mfb, object->draw_x, object->draw_y, 255, 1);
                    }
                    else
                    {
                      if ( object->mfb_file != barlfema_mfb )
                        SetObjectMFBFile(object, barlfema_mfb);
                      barlfema_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                      DrawTexture(barlfema_mfb, object->draw_x, object->draw_y, 255, 1);
                    }
                    break;
                  case 0x13u:
                    f_milk_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                    DrawTexture(f_milk_mfb, object->draw_x, object->draw_y, 255, 1);
                    break;
                  default:
                    sex = object->sex;
                    switch ( sex )
                    {
                      case 4:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != reparman_mfb )
                            SetObjectMFBFile(object, reparman_mfb);
                          reparman_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(reparman_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != rp_still_mfb )
                            SetObjectMFBFile(object, rp_still_mfb);
                          DrawTexture(rp_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 5:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != taxman_mfb )
                            SetObjectMFBFile(object, taxman_mfb);
                          taxman_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(taxman_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != tx_still_mfb )
                            SetObjectMFBFile(object, tx_still_mfb);
                          DrawTexture(tx_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 17:
                        if ( object->mfb_file != bombman_mfb )
                          SetObjectMFBFile(object, bombman_mfb);
                        bombman_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                        DrawTexture(bombman_mfb, object->draw_x, object->draw_y, 255, 1);
                        break;
                      case 3:
                        if ( object->is_fleeing )
                        {
                          if ( object->mfb_file != fleeprie_mfb )
                            SetObjectMFBFile(object, fleeprie_mfb);
                          fleeprie_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(fleeprie_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else if ( object->is_going )
                        {
                          if ( object->mfb_file != priest_mfb )
                            SetObjectMFBFile(object, priest_mfb);
                          priest_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(priest_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != pr_still_mfb )
                            SetObjectMFBFile(object, pr_still_mfb);
                          DrawTexture(pr_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 2:
                        if ( object->is_fleeing )
                        {
                          if ( object->mfb_file != fleefema_mfb )
                            SetObjectMFBFile(object, fleefema_mfb);
                          fleefema_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(fleefema_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else if ( object->is_going )
                        {
                          if ( object->mfb_file != woman_mfb )
                            SetObjectMFBFile(object, woman_mfb);
                          woman_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(woman_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != f_still_mfb )
                            SetObjectMFBFile(object, f_still_mfb);
                          DrawTexture(f_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 1:
                        if ( object->is_fleeing )
                        {
                          if ( object->mfb_file != fleemale_mfb )
                            SetObjectMFBFile(object, fleemale_mfb);
                          fleemale_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(fleemale_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else if ( object->is_going )
                        {
                          if ( object->mfb_file != villager_mfb )
                            SetObjectMFBFile(object, villager_mfb);
                          villager_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(villager_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != m_still_mfb )
                            SetObjectMFBFile(object, m_still_mfb);
                          DrawTexture(m_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 32:
                        v22 = object->mfb_file;
                        if ( object->is_going )
                        {
                          if ( v22 != m_weddin_mfb )
                            SetObjectMFBFile(object, m_weddin_mfb);
                          object->mfb_file->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( v22 != m_weddin_mfb )
                            SetObjectMFBFile(object, m_weddin_mfb);
                          object->mfb_file->frame_id = 42;
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        break;
                      case 33:
                        v23 = object->mfb_file;
                        if ( object->is_going )
                        {
                          if ( v23 != f_weddin_mfb )
                            SetObjectMFBFile(object, f_weddin_mfb);
                          object->mfb_file->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( v23 != f_weddin_mfb )
                            SetObjectMFBFile(object, f_weddin_mfb);
                          object->mfb_file->frame_id = 42;
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        break;
                      case 11:
                        if ( object->mfb_file != elderm_mfb )
                          SetObjectMFBFile(object, elderm_mfb);
                        elderm_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                        DrawTexture(elderm_mfb, object->draw_x, object->draw_y, 255, 1);
                        break;
                      case 12:
                        if ( object->mfb_file != elderf_mfb )
                          SetObjectMFBFile(object, elderf_mfb);
                        elderf_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                        DrawTexture(elderf_mfb, object->draw_x, object->draw_y, 255, 1);
                        break;
                      case 13:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != kidm_mfb )
                            SetObjectMFBFile(object, kidm_mfb);
                          kidm_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(kidm_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != boystill_mfb )
                            SetObjectMFBFile(object, boystill_mfb);
                          DrawTexture(boystill_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 14:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != kidf_mfb )
                            SetObjectMFBFile(object, kidf_mfb);
                          kidf_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(kidf_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != girlstil_mfb )
                            SetObjectMFBFile(object, girlstil_mfb);
                          DrawTexture(girlstil_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 7:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != footwalk_mfb )
                            SetObjectMFBFile(object, footwalk_mfb);
                          footwalk_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(footwalk_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != ft_still_mfb )
                            SetObjectMFBFile(object, ft_still_mfb);
                          DrawTexture(ft_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 8:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != knigwalk_mfb )
                            SetObjectMFBFile(object, knigwalk_mfb);
                          knigwalk_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(knigwalk_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != kn_still_mfb )
                            SetObjectMFBFile(object, kn_still_mfb);
                          DrawTexture(kn_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 19:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != archer_mfb )
                            SetObjectMFBFile(object, archer_mfb);
                          archer_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(archer_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != arc_stil_mfb )
                            SetObjectMFBFile(object, arc_stil_mfb);
                          DrawTexture(arc_stil_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        break;
                      case 20:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != minstrel_mfb )
                            SetObjectMFBFile(object, minstrel_mfb);
                          minstrel_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(minstrel_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != minjuggl_mfb )
                            SetObjectMFBFile(object, minjuggl_mfb);
                          object->mfb_file->frame_id = object->data8[2] >> 2;
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        break;
                      case 21:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != monkwalk_mfb )
                            SetObjectMFBFile(object, monkwalk_mfb);
                          object->mfb_file->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != mk_stil_mfb )
                            SetObjectMFBFile(object, mk_stil_mfb);
                          object->mfb_file->frame_id = object->data8[2] >> 2;
                          DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        }
                        break;
                      case 9:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != wizwalk_mfb )
                            SetObjectMFBFile(object, wizwalk_mfb);
                          wizwalk_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(wizwalk_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != wz_still_mfb )
                            SetObjectMFBFile(object, wz_still_mfb);
                          DrawTexture(wz_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 6:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != pikewalk_mfb )
                            SetObjectMFBFile(object, pikewalk_mfb);
                          pikewalk_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(pikewalk_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != pk_still_mfb )
                            SetObjectMFBFile(object, pk_still_mfb);
                          DrawTexture(pk_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 10:
                        if ( object->is_going )
                        {
                          if ( object->mfb_file != flagwalk_mfb )
                            SetObjectMFBFile(object, flagwalk_mfb);
                          flagwalk_mfb->frame_id = (object->state_id >> 1) + 6 * ((object->gen_period + 16) / 32);
                          DrawTexture(flagwalk_mfb, object->draw_x, object->draw_y, 255, 1);
                        }
                        else
                        {
                          if ( object->mfb_file != fg_still_mfb )
                            SetObjectMFBFile(object, fg_still_mfb);
                          DrawTexture(fg_still_mfb, object->draw_x, object->draw_y, object->state_id, 1);
                        }
                        break;
                      case 16:
                        if ( object->mfb_file != cavalier_mfb )
                          SetObjectMFBFile(object, cavalier_mfb);
                        object->mfb_file->frame_id = (object->state_id / 3u & 3) + 4 * ((object->gen_period + 16) / 32);
                        DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                        break;
                    }
                    break;
                }
                break;
              case 3u:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != cowchopm_mfb )
                    SetObjectMFBFile(object, cowchopm_mfb);
                  cowchopm_mfb->frame_id = object->frame >> 2;
                  DrawTexture(cowchopm_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != cowchopf_mfb )
                    SetObjectMFBFile(object, cowchopf_mfb);
                  cowchopf_mfb->frame_id = object->frame >> 2;
                  DrawTexture(cowchopf_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 4u:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != m_chkill_mfb )
                    SetObjectMFBFile(object, m_chkill_mfb);
                  m_chkill_mfb->frame_id = object->frame >> 2;
                  DrawTexture(m_chkill_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != f_chkill_mfb )
                    SetObjectMFBFile(object, f_chkill_mfb);
                  f_chkill_mfb->frame_id = object->frame >> 2;
                  DrawTexture(f_chkill_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 5u:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != m_shaker_mfb )
                    SetObjectMFBFile(object, m_shaker_mfb);
                  m_shaker_mfb->frame_id = object->frame >> 2;
                  DrawTexture(m_shaker_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != f_shaker_mfb )
                    SetObjectMFBFile(object, f_shaker_mfb);
                  f_shaker_mfb->frame_id = object->frame >> 2;
                  DrawTexture(f_shaker_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 6u:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != mharvest_mfb )
                    SetObjectMFBFile(object, mharvest_mfb);
                  mharvest_mfb->frame_id = object->frame >> 2;
                  DrawTexture(mharvest_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != fharvest_mfb )
                    SetObjectMFBFile(object, fharvest_mfb);
                  fharvest_mfb->frame_id = object->frame >> 2;
                  DrawTexture(fharvest_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 7u:
                switch ( object->sex )
                {
                  case 1u:
                    if ( object->mfb_file != mthrow_mfb )
                      SetObjectMFBFile(object, mthrow_mfb);
                    object->mfb_file->frame_id = object->frame + 5 * ((object->gen_period + 16) / 32);
                    DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    break;
                  case 2u:
                    if ( object->mfb_file != fthrow_mfb )
                      SetObjectMFBFile(object, fthrow_mfb);
                    object->mfb_file->frame_id = object->frame + 5 * ((object->gen_period + 16) / 32);
                    DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    break;
                  case 6u:
                    if ( object->mfb_file != pikeatta_mfb )
                      SetObjectMFBFile(object, pikeatta_mfb);
                    pikeatta_mfb->frame_id = (object->state_id >> 2) + 6 * (object->gen_period >> 6);
                    DrawTexture(pikeatta_mfb, object->draw_x, object->draw_y, 255, 1);
                    break;
                  case 7u:
                    if ( object->mfb_file != footatta_mfb )
                      SetObjectMFBFile(object, footatta_mfb);
                    footatta_mfb->frame_id = object->frame + 6 * ((object->gen_period + 16) / 32);
                    DrawTexture(footatta_mfb, object->draw_x, object->draw_y, 255, 1);
                    break;
                  case 8u:
                    if ( object->frame >= 7u )
                    {
                      if ( object->mfb_file != knigwalk_mfb )
                        SetObjectMFBFile(object, knigwalk_mfb);
                      object->mfb_file->frame_id = 6 * ((object->gen_period + 16) / 32);
                      DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    }
                    else
                    {
                      if ( object->mfb_file != knigatta_mfb )
                        SetObjectMFBFile(object, knigatta_mfb);
                      object->mfb_file->frame_id = object->frame + 7 * ((object->gen_period + 16) / 32);
                      DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    }
                    break;
                  case 9u:
                    if ( object->mfb_file != wizaim_mfb )
                      SetObjectMFBFile(object, wizaim_mfb);
                    object->mfb_file->frame_id = (object->gen_period + 16) / 32;
                    DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    break;
                  case 0x10u:
                    if ( object->frame >= 5u )
                    {
                      if ( object->mfb_file != cavalier_mfb )
                        SetObjectMFBFile(object, cavalier_mfb);
                      object->mfb_file->frame_id = 4 * ((object->gen_period + 16) / 32);
                      DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    }
                    else
                    {
                      if ( object->mfb_file != cavatta_mfb )
                        SetObjectMFBFile(object, cavatta_mfb);
                      object->mfb_file->frame_id = object->frame + 5 * ((object->gen_period + 16) / 32);
                      DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    }
                    break;
                  case 0x13u:
                    if ( object->mfb_file != archshoo_mfb )
                      SetObjectMFBFile(object, archshoo_mfb);
                    v24 = (object->gen_period + 16) / 32;
                    archshoo_mfb->frame_id = object->frame + 4 * ((HIDWORD(v24) ^ abs((_BYTE)v24) & 7) - HIDWORD(v24));
                    DrawTexture(archshoo_mfb, object->draw_x, object->draw_y, 255, 1);
                    break;
                  default:
                    DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                    break;
                }
                break;
              case 9u:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != vpick_mfb )
                    SetObjectMFBFile(object, vpick_mfb);
                  object->mfb_file->frame_id = object->frame >> 2;
                  DrawTexture(object->mfb_file, object->draw_x, object->draw_y - 20, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != pick_mfb )
                    SetObjectMFBFile(object, pick_mfb);
                  object->mfb_file->frame_id = (object->frame >> 2) + 1;
                  DrawTexture(object->mfb_file, object->draw_x, object->draw_y - 20, 255, 1);
                }
                break;
              case 0xAu:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != vsaw_mfb )
                    SetObjectMFBFile(object, vsaw_mfb);
                  object->mfb_file->frame_id = object->frame >> 2;
                  DrawTexture(object->mfb_file, object->draw_x, object->draw_y - 20, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != saw_mfb )
                    SetObjectMFBFile(object, saw_mfb);
                  object->mfb_file->frame_id = (object->frame >> 2) + 1;
                  DrawTexture(object->mfb_file, object->draw_x, object->draw_y - 20, 255, 1);
                }
                break;
              case 0xBu:
                if ( object->sex == 4 )
                {
                  if ( object->mfb_file != hammer_mfb )
                    SetObjectMFBFile(object, hammer_mfb);
                  hammer_mfb->frame_id = (object->frame >> 2) + ((object->gen_period >> 4) & 0xFC);
                  DrawTexture(hammer_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != manham_mfb )
                    SetObjectMFBFile(object, manham_mfb);
                  manham_mfb->frame_id = (object->frame >> 2) + ((object->gen_period >> 4) & 0xFC);
                  DrawTexture(manham_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 0xCu:
                if ( object->sex == 1 )
                {
                  if ( object->mfb_file != m_chop_mfb )
                    SetObjectMFBFile(object, m_chop_mfb);
                  m_chop_mfb->frame_id = object->frame >> 2;
                  DrawTexture(m_chop_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else
                {
                  if ( object->mfb_file != f_chop_mfb )
                    SetObjectMFBFile(object, f_chop_mfb);
                  f_chop_mfb->frame_id = object->frame >> 2;
                  DrawTexture(f_chop_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 0xDu:
                if ( object->mfb_file != pri_heal_mfb )
                  SetObjectMFBFile(object, pri_heal_mfb);
                pri_heal_mfb->frame_id = object->frame >> 2;
                DrawTexture(pri_heal_mfb, object->draw_x, object->draw_y, 255, 1);
                healovr_mfb->frame_id = pri_heal_mfb->frame_id;
                DrawTexture(healovr_mfb, object->draw_x, object->draw_y, 255, 1);
                break;
              case 0xEu:
                v25 = object->sex;
                if ( v25 == 3 )
                {
                  if ( object->mfb_file != pri_heal_mfb )
                    SetObjectMFBFile(object, pri_heal_mfb);
                  pri_heal_mfb->frame_id = object->frame >> 2;
                  DrawTexture(pri_heal_mfb, object->draw_x, object->draw_y, 255, 1);
                  healovr_mfb->frame_id = pri_heal_mfb->frame_id;
                  DrawTexture(healovr_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                else if ( v25 == 9 )
                {
                  if ( object->mfb_file != wizcast_mfb )
                    SetObjectMFBFile(object, wizcast_mfb);
                  wizcast_mfb->frame_id = object->frame >> 2;
                  DrawTexture(wizcast_mfb, object->draw_x, object->draw_y, 255, 1);
                }
                break;
              case 0x10u:
                if ( object->mfb_file != dword_6033CC )
                  SetObjectMFBFile(object, dword_6033CC);
                switch ( object->sex )
                {
                  case 1u:
                    v26 = (object->gen_period >> 7) + 6;
                    break;
                  case 2u:
                    v26 = (object->gen_period >> 7) + 8;
                    break;
                  case 4u:
                    v26 = object->gen_period >> 7;
                    break;
                  case 5u:
                    v26 = (object->gen_period >> 7) + 2;
                    break;
                  default:
                    v26 = (object->gen_period >> 7) + 6;
                    break;
                }
                object->mfb_file->frame_id = v26;
                DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                break;
              case 0x5Du:
                if ( object->mfb_file != milking_mfb )
                  SetObjectMFBFile(object, milking_mfb);
                milking_mfb->frame_id = object->frame >> 2;
                DrawTexture(milking_mfb, object->draw_x, object->draw_y, 255, 1);
                break;
              default:
                break;
            }
            if ( object->disease )
            {
              buzz_mfb->frame_id = object->data8[2] % 0x12u / 3;
              DrawTexture(buzz_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            goto LABEL_907;
          case creature:
            if ( object->field_F2 )
            {
              if ( object->field_F2 != 7 )
                goto LABEL_750;
              switch ( object->sex )
              {
                case 0xFu:
                  if ( object->mfb_file != catfire_mfb )
                    SetObjectMFBFile(object, catfire_mfb);
                  object->mfb_file->frame_id = object->frame + 2 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  v52 = object->draw_x;
                  goto LABEL_749;
                case 0x12u:
                  if ( object->mfb_file != zombatta_mfb )
                    SetObjectMFBFile(object, zombatta_mfb);
                  object->mfb_file->frame_id = object->frame + 4 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  v52 = object->draw_x;
                  goto LABEL_749;
                case 0x16u:
                  if ( object->mfb_file != crossbow_mfb )
                    SetObjectMFBFile(object, crossbow_mfb);
                  object->mfb_file->frame_id = object->frame + 2 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  v52 = object->draw_x;
                  goto LABEL_749;
                case 0x17u:
                  if ( object->frame )
                  {
                    if ( object->mfb_file != wolfatta_mfb )
                      SetObjectMFBFile(object, wolfatta_mfb);
                    v28 = (object->gen_period + 16) / 32;
                  }
                  else
                  {
                    if ( object->mfb_file != wolf_mfb )
                      SetObjectMFBFile(object, wolf_mfb);
                    v28 = 4 * ((object->gen_period + 16) / 32);
                  }
                  object->mfb_file->frame_id = v28;
                  goto LABEL_747;
                case 0x18u:
                  if ( object->state_id < 0xCu )
                  {
                    if ( object->mfb_file != waspat_mfb )
                      SetObjectMFBFile(object, waspat_mfb);
                    object->mfb_file->frame_id = object->frame + 6 * ((object->gen_period + 16) / 32);
                    v55 = object->draw_y;
                    v52 = object->draw_x;
                    goto LABEL_749;
                  }
                  if ( object->mfb_file != wasp_mfb )
                    SetObjectMFBFile(object, wasp_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x19u:
                  if ( object->frame == 1 )
                  {
                    if ( object->mfb_file != bat_mfb )
                      SetObjectMFBFile(object, bat_mfb);
                    object->mfb_file->frame_id = (object->gen_period + 16) / 32;
                    v55 = object->draw_y;
                    v52 = object->draw_x;
                    goto LABEL_749;
                  }
                  if ( object->mfb_file != bat_mfb )
                    SetObjectMFBFile(object, bat_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x1Au:
                  if ( object->mfb_file != fiend_mfb )
                    SetObjectMFBFile(object, fiend_mfb);
                  object->mfb_file->frame_id = (object->data8[2] >> 1) % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  v52 = object->draw_x;
                  goto LABEL_749;
                case 0x1Bu:
                  if ( object->frame < 4u )
                  {
                    if ( object->mfb_file != gianatt_mfb )
                      SetObjectMFBFile(object, gianatt_mfb);
                    object->mfb_file->frame_id = object->frame + 4 * ((object->gen_period + 16) / 32);
                    v55 = object->draw_y;
                    v52 = object->draw_x;
                    goto LABEL_749;
                  }
                  if ( object->mfb_file != giant_mfb )
                    SetObjectMFBFile(object, giant_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x1Cu:
                  if ( object->state_id < 0xCu )
                  {
                    if ( object->mfb_file != bldsting_mfb )
                      SetObjectMFBFile(object, bldsting_mfb);
                    object->mfb_file->frame_id = object->frame + 6 * ((object->gen_period + 16) / 32);
                    v55 = object->draw_y;
                    v52 = object->draw_x;
                    goto LABEL_749;
                  }
                  if ( object->mfb_file != bloodwsp_mfb )
                    SetObjectMFBFile(object, bloodwsp_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x1Du:
                  if ( object->frame )
                  {
                    if ( object->mfb_file != dw_attak_mfb )
                      SetObjectMFBFile(object, dw_attak_mfb);
                    v29 = (object->gen_period + 16) / 32;
                  }
                  else
                  {
                    if ( object->mfb_file != dw_walk_mfb )
                      SetObjectMFBFile(object, dw_walk_mfb);
                    v29 = 4 * ((object->gen_period + 16) / 32);
                  }
                  object->mfb_file->frame_id = v29;
                  goto LABEL_747;
                case 0x1Eu:
                  if ( object->frame >= 7u )
                  {
                    if ( object->mfb_file != ogrewalk_mfb )
                      SetObjectMFBFile(object, ogrewalk_mfb);
                    object->mfb_file->frame_id = 6 * ((object->gen_period + 16) / 32);
                  }
                  else
                  {
                    if ( object->mfb_file != ogreatta_mfb )
                      SetObjectMFBFile(object, ogreatta_mfb);
                    object->mfb_file->frame_id = object->frame + 7 * ((object->gen_period + 16) / 32);
                  }
                  goto LABEL_747;
                case 0x1Fu:
                  v30 = object->frame;
                  if ( v30 < 1u || v30 > 7u )
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
                  goto LABEL_747;
                default:
                  goto LABEL_750;
              }
            }
            else
            {
              switch ( object->sex )
              {
                case 0xFu:
                  if ( object->mfb_file != catapult_mfb )
                    SetObjectMFBFile(object, catapult_mfb);
                  object->mfb_file->frame_id = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                                             + 4 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  v52 = object->draw_x;
                  goto LABEL_749;
                case 0x12u:
                  if ( object->mfb_file != zombie_mfb )
                    SetObjectMFBFile(object, zombie_mfb);
                  object->mfb_file->frame_id = (object->state_id >> 2) % 6u + 6 * ((object->gen_period + 16) / 32);
                  DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
                  if ( is_night )
                    DrawTexture(zombglow_mfb, object->draw_x, object->draw_y, (object->gen_period + 16) / 32, 1);
                  goto LABEL_750;
                case 0x16u:
                  if ( object->mfb_file != crossbow_mfb )
                    SetObjectMFBFile(object, crossbow_mfb);
                  object->mfb_file->frame_id = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                                             + 4 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  v52 = object->draw_x;
                  goto LABEL_749;
                case 0x17u:
                  if ( object->is_going )
                  {
                    if ( object->mfb_file != wolf_mfb )
                      SetObjectMFBFile(object, wolf_mfb);
                    object->mfb_file->frame_id = ((unsigned __int8)(object->state_id & 0xC) >> 2)
                                               + 4 * ((object->gen_period + 16) / 32);
                  }
                  else
                  {
                    if ( object->mfb_file != wolfstil_mfb )
                      SetObjectMFBFile(object, wolfstil_mfb);
                    object->mfb_file->frame_id = (object->gen_period + 16) / 32;
                  }
                  goto LABEL_747;
                case 0x18u:
                  if ( object->mfb_file != wasp_mfb )
                    SetObjectMFBFile(object, wasp_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x19u:
                  if ( object->mfb_file != bat_mfb )
                    SetObjectMFBFile(object, bat_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x1Au:
                  if ( object->mfb_file != fiend_mfb )
                    SetObjectMFBFile(object, fiend_mfb);
                  if ( object->unk30 || object->unk31 )
                  {
                    object->mfb_file->frame_id = (object->data8[2] >> 1) % 6u + 6 * ((object->gen_period + 16) / 32);
                  }
                  else if ( object->unk32 & 0x10000 )
                  {
                    object->mfb_file->frame_id = 54;
                  }
                  else
                  {
                    object->mfb_file->frame_id = (object->data8[2] >> 1) % 6u + 48;
                  }
                  goto LABEL_747;
                case 0x1Bu:
                  if ( object->is_going )
                  {
                    if ( object->mfb_file != giant_mfb )
                      SetObjectMFBFile(object, giant_mfb);
                    object->mfb_file->frame_id = (object->state_id >> 1) % 6u + 6 * ((object->gen_period + 16) / 32);
                    v55 = object->draw_y;
                    v52 = object->draw_x;
                    goto LABEL_749;
                  }
                  if ( object->mfb_file != gianstil_mfb )
                    SetObjectMFBFile(object, gianstil_mfb);
                  goto LABEL_747;
                case 0x1Cu:
                  if ( object->mfb_file != bloodwsp_mfb )
                    SetObjectMFBFile(object, bloodwsp_mfb);
                  object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                  v55 = object->draw_y;
                  break;
                case 0x1Du:
                  if ( object->is_going )
                  {
                    if ( object->mfb_file != dw_walk_mfb )
                      SetObjectMFBFile(object, dw_walk_mfb);
                    v27 = ((unsigned __int8)(object->state_id & 0xC) >> 2) + 4 * ((object->gen_period + 16) / 32);
                  }
                  else
                  {
                    if ( object->mfb_file != dw_still_mfb )
                      SetObjectMFBFile(object, dw_still_mfb);
                    v27 = (object->gen_period + 16) / 32;
                  }
                  object->mfb_file->frame_id = v27;
                  goto LABEL_747;
                case 0x1Eu:
                  if ( object->is_going )
                  {
                    if ( object->mfb_file != ogrewalk_mfb )
                      SetObjectMFBFile(object, ogrewalk_mfb);
                    object->mfb_file->frame_id = object->state_id % 6u + 6 * ((object->gen_period + 16) / 32);
                    v55 = object->draw_y;
                  }
                  else
                  {
                    if ( object->mfb_file != ogrestil_mfb )
                      SetObjectMFBFile(object, ogrestil_mfb);
LABEL_747:
                    v55 = object->draw_y;
                  }
                  break;
                case 0x1Fu:
                  if ( object->mfb_file != vampstil_mfb )
                    SetObjectMFBFile(object, vampstil_mfb);
                  object->mfb_file->frame_id = object->state_id;
                  v55 = object->draw_y;
                  break;
                default:
                  goto LABEL_750;
              }
            }
            v52 = object->draw_x;
LABEL_749:
            DrawTexture(object->mfb_file, v52, v55, 255, 1);
LABEL_750:
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            goto LABEL_907;
          case none_6A:
            object->mfb_file->frame_id = (object->gen_period + 4) / 8;
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
            dword_6A9948->frame_id = (object->unk82 + 4) / 8;
            DrawTexture(dword_6A9948, object->draw_x, object->draw_y, 255, 1);
            goto LABEL_907;
          case cow:
            if ( object->field_F2 == 94 )
              goto LABEL_760;
            v31 = object->mfb_file;
            if ( object->is_going )
            {
              if ( v31 == cowwalk_mfb )
                goto LABEL_759;
            }
            else if ( v31 == cowwalk_mfb )
            {
              goto LABEL_759;
            }
            SetObjectMFBFile(object, cowwalk_mfb);
LABEL_759:
            object->mfb_file->frame_id = (object->state_id >> 1) + 7 * ((object->gen_period + 16) / 32);
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
LABEL_760:
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            goto LABEL_907;
          case chicken:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 255, 1);
            chicken_mfb->frame_id = object->state_id + ((object->gen_period >> 5) & 0xFE);
            DrawTexture(chicken_mfb, object->draw_x, object->draw_y + 20, 255, 1);
            if ( object->field_F2 == 92 )
              DrawTexture(chickegg_mfb, object->draw_x + 12, object->draw_y + 20, 0, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y + 20, 255, 1);
            }
            goto LABEL_907;
          case peasant_hut1:
          case bakery1:
          case well1:
          case farm1:
          case builders_guild1:
          case brewery1:
          case town_hall1:
          case church1:
          case archers_guild1:
          case minstrels_guild1:
          case knights_guild1:
          case prison1:
          case stables1:
          case wizards_guild1:
          case footmans_guild1:
          case lookout_post1:
            if ( object->field_F2 != 67 )
              goto LABEL_907;
            frame_id = 1;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case rockpile:
            v32 = object->field_F2;
            if ( !v32 )
            {
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_905;
            }
            if ( v32 != 61 )
              goto LABEL_907;
            frame_id = 5;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case woodpile:
            v33 = object->field_F2;
            if ( !v33 )
            {
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
              goto LABEL_905;
            }
            if ( v33 != 63 )
              goto LABEL_907;
            frame_id = 5;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case fence:
            if ( current_season == 3 )
            {
              v34 = snwfence_mfb;
              if ( object->mfb_file == snwfence_mfb )
                goto LABEL_781;
            }
            else
            {
              v34 = fence_mfb;
              if ( object->mfb_file == fence_mfb )
                goto LABEL_781;
            }
            SetObjectMFBFile(object, v34);
LABEL_781:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_83:
            frame_id = 1;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_84:
            frame_id = object->frame >> 2;
            y = object->draw_y;
            goto LABEL_904;
          case young_tree:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case none_87:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_88:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_8A:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_8D:
            if ( object->field_F2 != 75 )
              goto LABEL_907;
            if ( object->mfb_file != s_summon_mfb )
              SetObjectMFBFile(object, s_summon_mfb);
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case none_8E:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case archers_guild:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( is_night )
            {
              DrawTexture(l_arch01_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            else if ( object->unk32 & 0x20000 )
            {
              DrawTexture(archdoor_mfb, object->draw_x, object->draw_y, 255, 1);
            }
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 25, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x + 10, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case none_93:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case none_94:
            v14 = object->frame >> 1;
            goto LABEL_903;
          case none_95:
            v14 = object->frame >> 1;
            goto LABEL_903;
          case minstrels_guild:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case knights_guild:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x20000 )
              DrawTexture(keepdoor_mfb, object->draw_x, object->draw_y, 255, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case prison:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x20000 )
              DrawTexture(jaildoor_mfb, object->draw_x, object->draw_y, 255, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 10, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 35, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case none_9C:
            frame_id = (object->gen_period + 16) / 32;
            y = object->draw_y;
            goto LABEL_904;
          case stables:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x20000 )
              DrawTexture(stabdoor_mfb, object->draw_x, object->draw_y, 255, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case silver_goblet:
          case potion:
          case gold_goblet:
          case holy_sword:
          case helmet_of_strength:
          case ring_of_fire_protection:
          case shield_of_the_gods:
          case crucifix:
          case magic_key:
          case shovel:
          case cloak_of_invisibility:
          case ring_of_absolute_power:
            v16 = object->data8[2];
            goto LABEL_902;
          case gold:
            v16 = object->data8[2];
            goto LABEL_902;
          case temple:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case rock:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_A4:
            v14 = object->frame >> 1;
            goto LABEL_903;
          case gate:
            frame_id = 255;
            object->mfb_file->frame_id = object->state_id + 3 * object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case generator:
            if ( byte_4843E8 != 1 )
              goto LABEL_907;
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_AD:
            v14 = object->data8[2] >> 1;
            goto LABEL_903;
          case magic_scroll:
            v35 = object->state_id;
            if ( v35 > 6u )
            {
              if ( v35 < 0x10u || v35 > 0x16u )
              {
                v36 = &object->frame;
                object->frame = 32;
              }
              else
              {
                v36 = &object->frame;
                object->frame = v35 - 9;
              }
            }
            else
            {
              object->frame = v35;
              v36 = &object->frame;
            }
            if ( *v36 >= 0x20u )
            {
              DrawTexture(crate_mfb, object->draw_x, object->draw_y, 255, 1);
              goto LABEL_907;
            }
            DrawTexture(shadow_mfb, object->draw_x, object->draw_y + 6, 255, 1);
            v37 = (unsigned __int8)(object->data8[2] & 0x1C) >> 2;
            object->gen_period = v37;
            switch ( v37 )
            {
              case 0u:
                frame_id = *v36;
                y = object->draw_y - 5;
                x = object->draw_x;
                goto LABEL_905;
              case 1u:
              case 7u:
                frame_id = *v36;
                y = object->draw_y - 3;
                x = object->draw_x;
                break;
              case 2u:
              case 6u:
                frame_id = *v36;
                y = object->draw_y;
                goto LABEL_904;
              case 3u:
              case 5u:
                frame_id = *v36;
                y = object->draw_y + 3;
                x = object->draw_x;
                break;
              case 4u:
                frame_id = *v36;
                y = object->draw_y + 5;
                x = object->draw_x;
                break;
              default:
                goto LABEL_907;
            }
            goto LABEL_905;
          case coffin:
            frame_id = current_season == 3;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case grave:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case zombie_tomb:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case trap_detected:
            if ( object->state_id == 36 )
            {
              v38 = d_spike_mfb;
              if ( object->mfb_file == d_spike_mfb )
                goto LABEL_855;
            }
            else
            {
              v38 = d_flame_mfb;
              if ( object->mfb_file == d_flame_mfb )
                goto LABEL_855;
            }
            SetObjectMFBFile(object, v38);
LABEL_855:
            v16 = object->data8[2];
LABEL_902:
            v14 = v16 >> 2;
LABEL_903:
            frame_id = v14;
            y = object->draw_y;
            goto LABEL_904;
          case none_C4:
            v39 = object->gen_period + 16;
            frame_id = ((unsigned __int8)(object->data8[2] & 0xC) >> 2)
                     + 4 * (((HIDWORD(v39) ^ (unsigned __int8)abs(object->gen_period + 16)) - HIDWORD(v39)) / 32);
            y = object->draw_y;
            goto LABEL_904;
          case none_C5:
            if ( !object->state_id )
            {
              v40 = shadow_mfb;
              if ( object->mfb_file == shadow_mfb )
                goto LABEL_864;
              goto LABEL_863;
            }
            if ( object->state_id == 1 )
            {
              v40 = rockshad_mfb;
              if ( object->mfb_file != rockshad_mfb )
              {
LABEL_863:
                SetObjectMFBFile(object, v40);
                goto LABEL_864;
              }
            }
LABEL_864:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
LABEL_905:
            v6 = object->mfb_file;
LABEL_906:
            DrawTexture(v6, x, y, frame_id, 1);
LABEL_907:
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
                v46 = object->data7[1];
                if ( v46 == 1 )
                {
                  artminis_mfb->frame_id = 13;
                }
                else if ( v46 == 2 )
                {
                  artminis_mfb->frame_id = 11;
                }
              }
            }
            else
            {
              v47 = object->data9[5];
              if ( !v47 )
                goto LABEL_933;
              switch ( v47 )
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
LABEL_933:
            v48 = object->unk13;
            if ( v48 && v48 & (1 << cur_player) )
              sub_43F170((int)object);
            byte_4842BC = Player->player_id_2;
            if ( object == cur_object )
            {
              switch ( byte_5F746C[0] )
              {
                case 0x20u:
                  v49 = object->class_id;
                  if ( *(_DWORD *)((char *)&unk_663578 + 914 * v49) )
                  {
                    DrawTexture(
                      magnify_mfb,
                      object->field_C2 / 2 + object->field_BE / 2,
                      object->field_C0 / 2 + object->field_C4 / 2,
                      255,
                      1);
                  }
                  else if ( v49 == 70 )
                  {
                    urotate_mfb->frame_id = dword_48445C;
                    DrawTexture(
                      urotate_mfb,
                      object->field_C2 / 2 + object->field_BE / 2,
                      object->field_C0 / 2 + object->field_C4 / 2,
                      255,
                      1);
                  }
                  else
                  {
                    hand_mfb->frame_id = dword_48445C;
                    DrawTexture(
                      hand_mfb,
                      object->field_C2 / 2 + object->field_BE / 2,
                      object->field_C0 / 2 + object->field_C4 / 2,
                      255,
                      1);
                  }
                  break;
                case 0x22u:
                  capture_mfb->frame_id = dword_484464;
                  DrawTexture(
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
                    DrawTexture(
                      torch_mfb,
                      object->field_C2 / 2 + object->field_BE / 2,
                      object->field_C0 / 2 + object->field_C4 / 2,
                      255,
                      1);
                  }
                  else
                  {
                    ufight_mfb->frame_id = 0;
                    DrawTexture(
                      ufight_mfb,
                      object->field_C2 / 2 + object->field_BE / 2,
                      object->field_C0 / 2 + object->field_C4 / 2,
                      255,
                      1);
                  }
                  break;
                case 0x24u:
                  DrawTexture(
                    uguild_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    dword_484464,
                    1);
                  break;
                case 0x25u:
                  utame_mfb->frame_id = dword_484464;
                  DrawTexture(
                    utame_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x26u:
                  urotate_mfb->frame_id = dword_48445C;
                  DrawTexture(
                    urotate_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x27u:
                  capture_mfb->frame_id = dword_484464;
                  DrawTexture(
                    capture_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x28u:
                  ueat_mfb->frame_id = dword_484468;
                  DrawTexture(
                    ueat_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x29u:
                  capture_mfb->frame_id = dword_484464;
                  DrawTexture(
                    capture_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x2Au:
                  if ( *(_DWORD *)((char *)&unk_663578 + 914 * object->class_id) )
                    DrawTexture(
                      magnify_mfb,
                      object->field_C2 / 2 + object->field_BE / 2,
                      object->field_C0 / 2 + object->field_C4 / 2,
                      255,
                      1);
                  break;
                case 0x2Bu:
                  hand_mfb->frame_id = dword_48445C;
                  DrawTexture(
                    hand_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x2Cu:
                  DrawTexture(
                    uleave_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    dword_484464,
                    1);
                  break;
                case 0x2Du:
                  DrawTexture(
                    unoguild_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    dword_484464,
                    1);
                  break;
                case 0x2Eu:
                  urepair_mfb->frame_id = dword_484464;
                  DrawTexture(
                    urepair_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x2Fu:
                  ufight_mfb->frame_id = dword_484464;
                  DrawTexture(
                    ufight_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                case 0x30u:
                  capture_mfb->frame_id = dword_484464;
                  DrawTexture(
                    capture_mfb,
                    object->field_C2 / 2 + object->field_BE / 2,
                    object->field_C0 / 2 + object->field_C4 / 2,
                    255,
                    1);
                  break;
                default:
                  return;
              }
            }
            break;
          case magic_gate:
            v41 = object->field_F2;
            if ( v41 == 106 )
            {
              frame_id = 5;
              y = object->draw_y;
              x = object->draw_x;
            }
            else if ( v41 == 108 || v41 == 109 )
            {
              frame_id = object->frame;
              y = object->draw_y;
LABEL_904:
              x = object->draw_x;
            }
            else
            {
              frame_id = 0;
              y = object->draw_y;
              x = object->draw_x;
            }
            goto LABEL_905;
          case none_C9:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case explosion:
            frame_id = object->frame >> 1;
            y = object->draw_y;
            goto LABEL_904;
          case none_CD:
            frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case footmans_guild:
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, 0, 1);
            if ( object->unk32 & 0x20000 )
              DrawTexture(footdoor_mfb, object->draw_x, object->draw_y, 255, 1);
            if ( object->unk32 & 0x80000 )
            {
              aargh_mfb->frame_id = object->data8[2] % 0x15u / 3;
              DrawTexture(aargh_mfb, object->draw_x - 50, object->draw_y, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 75, object->draw_y - 10, 255, 1);
              DrawTexture(aargh_mfb, object->draw_x - 40, object->draw_y - 40, 255, 1);
            }
            goto LABEL_907;
          case none_D1:
            v42 = object->gen_period + 16;
            frame_id = ((unsigned __int8)(object->data8[2] & 0xC) >> 2)
                     + 4 * (((HIDWORD(v42) ^ (unsigned __int8)abs(object->gen_period + 16)) - HIDWORD(v42)) / 32);
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case lever:
            frame_id = object->frame;
            y = object->draw_y;
            goto LABEL_904;
          case target:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case fountain_of_youth:
            if ( current_season == 3 )
              frame_id = 2;
            else
              frame_id = 0;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case shrubbery:
            frame_id = object->state_id;
            y = object->draw_y;
            goto LABEL_904;
          case chair:
            frame_id = object->state_id;
            y = object->draw_y;
            goto LABEL_904;
          case dark_altar:
            frame_id = current_season == 3;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case weird_tree:
            frame_id = object->state_id;
            y = object->draw_y;
            goto LABEL_904;
          case graveyard_fence:
            frame_id = 255;
            object->mfb_file->frame_id = object->frame;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case graveyard_fence1:
            frame_id = object->state_id;
            y = object->draw_y;
            goto LABEL_904;
          case lookout_post:
            v43 = (int *)&object->draw_y;
            v44 = (int *)&object->draw_x;
            DrawTexture(object->mfb_file, object->draw_x, object->draw_y, current_season == 3, 1);
            if ( object->unk225 )
            {
              bellring_mfb->frame_id = (unsigned __int8)(object->data8[2] & 0xC) >> 2;
              DrawTexture(bellring_mfb, *v44, *v43, 255, 1);
            }
            else
            {
              DrawTexture(look_ov_mfb, *v44, *v43, object->frame, 1);
            }
            goto LABEL_907;
          case none_DE:
            DrawTexture(fireball_mfb, object->draw_x, object->draw_y, 0, 1);
            v16 = object->data8[2];
            goto LABEL_902;
          case none_DF:
            v45 = object->gen_period + 16;
            frame_id = ((HIDWORD(v45) ^ (unsigned __int8)abs(object->gen_period + 16)) - HIDWORD(v45)) / 32;
            y = object->draw_y;
            goto LABEL_904;
          case none_E0:
            v16 = object->data8[2];
            goto LABEL_902;
          case none_E2:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_E3:
            frame_id = object->data8[2] >> 2;
            y = object->draw_y;
            goto LABEL_904;
          case none_E4:
            frame_id = 255;
            y = object->draw_y;
            x = object->draw_x;
            goto LABEL_905;
          case none_E5:
            frame_id = object->state_id;
            y = object->draw_y;
            goto LABEL_904;
          default:
            goto LABEL_907;
        }
      }
    }
  }
}