/* CHANGELOG:
	 v1.9:
	   The number of cards in the starting hand was increased from 6 to 7.
	   Professor's draw was increased from 6 to 7.
	   Lecturer's draw was increased from 5 to 6.
	   Investor's draw was increased from 7 to 8.
	   Changes to the decklists.
     v1.8:
	   The number of copies of a single energy card was decreased from 4 to 2.
	   Heat Wave's cost was decreased from 2000 to 0.
	   Cleric's element was changed from the Water to Air.
	   Radiant Pulse's cost was decreased from 2000 to 1000.
	   Vacuumancer was renamed to Hydromancer.
	   Hydromancer's element was changed from Air to Water.
	   Hydromancer's retreat cost was decreased from 2000 to 1000.
	   Air Lock was renamed to Whirlpool.
	   Slipstream's damage was decreased from 650 to 600.
	   Slipstream's cost was decreased from 2000 to 1000.
	   Sensei's Chosen's retreat cost was decreased from 1500 to 1000.
	   Flying Kick's cost was decreased from 1500 to 1000.
	   Ninja's retreat cost was decreased from 500 to 0.
	   Shuriken Storm's cost was decreased from 1500 to 1000.
	   Samurai's retreat cost was decreased from 1500 to 1000.
	   Subjugate's cost was decreased from 1500 to 1000.
	   Changes to the decklists.
	 v1.7.1:
	   Miner's health was decreased from 1200 to 1100.
	   Swimmer's health was decreased from 1100 to 1050.
	   Banshee's health was decreased from 1200 to 1100.
	   Screech's damage scaling was increased from 55 to 60.
	   Screech's maximum damage was increased from 800 to 900.
	   Screech's cost was decreased from 4000 to 2000.
	   Void Pact's maximum healing was decreased from 400 to 375.
	   Shadow Bond's cost was decreased from 3000 to 2000.
	   Unify was renamed to Synthesise.
	   Synthesise now generates a copy of the chosen card instead of taking it.
	   Synthesise no longer announces the chosen card.
	   Assimilate no longer attempts to deal damage to defeated fighters.
	   Changes to some decklists.
	   Added CARDS.hpp which records all of the card data in the game.
	   Changed DECKLISTS.txt and CHANGELOG.txt to .hpp files.
	 v1.7:
	   The card, Recruiter, was added to the game.
	   Airborne now correctly provides 2000 Agility Aura instead of 2500.
	   Shuriken Storm now has 2 snipes minimum.
	   Shuriken Storm now flips 2 coins and gains an extra snipe for each heads flipped.
	   Gambler now flips 2 coins and gains an extra draw for each heads flipped.
	   Doctor's healing scaling was increased from 400 to 500.
	   Changed the starting fighter prompt.
	   The changelog's ordering was reversed.
	   Added CHANGELOG.txt which records all of the changes to this game.
	   Added DECKLISTS.txt which records all of the premade decklists.
	 v1.6.2:
	   Quick Fix's healing was reduced from 250 to 200.
	   Scrap Metal's healing was reduced from 450 to 400.
	   Incinerate's opposing mill was decreased from 3 to 2.
	   Shadow Bond will terminate if a mimic attack is chosen.
	   Katana Slash was renamed to Subjugate.
	   Trader no longer draws nothing when the deck has no energy cards.
	   Innkeeper's healing scaling was increased from 300 to 400.
	   Doctor's healing scaling was increased from 250 to 400.
	   Escape Artist no longer causes a stalemate when played with an empty bench.
	   Matchmaker now roots instead of crippling.
	   Miller's mill was decreased from 3 to 2.
	   Arsonist now searches for a card after banish milling.
	   Changes to the decklists.
	 v1.6.1:
	   Shred's damage scaling was increased from 5 to 7.
	   Crush's damage scaling was increased from 10 to 15.
	   Excavator's retreat cost was decreased from 3000 to 2000.
	   Tunnel's cost was decreased from 2000 to 1000.
	   Pyromaniac was renamed to Pyromania.
	   Primed Payload's damage scaling was decreased from 0.275 to 0.25.
	   Primed Payload's damage cap was decreased from 700 to 650.
	   Boxer's health was decreased from 1100 to 1000.
	   Haymaker's base damage was deceased from 800 to 600.
	   Shadow Flame's damage scaling was increased from 30 to 40.
	   Forbidden Fuel's energy scaling was increased from 200 to 250.
	   Screech's damage scaling was increased from 40 to 55.
	   Void Pact's healing scaling was increased from 20 to 25.
	   Omega Elemental was returned to the Midrange deck.
	   Changes to Glutton's description.
	   Audio was removed from the mobile version.
	 v1.6.0.1:
	   Removed a useless RNG call that desynchronised the desktop and mobile versions.
	   Reoredered the fighters - the Unranked Family was moved before the Void Family.
	   README.txt was updated.
	 v1.6:
	   The number of cards per deck has been reduced from 40 to 30.
	   The number of cards in the starting hand have been reduced from 10 to 6.
	   An unranked fighter is always guaranteed to be drawn in the initial starting hand.
	   Life cards can now store energy cards when there are no supporter cards in the deck.
	   Life cards can now store fighter cards when there are no other cards in the deck.
	   Professor's draw count was reduced from 8 to 6.
	   Lecturer's draw count was reduced from 7 to 5.
	   Investor's draw count was reduced from 9 to 7.
	   Researcher's draw count was reduced from 3 to 2.
	   Gambler's draw count with heads was reduced from 6 to 4.
	   Locksmith's draw count was decreased from 4 to 3.
	   Major changes to all of the decklists.
	   Drawing from empty card stores or substores throws an exception.
     v1.5:
	   The number of life cards was decreased from 4 to 3.
	   The number of cards in the starting hand was increased from 8 to 10.
	   Dirt Biker's health was decreased from 1300 to 1250.
	   Dirt Biker's retreat cost was decreased from 2000 to 1500.
	   Quick Fix's healing was reduced from 400 to 250.
	   Shred's cost was reduced from 2000 to 1500.
	   Monster Trucker's health was decreased from 1600 to 1500.
	   Monster Trucker's retreat cost was decreased from 3000 to 2000.
	   Scrap Metal's healing was decreased from 600 to 450.
	   Pilot's health was increased from 1250 to 1300.
	   Pilot's retreat cost was decreased from 2500 to 1000.
	   Airborne's agility aura was decreased from 2500 to 2000.
	   Divebomb's damage was increased from 300 to 400.
	   Divebomb's agility reduction was decreased from 2500 to 1000.
	   Divebomb's cost was increased from 500 to 1000.
	   Astronaut's health was increased from 1500 to 1600.
	   Astronaut's retreat cost was decreased from 4000 to 2000.
	   Zero Gravity's agility aura was decreased from 4000 to 2000.
	   Gravity Flip's damage was increased from 450 to 500.
	   Gravity Flip's agility reduction was decreased from 4000 to 2000.
	   Gravity Flip's cost was increased form 500 to 1000.
	   Healing Aura's healing was increased from 100 to 125.
	   Vacuum Wave was renamed to Air Lock.
	   Banshee's retreat cost was decreased from 4000 to 2000.
	   Void Pact's scaling was decreased from 25 to 20.
	   Void Pact's ceiling was decreased from 500 to 400.
	   Omega Fusion's defeat requirement was decreased from 3 to 2.
	   Omega Elemental's health was decreased from 2000 to 1500.
	   Omega Elemental's retreat cost was decreased from 2000 to 0.
	   Major changes to the decklists' contents and descriptions.
	 v1.4:
	   sdlandnet v2.1 is now used.
	   std::uniform_int_distribution instances have been replaced with calls
	     to the function, Random::get_int() (for cross-platform synchronisation).
	 v1.3.5:
	   Incinerate's opposing mill count was decreased from 4 to 3.
	   Incinerate's friendly mill count was decreased from 3 to 2.
	   Katana Slash's damage was decreased from 300 to 275.
	   Assimilate's damage was decreased from 800 to 700.
	   Assimilate's healing ratio was increased from 0.375 to 0.5.
	   Miller's mill count was increased from 2 to 3.
	   Changes to some of the decklists.
	 v1.3.4.1:
	   Hooks are no longer announced twice.
	 v1.3.4:
	   Time Traveller's extra play count was decreased from 2 to 1.
	   Time Traveller's overload was decreased from 3 to 2.
	   Changes to some of the decklists.
	   Reduction in the size of some of the assets.
	 v1.3.3:
	   Drift's cost was decreased from 1000 to 0.
	   Mage's retreat cost was decreased from 2000 to 1000.
	   Shadow Bond's cost was decreased from 4000 to 3000.
	   The Basic Elementals' attack damage was increased from 200 to 250.
	   Assimilate's damage was decreased from 1000 to 800.
	   Assimilate's healing ratio was increased from 0.2 to 0.375.
	   Alpha Energy's energy value was decreased from 500 to 250.
	   Omega Energy now overloads one play.
	   Bond Energy's energy value was increased from 500 to 750.
	 v1.3.2.1:
	   Rooting is no longer a perpetual effect.
	 v1.3.2:
	   Slipstream's damage was decreased from 700 to 650.
	   Primed Payload's damage scaling was decreased from 0.35 to 0.275.
	   SHadow Bond's cost was increased from 2000 to 4000.
	   Substite now gives an extra play.
	   Doctor's heal scaling was increased from 200 to 250.
	   Arms Smuggler no longer deals damage to the opponent's active fighter.
	   Arms Smuggler's snipe damage was increased from 15 to 25.
	   Arms Smuggler's power boost was increased from 10 to 25.
	   Alpha Energy now gives an extra play.
	   Some changes to the decklists.
	 v1.3.1.1:
	   Various decklists were renamed.
	   Various decklist descriptions have been modified.
	   Splash no longer uses the plural for singular cases.
	 v1.3.1:
	   Racer's health was decreased from 1250 to 1200.
	   Hot Rodder's health was decreased from 1500 to 1400.
	   Pilot's health was increased from 1200 to 1250.
	   Divebomb's damage was decreased from 350 to 300.
	   Divebomb's cost was decreased from 1000 to 500.
	   Astronaut's health was increased from 1400 to 1500.
	   Gravity Flip's damage was decreased from 450 to 400.
	   Gravity Flip's cost was decreased from 1000 to 500.
	   Submerge now prevents the user from switching out.
	   Undercurrent's damage was increased from 500 to 550.
	   Undercurrent's damage boost was decreased from 500 to 250.
	   Time Traveller no longer mills the player.
	   Time Traveller now decreases the number of plays for the next turn.
	   Time Traveller now increases the number of plays for this turn.
	   Arms Smuggler now deals 20 damage to the opponent's active fighter.
	   Arms Smuggler now deals 15 damage to one of the opponent's fighters.
	   Arms Smuggler's power boost was decreased from 50 to 10.
	   An effect explanation for fatigue (empty deck) has been added.
	   The "shuffle all" announcement no longer displays the card shuffled in.
	   The agility announcement has been fixed.
	 v1.3.0.2:
	   Added demiduellocal and demiduelversionlocal to the .zip archive.
	   Corrected a typo in Magic Missiles' cost reduction.
	 v1.3.0.1:
	   Time Traveller was renamed to Arms Smuggler.
	   Smuggler was renamed to Time Traveller.
	 v1.3:
	   The card, Time Traveller, was added.
	   Chef's search count was increased from 1 to 2.
	   Electrician's search count was increased from 1 to 2.
	   Changes to the decklists' contents.
	 v1.2:
	   The card, Gatekeeper, was added.
	   The player going second can now play an extra card on their first turn.
	   README.txt was updated to reflect this.
	   Magic Missiles' cost was decreased from 2000 to 1000.
	   Incinerate's opposing mill count was decreased from 5 to 4.
	   Incinerate's self mill count was decreased from 4 to 3.
	   Heat Wave now deals the correct amount of damage to the opponent's active fighter.
	   Windfall's damage decrease was decreased from 400 to 300.
	   Hurricane's damage was increased from 200 to 250.
	   Banisher's health was decreased from 1300 to 1100.
	   Shadow Flame is now included in the attack boost explanation.
	   Void Pact's scaling was decreased from 30 to 25.
	   Void Pact's healing cap was decreased from 600 to 500.
	   Shadow Bond's cost was increased from 1000 to 2000.
	   Innkeeper's healing was increased from 250 to 300.
	   Peacemaker's damage decrease was increased from 500 to 1000.
	   The opponent's number of plays for their next turn is now displayed.
	   The number of versions included in the versions folder were decreased.
	   Only major versions will be included from now on.
	   Changes to the decklists' contents.
	 v1.1.7.1:
	   Fixed a bug where Katana Slash crashed the game with a heads flip.
	   Fixed a bug, where Samurai's text exceeded the length of the screen.
	 v1.1.7:
	   Accelerate's damage boost was decreased from 150 to 100.
	   Charged Thruster's damage boost was decreased from 250 to 200.
	   Super Nitro's damage was increased from 450 to 500.
	   Pyromancer's health was decreased from 1400 to 1200.
	   Incinerate's opposing mill was increased from 4 to 5.
	   Incinerate now searches the deck for a card (after milling).
	   Blowtorch's damage was increased from 300 to 350.
	   Primed Payload's scaling was increased from 300 to 350.
	   Primed Payload's damage cap was decreased from 800 to 700.
	   Gust's cost was decreased from 1500 to 1000.
	   Hurricane's cost was decreased from 3000 to 2000.
	   Changes to some of the decklists.
	   Changes to some of the announcements.
	 v1.1.6:
	   Incinerate's mill count was decreased from 5 to 4.
	   Miller's mill count was increased from 1 to 2.
	   Void's description was changed.
	 v1.1.5:
	   Void Pact now banishes a card in hand.
	   Void Pact's scaling was increased from 15 to 30.
	   Void Pact's maximum healing was increased from 300 to 600.
	   Shadow Bond's attack cost was reduced from 2000 to 1000.
	   The "Void" deck now uses Vacuumancer.
	   The "End Draw" explanation has been renamed to "Invested".
	 v1.1.4:
	   Pyromancer's health was increased from 1200 to 1400.
	   Lecturer's draw count was increased from 6 to 7.
	   Investor's draw count was increased from 8 to 9.
	 v1.1.3.1:
	   The opponent having running out of life cards from
	     fatigue no longer produces multiple announcements.
	 v1.1.3.0:
	   Quick Fix's healing was increased from 200 to 400.
	   Scrap Metal's healing was increased from 400 to 600.
	   Crush's base damage was increased from 400 to 500.
	   demiduelverion and demiduelversionmini no longer use the "v" for the version.
	 v1.1.2.1:
	   Burnt Offering's effects now take place after end discard's effects.
	   Added the end discard explanation for Miller.
	   Added universal constants for end discard explanations.
	 v1.1.2:
	   Miller no longer shuffles itself into the deck.
	   Miller now returns to hand and discards itself at the end of the turn.
	   Shadow Flame's damage cap was increased from 500 to 600.
	   Shadow Flame's damage scaling was increased from 25 to 30.
	   Fixed Experimenter's description to correctly show the hand recycle and end discard.
	   Standard search effects now automatically draw from a deck with 1 card.
	   Damage reduced beyond zero for splash is now displayed as zero damage.
	 v1.1.1.1:
	   Changes to some of the decklists.
	   Clear Deck no longer generates a test deck.
	 v1.1.1:
	   Forsaken's mill count was reduced from 3 to 1.
	   Cheerleader's power boost was decreased from 150 to 100.
	   Ninja's health was decreased from 1250 to 1200.
	   Shuriken Storm's damage was decreased from 200 to 175.
	   Katana Slash's damage was decreased from 450 to 300.
	   Katana Slash now impairs if the first flip gives heads.
	   Katana Slash now cripples if the second flip gives heads.
	   Crush's attack cost was decreased from 3000 to 2000.
	   Experimenter now returns to hand after being played.
	   Experimenter now discards itself at the end of the turn.
	   Doctor now discards all energy from the hand and heals 200
	     damage from each of the player's fighters for each card
		 discarded (effects are still cleared from the active fighter).
	   Specific end discard explanations are now used (with the new effect_search()).
	   Explanations can now store integers in the condition.
	   Clear Deck no longer generates a test deck.
	   last_drawn is now set to null at the end of each action.
	   last_draws is now set to zero at the end of each action.
	   last_chosen is now set to -1 at the end of each action.
	 v1.1:
	   Added the random deck to the deck generator decklists.
	   Added the "Boost" player effect explanation for active fighters with
	     attacks that deal variable amounts of damage depending on the gamestate.
	   Only Supporter cards can be chosen to be life cards.
	   Floating point effects are now rounded to the nearest integer (rather than down).
	 v1.0.4.1:
	   Forsaken's banish mill now correctly indicates the owners of cards.
	   Changes to the "Combo" decklist.
	 v1.0.4:
	   Pyromaniac now converts all of the player's cards (no matter where they are).
	   Primed Payload's damage sclaing was increased from 0.2 to 0.3.
	   All of the basic elementals' attacks have been changed to deal 200
	     damage to the opponent's active fighter and draw both players a card.
	   Omega Fusion no longer crashes the game when Omega Elemental was not in hand.
	   Changes to some of the decklists.
	 v1.0.3.1:
	   Added demiduel v1.0.3 to the versions folder.
	 v1.0.3:
	   Lost Soul's health was reduced from 1200 to 1000.
	   Banisher' health was increased from 1200 to 1300.
	   Cultist's health was reduced from 1200 to 1100.
	   Scuba Diver's immunity clear power boost was increased from 300 to 500.
	   Fire Elemental's splash damage was decreased from 100 to 50.
	   Water Elemental's splash heal was decreased from 100 to 50.
	   Improved descriptions for the decklists.
	   Changes to some of the decklists.
	 v1.0.2:
	   Ninja's health was decreased from 1300 to 1250.
	   Ninja's retreat cost was increased from 0 to 500.
	   Suriken Storm's flip count was increased from 3 to 6.
	   Shuriken Storm's damage was decreased from 350 to 200.
	   Shuriken Storm's cost was increased from 1000 to 1500.
	   Samurai's retreat cost wsa decreased from 2000 to 1500.
	   Katana Slash's damage was decreased from 500 to 450.
	   Katana Slash' cost was decreased from 2000 to 1500.
	   Doctor's healing was increased from 600 to 750.
	   Doctor now removes the effects from the player's active fighter.
	   Cheerleader's power boost was increased from 100 to 150.
	   Maniac now boosts power by 10000, if the player's deck, hand, and bench are empty.
	   Documented the undocumented changes to Ninja and Samurai in v1.0.1.
	 v1.0.1:
	   Gambler's draw counts were changed from 3 and 5 to 2 and 6.
	   Experimenter now searches the deck for 1 card and banishes mills 1 card afterwards.
	   Ninja's health was increased from 1250 to 1300.
	   Shuriken's Storm's damage was increased from 300 to 350.
	   Katana Slash's damage was increased from 450 to 500.
	   Minor changes to card text.
	 v1:
	   A limit on the number of cards that can be played each turn has been added.
	   The card limit starts off at 1 card per turn and increments with each turn.
	   This rule change has been documented in README.txt
	   The cards, Boxer, Fire Elemental, Air Elemental, Water Elemental,
	    Earth Elemental, and Omega Elemental, were added.
	   Researcher and Gambler were returned to the game.
	   Researcher's draw count was increased from 2 to 3.
	   Gambler's draw counts were increased from 2 and 4 to 3 and 5.
	   Doctor now discards all of the cards in hand to splash heal 600.
	   Nurse's healing was decreased from 750 to 600.
	   Innkeeper's healing was reduced from 300 to 250.
	   Innkeeper's description was changed to clarify its behaviour.
	   Miracle Worker's healing was reduced from 1000 to 800.
	   Miracle Worker's description was changed to clarify its behaviour.
	   Miller's draw count was decreased from 1 to 0.
	   Incenerate's mill count was increased from 3 to 5.
	   Heat Wave's opposing splash was decreased from 300 to 200.
	   Heat Wave's friendly bench splash was increased from 100 to 200.
	   Wander's damage boost was decreased from 500 to 300.
	   Screech's damage scaling was decreased from 50 to 40.
	   Screech's maximum damage was decreased from 1000 to 800.
	   Void Pact's heal scaling was decreased from 20 to 15.
	   Void Pact's maximum heal was decreased from 400 to 300.
	   Dark Bargain's uses were decreased from infinity to 1.
	   Vacuum Wave's uses were decreased from infinity to 1.
	   Abandon effects no longer crash the game when there are no valid options.
	   Investor's now draws at the start of the next
	     turn, instead of at the end of the turn played.
	   Recoil is now boosted by power.
	   The turn's attack and retreat use are now indicated by effect explanations.
	   Retreating with a single fighter on the bench no longer prompts for a choice.
	   Energy play effects are now resolved before attachment.
	   Many announcement now indicate the player affected.
	   Drawing all of the life cards at the start of turn is no longer announced twice.
	   The Midrange deck has been renamed to Tempo and uses Boxer instead of Warlock.
	   Changes to the cards used in most of the decklists.
	   Sniper no longer crashes when used against an opponent with a single fighter.
	   Miscellaneous changes to card text.
	 v0.9:
	   The cards, Peacemaker and Bond Energy, were added.
	   Radiant Pulse's damage was increased from 375 to 400.
	   Radiant Pulse's healing was decreased from 125 to 100.
	   Dark Bargain now banishes old ranks in the trash to search the trash.
	   Shadow Pulse's recoil was reduced from 250 to 150.
	   Vacuum Wave now banishes old ranks in the trash to hook and cripple.
	   "Twister" was renamed to "Slipstream".
	   Slipstream's damage was decreased from 800 to 700.
	   Slipstream now switches out the user rather than switching in an enemy.
	   "Undermine" was renamed to "Tunnel".
	   Tunnel's damage was increased from 400 to 500.
	   "Energy Mine" was renamed to "Undermine".
	   "Diver" was renamed to "Scuba Diver".
	   Shadow Flame's damage per turn was capped at 500 damage.
	   "Lost Wail" was renamed to "Screech".
	   Screech's damage was capped at 1000 damage.
	   Void Pact's healing was capped at 400 damage.
	   Various effects now automatically choose the only option available.
	   Rank Ups now use a common method: Player::rank_up(const Fighter&, int).
	   Power effects are now removed at the end of the
	     player's turn, rather than at the end of every turn.
	   Player effects no longer consider Fighter explanations.
	   Player Power and Fighter Power now have separate explanations.
	 v0.8.0.1:
	   Undermine's description was fixed to show that the number of
	     cards drawn is equal to the number of cards shuffled in.
	   The "End Discard" effect is no longer persistent.
	 v0.8:
	   The cards Lost Soul, Banisher, Banshee, Cultist, Apprentice, Sensei's
	     Chosen, Ninja, Samurai, Innkeeper, and Matchmaker, were added.
	   Windfall's power cut was increased from 200 to 400.
	   Primed Payload's damage cap was decreased from 1000 to 800.
	   Judge was renamed to Locksmith.
	   Nitro Boost's damage was increased from 350 to 400.
	   Vacuumancer's health was decreased from 1100 to 1000.
	   Warlock's health was decreased from 1150 to 1100.
	   Pyromancer's health was decreased from 1250 to 1200.
	   Cleric's health was increased from 1200 to 1300.
	   Healing Aura's healing was increased from 75 to 100.
	   Fixed a visual bug with Arsonist showing that it banish
	     milled 4 cards when it only banish milled 3 cards.
	   Supporter cards are now ordered by functionality.
	   Effects have been reordered.
	   demiduelversion and demiduelversionmini were added for easy multi-version use.
	   versions/README.txt was updated to reflect this.
	   README.txt was updated to clarify that switching clears effects.
	   Added utility/README.txt.
	   Added data/README.txt.
	   Fighter::energy_value() was modified to be more flexible with effects.
	 v0.7.3.1:
	   Fixed a bug that displayed Divebomb dealing
	     350 damage, but only dealing 250 damage.
	   Fixed a bug that displayed Gravity Flip dealing
	     450 damage, but only dealing 300 damage.
	 v0.7.3:
	   Pyrotechnician's health was reduced from 1300 to 1200.
	   Pyrotechnician's retreat cost was decreased from 3000 to 2000.
	   Primed Payload's damage scaling was increased from 0.1 to 0.2.
	   Primed Payload's damage was capped at 1000.
	   Dirt Biker's health was increased from 1250 to 1300.
	   Quick Fix's healing was increased from 100 to 200.
	   Quick Fix's uses were decreased from 2 to 1.
	   Shred's damage scaling was reduced from 8 to 5.
	   Monster Trucker's health was increased from 1500 to 1600.
	   Scrap Metal's healing was increased from 150 to 400.
	   Scrap Metal's uses were reduced from 3 to 1.
	   Crush's damage scaling was reduced from 15 to 10.
	   Sailor's health was reduced from 1250 to 1200.
	   Divebomb's damage was increased from 250 to 350.
	   Astronaut's health was increased from 1300 to 1400.
	   Gravity Flip's damage was increased from 300 to 450.
	   Magic Missiles' burst count was reduced from 3 to 2.
	   Magic Missiles' damage was increased from 100 to 150.
	   Pyromancer's health was decreased from 1300 to 1250.
	   Warlock's health was decreased from 1300 to 1150.
	   Cleric's health was increased from 1100 to 1200.
	   Vacuumancer's health was decreased from 1200 to 1100.
	   Diver's health was increased from 1200 to 1300.
	   Welder's retreat cost was decreased from 1500 to 1000.
	   Blowtorch's cost was increased from 1000 to 1500.
	   Wind Runner's health was decreased from 1000 to 950.
	   Cloud Surfer's health was decreased from 1300 to 1100.
	   Solo was removed from the decklists.
	   Aggro was modified to use Pyrotechnician instead of Diver.
	 v0.7.2:
	   Super Nitro's damage was increased from 425 to 450.
	   Twister's damage was increased from 700 to 800.
	   Undermine's draw count now depends on hand size.
	   Healing Aura's healing was increased from 25 to 75.
	   Healing Aura only heals at the end of the player's turn.
	   Dark Bargain's search effect is now dependent on the rank down.
	   Dark Bargain now chooses a random previous rank.
	   The new decklists for the deck generator, Aggro,
	     Control, Mill, Combo, and Solo, have been added.
	   Fighter's energy values no longer display the values from the first page.
	   Updated README.txt to explain how to play on a single PC.
	 v0.7.1:
	   Windfall now resets the attack and retreat usage for the
	     turn, but reduces all friendly fighter's damage by 200.
	   Diver's health was reduced from 1600 to 1200.
	   Undercurrent's base damage was increased from 400 to 500.
	   Undercurrent now deals 300 extra damage if the user is invincible
	     (upon use), but still clears the invinciblity effect.
	   Excavator's health was reduced from 1600 to 1400.
	   Incinerate's discard count was increased from 2 to 3.
	   Quick Fix's healing was increased from 75 to 100.
	   Scrap Metal's healing was increased from 100 to 150.
	   Escape Artist now chooses a random old rank to return to hand.
	   Negative power messages now use "{x} less" rather than "{-x} more".
	   effect_search() now filters the effects for all of the matches
	     and thus has a return type of std::vector<std::vector<std::string>>
		 instead of const std::vector<std::string>*.
	 v0.7.0.2:
	   The player is no longer prompted to draw a life card at the start
	     of their turn when they only have one and have an empty deck.
	 v0.7.0.1:
	   Fixed a bug where Smuggler would mill the opponent rather than the player.
	   Recycle to deck effects no longer crash the game.
	 v0.7:
	   The cards, Miner, Excavator, Swimmer, Diver, Welder,
	     Pyrotechnician, Wind Runner, Cloud Surfer, Personal Trainer,
		 Lock Picker, and Scapegoat, were added to the game.
	   Banker now shuffles any number of cards in the hand into the deck.
	   Banker was moved from the draw category to the "Recycle" category.
	   Lecturer's draw count was increased from 5 to 6.
	   Researcher was removed from the game.
	   Gambler was removed from the game.
	   Miracle Worker's algorithm's efficiency was improved.
	   Healing now shows the exact amount healed.
	   Damage now shows the exact amount dealt.
	   Agility is now correctly mirrored for both players.
	   The decklists from v0.6 were removed.
	   demiduelbuild was added to the zip package for easier development.
	   Minor miscellaneous improvements to source documentation.
	   Fixed some typos in card text.
	 v0.6.2:
	   Smuggler was returned into the game.
	   Smuggler now discards the top 2 cards of the
	     deck and searches the trash for a card.
	   Universal Energy was returned into the game.
	   Universal Energy's energy value was increased from 750 to 1000.
	   Fire Energy, Air Energy, Water Energy, and Earth Energy
	     now draw a card upon attachment to a fighter.
	   Void Energy was removed from the game.
	   Pirate's health was reduced from 1500 to 1300.
	   Plank Walk's bonus damage was decreased from 100 to 50.
	   Cleric's health was decreased from 1300 to 1100.
	   Healing Aura's healing was reduced from 50 to 25.
	   Vacuumancer's health was decreased from 1300 to 1200.
	   Twister's damage was increased from 600 to 700.
	   Professor's draw was increased from 5 to 8.
	   Divebomb's attack cost was increased from 500 to 1000.
	   Pilot's health was decreased from 1250 to 1200.
	   Gravity Flip's attack cost was increased from 0 to 1000.
	   Astronaut's health was decreased from 1500 to 1300.
	   Alchemist and Electrician were moved to the "Recycle" category.
	 v0.6.1:
	   Smuggler was removed from the game.
	   Matchmaker was removed from the game.
	   Universal Energy was removed from the game.
	   Bounty Hunter now shuffles itself into the deck instead of being discarded.
	   Bounty Hunter now draws a card after shuffling itself into the deck.
	   Miracle Worker now distributes healing properly when some
	     of the player's fighters are already fully healed.
	   Omega Energy's energy value was reduced from 10000 to 2000.
	   Omega Energy now only discards 1 card instead of 2.
	   Twin Energy's energy value was increased from 2000 to 3000.
	   Twin Energy was renamed to Void Energy.
	   Alpha Energy's value was increased from 250 to 500.
	   Miller has been reworked.
	   Miller now shuffles itself into the deck, discards the
	     top card of each player's deck, and draws a card.
	   Arsonist's banish count was reduced from 4 to 3.
	   Radiant Pulse's damage was decreased from 400 to 375.
	   Radiant Pulse's healing was increased from 100 to 125.
	   Twister's damage was increased from 500 to 600.
	   Incinerate's uses were decreased from 3 to 1.
	   Incinerate's discard count was increased from 1 to 2.
	   Deck lists using removed cards have been updated.
	   Minor card wording changes.
	   The zip package now contains various versions of the game.
	 v0.6:
	   The cards, Mage, Vacuumancer, Pyromancer, Warlock, and Cleric, were added.
	   Smuggler's shuffle count was decreased from 5 to 1.
	   Quick Fix's uses were decreased from infinity to 2.
	   Quick Fix's healing was increased from 50 to 75.
	   Scrap Metal's uses were decreased from infinity to 3.
	   Removed all of the decklists from v0.5.
	   Added new "Aggro Deck" and "Control Deck" decklists.
	   Snipe effects are now correctly affected by power boosts.
	   Snipe effects now target the correct fighter when there is only one target.
	   demiduelmini.cpp and demiduelmini.exe were added to the zip package.
	   demiduelmini opens demiduel with a screen of 700 x 400 pixels in size.
	 v0.5.2:
	   Players now draw a life card, at the start of their turn, when their deck is empty.
	   Increased Nurse's healing from 500 to 750.
	   Decreased Miracle Worker's healing from 2000 to 1000.
	   Increased Super Nitro's damage from 400 to 425.
	   Increased Charged Thruster's damage boost from 200 to 250.
	   Miracle Worker's healing is no longer symmetricl and only affects the player.
	   A new fighter is not prompted for when the player only has a single
	     fighter on the bench and the active fighter was defeated.
	   A fighter is not prompted for when sniping, if the opponent's bench is empty.
	   README.txt has been updated with the new rules.
	 v0.5.1.3:
	   Shuffling the opponent's hand into their deck no longer
	     displays the details for the player instead of the opponent.
	   Self draining effects no longer show the opponent's fighters.
	 v0.5.1.2:
	   Scrap Metal now correctly mills the deck.
	   The winner no longer waits for their opponent to draw a life
	     card if they defeat all of their opponent's fighters.
	 v0.5.1.1:
	   Fixed the unhandled message logging to no longer print every loop.
	 v0.5.1:
	   The deck generator decklists, Aggro, Control, and Blend, were added.
	   Omega Energy now only discards 2 cards rather than the entire hand.
	   The window dimensions can now be chosen using command line arguments.
	   Unhandled messages, between the players, are
	     now logged with the standard error stream.
	 v0.5:
	   The cards, Cheerleader, Maniac, Nurse, Doctor, Miracler Worker,
	     Escape Artist, Plumber, Miller, Scammer, Arsonsist, Smuggler,
	 	 Glutton, Assassin, Sniper, Alpha Energy, and Omega Energy, were added.
	   Changed the power announcement to make clear that only attacks are buffed.
	   Changed the shuffle announcement for the player to flow better.
	   Changed the discard and shuffle all announcements to display the number of cards
	     discarded. The announcement shows which card was discarded for a singleton dump.
	 v0.4:
	   The cards, Computer Scientist, Experimenter, Alchemist, Chef, Trader,
	     Electrician, Switch, Bounty Hunter, and Matchmaker, were added.
       Fixed the description for Astronaut's attack to correctly show the damage.
	   Increased the retreat cost increase for Divebomb from 1500 to 2500.
	   Increased the retreat cost increase for Gravity Flip from 3000 to 4000.
	   Reduced the damage boost for Charged Thruster from 400 to 200.
	   Increased Super Nitro's damage from 350 to 400.
	   Reduced the scaling of Shred from 10 damage per card
	     in the trash to 8 damage per card in the trash.
	   Reduced the scaling of Crush from 20 damage per card
	     in the trash to 15 damage per card in the trash.
	 v0.3
	   The cards, Sailor, Pirate, Dirt Biker, Monster
	     Trucker, Pilot, and Astronaut, were added.
	   Racer's attack cost was decreased from 2000 to 1500.
	   Fighters now display what they rank up from in brackets.
	   Fighters can no longer attempt to retreat when the bench is empty.
	   Fighters now display their number of ability uses.
	   The "defending fighter" in the attack description has
	     been renamed to the "opponent's active fighter".
	   Racer's attack's damage was reduced from 400 to 350.
	   Racer's ability's damage boost was increased from 100 to 150.
	   Hot Rodder's attack's damage was reduced from 500 to 350.
	   Hot Rodder's ability's damage boost was increased from 250 to 400.
	   Drawing now display the total number of cards drawn for the player drawing.
	 v0.2:
	   The cards, Lecturer, Investor, Banker, and Gambler, were added.
	   Racer's attack's damage was decreased from 500 to 400.
	   Racer's ability now applies a power effect of 100.
	   Preparation no longer affects the first player for the entire game.
	   Increased the number of cards in a deck from 30 to 40.
	   Increased the number of life cards placed from 3 to 4.
	   Increased the number of cards in the starting hand from 5 to 8.
	 v0.1:
	   The essential game components were implemented.
	   The cards, Driver, Racer, Hot Rodder, Professor, Researcher,
	     Fire Energy, Air Energy, Water Energy, Earth Energy,
		 Twin Energy, and Universal Energy, were added.
 */