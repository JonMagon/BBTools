void __thiscall Objects::GetMFB(MapObject *object)
{
  int v1; // eax

  object->mfb_file = crate_mfb;
  switch ( object->class_id )
  {
    case tree:
      object->mfb_file = bigfir_mfb;
      break;
    case church:
      object->mfb_file = church_mfb;
      break;
    case peasant_hut:
      object->mfb_file = peashut_mfb;
      break;
    case tree1:
      object->mfb_file = tree02_mfb;
      break;
    case tree2:
      object->mfb_file = tree10_mfb;
      break;
    case fire:
      object->mfb_file = flames_mfb;
      break;
    case none_09:
      object->mfb_file = crate_mfb;
      break;
    case none_0A:
      object->mfb_file = (MFBEntry *)unk_60232C;
      break;
    case none_10:
      object->mfb_file = crate_mfb;
      break;
    case none_18:
      object->mfb_file = (MFBEntry *)unk_5F9194;
      break;
    case crate:
      object->mfb_file = crate_mfb;
      break;
    case none_1A:
      object->mfb_file = probe_mfb;
      break;
    case none_1C:
      object->mfb_file = crate_mfb;
      break;
    case stone_wall:
      object->mfb_file = wall_mfb;
      break;
    case none_21:
      object->mfb_file = breeder_mfb;
      break;
    case none_22:
      object->mfb_file = gas_mfb;
      break;
    case spike_trap:
      object->mfb_file = spike_mfb;
      break;
    case mine:
      object->mfb_file = skulls_mfb;
      break;
    case none_26:
      object->mfb_file = gasmold_mfb;
      break;
    case street_lamp:
      object->mfb_file = lamp_mfb;
      break;
    case none_28:
      object->mfb_file = skulls_mfb;
      break;
    case none_29:
      object->mfb_file = airstrik_mfb;
      break;
    case none_2A:
      object->mfb_file = cloud_mfb;
      break;
    case none_2B:
      object->mfb_file = cloud_mfb;
      break;
    case none_2C:
      object->mfb_file = equake_mfb;
      break;
    case none_2E:
      object->mfb_file = (MFBEntry *)unk_6045F0;
      break;
    case well:
      object->mfb_file = well_mfb;
      break;
    case none_30:
      object->mfb_file = logs_mfb;
      break;
    case none_31:
      object->mfb_file = stump_mfb;
      break;
    case none_32:
      object->mfb_file = flag_mfb;
      break;
    case farm:
      object->mfb_file = farm_mfb;
      break;
    case bakery:
      object->mfb_file = bakery_mfb;
      break;
    case brewery:
      object->mfb_file = brewery_mfb;
      break;
    case none_37:
      object->mfb_file = rocks_mfb;
      break;
    case none_38:
      object->mfb_file = flames_mfb;
      break;
    case none_39:
      object->mfb_file = cross_mfb;
      break;
    case corpse:
      object->mfb_file = d_male_mfb;
      break;
    case none_3C:
      object->mfb_file = bench_mfb;
      break;
    case oil:
      object->mfb_file = oilslick_mfb;
      break;
    case none_3E:
      object->mfb_file = glue_mfb;
      break;
    case none_3F:
      object->mfb_file = crate_mfb;
      break;
    case none_40:
      object->mfb_file = crate_mfb;
      break;
    case town_hall:
      object->mfb_file = th_nodo_mfb;
      break;
    case none_43:
      object->mfb_file = firebomb_mfb;
      break;
    case none_44:
      object->mfb_file = shrapnel_mfb;
      break;
    case builders_guild:
      object->mfb_file = toolshed_mfb;
      break;
    case none_46:
      object->mfb_file = armed_mfb;
      break;
    case none_47:
      object->mfb_file = cbolt_mfb;
      break;
    case none_48:
      object->mfb_file = c_target_mfb;
      break;
    case none_49:
      object->mfb_file = chapel_mfb;
      break;
    case none_4A:
      object->mfb_file = bridge_mfb;
      break;
    case tower:
      object->mfb_file = treehous_mfb;
      break;
    case none_4C:
      object->mfb_file = barrack_mfb;
      break;
    case none_4D:
      object->mfb_file = miniflag_mfb;
      break;
    case wheat:
      object->mfb_file = crops_mfb;
      break;
    case apple_tree:
      object->mfb_file = appltree_mfb;
      break;
    case none_50:
      object->mfb_file = thumper_mfb;
      break;
    case none_51:
      object->mfb_file = towreal_mfb;
      break;
    case none_52:
      object->mfb_file = snicket_mfb;
      break;
    case _mushroom:
      object->mfb_file = poison_mfb;
      break;
    case none_54:
      object->mfb_file = worm_mfb;
      break;
    case none_55:
      object->mfb_file = turf_mfb;
      break;
    case wizards_guild:
      object->mfb_file = summon_mfb;
      break;
    case none_57:
      object->mfb_file = pile01_mfb;
      break;
    case none_58:
      object->mfb_file = pile02_mfb;
      break;
    case none_59:
      object->mfb_file = pile03_mfb;
      break;
    case none_5A:
      object->mfb_file = pile04_mfb;
      break;
    case none_5B:
      object->mfb_file = bombman_mfb;
      break;
    case none_5C:
      object->mfb_file = bushman_mfb;
      break;
    case flame_trap:
      object->mfb_file = flamedev_mfb;
      break;
    case apple_tree1:
      object->mfb_file = appsprig_mfb;
      break;
    case chick:
      object->mfb_file = chickegg_mfb;
      break;
    case baby_cow:
      object->mfb_file = cowborn_mfb;
      break;
    case none_61:
      object->mfb_file = wheatovr_mfb;
      break;
    case flagpost:
      object->mfb_file = owner_mfb;
      break;
    case none_63:
      object->mfb_file = pile05_mfb;
      break;
    case none_64:
      object->mfb_file = (MFBEntry *)unk_5E42C8;
      break;
    case none_66:
      object->mfb_file = (MFBEntry *)unk_5C77A0;
      break;
    case villager:
      object->mfb_file = villager_mfb;
      break;
    case creature:
      object->mfb_file = villager_mfb;
      break;
    case none_6A:
      object->mfb_file = (MFBEntry *)unk_6A9088;
      break;
    case none_6C:
      object->mfb_file = zombie_mfb;
      break;
    case cow:
      object->mfb_file = cowwalk_mfb;
      break;
    case chicken:
      object->mfb_file = chikfeld_mfb;
      break;
    case peasant_hut1:
      object->mfb_file = peashut_mfb;
      break;
    case rockpile:
      object->mfb_file = pick_mfb;
      break;
    case woodpile:
      object->mfb_file = saw_mfb;
      break;
    case hammer_point:
      object->mfb_file = saw_mfb;
      break;
    case bakery1:
      object->mfb_file = bakery_mfb;
      break;
    case well1:
      object->mfb_file = well_mfb;
      break;
    case farm1:
      object->mfb_file = farm_mfb;
      break;
    case stone_wall1:
      object->mfb_file = wall_mfb;
      break;
    case builders_guild1:
      object->mfb_file = toolshed_mfb;
      break;
    case brewery1:
      object->mfb_file = brewery_mfb;
      break;
    case town_hall1:
      object->mfb_file = th_nodo_mfb;
      break;
    case church1:
      object->mfb_file = church_mfb;
      break;
    case none_80:
      object->mfb_file = armed_mfb;
      break;
    case fence:
      object->mfb_file = fence_mfb;
      break;
    case fence1:
      object->mfb_file = fence_mfb;
      break;
    case none_83:
      object->mfb_file = appltree_mfb;
      break;
    case none_84:
      object->mfb_file = spirt_mfb;
      break;
    case young_tree:
      object->mfb_file = sap_fir_mfb;
      break;
    case none_87:
      object->mfb_file = castle_mfb;
      break;
    case none_88:
      object->mfb_file = cabin_mfb;
      break;
    case none_89:
      object->mfb_file = cabin_mfb;
      break;
    case none_8A:
      object->mfb_file = execblok_mfb;
      break;
    case none_8C:
      object->mfb_file = crate_mfb;
      break;
    case none_8D:
      object->mfb_file = crate_mfb;
      break;
    case none_8E:
      object->mfb_file = rocks_mfb;
      break;
    case campfire:
      object->mfb_file = campfire_mfb;
      break;
    case spring:
      object->mfb_file = crate_mfb;
      break;
    case archers_guild:
      object->mfb_file = fletcher_mfb;
      break;
    case archers_guild1:
      object->mfb_file = fletcher_mfb;
      break;
    case none_93:
      object->mfb_file = shoot_mfb;
      break;
    case none_94:
      object->mfb_file = mace_mfb;
      break;
    case none_95:
      object->mfb_file = electro_mfb;
      break;
    case minstrels_guild:
      object->mfb_file = tent_mfb;
      break;
    case minstrels_guild1:
      object->mfb_file = tent_mfb;
      break;
    case knights_guild:
      object->mfb_file = keep_mfb;
      break;
    case knights_guild1:
      object->mfb_file = keep_mfb;
      break;
    case prison:
      object->mfb_file = jail_mfb;
      break;
    case prison1:
      object->mfb_file = jail_mfb;
      break;
    case none_9C:
      object->mfb_file = acidbolt_mfb;
      break;
    case stables:
      object->mfb_file = stables_mfb;
      break;
    case stables1:
      object->mfb_file = stables_mfb;
      break;
    case silver_goblet:
      object->mfb_file = gob_silv_mfb;
      break;
    case potion:
      v1 = object->field_F2;
      switch ( v1 )
      {
        case 84:
          object->mfb_file = pot_red_mfb;
          break;
        case 85:
          object->mfb_file = pot_gren_mfb;
          break;
        case 86:
          object->mfb_file = pot_blue_mfb;
          break;
      }
      break;
    case gold:
      object->mfb_file = goldcoin_mfb;
      break;
    case temple:
      object->mfb_file = pagnbulk_mfb;
      break;
    case rock:
      object->mfb_file = paganrok_mfb;
      break;
    case none_A4:
      object->mfb_file = sword_mfb;
      break;
    case none_A6:
      object->mfb_file = catapult_mfb;
      break;
    case gate:
      object->mfb_file = gate_mfb;
      break;
    case gate1:
      object->mfb_file = gate_mfb;
      break;
    case generator:
      object->mfb_file = crate_mfb;
      break;
    case gold_goblet:
      object->mfb_file = gob_gold_mfb;
      break;
    case none_AD:
      object->mfb_file = flag_mfb;
      break;
    case holy_sword:
      object->mfb_file = holyswrd_mfb;
      break;
    case wizards_guild1:
      object->mfb_file = summon_mfb;
      break;
    case magic_scroll:
      object->mfb_file = tablets_mfb;
      break;
    case helmet_of_strength:
      object->mfb_file = helmet_mfb;
      break;
    case ring_of_fire_protection:
      object->mfb_file = magring_mfb;
      break;
    case coffin:
      object->mfb_file = grave_mfb;
      break;
    case grave:
      object->mfb_file = grave_mfb_dub;
      break;
    case zombie_tomb:
      object->mfb_file = zombtomb_mfb;
      break;
    case shield_of_the_gods:
      object->mfb_file = shield_mfb;
      break;
    case crucifix:
      object->mfb_file = crucifix_mfb;
      break;
    case trap_detected:
      object->mfb_file = d_spike_mfb;
      break;
    case none_C3:
      object->mfb_file = s_tport_mfb;
      break;
    case none_C4:
      object->mfb_file = s_fireb_mfb;
      break;
    case none_C5:
      object->mfb_file = shadow_mfb;
      break;
    case magic_key:
      object->mfb_file = mkey_mfb;
      break;
    case magic_gate:
      object->mfb_file = mgate_mfb;
      break;
    case shovel:
      object->mfb_file = shovel_mfb;
      break;
    case none_C9:
      object->mfb_file = rocks_mfb;
      break;
    case smoke:
      object->mfb_file = missmoke_mfb;
      break;
    case explosion:
      object->mfb_file = explode_mfb;
      break;
    case smoke1:
      object->mfb_file = smolder_mfb;
      break;
    case none_CD:
      object->mfb_file = rocks_mfb;
      break;
    case path:
      object->mfb_file = crate_mfb;
      break;
    case footmans_guild:
      object->mfb_file = fguild_mfb;
      break;
    case footmans_guild1:
      object->mfb_file = fguild_mfb;
      break;
    case none_D1:
      object->mfb_file = ogrefire_mfb;
      break;
    case lever:
      object->mfb_file = lever_mfb;
      break;
    case cloak_of_invisibility:
      object->mfb_file = cloak_mfb;
      break;
    case ring_of_absolute_power:
      object->mfb_file = power_mfb;
      break;
    case target:
      object->mfb_file = trigger_mfb;
      break;
    case fountain_of_youth:
      object->mfb_file = youth_mfb;
      break;
    case shrubbery:
      object->mfb_file = shrub_mfb;
      break;
    case chair:
      object->mfb_file = logchair_mfb;
      break;
    case dark_altar:
      object->mfb_file = altar_mfb;
      break;
    case weird_tree:
      object->mfb_file = spooky_mfb;
      break;
    case graveyard_fence:
      object->mfb_file = gfence_mfb;
      break;
    case graveyard_fence1:
      object->mfb_file = special_mfb;
      break;
    case lookout_post:
      object->mfb_file = lookout_mfb;
      break;
    case none_DE:
      object->mfb_file = flames_mfb;
      break;
    case none_DF:
      object->mfb_file = s_see_mfb;
      break;
    case none_E0:
      object->mfb_file = s_fear_mfb;
      break;
    case lookout_post1:
      object->mfb_file = lookout_mfb;
      break;
    case none_E2:
      object->mfb_file = hive_mfb;
      break;
    case none_E3:
      object->mfb_file = s_ffood_mfb;
      break;
    case none_E4:
      object->mfb_file = ship_mfb;
      break;
    case none_E5:
      object->mfb_file = rubble_mfb;
      break;
    case none_E6:
      object->mfb_file = s_flash_mfb;
      break;
    case none_E7:
      object->mfb_file = s_cure_mfb;
      break;
    default:
      return;
  }
}