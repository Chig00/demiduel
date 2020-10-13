const DeckCode AGGRO_DECK(
    "Aggro",
    "This is an aggressive deck that uses Hot Rodder and "
    "Pyrotechnician to deal high amounts of damage every turn!\n\n"
    "Hydromancer helps to force out key targets and lock them in the active position!\n\n"
    "Various supporter cards in the deck can be used to make quick "
    "work of the opponent's important or unranked fighters.",
    {
        // Fighter Cards
        1, // DRIVER
        1, // RACER
        1, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        1, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        1, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        1, // WELDER
        1, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        1, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        1, // RECRUITER
        
        0, // CHEF
        1, // TRADER
        1, // LIBRARIAN
        0, // EXPERIMENTER
        1, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        1, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        1, // BOUNTY HUNTER
        
        1, // NURSE
        0, // INNKEEPER
        0, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        1, // ASSASSIN
        1, // SNIPER
        
        1, // CHEERLEADER
        1, // ARMS SMUGGLER
        0, // MANIAC
        
        0, // PEACEMAKER
        1, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        0, // LOCK PICKER
        1, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        2, // FIRE ENERGY
        0, // AIR ENERGY
        2, // WATER ENERGY
        0, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        0, // ALPHA ENERGY
        1, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

const DeckCode TEMPO_DECK(
    "Tempo",
    "This is an offensive deck that focuses on being efficient with card plays.\n\n"
    "Swimmer, Welder, and Wind Runner can attach energy to themselves "
    "directly from the deck with their ability, Energy Acceleration!\n\n"
    "This makes it easier to play important Fighter and Supporter cards, "
    "as you don't need to focus on drawing and playing Energy cards!",
    {
        // Fighter Cards
        0, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        0, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        1, // SWIMMER
        1, // SCUBA DIVER
        1, // WELDER
        1, // PYROTECHNICIAN
        1, // WIND RUNNER
        1, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        1, // RECRUITER
        
        0, // CHEF
        1, // TRADER
        1, // LIBRARIAN
        0, // EXPERIMENTER
        0, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        1, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        1, // BOUNTY HUNTER
        
        1, // NURSE
        0, // INNKEEPER
        1, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        1, // ASSASSIN
        1, // SNIPER
        
        1, // CHEERLEADER
        1, // ARMS SMUGGLER
        0, // MANIAC
        
        0, // PEACEMAKER
        1, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        0, // LOCK PICKER
        1, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        2, // FIRE ENERGY
        2, // AIR ENERGY
        2, // WATER ENERGY
        0, // EARTH ENERGY
        
        1, // UNIVERSAL ENERGY
        0, // ALPHA ENERGY
        0, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

const DeckCode BLEND_DECK(
    "Blend",
    "This is an offensive deck that also has some defensive options.\n\n"
    "Monster Trucker can heal itself and has an attack that gains power over time!\n\n"
    "Warlock deals a ton of damage and can return cards from the trash back to the hand!\n\n"
    "Scuba Diver can be used to stall, burst, or maintain tempo when played.",
    {
        // Fighter Cards
        1, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        1, // DIRT BIKER
        1, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        1, // MAGE
        0, // PYROMANCER
        1, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        1, // SWIMMER
        1, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        1, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        1, // RECRUITER
        
        0, // CHEF
        1, // TRADER
        1, // LIBRARIAN
        0, // EXPERIMENTER
        1, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        1, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        1, // BOUNTY HUNTER
        
        1, // NURSE
        1, // INNKEEPER
        1, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        1, // ASSASSIN
        1, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        0, // PEACEMAKER
        1, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        0, // LOCK PICKER
        1, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        2, // WATER ENERGY
        2, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        0, // ALPHA ENERGY
        1, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

const DeckCode CONTROL_DECK(
    "Control",
    "This is a defensive deck that focuses on keeping its "
    "fighters healthy to eventually overcome the opponent.\n\n"
    "Cleric heals all of the friendly fighters at the end of your turn!\n\n"
    "Astronaut can allow fighters to retreat freely to "
    "distribute splash healing as efficiently as possible!\n\n"
    "Excavator can return energy cards to hand and shuffle them "
    "back into the deck to slow down aggressive opponents.",
    {
        // Fighter Cards
        1, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        1, // PILOT
        1, // ASTRONAUT
        
        1, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        1, // CLERIC
        0, // HYDROMANCER
        
        1, // MINER
        1, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        0, // LECTURER
        0, // INVESTOR
        1, // RESEARCHER
        1, // GAMBLER
        0, // RECRUITER
        
        1, // CHEF
        0, // TRADER
        0, // LIBRARIAN
        0, // EXPERIMENTER
        0, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        0, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        0, // BANKER
        1, // GLUTTON
        
        0, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        1, // NURSE
        1, // INNKEEPER
        1, // MIRACLE WORKER
        1, // DOCTOR
        1, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        1, // PEACEMAKER
        0, // MATCHMAKER
        1, // PLUMBER
        1, // LOCKSMITH
        1, // LOCK PICKER
        0, // GATEKEEPER
        1, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        1, // AIR ENERGY
        0, // WATER ENERGY
        2, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        2, // ALPHA ENERGY
        0, // OMEGA ENERGY
        2  // BOND ENERGY
    }
);

const DeckCode MILL_DECK(
    "Mill",
    "This is a mill deck that focuses on emptying the opponent's "
    "deck, in order to make them draw life cards.\n\n"
    "Lost Soul is a tutor card that is used to draw Mage and Pyromancer.\n\n"
    "Pyromancer can discard random cards from your opponent's deck.\n\n"
    "Glutton shuffles discarded energy cards back into the deck, "
    "so you don't draw life cards while your opponent does!\n\n"
    "Lost Soul, Miller, and Arsonist also help to mill the opponent.\n\n"
    "Boxer can protect Pyromancer from being forced into the active position.",
    {
        // Fighter Cards
        0, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        1, // MAGE
        1, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        1, // BOXER
        1, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        0, // RECRUITER
        
        0, // CHEF
        0, // TRADER
        1, // LIBRARIAN
        0, // EXPERIMENTER
        0, // PERSONAL TRAINER
        1, // SCAPEGOAT
        
        0, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        1, // BANKER
        1, // GLUTTON
        
        0, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        1, // NURSE
        1, // INNKEEPER
        1, // MIRACLE WORKER
        1, // DOCTOR
        0, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        1, // PEACEMAKER
        0, // MATCHMAKER
        1, // PLUMBER
        1, // LOCKSMITH
        1, // LOCK PICKER
        0, // GATEKEEPER
        1, // MILLER
        1, // ARSONIST
        
        // Energy Cards
        2, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        2, // UNIVERSAL ENERGY
        2, // ALPHA ENERGY
        2, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

const DeckCode MIDRANGE_DECK(
    "Midrange",
    "This is a midrange deck that is powered up with the size of the Void.\n\n"
    "Banisher sends cards in your trash to the Void to empower your fighters!\n\n"
    "Banshee is the deck's main big hitter and is energised and empowered by the Void!\n\n"
    "Cultist can use the attack of any banished fighter and heal any friendly fighter!\n\n"
    "Omega Elemental is a fighter that can be banished, so Cultist can use its attack.\n\n"
    "Arsonist is a disruptive supporter card that also strengthens your fighters.",
    {
        // Fighter Cards
        0, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        0, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        1, // BANISHER
        1, // BANSHEE
        1, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        1, // OMEGA ELEMENTAL
        
        // Supporter Cards
        1, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        1, // RECRUITER
        
        1, // CHEF
        1, // TRADER
        1, // LIBRARIAN
        1, // EXPERIMENTER
        0, // PERSONAL TRAINER
        1, // SCAPEGOAT
        
        1, // ELECTRICIAN
        0, // ALCHEMIST
        0, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        1, // SUBSTITUTE
        1, // BOUNTY HUNTER
        
        1, // NURSE
        1, // INNKEEPER
        1, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        1, // ASSASSIN
        1, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        1, // PEACEMAKER
        1, // MATCHMAKER
        1, // PLUMBER
        1, // LOCKSMITH
        0, // LOCK PICKER
        0, // GATEKEEPER
        0, // MILLER
        1, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        2, // UNIVERSAL ENERGY
        0, // ALPHA ENERGY
        2, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

const DeckCode AGGRO_COMBO_DECK(
    "Aggro Combo",
    "This is a combo-oriented offensive deck that uses Ninja "
    "and Samurai to deal a huge amount of damage every turn!\n\n"
    "Ninja and Samurai have the ability to attack in tandem!\n\n"
    "If one of them attacks and the other is benched "
    "with enough energy to attack, it also attacks!\n\n"
    "Ninja and Samurai both rank up from the same "
    "fighter, so Bond Energy can help to get them "
    "both in play without dicarding their old ranks.\n\n"
    "Lost Soul, Personal Trainer, and Ascension can "
    "help to get the combo attackers in play quickly.",
    {
        // Fighter Cards
        0, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        0, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        0, // BOXER
        1, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        1, // APPRENTICE
        1, // SENSEI'S CHOSEN
        1, // NINJA
        1, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        1, // RESEARCHER
        1, // GAMBLER
        0, // RECRUITER
        
        1, // CHEF
        1, // TRADER
        1, // LIBRARIAN
        0, // EXPERIMENTER
        1, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        1, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        1, // NURSE
        0, // INNKEEPER
        1, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        1, // CHEERLEADER
        1, // ARMS SMUGGLER
        0, // MANIAC
        
        1, // PEACEMAKER
        1, // MATCHMAKER
        1, // PLUMBER
        1, // LOCKSMITH
        0, // LOCK PICKER
        1, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        1, // UNIVERSAL ENERGY
        2, // ALPHA ENERGY
        0, // OMEGA ENERGY
        2  // BOND ENERGY
    }
);

const DeckCode CONTROL_COMBO_DECK(
    "Control Combo",
    "This is a combo-oriented, defensive deck that uses elementals.\n\n"
    "The 4 basic elementals are weak unranked fighters.\n\n"
    "However, if all of them are in play simultaneously, "
    "they can fuse into the Omega Elemental!\n\n"
    "The Omega Elemental is an exceptionally powerful fighter that can "
    "heal itself and generate copies of your opponent's cards!\n\n"
    "Omega Elemental is also capable of using the OTK Combo!",
    {
        // Fighter Cards
        0, // DRIVER
        0, // RACER
        0, // HOT RODDER
        0, // SAILOR
        0, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        0, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        0, // MINER
        0, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        0, // WIND RUNNER
        0, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        1, // FIRE ELEMENTAL
        1, // AIR ELEMENTAL
        1, // WATER ELEMENTAL
        1, // EARTH ELEMENTAL
        1, // OMEGA ELEMENTAL
        
        // Supporter Cards
        1, // PROFESSOR
        1, // LECTURER
        1, // INVESTOR
        1, // RESEARCHER
        1, // GAMBLER
        1, // RECRUITER
        
        1, // CHEF
        1, // TRADER
        1, // LIBRARIAN
        1, // EXPERIMENTER
        0, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        0, // ELECTRICIAN
        0, // ALCHEMIST
        0, // TIME TRAVELLER
        1, // BANKER
        0, // GLUTTON
        
        1, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        1, // NURSE
        0, // INNKEEPER
        1, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        1, // MANIAC
        
        1, // PEACEMAKER
        0, // MATCHMAKER
        1, // PLUMBER
        1, // LOCKSMITH
        1, // LOCK PICKER
        1, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        2, // UNIVERSAL ENERGY
        2, // ALPHA ENERGY
        1, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

const DeckCode OTK_COMBO_DECK(
    "OTK Combo",
    "This is a one-turn kill combo deck that aims to defeat "
    "all of the opponent's fighters in a single turn!\n\n"
    "Maniac boosts damage to the sky, if the player's deck, hand, and bench are empty!\n\n"
    "Cloud Surfer attacks all opposing fighters simultaneously, so Maniac "
    "allows it to defeat all of the opposing fighters in one fell swoop!\n\n"
    "Emptying the deck, playing Banker to shuffle Maniac into the "
    "deck, and playing Professor is one way to pull off the combo.\n\n"
    "Pirate and Excavator can help to find combo pieces.",
    {
        // Fighter Cards
        1, // DRIVER
        0, // RACER
        0, // HOT RODDER
        1, // SAILOR
        1, // PIRATE
        0, // DIRT BIKER
        0, // MONSTER TRUCKER
        0, // PILOT
        0, // ASTRONAUT
        
        0, // MAGE
        0, // PYROMANCER
        0, // WARLOCK
        0, // CLERIC
        0, // HYDROMANCER
        
        1, // MINER
        1, // EXCAVATOR
        0, // SWIMMER
        0, // SCUBA DIVER
        0, // WELDER
        0, // PYROTECHNICIAN
        1, // WIND RUNNER
        1, // CLOUD SURFER
        
        0, // BOXER
        0, // LOST SOUL
        
        0, // BANISHER
        0, // BANSHEE
        0, // CULTIST
        
        0, // APPRENTICE
        0, // SENSEI'S CHOSEN
        0, // NINJA
        0, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        1, // PROFESSOR
        0, // LECTURER
        0, // INVESTOR
        1, // RESEARCHER
        1, // GAMBLER
        0, // RECRUITER
        
        1, // CHEF
        0, // TRADER
        0, // LIBRARIAN
        1, // EXPERIMENTER
        0, // PERSONAL TRAINER
        1, // SCAPEGOAT
        
        0, // ELECTRICIAN
        1, // ALCHEMIST
        1, // TIME TRAVELLER
        1, // BANKER
        0, // GLUTTON
        
        1, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        1, // NURSE
        0, // INNKEEPER
        1, // MIRACLE WORKER
        0, // DOCTOR
        1, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        1, // MANIAC
        
        1, // PEACEMAKER
        0, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        1, // LOCK PICKER
        0, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        2, // AIR ENERGY
        1, // WATER ENERGY
        2, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        2, // ALPHA ENERGY
        0, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);c