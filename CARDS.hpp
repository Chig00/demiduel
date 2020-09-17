// Fighter Cards
//{
// Driver Family
//{
// Fire Driver Family
//{
// Driver
//{
constexpr const char* DRIVER_NAME = "Driver";
constexpr const char* DRIVER_ELEMENT = FIRE_ELEMENT;
constexpr int DRIVER_HEALTH = 1000;
constexpr int DRIVER_RETREAT_COST = 1000;
constexpr const char* DRIVER_OLD_RANK = NO_OLD_RANK;
constexpr const char* DRIVER_ABILITY_NAME = "Fuel Conversion";
constexpr const char* DRIVER_ABILITY_DESCRIPTION =
	"When this fighter ranks up, convert all of energy cards attached "
	"to this fighter to the element of the new rank."
;
const std::string DRIVER_ABILITY_EFFECTS(
	std::string(RANK_UP_EFFECT) // rank_up
	+ EFFECT_SEPARATOR          //
	+ CONVERSION_EFFECT         // conversion
);
constexpr bool DRIVER_ABILITY_PASSIVE = true;
constexpr int DRIVER_ABILITY_USES = PASSIVE_USES;
constexpr const char* DRIVER_ATTACK_NAME = "Drift";
constexpr const char* DRIVER_ATTACK_DESCRIPTION =
	"Deal 250 damage to your opponent's active fighter."
;
constexpr const char* DRIVER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int DRIVER_ATTACK_DAMAGE = 250;
constexpr int DRIVER_ATTACK_COST = 0;
//}

// Racer
//{
constexpr const char* RACER_NAME = "Racer";
constexpr const char* RACER_ELEMENT = FIRE_ELEMENT;
constexpr int RACER_HEALTH = 1200;
constexpr int RACER_RETREAT_COST = 1000;
constexpr const char* RACER_OLD_RANK = DRIVER_NAME;
constexpr const char* RACER_ABILITY_NAME = "Acceleration";
constexpr const char* RACER_ABILITY_DESCRIPTION =
	"Once a turn, you may switch this fighter in from the bench.\n"
	"If you do, this fighter deals 125 more damage this turn."
;
const std::string RACER_ABILITY_EFFECTS(
	std::string(SWITCH_IN_EFFECT) // switch_in
	+ EFFECT_SEPARATOR            //
	+ POWER_EFFECT                // power
	+ EFFECT_SEPARATOR            //
	+ "125"                       // 125
);
constexpr bool RACER_ABILITY_PASSIVE = false;
constexpr int RACER_ABILITY_USES = 1;
constexpr const char* RACER_ATTACK_NAME = "Nitro Boost";
constexpr const char* RACER_ATTACK_DESCRIPTION =
	"Deal 425 damage to your opponent's active fighter."
;
constexpr const char* RACER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int RACER_ATTACK_DAMAGE = 425;
constexpr int RACER_ATTACK_COST = 1000;
//}

// Hot Rodder
//{
constexpr const char* HOT_RODDER_NAME = "Hot Rodder";
constexpr const char* HOT_RODDER_ELEMENT = FIRE_ELEMENT;
constexpr int HOT_RODDER_HEALTH = 1400;
constexpr int HOT_RODDER_RETREAT_COST = 1000;
constexpr const char* HOT_RODDER_OLD_RANK = RACER_NAME;
constexpr const char* HOT_RODDER_ABILITY_NAME = "Charged Thruster";
constexpr const char* HOT_RODDER_ABILITY_DESCRIPTION =
	"Once a turn, you may switch this fighter in from the bench.\n"
	"If you do, this fighter deals 250 more damage this turn."
;
const std::string HOT_RODDER_ABILITY_EFFECTS(
	std::string(SWITCH_IN_EFFECT) // switch_in
	+ EFFECT_SEPARATOR            //
	+ POWER_EFFECT                // power
	+ EFFECT_SEPARATOR            //
	+ "250"                       // 250
);
constexpr bool HOT_RODDER_ABILITY_PASSIVE = false;
constexpr int HOT_RODDER_ABILITY_USES = 1;
constexpr const char* HOT_RODDER_ATTACK_NAME = "Super Nitro";
constexpr const char* HOT_RODDER_ATTACK_DESCRIPTION =
	"Deal 500 damage to your opponent's active fighter."
;
constexpr const char* HOT_RODDER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int HOT_RODDER_ATTACK_DAMAGE = 500;
constexpr int HOT_RODDER_ATTACK_COST = 2000;
//}
//}

// Water Driver Family
//{
// Sailor
//{
constexpr const char* SAILOR_NAME = "Sailor";
constexpr const char* SAILOR_ELEMENT = WATER_ELEMENT;
constexpr int SAILOR_HEALTH = 1200;
constexpr int SAILOR_RETREAT_COST = 1000;
constexpr const char* SAILOR_OLD_RANK = DRIVER_NAME;
constexpr const char* SAILOR_ABILITY_NAME = "Sailor's Compass";
constexpr const char* SAILOR_ABILITY_DESCRIPTION =
	"Once a turn, you may draw a card."
;
const std::string SAILOR_ABILITY_EFFECTS(
	std::string(DRAW_EFFECT) // draw
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
);
constexpr bool SAILOR_ABILITY_PASSIVE = false;
constexpr int SAILOR_ABILITY_USES = 1;
constexpr const char* SAILOR_ATTACK_NAME = "Torpedo";
constexpr const char* SAILOR_ATTACK_DESCRIPTION =
	"Deal 300 damage to one of your opponent's fighters."
;
const std::string SAILOR_ATTACK_EFFECTS(
	std::string(SNIPE_EFFECT) // snipe
	+ EFFECT_SEPARATOR        //
	+ "300"                   // 300
);
constexpr int SAILOR_ATTACK_DAMAGE = 0;
constexpr int SAILOR_ATTACK_COST = 1000;
//}

// Pirate
//{
constexpr const char* PIRATE_NAME = "Pirate";
constexpr const char* PIRATE_ELEMENT = WATER_ELEMENT;
constexpr int PIRATE_HEALTH = 1300;
constexpr int PIRATE_RETREAT_COST = 2000;
constexpr const char* PIRATE_OLD_RANK = SAILOR_NAME;
constexpr const char* PIRATE_ABILITY_NAME = "Plundered";
constexpr const char* PIRATE_ABILITY_DESCRIPTION =
	"Once a turn, you may search your deck for a card and draw it."
;
const std::string PIRATE_ABILITY_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
);
constexpr bool PIRATE_ABILITY_PASSIVE = false;
constexpr int PIRATE_ABILITY_USES = 1;
constexpr const char* PIRATE_ATTACK_NAME = "Plank Walk";
constexpr const char* PIRATE_ATTACK_DESCRIPTION =
	"Deal 300 damage to one of your opponent's fighters.\n"
	"Deal 50 extra damage to non-water element fighters."
;
const std::string PIRATE_ATTACK_EFFECTS(
	std::string(SNIPE_EFFECT) // snipe
	+ EFFECT_SEPARATOR        //
	+ "350"                   // 350
	+ EFFECT_SEPARATOR        //
	+ POWER_EFFECT            // power
	+ EFFECT_SEPARATOR        //
	+ WATER_ELEMENT           // Water
	+ EFFECT_SEPARATOR        //
	+ "-50"                   // -50
);
constexpr int PIRATE_ATTACK_DAMAGE = 0;
constexpr int PIRATE_ATTACK_COST = 1000;
//}
//}

// Earth Driver Family
//{
// Dirt Biker
//{
constexpr const char* DIRT_BIKER_NAME = "Dirt Biker";
constexpr const char* DIRT_BIKER_ELEMENT = EARTH_ELEMENT;
constexpr int DIRT_BIKER_HEALTH = 1250;
constexpr int DIRT_BIKER_RETREAT_COST = 1000;
constexpr const char* DIRT_BIKER_OLD_RANK = DRIVER_NAME;
constexpr const char* DIRT_BIKER_ABILITY_NAME = "Quick Fix";
constexpr const char* DIRT_BIKER_ABILITY_DESCRIPTION =
	"Once a turn, you may discard the top card of "
	"your deck and heal 200 damage from this fighter."
;
const std::string DIRT_BIKER_ABILITY_EFFECTS(
	std::string(MILL_EFFECT) // mill
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
	+ EFFECT_TERMINATOR
	+ HEAL_EFFECT            // heal
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "200"                  // 200
);
constexpr bool DIRT_BIKER_ABILITY_PASSIVE = false;
constexpr int DIRT_BIKER_ABILITY_USES = 1;
constexpr const char* DIRT_BIKER_ATTACK_NAME = "Shred";
constexpr const char* DIRT_BIKER_ATTACK_DESCRIPTION =
	"Deal 400 damage to your opponent's active fighter.\n"
	"Deal 8 more damage for each card in your trash."
;
const std::string DIRT_BIKER_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ TRASH_EFFECT            // trash
	+ EFFECT_SEPARATOR        //
	+ "8"                     // 8
);
constexpr int DIRT_BIKER_ATTACK_DAMAGE = 400;
constexpr int DIRT_BIKER_ATTACK_COST = 1000;
//}

// Monster Trucker
//{
constexpr const char* MONSTER_TRUCKER_NAME = "Monster Trucker";
constexpr const char* MONSTER_TRUCKER_ELEMENT = EARTH_ELEMENT;
constexpr int MONSTER_TRUCKER_HEALTH = 1500;
constexpr int MONSTER_TRUCKER_RETREAT_COST = 2000;
constexpr const char* MONSTER_TRUCKER_OLD_RANK = DIRT_BIKER_NAME;
constexpr const char* MONSTER_TRUCKER_ABILITY_NAME = "Scrap Metal";
constexpr const char* MONSTER_TRUCKER_ABILITY_DESCRIPTION =
	"Once a turn, you may discard the top card of "
	"your deck and heal 400 damage from this fighter."
;
const std::string MONSTER_TRUCKER_ABILITY_EFFECTS(
	std::string(MILL_EFFECT) // mill
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
	+ EFFECT_TERMINATOR
	+ HEAL_EFFECT            // heal
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "400"                  // 400
);
constexpr bool MONSTER_TRUCKER_ABILITY_PASSIVE = false;
constexpr int MONSTER_TRUCKER_ABILITY_USES = 1;
constexpr const char* MONSTER_TRUCKER_ATTACK_NAME = "Crush";
constexpr const char* MONSTER_TRUCKER_ATTACK_DESCRIPTION =
	"Deal 500 damage to your opponent's active fighter.\n"
	"Deal 15 more damage for each card in your trash."
;
const std::string MONSTER_TRUCKER_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ TRASH_EFFECT            // trash
	+ EFFECT_SEPARATOR        //
	+ "15"                    // 15
);
constexpr int MONSTER_TRUCKER_ATTACK_DAMAGE = 500;
constexpr int MONSTER_TRUCKER_ATTACK_COST = 2000;
//}
//}

// Air Driver Family
//{
// Pilot
//{
constexpr const char* PILOT_NAME = "Pilot";
constexpr const char* PILOT_ELEMENT = AIR_ELEMENT;
constexpr int PILOT_HEALTH = 1300;
constexpr int PILOT_RETREAT_COST = 1000;
constexpr const char* PILOT_OLD_RANK = DRIVER_NAME;
constexpr const char* PILOT_ABILITY_NAME = "Airborne";
constexpr const char* PILOT_ABILITY_DESCRIPTION =
	"Your fighters can retreat for 2000 less energy."
;
const std::string PILOT_ABILITY_EFFECTS(
	std::string(AGILITY_AURA_EFFECT) // agility_aura
	+ EFFECT_SEPARATOR               //
	+ "2000"                         // 2000
);
constexpr bool PILOT_ABILITY_PASSIVE = true;
constexpr int PILOT_ABILITY_USES = PASSIVE_USES;
constexpr const char* PILOT_ATTACK_NAME = "Divebomb";
constexpr const char* PILOT_ATTACK_DESCRIPTION =
	"Deal 375 damage to the defending fighter.\n"
	"It needs 1000 more energy to retreat next turn."
;
const std::string PILOT_ATTACK_EFFECTS(
	std::string(AGILITY_EFFECT) // agility
	+ EFFECT_SEPARATOR          //
	+ "-1000"                   // -1000
);
constexpr int PILOT_ATTACK_DAMAGE = 375;
constexpr int PILOT_ATTACK_COST = 1000;
//}

// Astronaut
//{
constexpr const char* ASTRONAUT_NAME = "Astronaut";
constexpr const char* ASTRONAUT_ELEMENT = AIR_ELEMENT;
constexpr int ASTRONAUT_HEALTH = 1600;
constexpr int ASTRONAUT_RETREAT_COST = 2000;
constexpr const char* ASTRONAUT_OLD_RANK = PILOT_NAME;
constexpr const char* ASTRONAUT_ABILITY_NAME = "Zero Gravity";
constexpr const char* ASTRONAUT_ABILITY_DESCRIPTION =
	"Your fighters can retreat for 2000 less energy.\n"
	"You can retreat your fighters as often as you like."
;
const std::string ASTRONAUT_ABILITY_EFFECTS(
	std::string(AGILITY_AURA_EFFECT) // agility_aura
	+ EFFECT_SEPARATOR               //
	+ "2000"                         // 2000
	+ EFFECT_TERMINATOR
	+ FREEDOM_EFFECT                 // freedom
);
constexpr bool ASTRONAUT_ABILITY_PASSIVE = true;
constexpr int ASTRONAUT_ABILITY_USES = PASSIVE_USES;
constexpr const char* ASTRONAUT_ATTACK_NAME = "Gravity Flip";
constexpr const char* ASTRONAUT_ATTACK_DESCRIPTION =
	"Deal 500 damage to the defending fighter.\n"
	"It needs 2000 more energy to retreat next turn."
;
const std::string ASTRONAUT_ATTACK_EFFECTS(
	std::string(AGILITY_EFFECT) // agility
	+ EFFECT_SEPARATOR          //
	+ "-2000"                   // -2000
);
constexpr int ASTRONAUT_ATTACK_DAMAGE = 500;
constexpr int ASTRONAUT_ATTACK_COST = 1000;
//}
//}
//}

// Mage Family
//{
// Mage
//{
constexpr const char* MAGE_NAME = "Mage";
constexpr const char* MAGE_ELEMENT = AIR_ELEMENT;
constexpr int MAGE_HEALTH = 900;
constexpr int MAGE_RETREAT_COST = 1000;
constexpr const char* MAGE_OLD_RANK = NO_OLD_RANK;
constexpr const char* MAGE_ABILITY_NAME = "Adaptability";
constexpr const char* MAGE_ABILITY_DESCRIPTION =
	"This fighter can use energy of any element."
;
constexpr const char* MAGE_ABILITY_EFFECTS = ADAPTABILITY_EFFECT; // adaptability
constexpr bool MAGE_ABILITY_PASSIVE = true;
constexpr int MAGE_ABILITY_USES = PASSIVE_USES;
constexpr const char* MAGE_ATTACK_NAME = "Magic Missles";
constexpr const char* MAGE_ATTACK_DESCRIPTION =
	"Deal 300 damage in 150 damage bursts to your opponent's "
	"fighters in a distribution of your choosing."
;
const std::string MAGE_ATTACK_EFFECTS(
	std::string(SNIPE_EFFECT) // snipe
	+ EFFECT_SEPARATOR        //
	+ "150"                   // 150
	+ EFFECT_TERMINATOR
	+ SNIPE_EFFECT            // snipe
	+ EFFECT_SEPARATOR        //
	+ "150"                   // 150
);
constexpr int MAGE_ATTACK_DAMAGE = 0;
constexpr int MAGE_ATTACK_COST = 1000;
//}

// Pyromancer
//{
constexpr const char* PYROMANCER_NAME = "Pyromancer";
constexpr const char* PYROMANCER_ELEMENT = FIRE_ELEMENT;
constexpr int PYROMANCER_HEALTH = 1250;
constexpr int PYROMANCER_RETREAT_COST = 2000;
constexpr const char* PYROMANCER_OLD_RANK = MAGE_NAME;
constexpr const char* PYROMANCER_ABILITY_NAME = "Incinerate";
constexpr const char* PYROMANCER_ABILITY_DESCRIPTION =
	"Once a turn, you may discard the top 2 cards of "
	"both players' decks and search your deck for a card."
;
const std::string PYROMANCER_ABILITY_EFFECTS(
	std::string(MILL_EFFECT) // mill
	+ EFFECT_SEPARATOR       //
	+ "2"                    // 2
	+ EFFECT_TERMINATOR
	+ MILL_EFFECT            // mill
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "2"                    // 2
	+ EFFECT_TERMINATOR
	+ SEARCH_EFFECT          // search
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
);
constexpr bool PYROMANCER_ABILITY_PASSIVE = false;
constexpr int PYROMANCER_ABILITY_USES = 1;
constexpr const char* PYROMANCER_ATTACK_NAME = "Heat Wave";
constexpr const char* PYROMANCER_ATTACK_DESCRIPTION =
	"Deal 200 damage to all other fighters."
;
const std::string PYROMANCER_ATTACK_EFFECTS(
	std::string(SPLASH_EFFECT) // splash
	+ EFFECT_SEPARATOR         //
	+ "200"                    // 200
	+ EFFECT_TERMINATOR
	+ SPLASH_EFFECT            // splash
	+ EFFECT_SEPARATOR         //
	+ SELF_EFFECT              // self
	+ EFFECT_SEPARATOR         //
	+ "200"                    // 200
);
constexpr int PYROMANCER_ATTACK_DAMAGE = 200;
constexpr int PYROMANCER_ATTACK_COST = 0;
//}

// Warlock
//{
constexpr const char* WARLOCK_NAME = "Warlock";
constexpr const char* WARLOCK_ELEMENT = EARTH_ELEMENT;
constexpr int WARLOCK_HEALTH = 1150;
constexpr int WARLOCK_RETREAT_COST = 2000;
constexpr const char* WARLOCK_OLD_RANK = MAGE_NAME;
constexpr const char* WARLOCK_ABILITY_NAME = "Dark Bargain";
constexpr const char* WARLOCK_ABILITY_DESCRIPTION =
	"You may banish a random fighter in your trash that ranks up into this one.\n"
	"If you do, search your trash for a card and draw it."
;
const std::string WARLOCK_ABILITY_EFFECTS(
	std::string(ABANDON_EFFECT) // abandon
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_SEPARATOR          //
	+ SEARCH_EFFECT             // search
	+ EFFECT_SEPARATOR          //
	+ TRASH_EFFECT              // trash
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
);
constexpr bool WARLOCK_ABILITY_PASSIVE = false;
constexpr int WARLOCK_ABILITY_USES = 1;
constexpr const char* WARLOCK_ATTACK_NAME = "Shadow Pulse";
constexpr const char* WARLOCK_ATTACK_DESCRIPTION =
	"Deal 750 damage to your opponent's active fighter.\n"
	"Deal 150 damage to this fighter."
;
const std::string WARLOCK_ATTACK_EFFECTS(
	std::string(RECOIL_EFFECT) // recoil
	+ EFFECT_SEPARATOR         //
	+ "150"                    // 150
);
constexpr int WARLOCK_ATTACK_DAMAGE = 750;
constexpr int WARLOCK_ATTACK_COST = 2000;
//}

// Cleric
//{
constexpr const char* CLERIC_NAME = "Cleric";
constexpr const char* CLERIC_ELEMENT = AIR_ELEMENT;
constexpr int CLERIC_HEALTH = 1350;
constexpr int CLERIC_RETREAT_COST = 2000;
constexpr const char* CLERIC_OLD_RANK = MAGE_NAME;
constexpr const char* CLERIC_ABILITY_NAME = "Healing Aura";
constexpr const char* CLERIC_ABILITY_DESCRIPTION =
	"At the end of your turn, heal 150 damage from each of your fighters."
;
const std::string CLERIC_ABILITY_EFFECTS(
	std::string(HEAL_AURA_EFFECT) // heal_aura
	+ EFFECT_SEPARATOR            //
	+ "150"                       // 150
);
constexpr bool CLERIC_ABILITY_PASSIVE = true;
constexpr int CLERIC_ABILITY_USES = PASSIVE_USES;
constexpr const char* CLERIC_ATTACK_NAME = "Radiant Pulse";
constexpr const char* CLERIC_ATTACK_DESCRIPTION =
	"Deal 400 damage to your opponent's active fighter.\n"
	"Heal 100 damage from this fighter."
;
const std::string CLERIC_ATTACK_EFFECTS(
	std::string(HEAL_EFFECT) // heal
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "100"                  // 100
);
constexpr int CLERIC_ATTACK_DAMAGE = 400;
constexpr int CLERIC_ATTACK_COST = 1000;
//}

// Hydromancer
//{
constexpr const char* HYDROMANCER_NAME = "Hydromancer";
constexpr const char* HYDROMANCER_ELEMENT = WATER_ELEMENT;
constexpr int HYDROMANCER_HEALTH = 1050;
constexpr int HYDROMANCER_RETREAT_COST = 1000;
constexpr const char* HYDROMANCER_OLD_RANK = MAGE_NAME;
constexpr const char* HYDROMANCER_ABILITY_NAME = "Whirlpool";
constexpr const char* HYDROMANCER_ABILITY_DESCRIPTION =
	"You may banish a random fighter in your trash that ranks up into this one.\n"
	"If you do, switch in one of your opponent's benched fighters.\n"
	"Your opponent's active fighter can't retreat during your opponent's next turn."
;
const std::string HYDROMANCER_ABILITY_EFFECTS(
	std::string(ABANDON_EFFECT) // abandon
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_SEPARATOR          //
	+ HOOK_EFFECT               // hook
	+ EFFECT_SEPARATOR          //
	+ CRIPPLE_EFFECT            // cripple
);
constexpr bool HYDROMANCER_ABILITY_PASSIVE = false;
constexpr int HYDROMANCER_ABILITY_USES = 1;
constexpr const char* HYDROMANCER_ATTACK_NAME = "Slipstream";
constexpr const char* HYDROMANCER_ATTACK_DESCRIPTION =
	"Deal 600 to your opponent's active fighter.\n"
	"Switch in a fighter from your bench."
;
constexpr const char* HYDROMANCER_ATTACK_EFFECTS = SWITCH_EFFECT; // switch
constexpr int HYDROMANCER_ATTACK_DAMAGE = 600;
constexpr int HYDROMANCER_ATTACK_COST = 1000;
//}
//}

// Ranker Family
//{
// Universal Ranker Ability Constants
//{
constexpr const char* RANKER_ABILITY_NAME = "Energy Acceleration";
constexpr const char* RANKER_ABILITY_DESCRIPTION =
	"Once a turn, you may attach a random energy card of "
	"this fighter's element in your deck to this fighter."
;
const std::string RANKER_ABILITY_EFFECTS(
	std::string(ACCELERATION_EFFECT) // accelerate
	+ EFFECT_SEPARATOR               //
	+ "1"                            // 1
);
constexpr bool RANKER_ABILITY_PASSIVE = false;
constexpr int RANKER_ABILITY_USES = 1;
//}

// Miner Family
//{
// Miner
//{
constexpr const char* MINER_NAME = "Miner";
constexpr const char* MINER_ELEMENT = EARTH_ELEMENT;
constexpr int MINER_HEALTH = 1100;
constexpr int MINER_RETREAT_COST = 1500;
constexpr const char* MINER_OLD_RANK = NO_OLD_RANK;
constexpr const char* MINER_ABILITY_NAME = RANKER_ABILITY_NAME;
constexpr const char* MINER_ABILITY_DESCRIPTION = RANKER_ABILITY_DESCRIPTION;
const std::string MINER_ABILITY_EFFECTS(RANKER_ABILITY_EFFECTS);
constexpr bool MINER_ABILITY_PASSIVE = RANKER_ABILITY_PASSIVE;
constexpr int MINER_ABILITY_USES = RANKER_ABILITY_USES;
constexpr const char* MINER_ATTACK_NAME = "Chip Away";
constexpr const char* MINER_ATTACK_DESCRIPTION =
	"Deal 250 damage to your opponent's active fighter."
;
constexpr const char* MINER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int MINER_ATTACK_DAMAGE = 250;
constexpr int MINER_ATTACK_COST = 1000;
//}

// Excavator
//{
constexpr const char* EXCAVATOR_NAME = "Excavator";
constexpr const char* EXCAVATOR_ELEMENT = EARTH_ELEMENT;
constexpr int EXCAVATOR_HEALTH = 1400;
constexpr int EXCAVATOR_RETREAT_COST = 2000;
constexpr const char* EXCAVATOR_OLD_RANK = MINER_NAME;
constexpr const char* EXCAVATOR_ABILITY_NAME = "Undermine";
constexpr const char* EXCAVATOR_ABILITY_DESCRIPTION =
	"When this fighter card is played from your hand, "
	"return all energy cards in play to their owners' hands."
;
const std::string EXCAVATOR_ABILITY_EFFECTS(
	std::string(PLAY_EFFECT) // play
	+ EFFECT_SEPARATOR       //
	+ ENERGY_BOUNCE_EFFECT   // energy_bounce
);
constexpr bool EXCAVATOR_ABILITY_PASSIVE = true;
constexpr int EXCAVATOR_ABILITY_USES = PASSIVE_USES;
constexpr const char* EXCAVATOR_ATTACK_NAME = "Tunnel";
constexpr const char* EXCAVATOR_ATTACK_DESCRIPTION =
	"Deal 500 damage to your opponent's active fighter.\n"
	"Shuffle both players' hands into their decks.\n"
	"Both players draw a card for each card they shuffled in."
;
const std::string EXCAVATOR_ATTACK_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ OPPONENT_EFFECT           // opponent
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ OPPONENT_EFFECT           // opponent
	+ EFFECT_SEPARATOR          //
	+ DRAW_COUNT_EFFECT         // draw_count
	+ EFFECT_TERMINATOR
	+ SHUFFLE_EFFECT            // shuffle
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ DRAW_COUNT_EFFECT         // draw_count
);
constexpr int EXCAVATOR_ATTACK_DAMAGE = 500;
constexpr int EXCAVATOR_ATTACK_COST = 1000;
//}
//}

// Swimmer Family
//{
// Swimmer
//{
constexpr const char* SWIMMER_NAME = "Swimmer";
constexpr const char* SWIMMER_ELEMENT = WATER_ELEMENT;
constexpr int SWIMMER_HEALTH = 1050;
constexpr int SWIMMER_RETREAT_COST = 1000;
constexpr const char* SWIMMER_OLD_RANK = NO_OLD_RANK;
constexpr const char* SWIMMER_ABILITY_NAME = RANKER_ABILITY_NAME;
constexpr const char* SWIMMER_ABILITY_DESCRIPTION = RANKER_ABILITY_DESCRIPTION;
const std::string SWIMMER_ABILITY_EFFECTS(RANKER_ABILITY_EFFECTS);
constexpr bool SWIMMER_ABILITY_PASSIVE = RANKER_ABILITY_PASSIVE;
constexpr int SWIMMER_ABILITY_USES = RANKER_ABILITY_USES;
constexpr const char* SWIMMER_ATTACK_NAME = "Aqua Charge";
constexpr const char* SWIMMER_ATTACK_DESCRIPTION =
	"Deal 250 damage to your opponent's active fighter."
;
constexpr const char* SWIMMER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int SWIMMER_ATTACK_DAMAGE = 250;
constexpr int SWIMMER_ATTACK_COST = 1000;
//}

// Scuba Diver
//{
constexpr const char* SCUBA_DIVER_NAME = "Scuba Diver";
constexpr const char* SCUBA_DIVER_ELEMENT = WATER_ELEMENT;
constexpr int SCUBA_DIVER_HEALTH = 1300;
constexpr int SCUBA_DIVER_RETREAT_COST = 2000;
constexpr const char* SCUBA_DIVER_OLD_RANK = SWIMMER_NAME;
constexpr const char* SCUBA_DIVER_ABILITY_NAME = "Submerge";
constexpr const char* SCUBA_DIVER_ABILITY_DESCRIPTION =
	"When this fighter card is played from your hand, "
	"if this fighter is your active fighter, "
	"it can't be damaged or switched out until your next turn."
;
const std::string SCUBA_DIVER_ABILITY_EFFECTS(
	std::string(PLAY_EFFECT) // play
	+ EFFECT_SEPARATOR       //
	+ ACTIVE_EFFECT          // active
	+ EFFECT_SEPARATOR       //
	+ INVINCIBILITY_EFFECT   // invincibility
	+ EFFECT_TERMINATOR
	+ PLAY_EFFECT            // play
	+ EFFECT_SEPARATOR       //
	+ ACTIVE_EFFECT          // active
	+ EFFECT_SEPARATOR       //
	+ ROOT_EFFECT            // root
);
constexpr bool SCUBA_DIVER_ABILITY_PASSIVE = true;
constexpr int SCUBA_DIVER_ABILITY_USES = PASSIVE_USES;
constexpr const char* SCUBA_DIVER_ATTACK_NAME = "Undercurrent";
constexpr const char* SCUBA_DIVER_ATTACK_DESCRIPTION =
	"Deal 550 damage to your opponent's active fighter.\n"
	"If this fighter has the invinciblity effect, deal 250 more damage.\n"
	"Clear all effects from this fighter."
;
const std::string SCUBA_DIVER_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ INVINCIBILITY_EFFECT    // invincibility
	+ EFFECT_SEPARATOR        //
	+ "250"                   // 250
	+ EFFECT_TERMINATOR
	+ CLEAR_EFFECT            // clear
);
constexpr int SCUBA_DIVER_ATTACK_DAMAGE = 550;
constexpr int SCUBA_DIVER_ATTACK_COST = 2000;
//}	
//}

// Welder Family
//{
// Welder
//{
constexpr const char* WELDER_NAME = "Welder";
constexpr const char* WELDER_ELEMENT = FIRE_ELEMENT;
constexpr int WELDER_HEALTH = 1000;
constexpr int WELDER_RETREAT_COST = 1000;
constexpr const char* WELDER_OLD_RANK = NO_OLD_RANK;
constexpr const char* WELDER_ABILITY_NAME = RANKER_ABILITY_NAME;
constexpr const char* WELDER_ABILITY_DESCRIPTION = RANKER_ABILITY_DESCRIPTION;
const std::string WELDER_ABILITY_EFFECTS(RANKER_ABILITY_EFFECTS);
constexpr bool WELDER_ABILITY_PASSIVE = RANKER_ABILITY_PASSIVE;
constexpr int WELDER_ABILITY_USES = RANKER_ABILITY_USES;
constexpr const char* WELDER_ATTACK_NAME = "Blowtorch";
constexpr const char* WELDER_ATTACK_DESCRIPTION =
	"Deal 350 damage to your opponent's active fighter."
;
constexpr const char* WELDER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int WELDER_ATTACK_DAMAGE = 350;
constexpr int WELDER_ATTACK_COST = 1500;
//}

// Pyrotechnician
//{
constexpr const char* PYROTECHNICIAN_NAME = "Pyrotechnician";
constexpr const char* PYROTECHNICIAN_ELEMENT = FIRE_ELEMENT;
constexpr int PYROTECHNICIAN_HEALTH = 1200;
constexpr int PYROTECHNICIAN_RETREAT_COST = 2000;
constexpr const char* PYROTECHNICIAN_OLD_RANK = WELDER_NAME;
constexpr const char* PYROTECHNICIAN_ABILITY_NAME = "Pyromania";
constexpr const char* PYROTECHNICIAN_ABILITY_DESCRIPTION =
	"When this fighter card is played from your hand, "
	"convert all of your cards to this fighter's element."
;
const std::string PYROTECHNICIAN_ABILITY_EFFECTS(
	std::string(PLAY_EFFECT) // play
	+ EFFECT_SEPARATOR       //
	+ CONVERSION_EFFECT      // conversion
);
constexpr bool PYROTECHNICIAN_ABILITY_PASSIVE = true;
constexpr int PYROTECHNICIAN_ABILITY_USES = PASSIVE_USES;
constexpr const char* PYROTECHNICIAN_ATTACK_NAME = "Primed Payload";
constexpr const char* PYROTECHNICIAN_ATTACK_DESCRIPTION =
	"Deal 0.25 damage to your opponent's active fighter "
	"multiplied by this fighter's total energy value "
	"for a maximum of 700 damage."
;
const std::string PYROTECHNICIAN_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ ENERGY_TYPE             // Energy
	+ EFFECT_SEPARATOR        //
	+ "0.25"                  // 0.25
	+ EFFECT_SEPARATOR        //
	+ "700"                   // 700
);
constexpr int PYROTECHNICIAN_ATTACK_DAMAGE = 0;
constexpr int PYROTECHNICIAN_ATTACK_COST = 2000;
//}	
//}

// Wind Runner Family
//{
// Wind Runner
//{
constexpr const char* WIND_RUNNER_NAME = "Wind Runner";
constexpr const char* WIND_RUNNER_ELEMENT = AIR_ELEMENT;
constexpr int WIND_RUNNER_HEALTH = 950;
constexpr int WIND_RUNNER_RETREAT_COST = 0;
constexpr const char* WIND_RUNNER_OLD_RANK = NO_OLD_RANK;
constexpr const char* WIND_RUNNER_ABILITY_NAME = RANKER_ABILITY_NAME;
constexpr const char* WIND_RUNNER_ABILITY_DESCRIPTION = RANKER_ABILITY_DESCRIPTION;
const std::string WIND_RUNNER_ABILITY_EFFECTS(RANKER_ABILITY_EFFECTS);
constexpr bool WIND_RUNNER_ABILITY_PASSIVE = RANKER_ABILITY_PASSIVE;
constexpr int WIND_RUNNER_ABILITY_USES = RANKER_ABILITY_USES;
constexpr const char* WIND_RUNNER_ATTACK_NAME = "Gust";
constexpr const char* WIND_RUNNER_ATTACK_DESCRIPTION =
	"Deal 250 damage to your opponent's active fighter."
;
constexpr const char* WIND_RUNNER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int WIND_RUNNER_ATTACK_DAMAGE = 250;
constexpr int WIND_RUNNER_ATTACK_COST = 1000;
//}

// Cloud Surfer
//{
constexpr const char* CLOUD_SURFER_NAME = "Cloud Surfer";
constexpr const char* CLOUD_SURFER_ELEMENT = AIR_ELEMENT;
constexpr int CLOUD_SURFER_HEALTH = 1100;
constexpr int CLOUD_SURFER_RETREAT_COST = 0;
constexpr const char* CLOUD_SURFER_OLD_RANK = WIND_RUNNER_NAME;
constexpr const char* CLOUD_SURFER_ABILITY_NAME = "Windfall";
constexpr const char* CLOUD_SURFER_ABILITY_DESCRIPTION =
	"When this fighter card is played from your hand, "
	"reset your attack and retreat usage for this turn.\n"
	"Attacks deal 300 less damage this turn."
;
const std::string CLOUD_SURFER_ABILITY_EFFECTS(
	std::string(PLAY_EFFECT) // play
	+ EFFECT_SEPARATOR       //
	+ RESET_EFFECT           // reset
	+ EFFECT_TERMINATOR
	+ PLAY_EFFECT            // play
	+ EFFECT_SEPARATOR       //
	+ POWER_EFFECT           // power
	+ EFFECT_SEPARATOR       //
	+ "-300"                 // -300
);
constexpr bool CLOUD_SURFER_ABILITY_PASSIVE = true;
constexpr int CLOUD_SURFER_ABILITY_USES = PASSIVE_USES;
constexpr const char* CLOUD_SURFER_ATTACK_NAME = "Hurricane";
constexpr const char* CLOUD_SURFER_ATTACK_DESCRIPTION =
	"Deal 250 damage to all of your opponent's fighters."
;
const std::string CLOUD_SURFER_ATTACK_EFFECTS(
	std::string(SPLASH_EFFECT) // splash
	+ EFFECT_SEPARATOR         //
	+ "250"                    // 250
);
constexpr int CLOUD_SURFER_ATTACK_DAMAGE = 250;
constexpr int CLOUD_SURFER_ATTACK_COST = 2000;
//}
//}
//}

// Unranked Family
//{
// Boxer
//{
constexpr const char* BOXER_NAME = "Boxer";
constexpr const char* BOXER_ELEMENT = FIRE_ELEMENT;
constexpr int BOXER_HEALTH = 1000;
constexpr int BOXER_RETREAT_COST = 0;
constexpr const char* BOXER_OLD_RANK = NO_OLD_RANK;
constexpr const char* BOXER_ABILITY_NAME = "Aggressive";
constexpr const char* BOXER_ABILITY_DESCRIPTION =
	"If this fighter is on your bench, switch it into the active position."
;
constexpr const char* BOXER_ABILITY_EFFECTS = AGGRESSIVE_EFFECT; // aggressive
constexpr bool BOXER_ABILITY_PASSIVE = true;
constexpr int BOXER_ABILITY_USES = PASSIVE_USES;
constexpr const char* BOXER_ATTACK_NAME = "Haymaker";
constexpr const char* BOXER_ATTACK_DESCRIPTION =
	"Deal 600 damage to your opponent's active fighter. "
	"Deal 50 less damage for each card in your hand."
;
const std::string BOXER_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ HAND_EFFECT             // hand
	+ EFFECT_SEPARATOR        //
	+ "-50"                   // -50
);
constexpr int BOXER_ATTACK_DAMAGE = 600;
constexpr int BOXER_ATTACK_COST = 0;
//}

// Lost Soul
//{
constexpr const char* LOST_SOUL_NAME = "Lost Soul";
constexpr const char* LOST_SOUL_ELEMENT = AIR_ELEMENT;
constexpr int LOST_SOUL_HEALTH = 1000;
constexpr int LOST_SOUL_RETREAT_COST = 0;
constexpr const char* LOST_SOUL_OLD_RANK = NO_OLD_RANK;
constexpr const char* LOST_SOUL_ABILITY_NAME = "Forsaken";
constexpr const char* LOST_SOUL_ABILITY_DESCRIPTION =
	"When this fighter is defeated, banish it, its energy cards, "
	"its life card, and the top card of each player's deck."
;
const std::string LOST_SOUL_ABILITY_EFFECTS(
	std::string(FORSAKEN_EFFECT) // forsaken
	+ EFFECT_SEPARATOR           //
	+ "1"                        // 1
);
constexpr bool LOST_SOUL_ABILITY_PASSIVE = true;
constexpr int LOST_SOUL_ABILITY_USES = PASSIVE_USES;
constexpr const char* LOST_SOUL_ATTACK_NAME = "Wander";
constexpr const char* LOST_SOUL_ATTACK_DESCRIPTION =
	"If your deck has no fighter cards, deal 300 "
	"damage to your opponent's active fighter.\n"
	"Draw a fighter card from your deck."
;
const std::string LOST_SOUL_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ FIGHTERLESS_EFFECT      // fighterless
	+ EFFECT_SEPARATOR        //
	+ "300"                   // 300
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT             // draw
	+ EFFECT_SEPARATOR        //
	+ FIGHTER_TYPE            // Fighter
	+ EFFECT_SEPARATOR        //
	+ "1"                     // 1
);
constexpr int LOST_SOUL_ATTACK_DAMAGE = 0;
constexpr int LOST_SOUL_ATTACK_COST = 0;
//}
//}

// Void Family
//{
// Banisher
//{
constexpr const char* BANISHER_NAME = "Banisher";
constexpr const char* BANISHER_ELEMENT = FIRE_ELEMENT;
constexpr int BANISHER_HEALTH = 1100;
constexpr int BANISHER_RETREAT_COST = 2000;
constexpr const char* BANISHER_OLD_RANK = NO_OLD_RANK;
constexpr const char* BANISHER_ABILITY_NAME = "Burnt Offering";
constexpr const char* BANISHER_ABILITY_DESCRIPTION =
	"At the end of your turn, banish all of the cards in your trash."
;
constexpr const char* BANISHER_ABILITY_EFFECTS = BANISHMENT_EFFECT; // banishment
constexpr bool BANISHER_ABILITY_PASSIVE = true;
constexpr int BANISHER_ABILITY_USES = PASSIVE_USES;
constexpr const char* BANISHER_ATTACK_NAME = "Shadow Flame";
constexpr const char* BANISHER_ATTACK_DESCRIPTION =
	"Your opponent's active fighter takes 40 damage at "
	"the end of each turn, for each card in the void, "
	"for a maximum of 600 damage."
;
const std::string BANISHER_ATTACK_EFFECTS(
	std::string(CURSE_EFFECT) // curse
	+ EFFECT_SEPARATOR        //
	+ VOID_EFFECT             // void
	+ EFFECT_SEPARATOR        //
	+ "40"                    // 40
	+ EFFECT_SEPARATOR        //
	+ "600"                   // 600
);
constexpr int BANISHER_ATTACK_DAMAGE = 0;
constexpr int BANISHER_ATTACK_COST = 2000;
//}

// Banshee
//{
constexpr const char* BANSHEE_NAME = "Banshee";
constexpr const char* BANSHEE_ELEMENT = WATER_ELEMENT;
constexpr int BANSHEE_HEALTH = 1100;
constexpr int BANSHEE_RETREAT_COST = 2000;
constexpr const char* BANSHEE_OLD_RANK = NO_OLD_RANK;
constexpr const char* BANSHEE_ABILITY_NAME = "Forbidden Fuel";
constexpr const char* BANSHEE_ABILITY_DESCRIPTION =
	"This fighter can attack and retreat for 250 less energy for each card in the void."
;
const std::string BANSHEE_ABILITY_EFFECTS(
	std::string(FUEL_EFFECT) // fuel
	+ EFFECT_SEPARATOR       //
	+ VOID_EFFECT            // void
	+ EFFECT_SEPARATOR       //
	+ "250"                  // 250
);
constexpr bool BANSHEE_ABILITY_PASSIVE = true;
constexpr int BANSHEE_ABILITY_USES = PASSIVE_USES;
constexpr const char* BANSHEE_ATTACK_NAME = "Screech";
constexpr const char* BANSHEE_ATTACK_DESCRIPTION =
	"Deal 60 damage to your opponent's active fighter, "
	"for each card in the void, "
	"for a maximum of 900 damage."
;
const std::string BANSHEE_ATTACK_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ VOID_EFFECT             // void
	+ EFFECT_SEPARATOR        //
	+ "60"                    // 60
	+ EFFECT_SEPARATOR        //
	+ "900"                   // 900
);
constexpr int BANSHEE_ATTACK_DAMAGE = 0;
constexpr int BANSHEE_ATTACK_COST = 2000;
//}

// Cultist
//{
constexpr const char* CULTIST_NAME = "Cultist";
constexpr const char* CULTIST_ELEMENT = EARTH_ELEMENT;
constexpr int CULTIST_HEALTH = 1100;
constexpr int CULTIST_RETREAT_COST = 2000;
constexpr const char* CULTIST_OLD_RANK = NO_OLD_RANK;
constexpr const char* CULTIST_ABILITY_NAME = "Void Pact";
constexpr const char* CULTIST_ABILITY_DESCRIPTION =
	"Once a turn, you may banish a card in your hand "
	"and heal 25 damage from one "
	"of your fighters, for each card in the void, "
	"for a maximum of 375 healing."
;
const std::string CULTIST_ABILITY_EFFECTS(
	std::string(BANISH_EFFECT) // banish
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ HEAL_EFFECT              // heal
	+ EFFECT_SEPARATOR         //
	+ VOID_EFFECT              // void
	+ EFFECT_SEPARATOR         //
	+ "25"                     // 25
	+ EFFECT_SEPARATOR         //
	+ "375"                    // 375
);
constexpr bool CULTIST_ABILITY_PASSIVE = false;
constexpr int CULTIST_ABILITY_USES = 1;
constexpr const char* CULTIST_ATTACK_NAME = "Shadow Bond";
constexpr const char* CULTIST_ATTACK_DESCRIPTION =
	"Choose a fighter in the void. Use its attack."
;
const std::string CULTIST_ATTACK_EFFECTS(
	std::string(MIMIC_EFFECT) // mimic
	+ EFFECT_SEPARATOR        //
	+ VOID_EFFECT             // void
);
constexpr int CULTIST_ATTACK_DAMAGE = 0;
constexpr int CULTIST_ATTACK_COST = 2000;
//}
//}

// Apprentice Family
//{
// Universal Apprentice Final Rank Ability Constants
//{
constexpr const char* APPRENTICE_FINAL_RANK_ABILITY_NAME = "Combo Attack";
constexpr const char* APPRENTICE_FINAL_RANK_ABILITY_DESCRIPTION =
	"After this fighter attacks, your other fighters with "
	"this ability and sufficient energy also attack."
;
constexpr const char* APPRENTICE_FINAL_RANK_ABILITY_EFFECTS = COMBO_EFFECT; // combo
constexpr bool APPRENTICE_FINAL_RANK_ABILITY_PASSIVE = true;
constexpr int APPRENTICE_FINAL_RANK_ABILITY_USES = PASSIVE_USES;
//}

// Apprentice
//{
constexpr const char* APPRENTICE_NAME = "Apprentice";
constexpr const char* APPRENTICE_ELEMENT = AIR_ELEMENT;
constexpr int APPRENTICE_HEALTH = 1000;
constexpr int APPRENTICE_RETREAT_COST = 1000;
constexpr const char* APPRENTICE_OLD_RANK = NO_OLD_RANK;
constexpr const char* APPRENTICE_ABILITY_NAME = "Earth Affinity";
constexpr const char* APPRENTICE_ABILITY_DESCRIPTION =
	"This fighter can use energy of the Earth element."
;
const std::string APPRENTICE_ABILITY_EFFECTS(
	std::string(AFFINITY_EFFECT) // affinity
	+ EFFECT_SEPARATOR           //
	+ EARTH_ELEMENT              // Earth
);
constexpr bool APPRENTICE_ABILITY_PASSIVE = true;
constexpr int APPRENTICE_ABILITY_USES = PASSIVE_USES;
constexpr const char* APPRENTICE_ATTACK_NAME = "Fist Flurry";
constexpr const char* APPRENTICE_ATTACK_DESCRIPTION =
	"Deal 250 damage to your opponent's active fighter."
;
constexpr const char* APPRENTICE_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int APPRENTICE_ATTACK_DAMAGE = 250;
constexpr int APPRENTICE_ATTACK_COST = 1000;
//}

// Sensei's Chosen
//{
constexpr const char* SENSEIS_CHOSEN_NAME = "Sensei's Chosen";
constexpr const char* SENSEIS_CHOSEN_ELEMENT = EARTH_ELEMENT;
constexpr int SENSEIS_CHOSEN_HEALTH = 1200;
constexpr int SENSEIS_CHOSEN_RETREAT_COST = 1000;
constexpr const char* SENSEIS_CHOSEN_OLD_RANK = APPRENTICE_NAME;
constexpr const char* SENSEIS_CHOSEN_ABILITY_NAME = "Air Affinity";
constexpr const char* SENSEIS_CHOSEN_ABILITY_DESCRIPTION =
	"This fighter can use energy of the Air element."
;
const std::string SENSEIS_CHOSEN_ABILITY_EFFECTS(
	std::string(AFFINITY_EFFECT) // affinity
	+ EFFECT_SEPARATOR           //
	+ AIR_ELEMENT                // Air
);
constexpr bool SENSEIS_CHOSEN_ABILITY_PASSIVE = true;
constexpr int SENSEIS_CHOSEN_ABILITY_USES = PASSIVE_USES;
constexpr const char* SENSEIS_CHOSEN_ATTACK_NAME = "Flying Kick";
constexpr const char* SENSEIS_CHOSEN_ATTACK_DESCRIPTION =
	"Deal 400 damage to your opponent's active fighter.\n"
	"Flip a coin.\n"
	"If heads, deal 100 more damage."
;
const std::string SENSEIS_CHOSEN_ATTACK_EFFECTS(
	std::string(FLIP_EFFECT) // flip
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
	+ EFFECT_TERMINATOR
	+ HEADS_EFFECT           // heads
	+ EFFECT_SEPARATOR       //
	+ POWER_EFFECT           // power
	+ EFFECT_SEPARATOR       //
	+ "100"                  // 100
);
constexpr int SENSEIS_CHOSEN_ATTACK_DAMAGE = 400;
constexpr int SENSEIS_CHOSEN_ATTACK_COST = 1000;
//}

// Ninja
//{
constexpr const char* NINJA_NAME = "Ninja";
constexpr const char* NINJA_ELEMENT = AIR_ELEMENT;
constexpr int NINJA_HEALTH = 1200;
constexpr int NINJA_RETREAT_COST = 0;
constexpr const char* NINJA_OLD_RANK = SENSEIS_CHOSEN_NAME;
constexpr const char* NINJA_ABILITY_NAME = APPRENTICE_FINAL_RANK_ABILITY_NAME;
constexpr const char* NINJA_ABILITY_DESCRIPTION = APPRENTICE_FINAL_RANK_ABILITY_DESCRIPTION;
constexpr const char* NINJA_ABILITY_EFFECTS = APPRENTICE_FINAL_RANK_ABILITY_EFFECTS;
constexpr bool NINJA_ABILITY_PASSIVE = APPRENTICE_FINAL_RANK_ABILITY_PASSIVE;
constexpr int NINJA_ABILITY_USES = APPRENTICE_FINAL_RANK_ABILITY_USES;
constexpr const char* NINJA_ATTACK_NAME = "Shuriken Storm";
constexpr const char* NINJA_ATTACK_DESCRIPTION =
	"Flip 2 coins.\n"
	"Deal 350 damage in 175 damage bursts to your opponent's "
	"fighters in a distribution of your choosing.\n"
	"For each heads, deal another 175 damage burst."
;
const std::string NINJA_ATTACK_EFFECTS(
	std::string(FLIP_EFFECT) // flip
	+ EFFECT_SEPARATOR       //
	+ "2"                    // 2
	+ EFFECT_TERMINATOR
	+ SNIPE_EFFECT           // snipe
	+ EFFECT_SEPARATOR       //
	+ HEADS_COUNT_EFFECT     // heads_count
	+ EFFECT_SEPARATOR       //
	+ "175"                  // 175
	+ EFFECT_TERMINATOR
	+ SNIPE_EFFECT           // snipe
	+ EFFECT_SEPARATOR       //
	+ "175"                  // 175
	+ EFFECT_TERMINATOR
	+ SNIPE_EFFECT           // snipe
	+ EFFECT_SEPARATOR       //
	+ "175"                  // 175
);
constexpr int NINJA_ATTACK_DAMAGE = 0;
constexpr int NINJA_ATTACK_COST = 1000;
//}

// Samurai
//{
constexpr const char* SAMURAI_NAME = "Samurai";
constexpr const char* SAMURAI_ELEMENT = EARTH_ELEMENT;
constexpr int SAMURAI_HEALTH = 1400;
constexpr int SAMURAI_RETREAT_COST = 1000;
constexpr const char* SAMURAI_OLD_RANK = SENSEIS_CHOSEN_NAME;
constexpr const char* SAMURAI_ABILITY_NAME = APPRENTICE_FINAL_RANK_ABILITY_NAME;
constexpr const char* SAMURAI_ABILITY_DESCRIPTION = APPRENTICE_FINAL_RANK_ABILITY_DESCRIPTION;
constexpr const char* SAMURAI_ABILITY_EFFECTS = APPRENTICE_FINAL_RANK_ABILITY_EFFECTS;
constexpr bool SAMURAI_ABILITY_PASSIVE = APPRENTICE_FINAL_RANK_ABILITY_PASSIVE;
constexpr int SAMURAI_ABILITY_USES = APPRENTICE_FINAL_RANK_ABILITY_USES;
constexpr const char* SAMURAI_ATTACK_NAME = "Subjugate";
constexpr const char* SAMURAI_ATTACK_DESCRIPTION =
	"Deal 275 damage to your opponent's active fighter.\n"
	"Flip 2 coins.\n"
	"Your opponent's active fighter can't attack if the first flip gives heads.\n"
	"Your opponent's active fighter can't retreat if the second flip gives heads."
;
const std::string SAMURAI_ATTACK_EFFECTS(
	std::string(FLIP_EFFECT) // flip
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
	+ EFFECT_TERMINATOR
	+ HEADS_EFFECT           // heads
	+ EFFECT_SEPARATOR       //
	+ IMPAIR_EFFECT          // impair
	+ EFFECT_TERMINATOR
	+ FLIP_EFFECT            // flip
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
	+ EFFECT_TERMINATOR
	+ HEADS_EFFECT           // heads
	+ EFFECT_SEPARATOR       //
	+ CRIPPLE_EFFECT         // cripple
);
constexpr int SAMURAI_ATTACK_DAMAGE = 275;
constexpr int SAMURAI_ATTACK_COST = 1000;
//}
//}

// Elemental Family
//{
// Basic Elemental Universal Constants
//{
constexpr int ELEMENTAL_HEALTH = 1000;
constexpr int ELEMENTAL_RETREAT_COST = 1000;
constexpr const char* ELEMENTAL_OLD_RANK = NO_OLD_RANK;
constexpr const char* ELEMENTAL_ABILITY_NAME = "Omega Fusion";
constexpr const char* ELEMENTAL_ABILITY_DESCRIPTION =
	"If this fighter is your active fighter, you may defeat "
	"the fighters on your bench with this ability.\n"
	"If you defeat at least 2, rank this fighter up into a random "
	"fighter card in your hand that ranks up from this ability."
;
const std::string ELEMENTAL_ABILITY_EFFECTS(
	std::string(FUSION_EFFECT) // fusion
	+ EFFECT_SEPARATOR         //
	+ "2"                      // 2
);
constexpr bool ELEMENTAL_ABILITY_PASSIVE = false;
constexpr int ELEMENTAL_ABILITY_USES = 1;
constexpr const char* ELEMENTAL_ATTACK_DESCRIPTION =
	"Deal 250 damage to your opponent's active fighter.\n"
	"Both players draw a card."
;
const std::string ELEMENTAL_ATTACK_EFFECTS(
	std::string(DRAW_EFFECT) // draw
	+ EFFECT_SEPARATOR       //
	+ OPPONENT_EFFECT        // opponent
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT            // draw
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
);
constexpr int ELEMENTAL_ATTACK_DAMAGE = 250;
constexpr int ELEMENTAL_ATTACK_COST = 1000;
//}

// Fire Elemental
//{
constexpr const char* FIRE_ELEMENTAL_NAME = "Fire Elemental";
constexpr const char* FIRE_ELEMENTAL_ELEMENT = FIRE_ELEMENT;
constexpr int FIRE_ELEMENTAL_HEALTH = ELEMENTAL_HEALTH;
constexpr int FIRE_ELEMENTAL_RETREAT_COST = ELEMENTAL_RETREAT_COST;
constexpr const char* FIRE_ELEMENTAL_OLD_RANK = ELEMENTAL_OLD_RANK;
constexpr const char* FIRE_ELEMENTAL_ABILITY_NAME = ELEMENTAL_ABILITY_NAME;
constexpr const char* FIRE_ELEMENTAL_ABILITY_DESCRIPTION = ELEMENTAL_ABILITY_DESCRIPTION;
const std::string FIRE_ELEMENTAL_ABILITY_EFFECTS(ELEMENTAL_ABILITY_EFFECTS);
constexpr bool FIRE_ELEMENTAL_ABILITY_PASSIVE = ELEMENTAL_ABILITY_PASSIVE;
constexpr int FIRE_ELEMENTAL_ABILITY_USES = ELEMENTAL_ABILITY_USES;
constexpr const char* FIRE_ELEMENTAL_ATTACK_NAME = "Bonfire";
constexpr const char* FIRE_ELEMENTAL_ATTACK_DESCRIPTION = ELEMENTAL_ATTACK_DESCRIPTION;
const std::string FIRE_ELEMENTAL_ATTACK_EFFECTS(ELEMENTAL_ATTACK_EFFECTS);
constexpr int FIRE_ELEMENTAL_ATTACK_DAMAGE = ELEMENTAL_ATTACK_DAMAGE;
constexpr int FIRE_ELEMENTAL_ATTACK_COST = ELEMENTAL_ATTACK_COST;
//}

// Air Elemental
//{
constexpr const char* AIR_ELEMENTAL_NAME = "Air Elemental";
constexpr const char* AIR_ELEMENTAL_ELEMENT = AIR_ELEMENT;
constexpr int AIR_ELEMENTAL_HEALTH = ELEMENTAL_HEALTH;
constexpr int AIR_ELEMENTAL_RETREAT_COST = ELEMENTAL_RETREAT_COST;
constexpr const char* AIR_ELEMENTAL_OLD_RANK = ELEMENTAL_OLD_RANK;
constexpr const char* AIR_ELEMENTAL_ABILITY_NAME = ELEMENTAL_ABILITY_NAME;
constexpr const char* AIR_ELEMENTAL_ABILITY_DESCRIPTION = ELEMENTAL_ABILITY_DESCRIPTION;
const std::string AIR_ELEMENTAL_ABILITY_EFFECTS(ELEMENTAL_ABILITY_EFFECTS);
constexpr bool AIR_ELEMENTAL_ABILITY_PASSIVE = ELEMENTAL_ABILITY_PASSIVE;
constexpr int AIR_ELEMENTAL_ABILITY_USES = ELEMENTAL_ABILITY_USES;
constexpr const char* AIR_ELEMENTAL_ATTACK_NAME = "Windfall";
constexpr const char* AIR_ELEMENTAL_ATTACK_DESCRIPTION = ELEMENTAL_ATTACK_DESCRIPTION;
const std::string AIR_ELEMENTAL_ATTACK_EFFECTS(ELEMENTAL_ATTACK_EFFECTS);
constexpr int AIR_ELEMENTAL_ATTACK_DAMAGE = ELEMENTAL_ATTACK_DAMAGE;
constexpr int AIR_ELEMENTAL_ATTACK_COST = ELEMENTAL_ATTACK_COST;
//}

// Water Elemental
//{
constexpr const char* WATER_ELEMENTAL_NAME = "Water Elemental";
constexpr const char* WATER_ELEMENTAL_ELEMENT = WATER_ELEMENT;
constexpr int WATER_ELEMENTAL_HEALTH = ELEMENTAL_HEALTH;
constexpr int WATER_ELEMENTAL_RETREAT_COST = ELEMENTAL_RETREAT_COST;
constexpr const char* WATER_ELEMENTAL_OLD_RANK = ELEMENTAL_OLD_RANK;
constexpr const char* WATER_ELEMENTAL_ABILITY_NAME = ELEMENTAL_ABILITY_NAME;
constexpr const char* WATER_ELEMENTAL_ABILITY_DESCRIPTION = ELEMENTAL_ABILITY_DESCRIPTION;
const std::string WATER_ELEMENTAL_ABILITY_EFFECTS(ELEMENTAL_ABILITY_EFFECTS);
constexpr bool WATER_ELEMENTAL_ABILITY_PASSIVE = ELEMENTAL_ABILITY_PASSIVE;
constexpr int WATER_ELEMENTAL_ABILITY_USES = ELEMENTAL_ABILITY_USES;
constexpr const char* WATER_ELEMENTAL_ATTACK_NAME = "Reservoir";
constexpr const char* WATER_ELEMENTAL_ATTACK_DESCRIPTION = ELEMENTAL_ATTACK_DESCRIPTION;
const std::string WATER_ELEMENTAL_ATTACK_EFFECTS(ELEMENTAL_ATTACK_EFFECTS);
constexpr int WATER_ELEMENTAL_ATTACK_DAMAGE = ELEMENTAL_ATTACK_DAMAGE;
constexpr int WATER_ELEMENTAL_ATTACK_COST = ELEMENTAL_ATTACK_COST;
//}

// Earth Elemental
//{
constexpr const char* EARTH_ELEMENTAL_NAME = "Earth Elemental";
constexpr const char* EARTH_ELEMENTAL_ELEMENT = EARTH_ELEMENT;
constexpr int EARTH_ELEMENTAL_HEALTH = ELEMENTAL_HEALTH;
constexpr int EARTH_ELEMENTAL_RETREAT_COST = ELEMENTAL_RETREAT_COST;
constexpr const char* EARTH_ELEMENTAL_OLD_RANK = ELEMENTAL_OLD_RANK;
constexpr const char* EARTH_ELEMENTAL_ABILITY_NAME = ELEMENTAL_ABILITY_NAME;
constexpr const char* EARTH_ELEMENTAL_ABILITY_DESCRIPTION = ELEMENTAL_ABILITY_DESCRIPTION;
const std::string EARTH_ELEMENTAL_ABILITY_EFFECTS(ELEMENTAL_ABILITY_EFFECTS);
constexpr bool EARTH_ELEMENTAL_ABILITY_PASSIVE = ELEMENTAL_ABILITY_PASSIVE;
constexpr int EARTH_ELEMENTAL_ABILITY_USES = ELEMENTAL_ABILITY_USES;
constexpr const char* EARTH_ELEMENTAL_ATTACK_NAME = "Unearth";
constexpr const char* EARTH_ELEMENTAL_ATTACK_DESCRIPTION = ELEMENTAL_ATTACK_DESCRIPTION;
const std::string EARTH_ELEMENTAL_ATTACK_EFFECTS(ELEMENTAL_ATTACK_EFFECTS);
constexpr int EARTH_ELEMENTAL_ATTACK_DAMAGE = ELEMENTAL_ATTACK_DAMAGE;
constexpr int EARTH_ELEMENTAL_ATTACK_COST = ELEMENTAL_ATTACK_COST;
//}

// Omega Elemental
//{
constexpr const char* OMEGA_ELEMENTAL_NAME = "Omega Elemental";
constexpr const char* OMEGA_ELEMENTAL_ELEMENT = NO_ELEMENT;
constexpr int OMEGA_ELEMENTAL_HEALTH = 1750;
constexpr int OMEGA_ELEMENTAL_RETREAT_COST = 0;
constexpr const char* OMEGA_ELEMENTAL_OLD_RANK = ELEMENTAL_ABILITY_NAME;
constexpr const char* OMEGA_ELEMENTAL_ABILITY_NAME = "Synthesise";
constexpr const char* OMEGA_ELEMENTAL_ABILITY_DESCRIPTION =
	"Once a turn, you may search your opponent's hand for a card and draw a copy of it."
;
const std::string OMEGA_ELEMENTAL_ABILITY_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ OPPONENT_EFFECT          // opponent
	+ EFFECT_SEPARATOR         //
	+ HAND_EFFECT              // hand
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
);
constexpr bool OMEGA_ELEMENTAL_ABILITY_PASSIVE = false;
constexpr int OMEGA_ELEMENTAL_ABILITY_USES = 1;
constexpr const char* OMEGA_ELEMENTAL_ATTACK_NAME = "Assimilate";
constexpr const char* OMEGA_ELEMENTAL_ATTACK_DESCRIPTION =
	"Deal 700 damage in total to your opponent's fighters.\n"
	"The damage is randomly distributed.\n"
	"Heal 0.5 damage from this fighter multiplied by the damage dealt."
;
const std::string OMEGA_ELEMENTAL_ATTACK_EFFECTS(
	std::string(DISTRIBUTE_EFFECT) // distribute
	+ EFFECT_SEPARATOR             //
	+ "700"                        // 700
	+ EFFECT_TERMINATOR
	+ HEAL_EFFECT                  // heal
	+ EFFECT_SEPARATOR             //
	+ SELF_EFFECT                  // self
	+ EFFECT_SEPARATOR             //
	+ DAMAGE_EFFECT                // damage
	+ EFFECT_SEPARATOR             //
	+ "0.5"                        // 0.5
);
constexpr int OMEGA_ELEMENTAL_ATTACK_DAMAGE = 0;
constexpr int OMEGA_ELEMENTAL_ATTACK_COST = 2000;
//}
//}
//}

// Supporter Cards
//{
// Draw
//{
// Professor
//{
constexpr const char* PROFESSOR_NAME = "Professor";
constexpr const char* PROFESSOR_DESCRIPTION =
	"Discard your hand.\n"
	"Draw 7 cards.";
const std::string PROFESSOR_EFFECTS(
	std::string(DISCARD_EFFECT) // discard
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "7"                       // 7
);
//}

// Lecturer
//{
constexpr const char* LECTURER_NAME = "Lecturer";
constexpr const char* LECTURER_DESCRIPTION =
	"Shuffle your hand into your deck.\n"
	"Draw 6 cards."
;
const std::string LECTURER_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "6"                       // 6
);
//}

// Investor
//{
constexpr const char* INVESTOR_NAME = "Investor";
constexpr const char* INVESTOR_DESCRIPTION =
	"Shuffle your hand into your deck.\n"
	"At the start of your next turn, draw 8 cards."
;
const std::string INVESTOR_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ END_DRAW_EFFECT           // end_draw
	+ EFFECT_SEPARATOR          //
	+ "8"                       // 8
);
//}

// Researcher
//{
constexpr const char* RESEARCHER_NAME = "Researcher";
constexpr const char* RESEARCHER_DESCRIPTION = "Draw 2 cards.";
const std::string RESEARCHER_EFFECTS(
	std::string(DRAW_EFFECT) // draw
	+ EFFECT_SEPARATOR
	+ "2"                    // 2
);
//}

// Gambler
//{
constexpr const char* GAMBLER_NAME = "Gambler";
constexpr const char* GAMBLER_DESCRIPTION =
	"Discard a card from your hand.\n"
	"Flip 2 coins.\n"
	"Draw 2 cards.\n"
	"Draw an extra card for each heads."
;
const std::string GAMBLER_EFFECTS(
	std::string(DISCARD_EFFECT) // discard
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_TERMINATOR
	+ FLIP_EFFECT               // flip
	+ EFFECT_SEPARATOR          //
	+ "2"                       // 2
	+ EFFECT_TERMINATOR
	+ HEADS_EFFECT              // heads
	+ EFFECT_SEPARATOR          //
	+ HEADS_EFFECT              // heads
	+ EFFECT_SEPARATOR          //
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "4"                       // 4
	+ EFFECT_TERMINATOR
	+ HEADS_EFFECT              // heads
	+ EFFECT_SEPARATOR          //
	+ TAILS_EFFECT              // tails
	+ EFFECT_SEPARATOR          //
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "3"                       // 3
	+ EFFECT_TERMINATOR
	+ TAILS_EFFECT              // tails
	+ EFFECT_SEPARATOR          //
	+ HEADS_EFFECT              // heads
	+ EFFECT_SEPARATOR          //
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "3"                       // 3
	+ EFFECT_TERMINATOR
	+ TAILS_EFFECT              // tails
	+ EFFECT_SEPARATOR          //
	+ TAILS_EFFECT              // tails
	+ EFFECT_SEPARATOR          //
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "2"                       // 2
);
//}

// Recruiter
//{
constexpr const char* RECRUITER_NAME = "Recruiter";
constexpr const char* RECRUITER_DESCRIPTION =
	"Draw all of the unranked fighter cards in your deck."
;
const std::string RECRUITER_EFFECTS(
	std::string(DRAW_EFFECT) // draw
	+ EFFECT_SEPARATOR       //
	+ UNRANKED_EFFECT        // unranked
);
//}
//}

// Search
//{
// Chef
//{
constexpr const char* CHEF_NAME = "Chef";
constexpr const char* CHEF_DESCRIPTION =
	"Search your deck for 2 energy cards and draw them."
;
const std::string CHEF_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ ENERGY_TYPE              // Energy
	+ EFFECT_SEPARATOR         //
	+ "2"                      // 2
);
//}

// Trader
//{
constexpr const char* TRADER_NAME = "Trader";
constexpr const char* TRADER_DESCRIPTION =
	"Shuffle a card into your deck.\n"
	"Search your deck for a card of the same type."
;
const std::string TRADER_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_TERMINATOR
	+ SEARCH_EFFECT             // search
	+ EFFECT_SEPARATOR          //
	+ SAME_TYPE_EFFECT          // same_type
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
);
//}

// Librarian
//{
constexpr const char* LIBRARIAN_NAME = "Librarian";
constexpr const char* LIBRARIAN_DESCRIPTION =
	"Discard a card from your hand.\n"
	"Search your deck for a card and draw it."
;
const std::string LIBRARIAN_EFFECTS(
	std::string(DISCARD_EFFECT) // discard
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_TERMINATOR
	+ SEARCH_EFFECT             // search
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
);
//}

// Experimenter
//{
constexpr const char* EXPERIMENTER_NAME = "Experimenter";
constexpr const char* EXPERIMENTER_DESCRIPTION =
	"Search your deck for a card.\n"
	"Banish the top card of your deck.\n"
	"Return this card to your hand.\n"
	"At the end of your turn, discard this card."
;
const std::string EXPERIMENTER_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ MILL_EFFECT              // mill
	+ EFFECT_SEPARATOR         //
	+ SELF_EFFECT              // self
	+ EFFECT_SEPARATOR         //
	+ BANISH_EFFECT            // banish
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT           // recycle
	+ EFFECT_SEPARATOR         //
	+ HAND_EFFECT              // hand
	+ EFFECT_TERMINATOR
	+ END_DISCARD_EFFECT       // end_discard
);
//}

// Personal Trainer
//{
constexpr const char* PERSONAL_TRAINER_NAME = "Personal Trainer";
constexpr const char* PERSONAL_TRAINER_DESCRIPTION =
	"Fully rank up one of your fighters using cards in your deck."
;
constexpr const char* PERSONAL_TRAINER_EFFECTS = TRAIN_EFFECT; // train
//}

// Scapegoat
//{
constexpr const char* SCAPEGOAT_NAME = "Scapegoat";
constexpr const char* SCAPEGOAT_DESCRIPTION =
	"Swap this card with one of your life cards."
;
const std::string SCAPEGOAT_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ LIFE_EFFECT              // life
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT           // recycle
	+ EFFECT_SEPARATOR         //
	+ LIFE_EFFECT              // life
);
//}
//}

// Recycle
//{
// Electrician
//{
constexpr const char* ELECTRICIAN_NAME = "Electrician";
constexpr const char* ELECTRICIAN_DESCRIPTION =
	"Search your trash for 2 energy cards and draw them."
;
const std::string ELECTRICIAN_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ TRASH_EFFECT             // trash
	+ EFFECT_SEPARATOR         //
	+ ENERGY_TYPE              // Energy
	+ EFFECT_SEPARATOR         //
	+ "2"                      // 2
);
//}

// Alchemist
//{
constexpr const char* ALCHEMIST_NAME = "Alchemist";
constexpr const char* ALCHEMIST_DESCRIPTION =
	"Discard a card from your hand.\n"
	"Search your trash for a card and draw it."
;
const std::string ALCHEMIST_EFFECTS(
	std::string(DISCARD_EFFECT) // discard
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_TERMINATOR
	+ SEARCH_EFFECT             // search
	+ EFFECT_SEPARATOR          //
	+ TRASH_EFFECT              // trash
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
);
//}

// Time Traveller
//{
constexpr const char* TIME_TRAVELLER_NAME = "Time Traveller";
constexpr const char* TIME_TRAVELLER_DESCRIPTION =
	"Search your trash for a card and draw it.\n"
	"You can play 1 more card this turn.\n"
	"You can play 2 fewer cards next turn."
;
const std::string TIME_TRAVELLER_EFFECTS(
	std::string(SEARCH_EFFECT) // search
	+ EFFECT_SEPARATOR         //
	+ TRASH_EFFECT             // trash
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ EXTRA_PLAY_EFFECT        // extra_play
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ OVERLOAD_EFFECT          // overload
	+ EFFECT_SEPARATOR         //
	+ "2"                      // 2
);
//}

// Banker
//{
constexpr const char* BANKER_NAME = "Banker";
constexpr const char* BANKER_DESCRIPTION =
	"Shuffle a card from your hand into your deck.\n"
	"Return this card to your hand.\n"
	"At the end of your turn, discard this card."
;
const std::string BANKER_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ "1"                       // 1
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT            // recycle
	+ EFFECT_SEPARATOR          //
	+ HAND_EFFECT               // hand
	+ EFFECT_TERMINATOR
	+ END_DISCARD_EFFECT        // end_discard
);
//}

// Glutton
//{
constexpr const char* GLUTTON_NAME = "Glutton";
constexpr const char* GLUTTON_DESCRIPTION =
	"Shuffle your discarded energy cards into your deck."
;
const std::string GLUTTON_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ TRASH_EFFECT              // trash
	+ EFFECT_SEPARATOR          //
	+ ENERGY_TYPE               // Energy
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
);
//}
//}

// Switch
//{
// Substitute
//{
constexpr const char* SUBSTITUTE_NAME = "Substitute";
constexpr const char* SUBSTITUTE_DESCRIPTION =
	"Switch in a fighter from your bench.\n"
	"Shuffle this card into your deck instead of discarding it.\n"
	"Draw a card.\n"
	"You can play 1 more card this turn."
;
const std::string SUBSTITUTE_EFFECTS(
	std::string(SWITCH_EFFECT) // switch
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT           // recycle
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT              // draw
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ EXTRA_PLAY_EFFECT        // extra_play
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
);
//}

// Bounty Hunter
//{
constexpr const char* BOUNTY_HUNTER_NAME = "Bounty Hunter";
constexpr const char* BOUNTY_HUNTER_DESCRIPTION =
	"Switch in one of your opponent's benched fighters.\n"
	"Shuffle this card into your deck instead of discarding it.\n"
	"Draw a card."
;
const std::string BOUNTY_HUNTER_EFFECTS(
	std::string(HOOK_EFFECT) // hook
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT         // recycle
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT            // draw
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
);
//}
//}

// Healing
//{
// Nurse
//{
constexpr const char* NURSE_NAME = "Nurse";
constexpr const char* NURSE_DESCRIPTION =
	"Heal 600 damage from one of your fighters."
;
const std::string NURSE_EFFECTS(
	std::string(HEAL_EFFECT) // heal
	+ EFFECT_SEPARATOR       //
	+ "600"                  // 600
);
//}

// Innkeeper
//{
constexpr const char* INNKEEPER_NAME = "Innkeeper";
constexpr const char* INNKEEPER_DESCRIPTION =
	"Heal 400 damage from each of your fighters."
;
const std::string INNKEEPER_EFFECTS(
	std::string(HEAL_EFFECT) // heal
	+ EFFECT_SEPARATOR       //
	+ SPLASH_EFFECT          // splash
	+ EFFECT_SEPARATOR       //
	+ "400"                  // 400
);
//}

// Miracle Worker
//{
constexpr const char* MIRACLE_WORKER_NAME = "Miracle Worker";
constexpr const char* MIRACLE_WORKER_DESCRIPTION =
	"Heal 800 damage in total from your fighters.\n"
	"The healing is randomly distributed."
;
const std::string MIRACLE_WORKER_EFFECTS(
	std::string(HEAL_EFFECT) // heal
	+ EFFECT_SEPARATOR       //
	+ DISTRIBUTE_EFFECT      // distribute
	+ EFFECT_SEPARATOR       //
	+ "800"                  // 800
);
//}

// Doctor
//{
constexpr const char* DOCTOR_NAME = "Doctor";
constexpr const char* DOCTOR_DESCRIPTION =
	"Discard all of the energy cards in your hand.\n"
	"Heal 500 damage from each of your fighters for each card discarded."
;
const std::string DOCTOR_EFFECTS(
	std::string(DISCARD_EFFECT) // discard
	+ EFFECT_SEPARATOR          //
	+ ENERGY_TYPE               // Energy
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ HEAL_EFFECT               // heal
	+ EFFECT_SEPARATOR          //
	+ SPLASH_EFFECT             // splash
	+ EFFECT_SEPARATOR          //
	+ DRAW_COUNT_EFFECT         // draw_count
	+ EFFECT_SEPARATOR          //
	+ "500"                     // 500
	+ EFFECT_TERMINATOR
	+ CLEAR_EFFECT              // clear
);
//}

// Escape Artist
//{
constexpr const char* ESCAPE_ARTIST_NAME = "Escape Artist";
constexpr const char* ESCAPE_ARTIST_DESCRIPTION =
	"Discard all of the energy cards attached to one of your benched fighters.\n"
	"Return it and its previous ranks to your hand."
;
const std::string ESCAPE_ARTIST_EFFECTS(
	std::string(DRAIN_EFFECT) // drain
	+ EFFECT_SEPARATOR        //
	+ SELF_EFFECT             // self
	+ EFFECT_SEPARATOR        //
	+ BENCH_EFFECT            // bench
	+ EFFECT_SEPARATOR        //
	+ UNIVERSAL_EFFECT        // all
	+ EFFECT_TERMINATOR
	+ BOUNCE_EFFECT           // bounce
);
//}
//}

// Direct Damage
//{
// Assassin
//{
constexpr const char* ASSASSIN_NAME = "Assassin";
constexpr const char* ASSASSIN_DESCRIPTION =
	"Deal 200 damage to your opponent's active fighter."
;
const std::string ASSASSIN_EFFECTS(
	std::string(DAMAGE_EFFECT) // damage
	+ EFFECT_SEPARATOR         //
	+ "200"                    // 200
);
//}

// Sniper
//{
constexpr const char* SNIPER_NAME = "Sniper";
constexpr const char* SNIPER_DESCRIPTION =
	"Deal 150 damage to one of your opponent's fighters."
;
const std::string SNIPER_EFFECTS(
	std::string(SNIPE_EFFECT) // snipe
	+ EFFECT_SEPARATOR        //
	+ "150"                   // 150
);
//}
//}

// Power
//{
// Cheerleader
//{
constexpr const char* CHEERLEADER_NAME = "Cheerleader";
constexpr const char* CHEERLEADER_DESCRIPTION =
	"Attacks deal 100 more damage this turn."
;
const std::string CHEERLEADER_EFFECTS(
	std::string(POWER_EFFECT) // power
	+ EFFECT_SEPARATOR        //
	+ "100"                   // 100
);
//}

// Arms Smuggler
//{
constexpr const char* ARMS_SMUGGLER_NAME = "Arms Smuggler";
constexpr const char* ARMS_SMUGGLER_DESCRIPTION =
	"Deal 25 damage to one of your opponent's fighters.\n"
	"Attacks deal 25 more damage this turn.\n"
	"Shuffle this card into your deck instead of discarding it.\n"
	"Draw a card at the start of your turn."
;
const std::string ARMS_SMUGGLER_EFFECTS(
	std::string(SNIPE_EFFECT)  // snipe
	+ EFFECT_SEPARATOR         //
	+ "25"                     // 25
	+ EFFECT_TERMINATOR
	+ POWER_EFFECT             // power
	+ EFFECT_SEPARATOR         //
	+ "25"                     // 25
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT           // recycle
	+ EFFECT_TERMINATOR
	+ END_DRAW_EFFECT          // end_draw
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
);
//}

// Maniac
//{
constexpr const char* MANIAC_NAME = "Maniac";
constexpr const char* MANIAC_DESCRIPTION =
	"If your deck, hand, and bench are empty, "
	"attacks deal 10000 more damage this turn."
;
const std::string MANIAC_EFFECTS(
	std::string(EMPTY_DECK_EFFECT) // empty_deck
	+ EFFECT_TERMINATOR
	+ EMPTY_HAND_EFFECT            // empty_hand
	+ EFFECT_TERMINATOR
	+ EMPTY_BENCH_EFFECT           // empty_bench
	+ EFFECT_TERMINATOR
	+ POWER_EFFECT                 // power
	+ EFFECT_SEPARATOR             //
	+ "10000"                      // 10000
);
//}
//}

// Disruption
//{
// Peacemaker
//{
constexpr const char* PEACEMAKER_NAME = "Peacemaker";
constexpr const char* PEACEMAKER_DESCRIPTION =
	"If you haven't attacked this turn, both players' attacks "
	"deal 1000 less damage until the start of your next turn."
;
const std::string PEACEMAKER_EFFECTS(
	std::string(ATTACKLESS_EFFECT) // attackless
	+ EFFECT_TERMINATOR
	+ POWER_EFFECT                 // power
	+ EFFECT_SEPARATOR             //
	+ "-1000"                      // -1000
	+ EFFECT_TERMINATOR
	+ POWER_EFFECT                 // power
	+ EFFECT_SEPARATOR             //
	+ OPPONENT_EFFECT              // opponent
	+ EFFECT_SEPARATOR             //
	+ "-1000"                      // -1000
);
//}

// Matchmaker
//{
constexpr const char* MATCHMAKER_NAME = "Matchmaker";
constexpr const char* MATCHMAKER_DESCRIPTION =
	"Your opponent's active fighter can't retreat during their next turn."
;
constexpr const char* MATCHMAKER_EFFECTS = ROOT_EFFECT;
//}

// Plumber
//{
constexpr const char* PLUMBER_NAME = "Plumber";
constexpr const char* PLUMBER_DESCRIPTION =
	"Discard an energy card attached to one your opponent's fighters."
;
const std::string PLUMBER_EFFECTS(
	std::string(DRAIN_EFFECT) // drain
	+ EFFECT_SEPARATOR        //
	+ "1"                     // 1
);
//}

// Locksmith
//{
constexpr const char* LOCKSMITH_NAME = "Locksmith";
constexpr const char* LOCKSMITH_DESCRIPTION =
	"Shuffle both player's hands into their decks.\n"
	"Both players draw 3 cards."
;
const std::string LOCKSMITH_EFFECTS(
	std::string(SHUFFLE_EFFECT) // shuffle
	+ EFFECT_SEPARATOR          //
	+ OPPONENT_EFFECT           // opponent
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ SHUFFLE_EFFECT            // shuffle
	+ EFFECT_SEPARATOR          //
	+ UNIVERSAL_EFFECT          // all
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ OPPONENT_EFFECT           // opponent
	+ EFFECT_SEPARATOR          //
	+ "3"                       // 3
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT               // draw
	+ EFFECT_SEPARATOR          //
	+ "3"                       // 3
);
//}

// Lock Picker
//{
constexpr const char* LOCK_PICKER_NAME = "Lock Picker";
constexpr const char* LOCK_PICKER_DESCRIPTION =
	"Return all energy cards in play to their owners' hands."
;
constexpr const char* LOCK_PICKER_EFFECTS = ENERGY_BOUNCE_EFFECT; // energy_bounce
//}

// Gatekeeper
//{
constexpr const char* GATEKEEPER_NAME = "Gatekeeper";
constexpr const char* GATEKEEPER_DESCRIPTION =
	"Your opponent can play one less card next turn.\n"
	"Return this card to your hand.\n"
	"At the end of your turn, discard this card."
;
const std::string GATEKEEPER_EFFECTS(
	std::string(DEPLAY_EFFECT) // deplay
	+ EFFECT_SEPARATOR         //
	+ "1"                      // 1
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT           // recycle
	+ EFFECT_SEPARATOR         //
	+ HAND_EFFECT              // hand
	+ EFFECT_TERMINATOR
	+ END_DISCARD_EFFECT       // end_discard
);
//}

// Miller
//{
constexpr const char* MILLER_NAME = "Miller";
constexpr const char* MILLER_DESCRIPTION =
	"Discard the top 2 cards of both player's deck.\n"
	"Return this card to your hand.\n"
	"At the end of your turn, discard this card."
;
const std::string MILLER_EFFECTS(
	std::string(MILL_EFFECT) // mill
	+ EFFECT_SEPARATOR       //
	+ "2"                    // 2
	+ EFFECT_TERMINATOR
	+ MILL_EFFECT            // mill
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ "2"                    // 2
	+ EFFECT_TERMINATOR
	+ RECYCLE_EFFECT         // recycle
	+ EFFECT_SEPARATOR       //
	+ HAND_EFFECT            // hand
	+ EFFECT_TERMINATOR
	+ END_DISCARD_EFFECT     // end_discard
);
//}

// Arsonist
//{
constexpr const char* ARSONIST_NAME = "Arsonist";
constexpr const char* ARSONIST_DESCRIPTION =
	"Banish the top 3 cards of each player's deck.\n"
	"Search your deck for a card."
;
const std::string ARSONIST_EFFECTS(
	std::string(MILL_EFFECT) // mill
	+ EFFECT_SEPARATOR       //
	+ BANISH_EFFECT          // banish
	+ EFFECT_SEPARATOR       //
	+ "3"                    // 3
	+ EFFECT_TERMINATOR
	+ MILL_EFFECT            // mill
	+ EFFECT_SEPARATOR       //
	+ SELF_EFFECT            // self
	+ EFFECT_SEPARATOR       //
	+ BANISH_EFFECT          // banish
	+ EFFECT_SEPARATOR       //
	+ "3"                    // 3
	+ EFFECT_TERMINATOR
	+ SEARCH_EFFECT          // search
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
);
//}
//}
//}

// Energy Cards
//{
// Basic Energy
//{
// Universal Basic Energy Constants
//{
constexpr const char* BASIC_ENERGY_DESCRIPTION =
	"Provides 1000 energy for fighters of this element.\n"
	"When this energy card is played, draw a card."
;
const std::string BASIC_ENERGY_EFFECTS(
	std::string(DRAW_EFFECT) // draw
	+ EFFECT_SEPARATOR       //
	+ "1"                    // 1
);
constexpr int BASIC_ENERGY_VALUE = 1000;
//}

// Fire Energy
//{
constexpr const char* FIRE_ENERGY_NAME = "Fire Energy";
constexpr const char* FIRE_ENERGY_DESCRIPTION = BASIC_ENERGY_DESCRIPTION;
constexpr const char* FIRE_ENERGY_ELEMENT = FIRE_ELEMENT;
const std::string FIRE_ENERGY_EFFECTS(BASIC_ENERGY_EFFECTS);
constexpr int FIRE_ENERGY_VALUE = BASIC_ENERGY_VALUE;
//}

// Air Energy
//{
constexpr const char* AIR_ENERGY_NAME = "Air Energy";
constexpr const char* AIR_ENERGY_DESCRIPTION = BASIC_ENERGY_DESCRIPTION;
constexpr const char* AIR_ENERGY_ELEMENT = AIR_ELEMENT;
const std::string AIR_ENERGY_EFFECTS(BASIC_ENERGY_EFFECTS);
constexpr int AIR_ENERGY_VALUE = BASIC_ENERGY_VALUE;
//}

// Water Energy
//{
constexpr const char* WATER_ENERGY_NAME = "Water Energy";
constexpr const char* WATER_ENERGY_DESCRIPTION = BASIC_ENERGY_DESCRIPTION;
constexpr const char* WATER_ENERGY_ELEMENT = WATER_ELEMENT;
const std::string WATER_ENERGY_EFFECTS(BASIC_ENERGY_EFFECTS);
constexpr int WATER_ENERGY_VALUE = BASIC_ENERGY_VALUE;
//}

// Earth Energy
//{
constexpr const char* EARTH_ENERGY_NAME = "Earth Energy";
constexpr const char* EARTH_ENERGY_DESCRIPTION = BASIC_ENERGY_DESCRIPTION;
constexpr const char* EARTH_ENERGY_ELEMENT = EARTH_ELEMENT;
const std::string EARTH_ENERGY_EFFECTS(BASIC_ENERGY_EFFECTS);
constexpr int EARTH_ENERGY_VALUE = BASIC_ENERGY_VALUE;
//}
//}

// Special Energy
//{
// Void Energy
//{
constexpr const char* VOID_ENERGY_NAME = "Void Energy";
constexpr const char* VOID_ENERGY_DESCRIPTION =
	"Provides 3000 energy for fighters of this element."
;
constexpr const char* VOID_ENERGY_ELEMENT = NO_ELEMENT;
constexpr const char* VOID_ENERGY_EFFECTS = NO_EFFECTS;
constexpr int VOID_ENERGY_VALUE = 3000;
//}

// Universal Energy
//{
constexpr const char* UNIVERSAL_ENERGY_NAME = "Universal Energy";
constexpr const char* UNIVERSAL_ENERGY_DESCRIPTION =
	"Provides 1000 energy for fighters of all elements."
;
constexpr const char* UNIVERSAL_ENERGY_ELEMENT = NO_ELEMENT;
constexpr const char* UNIVERSAL_ENERGY_EFFECTS = UNIVERSAL_EFFECT; // all
constexpr int UNIVERSAL_ENERGY_VALUE = 1000;
//}

// Alpha Energy
//{
constexpr const char* ALPHA_ENERGY_NAME = "Alpha Energy";
constexpr const char* ALPHA_ENERGY_DESCRIPTION =
	"Provides 250 energy for fighters of all elements.\n"
	"When this energy card is played, draw a card.\n"
	"You can play 1 more card this turn."
;
constexpr const char* ALPHA_ENERGY_ELEMENT = NO_ELEMENT;
const std::string ALPHA_ENERGY_EFFECTS(
	std::string(UNIVERSAL_EFFECT) // all
	+ EFFECT_TERMINATOR
	+ DRAW_EFFECT                 // draw
	+ EFFECT_SEPARATOR            //
	+ "1"                         // 1
	+ EFFECT_TERMINATOR
	+ EXTRA_PLAY_EFFECT           // extra_play
	+ EFFECT_SEPARATOR            //
	+ "1"                         // 1
);
constexpr int ALPHA_ENERGY_VALUE = 250;
//}

// Omega Energy
//{
constexpr const char* OMEGA_ENERGY_NAME = "Omega Energy";
constexpr const char* OMEGA_ENERGY_DESCRIPTION =
	"Provides 2000 energy for fighters of all elements.\n"
	"When this energy card is played, discard a card from your hand.\n"
	"You can play 1 less card this turn."
;
constexpr const char* OMEGA_ENERGY_ELEMENT = NO_ELEMENT;
const std::string OMEGA_ENERGY_EFFECTS(
	std::string(UNIVERSAL_EFFECT) // all
	+ EFFECT_TERMINATOR
	+ DISCARD_EFFECT              // discard
	+ EFFECT_SEPARATOR            //
	+ "1"                         // 1
	+ EFFECT_TERMINATOR
	+ OVERLOAD_EFFECT             // overload
	+ EFFECT_SEPARATOR            //
	+ "1"                         // 1
);
constexpr int OMEGA_ENERGY_VALUE = 2000;
//}

// Bond Energy
//{
constexpr const char* BOND_ENERGY_NAME = "Bond Energy";
constexpr const char* BOND_ENERGY_DESCRIPTION =
	"Provides 750 energy for fighters of all elements.\n"
	"When the fighter, that this energy card is attached to, ranks up, "
	"draw the old rank instead of discarding it."
;
constexpr const char* BOND_ENERGY_ELEMENT = NO_ELEMENT;
const std::string BOND_ENERGY_EFFECTS(
	std::string(UNIVERSAL_EFFECT) // all
	+ EFFECT_TERMINATOR
	+ BOND_EFFECT                 // bond
);
constexpr int BOND_ENERGY_VALUE = 750;
//}
//}
//}