#include <iostream>
#include <type_traits>
#include "sdlandnet.hpp"

// Universal Constants
//{
// System Constants
//{
// The current version of the program.
constexpr int VERSION[] = {1, 12, 0, 1};

// The title of the game in string form.
constexpr const char* TITLE_STRING = "Demi Duel";

// Default window dimensions.
constexpr int WINDOW_WIDTH = 0;
constexpr int WINDOW_HEIGHT = 0;

// The game's keybindings.
//{
constexpr int QUIT_KEY = Events::ESCAPE;
constexpr int BACK_KEY = QUIT_KEY;
constexpr int SUBMIT_KEY = Events::ENTER;
constexpr int NEXT_KEY = SUBMIT_KEY;
constexpr int DELETE_KEY = Events::BACKSPACE;
//}

// The number of letters, numbers, and punctuation marks used as sprites.
//{
constexpr int LETTERS = System::LETTERS;
constexpr int NUMBERS = System::NUMBERS;
constexpr int PUNCTUATION = 12;
//}

// The number of renderer sources.
constexpr int RENDERER_COUNT = 2 * LETTERS + NUMBERS + PUNCTUATION;

// The directory and extension of renderer sources.
constexpr const char* SOURCE_DIRECTORY = "data/";
constexpr const char* SOURCE_EXTENSION = ".bmp";

// The source of the punctuation.
//{
constexpr const char* FULL_STOP_SOURCE = "data/fullstop.bmp";
constexpr const char* COMMA_SOURCE = "data/comma.bmp";
constexpr const char* COLON_SOURCE = "data/colon.bmp";
constexpr const char* SLASH_SOURCE = "data/slash.bmp";
constexpr const char* EXCLAMATION_SOURCE = "data/exclamation.bmp";
constexpr const char* QUESTION_SOURCE = "data/question.bmp";
constexpr const char* SEMICOLON_SOURCE = "data/semicolon.bmp";
constexpr const char* LEFT_BRACKET_SOURCE = "data/leftbracket.bmp";
constexpr const char* RIGHT_BRACKET_SOURCE = "data/rightbracket.bmp";
constexpr const char* APOSTROPHE_SOURCE = "data/apostrophe.bmp";
constexpr const char* PLUS_SOURCE = "data/plus.bmp";
constexpr const char* MINUS_SOURCE = "data/minus.bmp";
//}

// The string that indicates that the player quit.
constexpr const char* TERMINATOR_STRING = "/quit";
 
// The number of cards to be displayed per page.
constexpr int PAGE_COUNT = 5;

// The number of players in a game.
constexpr int PLAYERS = 2;

// The initial state of messenger strings.
constexpr const char* EMPTY_MESSAGE = "";

// The string of the error thrown when attempting to
//   remove cards from an empty card store.
constexpr const char* EMPTY_CARD_STORE = "Removal from an empty card store.";

// Constants to index the players.
constexpr int PLAYER = 0;
constexpr int OPPONENT = 1;

// A constant that defines the user not making a choice.
constexpr int NO_CHOICE = -1;

// The message to indicate a move.
constexpr const char* PLAY_MESSAGE = "play";
constexpr const char* ABILITY_MESSAGE = "ability";
constexpr const char* RETREAT_MESSAGE = "retreat";
constexpr const char* ATTACK_MESSAGE = "attack";

// Constants to define a game condition.
constexpr int NO_END = -1;
constexpr int TIE = 2;

// Constants to define the outcomes of a coin flip.
constexpr bool HEADS = true;
constexpr bool TAILS = false;
//}

// Game Constants
//{
// Count Constants
//{
constexpr int DECK_SIZE = 30;
constexpr int CARD_TYPES = 3;
constexpr int BENCH_INDEX = 1;
constexpr int HAND_SIZE = 7;
constexpr int LIFE_SIZE = 3;
constexpr int TURN_DRAW = 1;
constexpr int MAX_FIGHTER_COPIES = 1;
constexpr int MAX_SUPPORTER_COPIES = MAX_FIGHTER_COPIES;
constexpr int MAX_ENERGY_COPIES = 2;
constexpr int BASE_CARD_LIMIT = 1;
constexpr int CARD_LIMIT_INCREMENT = 1;

// Ensures that the game can begin after the bonus draws.
constexpr int MAX_BONUS = DECK_SIZE - HAND_SIZE - LIFE_SIZE - 1;
//}

// Card Attribute Constants
//{
// Element
//{
constexpr const char* FIRE_ELEMENT = "Fire";
constexpr const char* AIR_ELEMENT = "Air";
constexpr const char* WATER_ELEMENT = "Water";
constexpr const char* EARTH_ELEMENT = "Earth";
constexpr const char* NO_ELEMENT = "Null";
//}

// Card Types
//{
constexpr const char* FIGHTER_TYPE = "Fighter";
constexpr const char* SUPPORTER_TYPE = "Supporter";
constexpr const char* ENERGY_TYPE = "Energy";
constexpr const char* ABILITY_TYPE = "Ability";
constexpr const char* ATTACK_TYPE = "Attack";
//}

// Miscellaneous
//{
constexpr const char* NO_EFFECTS = "";
constexpr const char* FIGHTER_DESCRIPTION = "";
constexpr const char* FIGHTER_EFFECTS = NO_EFFECTS;
constexpr const char* NO_OLD_RANK = "";
constexpr int PASSIVE_USES = 0;
constexpr int INFINITE_USES = 0;
constexpr const char* PLAYER_EFFECTS = NO_EFFECTS;
//}
//}

// Effect Constants
//{
// The characters used in effect parsing.
//{
constexpr char EFFECT_TERMINATOR = '\n';
constexpr char EFFECT_SEPARATOR = ' ';
//}

// The constant strings for the effects.
//{
constexpr const char* RANK_UP_EFFECT = "rank_up";
constexpr const char* CONVERSION_EFFECT = "conversion";
constexpr const char* POWER_EFFECT = "power";
constexpr const char* SWITCH_IN_EFFECT = "switch_in";
constexpr const char* FLIP_EFFECT = "flip";
constexpr const char* HEADS_EFFECT = "heads";
constexpr const char* INVINCIBILITY_EFFECT = "invincibility";
constexpr const char* TAILS_EFFECT = "tails";
constexpr const char* BACKPEDAL_EFFECT = "backpedal";
constexpr const char* DISCARD_EFFECT = "discard";
constexpr const char* UNIVERSAL_EFFECT = "all";
constexpr const char* DRAW_EFFECT = "draw";
constexpr const char* PREPARATION_EFFECT = "prep";
constexpr const char* SHUFFLE_EFFECT = "shuffle";
constexpr const char* END_DRAW_EFFECT = "end_draw";
constexpr const char* SNIPE_EFFECT = "snipe";
constexpr const char* SEARCH_EFFECT = "search";
constexpr const char* MILL_EFFECT = "mill";
constexpr const char* HEAL_EFFECT = "heal";
constexpr const char* TRASH_EFFECT = "trash";
constexpr const char* AGILITY_EFFECT = "agility";
constexpr const char* AGILITY_AURA_EFFECT = "agility_aura";
constexpr const char* FREEDOM_EFFECT = "freedom";
constexpr const char* BANISH_EFFECT = "banish";
constexpr const char* SWITCH_EFFECT = "switch";
constexpr const char* RECYCLE_EFFECT = "recycle";
constexpr const char* HOOK_EFFECT = "hook";
constexpr const char* SAME_TYPE_EFFECT = "same_type";
constexpr const char* SELF_EFFECT = "self";
constexpr const char* DRAIN_EFFECT = "drain";
constexpr const char* BENCH_EFFECT = "bench";
constexpr const char* BOUNCE_EFFECT = "bounce";
constexpr const char* DRAW_COUNT_EFFECT = "draw_count";
constexpr const char* OPPONENT_EFFECT = "opponent";
constexpr const char* CLEAR_EFFECT = "clear";
constexpr const char* CHOSEN_EFFECT = "chosen";
constexpr const char* DISTRIBUTE_EFFECT = "distribute";
constexpr const char* DAMAGE_EFFECT = "damage";
constexpr const char* ADAPTABILITY_EFFECT = "adaptability";
constexpr const char* SPLASH_EFFECT = "splash";
constexpr const char* RANK_DOWN_EFFECT = "rank_down";
constexpr const char* RECOIL_EFFECT = "recoil";
constexpr const char* HEAL_AURA_EFFECT = "heal_aura";
constexpr const char* ACTIVE_EFFECT = "active";
constexpr const char* GUST_EFFECT = "gust";
constexpr const char* TRAIN_EFFECT = "train";
constexpr const char* LIFE_EFFECT = "life";
constexpr const char* HAND_EFFECT = "hand";
constexpr const char* END_DISCARD_EFFECT = "end_discard";
constexpr const char* ENERGY_BOUNCE_EFFECT = "energy_bounce";
constexpr const char* ACCELERATION_EFFECT = "acceleration";
constexpr const char* PLAY_EFFECT = "play";
constexpr const char* HAND_CONVERSION_EFFECT = "hand_conversion";
constexpr const char* RESET_EFFECT = "reset";
constexpr const char* FORSAKEN_EFFECT = "forsaken";
constexpr const char* FIGHTERLESS_EFFECT = "fighterless";
constexpr const char* BANISHMENT_EFFECT = "banishment";
constexpr const char* CURSE_EFFECT = "curse";
constexpr const char* VOID_EFFECT = "void";
constexpr const char* FUEL_EFFECT = "fuel";
constexpr const char* MIMIC_EFFECT = "mimic";
constexpr const char* COMBO_EFFECT = "combo";
constexpr const char* AFFINITY_EFFECT = "affinity";
constexpr const char* HEADS_COUNT_EFFECT = "heads_count";
constexpr const char* CRIPPLE_EFFECT = "cripple";
constexpr const char* IMPAIR_EFFECT = "impair";
constexpr const char* BOND_EFFECT = "bond";
constexpr const char* ATTACKLESS_EFFECT = "attackless";
constexpr const char* ABANDON_EFFECT = "abandon";
constexpr const char* AGGRESSIVE_EFFECT = "aggressive";
constexpr const char* FUSION_EFFECT = "fusion";
constexpr const char* DEFEAT_EFFECT = "defeat";
constexpr const char* UNIFY_EFFECT = "unify";
constexpr const char* EMPTY_DECK_EFFECT = "empty_deck";
constexpr const char* EMPTY_HAND_EFFECT = "empty_hand";
constexpr const char* EMPTY_BENCH_EFFECT = "empty_bench";
constexpr const char* DEPLAY_EFFECT = "deplay";
constexpr const char* ROOT_EFFECT = "root";
constexpr const char* EXTRA_PLAY_EFFECT = "extra_play";
constexpr const char* OVERLOAD_EFFECT = "overload";
constexpr const char* DOUBLE_ROOT_EFFECT = "double_root";
constexpr const char* UNRANKED_EFFECT = "unranked";
constexpr const char* ASSASSINATE_EFFECT = "assassinate";
constexpr const char* ASCENSION_EFFECT = "ascension";
constexpr const char* POWER_AURA_EFFECT = "power_aura";
constexpr const char* DEPOWER_EFFECT = "depower";
//}

// The constants for effect explanations.
//{
// The constants for the rank conversion effect explanation.
//{
#define RANK_CONVERSION_CONDITION (                   \
    (filtered = effect_search(RANK_UP_EFFECT)).size() \
    && filtered[0][1] == CONVERSION_EFFECT            \
)
constexpr const char* RANK_CONVERSION_REPRESENTATION = "Rank Conversion";
constexpr const char* RANK_CONVERSION_VALUE = "";
constexpr const char* RANK_CONVERSION_EXPLANATION =
    "When this fighter ranks up, the attached energy "
    "is converted to the element of the new rank."
;
//}

// The constants for the fighter power effect explanation.
//{
#define FIGHTER_POWER_CONDITION (value = effect_count(POWER_EFFECT))
constexpr const char* FIGHTER_POWER_REPRESENTATION = "Power";
#define FIGHTER_POWER_VALUE std::to_string(value)
#define FIGHTER_POWER_EXPLANATION (                     \
    "This fighter's attacks deal "                      \
    + std::to_string(abs(std::stoi(effect_value)))      \
    + (std::stoi(effect_value) < 0 ? " less" : " more") \
    + " damage this turn."                              \
)
//}

// The constants for the power effect explanation.
//{
#define PLAYER_POWER_CONDITION (value = effect_count(POWER_EFFECT))
constexpr const char* PLAYER_POWER_REPRESENTATION = "Power";
#define PLAYER_POWER_VALUE std::to_string(value)
#define PLAYER_POWER_EXPLANATION (                      \
    "This player's fighters' attacks deal "             \
    + std::to_string(abs(std::stoi(effect_value)))      \
    + (std::stoi(effect_value) < 0 ? " less" : " more") \
    + " damage this turn."                              \
)
//}

// The constants for the power effect explanation.
//{
#define POWER_AURA_CONDITION (value = effect_count(POWER_AURA_EFFECT))
constexpr const char* POWER_AURA_REPRESENTATION = "Power Aura";
#define POWER_AURA_VALUE std::to_string(value)
#define POWER_AURA_EXPLANATION (                        \
    "This player's fighters' attacks deal "             \
    + std::to_string(abs(std::stoi(effect_value)))      \
    + (std::stoi(effect_value) < 0 ? " less" : " more") \
    + " damage for the rest of the duel."               \
)
//}

// The constants for the preparation explanation.
//{
#define PREPARATION_CONDITION effect_search(PREPARATION_EFFECT).size()
constexpr const char* PREPARATION_REPRESENTATION = "Preparation";
constexpr const char* PREPARATION_VALUE = "";
constexpr const char* PREPARATION_EXPLANATION =
    "If you go first, you can't attack on your first turn."
;
//}

// The constants for the end draw explanation.
//{
#define END_DRAW_CONDITION (value = effect_count(END_DRAW_EFFECT))
constexpr const char* END_DRAW_REPRESENTATION = "Invested";
#define END_DRAW_VALUE std::to_string(value)
#define END_DRAW_EXPLANATION (                  \
    "This player draws "                        \
    + effect_value                              \
    + " cards at the start of their next turn." \
)
//}

// The constants for the agility explanation.
//{
#define AGILITY_CONDITION (value = effect_count(AGILITY_EFFECT))
constexpr const char* AGILITY_REPRESENTATION = "Agility";
#define AGILITY_VALUE std::to_string(value)
#define AGILITY_EXPLANATION (                                      \
    "This fighter's retreat cost is "                                      \
    + std::string(std::stoi(effect_value) < 0 ? "increased" : "decreased") \
    + " by "                                                               \
    + std::to_string(abs(std::stoi(effect_value)))                         \
    + "."                                                                  \
)
//}

// The constants for the agility aura explanation.
//{
#define AGILITY_AURA_CONDITION (value = fighter_effect_count(AGILITY_AURA_EFFECT))
constexpr const char* AGILITY_AURA_REPRESENTATION = "Agility Aura";
#define AGILITY_AURA_VALUE std::to_string(value)
#define AGILITY_AURA_EXPLANATION (                      \
    "This player's fighters retreat for "               \
    + std::to_string(abs(std::stoi(effect_value)))      \
    + (std::stoi(effect_value) < 0 ? " more" : " less") \
    + " energy!"                                        \
)
//}

// The constants for the freedom explanation.
//{
#define FREEDOM_CONDITION fighter_effect_search(FREEDOM_EFFECT)
constexpr const char* FREEDOM_REPRESENTATION = "Freedom";
constexpr const char* FREEDOM_VALUE = "";
constexpr const char* FREEDOM_EXPLANATION =
    "This player's fighters can retreat as often as the player wishes."
;
//}

// The constants for the adaptability effect explanation.
//{
#define ADAPTABLE_CONDITION effect_search(ADAPTABILITY_EFFECT).size()
constexpr const char* ADAPTABLE_REPRESENTATION = "Adaptable";
constexpr const char* ADAPTABLE_VALUE = "";
constexpr const char* ADAPTABLE_EXPLANATION =
    "This fighter can use energy of any element."
;
//}

// The constants for the heal aura explanation.
//{
#define HEAL_AURA_CONDITION (value = fighter_effect_count(HEAL_AURA_EFFECT))
constexpr const char* HEAL_AURA_REPRESENTATION = "Healing Aura";
#define HEAL_AURA_VALUE std::to_string(value)
#define HEAL_AURA_EXPLANATION (           \
    "This player's fighters are healed "  \
    + effect_value                        \
    + " damage at the end of their turn." \
)
//}

// The constants for the invincibilty explanation.
//{
#define INVINCIBILITY_CONDITION effect_search(INVINCIBILITY_EFFECT).size()
constexpr const char* INVINCIBILITY_REPRESENTATION = "Invincibility";
constexpr const char* INVINCIBILITY_VALUE = "";
constexpr const char* INVINCIBILITY_EXPLANATION =
    "This fighter can't be damaged until its player's next turn."
;
//}

// The constants for the cripple explanation.
//{
#define CRIPPLE_CONDITION effect_search(CRIPPLE_EFFECT).size()
constexpr const char* CRIPPLE_REPRESENTATION = "Crippled";
constexpr const char* CRIPPLE_VALUE = "";
constexpr const char* CRIPPLE_EXPLANATION =
    "This fighter can't be retreated until the end of its player's turn."
;
//}

// The constants for the affinity explanation.
//{
#define AFFINITY_CONDITION (filtered = effect_search(AFFINITY_EFFECT)).size()
constexpr const char* AFFINITY_REPRESENTATION = "Affinity";
#define AFFINITY_VALUE filtered[0][1]
#define AFFINITY_EXPLANATION (            \
    "This fighter can use energy of the " \
    + effect_value                        \
    + " element."                         \
)
//}

// The constants for the impair explanation.
//{
#define IMPAIR_CONDITION effect_search(IMPAIR_EFFECT).size()
constexpr const char* IMPAIR_REPRESENTATION = "Impaired";
constexpr const char* IMPAIR_VALUE = "";
constexpr const char* IMPAIR_EXPLANATION =
    "This fighter can't attack until the end of its player's turn."
;
//}

// The constants for the combo explanation.
//{
#define COMBO_CONDITION effect_search(COMBO_EFFECT).size()
constexpr const char* COMBO_REPRESENTATION = "Combo Attack";
constexpr const char* COMBO_VALUE = "";
constexpr const char* COMBO_EXPLANATION =
    "All friendly fighters with this effect and "
    "sufficient energy attack simultaneously."
;
//}

// The constants for the forsaken explanation.
//{
#define FORSAKEN_CONDITION (value = effect_count(FORSAKEN_EFFECT))
constexpr const char* FORSAKEN_REPRESENTATION = "Forsaken";
#define FORSAKEN_VALUE std::to_string(value)
#define FORSAKEN_EXPLANATION (                                                   \
    "When this fighter is defeated, it, its energy, its life card, and the top " \
    + effect_value                                                               \
    + " cards of both player's decks are banished."                             \
)
//}

// The constants for the banishment explanation.
//{
#define BANISHMENT_CONDITION fighter_effect_search(BANISHMENT_EFFECT)
constexpr const char* BANISHMENT_REPRESENTATION = "Void Servant";
constexpr const char* BANISHMENT_VALUE = "";
constexpr const char* BANISHMENT_EXPLANATION =
    "This player banishes the cards in their trash at the end of their turn."
;
//}

// The constants for the forbidden fuel explanation.
//{
#define FORBIDDEN_FUEL_CONDITION (                             \
    (filtered = fighters[0].effect_search(FUEL_EFFECT)).size() \
    && filtered[0][1] == VOID_EFFECT                           \
)
constexpr const char* FORBIDDEN_FUEL_REPRESENTATION = "Void Fuel";
#define FORBIDDEN_FUEL_VALUE std::to_string(std::stoi(filtered[0][2]) * the_void.size())
#define FORBIDDEN_FUEL_EXPLANATION (                           \
    "This player's active fighter can attack and retreat for " \
    + effect_value                                             \
    + " less energy!"                                          \
)
//}

// The constants for the curse explanation.
//{
#define CURSE_CONDITION (value = effect_count(CURSE_EFFECT))
constexpr const char* CURSE_REPRESENTATION = "Curse";
#define CURSE_VALUE std::to_string(value)
#define CURSE_EXPLANATION (              \
    "This fighter takes "                \
    + effect_value                       \
    + " damage at the end of each turn!" \
)
//}

// The constants for the rank bond explanation.
//{
#define RANK_BOND_CONDITION energy_effect_search(BOND_EFFECT)
constexpr const char* RANK_BOND_REPRESENTATION = "Rank Bond";
constexpr const char* RANK_BOND_VALUE = "";
constexpr const char* RANK_BOND_EXPLANATION =
    "When this fighter ranks up, it is drawn instead of being discarded."
;
//}

// The constants for the aggressive explanation.
//{
#define AGGRESSIVE_CONDITION effect_search(AGGRESSIVE_EFFECT).size()
constexpr const char* AGGRESSIVE_REPRESENTATION = "Aggressive";
constexpr const char* AGGRESSIVE_VALUE = "";
constexpr const char* AGGRESSIVE_EXPLANATION =
    "If this fighter is on the bench, it is switched into the active position."
;
//}

// The constants for the attacked explanation.
//{
#define ATTACKED_CONDITION attacked
constexpr const char* ATTACKED_REPRESENTATION = "Attacked";
constexpr const char* ATTACKED_VALUE = "";
constexpr const char* ATTACKED_EXPLANATION =
    "This player has attacked this turn and can't attack again."
;
//}

// The constants for the retreated explanation.
//{
#define RETREATED_CONDITION (retreated && !FREEDOM_CONDITION)
constexpr const char* RETREATED_REPRESENTATION = "Retreated";
constexpr const char* RETREATED_VALUE = "";
constexpr const char* RETREATED_EXPLANATION =
    "This player has retreated this turn and can't retreat again."
;
//}

// The constants for the card plays explanation.
//{
#define CARD_PLAYS_CONDITION (turn == opposing)
constexpr const char* CARD_PLAYS_REPRESENTATION = "Plays";
#define CARD_PLAYS_VALUE std::to_string(plays)
#define CARD_PLAYS_EXPLANATION (                \
    "This player can play "                     \
    + effect_value                              \
    + " more card"                              \
    + (std::stoi(effect_value) == 1 ? "" : "s") \
    + " this turn."                             \
)
//}

// The constants for the next card plays explanation.
//{
#define NEXT_CARD_PLAYS_CONDITION (turn != opposing)
constexpr const char* NEXT_CARD_PLAYS_REPRESENTATION = " Plays ";
#define NEXT_CARD_PLAYS_VALUE std::to_string(plays)
#define NEXT_CARD_PLAYS_EXPLANATION (           \
    "This player can play "                     \
    + effect_value                              \
    + " card"                                   \
    + (std::stoi(effect_value) == 1 ? "" : "s") \
    + " next turn."                             \
)
//}

// The constants for the friendly next card plays explanation.
//{
#define NEXT_TURN_CARD_PLAYS_CONDITION (turn == opposing)
constexpr const char* NEXT_TURN_CARD_PLAYS_REPRESENTATION = "Next Plays";
#define NEXT_TURN_CARD_PLAYS_VALUE std::to_string( \
    (                                              \
        value                                      \
        = card_limit                               \
        + CARD_LIMIT_INCREMENT                     \
        - effect_count(OVERLOAD_EFFECT)            \
    ) < 0                                          \
    ? 0                                            \
    : value                                        \
)
#define NEXT_TURN_CARD_PLAYS_EXPLANATION (      \
    "This player can play "                     \
    + effect_value                              \
    + " card"                                   \
    + (std::stoi(effect_value) == 1 ? "" : "s") \
    + " during their next turn."                \
)
//}

// The constants for the boost explanation.
//{
#define BOOST_CONDITION (value = get_boost())
constexpr const char* BOOST_REPRESENTATION = "Boost";
#define BOOST_VALUE std::to_string(value)
#define BOOST_EXPLANATION (                                                \
    "The power of this player's active fighter's attack was "              \
    + std::string(std::stoi(effect_value) < 0 ? "decreased" : "increased") \
    + " by "                                                               \
    + std::to_string(abs(std::stoi(effect_value)))                         \
    + " damage, due to the effects of the attack."                         \
)
//}

// The universal constants for the end discard explanations.
//{
constexpr const char* END_DISCARD_REPRESENTATION = "End Discard";
#define END_DISCARD_EXPLANATION (                 \
    "This player discards all cards named "       \
    + effect_value                                \
    + " from their hand at the end of this turn." \
)
//}

// The constants for the experimenter end discard explanation.
//{
#define EXPERIMENTER_END_DISCARD_CONDITION effect_search<2>({ \
    END_DISCARD_EFFECT,                                       \
    EXPERIMENTER_NAME                                         \
}).size()
#define EXPERIMENTER_END_DISCARD_VALUE EXPERIMENTER_NAME
//}

// The constants for the banker end discard explanation.
//{
#define BANKER_END_DISCARD_CONDITION effect_search<2>({ \
    END_DISCARD_EFFECT,                                 \
    BANKER_NAME                                         \
}).size()
#define BANKER_END_DISCARD_VALUE BANKER_NAME
//}

// The constants for the gatekeeper end discard explanation.
//{
#define GATEKEEPER_END_DISCARD_CONDITION effect_search<2>({ \
    END_DISCARD_EFFECT,                                     \
    GATEKEEPER_NAME                                         \
}).size()
#define GATEKEEPER_END_DISCARD_VALUE GATEKEEPER_NAME
//}

// The constants for the miller end discard explanation.
//{
#define MILLER_END_DISCARD_CONDITION effect_search<2>({ \
    END_DISCARD_EFFECT,                                 \
    MILLER_NAME                                         \
}).size()
#define MILLER_END_DISCARD_VALUE MILLER_NAME
//}

// The constants for the fatigue explanation.
//{
#define FATIGUE_CONDITION (deck.size() <= effect_count(END_DRAW_EFFECT))
constexpr const char* FATIGUE_REPRESENTATION = "Fatigued";
constexpr const char* FATIGUE_VALUE = "";
constexpr const char* FATIGUE_EXPLANATION =
    "This player will draw a life card at the start of their next turn."
;
//}

// The constants for the overload explanation.
//{
#define OVERLOAD_CONDITION (value = effect_count(OVERLOAD_EFFECT))
constexpr const char* OVERLOAD_REPRESENTATION = "Overloaded";
#define OVERLOAD_VALUE std::to_string(value)
#define OVERLOAD_EXPLANATION (                   \
    "This player can play "                      \
    + effect_value                               \
    + (effect_value == "1" ? " less" : " fewer") \
    + " card"                                    \
    + (effect_value == "1" ? "" : "s")           \
    + " during their next turn."                 \
)
//}

// The constants for the root explanation.
//{
#define ROOT_CONDITION effect_search(ROOT_EFFECT).size()
constexpr const char* ROOT_REPRESENTATION = "Rooted";
#define ROOT_VALUE (effect_search(DOUBLE_ROOT_EFFECT).size() ? " " : "")
#define ROOT_EXPLANATION (                                  \
    "This fighter can't be switched out until its player's" \
    + std::string(effect_value.length() ? " next " : " ")   \
    + "next turn."                                          \
)
//}
//}

// The total number of fighter-specific explainable effects.
constexpr int EXPLANATION_COUNT = 14;

// All of the fighter-specific explainable effect conditions.
//{
#define EFFECT_CONDITIONS(X) (                             \
    X == 0 ? static_cast<bool>(RANK_CONVERSION_CONDITION)  \
    : X == 1 ? static_cast<bool>(ADAPTABLE_CONDITION)      \
    : X == 2 ? static_cast<bool>(AFFINITY_CONDITION)       \
    : X == 3 ? static_cast<bool>(COMBO_CONDITION)          \
    : X == 4 ? static_cast<bool>(FORSAKEN_CONDITION)       \
    : X == 5 ? static_cast<bool>(AGGRESSIVE_CONDITION)     \
    : X == 6 ? static_cast<bool>(INVINCIBILITY_CONDITION)  \
    : X == 7 ? static_cast<bool>(ROOT_CONDITION)           \
    : X == 8 ? static_cast<bool>(CRIPPLE_CONDITION)        \
    : X == 9 ? static_cast<bool>(IMPAIR_CONDITION)         \
    : X == 10 ? static_cast<bool>(FIGHTER_POWER_CONDITION) \
    : X == 11 ? static_cast<bool>(AGILITY_CONDITION)       \
    : X == 12 ? static_cast<bool>(CURSE_CONDITION)         \
    : static_cast<bool>(RANK_BOND_CONDITION)               \
)
//}

// All of the fighter-specific explainable effect representations.
constexpr const char* EFFECT_REPRESENTATIONS[EXPLANATION_COUNT] = {
    RANK_CONVERSION_REPRESENTATION,
    ADAPTABLE_REPRESENTATION,
    AFFINITY_REPRESENTATION,
    COMBO_REPRESENTATION,
    FORSAKEN_REPRESENTATION,
    AGGRESSIVE_REPRESENTATION,
    INVINCIBILITY_REPRESENTATION,
    ROOT_REPRESENTATION,
    CRIPPLE_REPRESENTATION,
    IMPAIR_REPRESENTATION,
    FIGHTER_POWER_REPRESENTATION,
    AGILITY_REPRESENTATION,
    CURSE_REPRESENTATION,
    RANK_BOND_REPRESENTATION
};

// All of the fighter-specific explainable effect values.
//{
#define EFFECT_VALUES(X) (          \
    X == 0 ? RANK_CONVERSION_VALUE  \
    : X == 1 ? ADAPTABLE_VALUE      \
    : X == 2 ? AFFINITY_VALUE       \
    : X == 3 ? COMBO_VALUE          \
    : X == 4 ? FORSAKEN_VALUE       \
    : X == 5 ? AGGRESSIVE_VALUE     \
    : X == 6 ? INVINCIBILITY_VALUE  \
    : X == 7 ? ROOT_VALUE           \
    : X == 8 ? CRIPPLE_VALUE        \
    : X == 9 ? IMPAIR_VALUE         \
    : X == 10 ? FIGHTER_POWER_VALUE \
    : X == 11 ? AGILITY_VALUE       \
    : X == 12 ? CURSE_VALUE         \
    : RANK_BOND_VALUE               \
)
//}

// All of the fighter-specific explainable effect expanations.
//{
#define EFFECT_EXPLANATIONS(X) (          \
    X == 0 ? RANK_CONVERSION_EXPLANATION  \
    : X == 1 ? ADAPTABLE_EXPLANATION      \
    : X == 2 ? AFFINITY_EXPLANATION       \
    : X == 3 ? COMBO_EXPLANATION          \
    : X == 4 ? FORSAKEN_EXPLANATION       \
    : X == 5 ? AGGRESSIVE_EXPLANATION     \
    : X == 6 ? INVINCIBILITY_EXPLANATION  \
    : X == 7 ? ROOT_EXPLANATION           \
    : X == 8 ? CRIPPLE_EXPLANATION        \
    : X == 9 ? IMPAIR_EXPLANATION         \
    : X == 10 ? FIGHTER_POWER_EXPLANATION \
    : X == 11 ? AGILITY_EXPLANATION       \
    : X == 12 ? CURSE_EXPLANATION         \
    : RANK_BOND_EXPLANATION               \
)
//}

// The total number of player-specific explainable effects.
constexpr int PLAYER_EXPLANATION_COUNT = 20;

// All of the player-specific explainable effect conditions.
//{
#define PLAYER_EFFECT_CONDITIONS(X) (                                 \
    X == 0 ? static_cast<bool>(PREPARATION_CONDITION)                 \
    : X == 1 ? static_cast<bool>(CARD_PLAYS_CONDITION)                \
    : X == 2 ? static_cast<bool>(NEXT_CARD_PLAYS_CONDITION)           \
    : X == 3 ? static_cast<bool>(NEXT_TURN_CARD_PLAYS_CONDITION)      \
    : X == 4 ? static_cast<bool>(FATIGUE_CONDITION)                   \
    : X == 5 ? static_cast<bool>(ATTACKED_CONDITION)                  \
    : X == 6 ? static_cast<bool>(RETREATED_CONDITION)                 \
    : X == 7 ? static_cast<bool>(FORBIDDEN_FUEL_CONDITION)            \
    : X == 8 ? static_cast<bool>(BOOST_CONDITION)                     \
    : X == 9 ? static_cast<bool>(BANISHMENT_CONDITION)                \
    : X == 10 ? static_cast<bool>(FREEDOM_CONDITION)                  \
    : X == 11 ? static_cast<bool>(AGILITY_AURA_CONDITION)             \
    : X == 12 ? static_cast<bool>(HEAL_AURA_CONDITION)                \
    : X == 13 ? static_cast<bool>(POWER_AURA_CONDITION)               \
    : X == 14 ? static_cast<bool>(PLAYER_POWER_CONDITION)             \
    : X == 15 ? static_cast<bool>(END_DRAW_CONDITION)                 \
    : X == 16 ? static_cast<bool>(EXPERIMENTER_END_DISCARD_CONDITION) \
    : X == 17 ? static_cast<bool>(BANKER_END_DISCARD_CONDITION)       \
    : X == 18 ? static_cast<bool>(GATEKEEPER_END_DISCARD_CONDITION)   \
    : static_cast<bool>(MILLER_END_DISCARD_CONDITION)                 \
)
//}

// All of the player-specific explainable effect representations.
constexpr const char* PLAYER_EFFECT_REPRESENTATIONS[PLAYER_EXPLANATION_COUNT] = {
    PREPARATION_REPRESENTATION,
    CARD_PLAYS_REPRESENTATION,
    NEXT_CARD_PLAYS_REPRESENTATION,
    NEXT_TURN_CARD_PLAYS_REPRESENTATION,
    FATIGUE_REPRESENTATION,
    ATTACKED_REPRESENTATION,
    RETREATED_REPRESENTATION,
    FORBIDDEN_FUEL_REPRESENTATION,
    BOOST_REPRESENTATION,
    BANISHMENT_REPRESENTATION,
    FREEDOM_REPRESENTATION,
    AGILITY_AURA_REPRESENTATION,
    HEAL_AURA_REPRESENTATION,
    POWER_AURA_REPRESENTATION,
    PLAYER_POWER_REPRESENTATION,
    END_DRAW_REPRESENTATION,
    END_DISCARD_REPRESENTATION,
    END_DISCARD_REPRESENTATION,
    END_DISCARD_REPRESENTATION,
    END_DISCARD_REPRESENTATION
};

// All of the player-specific explainable effect values.
//{
#define PLAYER_EFFECT_VALUES(X) (              \
    X == 0 ? PREPARATION_VALUE                 \
    : X == 1 ? CARD_PLAYS_VALUE                \
    : X == 2 ? NEXT_CARD_PLAYS_VALUE           \
    : X == 3 ? NEXT_TURN_CARD_PLAYS_VALUE      \
    : X == 4 ? FATIGUE_VALUE                   \
    : X == 5 ? ATTACKED_VALUE                  \
    : X == 6 ? RETREATED_VALUE                 \
    : X == 7 ? FORBIDDEN_FUEL_VALUE            \
    : X == 8 ? BOOST_VALUE                     \
    : X == 9 ? BANISHMENT_VALUE                \
    : X == 10 ? FREEDOM_VALUE                  \
    : X == 11 ? AGILITY_AURA_VALUE             \
    : X == 12 ? HEAL_AURA_VALUE                \
    : X == 13 ? POWER_AURA_VALUE               \
    : X == 14 ? PLAYER_POWER_VALUE             \
    : X == 15 ? END_DRAW_VALUE                 \
    : X == 16 ? EXPERIMENTER_END_DISCARD_VALUE \
    : X == 17 ? BANKER_END_DISCARD_VALUE       \
    : X == 18 ? GATEKEEPER_END_DISCARD_VALUE   \
    : MILLER_END_DISCARD_VALUE                 \
)
//}

// All of the player-specific explainable effect expanations.
//{
#define PLAYER_EFFECT_EXPLANATIONS(X) (         \
    X == 0 ? PREPARATION_EXPLANATION            \
    : X == 1 ? CARD_PLAYS_EXPLANATION           \
    : X == 2 ? NEXT_CARD_PLAYS_EXPLANATION      \
    : X == 3 ? NEXT_TURN_CARD_PLAYS_EXPLANATION \
    : X == 4 ? FATIGUE_EXPLANATION              \
    : X == 5 ? ATTACKED_EXPLANATION             \
    : X == 6 ? RETREATED_EXPLANATION            \
    : X == 7 ? FORBIDDEN_FUEL_EXPLANATION       \
    : X == 8 ? BOOST_EXPLANATION                \
    : X == 9 ? BANISHMENT_EXPLANATION           \
    : X == 10 ? FREEDOM_EXPLANATION             \
    : X == 11 ? AGILITY_AURA_EXPLANATION        \
    : X == 12 ? HEAL_AURA_EXPLANATION           \
    : X == 13 ? POWER_AURA_EXPLANATION          \
    : X == 14 ? PLAYER_POWER_EXPLANATION        \
    : X == 15 ? END_DRAW_EXPLANATION            \
    : X == 16 ? END_DISCARD_EXPLANATION         \
    : X == 17 ? END_DISCARD_EXPLANATION         \
    : X == 18 ? END_DISCARD_EXPLANATION         \
    : END_DISCARD_EXPLANATION                   \
)
//}
//}
//}

// Video Constants
//{
// Main and Connection Menus Constants
//{
// The position and dimensions of the title.
constexpr double TITLE_X = 0.5;
constexpr double TITLE_Y = 0.2;
constexpr double TITLE_WIDTH = 0.075;
constexpr double TITLE_HEIGHT = 2 * TITLE_WIDTH;
constexpr double TITLE_SEPARATION = TITLE_WIDTH / 20;

// The constants for the credits sprite.
#define CREDITS_STRING (     \
    "2020 Chigozie Agomo\nv" \
    + version_string         \
)
constexpr double CREDITS_X = 0.25;
constexpr double CREDITS_Y = 0.925;
constexpr double CREDITS_WIDTH = 0.025;
constexpr double CREDITS_HEIGHT = 2 * CREDITS_WIDTH;
constexpr double CREDITS_MAX_WIDTH = 0;
constexpr double CREDITS_SEPARATION_X = CREDITS_WIDTH / 10;
constexpr double CREDITS_SEPARATION_Y = 5 * CREDITS_SEPARATION_X;
constexpr Renderer::Justification CREDITS_JUSTIFICATION = Renderer::LEFT_JUSTIFY;

// The constants for the quit buton.
constexpr const char* QUIT_STRING = "Quit";
constexpr double QUIT_X = 0.875;
constexpr double QUIT_X_ALT = 1 - QUIT_X;
constexpr double QUIT_Y = 0.925;
constexpr double QUIT_WIDTH = 0.05;
constexpr double QUIT_HEIGHT = 2 * QUIT_WIDTH;
constexpr double QUIT_SEPARATION = QUIT_WIDTH / 20;

// The constants for the play button.
constexpr const char* PLAY_STRING = "Play";
constexpr double PLAY_X = TITLE_X;
constexpr double PLAY_Y = 0.7;
constexpr double PLAY_WIDTH = QUIT_WIDTH;
constexpr double PLAY_HEIGHT = 2 * PLAY_WIDTH;
constexpr double PLAY_SEPARATION = PLAY_WIDTH / 20;

// The constants for the server button.
constexpr const char* SERVER_STRING = "Server";
constexpr double SERVER_X = TITLE_X;
constexpr double SERVER_Y = 0.3;
constexpr double SERVER_WIDTH = PLAY_WIDTH;
constexpr double SERVER_HEIGHT = 2 * SERVER_WIDTH;
constexpr double SERVER_SEPARATION = SERVER_WIDTH / 20;

// The constants for the client button.
constexpr const char* CLIENT_STRING = "Client";
constexpr double CLIENT_X = SERVER_X;
constexpr double CLIENT_Y = 1 - SERVER_Y;
constexpr double CLIENT_WIDTH = SERVER_WIDTH;
constexpr double CLIENT_HEIGHT = SERVER_HEIGHT;
constexpr double CLIENT_SEPARATION = SERVER_SEPARATION;

// The constants for the back button.
constexpr const char* BACK_STRING = "Back";
constexpr double BACK_X = 1 - QUIT_X;
constexpr double BACK_Y = QUIT_Y;
constexpr double BACK_WIDTH = QUIT_WIDTH;
constexpr double BACK_HEIGHT = QUIT_HEIGHT;
constexpr double BACK_SEPARATION = QUIT_SEPARATION;

// The constants for the next button.
constexpr const char* NEXT_STRING = "Next";
constexpr double NEXT_X = 1 - BACK_X;
constexpr double NEXT_Y = BACK_Y;
constexpr double NEXT_WIDTH = BACK_WIDTH;
constexpr double NEXT_HEIGHT = BACK_HEIGHT;
constexpr double NEXT_SEPARATION = BACK_SEPARATION;

// The constants for the address sprite.
constexpr const char* ADDRESS_STRING = "Address";
constexpr double ADDRESS_X = SERVER_X;
constexpr double ADDRESS_Y = SERVER_Y;
constexpr double ADDRESS_SHIFT = 0.5 - SERVER_Y;
constexpr double ADDRESS_WIDTH = SERVER_WIDTH;
constexpr double ADDRESS_HEIGHT = SERVER_HEIGHT;
constexpr double ADDRESS_SEPARATION = SERVER_SEPARATION;

// The constants for the port sprite.
constexpr const char* PORT_STRING = "Port";
constexpr double PORT_X = ADDRESS_X;
constexpr double PORT_Y = ADDRESS_Y;
constexpr double PORT_SHIFT = ADDRESS_SHIFT;
constexpr double PORT_WIDTH = ADDRESS_WIDTH;
constexpr double PORT_HEIGHT = ADDRESS_HEIGHT;
constexpr double PORT_SEPARATION = ADDRESS_SEPARATION;

// The constants for the wait sprite.
constexpr const char* WAIT_STRING = "Waiting for\nthe opponent...";
constexpr double WAIT_X = 0.5;
constexpr double WAIT_Y = 0.5;
constexpr double WAIT_WIDTH = PORT_WIDTH;
constexpr double WAIT_HEIGHT = PORT_HEIGHT;
constexpr double WAIT_MAX_WIDTH = 0;
constexpr double WAIT_SEPARATION_X = PORT_SEPARATION;
constexpr double WAIT_SEPARATION_Y = 50 * WAIT_SEPARATION_X;
constexpr Renderer::Justification WAIT_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// The constants for the no server sprite.
constexpr const char* NO_SERVER_STRING = "The host could\nnot be resolved.";
constexpr double NO_SERVER_X = WAIT_X;
constexpr double NO_SERVER_Y = WAIT_Y;
constexpr double NO_SERVER_WIDTH = WAIT_WIDTH;
constexpr double NO_SERVER_HEIGHT = WAIT_HEIGHT;
constexpr double NO_SERVER_MAX_WIDTH = WAIT_MAX_WIDTH;
constexpr double NO_SERVER_SEPARATION_X = WAIT_SEPARATION_X;
constexpr double NO_SERVER_SEPARATION_Y = WAIT_SEPARATION_Y;
constexpr Renderer::Justification NO_SERVER_JUSTIFICATION = WAIT_JUSTIFICATION;
//}

// Deck Builder Constants
//{
// The constants for the deck builder sprite.
constexpr const char* BUILDER_STRING = "Build your deck!";
constexpr double BUILDER_X = 0.5;
constexpr double BUILDER_Y = 0.1;
constexpr double BUILDER_WIDTH = PORT_WIDTH;
constexpr double BUILDER_HEIGHT = PORT_HEIGHT;
constexpr double BUILDER_SEPARATION = PORT_SEPARATION;

// The constants for the fighter button.
constexpr const char* FIGHTER_STRING = "Fighter";
constexpr double FIGHTER_X = BUILDER_X;
constexpr double FIGHTER_Y = BUILDER_Y + 0.3;
constexpr double FIGHTER_WIDTH = 0.75 * BUILDER_WIDTH;
constexpr double FIGHTER_HEIGHT = 2 * FIGHTER_WIDTH;
constexpr double FIGHTER_SEPARATION = FIGHTER_WIDTH / 20;

// The constants for the supporter button.
constexpr const char* SUPPORTER_STRING = "Supporter";
constexpr double SUPPORTER_X = FIGHTER_X;
constexpr double SUPPORTER_Y = FIGHTER_Y + 0.125;
constexpr double SUPPORTER_WIDTH = FIGHTER_WIDTH;
constexpr double SUPPORTER_HEIGHT = FIGHTER_HEIGHT;
constexpr double SUPPORTER_SEPARATION = FIGHTER_SEPARATION;

// The constants for the energy button.
constexpr const char* ENERGY_STRING = "Energy";
constexpr double ENERGY_X = SUPPORTER_X;
constexpr double ENERGY_Y = SUPPORTER_Y + 0.125;
constexpr double ENERGY_WIDTH = SUPPORTER_WIDTH;
constexpr double ENERGY_HEIGHT = SUPPORTER_HEIGHT;
constexpr double ENERGY_SEPARATION = SUPPORTER_SEPARATION;

// The constants for the generator button.
constexpr const char* GENERATOR_STRING = "Deck Generator";
constexpr double GENERATOR_X = ENERGY_X;
constexpr double GENERATOR_Y = ENERGY_Y + 0.125;
constexpr double GENERATOR_WIDTH = ENERGY_WIDTH;
constexpr double GENERATOR_HEIGHT = ENERGY_HEIGHT;
constexpr double GENERATOR_SEPARATION = ENERGY_SEPARATION;

// The constants for the done button.
constexpr const char* DONE_STRING = "Done";
constexpr double DONE_X = QUIT_X;
constexpr double DONE_Y = QUIT_Y;
constexpr double DONE_WIDTH = QUIT_WIDTH;
constexpr double DONE_HEIGHT = QUIT_HEIGHT;
constexpr double DONE_SEPARATION = QUIT_SEPARATION;

// The constants for the deck capacity sprite.
#define CAPACITY_STRING (        \
    "Cards "                     \
    + std::to_string(card_count) \
    + '/'                        \
    + std::to_string(DECK_SIZE)  \
)
constexpr double CAPACITY_X = BUILDER_X;
constexpr double CAPACITY_Y = BUILDER_Y + 0.175;
constexpr double CAPACITY_WIDTH = FIGHTER_WIDTH;
constexpr double CAPACITY_HEIGHT = FIGHTER_HEIGHT;
constexpr double CAPACITY_SEPARATION = FIGHTER_SEPARATION;

// The constants for the incompatible sprite.
constexpr const char* INCOMPATIBLE_STRING = "The versions of the program are incompatible...";
constexpr double INCOMPATIBLE_X = 0.5;
constexpr double INCOMPATIBLE_Y = 0.5;
constexpr double INCOMPATIBLE_WIDTH = NO_SERVER_WIDTH;
constexpr double INCOMPATIBLE_HEIGHT = NO_SERVER_HEIGHT;
constexpr double INCOMPATIBLE_MAX_WIDTH = 20 * INCOMPATIBLE_WIDTH;
constexpr double INCOMPATIBLE_SEPARATION_X = NO_SERVER_SEPARATION_X;
constexpr double INCOMPATIBLE_SEPARATION_Y = NO_SERVER_SEPARATION_Y;
constexpr Renderer::Justification INCOMPATIBLE_JUSTIFICATION = NO_SERVER_JUSTIFICATION;

// The constants for the card sprites.
#define CARD_STRING (card.to_string())
constexpr double CARD_X = 0.5;
constexpr double CARD_Y = 0.5;
constexpr double CARD_WIDTH = INCOMPATIBLE_WIDTH / 3;
constexpr double CARD_HEIGHT = 2 * CARD_WIDTH;
constexpr double CARD_MAX_WIDTH = 0.5;
constexpr double CARD_SEPARATION_X = CARD_WIDTH / 20;
constexpr double CARD_SEPARATION_Y = CARD_HEIGHT / 8;
constexpr Renderer::Justification CARD_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// The constants for the left arrow button.
constexpr const char* LEFT_SOURCE = "data/left.bmp";
constexpr double LEFT_X = 0.1;
constexpr double LEFT_Y = 0.5;
constexpr double LEFT_WIDTH = 0.05;
constexpr double LEFT_HEIGHT = 0.1;

// The constants for the right arrow button.
constexpr const char* RIGHT_SOURCE = "data/right.bmp";
constexpr double RIGHT_X = 1 - LEFT_X;
constexpr double RIGHT_Y = LEFT_Y;
constexpr double RIGHT_WIDTH = LEFT_WIDTH;
constexpr double RIGHT_HEIGHT = LEFT_HEIGHT;

// The constants for the card page.
constexpr double PAGE_NAME_X = 0.375;
constexpr double PAGE_VALUE_X = 0.725;
constexpr double PAGE_Y = 0.4;
constexpr double PAGE_Y_SHIFT = 0.075;
constexpr double PAGE_WIDTH = INCOMPATIBLE_WIDTH / 2;
constexpr double PAGE_HEIGHT = INCOMPATIBLE_HEIGHT / 2;
constexpr double PAGE_SEPARATION = PAGE_WIDTH / 20;

// The constants for the minus buttons.
constexpr double MINUS_X = PAGE_VALUE_X - 0.1;
constexpr double MINUS_Y = PAGE_Y;
constexpr double MINUS_Y_SHIFT = PAGE_Y_SHIFT;
constexpr double MINUS_WIDTH = 0.75 * PAGE_HEIGHT;
constexpr double MINUS_HEIGHT = MINUS_WIDTH;

// The constants for the plus buttons.
constexpr double PLUS_X = 2 * PAGE_VALUE_X - MINUS_X;
constexpr double PLUS_Y = MINUS_Y;
constexpr double PLUS_Y_SHIFT = MINUS_Y_SHIFT;
constexpr double PLUS_WIDTH = MINUS_WIDTH;
constexpr double PLUS_HEIGHT = MINUS_HEIGHT;

// The constants for the generate button.
constexpr const char* GENERATE_STRING = "Generate";
constexpr double GENERATE_X = PAGE_VALUE_X;
constexpr double GENERATE_Y = PAGE_Y;
constexpr double GENERATE_Y_SHIFT = PAGE_Y_SHIFT;
constexpr double GENERATE_WIDTH = PAGE_WIDTH;
constexpr double GENERATE_HEIGHT = PAGE_HEIGHT;
constexpr double GENERATE_SEPARATION = PAGE_SEPARATION;

// The constants for the description button.
#define DESCRIPTION_STRING (ALL_DECK_CODES[page * PAGE_COUNT + i]->get_description())
constexpr double DESCRIPTION_X = CARD_X;
constexpr double DESCRIPTION_Y = CARD_Y;
constexpr double DESCRIPTION_WIDTH = CARD_WIDTH;
constexpr double DESCRIPTION_HEIGHT = CARD_HEIGHT;
constexpr double DESCRIPTION_MAX_WIDTH = CARD_MAX_WIDTH;
constexpr double DESCRIPTION_SEPARATION_X = CARD_SEPARATION_X;
constexpr double DESCRIPTION_SEPARATION_Y = CARD_SEPARATION_Y;
constexpr Renderer::Justification DESCRIPTION_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// The constants for the deck error sprite.
#define INVALID_SIZE_STRING (         \
    "A deck must consist of exactly " \
    + std::to_string(DECK_SIZE)       \
    + " cards."                       \
)
constexpr const char* NO_BASICS_STRING =
    "A deck must have at least 1 fighter that doesn't rank up from another fighter."
;
constexpr double DECK_ERROR_X = INCOMPATIBLE_X;
constexpr double DECK_ERROR_Y = INCOMPATIBLE_Y;
constexpr double DECK_ERROR_WIDTH = 0.75 * INCOMPATIBLE_WIDTH;
constexpr double DECK_ERROR_HEIGHT = 2 * DECK_ERROR_WIDTH;
constexpr double DECK_ERROR_MAX_WIDTH = 0.75;
constexpr double DECK_ERROR_SEPARATION_X = DECK_ERROR_WIDTH / 20;
constexpr double DECK_ERROR_SEPARATION_Y = 0.4 * DECK_ERROR_HEIGHT;
constexpr Renderer::Justification DECK_ERROR_JUSTIFICATION = INCOMPATIBLE_JUSTIFICATION;
//}

// Main Game Setup Constants
//{
// Constants for the mulligan fail sprite.
#define MULLIGAN_FAIL_STRING (                         \
    std::string(opposing ? "Your opponent's" : "Your") \
    + " hand has no playable fighters."                \
)
constexpr double MULLIGAN_FAIL_X = 0.5;
constexpr double MULLIGAN_FAIL_Y = 0.5;
constexpr double MULLIGAN_FAIL_WIDTH = DECK_ERROR_WIDTH;
constexpr double MULLIGAN_FAIL_HEIGHT = DECK_ERROR_HEIGHT;
constexpr double MULLIGAN_FAIL_MAX_WIDTH = DECK_ERROR_MAX_WIDTH;
constexpr double MULLIGAN_FAIL_SEPARATION_X = DECK_ERROR_SEPARATION_X;
constexpr double MULLIGAN_FAIL_SEPARATION_Y = DECK_ERROR_SEPARATION_Y;
constexpr Renderer::Justification MULLIGAN_FAIL_JUSTIFICATION = DECK_ERROR_JUSTIFICATION;

// Constants for the new mulligan sprite.
#define NEW_MULLIGAN_STRING (                       \
    std::string(opposing ? "Your opponent" : "You") \
    + " will redraw "                               \
    + (opposing ? "their" : "your")                 \
    + " starting hand."                             \
)
constexpr double NEW_MULLIGAN_X = MULLIGAN_FAIL_X;
constexpr double NEW_MULLIGAN_Y = MULLIGAN_FAIL_Y;
constexpr double NEW_MULLIGAN_WIDTH = MULLIGAN_FAIL_WIDTH;
constexpr double NEW_MULLIGAN_HEIGHT = MULLIGAN_FAIL_HEIGHT;
constexpr double NEW_MULLIGAN_MAX_WIDTH = MULLIGAN_FAIL_MAX_WIDTH;
constexpr double NEW_MULLIGAN_SEPARATION_X = MULLIGAN_FAIL_SEPARATION_X;
constexpr double NEW_MULLIGAN_SEPARATION_Y = MULLIGAN_FAIL_SEPARATION_Y;
constexpr Renderer::Justification NEW_MULLIGAN_JUSTIFICATION = MULLIGAN_FAIL_JUSTIFICATION;

// Constants for the player ordering sprite.
#define ORDER_STRING ("You go " + std::string(turn ? "second" : "first") + ".")
constexpr double ORDER_X = NEW_MULLIGAN_X;
constexpr double ORDER_Y = NEW_MULLIGAN_Y;
constexpr double ORDER_WIDTH = NEW_MULLIGAN_WIDTH;
constexpr double ORDER_HEIGHT = NEW_MULLIGAN_HEIGHT;
constexpr double ORDER_MAX_WIDTH = NEW_MULLIGAN_MAX_WIDTH;
constexpr double ORDER_SEPARATION_X = NEW_MULLIGAN_SEPARATION_X;
constexpr double ORDER_SEPARATION_Y = NEW_MULLIGAN_SEPARATION_Y;
constexpr Renderer::Justification ORDER_JUSTIFICATION = NEW_MULLIGAN_JUSTIFICATION;

// Constants for the life cards announcement sprite.
#define LIFE_STRING (                               \
    std::string(opposing ? "Your opponent" : "You") \
    + " set out "                                   \
    + std::to_string(LIFE_SIZE)                          \
    + " life cards."                                \
)
constexpr double LIFE_X = ORDER_X;
constexpr double LIFE_Y = ORDER_Y;
constexpr double LIFE_WIDTH = ORDER_WIDTH;
constexpr double LIFE_HEIGHT = ORDER_HEIGHT;
constexpr double LIFE_MAX_WIDTH = ORDER_MAX_WIDTH;
constexpr double LIFE_SEPARATION_X = ORDER_SEPARATION_X;
constexpr double LIFE_SEPARATION_Y = ORDER_SEPARATION_Y;
constexpr Renderer::Justification LIFE_JUSTIFICATION = ORDER_JUSTIFICATION;

// Constants for the bonus draw sprite.
#define BONUS_DRAW_STRING (        \
    "You may draw up to "          \
    + std::to_string(difference)   \
    + " extra card"                \
    + (difference == 1 ? "" : "s") \
    + "!"                          \
)
constexpr double BONUS_DRAW_X = LIFE_X;
constexpr double BONUS_DRAW_Y = LIFE_Y;
constexpr double BONUS_DRAW_WIDTH = LIFE_WIDTH;
constexpr double BONUS_DRAW_HEIGHT = LIFE_HEIGHT;
constexpr double BONUS_DRAW_MAX_WIDTH = LIFE_MAX_WIDTH;
constexpr double BONUS_DRAW_SEPARATION_X = LIFE_SEPARATION_X;
constexpr double BONUS_DRAW_SEPARATION_Y = LIFE_SEPARATION_Y;
constexpr Renderer::Justification BONUS_DRAW_JUSTIFICATION = LIFE_JUSTIFICATION;

// Constants for the opponent's bonus draw sprite.
#define NO_BONUS_DRAW_STRING (      \
    "Your opponent may draw up to " \
    + std::to_string(-difference)   \
    + " extra card"                 \
    + (difference == -1 ? "" : "s") \
    + "..."                         \
)
constexpr double NO_BONUS_DRAW_X = BONUS_DRAW_X;
constexpr double NO_BONUS_DRAW_Y = BONUS_DRAW_Y;
constexpr double NO_BONUS_DRAW_WIDTH = BONUS_DRAW_WIDTH;
constexpr double NO_BONUS_DRAW_HEIGHT = BONUS_DRAW_HEIGHT;
constexpr double NO_BONUS_DRAW_MAX_WIDTH = BONUS_DRAW_MAX_WIDTH;
constexpr double NO_BONUS_DRAW_SEPARATION_X = BONUS_DRAW_SEPARATION_X;
constexpr double NO_BONUS_DRAW_SEPARATION_Y = BONUS_DRAW_SEPARATION_Y;
constexpr Renderer::Justification NO_BONUS_DRAW_JUSTIFICATION = BONUS_DRAW_JUSTIFICATION;

// Constants for the opponent's draw sprite.
#define OPPONENT_DRAW_STRING (  \
    "Your opponent drew "       \
    + std::to_string(draws)     \
    + " card"                   \
    + (draws == 1 ? "." : "s.") \
)
constexpr double OPPONENT_DRAW_X = NO_BONUS_DRAW_X;
constexpr double OPPONENT_DRAW_Y = NO_BONUS_DRAW_Y;
constexpr double OPPONENT_DRAW_WIDTH = NO_BONUS_DRAW_WIDTH;
constexpr double OPPONENT_DRAW_HEIGHT = NO_BONUS_DRAW_HEIGHT;
constexpr double OPPONENT_DRAW_MAX_WIDTH = NO_BONUS_DRAW_MAX_WIDTH;
constexpr double OPPONENT_DRAW_SEPARATION_X = NO_BONUS_DRAW_SEPARATION_X;
constexpr double OPPONENT_DRAW_SEPARATION_Y = NO_BONUS_DRAW_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_DRAW_JUSTIFICATION = NO_BONUS_DRAW_JUSTIFICATION;

// Constants for the bonus sprite.
#define BONUS_STRING (           \
    "Bonus Draw ("               \
    + std::to_string(difference) \
    + " max)"                    \
)
constexpr double BONUS_X = PORT_X;
constexpr double BONUS_Y = PORT_Y;
constexpr double BONUS_SHIFT = PORT_SHIFT;
constexpr double BONUS_WIDTH = PORT_WIDTH;
constexpr double BONUS_HEIGHT = PORT_HEIGHT;
constexpr double BONUS_SEPARATION = PORT_SEPARATION;

// Constants for the mulligan sprite.
#define MULLIGAN_STRING (                   \
    "Both players will draw "               \
    + std::to_string(HAND_SIZE)             \
    + " cards to form their starting hand." \
) 
constexpr double MULLIGAN_X = OPPONENT_DRAW_X;
constexpr double MULLIGAN_Y = OPPONENT_DRAW_Y;
constexpr double MULLIGAN_WIDTH = OPPONENT_DRAW_WIDTH;
constexpr double MULLIGAN_HEIGHT = OPPONENT_DRAW_HEIGHT;
constexpr double MULLIGAN_MAX_WIDTH = OPPONENT_DRAW_MAX_WIDTH;
constexpr double MULLIGAN_SEPARATION_X = OPPONENT_DRAW_SEPARATION_X;
constexpr double MULLIGAN_SEPARATION_Y = OPPONENT_DRAW_SEPARATION_Y;
constexpr Renderer::Justification MULLIGAN_JUSTIFICATION = OPPONENT_DRAW_JUSTIFICATION;

// Constants for the active fighter sprite.
constexpr const char* SET_ACTIVE_STRING =
    "Choose an unranked fighter to be your active fighter!"
;
constexpr double SET_ACTIVE_X = MULLIGAN_X;
constexpr double SET_ACTIVE_Y = MULLIGAN_Y;
constexpr double SET_ACTIVE_WIDTH = MULLIGAN_WIDTH;
constexpr double SET_ACTIVE_HEIGHT = MULLIGAN_HEIGHT;
constexpr double SET_ACTIVE_MAX_WIDTH = MULLIGAN_MAX_WIDTH;
constexpr double SET_ACTIVE_SEPARATION_X = MULLIGAN_SEPARATION_X;
constexpr double SET_ACTIVE_SEPARATION_Y = MULLIGAN_SEPARATION_Y;
constexpr Renderer::Justification SET_ACTIVE_JUSTIFICATION = MULLIGAN_JUSTIFICATION;

// Constants for the basic fighter sprite.
constexpr const char* BASIC_FIGHTER_STRING = "Choose a basic fighter:";
constexpr double BASIC_FIGHTER_X = BUILDER_X;
constexpr double BASIC_FIGHTER_Y = BUILDER_Y;
constexpr double BASIC_FIGHTER_WIDTH = 0.75 * BUILDER_WIDTH;
constexpr double BASIC_FIGHTER_HEIGHT = 2 * BASIC_FIGHTER_WIDTH;
constexpr double BASIC_FIGHTER_SEPARATION = BASIC_FIGHTER_WIDTH / 20;

// The constants for the choice button.
constexpr const char* CHOICE_STRING = "Choose";
constexpr double CHOICE_X = GENERATE_X;
constexpr double CHOICE_Y = GENERATE_Y;
constexpr double CHOICE_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double CHOICE_WIDTH = GENERATE_WIDTH;
constexpr double CHOICE_HEIGHT = GENERATE_HEIGHT;
constexpr double CHOICE_SEPARATION = GENERATE_SEPARATION;

// The constants for the game sprite.
#define GAME_STRING (                                 \
    winner == TIE ? "It's a tie!" :                   \
    "You " + std::string(winner ? "lose..." : "win!") \
)
constexpr double GAME_X = 0.5;
constexpr double GAME_Y = 0.5;
constexpr double GAME_WIDTH = 0.875 * TITLE_WIDTH;
constexpr double GAME_HEIGHT = 2 * GAME_WIDTH;
constexpr double GAME_SEPARATION = GAME_WIDTH / 20;

// The constants for the store size sprite.
#define STORE_SIZE_STRING (    \
    "Contains "                \
    + std::to_string(size())   \
    + " card"                  \
    + (size() == 1 ? "" : "s") \
    + ":"                      \
)
constexpr double STORE_SIZE_X = BUILDER_X;
constexpr double STORE_SIZE_Y = BUILDER_Y;
constexpr double STORE_SIZE_WIDTH = 0.75 * BUILDER_WIDTH;
constexpr double STORE_SIZE_HEIGHT = 2 * STORE_SIZE_WIDTH;
constexpr double STORE_SIZE_SEPARATION = STORE_SIZE_WIDTH / 20;
//}

// Duel Board Constants
//{
// The player's Buttons
//{
// Constants for the player's deck button.
constexpr const char* YOUR_DECK_STRING = "Your\nDeck";
constexpr double YOUR_DECK_X = 0.85;
constexpr double YOUR_DECK_Y = 0.6;
constexpr double YOUR_DECK_WIDTH = 0.02;
constexpr double YOUR_DECK_HEIGHT = 2 * YOUR_DECK_WIDTH;
constexpr double YOUR_DECK_MAX_WIDTH = 0;
constexpr double YOUR_DECK_SEPARATION_X = YOUR_DECK_WIDTH / 20;
constexpr double YOUR_DECK_SEPARATION_Y = YOUR_DECK_HEIGHT / 5;
constexpr Renderer::Justification YOUR_DECK_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// Constants for the player's trash button.
constexpr const char* YOUR_TRASH_STRING = "Your\nTrash";
constexpr double YOUR_TRASH_X = YOUR_DECK_X;
constexpr double YOUR_TRASH_Y = YOUR_DECK_Y + 0.175;
constexpr double YOUR_TRASH_WIDTH = YOUR_DECK_WIDTH;
constexpr double YOUR_TRASH_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double YOUR_TRASH_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double YOUR_TRASH_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double YOUR_TRASH_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification YOUR_TRASH_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;

// Constants for the player's hand button.
constexpr const char* YOUR_HAND_STRING = "Your Hand";
constexpr double YOUR_HAND_X = 0.5;
constexpr double YOUR_HAND_Y = 0.95;
constexpr double YOUR_HAND_WIDTH = YOUR_DECK_WIDTH;
constexpr double YOUR_HAND_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double YOUR_HAND_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double YOUR_HAND_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double YOUR_HAND_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification YOUR_HAND_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;

// Constants for the player's life cards button.
constexpr const char* YOUR_LIFE_STRING = "Your\nLife\nCards";
constexpr double YOUR_LIFE_X = 1 - YOUR_DECK_X;
constexpr double YOUR_LIFE_Y = 0.7;
constexpr double YOUR_LIFE_WIDTH = YOUR_DECK_WIDTH;
constexpr double YOUR_LIFE_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double YOUR_LIFE_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double YOUR_LIFE_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double YOUR_LIFE_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification YOUR_LIFE_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;

// Constants for the player's active fighter button.
constexpr const char* YOUR_ACTIVE_STRING = "Your Active\nFighter";
constexpr double YOUR_ACTIVE_X = YOUR_HAND_X;
constexpr double YOUR_ACTIVE_Y = YOUR_DECK_Y;
constexpr double YOUR_ACTIVE_WIDTH = YOUR_DECK_WIDTH;
constexpr double YOUR_ACTIVE_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double YOUR_ACTIVE_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double YOUR_ACTIVE_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double YOUR_ACTIVE_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification YOUR_ACTIVE_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;

// Constants for the player's benched fighter button.
constexpr const char* YOUR_BENCH_STRING = "Your Benched\nFighters";
constexpr double YOUR_BENCH_X = YOUR_HAND_X;
constexpr double YOUR_BENCH_Y = YOUR_TRASH_Y;
constexpr double YOUR_BENCH_WIDTH = YOUR_DECK_WIDTH;
constexpr double YOUR_BENCH_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double YOUR_BENCH_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double YOUR_BENCH_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double YOUR_BENCH_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification YOUR_BENCH_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;

// Constants for the player's effects button.
constexpr const char* YOUR_EFFECTS_STRING = "Your\nEffects";
constexpr double YOUR_EFFECTS_X = QUIT_X_ALT;
constexpr double YOUR_EFFECTS_Y = QUIT_Y;
constexpr double YOUR_EFFECTS_WIDTH = YOUR_DECK_WIDTH;
constexpr double YOUR_EFFECTS_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double YOUR_EFFECTS_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double YOUR_EFFECTS_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double YOUR_EFFECTS_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification YOUR_EFFECTS_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;
//}

// The opponent's buttons
//{
// Constants for the opponent's deck button.
constexpr const char* OPPONENT_DECK_STRING = "Opponent's\nDeck";
constexpr double OPPONENT_DECK_X = YOUR_DECK_X;
constexpr double OPPONENT_DECK_Y = 1 - YOUR_DECK_Y;
constexpr double OPPONENT_DECK_WIDTH = YOUR_DECK_WIDTH;
constexpr double OPPONENT_DECK_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double OPPONENT_DECK_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double OPPONENT_DECK_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double OPPONENT_DECK_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_DECK_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;

// Constants for the opponent's trash button.
constexpr const char* OPPONENT_TRASH_STRING = "Opponent's\nTrash";
constexpr double OPPONENT_TRASH_X = OPPONENT_DECK_X;
constexpr double OPPONENT_TRASH_Y = 1 - YOUR_TRASH_Y;
constexpr double OPPONENT_TRASH_WIDTH = OPPONENT_DECK_WIDTH;
constexpr double OPPONENT_TRASH_HEIGHT = OPPONENT_DECK_HEIGHT;
constexpr double OPPONENT_TRASH_MAX_WIDTH = OPPONENT_DECK_MAX_WIDTH;
constexpr double OPPONENT_TRASH_SEPARATION_X = OPPONENT_DECK_SEPARATION_X;
constexpr double OPPONENT_TRASH_SEPARATION_Y = OPPONENT_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_TRASH_JUSTIFICATION = OPPONENT_DECK_JUSTIFICATION;

// Constants for the opponent's hand button.
constexpr const char* OPPONENT_HAND_STRING = "Opponent's Hand";
constexpr double OPPONENT_HAND_X = 0.5;
constexpr double OPPONENT_HAND_Y = 1 - YOUR_HAND_Y;
constexpr double OPPONENT_HAND_WIDTH = OPPONENT_DECK_WIDTH;
constexpr double OPPONENT_HAND_HEIGHT = OPPONENT_DECK_HEIGHT;
constexpr double OPPONENT_HAND_MAX_WIDTH = OPPONENT_DECK_MAX_WIDTH;
constexpr double OPPONENT_HAND_SEPARATION_X = OPPONENT_DECK_SEPARATION_X;
constexpr double OPPONENT_HAND_SEPARATION_Y = OPPONENT_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_HAND_JUSTIFICATION = OPPONENT_DECK_JUSTIFICATION;

// Constants for the opponent's life cards button.
constexpr const char* OPPONENT_LIFE_STRING = "Opponent's\nLife\nCards";
constexpr double OPPONENT_LIFE_X = 1 - OPPONENT_DECK_X;
constexpr double OPPONENT_LIFE_Y = 1 - YOUR_LIFE_Y;
constexpr double OPPONENT_LIFE_WIDTH = OPPONENT_DECK_WIDTH;
constexpr double OPPONENT_LIFE_HEIGHT = OPPONENT_DECK_HEIGHT;
constexpr double OPPONENT_LIFE_MAX_WIDTH = OPPONENT_DECK_MAX_WIDTH;
constexpr double OPPONENT_LIFE_SEPARATION_X = OPPONENT_DECK_SEPARATION_X;
constexpr double OPPONENT_LIFE_SEPARATION_Y = OPPONENT_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_LIFE_JUSTIFICATION = OPPONENT_DECK_JUSTIFICATION;

// Constants for the opponent's active fighter button.
constexpr const char* OPPONENT_ACTIVE_STRING = "Opponent's\nActive Fighter";
constexpr double OPPONENT_ACTIVE_X = OPPONENT_HAND_X;
constexpr double OPPONENT_ACTIVE_Y = OPPONENT_DECK_Y;
constexpr double OPPONENT_ACTIVE_WIDTH = OPPONENT_DECK_WIDTH;
constexpr double OPPONENT_ACTIVE_HEIGHT = OPPONENT_DECK_HEIGHT;
constexpr double OPPONENT_ACTIVE_MAX_WIDTH = OPPONENT_DECK_MAX_WIDTH;
constexpr double OPPONENT_ACTIVE_SEPARATION_X = OPPONENT_DECK_SEPARATION_X;
constexpr double OPPONENT_ACTIVE_SEPARATION_Y = OPPONENT_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_ACTIVE_JUSTIFICATION = OPPONENT_DECK_JUSTIFICATION;

// Constants for the opponent's benched fighter button.
constexpr const char* OPPONENT_BENCH_STRING = "Opponent's\nBenched Fighters";
constexpr double OPPONENT_BENCH_X = OPPONENT_HAND_X;
constexpr double OPPONENT_BENCH_Y = OPPONENT_TRASH_Y;
constexpr double OPPONENT_BENCH_WIDTH = OPPONENT_DECK_WIDTH;
constexpr double OPPONENT_BENCH_HEIGHT = OPPONENT_DECK_HEIGHT;
constexpr double OPPONENT_BENCH_MAX_WIDTH = OPPONENT_DECK_MAX_WIDTH;
constexpr double OPPONENT_BENCH_SEPARATION_X = OPPONENT_DECK_SEPARATION_X;
constexpr double OPPONENT_BENCH_SEPARATION_Y = OPPONENT_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_BENCH_JUSTIFICATION = OPPONENT_DECK_JUSTIFICATION;

// Constants for the opponent's effects button.
constexpr const char* OPPONENT_EFFECTS_STRING = "Opponent's\nEffects";
constexpr double OPPONENT_EFFECTS_X = QUIT_X_ALT;
constexpr double OPPONENT_EFFECTS_Y = 1 - QUIT_Y;
constexpr double OPPONENT_EFFECTS_WIDTH = YOUR_DECK_WIDTH;
constexpr double OPPONENT_EFFECTS_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double OPPONENT_EFFECTS_MAX_WIDTH = YOUR_DECK_MAX_WIDTH;
constexpr double OPPONENT_EFFECTS_SEPARATION_X = YOUR_DECK_SEPARATION_X;
constexpr double OPPONENT_EFFECTS_SEPARATION_Y = YOUR_DECK_SEPARATION_Y;
constexpr Renderer::Justification OPPONENT_EFFECTS_JUSTIFICATION = YOUR_DECK_JUSTIFICATION;
//}

// Other buttons
//{
// Constants for the void button.
constexpr const char* THE_VOID_STRING = "The Void";
constexpr double THE_VOID_X = YOUR_LIFE_X;
constexpr double THE_VOID_Y = 0.5;
constexpr double THE_VOID_WIDTH = YOUR_DECK_WIDTH;
constexpr double THE_VOID_HEIGHT = YOUR_DECK_HEIGHT;
constexpr double THE_VOID_SEPARATION = YOUR_DECK_SEPARATION_X;

    
// Constants for the end turn button.
constexpr const char* END_TURN_STRING = DONE_STRING;
constexpr double END_TURN_X = DONE_X;
constexpr double END_TURN_Y = DONE_Y;
constexpr double END_TURN_WIDTH = DONE_WIDTH;
constexpr double END_TURN_HEIGHT = DONE_HEIGHT;
constexpr double END_TURN_SEPARATION = DONE_SEPARATION;

// Constants for the concede button.
constexpr const char* CONCEDE_STRING = QUIT_STRING;
constexpr double CONCEDE_X = END_TURN_X;
constexpr double CONCEDE_Y = 1 - QUIT_Y;
constexpr double CONCEDE_WIDTH = QUIT_WIDTH;
constexpr double CONCEDE_HEIGHT = QUIT_HEIGHT;
constexpr double CONCEDE_SEPARATION = QUIT_SEPARATION;
//}
//}

// Duel Constants
//{
// Constants for the last drawn card sprite.
#define LAST_DRAWN_STRING ("You drew\n" + last_drawn->get_name())
constexpr double LAST_DRAWN_X = 0.5;
constexpr double LAST_DRAWN_Y = 0.5;
constexpr double LAST_DRAWN_WIDTH = 0.75 * TITLE_WIDTH;
constexpr double LAST_DRAWN_HEIGHT = 2 * LAST_DRAWN_WIDTH;
constexpr double LAST_DRAWN_MAX_WIDTH = 0.75;
constexpr double LAST_DRAWN_SEPARATION_X = LAST_DRAWN_WIDTH / 20;
constexpr double LAST_DRAWN_SEPARATION_Y = LAST_DRAWN_HEIGHT / 2;
constexpr Renderer::Justification LAST_DRAWN_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// Constants for the player's concede sprite.
constexpr const char* PLAYER_CONCEDE_STRING = "You conceded...";
constexpr double PLAYER_CONCEDE_X = 0.5;
constexpr double PLAYER_CONCEDE_Y = 0.5;
constexpr double PLAYER_CONCEDE_WIDTH = 0.5 * TITLE_WIDTH;
constexpr double PLAYER_CONCEDE_HEIGHT = 2 * PLAYER_CONCEDE_WIDTH;
constexpr double PLAYER_CONCEDE_MAX_WIDTH = 0;
constexpr double PLAYER_CONCEDE_SEPARATION_X = PLAYER_CONCEDE_WIDTH / 20;
constexpr double PLAYER_CONCEDE_SEPARATION_Y = PLAYER_CONCEDE_HEIGHT / 2;
constexpr Renderer::Justification PLAYER_CONCEDE_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// Constants for the opponent's concede sprite.
constexpr const char* OPPONENT_CONCEDE_STRING = "Your opponent\nconceded!";
constexpr double OPPONENT_CONCEDE_X = 0.5;
constexpr double OPPONENT_CONCEDE_Y = 0.5;
constexpr double OPPONENT_CONCEDE_WIDTH = 0.5 * TITLE_WIDTH;
constexpr double OPPONENT_CONCEDE_HEIGHT = 2 * OPPONENT_CONCEDE_WIDTH;
constexpr double OPPONENT_CONCEDE_MAX_WIDTH = 0;
constexpr double OPPONENT_CONCEDE_SEPARATION_X = OPPONENT_CONCEDE_WIDTH / 20;
constexpr double OPPONENT_CONCEDE_SEPARATION_Y = OPPONENT_CONCEDE_HEIGHT / 2;
constexpr Renderer::Justification OPPONENT_CONCEDE_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// Constants for the opponent's concede sprite.
#define VIEW_SIZE_STRING (     \
    "Contains "                \
    + std::to_string(size())   \
    + " card"                  \
    + (size() == 1 ? "" : "s") \
    + "."                      \
)
constexpr double VIEW_SIZE_X = 0.5;
constexpr double VIEW_SIZE_Y = 0.5;
constexpr double VIEW_SIZE_WIDTH = 0.5 * TITLE_WIDTH;
constexpr double VIEW_SIZE_HEIGHT = 2 * VIEW_SIZE_WIDTH;
constexpr double VIEW_SIZE_MAX_WIDTH = 0;
constexpr double VIEW_SIZE_SEPARATION_X = VIEW_SIZE_WIDTH / 20;
constexpr double VIEW_SIZE_SEPARATION_Y = VIEW_SIZE_HEIGHT / 2;
constexpr Renderer::Justification VIEW_SIZE_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// Constants for the fighter's energy button.
constexpr const char* FIGHTER_ENERGY_STRING = "Energy";
constexpr double FIGHTER_ENERGY_X = 0.125;
constexpr double FIGHTER_ENERGY_Y = 0.35;
constexpr double FIGHTER_ENERGY_WIDTH = 0.02;
constexpr double FIGHTER_ENERGY_HEIGHT = 2 * FIGHTER_ENERGY_WIDTH;
constexpr double FIGHTER_ENERGY_SEPARATION = FIGHTER_ENERGY_WIDTH / 20;

// Constants for the fighter's effects button.
constexpr const char* FIGHTER_EFFECTS_STRING = "Effects";
constexpr double FIGHTER_EFFECTS_X = FIGHTER_ENERGY_X;
constexpr double FIGHTER_EFFECTS_Y = 1 - FIGHTER_ENERGY_Y;
constexpr double FIGHTER_EFFECTS_WIDTH = FIGHTER_ENERGY_WIDTH;
constexpr double FIGHTER_EFFECTS_HEIGHT = 2 * FIGHTER_EFFECTS_WIDTH;
constexpr double FIGHTER_EFFECTS_SEPARATION = FIGHTER_EFFECTS_WIDTH / 20;

// The constants for the energy size sprite.
#define ENERGY_SIZE_STRING ("Contains " + std::to_string(energy.size()) + " cards:")
constexpr double ENERGY_SIZE_X = BUILDER_X;
constexpr double ENERGY_SIZE_Y = BUILDER_Y;
constexpr double ENERGY_SIZE_WIDTH = 0.75 * BUILDER_WIDTH;
constexpr double ENERGY_SIZE_HEIGHT = 2 * ENERGY_SIZE_WIDTH;
constexpr double ENERGY_SIZE_SEPARATION = ENERGY_SIZE_WIDTH / 20;

// Constants for the opponent's concede sprite.
#define DRAW_FAIL_STRING (                           \
    std::string(turn ? "Your opponenent's" : "Your") \
    + " deck is empty, so "                          \
    + (turn ? "they" : "you")                        \
    + " can't draw at the start of "                 \
    + (turn ? "their" : "your")                      \
    + " turn"                                        \
    + (turn ? "!" : "...")                           \
)
constexpr double DRAW_FAIL_X = 0.5;
constexpr double DRAW_FAIL_Y = 0.5;
constexpr double DRAW_FAIL_WIDTH = 0.5 * TITLE_WIDTH;
constexpr double DRAW_FAIL_HEIGHT = 2 * DRAW_FAIL_WIDTH;
constexpr double DRAW_FAIL_MAX_WIDTH = 0.75;
constexpr double DRAW_FAIL_SEPARATION_X = DRAW_FAIL_WIDTH / 20;
constexpr double DRAW_FAIL_SEPARATION_Y = DRAW_FAIL_HEIGHT / 2;
constexpr Renderer::Justification DRAW_FAIL_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// The constants for the play card button.
constexpr const char* PLAY_CARD_STRING = "Play";
constexpr double PLAY_CARD_X = GENERATE_X;
constexpr double PLAY_CARD_Y = GENERATE_Y;
constexpr double PLAY_CARD_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double PLAY_CARD_WIDTH = GENERATE_WIDTH;
constexpr double PLAY_CARD_HEIGHT = GENERATE_HEIGHT;
constexpr double PLAY_CARD_SEPARATION = GENERATE_SEPARATION;

// The constants for the attachment sprite.
#define ATTACHMENT_STRING (                          \
    "Your opponent is choosing a fighter to attach " \
    + e.get_name()                                   \
    + " to."                                         \
)
constexpr double ATTACHMENT_X = 0.5;
constexpr double ATTACHMENT_Y = 0.5;
constexpr double ATTACHMENT_WIDTH = 0.5 * TITLE_WIDTH;
constexpr double ATTACHMENT_HEIGHT = 2 * ATTACHMENT_WIDTH;
constexpr double ATTACHMENT_MAX_WIDTH = 0.75;
constexpr double ATTACHMENT_SEPARATION_X = ATTACHMENT_WIDTH / 20;
constexpr double ATTACHMENT_SEPARATION_Y = ATTACHMENT_HEIGHT / 5;
constexpr Renderer::Justification ATTACHMENT_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// The constants for the attach button.
constexpr const char* ATTACH_STRING = "Attach";
constexpr double ATTACH_X = GENERATE_X;
constexpr double ATTACH_Y = GENERATE_Y;
constexpr double ATTACH_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double ATTACH_WIDTH = GENERATE_WIDTH;
constexpr double ATTACH_HEIGHT = GENERATE_HEIGHT;
constexpr double ATTACH_SEPARATION = GENERATE_SEPARATION;

// The constants for the energy value sprites.
#define ENERGY_VALUE_STRING std::to_string(energy_value(page * PAGE_COUNT + i))
constexpr double ENERGY_VALUE_X = GENERATE_X;
constexpr double ENERGY_VALUE_Y = GENERATE_Y;
constexpr double ENERGY_VALUE_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double ENERGY_VALUE_WIDTH = GENERATE_WIDTH;
constexpr double ENERGY_VALUE_HEIGHT = GENERATE_HEIGHT;
constexpr double ENERGY_VALUE_SEPARATION = GENERATE_SEPARATION;

// The constants for the total energy value sprite.
#define TOTAL_ENERGY_STRING ( \
    "Total Energy: "          \
    + std::to_string(total)   \
)
constexpr double TOTAL_ENERGY_X = 0.5;
constexpr double TOTAL_ENERGY_Y = 0.9;
constexpr double TOTAL_ENERGY_WIDTH = GENERATE_WIDTH;
constexpr double TOTAL_ENERGY_HEIGHT = GENERATE_HEIGHT;
constexpr double TOTAL_ENERGY_SEPARATION = GENERATE_SEPARATION;

// The constants for the rank up sprite.
#define RANK_UP_STRING (                                   \
    "Your opponent is choosing a fighter to rank up into " \
    + f.get_name()                                         \
    + "."                                                  \
)
constexpr double RANK_UP_X = 0.5;
constexpr double RANK_UP_Y = 0.5;
constexpr double RANK_UP_WIDTH = 0.5 * TITLE_WIDTH;
constexpr double RANK_UP_HEIGHT = 2 * RANK_UP_WIDTH;
constexpr double RANK_UP_MAX_WIDTH = 0.75;
constexpr double RANK_UP_SEPARATION_X = RANK_UP_WIDTH / 20;
constexpr double RANK_UP_SEPARATION_Y = RANK_UP_HEIGHT / 5;
constexpr Renderer::Justification RANK_UP_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;

// The constants for the attachment preview button.
#define ATTACH_PREVIEW_STRING e.get_name()
constexpr double ATTACH_PREVIEW_X = 0.5;
constexpr double ATTACH_PREVIEW_Y = 0.1;
constexpr double ATTACH_PREVIEW_WIDTH = GENERATE_WIDTH;
constexpr double ATTACH_PREVIEW_HEIGHT = GENERATE_HEIGHT;
constexpr double ATTACH_PREVIEW_SEPARATION = GENERATE_SEPARATION;

// The constants for the rank up buttons.
constexpr const char* RANK_STRING = "Rank up";
constexpr double RANK_X = GENERATE_X;
constexpr double RANK_Y = GENERATE_Y;
constexpr double RANK_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double RANK_WIDTH = GENERATE_WIDTH;
constexpr double RANK_HEIGHT = GENERATE_HEIGHT;
constexpr double RANK_SEPARATION = GENERATE_SEPARATION;

// The constants for the rank up preview button.
#define RANK_PREVIEW_STRING f.get_name()
constexpr double RANK_PREVIEW_X = 0.5;
constexpr double RANK_PREVIEW_Y = 0.1;
constexpr double RANK_PREVIEW_WIDTH = GENERATE_WIDTH;
constexpr double RANK_PREVIEW_HEIGHT = GENERATE_HEIGHT;
constexpr double RANK_PREVIEW_SEPARATION = GENERATE_SEPARATION;

// The constants for the effects value sprites.
#define EFFECT_VALUE_STRING effect_values[page * PAGE_COUNT + i]
constexpr double EFFECT_VALUE_X = GENERATE_X;
constexpr double EFFECT_VALUE_Y = GENERATE_Y;
constexpr double EFFECT_VALUE_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double EFFECT_VALUE_WIDTH = GENERATE_WIDTH;
constexpr double EFFECT_VALUE_HEIGHT = GENERATE_HEIGHT;
constexpr double EFFECT_VALUE_SEPARATION = GENERATE_SEPARATION;

// The constants for the bench size sprite.
#define BENCH_SIZE_STRING (             \
    std::to_string(fighters.size() - 1) \
    + " benched fighters:"              \
)
constexpr double BENCH_SIZE_X = 0.5;
constexpr double BENCH_SIZE_Y = 0.1;
constexpr double BENCH_SIZE_WIDTH = GENERATE_WIDTH;
constexpr double BENCH_SIZE_HEIGHT = GENERATE_HEIGHT;
constexpr double BENCH_SIZE_SEPARATION = GENERATE_SEPARATION;

// The constants for the ability button.
constexpr const char* ABILITY_STRING = "Ability";
constexpr double ABILITY_X = GENERATE_X;
constexpr double ABILITY_Y = GENERATE_Y;
constexpr double ABILITY_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double ABILITY_WIDTH = GENERATE_WIDTH;
constexpr double ABILITY_HEIGHT = GENERATE_HEIGHT;
constexpr double ABILITY_SEPARATION = GENERATE_SEPARATION;

// Constants for the fighter's ability button.
constexpr const char* FIGHTER_ABILITY_STRING = "Ability";
constexpr double FIGHTER_ABILITY_X = 1 - FIGHTER_ENERGY_X;
constexpr double FIGHTER_ABILITY_Y = 0.25;
constexpr double FIGHTER_ABILITY_WIDTH = 0.02;
constexpr double FIGHTER_ABILITY_HEIGHT = 2 * FIGHTER_ABILITY_WIDTH;
constexpr double FIGHTER_ABILITY_SEPARATION = FIGHTER_ABILITY_WIDTH / 20;

// Constants for the fighter's attack button.
constexpr const char* FIGHTER_ATTACK_STRING = "Attack";
constexpr double FIGHTER_ATTACK_X = FIGHTER_ABILITY_X;
constexpr double FIGHTER_ATTACK_Y = 0.5;
constexpr double FIGHTER_ATTACK_WIDTH = 0.02;
constexpr double FIGHTER_ATTACK_HEIGHT = 2 * FIGHTER_ATTACK_WIDTH;
constexpr double FIGHTER_ATTACK_SEPARATION = FIGHTER_ATTACK_WIDTH / 20;

// Constants for the fighter's retreat button.
constexpr const char* FIGHTER_RETREAT_STRING = "Retreat";
constexpr double FIGHTER_RETREAT_X = FIGHTER_ATTACK_X;
constexpr double FIGHTER_RETREAT_Y = 0.75;
constexpr double FIGHTER_RETREAT_WIDTH = 0.02;
constexpr double FIGHTER_RETREAT_HEIGHT = 2 * FIGHTER_RETREAT_WIDTH;
constexpr double FIGHTER_RETREAT_SEPARATION = FIGHTER_RETREAT_WIDTH / 20;

// Constants for the retreat preview button.
#define RETREAT_PREVIEW_STRING fighters[0].get_name()
constexpr double RETREAT_PREVIEW_X = 0.5;
constexpr double RETREAT_PREVIEW_Y = 0.1;
constexpr double RETREAT_PREVIEW_WIDTH = GENERATE_WIDTH;
constexpr double RETREAT_PREVIEW_HEIGHT = GENERATE_HEIGHT;
constexpr double RETREAT_PREVIEW_SEPARATION = GENERATE_SEPARATION;

// The constants for the switch in buttons.
constexpr const char* SWITCH_IN_STRING = "Switch In";
constexpr double SWITCH_IN_X = GENERATE_X;
constexpr double SWITCH_IN_Y = GENERATE_Y;
constexpr double SWITCH_IN_Y_SHIFT = GENERATE_Y_SHIFT;
constexpr double SWITCH_IN_WIDTH = GENERATE_WIDTH;
constexpr double SWITCH_IN_HEIGHT = GENERATE_HEIGHT;
constexpr double SWITCH_IN_SEPARATION = GENERATE_SEPARATION;
//}

// Announcement Constants
//{
// Universal announcement constants.
//{
#define ANNOUNCEMENT_STRING announcement
constexpr double ANNOUNCEMENT_X = 0.5;
constexpr double ANNOUNCEMENT_Y = 0.5;
constexpr double ANNOUNCEMENT_WIDTH = 0.3125 * TITLE_WIDTH;
constexpr double ANNOUNCEMENT_HEIGHT = 2 * ANNOUNCEMENT_WIDTH;
constexpr double ANNOUNCEMENT_MAX_WIDTH = 0.75;
constexpr double ANNOUNCEMENT_SEPARATION_X = ANNOUNCEMENT_WIDTH / 20;
constexpr double ANNOUNCEMENT_SEPARATION_Y = ANNOUNCEMENT_HEIGHT / 5;
constexpr Renderer::Justification ANNOUNCEMENT_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;
//}

// Announcement for playing a basic fighter.
//{
#define BENCHED_ANNOUNCEMENT (                      \
    std::string(opposing ? "Your opponent" : "You") \
    + " played "                                    \
    + f.get_name()                                  \
    + " onto the bench!"                            \
)
//}

// Announcement to display the total number of cards drawn.
//{
#define DRAW_ANNOUNCEMENT (                         \
    std::string(opposing ? "Your opponent" : "You") \
    + " drew "                                      \
    + std::to_string(draws)                         \
    + " card"                                       \
    + (draws == 1 ? "" : "s")                       \
    + "."                                           \
)
//}

// Announcement to display the drawn card.
//{
#define LAST_DRAWN_ANNOUNCEMENT ( \
    "You drew "                   \
    + last_drawn->get_name()      \
    + "."                         \
)
//}

// Announcement to display the total number of cards drawn by the opponent.
//{
#define DRAW_OPPONENT_ANNOUNCEMENT (                 \
    std::string(!opposing ? "Your opponent" : "You") \
    + " drew "                                       \
    + std::to_string(draws)                          \
    + " card"                                        \
    + (draws == 1 ? "" : "s")                        \
    + "."                                            \
)
//}

// Announcement to display the drawn card of the opponent.
//{
#define LAST_DRAWN_OPPONENT_ANNOUNCEMENT ( \
    "You drew "                            \
    + opponent->last_drawn->get_name()     \
    + "."                                  \
)
//}

// Announcement for the played supporter card.
//{
#define SUPPORTER_ANNOUNCEMENT (                    \
    std::string(opposing ? "Your opponent" : "You") \
    + " played "                                    \
    + s.get_name()                                  \
    + "!"                                           \
)
//}

// Announcement for the played energy card.
//{
#define ENERGY_ANNOUNCEMENT (                    \
    std::string(opposing ? "Your opponent" : "You") \
    + " played "                                    \
    + e.get_name()                                  \
    + "!"                                           \
)
//}

// Announcement for a discarded hand.
//{
#define DISCARD_ALL_ANNOUNCEMENT (                    \
    std::string(opposing ? "Your opponent" : "You")   \
    + " discarded "                                   \
    + (                                               \
        discards == 1 ? hand[0].get_name() + " from " \
        : "all "                                      \
        + std::to_string(discards)                    \
        + " of the cards in "                         \
    )                                                 \
    + (opposing ? "their" : "your")                   \
    + " hand!"                                        \
)
//}

// Announcement for all energy in hand being discarded.
//{
#define DISCARD_ENERGY_ALL_ANNOUNCEMENT (                          \
    std::string(opposing ? "Your opponent" : "You")                \
    + " discarded "                                                \
    + (                                                            \
        discards == 1 ? hand.get_energy()[0].get_name() + " from " \
        : "all "                                                   \
        + std::to_string(discards)                                 \
        + " of the energy cards in "                               \
    )                                                              \
    + (opposing ? "their" : "your")                                \
    + " hand!"                                                     \
)
//}

// Announcement for an attached energy card.
//{
#define ATTACHMENT_ANNOUNCEMENT (                   \
    std::string(opposing ? "Your opponent" : "You") \
    + " attached "                                  \
    + e.get_name()                                  \
    + " to "                                        \
    + recipient->get_name()                         \
    + "."                                           \
)
//}

// Announcement for a failed rank up attempt.
//{
#define UNRANKABLE_ANNOUNCEMENT (             \
    "None of your fighters can rank up into " \
    + f.get_name()                            \
    + "..."                                   \
)
//}

// Announcement for a successful rank up.
//{
#define RANK_UP_ANNOUNCEMENT (                      \
    std::string(opposing ? "Your opponent" : "You") \
    + " ranked up "                                 \
    + fighters[index].get_name()                    \
    + " into "                                      \
    + new_rank.get_name()                           \
    + "!"                                           \
)
//}

// Announcement for an ability use.
//{
#define ABILITY_ANNOUNCEMENT (                           \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + " used "                                           \
    + fighters[index].get_ability_name()                 \
    + "."                                                \
)
//}

// Announcement for a fighter switch in.
//{
#define SWITCH_IN_ANNOUNCEMENT (                           \
    std::string(opposing ? "Your opponent's " : "Your ")   \
    + fighters[0].get_name()                               \
    + " switched into the active position!\n\n"               \
    + std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                           \
    + " switched out to the bench."                        \
)
//}

// Announcement to declare fighter empowerment.
//{
#define POWER_ANNOUNCEMENT (                             \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + "'s attacks deal "                                 \
    + std::to_string(abs(std::stoi(power)))              \
    + (std::stoi(power) < 0 ? " less" : " more")         \
    + " damage this turn!"                               \
)
//}

// Announcement to declare player empowerment.
//{
#define PLAYER_POWER_ANNOUNCEMENT (                    \
    std::string(opposing ? "Your opponent's" : "Your") \
    + " fighters' attacks deal "                       \
    + std::to_string(abs(std::stoi(power)))            \
    + (std::stoi(power) < 0 ? " less" : " more")       \
    + " damage this turn!"                             \
)
//}

// Announcement to declare permanent player empowerment.
//{
#define POWER_AURA_ANNOUNCEMENT (                \
    "Attacks deal "                              \
    + std::to_string(abs(std::stoi(power)))      \
    + (std::stoi(power) < 0 ? " less" : " more") \
    + " damage for the rest of the duel!"        \
)
//}

// Announcement to declare opponent empowerment.
//{
#define OPPONENT_POWER_ANNOUNCEMENT (                   \
    std::string(!opposing ? "Your opponent's" : "Your") \
    + " fighters' attacks deal "                        \
    + std::to_string(abs(std::stoi(power)))             \
    + (std::stoi(power) < 0 ? " less" : " more")        \
    + " damage next turn!"                              \
)
//}

// Announcement for a fighter retreat.
//{
#define RETREAT_ANNOUNCEMENT (                           \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[0].get_name()                             \
    + " retreated."                                      \
)
//}

// Announcement for an attack.
//{
#define ATTACK_ANNOUNCEMENT (                            \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[0].get_name()                             \
    + " used "                                           \
    + attack.get_name()                                  \
    + "!"                                                \
)
//}

// Announcement for damage being dealt to the opponent's active fighter.
//{
#define DAMAGE_ANNOUNCEMENT (                             \
    std::string(!opposing ? "Your opponent's " : "Your ") \
    + opponent->fighters[0].get_name()                    \
    + " took "                                            \
    + std::to_string(damage)                              \
    + " damage!"                                          \
)
//}

// Announcement for a fighter defeat.
//{
#define DEFEAT_ANNOUNCEMENT (                            \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[i].get_name()                             \
    + " was defeated!"                                   \
)
//}

// Announcement for the player having all of their fighters defeated.
//{
#define NO_FIGHTERS_ANNOUNCEMENT (                             \
    opposing ? "You defeated all of your opponent's fighters!" \
    : "All of your fighters were defeated..."                  \
)
//}

// Announcement for the player drawing all of their life cards.
//{
#define NO_LIFE_ANNOUNCEMENT (                               \
    std::string(opposing ? "Your opponent has" : "You have") \
    + " no more life cards"                                  \
    + (opposing ? "!" : "...")                               \
)
//}

// Announceent for the opponent seeing how many life cards that the player will draw.
//{
#define LIFE_DRAW_ANNOUNCEMENT (   \
    "Your opponent is choosing "   \
    + std::to_string(life_draws)   \
    + " life card"                 \
    + (life_draws == 1 ? "" : "s") \
    + " to draw."                  \
)
//}

// Announcement for the player to draw a life card.
//{
constexpr const char* DRAW_LIFE_ANNOUNCEMENT = "Choose a life card to draw.";
//}

// Announcement for the player to choose a new active fighter.
//{
#define NEW_ACTIVE_ANNOUNCEMENT (                                \
    opposing ? "Your opponent is choosing a new active fighter." \
    : "Choose a new active fighter from your bench."             \
)
//}

// Announcement for the new active fighter.
//{
#define REPLACEMENT_ANNOUNCEMENT (                  \
    std::string(opposing ? "Your opponent" : "You") \
    + " chose "                                     \
    + fighters[0].get_name()                        \
    + " to be the new active fighter!"              \
)
//}

// Announcement for a hand shuffled into the deck.
//{
#define SHUFFLE_ALL_ANNOUNCEMENT (                    \
    std::string(opposing ? "Your opponent" : "You")   \
    + " shuffled "                                    \
    + (                                               \
        shuffles == 1 ? "a card from " \
        : "all "                                      \
        + std::to_string(shuffles)                    \
        + " of the cards in "                         \
    )                                                 \
    + (opposing ? "their" : "your")                   \
    + " hand into "                                   \
    + (opposing ? "their" : "your")                   \
    + " deck!"                                        \
)
//}

// Announcement for an opposing hand shuffled into the deck.
//{
#define SHUFFLE_OPPONENT_ALL_ANNOUNCEMENT (                    \
    std::string(!opposing ? "Your opponent" : "You")  \
    + " shuffled "                                    \
    + (                                               \
        shuffles == 1 ? opponent->hand[0].get_name() + " from " \
        : "all "                                      \
        + std::to_string(shuffles)                    \
        + " of the cards in "                         \
    )                                                 \
    + (!opposing ? "their" : "your")                  \
    + " hand into "                                   \
    + (!opposing ? "their" : "your")                  \
    + " deck!"                                        \
)
//}

// Announcement for drawing cards at the end of the turn.
//{
#define END_DRAW_ANNOUNCEMENT (                     \
    std::string(opposing ? "Your opponent" : "You") \
    + " will draw "                                 \
    + effects[i][1]                                 \
    + " card"                                       \
    + (std::stoi(effects[i][1]) == 1 ? "" : "s")    \
    + " at the start of "                           \
    + (opposing ? "their" : "your")                 \
    + " next turn."                                 \
)
//}

// Announcement to declare that a card must be shuffled into the deck from the hand.
//{
#define TO_SHUFFLE_ANNOUNCEMENT (                                                           \
    opposing ? "Your opponent is choosing a card in their hand to shuffle into their deck." \
    : "Choose a card from your hand to shuffle into your deck."                             \
)
//}

// Announcement to declare that a card must be shuffled into the deck from the trash.
//{
#define TO_SHUFFLE_TRASH_ANNOUNCEMENT (                                                            \
    opposing ? "Your opponent is choosing a card in their trash to shuffle into their deck." \
    : "Choose a card from your trash to shuffle into your deck."                             \
)
//}

// Announcement to declare the name of the card shuffled from the trash into the deck.
//{
#define SHUFFLE_TRASH_PEEK_ANNOUNCEMENT (           \
    std::string(opposing ? "Your opponent" : "You") \
    + " shuffled "                                  \
    + trash[index].get_name()                       \
    + " into "                                      \
    + (opposing ? "their" : "your")                 \
    + "deck."                                       \
)
//}

// Announcement to announce the number of cards shuffled.
//{
#define SHUFFLE_ANNOUNCEMENT (                      \
    std::string(opposing ? "Your opponent" : "You") \
    + " shuffled "                                  \
    + std::to_string(shuffles)                      \
    + " card"                                       \
    + (shuffles == 1 ? "" : "s")                    \
    + " into "                                      \
    + (opposing ? "their" : "your")                 \
    + " deck."                                      \
)
//}

// Announcement to announce the number of energy cards shuffled in.
//{
#define SHUFFLE_TRASH_ENERGY_ANNOUNCEMENT (                         \
    std::string(opposing ? "Your opponent" : "You")                 \
    + " shuffled "                                                  \
    + (                                                             \
        shuffles == 1 ? trash.get_energy()[0].get_name() + " from " \
        : "all "                                                    \
        + std::to_string(shuffles)                                  \
        + " of the energy cards in "                                \
    )                                                               \
    + (opposing ? "their" : "your")                                 \
    + " trash into "                                                \
    + (opposing ? "their" : "your")                                 \
    + " deck!"                                                      \
)
//}

// Announcement to announce the last coin flip.
//{
#define FLIP_ANNOUNCEMENT (                         \
    std::string(opposing ? "Your opponent" : "You") \
    + " flipped "                                   \
    + (result == HEADS ? "heads" : "tails")         \
    + "."                                           \
)
//}

// Announcement to announce the flip counts.
//{
#define FLIP_COUNT_ANNOUNCEMENT (        \
    "Heads: "                            \
    + std::to_string(flip_counts[HEADS]) \
    + "\nTails: "                        \
    + std::to_string(flip_counts[TAILS]) \
)
//}

// Announcement to declare that a card must be discarded.
//{
#define TO_DISCARD_ANNOUNCEMENT (                             \
    opposing ? "Your opponent is choosing a card to discard." \
    : "Choose a card to discard from your hand."              \
)
//}

// Announcement to declare that a card must be banished.
//{
#define TO_BANISH_ANNOUNCEMENT (                             \
    opposing ? "Your opponent is choosing a card to banish." \
    : "Choose a card to banish from your hand."              \
)
//}

// Announcement to announce the number of cards discarded.
//{
#define DISCARD_ANNOUNCEMENT (                      \
    std::string(opposing ? "Your opponent" : "You") \
    + " discarded "                                 \
    + std::to_string(discards)                      \
    + " card"                                       \
    + (discards == 1 ? "" : "s")                    \
    + "."                                           \
)
//}

// Announcement to announce the number of cards banished.
//{
#define BANISH_ANNOUNCEMENT (                       \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                  \
    + std::to_string(banishes)                      \
    + " card"                                       \
    + (banishes == 1 ? "" : "s")                    \
    + "."                                           \
)
//}

// Announcement to declare the name of the card discarded.
//{
#define DISCARD_PEEK_ANNOUNCEMENT (                 \
    std::string(opposing ? "Your opponent" : "You") \
    + " discarded "                                 \
    + hand[index].get_name()                        \
    + "."                                           \
)
//}

// Announcement to declare the name of the card banished.
//{
#define BANISH_PEEK_ANNOUNCEMENT (                 \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                 \
    + hand[index].get_name()                        \
    + "."                                           \
)
//}

// Announcement to declare that a card will be searched for in the deck.
//{
#define TO_SEARCH_ANNOUNCEMENT (                                           \
    opposing ? "Your opponent is searching their deck for a card to draw." \
    : "Choose a card to draw from your deck."                              \
)
//}

// Announcement to announce the number of cards drawn from a search.
//{
#define SEARCH_ANNOUNCEMENT (                       \
    std::string(opposing ? "Your opponent" : "You") \
    + " drew "                                      \
    + std::to_string(searches)                      \
    + " card"                                       \
    + (searches == 1 ? "" : "s")                    \
    + "."                                           \
)
//}

// Announcement to declare that a fighter will be sniped.
//{
#define TO_SNIPE_ANNOUNCEMENT (                                 \
    opposing ? "Your opponent is choosing a fighter to damage." \
    : "Choose a fighter to damage."                             \
)
//}

// Announcement for a fighter being damage from a snipe.
//{
#define SNIPE_ANNOUNCEMENT (                  \
    (opposing ? "Your " : "Your opponent's ") \
    + opponent->fighters[index].get_name()    \
    + " took "                                \
    + std::to_string(snipe)                   \
    + " damage!"                              \
)
//}

// Announcement that displays the last milled card.
//{
#define MILL_PEEK_ANNOUNCEMENT (                     \
    std::string(!opposing ? "Your opponent" : "You") \
    + " discarded "                                  \
    + last_drawn->get_name()                         \
    + "."                                            \
)
//}

// Announcement that displays the last milled card.
//{
#define MILL_SELF_PEEK_ANNOUNCEMENT (               \
    std::string(opposing ? "Your opponent" : "You") \
    + " discarded "                                 \
    + last_drawn->get_name()                        \
    + "."                                           \
)
//}

// Announcement to show the total number of cards self-milled.
//{
#define MILL_SELF_ANNOUNCEMENT (                    \
    std::string(opposing ? "Your opponent" : "You") \
    + " discarded "                                 \
    + std::to_string(mills)                         \
    + " card"                                       \
    + (mills == 1 ? "" : "s")                       \
    + " from "                                      \
    + (opposing ? "their" : "your")                 \
    + " deck."                                      \
)
//}

// Announcement to show the total number of cards milled.
//{
#define MILL_ANNOUNCEMENT (                          \
    std::string(!opposing ? "Your opponent" : "You") \
    + " discarded "                                  \
    + std::to_string(mills)                          \
    + " card"                                        \
    + (mills == 1 ? "" : "s")                        \
    + " from "                                       \
    + (!opposing ? "their" : "your")                 \
    + " deck."                                       \
)
//}

// Announcement that displays the last banish-milled card.
//{
#define MILL_BANISH_PEEK_ANNOUNCEMENT (              \
    std::string(!opposing ? "Your opponent" : "You") \
    + " banished "                                   \
    + last_drawn->get_name()                         \
    + "."                                            \
)
//}

// Announcement that displays the last self-banish-milled card.
//{
#define MILL_SELF_BANISH_PEEK_ANNOUNCEMENT (        \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                  \
    + last_drawn->get_name()                        \
    + "."                                           \
)
//}

// Announcement to show the total number of cards self-banish-milled.
//{
#define MILL_SELF_BANISH_ANNOUNCEMENT (             \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                  \
    + std::to_string(mills)                         \
    + " card"                                       \
    + (mills == 1 ? "" : "s")                       \
    + " from "                                      \
    + (opposing ? "their" : "your")                 \
    + " deck."                                      \
)
//}

// Announcement to show the total number of cards banish-milled.
//{
#define MILL_BANISH_ANNOUNCEMENT (                   \
    std::string(!opposing ? "Your opponent" : "You") \
    + " banished "                                   \
    + std::to_string(mills)                          \
    + " card"                                        \
    + (mills == 1 ? "" : "s")                        \
    + " from "                                       \
    + (!opposing ? "their" : "your")                 \
    + " deck."                                       \
)
//}

// Announcement to announce that the player is to choose a fighter to heal.
//{
#define TO_HEAL_ANNOUNCEMENT (                         \
    opposing ?                                         \
        "Your opponent is choosing a fighter to heal " \
        + std::to_string(healing)                      \
        + " damage from."                              \
    :                                                  \
        "Choose a fighter to heal "                    \
        + std::to_string(healing)                      \
        + " damage from."                              \
)
//}

// Announcement to display the health restored to a fighter.
//{
#define HEAL_ANNOUNCEMENT (                    \
    (!opposing ? "Your " : "Your opponent's ") \
    + fighters[index].get_name()               \
    + " was healed "                           \
    + std::to_string(healing)                  \
    + " damage!"                               \
)
//}

// Announcement to announce a change to a fighter's retreat cost.
//{
#define AGILITY_ANNOUNCEMENT (                             \
    std::string(!opposing ? "Your opponent's " : "Your ")  \
    + opponent->fighters[0].get_name()                     \
    + "'s retreat cost was "                               \
    + (std::stoi(agility) < 0 ? "increased" : "decreased") \
    + " by "                                               \
    + std::to_string(abs(std::stoi(agility)))              \
    + "!"                                                  \
)
//}

// Announcement to declare that the player will search the deck for a card to discard.
//{
#define SEARCH_DISCARD_ANNOUNCEMENT (                                         \
    opposing ? "Your opponent is choosing a card to discard from their deck." \
    : "Choose a card to discard from your deck."                              \
)
//}

// Announcement to show the card that was discarded.
//{
#define SEARCH_DISCARD_PEEK_ANNOUNCEMENT (          \
    std::string(opposing ? "Your opponent" : "You") \
    + " discarded "                                 \
    + deck[index].get_name()                        \
    + "."                                           \
)
//}

// Announcement to declare that the player will search the deck for a card to banish.
//{
#define SEARCH_BANISH_ANNOUNCEMENT (                                         \
    opposing ? "Your opponent is choosing a card to banish from their deck." \
    : "Choose a card to banish from your deck."                              \
)
//}

// Announcement to show the card that was banished.
//{
#define SEARCH_BANISH_PEEK_ANNOUNCEMENT (           \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                  \
    + deck[index].get_name()                        \
    + "."                                           \
)
//}

// Announcement to announce the number of cards banished.
//{
#define BANISH_ANNOUNCEMENT (                       \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                  \
    + std::to_string(banishes)                      \
    + " card"                                       \
    + (banishes == 1 ? "" : "s")                    \
    + "."                                           \
)
//}

// Announcement to declare that a card will be searched for in the trash.
//{
#define SEARCH_TRASH_ANNOUNCEMENT (                                         \
    opposing ? "Your opponent is searching their trash for a card to draw." \
    : "Choose a card to draw from your trash."                              \
)
//}

// Announcement to declare that a card will be searched for in the opponent's trash.
//{
#define SEARCH_OPPONENT_TRASH_ANNOUNCEMENT (                               \
    opposing ? "Your opponent is searching your trash for a card to draw." \
    : "Choose a card to draw from your opponent's trash."                  \
)
//}

// Announcement to declare that a card will be searched for in the opponent's hand.
//{
#define SEARCH_OPPONENT_HAND_ANNOUNCEMENT (                               \
    opposing ? "Your opponent is searching your hand for a card to draw a copy of." \
    : "Choose a card to draw a copy of from your opponent's hand."                  \
)
//}

// Announcement to show the card that was drawn from the trash.
//{
#define SEARCH_TRASH_PEEK_ANNOUNCEMENT (            \
    std::string(opposing ? "Your opponent" : "You") \
    + " drew "                                      \
    + trash[index].get_name()                       \
    + "."                                           \
)
//}

// Announcement to show the card that was drawn from the opponent's trash.
//{
#define SEARCH_OPPONENT_TRASH_PEEK_ANNOUNCEMENT (   \
    std::string(opposing ? "Your opponent" : "You") \
    + " drew "                                      \
    + opponent->trash[index].get_name()             \
    + "."                                           \
)
//}

// Announcement to show the card that was drawn from the opponent's trash.
//{
#define SEARCH_OPPONENT_HAND_PEEK_ANNOUNCEMENT (    \
    std::string(opposing ? "Your opponent" : "You") \
    + " drew "                                      \
    + opponent->hand[index].get_name()              \
    + "."                                           \
)
//}

// Announcement to declare that an energy card will be searched for in the deck.
//{
#define SEARCH_ENERGY_ANNOUNCEMENT (                                               \
    opposing ? "Your opponent is searching their deck for an energy card to draw." \
    : "Choose an energy card to draw from your deck."                              \
)
//}

// Announcement to declare that an energy card will be searched for in the trash.
//{
#define SEARCH_TRASH_ENERGY_ANNOUNCEMENT (                                          \
    opposing ? "Your opponent is searching their trash for an energy card to draw." \
    : "Choose an energy card to draw from your trash."                              \
)
//}

// Announcement to declare that a card of the same type
//   as last_drawn will be searched for in the deck.
//{
#define SEARCH_SAME_TYPE_ANNOUNCEMENT (                                \
    opposing ?                                                         \
        "Your opponent is searching their deck for "                   \
        + std::string(                                                 \
            last_drawn->get_type() == FIGHTER_TYPE ? "a fighter"       \
            : last_drawn->get_type() == SUPPORTER_TYPE ? "a supporter" \
            : "an energy"                                              \
        )                                                              \
        + " card to draw."                                             \
    :                                                                  \
        "Choose "                                                      \
        + std::string(                                                 \
            last_drawn->get_type() == FIGHTER_TYPE ? "a fighter"       \
            : last_drawn->get_type() == SUPPORTER_TYPE ? "a supporter" \
            : "an energy"                                              \
        )                                                              \
        + " card to draw from your deck."                                \
)
//}

// Announcement to declare that a fighter is to be switched in.
//{
#define TO_SWITCH_ANNOUNCEMENT (                                                        \
    opposing ? "Your opponent is choosing one of their benched fighters to switch in." \
    : "Choose one of your benched fighters to switch in."                              \
)
//}

// Announcement to declare that an opposing fighter is to be switched in.
//{
#define TO_HOOK_ANNOUNCEMENT (                                                        \
    opposing ? "Your opponent is choosing one of your benched fighters to switch in." \
    : "Choose one of your opponent's benched fighters to switch in."                  \
)
//}

// Announcement for an opposing fighter switch in.
//{
#define HOOK_ANNOUNCEMENT (                                 \
    std::string(!opposing ? "Your opponent's " : "Your ")   \
    + opponent->fighters[0].get_name()                      \
    + " switched into the active position!\n\n"                \
    + std::string(!opposing ? "Your opponent's " : "Your ") \
    + opponent->fighters[index].get_name()                  \
    + " switched out to the bench."                         \
)
//}

// Announcement for a supporter card recycle.
//{
#define RECYCLE_ANNOUNCEMENT (                      \
    std::string(opposing ? "Your opponent" : "You") \
    + " shuffled "                                  \
    + s.get_name()                                  \
    + " into "                                      \
    + std::string(opposing ? "their" : "your")      \
    + " deck!"                                      \
)
//}

// Announcement for a supporter card life card recycle.
//{
#define RECYCLE_LIFE_ANNOUNCEMENT (                 \
    std::string(opposing ? "Your opponent" : "You") \
    + " stored "                                    \
    + s.get_name()                                  \
    + " with "                                      \
    + std::string(opposing ? "their" : "your")      \
    + " life cards!"                                \
)
//}

// Announcement for a supporter card hand recycle.
//{
#define RECYCLE_HAND_ANNOUNCEMENT (                 \
    std::string(opposing ? "Your opponent" : "You") \
    + " returned "                                  \
    + s.get_name()                                  \
    + " to "                                        \
    + std::string(opposing ? "their" : "your")      \
    + " hand!"                                      \
)
//}

// Announcement to announce that a fighter is to be chosen for draining.
//{
#define TO_DRAIN_ANNOUNCEMENT (                                              \
    opposing ? "Your opponent is choosing a fighter to discard energy from." \
    : "Choose a fighter to discard energy from."                             \
)
//}

// Announcement to announce that a fighter's energy is to be chosen for draining.
//{
#define DRAIN_ENERGY_ANNOUNCEMENT (                                 \
    opposing ?                                                      \
        "Your opponent is choosing an energy card to discard from " \
        + opponent->fighters[index].get_name()                      \
        + "."                                                       \
    :                                                               \
        "Choose an energy card to discard from "                    \
        + opponent->fighters[index].get_name()                      \
        + "."                                                       \
)
//}

// Announcement to announce a successful drain.
//{
#define DRAIN_ANNOUNCEMENT (                                          \
    std::string(!opposing ? "Your opponent's " : "Your ")             \
    + opponent->fighters[index].get_name()                            \
    + " discarded its "                                               \
    + opponent->fighters[index].get_energy()[energy_index].get_name() \
    + "."                                                             \
)
//}

// Announcement to announce a full drain on a friendly fighter.
//{
#define DRAIN_SELF_UNIVERSAL_ANNOUNCEMENT (              \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + " had all of its energy discarded!"                \
)
//}

// Announcement for an effect clearance on a fighter.
//{
#define CLEAR_ANNOUNCEMENT (                             \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + "'s effects were cleared!"                         \
)
//}

// Announcement for a full heal for a fighter.
//{
#define FULL_HEAL_ANNOUNCEMENT (                         \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + " was fully healed!"                               \
)
//}

// Announcement for a friendly heal disttribution.
//{
#define HEAL_DISTRIBUTION_SELF_ANNOUNCEMENT (  \
    (!opposing ? "Your " : "Your opponent's ") \
    + fighters[i].get_name()                   \
    + " was healed "                           \
    + std::to_string(healing[i])               \
    + " damage!"                               \
)
//}

// Announcement for an opposing heal distribution.
//{
#define HEAL_DISTRIBUTION_OPPONENT_ANNOUNCEMENT (      \
    (opposing ? "Your " : "Your opponent's ")          \
    opponent->fighters[i - fighters.size()].get_name() \
    + " was healed "                                   \
    + std::to_string(healing[i])                       \
    + " damage!"                                       \
)
//}

// Announcement for a fighter returning to hand.
//{
#define BOUNCE_ANNOUNCEMENT (                \
    (                                        \
        opposing ? "Your opponent returned " \
        : "You returned "                    \
    )                                        \
    + last_fighter.get_name()                \
    + " to "                                 \
    + (opposing ? "their" : "your")          \
    + " hand!"                               \
)
//}

// Announcement for a splash attack.
//{
#define SPLASH_ANNOUNCEMENT (                          \
    std::string(opposing ? "Your" : "Your opponent's") \
    + " benched fighter"                               \
    + (opponent->fighters.size() == 2 ? "" : "s")      \
    + " took "                                         \
    + std::to_string(damage)                           \
    + " damage."                                       \
)
//}

// Announcement for a self-splash attack.
//{
#define SPLASH_SELF_ANNOUNCEMENT (                      \
    std::string(!opposing ? "Your" : "Your opponent's") \
    + " benched fighter"                                \
    + (fighters.size() == 2 ? "" : "s")                 \
    + " took "                                          \
    + std::to_string(damage)                            \
    + " damage."                                        \
)
//}

// Announcement for a rank down.
//{
#define RANK_DOWN_ANNOUNCEMENT (                         \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + " was ranked down into "                           \
    + old_rank.get_name()                                \
    + "!"                                                \
)
//}

// Announcement for recoil damage.
//{
#define RECOIL_ANNOUNCEMENT (                  \
    (!opposing ? "Your " : "Your opponent's ") \
    + fighters[index].get_name()               \
    + " dealt "                                \
    + std::to_string(damage)                   \
    + " damage to itself!"                     \
)
//}

// Announcement for heal aura.
//{
#define HEAL_AURA_ANNOUNCEMENT (                       \
    std::string(opposing ? "Your opponent's" : "Your") \
    + " fighters were all healed "                     \
    + std::to_string(healing)                          \
    + " damage!"                                       \
)
//}

// Announcement for an energy bounce.
//{
constexpr const char* ENERGY_BOUNCE_ANNOUNCEMENT =
    "All of the energy cards in play were returned to their owners' hands!"
;
//}

// Announcement to declare that a card will be searched for in the life cards.
//{
#define SEARCH_LIFE_ANNOUNCEMENT (                                               \
    opposing ? "Your opponent is searching their life cards for a card to draw." \
    : "Choose a card to draw from your life cards."                              \
)
//}

// Announcement to declare that a fighter should be chosen to rank up.
//{
#define TRAIN_ANNOUNCEMENT (                                     \
    opposing ? "Your opponent is choosing a fighter to rank up." \
    : "Choose a fighter to rank up (with cards from your deck)." \
)
//}

// Announcement for energy accelerated out of the deck.
//{
#define ACCELERATION_ANNOUNCEMENT (                 \
    std::string(opposing ? "Your opponent" : "You") \
    + " attached "                                  \
    + deck[energy_index].get_name()                 \
    + " from "                                      \
    + std::string(opposing ? "their" : "your")      \
    + " deck to "                                   \
    + fighters[index].get_name()                    \
    + "!"                                           \
)
//}

// Announcement for a fighter's invinciblity.
//{
#define INVINCIBILITY_ANNOUNCEMENT (          \
    (opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()              \
    + " can't be damaged until the start of " \
    + (opposing ? "their" : "your")           \
    + " next turn!"                           \
)
//}

// Announcement to declare that the energy in a player's hand has been converted.
//{
#define HAND_CONVERSION_ANNOUNCEMENT (                   \
    "The energy cards in "                               \
    + std::string(opposing ? "your opponent's" : "your") \
    + " hand were converted to the "                     \
    + fighters[index].get_element()                      \
    + " element!"                                        \
)
//}

// Announcement for an attack and retreat reset.
//{
#define RESET_ANNOUNCEMENT (                                  \
    std::string(opposing ? "Your opponent's" : "Your")        \
    + " attack and retreat use has been reset for this turn!" \
)
//}

// Announcement for a heal splash.
//{
#define HEAL_SPLASH_ANNOUNCEMENT (                     \
    std::string(opposing ? "Your opponent's" : "Your") \
    + " fighter"                                       \
    + (fighters.size() == 1 ? " was" : "s were")       \
    + " healed "                                       \
    + std::to_string(healing)                          \
    + " damage!"                                       \
)
//}

// Announcement for an opposing heal splash.
//{
#define HEAL_OPPONENT_SPLASH_ANNOUNCEMENT (                \
    std::string(!opposing ? "Your opponent's" : "Your")    \
    + " fighter"                                           \
    + (opponent->fighters.size() == 1 ? " was" : "s were") \
    + " healed "                                           \
    + std::to_string(healing)                              \
    + " damage!"                                           \
)
//}

// Announcement for a cripple.
//{
#define CRIPPLE_ANNOUNCEMENT (                            \
    std::string(!opposing ? "Your opponent's " : "Your ") \
    + opponent->fighters[0].get_name()                    \
    + " can't retreat during its player's next turn!"     \
)
//}

// Announcement for an impairment.
//{
#define IMPAIR_ANNOUNCEMENT (                             \
    std::string(!opposing ? "Your opponent's " : "Your ") \
    + opponent->fighters[0].get_name()                    \
    + " can't attack during its player's next turn!"      \
)
//}

// Announceent for the opponent seeing how many life cards that the player will banish.
//{
#define LIFE_BANISH_ANNOUNCEMENT (    \
    "Your opponent is choosing "      \
    + std::to_string(life_banishes)   \
    + " life card"                    \
    + (life_banishes == 1 ? "" : "s") \
    + " to banish."                   \
)
//}

// Announcement for the player to banish a life card.
//{
constexpr const char* BANISH_LIFE_ANNOUNCEMENT = "Choose a life card to banish.";
//}

// Announcement to display the banished life card.
//{
#define BANISH_LIFE_PEEK_ANNOUNCEMENT (             \
    std::string(opposing ? "Your opponent" : "You") \
    + " banished "                                  \
    + life_cards[index].get_name()                  \
    + "!"                                           \
)
//}

// Announcement to indicate that the trash's contents were banished.
//{
#define BANISHMENT_ANNOUNCEMENT (                        \
    "The cards in "                                      \
    + std::string(opposing ? "your opponent's" : "your") \
    + " trash were banished."                            \
)
//}

// Announcement to declare a mimicry choice.
//{
#define MIMIC_ANNOUNCEMENT (                                           \
    opposing ? "Your opponent is choosing a fighter's attack to copy." \
    : "Choose a fighter's attack to copy."                             \
)
//}

// Announcement to declare that a curse has been placed.
//{
#define CURSE_ANNOUNCEMENT (                              \
    std::string(!opposing ? "Your opponent's " : "Your ") \
    + opponent->fighters[0].get_name()                    \
    + " will take "                                       \
    + curse                                               \
    + " damage at the end of each turn!"                  \
)
//}

// Announcement to declare the damage dealt to a friendly fighter.
//{
#define FRIENDLY_DAMAGE_ANNOUNCEMENT (                   \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + fighters[index].get_name()                         \
    + " took "                                           \
    + std::to_string(damage)                             \
    + " damage!"                                         \
)
//}

// Annoucement to declare an abandonment.
//{
#define ABANDON_ANNOUNCEMENT (                           \
    std::string(opposing ? "Your opponent's " : "Your ") \
    + trash[fighter_index].get_name()                    \
    + " was banished!"                                   \
)
//}

// Announcement for the damage distribution.
//{
#define DAMAGE_DISTRIBUTION_ANNOUNCEMENT (                \
    std::string(!opposing ? "Your opponent's " : "Your ") \
    + opponent->fighters[i].get_name()                    \
    + " took "                                            \
    + std::to_string(damage[i])                           \
    + " damage!"                                          \
)
//}

// Announcement for element conversion.
//{
#define CONVERSION_ANNOUNCEMENT (                      \
    std::string(opposing ? "Your opponent's" : "Your") \
    + " cards were converted to the "                  \
    + fighters[index].get_element()                    \
    + " element!"                                      \
)
//}

// Announcement for deplays.
//{
#define DEPLAY_ANNOUNCEMENT (                        \
    std::string(opposing ? "You" : "Your opponent")  \
    + " can play "                                   \
    + std::to_string(deplays)                        \
    + (deplays == 1 ? " less card" : " fewer cards") \
    + " during "                                     \
    + (opposing ? "your" : "their")                  \
    + " next turn!"                                  \
)
//}

// Announcement for extra plays.
//{
#define EXTRA_PLAY_ANNOUNCEMENT (                    \
    std::string(!opposing ? "You" : "Your opponent") \
    + " can play "                                   \
    + std::to_string(extra_plays)                    \
    + " more card"                                   \
    + (extra_plays == 1 ? "" : "s")                  \
    + " this turn!"                                  \
)
//}

// Announcement for overload.
//{
#define OVERLOAD_ANNOUNCEMENT (                         \
    std::string(!opposing ? "You" : "Your opponent")    \
    + " can play "                                      \
    + overload                                          \
    + (overload == "1" ? " less card" : " fewer cards") \
    + " during "                                        \
    + (!opposing ? "your" : "their")                    \
    + " next turn!"                                     \
)
//}

// Announcement for a rooting.
//{
#define ROOT_ANNOUNCEMENT (                        \
    (opposing ? "Your opponent's " : "Your ")      \
    + fighters[index].get_name()                   \
    + " can't be switched out until the start of " \
    + (opposing ? "their" : "your")                \
    + " next turn!"                                \
)
//}

// Announcement for opposing rooting.
//{
#define ROOT_OPPONENT_ANNOUNCEMENT (             \
    (!opposing ? "Your opponent's " : "Your ")   \
    + opponent->fighters[0].get_name()           \
    + " can't be switched out until the end of " \
    + (opposing ? "their" : "your")              \
    + " next turn!"                              \
)
//}

// Announcement for an unranked draw.
//{
#define DRAW_UNRANKED_ANNOUNCEMENT (                \
    std::string(opposing ? "Your opponent" : "You") \
    + " draw all of the unranked fighters in "      \
    + (opposing ? "their" : "your")                 \
    + " deck!"                                      \
)
//}
//}

// Universal Effect Explanation Constants
//{
#define EXPLANATION_STRING explain(effect_name, effect_value)
constexpr double EXPLANATION_X = 0.5;
constexpr double EXPLANATION_Y = 0.5;
constexpr double EXPLANATION_WIDTH = 0.375 * TITLE_WIDTH;
constexpr double EXPLANATION_HEIGHT = 2 * EXPLANATION_WIDTH;
constexpr double EXPLANATION_MAX_WIDTH = 0.75;
constexpr double EXPLANATION_SEPARATION_X = EXPLANATION_WIDTH / 20;
constexpr double EXPLANATION_SEPARATION_Y = EXPLANATION_HEIGHT / 5;
constexpr Renderer::Justification EXPLANATION_JUSTIFICATION = Renderer::CENTRE_JUSTIFY;
constexpr const char* EMPTY_EXPLANATION = "";
//}
//}

// Card Instance Constants
//{
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
    "If you do, this fighter deals 50 more damage this turn."
;
const std::string RACER_ABILITY_EFFECTS(
    std::string(SWITCH_IN_EFFECT) // switch_in
    + EFFECT_SEPARATOR            //
    + POWER_EFFECT                // power
    + EFFECT_SEPARATOR            //
    + "50"                       // 50
);
constexpr bool RACER_ABILITY_PASSIVE = false;
constexpr int RACER_ABILITY_USES = 1;
constexpr const char* RACER_ATTACK_NAME = "Nitro Boost";
constexpr const char* RACER_ATTACK_DESCRIPTION =
    "Deal 450 damage to your opponent's active fighter."
;
constexpr const char* RACER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int RACER_ATTACK_DAMAGE = 450;
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
    "If you do, this fighter deals 100 more damage this turn."
;
const std::string HOT_RODDER_ABILITY_EFFECTS(
    std::string(SWITCH_IN_EFFECT) // switch_in
    + EFFECT_SEPARATOR            //
    + POWER_EFFECT                // power
    + EFFECT_SEPARATOR            //
    + "100"                       // 100
);
constexpr bool HOT_RODDER_ABILITY_PASSIVE = false;
constexpr int HOT_RODDER_ABILITY_USES = 1;
constexpr const char* HOT_RODDER_ATTACK_NAME = "Super Nitro";
constexpr const char* HOT_RODDER_ATTACK_DESCRIPTION =
    "Deal 650 damage to your opponent's active fighter."
;
constexpr const char* HOT_RODDER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int HOT_RODDER_ATTACK_DAMAGE = 650;
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
    "Deal 350 damage to one of your opponent's fighters.\n"
    "Deal 50 less damage to Water element fighters."
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
    "Deal 375 damage to your opponent's active fighter.\n"
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
    "Deal 500 damage to your opponent's active fighter.\n"
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
constexpr int PYROMANCER_HEALTH = 1150;
constexpr int PYROMANCER_RETREAT_COST = 2000;
constexpr const char* PYROMANCER_OLD_RANK = MAGE_NAME;
constexpr const char* PYROMANCER_ABILITY_NAME = "Incinerate";
constexpr const char* PYROMANCER_ABILITY_DESCRIPTION =
    "Once a turn, you may discard the top card of your opponent's deck."
;
const std::string PYROMANCER_ABILITY_EFFECTS(
    std::string(MILL_EFFECT) // mill
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
constexpr int WARLOCK_HEALTH = 1250;
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
    "Deal 800 damage to your opponent's active fighter.\n"
    "Deal 150 damage to this fighter."
;
const std::string WARLOCK_ATTACK_EFFECTS(
    std::string(RECOIL_EFFECT) // recoil
    + EFFECT_SEPARATOR         //
    + "150"                    // 150
);
constexpr int WARLOCK_ATTACK_DAMAGE = 800;
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
    "Once a turn, you may attach a random energy card, of "
    "this fighter's element, in your deck, to this fighter."
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
constexpr int MINER_RETREAT_COST = 1000;
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
    "Deal 600 damage to your opponent's active fighter.\n"
    "If this fighter has the invincibility effect, deal 200 more damage.\n"
    "Clear all effects from this fighter."
;
const std::string SCUBA_DIVER_ATTACK_EFFECTS(
    std::string(POWER_EFFECT) // power
    + EFFECT_SEPARATOR        //
    + INVINCIBILITY_EFFECT    // invincibility
    + EFFECT_SEPARATOR        //
    + "200"                   // 200
    + EFFECT_TERMINATOR
    + CLEAR_EFFECT            // clear
);
constexpr int SCUBA_DIVER_ATTACK_DAMAGE = 600;
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
    "Deal 450 damage to your opponent's active fighter."
;
constexpr const char* WELDER_ATTACK_EFFECTS = NO_EFFECTS;
constexpr int WELDER_ATTACK_DAMAGE = 450;
constexpr int WELDER_ATTACK_COST = 2000;
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
constexpr int PYROTECHNICIAN_ATTACK_COST = 0;
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
// Void Servant Ability Constants
//{
constexpr const char* VOID_SERVANT_ABILITY_NAME = "Void Servant";
constexpr const char* VOID_SERVANT_ABILITY_DESCRIPTION =
    "At the end of your turn, banish all of the cards in your trash."
;
constexpr const char* VOID_SERVANT_ABILITY_EFFECTS = BANISHMENT_EFFECT; // banishment
constexpr bool VOID_SERVANT_ABILITY_PASSIVE = true;
constexpr int VOID_SERVANT_ABILITY_USES = PASSIVE_USES;
//}

// Banisher
//{
constexpr const char* BANISHER_NAME = "Banisher";
constexpr const char* BANISHER_ELEMENT = FIRE_ELEMENT;
constexpr int BANISHER_HEALTH = 1100;
constexpr int BANISHER_RETREAT_COST = 0;
constexpr const char* BANISHER_OLD_RANK = NO_OLD_RANK;
constexpr const char* BANISHER_ABILITY_NAME = VOID_SERVANT_ABILITY_NAME;
constexpr const char* BANISHER_ABILITY_DESCRIPTION = VOID_SERVANT_ABILITY_DESCRIPTION;
constexpr const char* BANISHER_ABILITY_EFFECTS = VOID_SERVANT_ABILITY_EFFECTS;
constexpr bool BANISHER_ABILITY_PASSIVE = VOID_SERVANT_ABILITY_PASSIVE;
constexpr int BANISHER_ABILITY_USES = VOID_SERVANT_ABILITY_USES;
constexpr const char* BANISHER_ATTACK_NAME = "Shadow Flame";
constexpr const char* BANISHER_ATTACK_DESCRIPTION =
    "Your opponent's active fighter takes 50 damage at "
    "the end of each turn, for each card in the void, "
    "for a maximum of 500 damage."
;
const std::string BANISHER_ATTACK_EFFECTS(
    std::string(CURSE_EFFECT) // curse
    + EFFECT_SEPARATOR        //
    + VOID_EFFECT             // void
    + EFFECT_SEPARATOR        //
    + "50"                    // 50
    + EFFECT_SEPARATOR        //
    + "500"                   // 500
);
constexpr int BANISHER_ATTACK_DAMAGE = 0;
constexpr int BANISHER_ATTACK_COST = 0;
//}

// Banshee
//{
constexpr const char* BANSHEE_NAME = "Banshee";
constexpr const char* BANSHEE_ELEMENT = WATER_ELEMENT;
constexpr int BANSHEE_HEALTH = 1100;
constexpr int BANSHEE_RETREAT_COST = 0;
constexpr const char* BANSHEE_OLD_RANK = NO_OLD_RANK;
constexpr const char* BANSHEE_ABILITY_NAME = VOID_SERVANT_ABILITY_NAME;
constexpr const char* BANSHEE_ABILITY_DESCRIPTION = VOID_SERVANT_ABILITY_DESCRIPTION;
constexpr const char* BANSHEE_ABILITY_EFFECTS = VOID_SERVANT_ABILITY_EFFECTS;
constexpr bool BANSHEE_ABILITY_PASSIVE = VOID_SERVANT_ABILITY_PASSIVE;
constexpr int BANSHEE_ABILITY_USES = VOID_SERVANT_ABILITY_USES;
constexpr const char* BANSHEE_ATTACK_NAME = "Screech";
constexpr const char* BANSHEE_ATTACK_DESCRIPTION =
    "Deal 75 damage to your opponent's active fighter, "
    "for each card in the void, "
    "for a maximum of 750 damage."
;
const std::string BANSHEE_ATTACK_EFFECTS(
    std::string(POWER_EFFECT) // power
    + EFFECT_SEPARATOR        //
    + VOID_EFFECT             // void
    + EFFECT_SEPARATOR        //
    + "75"                    // 75
    + EFFECT_SEPARATOR        //
    + "750"                   // 750
);
constexpr int BANSHEE_ATTACK_DAMAGE = 0;
constexpr int BANSHEE_ATTACK_COST = 0;
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
    "and heal 30 damage from one "
    "of your fighters, for each card in the void, "
    "for a maximum of 300 healing."
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
    + "30"                     // 30
    + EFFECT_SEPARATOR         //
    + "300"                    // 300
);
constexpr bool CULTIST_ABILITY_PASSIVE = false;
constexpr int CULTIST_ABILITY_USES = 1;
constexpr const char* CULTIST_ATTACK_NAME = "Shadow Bond";
constexpr const char* CULTIST_ATTACK_DESCRIPTION =
    "Choose a fighter in the void.\n"
    "Use its attack."
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
// Universal Apprentice Rank Ability Constants
//{
constexpr const char* APPRENTICE_RANK_ABILITY_NAME = "Ascension";
constexpr const char* APPRENTICE_RANK_ABILITY_DESCRIPTION =
    "Once a turn, you may rank this fighter up into a random fighter in your hand."
;
constexpr const char* APPRENTICE_RANK_ABILITY_EFFECTS = ASCENSION_EFFECT; // ascension
constexpr bool APPRENTICE_RANK_ABILITY_PASSIVE = false;
constexpr int APPRENTICE_RANK_ABILITY_USES = 1;
//}

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
constexpr const char* APPRENTICE_ABILITY_NAME = APPRENTICE_RANK_ABILITY_NAME;
constexpr const char* APPRENTICE_ABILITY_DESCRIPTION = APPRENTICE_RANK_ABILITY_DESCRIPTION;
constexpr const char* APPRENTICE_ABILITY_EFFECTS = APPRENTICE_RANK_ABILITY_EFFECTS;
constexpr bool APPRENTICE_ABILITY_PASSIVE = APPRENTICE_RANK_ABILITY_PASSIVE;
constexpr int APPRENTICE_ABILITY_USES = APPRENTICE_RANK_ABILITY_USES;
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
constexpr const char* SENSEIS_CHOSEN_ABILITY_NAME = APPRENTICE_RANK_ABILITY_NAME;
constexpr const char* SENSEIS_CHOSEN_ABILITY_DESCRIPTION = APPRENTICE_RANK_ABILITY_DESCRIPTION;
constexpr const char* SENSEIS_CHOSEN_ABILITY_EFFECTS = APPRENTICE_RANK_ABILITY_EFFECTS;
constexpr bool SENSEIS_CHOSEN_ABILITY_PASSIVE = APPRENTICE_RANK_ABILITY_PASSIVE;
constexpr int SENSEIS_CHOSEN_ABILITY_USES = APPRENTICE_RANK_ABILITY_USES;
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
constexpr const char* NINJA_ATTACK_NAME = "Infiltrate";
constexpr const char* NINJA_ATTACK_DESCRIPTION =
    "Deal 400 damage to one of your opponent's fighters.\n"
    "Flip 2 coins.\n"
    "Deal 100 more damage for each heads."
;
const std::string NINJA_ATTACK_EFFECTS(
    std::string(FLIP_EFFECT) // flip
    + EFFECT_SEPARATOR       //
    + "1"                    // 1
    + EFFECT_TERMINATOR
    + HEADS_EFFECT           // heads
    + EFFECT_SEPARATOR       //
    + POWER_EFFECT           // power
    + EFFECT_SEPARATOR       //
    + "100"                  // 100
    + EFFECT_TERMINATOR
    + FLIP_EFFECT            // flip
    + EFFECT_SEPARATOR       //
    + "1"                    // 1
    + EFFECT_TERMINATOR
    + HEADS_EFFECT           // heads
    + EFFECT_SEPARATOR       //
    + POWER_EFFECT           // power
    + EFFECT_SEPARATOR       //
    + "100"                  // 100
    + EFFECT_TERMINATOR
    + SNIPE_EFFECT           // snipe
    + EFFECT_SEPARATOR       //
    + "400"                  // 400
    + EFFECT_TERMINATOR
    + DEPOWER_EFFECT         // depower
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
    "Deal 250 damage to your opponent's active fighter.\n"
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
constexpr int SAMURAI_ATTACK_DAMAGE = 250;
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
    "If you defeat at least 3, rank this fighter up into a random "
    "fighter card in your hand that ranks up from this ability.\n"
    "Store this fighter card with your life cards."
;
const std::string ELEMENTAL_ABILITY_EFFECTS(
    std::string(FUSION_EFFECT) // fusion
    + EFFECT_SEPARATOR         //
    + "3"                      // 3
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
constexpr int OMEGA_ELEMENTAL_HEALTH = 2000;
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
    "Randomly distribute 500 damage between your opponent's fighters.\n"
    "Heal 0.8 damage from this fighter multiplied by the damage dealt."
;
const std::string OMEGA_ELEMENTAL_ATTACK_EFFECTS(
    std::string(DISTRIBUTE_EFFECT) // distribute
    + EFFECT_SEPARATOR             //
    + "500"                        // 500
    + EFFECT_TERMINATOR
    + HEAL_EFFECT                  // heal
    + EFFECT_SEPARATOR             //
    + SELF_EFFECT                  // self
    + EFFECT_SEPARATOR             //
    + DAMAGE_EFFECT                // damage
    + EFFECT_SEPARATOR             //
    + "0.8"                        // 0.8
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
    "Search your deck for a card of the same type and draw it."
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
    "Search your deck for a card and draw it.\n"
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
    "You can play 1 less card next turn."
;
const std::string TIME_TRAVELLER_EFFECTS(
    std::string(SEARCH_EFFECT) // search
    + EFFECT_SEPARATOR         //
    + TRASH_EFFECT             // trash
    + EFFECT_SEPARATOR         //
    + "1"                      // 1
    + EFFECT_TERMINATOR
    + OVERLOAD_EFFECT          // overload
    + EFFECT_SEPARATOR         //
    + "1"                      // 1
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
    "Randomly distribute 800 healing between your fighters."
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
    "If your opponent's active fighter's current health is less than "
    "or equal to 0.2 multiplied by its maximum health, defeat it."
;
const std::string ASSASSIN_EFFECTS(
    std::string(ASSASSINATE_EFFECT) // assassinate
    + EFFECT_SEPARATOR              //
    + "0.2"                         // 0.2
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
    "Attacks deal 100 more damage for the rest of the duel.\n"
    "Draw a card.\n"
    "You can play 1 more card this turn."
;
const std::string ARMS_SMUGGLER_EFFECTS(
    std::string(POWER_AURA_EFFECT) // power_aura
    + EFFECT_SEPARATOR             //
    + "100"                        // 100
    + EFFECT_TERMINATOR
    + DRAW_EFFECT                  // draw
    + EFFECT_SEPARATOR             //
    + "1"                          // 1
    + EFFECT_TERMINATOR
    + EXTRA_PLAY_EFFECT            // extra_play
    + EFFECT_SEPARATOR             //
    + "1"                          // 1
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
    "deal 10000 less damage until the start of your next turn."
;
const std::string PEACEMAKER_EFFECTS(
    std::string(ATTACKLESS_EFFECT) // attackless
    + EFFECT_TERMINATOR
    + POWER_EFFECT                 // power
    + EFFECT_SEPARATOR             //
    + "-10000"                      // -10000
    + EFFECT_TERMINATOR
    + POWER_EFFECT                 // power
    + EFFECT_SEPARATOR             //
    + OPPONENT_EFFECT              // opponent
    + EFFECT_SEPARATOR             //
    + "-10000"                      // -10000
);
//}

// Matchmaker
//{
constexpr const char* MATCHMAKER_NAME = "Matchmaker";
constexpr const char* MATCHMAKER_DESCRIPTION =
    "Your opponent's active fighter can't be switched out during their next turn."
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
    "Shuffle both players' hands into their decks.\n"
    "Both players draw 5 cards."
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
    + "5"                       // 5
    + EFFECT_TERMINATOR
    + DRAW_EFFECT               // draw
    + EFFECT_SEPARATOR          //
    + "5"                       // 5
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
    "Discard the top card of both players' decks.\n"
    "Return this card to your hand.\n"
    "At the end of your turn, discard this card."
;
const std::string MILLER_EFFECTS(
    std::string(MILL_EFFECT) // mill
    + EFFECT_SEPARATOR       //
    + "1"                    // 1
    + EFFECT_TERMINATOR
    + MILL_EFFECT            // mill
    + EFFECT_SEPARATOR       //
    + SELF_EFFECT            // self
    + EFFECT_SEPARATOR       //
    + "1"                    // 1
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
    "Banish the top 2 cards of both players' decks."
;
const std::string ARSONIST_EFFECTS(
    std::string(MILL_EFFECT) // mill
    + EFFECT_SEPARATOR       //
    + BANISH_EFFECT          // banish
    + EFFECT_SEPARATOR       //
    + "2"                    // 2
    + EFFECT_TERMINATOR
    + MILL_EFFECT            // mill
    + EFFECT_SEPARATOR       //
    + SELF_EFFECT            // self
    + EFFECT_SEPARATOR       //
    + BANISH_EFFECT          // banish
    + EFFECT_SEPARATOR       //
    + "2"                    // 2
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
//}
//}

// PC Constants
//{
// Audio Constants
//{
// Menu song details.
constexpr const char* MENU_SONG_SOURCE = "data/menusong.wav";
constexpr double MENU_SONG_LENGTH = Timer::to_seconds(0, 1, 8);

// Build song details.
constexpr const char* BUILD_SONG_SOURCE = "data/buildsong.wav";
constexpr double BUILD_SONG_LENGTH = Timer::to_seconds(0, 0, 57);

// Duel song details.
constexpr const char* DUEL_SONG_SOURCE = "data/duelsong.wav";
constexpr double DUEL_SONG_LENGTH = Timer::to_seconds(0, 1, 55);
//}
//}

// Basic Classes
//{
/**
 * An abstract base class for objects
 *   that can be affected to inherit from.
 */
class Affectable {
    public:
        /**
         * Returns a constant reference to the object's effects.
         */
        const std::vector<std::vector<std::string>>& get_effects() const noexcept {
            return effects;
        }
        
        /**
         * Converts an effect representation to an effect explanation.
         */
        static std::string explain(
            const std::string& effect_name,
            const std::string& effect_value
        ) noexcept {
            // The explanation for the effect is searched for.
            for (int i = 0; i < EXPLANATION_COUNT; ++i) {
                if (effect_name == EFFECT_REPRESENTATIONS[i]) {
                    return EFFECT_EXPLANATIONS(i);
                }
            }
            
            // The explanation for the player-specific effect is searched for.
            for (int i = 0; i < PLAYER_EXPLANATION_COUNT; ++i) {
                if (effect_name == PLAYER_EFFECT_REPRESENTATIONS[i]) {
                    return PLAYER_EFFECT_EXPLANATIONS(i);
                }
            }
            
            // If no explanation is found, the empty explanation is returned.
            return EMPTY_EXPLANATION;
        }           
        
        /**
         * Explains the functionality of an effect.
         */
        static void explain(
            Display& display,
            const Renderer& renderer,
            const Button& back_button,
            const std::string& message,
            const std::string& effect_name,
            const std::string& effect_value
        ) noexcept {
            // The explanation is rendered.
            display.fill();
            display.blit(
                renderer.lined_render(
                    display,
                    EXPLANATION_STRING,
                    EXPLANATION_WIDTH,
                    EXPLANATION_HEIGHT,
                    EXPLANATION_SEPARATION_X,
                    EXPLANATION_MAX_WIDTH,
                    EXPLANATION_SEPARATION_Y,
                    EXPLANATION_JUSTIFICATION
                ),
                EXPLANATION_X,
                EXPLANATION_Y
            );
            back_button.blit_to(display);
            display.update();
            
            // The player proceeds when they or their opponent makes a move.
            while (
                !Events::unpress(NEXT_KEY)
                && !Events::unpress(BACK_KEY)
                && !back_button.get_rectangle().unclick()
                && message == EMPTY_MESSAGE
            ) {
                Events::update();
            }
        }
        
        /**
         * Counts the total effect value of an effect.
         */
        virtual int effect_count(const std::string& effect) const noexcept {
            int count = 0;
            
            for (int i = 0; i < effects.size(); ++i) {
                if (effects[i][0] == effect) {
                    count += std::stoi(effects[i][1]);
                }
            }
            
            return count;
        }
        
        /**
         * Returns a subset of the effects that begin with the given effect.
         */
        virtual std::vector<std::vector<std::string>> effect_search(
            const std::string& effect
        ) const noexcept {
            // The filtered effects are stored here.
            std::vector<std::vector<std::string>> filtered;
            
            // The effect is searched for.
            for (int i = 0; i < effects.size(); ++i) {
                // Matching effects are added to the filtered effects.
                if (effects[i][0] == effect) {
                    filtered.push_back(effects[i]);
                }
            }
            
            // The filtered effects are returned.
            return filtered;
        }
        
        /**
         * Returns a subset of the effects that begin with the two given effects.
         * This function uses the overridable virtual member function
         *   effect_search() as a basis for the initial filtering.
         */
        template<int count>
        std::vector<std::vector<std::string>> effect_search(
            const std::array<std::string, count>& effects
        ) const noexcept {
            // A positive search depth prompts the usual protocol.
            if (count > 0) {
                // The filtered effects will be stored in this vector.
                std::vector<std::vector<std::string>> filtered;
                
                // The effects that were filtered according to the first effect.
                std::vector<std::vector<std::string>> proto_filtered(
                    effect_search(effects[0])
                );
                
                // Each effect in proto_filtered is checked.
                for (int i = 0; i < proto_filtered.size(); ++i) {
                    // True, if all of the desired fields match.
                    bool valid = true;
                    
                    // The desired fields are checked
                    for (int j = 1; valid && j < count; ++j) {
                        // One mismatch invalidates the entire effect.
                        if (proto_filtered[i][j] != effects[j]) {
                            valid = false;
                        }
                    }
                    
                    // All of the desired fields match, so they are added to the vector.
                    if (valid) {
                        filtered.push_back(proto_filtered[i]);
                    }
                }
                
                return filtered;
            }
            
            // A non-positive search depth returns all of the effects.
            // Note that this is not necesaarily source of all of the effects that
            //   could be considered by the overridden effect_search() member function.
            else {
                return this->effects;
            }
        }
        
        /**
         * Adds an effect to his object.
         */
        void affect(const std::string& effects) noexcept {
            // A stream is used to parse the effects.
            std::stringstream effect_stream(effects + EFFECT_TERMINATOR);
            std::vector<std::string> proto_effects;
            std::string effect_string;
            
            // The effects are divided by line.
            for (
                std::getline(effect_stream, effect_string, EFFECT_TERMINATOR);
                !effect_stream.eof();
                std::getline(effect_stream, effect_string, EFFECT_TERMINATOR)
            ) {
                proto_effects.push_back(effect_string);
            }
            
            // The effects are then divided into words.
            for (int i = 0; i < proto_effects.size(); i++) {
                this->effects.push_back(std::vector<std::string>());
                
                effect_stream.clear();
                effect_stream.seekg(0);
                effect_stream.str(proto_effects[i] + EFFECT_SEPARATOR);
                
                for (
                    std::getline(effect_stream, effect_string, EFFECT_SEPARATOR);
                    !effect_stream.eof();
                    std::getline(effect_stream, effect_string, EFFECT_SEPARATOR)
                ) {
                    this->effects.back().push_back(effect_string);
                }
            }
        }
        
        /**
         * Removes all effects from this object that match the given argument.
         */
        void unaffect(const std::string& effect) noexcept {
            for (int i = 0; i < effects.size(); ++i) {
                if (effects[i][0] == effect) {
                    effects.erase(effects.cbegin() + i);
                    --i;
                }
            }
        }
        
    protected:
        /**
         * Parses, extracts, and organises the given effects.
         */
        Affectable(const std::string& effects) noexcept {
            affect(effects);
        }
        
        std::vector<std::vector<std::string>> effects; // The effects of the object.
};

/**
 * An abstract base class for the card types to inherit from.
 */
class Card: public Affectable {
    public:
        /**
         * Returns the card's name.
         */
        const std::string& get_name() const noexcept {
            return name;
        }
        
        /**
         * Returns the card's type.
         * The types of card are Fighter, Supporter, and Energy.
         * The instantiating class should define the card type.
         */
        const std::string& get_type() const noexcept {
            return type;
        }
        
        /**
         * Returns the card in string form.
         * This string should be compatible with the Renderer class.
         */
        virtual std::string to_string() const noexcept = 0;
        
        /**
         * Renders the card's text to the display.
         */
        void render(Display& display, const Renderer& renderer) const noexcept {
            // The components of the display are extracted.
            Sprite& display_sprite = display.get_sprite();
            int display_width = display_sprite.get_width();
            int display_height = display_sprite.get_height();
            
            // The display is blitted to.
            display_sprite.fill();
            
            display_sprite.blit(
                renderer.lined_render(
                    to_string(),
                    CARD_WIDTH * display_width,
                    CARD_HEIGHT * display_height,
                    CARD_SEPARATION_X * display_width,
                    CARD_MAX_WIDTH * display_width,
                    CARD_SEPARATION_Y * display_height,
                    CARD_JUSTIFICATION
                ),
                CARD_X,
                CARD_Y
            );
        }
        
    protected:
        /**
         * This class should not be instantiated.
         * The inheriting class must define the
         *   card's name, type, and effects.
         */
        Card(
            const std::string& name,
            const std::string& description,
            const std::string& type,
            const std::string& effects
        ) noexcept:
            Affectable(effects),
            name(name),
            description(description),
            type(type)
        {}
        
        std::string name; // The card's name.
        std::string description; // A string that describes the card's effects.
        std::string type; // The card's type (fighter, supporter, or energy).
};

/**
 * A type of card that is attached to fighter cards.
 * These cards pay for the fighter's attack and retreat cost.
 */
class Energy: public Card {
    public:
        /**
         * Constructs an energy card with the given name,
         *   description, element, effects, and value.
         */
        Energy(
            const std::string& name,
            const std::string& description,
            const std::string& element,
            const std::string& effects,
            int value
        ) noexcept:
            Card(name, description, ENERGY_TYPE, effects),
            element(element),
            value(value)
        {}
        
        /**
         * Sets the element of the energy card.
         */
        void set_element(const std::string& element) noexcept {
            this->element = element;
        }
        
        /**
         * Returns the energy card's value.
         */
        int get_value() const noexcept {
            return value;
        }
        
        /**
         * Returns the value of the energy card for the fighter's attacks.
         * Usually, returns the value integer for fighters with a matching
         *   element and zero for fighters without a matching element.
         */
        int get_value(const std::string& element) const noexcept {
            if (effect_search(UNIVERSAL_EFFECT).size()) {
                return value;
            }
            
            return this->element == element ? value : 0;
        }
        
        /**
         * Returns the energy card in string form.
         * This string is designed for the Renderer class.
         */
        std::string to_string() const noexcept {
            return
                element + " Element " + type + " Card\n\n"
                + name + "\n\n" + description
            ;
        }
        
        /**
         * Returns the card's element.
         */
        const std::string& get_element() const noexcept {
            return element;
        }
        
    private:
        std::string element; // The element of the fighters that the energy card can power.
        int value; // The amount of energy that this energy card provides.
};

/**
 * A type of card that is played to help assist the player,
 *   but doesn't get played on the field to battle directly.
 */
class Supporter: public Card {
    public:
        /**
         * Constructs a supporter card with its name, description, and effects.
         */
        Supporter(
            const std::string& name,
            const std::string& description,
            const std::string& effects
        ) noexcept:
            Card(name, description, SUPPORTER_TYPE, effects)
        {}
        
        /**
         * Returns the supporter card in string form.
         * This string is designed for the Renderer class.
         */
        std::string to_string() const noexcept {
            return
                std::string(type) + " Card\n\n"
                + name + "\n\n" + description
            ;
        }
};

/**
 * A feature of all fighters that takes effect when used,
 *   all the time, or at certain points in the game.
 */
class Ability: public Card {
    public:
        /**
         * Constructs an ability with its name, description,
         *   effects, passivity, and maximum uses per turn.
         */
        Ability(
            const std::string& name,
            const std::string& description,
            const std::string& effects,
            bool passive,
            int max_uses
        ) noexcept:
            Card(name, description, ABILITY_TYPE, effects),
            passive(passive),
            max_uses(max_uses),
            uses(max_uses)
        {}
        
        /**
         * Decreases the number of avialable ability uses.
         */
        void use() noexcept {
            // The number of uses aren't decremented if the ability can be used infinitely.
            if (max_uses != INFINITE_USES) {
                --uses;
            }
        }
        
        /**
         * Resets the number of avialable ability uses.
         */
        void reset_uses() noexcept {
            uses = max_uses;
        }
        
        /**
         * Returns true if the ability is usable.
         * An ability is usable if it is not passive and
         *   the number of uses is greater than 0
         *   (if the maximum number of uses is non-zero,
         *   as max_uses == 0 implies infinite uses).
         * This method does not consider the specific
         *   criteria featured in the ability's effects.
         */
        bool usable() const noexcept {
            return !passive && (!max_uses || uses > 0);
        }
        
        /**
         * Returns the ability in string form.
         * The string is designed for the fighter to use
         *   in its own to_string() member function.
         */
        std::string to_string() const noexcept {
            return '\n' + std::string(type) + ": " + name + '\n' + description + '\n';
        }
        
        /**
         * Returns true if this ability is passive.
         */
        bool is_passive() const noexcept {
            return passive;
        }
        
        /**
         * Returns the number of available ability uses.
         */
        int get_uses() const noexcept {
            return uses;
        }
        
        /**
         * Returns the maximum number of ability uses.
         */
        int get_max_uses() const noexcept {
            return max_uses;
        }
        
    private:
        bool passive;
        int max_uses;
        int uses;
};

/**
 * A feature of all fighters that ends the turn when used.
 * Most attacks deal damage and many have an additional effect.
 */
class Attack: public Card {
    public:
        /**
         * Contructs an attack with its name, description,
         *   effects, base damage, and energy cost.
         */
        Attack(
            const std::string& name,
            const std::string& description,
            const std::string& effects,
            int damage,
            int cost
        ) noexcept:
            Card(name, description, ATTACK_TYPE, effects),
            damage(damage),
            cost(cost)
        {}
        
        /**
         * Returns the cost of the attack.
         */
        int get_cost() const noexcept {
            return cost;
        }
        
        /**
         * Returns the attack's base damage.
         */
        int get_damage() const noexcept {
            return damage;
        }
        
        /**
         * Returns the attack in string form.
         * The string is designed for the fighter to use
         *   in its own to_string() member function.
         */
        std::string to_string() const noexcept {
            return
                '\n' + std::string(type) + ": " + name + '\n'
                + description + '\n'
                + "\nAttack Cost: " + std::to_string(cost) + '\n'
            ;
        }
        
    private:
        int damage; // The base damage of the attack.
        int cost; // The amount of energy needed to use the attack.
};

/**
 * A type of card that does battle against other fighters on the field.
 */
class Fighter: public Card {
    public:
        /**
         * Constructs a fighter with its name, element, health,
         *   retreat cost, rank, previous rank, ability, and attack.
         */
        Fighter(
            const std::string& name,
            const std::string& element,
            int health,
            int retreat_cost,
            const std::string& old_rank,
            const std::string& ability_name,
            const std::string& ability_description,
            const std::string& ability_effects,
            bool ability_passive,
            int ability_uses,
            const std::string& attack_name,
            const std::string& attack_description,
            const std::string& attack_effects,
            int attack_damage,
            int attack_cost
        ) noexcept:
            Card(name, FIGHTER_DESCRIPTION, FIGHTER_TYPE, FIGHTER_EFFECTS),
            element(element),
            health(health),
            max_health(health),
            retreat_cost(retreat_cost),
            old_rank(old_rank),
            ability(
                ability_name,
                ability_description,
                ability_effects,
                ability_passive,
                ability_uses
            ),
            attack(
                attack_name,
                attack_description,
                attack_effects,
                attack_damage,
                attack_cost
            )
        {}
        
        /**
         * Returns the fighter's element.
         */
        const std::string& get_element() const noexcept {
            return element;
        }
        
        /**
         * Returns the fighter card in string form.
         * The string is designed for the Renderer class.
         */
        std::string to_string() const noexcept {
            return
                element + " Element " + type + " Card\n\n"
                + name
                + (
                    old_rank == NO_OLD_RANK ? ""
                    : std::string("\n(from ") + old_rank + ")"
                )
                + "\n\n"
                + "Health: " + std::to_string(health) + '/' + std::to_string(max_health) + '\n'
                + ability.to_string()
                + attack.to_string()
                + "Retreat Cost: "
                + std::to_string(retreat_cost - effect_count(AGILITY_EFFECT))
                + '\n'
                + "Ability Uses: "
                + std::to_string(ability.get_uses())
                + '/'
                + std::to_string(ability.get_max_uses())
            ;
        }
        
        /**
         * Returns true if the fighter does not
         *   rank up from any other fighter card.
         */
        bool basic() const noexcept {
            return old_rank == NO_OLD_RANK;
        }
        
        /**
         * Renders the card's text to the display.
         * Also allows for the fighter's energy and effects to be seen.
         */
        void view(
            Display& display,
            const Renderer& renderer,
            const Button& back_button,
            const std::string& message = EMPTY_MESSAGE
        ) const noexcept {
            // The energy button is initialised.
            Button energy_button(
                renderer.render(
                    FIGHTER_ENERGY_STRING,
                    FIGHTER_ENERGY_WIDTH * display.width(),
                    FIGHTER_ENERGY_HEIGHT * display.height(),
                    FIGHTER_ENERGY_SEPARATION * display.width()
                ),
                display,
                FIGHTER_ENERGY_X,
                FIGHTER_ENERGY_Y
            );
            
            // The effects button is initialised.
            Button effects_button(
                renderer.render(
                    FIGHTER_EFFECTS_STRING,
                    FIGHTER_EFFECTS_WIDTH * display.width(),
                    FIGHTER_EFFECTS_HEIGHT * display.height(),
                    FIGHTER_EFFECTS_SEPARATION * display.width()
                ),
                display,
                FIGHTER_EFFECTS_X,
                FIGHTER_EFFECTS_Y
            );
            
            // True when this function should return.
            bool end = false;
            
            while (!end) {
                // The display is rendered.
                render(display, renderer);
                back_button.blit_to(display);
                energy_button.blit_to(display);
                effects_button.blit_to(display);
                display.update();
                
                while (true) {
                    // The player can go back using the next or back buttons.
                    if (
                        Events::unpress(NEXT_KEY)
                        || Events::unpress(BACK_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The energy can be viewed by pressing the energy button.
                    else if (energy_button.get_rectangle().unclick()) {
                        view_energy(display, renderer, back_button, message);
                        break;
                    }
                    
                    // The effects can be viewed by pressing the effects button.
                    else if (effects_button.get_rectangle().unclick()) {
                        view_effects(display, renderer, back_button, message);
                        break;
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Displays the energy cards attached to this fighter.
         * The card details can be displayed by clicking on the energy card's name.
         */
        void view_energy(
            Display& display,
            const Renderer& renderer,
            const Button& back_button,
            const std::string& message
        ) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The energy size sprite is intialised.
            Sprite energy_size_sprite(
                renderer.render(
                    ENERGY_SIZE_STRING,
                    ENERGY_SIZE_WIDTH * display.width(),
                    ENERGY_SIZE_HEIGHT * display.height(),
                    ENERGY_SIZE_SEPARATION * display.width()
                )
            );
            
            // Determines which cards are displayed.
            int page = 0;
            
            // True if the fighter can use energy of any element.
            bool adaptable = effect_search(ADAPTABILITY_EFFECT).size();
            
            // True if the function should return.
            bool end = false;
            
            while (!end) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                display.blit(energy_size_sprite, ENERGY_SIZE_X, ENERGY_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (static_cast<int>(energy.size())  - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < energy.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    energy[page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The value of the energy card is displayed.
                    display.blit(
                        renderer.render(
                            display,
                            ENERGY_VALUE_STRING,
                            ENERGY_VALUE_WIDTH,
                            ENERGY_VALUE_HEIGHT,
                            ENERGY_VALUE_SEPARATION
                        ),
                        ENERGY_VALUE_X,
                        ENERGY_VALUE_Y + i * ENERGY_VALUE_Y_SHIFT
                    );
                }
                
                // The total value of the energy cards attached is calculated.
                int total = energy_value();
                
                // The total value of the energy is rendered.
                display.blit(
                    renderer.render(
                        display,
                        TOTAL_ENERGY_STRING,
                        TOTAL_ENERGY_WIDTH,
                        TOTAL_ENERGY_HEIGHT,
                        TOTAL_ENERGY_SEPARATION
                    ),
                    TOTAL_ENERGY_X,
                    TOTAL_ENERGY_Y
                );
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The user can return to the previous menu with
                    //   the use of the back button or submit key.
                    if (
                        Events::unpress(SUBMIT_KEY)
                        || Events::unpress(QUIT_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (static_cast<int>(energy.size()) - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < energy.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                energy[page * PAGE_COUNT + i].render(display, renderer);
                                back_button.blit_to(display);
                                display.update();
                                
                                // The player proceeds at their own discretion.
                                while (
                                    !Events::unpress(QUIT_KEY)
                                    && !Events::unpress(NEXT_KEY)
                                    && !back_button.get_rectangle().unclick()
                                    && message == EMPTY_MESSAGE
                                ) {
                                    Events::update();
                                }
                                
                                found = true;
                                break;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Displays the effects on this fighter.
         * The details can be displayed by clicking on the effect's name.
         */
        void view_effects(
            Display& display,
            const Renderer& renderer,
            const Button& back_button,
            const std::string& message
        ) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The vectors of effects and values are inItialised.
            std::vector<std::string> effect_names;
            std::vector<std::string> effect_values;
            
            for (int i = 0; i < EXPLANATION_COUNT; ++i) {
                // A filtered effect store for macros to use.
                std::vector<std::vector<std::string>> filtered;
                int value;
                
                if (EFFECT_CONDITIONS(i)) {
                    effect_names.push_back(EFFECT_REPRESENTATIONS[i]);
                    effect_values.push_back(EFFECT_VALUES(i));
                }
            }
            
            // Determines which effects are displayed.
            int page = 0;
            
            // True if the function should return.
            bool end = false;
            
            while (!end) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (static_cast<int>(effect_names.size()) - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < effect_names.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            renderer.render(
                                effect_names[page * PAGE_COUNT + i],
                                PAGE_WIDTH * display.width(),
                                PAGE_HEIGHT * display.height(),
                                PAGE_SEPARATION * display.width()
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The value of the effect is displayed.
                    display.blit(
                        renderer.render(
                            display,
                            EFFECT_VALUE_STRING,
                            EFFECT_VALUE_WIDTH,
                            EFFECT_VALUE_HEIGHT,
                            EFFECT_VALUE_SEPARATION
                        ),
                        EFFECT_VALUE_X,
                        EFFECT_VALUE_Y + i * EFFECT_VALUE_Y_SHIFT
                    );
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The user can return to the previous menu with
                    //   the use of the back button or submit key.
                    if (
                        Events::unpress(SUBMIT_KEY)
                        || Events::unpress(QUIT_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (static_cast<int>(effect_names.size()) - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < effect_names.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                explain(
                                    display,
                                    renderer,
                                    back_button,
                                    message,
                                    effect_names[page * PAGE_COUNT + i],
                                    effect_values[page * PAGE_COUNT + i]
                                );
                                
                                found = true;
                                break;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Attaches the given energy card to this fighter.
         */
        void attach(const Energy& e) noexcept {
            energy.push_back(e);
        }
        
        /**
         * Resets the number of ability uses.
         */
        void reset_ability() noexcept {
            ability.reset_uses();
        }
        
        /**
         * Returns the name of the fighter that this fighter ranks up from.
         */
        const std::string& get_old_rank() const noexcept {
            return old_rank;
        }
        
        /**
         * For use when a fighter ranks up.
         * Transfers all of the damage and energy cards from
         *   this fighter card to the given fighter card.
         * Removes all effects from this fighter.
         */
        void rank_up(Fighter& f) noexcept {
            // Check for rank up effects.
            for (int i = 0; i < ability.get_effects().size(); ++i) {
                if (ability.get_effects()[i][0] == RANK_UP_EFFECT) {
                    if (ability.get_effects()[i][1] == CONVERSION_EFFECT) {
                        set_energy_element(f.get_element());
                    }
                }
            }
            
            f.energy = energy;
            f.health = f.max_health - (max_health - health);
            reset();
        }
        
        /**
         * Sets the element of this fighter.
         */
        void set_element(const std::string& element) noexcept {
            this->element = element;
        }
        
        /**
         * Sets the element of the fighter's energy cards.
         */
        void set_energy_element(const std::string& element) noexcept {
            for (int i = 0; i < energy.size(); ++i) {
                energy[i].set_element(element);
            }
        }
        
        /**
         * Resets this fighter's health, energy, effects, and ability uses.
         */
        void reset() noexcept {
            health = max_health;
            energy.clear();
            clear_effects();
            reset_ability();
        }
        
        /**
         * Returns this fighter's effects (including the effects from a passive ability).
         */
        std::vector<std::vector<std::string>> get_all_effects() const noexcept {
            std::vector<std::vector<std::string>> all_effects(effects);
            
            if (ability.is_passive()) {
                for (int i = 0; i < ability.get_effects().size(); ++i) {
                    all_effects.push_back(ability.get_effects()[i]);
                }
            }
            
            return all_effects;
        }
        
        /**
         * Returns true if this fighter's ability is usable.
         */
        bool ability_usable() const noexcept {
            return ability.usable();
        }
        
        /**
         * Returns true if this fighter has sufficient energy to attack.
         */
        bool attack_usable(int discount = 0) const noexcept {
            return 
                !effect_search(IMPAIR_EFFECT).size()
                && energy_value() >= attack.get_cost() - discount
            ;
        }
        
        /**
         * Returns true if this fighter has sufficient energy to retreat.
         */
        bool retreat_usable(int agility = 0) const noexcept {
            return
                !effect_search(CRIPPLE_EFFECT).size()
                && !effect_search(ROOT_EFFECT).size()
                && energy_value() >= retreat_cost - effect_count(AGILITY_EFFECT) - agility
            ;
        }
        
        /**
         * Returns the effects of the ability.
         */
        const std::vector<std::vector<std::string>>& get_ability_effects() const noexcept {
            return ability.get_effects();
        }
        
        /**
         * Returns the name of the ability.
         */
        const std::string& get_ability_name() const noexcept {
            return ability.get_name();
        }
        
        /**
         * Clears the effects on the fighter, but not its ability.
         */
        void clear_effects() noexcept {
            effects.clear();
        }
        
        /**
         * Increments the number of uses of the ability.
         */
        void use_ability() noexcept {
            ability.use();
        }
        
        /**
         * Returns a pointer to the vector of strings matching the given effect.
         * Returns the null pointer if the effect was not found.
         * This member function consider the effects of the ability, as well.
         */
        std::vector<std::vector<std::string>> effect_search(
            const std::string& effect
        ) const noexcept {
            std::vector<std::vector<std::string>> filtered;
            
            // Passive abilities are searched.
            if (ability.is_passive()) {
                filtered = ability.effect_search(effect);
            }
            
            // The effect is searched for.
            for (int i = 0; i < effects.size(); ++i) {
                // Matching effects are added to the filtered effects.
                if (effects[i][0] == effect) {
                    filtered.push_back(effects[i]);
                }
            }
            
            // The filtered effects are returned.
            return filtered;
        }
        
        /**
         * Counts the total effect value of an effect.
         * The member function also considers the effects of passive abilities.
         */
        int effect_count(const std::string& effect) const noexcept {
            int count = 0;
            
            for (int i = 0; i < effects.size(); ++i) {
                if (effects[i][0] == effect) {
                    count += std::stoi(effects[i][1]);
                }
            }
            
            if (ability.is_passive()) {
                count += ability.effect_count(effect);
            }
            
            return count;
        }
        
        /**
         * Calculates the total energy value of this fighter.
         */
        int energy_value() const noexcept {
            // The total amount of usable energy attached to the fighter.
            int total = 0;
            
            // The total energy value is calculated.
            for (int i = 0; i < energy.size(); ++i) {
                total += energy_value(i);
            }
            
            // The total energy value is returned.
            return total;
        }
        
        /**
         * Gives the value of the specific energy card.
         */
        int energy_value(int index) const noexcept {
            // If the fighter can use energy of any element,
            //   the energy's base value is returned.
            if (effect_search(ADAPTABILITY_EFFECT).size()) {
                return energy[index].get_value();
            }
            
            // Else, the energy's value with respect to the
            //   fighter's element and affinities is returned.
            else {
                // The maximum value of the energy card is found.
                int max_energy = energy[index].get_value(element);
                
                // The elemental affinities of the fighter are extracted.
                std::vector<std::vector<std::string>> affinities(
                    effect_search(
                        AFFINITY_EFFECT
                    )
                );
                
                // The affinities are checked for a greater energy value.
                for (int i = 0; i < affinities.size(); ++i) {
                    int potential_max = energy[index].get_value(affinities[i][1]);
                    
                    if (max_energy < potential_max) {
                        max_energy = potential_max;
                    }
                }
                
                // The maximum energy value is returned.
                return max_energy;
            }
        }
        
        /**
         * Returns a constant reference to the fighter's ability.
         */
        const Ability& get_ability() const noexcept {
            return ability;
        }
        
        /**
         * Returns a constant reference to the fighter's attack.
         */
        const Attack& get_attack() const noexcept {
            return attack;
        }
        
        /**
         * Deals damage to this fighter.
         * Returns the actual amount of damage dealt.
         */
        int damage(int amount) noexcept {
            // The fighter should not be healed by negative damage.
            if (amount < 0 || effect_search(INVINCIBILITY_EFFECT).size()) {
                amount = 0;
            }
            
            // The fighter's health should not be made negative.
            else if (amount > health) {
                amount = health;
            }
            
            // The damage is dealt.
            health -= amount;
            
            // The actual damage dealt is returned.
            return amount;
        }
        
        /**
         * Returns a constant reference to the vector of energy cards.
         */
        const std::vector<Energy>& get_energy() const noexcept {
            return energy;
        }
        
        /**
         * Returns the health of the fighter.
         */
        int get_health() const noexcept {
            return health;
        }
        
        /**
         * Heals the fighter according the passed argument.
         * The fighter's health cannot exceed its maximum health.
         * The fighter's health is not decreased with negative heals.
         * Returns the actual damage healed.
         */
        int heal(int heal_value) noexcept {
            // Heals must increase the fighter's health.
            if (heal_value < 0) {
                heal_value = 0;
            }
            
            // Heals cannot go past the fighter's maximum health.
            else if (heal_value > max_health - health) {
                heal_value = max_health - health;
            }
            
            // The healing is performed.
            health += heal_value;
            
            // The actual damage healed is returned.
            return heal_value;
        }
        
        /**
         * Chooses an energy card attached to the fighter and returns the index.
         */
        int choose_energy(
            Display& display,
            const Renderer& renderer,
            const Button& back_button
        ) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The energy size sprite is intialised.
            Sprite energy_size_sprite(
                renderer.render(
                    ENERGY_SIZE_STRING,
                    ENERGY_SIZE_WIDTH * display.width(),
                    ENERGY_SIZE_HEIGHT * display.height(),
                    ENERGY_SIZE_SEPARATION * display.width()
                )
            );
            
            // The choice buttons are initialised.
            std::vector<Button> choice_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                choice_buttons.push_back(
                    Button(
                        renderer.render(
                            display,
                            CHOICE_STRING,
                            CHOICE_WIDTH,
                            CHOICE_HEIGHT,
                            CHOICE_SEPARATION
                        ),
                        display,
                        CHOICE_X,
                        CHOICE_Y + i * CHOICE_Y_SHIFT
                    )
                );
            }
            
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                display.blit(energy_size_sprite, ENERGY_SIZE_X, ENERGY_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (static_cast<int>(energy.size())  - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < energy.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    energy[page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The value of the energy card is displayed.
                    choice_buttons[i].blit_to(display);
                }
                
                // The total value of the energy cards attached is calculated.
                int total = energy_value();
                
                // The total value of the energy is rendered.
                display.blit(
                    renderer.render(
                        display,
                        TOTAL_ENERGY_STRING,
                        TOTAL_ENERGY_WIDTH,
                        TOTAL_ENERGY_HEIGHT,
                        TOTAL_ENERGY_SEPARATION
                    ),
                    TOTAL_ENERGY_X,
                    TOTAL_ENERGY_Y
                );
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (static_cast<int>(energy.size()) - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < energy.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                energy[page * PAGE_COUNT + i].render(display, renderer);
                                back_button.blit_to(display);
                                display.update();
                                
                                // The player proceeds at their own discretion.
                                while (
                                    !Events::unpress(QUIT_KEY)
                                    && !Events::unpress(NEXT_KEY)
                                    && !back_button.get_rectangle().unclick()
                                ) {
                                    Events::update();
                                }
                                
                                found = true;
                                break;
                            }
                            
                            // Returns the chosen energy card's index.
                            else if (choice_buttons[i].get_rectangle().unclick()) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Removes and returns energy at the given index.
         */
        Energy remove_energy(int index) noexcept {
            Energy e(energy[index]);
            energy.erase(energy.cbegin() + index);
            return e;
        }
        
        /**
         * Removes and returns all of the energy attached to the fighter.
         */
        std::vector<Energy> remove_energy() noexcept {
            std::vector<Energy> e(energy);
            energy.clear();
            return e;
        }
        
        /**
         * Restores the fighter to full health.
         */
        void full_heal() noexcept {
            health = max_health;
        }
        
        /**
         * Returns the difference between the current and maximum health.
         */
        int max_healing() const noexcept {
            return max_health - health;
        }
        
        /**
         * Returns true if any of the attached energy cards has the given effect.
         */
        bool energy_effect_search(const std::string& effect) const noexcept {
            for (int i = 0; i < energy.size(); ++i) {
                if (energy[i].effect_search(effect).size()) {
                    return true;
                }
            }
            
            return false;
        }
        
        /**
         * Defeats the fighter by setting its health to zero.
         */
        void defeat() noexcept {
            health = 0;
        }
        
        /**
         * Returns this fighter's maximum health total.
         */
        int get_max_health() const noexcept {
            return max_health;
        }
        
    private:
        std::string element; // Determines which energy can power this fighter's attacks.
        int health; // When this reaches zero (or less), the fighter is defeated.
        int max_health; // The fighter's health cannot exceed this.
        int retreat_cost; // The energy value required for a retreat.
        std::string old_rank; // The fighter that this one ranks up from.
        Ability ability; // The fighter's ability.
        Attack attack; // The fighter's attack.
        std::vector<Energy> energy; // The energy attached to the fighter.
};
//}

// Cards
//{
// Fighters
//{
// Driver Family
//{
// Fire Driver Family
//{
const Fighter DRIVER(
    DRIVER_NAME,
    DRIVER_ELEMENT,
    DRIVER_HEALTH,
    DRIVER_RETREAT_COST,
    DRIVER_OLD_RANK,
    DRIVER_ABILITY_NAME,
    DRIVER_ABILITY_DESCRIPTION,
    DRIVER_ABILITY_EFFECTS,
    DRIVER_ABILITY_PASSIVE,
    DRIVER_ABILITY_USES,
    DRIVER_ATTACK_NAME,
    DRIVER_ATTACK_DESCRIPTION,
    DRIVER_ATTACK_EFFECTS,
    DRIVER_ATTACK_DAMAGE,
    DRIVER_ATTACK_COST
);

const Fighter RACER(
    RACER_NAME,
    RACER_ELEMENT,
    RACER_HEALTH,
    RACER_RETREAT_COST,
    RACER_OLD_RANK,
    RACER_ABILITY_NAME,
    RACER_ABILITY_DESCRIPTION,
    RACER_ABILITY_EFFECTS,
    RACER_ABILITY_PASSIVE,
    RACER_ABILITY_USES,
    RACER_ATTACK_NAME,
    RACER_ATTACK_DESCRIPTION,
    RACER_ATTACK_EFFECTS,
    RACER_ATTACK_DAMAGE,
    RACER_ATTACK_COST
);

const Fighter HOT_RODDER(
    HOT_RODDER_NAME,
    HOT_RODDER_ELEMENT,
    HOT_RODDER_HEALTH,
    HOT_RODDER_RETREAT_COST,
    HOT_RODDER_OLD_RANK,
    HOT_RODDER_ABILITY_NAME,
    HOT_RODDER_ABILITY_DESCRIPTION,
    HOT_RODDER_ABILITY_EFFECTS,
    HOT_RODDER_ABILITY_PASSIVE,
    HOT_RODDER_ABILITY_USES,
    HOT_RODDER_ATTACK_NAME,
    HOT_RODDER_ATTACK_DESCRIPTION,
    HOT_RODDER_ATTACK_EFFECTS,
    HOT_RODDER_ATTACK_DAMAGE,
    HOT_RODDER_ATTACK_COST
);
//}

// Water Driver Family
//{
const Fighter SAILOR(
    SAILOR_NAME,
    SAILOR_ELEMENT,
    SAILOR_HEALTH,
    SAILOR_RETREAT_COST,
    SAILOR_OLD_RANK,
    SAILOR_ABILITY_NAME,
    SAILOR_ABILITY_DESCRIPTION,
    SAILOR_ABILITY_EFFECTS,
    SAILOR_ABILITY_PASSIVE,
    SAILOR_ABILITY_USES,
    SAILOR_ATTACK_NAME,
    SAILOR_ATTACK_DESCRIPTION,
    SAILOR_ATTACK_EFFECTS,
    SAILOR_ATTACK_DAMAGE,
    SAILOR_ATTACK_COST
);

const Fighter PIRATE(
    PIRATE_NAME,
    PIRATE_ELEMENT,
    PIRATE_HEALTH,
    PIRATE_RETREAT_COST,
    PIRATE_OLD_RANK,
    PIRATE_ABILITY_NAME,
    PIRATE_ABILITY_DESCRIPTION,
    PIRATE_ABILITY_EFFECTS,
    PIRATE_ABILITY_PASSIVE,
    PIRATE_ABILITY_USES,
    PIRATE_ATTACK_NAME,
    PIRATE_ATTACK_DESCRIPTION,
    PIRATE_ATTACK_EFFECTS,
    PIRATE_ATTACK_DAMAGE,
    PIRATE_ATTACK_COST
);
//}

// Earth Driver
//{
const Fighter DIRT_BIKER(
    DIRT_BIKER_NAME,
    DIRT_BIKER_ELEMENT,
    DIRT_BIKER_HEALTH,
    DIRT_BIKER_RETREAT_COST,
    DIRT_BIKER_OLD_RANK,
    DIRT_BIKER_ABILITY_NAME,
    DIRT_BIKER_ABILITY_DESCRIPTION,
    DIRT_BIKER_ABILITY_EFFECTS,
    DIRT_BIKER_ABILITY_PASSIVE,
    DIRT_BIKER_ABILITY_USES,
    DIRT_BIKER_ATTACK_NAME,
    DIRT_BIKER_ATTACK_DESCRIPTION,
    DIRT_BIKER_ATTACK_EFFECTS,
    DIRT_BIKER_ATTACK_DAMAGE,
    DIRT_BIKER_ATTACK_COST
);

const Fighter MONSTER_TRUCKER(
    MONSTER_TRUCKER_NAME,
    MONSTER_TRUCKER_ELEMENT,
    MONSTER_TRUCKER_HEALTH,
    MONSTER_TRUCKER_RETREAT_COST,
    MONSTER_TRUCKER_OLD_RANK,
    MONSTER_TRUCKER_ABILITY_NAME,
    MONSTER_TRUCKER_ABILITY_DESCRIPTION,
    MONSTER_TRUCKER_ABILITY_EFFECTS,
    MONSTER_TRUCKER_ABILITY_PASSIVE,
    MONSTER_TRUCKER_ABILITY_USES,
    MONSTER_TRUCKER_ATTACK_NAME,
    MONSTER_TRUCKER_ATTACK_DESCRIPTION,
    MONSTER_TRUCKER_ATTACK_EFFECTS,
    MONSTER_TRUCKER_ATTACK_DAMAGE,
    MONSTER_TRUCKER_ATTACK_COST
);
//}

// Air Energy
//{
const Fighter PILOT(
    PILOT_NAME,
    PILOT_ELEMENT,
    PILOT_HEALTH,
    PILOT_RETREAT_COST,
    PILOT_OLD_RANK,
    PILOT_ABILITY_NAME,
    PILOT_ABILITY_DESCRIPTION,
    PILOT_ABILITY_EFFECTS,
    PILOT_ABILITY_PASSIVE,
    PILOT_ABILITY_USES,
    PILOT_ATTACK_NAME,
    PILOT_ATTACK_DESCRIPTION,
    PILOT_ATTACK_EFFECTS,
    PILOT_ATTACK_DAMAGE,
    PILOT_ATTACK_COST
);

const Fighter ASTRONAUT(
    ASTRONAUT_NAME,
    ASTRONAUT_ELEMENT,
    ASTRONAUT_HEALTH,
    ASTRONAUT_RETREAT_COST,
    ASTRONAUT_OLD_RANK,
    ASTRONAUT_ABILITY_NAME,
    ASTRONAUT_ABILITY_DESCRIPTION,
    ASTRONAUT_ABILITY_EFFECTS,
    ASTRONAUT_ABILITY_PASSIVE,
    ASTRONAUT_ABILITY_USES,
    ASTRONAUT_ATTACK_NAME,
    ASTRONAUT_ATTACK_DESCRIPTION,
    ASTRONAUT_ATTACK_EFFECTS,
    ASTRONAUT_ATTACK_DAMAGE,
    ASTRONAUT_ATTACK_COST
);
//}
//}

// Mage Family
//{
const Fighter MAGE(
    MAGE_NAME,
    MAGE_ELEMENT,
    MAGE_HEALTH,
    MAGE_RETREAT_COST,
    MAGE_OLD_RANK,
    MAGE_ABILITY_NAME,
    MAGE_ABILITY_DESCRIPTION,
    MAGE_ABILITY_EFFECTS,
    MAGE_ABILITY_PASSIVE,
    MAGE_ABILITY_USES,
    MAGE_ATTACK_NAME,
    MAGE_ATTACK_DESCRIPTION,
    MAGE_ATTACK_EFFECTS,
    MAGE_ATTACK_DAMAGE,
    MAGE_ATTACK_COST
);

const Fighter PYROMANCER(
    PYROMANCER_NAME,
    PYROMANCER_ELEMENT,
    PYROMANCER_HEALTH,
    PYROMANCER_RETREAT_COST,
    PYROMANCER_OLD_RANK,
    PYROMANCER_ABILITY_NAME,
    PYROMANCER_ABILITY_DESCRIPTION,
    PYROMANCER_ABILITY_EFFECTS,
    PYROMANCER_ABILITY_PASSIVE,
    PYROMANCER_ABILITY_USES,
    PYROMANCER_ATTACK_NAME,
    PYROMANCER_ATTACK_DESCRIPTION,
    PYROMANCER_ATTACK_EFFECTS,
    PYROMANCER_ATTACK_DAMAGE,
    PYROMANCER_ATTACK_COST
);

const Fighter WARLOCK(
    WARLOCK_NAME,
    WARLOCK_ELEMENT,
    WARLOCK_HEALTH,
    WARLOCK_RETREAT_COST,
    WARLOCK_OLD_RANK,
    WARLOCK_ABILITY_NAME,
    WARLOCK_ABILITY_DESCRIPTION,
    WARLOCK_ABILITY_EFFECTS,
    WARLOCK_ABILITY_PASSIVE,
    WARLOCK_ABILITY_USES,
    WARLOCK_ATTACK_NAME,
    WARLOCK_ATTACK_DESCRIPTION,
    WARLOCK_ATTACK_EFFECTS,
    WARLOCK_ATTACK_DAMAGE,
    WARLOCK_ATTACK_COST
);

const Fighter CLERIC(
    CLERIC_NAME,
    CLERIC_ELEMENT,
    CLERIC_HEALTH,
    CLERIC_RETREAT_COST,
    CLERIC_OLD_RANK,
    CLERIC_ABILITY_NAME,
    CLERIC_ABILITY_DESCRIPTION,
    CLERIC_ABILITY_EFFECTS,
    CLERIC_ABILITY_PASSIVE,
    CLERIC_ABILITY_USES,
    CLERIC_ATTACK_NAME,
    CLERIC_ATTACK_DESCRIPTION,
    CLERIC_ATTACK_EFFECTS,
    CLERIC_ATTACK_DAMAGE,
    CLERIC_ATTACK_COST
);

const Fighter HYDROMANCER(
    HYDROMANCER_NAME,
    HYDROMANCER_ELEMENT,
    HYDROMANCER_HEALTH,
    HYDROMANCER_RETREAT_COST,
    HYDROMANCER_OLD_RANK,
    HYDROMANCER_ABILITY_NAME,
    HYDROMANCER_ABILITY_DESCRIPTION,
    HYDROMANCER_ABILITY_EFFECTS,
    HYDROMANCER_ABILITY_PASSIVE,
    HYDROMANCER_ABILITY_USES,
    HYDROMANCER_ATTACK_NAME,
    HYDROMANCER_ATTACK_DESCRIPTION,
    HYDROMANCER_ATTACK_EFFECTS,
    HYDROMANCER_ATTACK_DAMAGE,
    HYDROMANCER_ATTACK_COST
);
//}

// Ranker Family
//{
// Miner Family
//{
const Fighter MINER(
    MINER_NAME,
    MINER_ELEMENT,
    MINER_HEALTH,
    MINER_RETREAT_COST,
    MINER_OLD_RANK,
    MINER_ABILITY_NAME,
    MINER_ABILITY_DESCRIPTION,
    MINER_ABILITY_EFFECTS,
    MINER_ABILITY_PASSIVE,
    MINER_ABILITY_USES,
    MINER_ATTACK_NAME,
    MINER_ATTACK_DESCRIPTION,
    MINER_ATTACK_EFFECTS,
    MINER_ATTACK_DAMAGE,
    MINER_ATTACK_COST
);

const Fighter EXCAVATOR(
    EXCAVATOR_NAME,
    EXCAVATOR_ELEMENT,
    EXCAVATOR_HEALTH,
    EXCAVATOR_RETREAT_COST,
    EXCAVATOR_OLD_RANK,
    EXCAVATOR_ABILITY_NAME,
    EXCAVATOR_ABILITY_DESCRIPTION,
    EXCAVATOR_ABILITY_EFFECTS,
    EXCAVATOR_ABILITY_PASSIVE,
    EXCAVATOR_ABILITY_USES,
    EXCAVATOR_ATTACK_NAME,
    EXCAVATOR_ATTACK_DESCRIPTION,
    EXCAVATOR_ATTACK_EFFECTS,
    EXCAVATOR_ATTACK_DAMAGE,
    EXCAVATOR_ATTACK_COST
);
//}

// Swimmer Family
//{
const Fighter SWIMMER(
    SWIMMER_NAME,
    SWIMMER_ELEMENT,
    SWIMMER_HEALTH,
    SWIMMER_RETREAT_COST,
    SWIMMER_OLD_RANK,
    SWIMMER_ABILITY_NAME,
    SWIMMER_ABILITY_DESCRIPTION,
    SWIMMER_ABILITY_EFFECTS,
    SWIMMER_ABILITY_PASSIVE,
    SWIMMER_ABILITY_USES,
    SWIMMER_ATTACK_NAME,
    SWIMMER_ATTACK_DESCRIPTION,
    SWIMMER_ATTACK_EFFECTS,
    SWIMMER_ATTACK_DAMAGE,
    SWIMMER_ATTACK_COST
);

const Fighter SCUBA_DIVER(
    SCUBA_DIVER_NAME,
    SCUBA_DIVER_ELEMENT,
    SCUBA_DIVER_HEALTH,
    SCUBA_DIVER_RETREAT_COST,
    SCUBA_DIVER_OLD_RANK,
    SCUBA_DIVER_ABILITY_NAME,
    SCUBA_DIVER_ABILITY_DESCRIPTION,
    SCUBA_DIVER_ABILITY_EFFECTS,
    SCUBA_DIVER_ABILITY_PASSIVE,
    SCUBA_DIVER_ABILITY_USES,
    SCUBA_DIVER_ATTACK_NAME,
    SCUBA_DIVER_ATTACK_DESCRIPTION,
    SCUBA_DIVER_ATTACK_EFFECTS,
    SCUBA_DIVER_ATTACK_DAMAGE,
    SCUBA_DIVER_ATTACK_COST
);
//}

// Welder Family
//{
const Fighter WELDER(
    WELDER_NAME,
    WELDER_ELEMENT,
    WELDER_HEALTH,
    WELDER_RETREAT_COST,
    WELDER_OLD_RANK,
    WELDER_ABILITY_NAME,
    WELDER_ABILITY_DESCRIPTION,
    WELDER_ABILITY_EFFECTS,
    WELDER_ABILITY_PASSIVE,
    WELDER_ABILITY_USES,
    WELDER_ATTACK_NAME,
    WELDER_ATTACK_DESCRIPTION,
    WELDER_ATTACK_EFFECTS,
    WELDER_ATTACK_DAMAGE,
    WELDER_ATTACK_COST
);

const Fighter PYROTECHNICIAN(
    PYROTECHNICIAN_NAME,
    PYROTECHNICIAN_ELEMENT,
    PYROTECHNICIAN_HEALTH,
    PYROTECHNICIAN_RETREAT_COST,
    PYROTECHNICIAN_OLD_RANK,
    PYROTECHNICIAN_ABILITY_NAME,
    PYROTECHNICIAN_ABILITY_DESCRIPTION,
    PYROTECHNICIAN_ABILITY_EFFECTS,
    PYROTECHNICIAN_ABILITY_PASSIVE,
    PYROTECHNICIAN_ABILITY_USES,
    PYROTECHNICIAN_ATTACK_NAME,
    PYROTECHNICIAN_ATTACK_DESCRIPTION,
    PYROTECHNICIAN_ATTACK_EFFECTS,
    PYROTECHNICIAN_ATTACK_DAMAGE,
    PYROTECHNICIAN_ATTACK_COST
);
//}

// Wind Runner Family
//{
const Fighter WIND_RUNNER(
    WIND_RUNNER_NAME,
    WIND_RUNNER_ELEMENT,
    WIND_RUNNER_HEALTH,
    WIND_RUNNER_RETREAT_COST,
    WIND_RUNNER_OLD_RANK,
    WIND_RUNNER_ABILITY_NAME,
    WIND_RUNNER_ABILITY_DESCRIPTION,
    WIND_RUNNER_ABILITY_EFFECTS,
    WIND_RUNNER_ABILITY_PASSIVE,
    WIND_RUNNER_ABILITY_USES,
    WIND_RUNNER_ATTACK_NAME,
    WIND_RUNNER_ATTACK_DESCRIPTION,
    WIND_RUNNER_ATTACK_EFFECTS,
    WIND_RUNNER_ATTACK_DAMAGE,
    WIND_RUNNER_ATTACK_COST
);

const Fighter CLOUD_SURFER(
    CLOUD_SURFER_NAME,
    CLOUD_SURFER_ELEMENT,
    CLOUD_SURFER_HEALTH,
    CLOUD_SURFER_RETREAT_COST,
    CLOUD_SURFER_OLD_RANK,
    CLOUD_SURFER_ABILITY_NAME,
    CLOUD_SURFER_ABILITY_DESCRIPTION,
    CLOUD_SURFER_ABILITY_EFFECTS,
    CLOUD_SURFER_ABILITY_PASSIVE,
    CLOUD_SURFER_ABILITY_USES,
    CLOUD_SURFER_ATTACK_NAME,
    CLOUD_SURFER_ATTACK_DESCRIPTION,
    CLOUD_SURFER_ATTACK_EFFECTS,
    CLOUD_SURFER_ATTACK_DAMAGE,
    CLOUD_SURFER_ATTACK_COST
);
//}
//}

// Unranked Family
//{
const Fighter BOXER(
    BOXER_NAME,
    BOXER_ELEMENT,
    BOXER_HEALTH,
    BOXER_RETREAT_COST,
    BOXER_OLD_RANK,
    BOXER_ABILITY_NAME,
    BOXER_ABILITY_DESCRIPTION,
    BOXER_ABILITY_EFFECTS,
    BOXER_ABILITY_PASSIVE,
    BOXER_ABILITY_USES,
    BOXER_ATTACK_NAME,
    BOXER_ATTACK_DESCRIPTION,
    BOXER_ATTACK_EFFECTS,
    BOXER_ATTACK_DAMAGE,
    BOXER_ATTACK_COST
);

const Fighter LOST_SOUL(
    LOST_SOUL_NAME,
    LOST_SOUL_ELEMENT,
    LOST_SOUL_HEALTH,
    LOST_SOUL_RETREAT_COST,
    LOST_SOUL_OLD_RANK,
    LOST_SOUL_ABILITY_NAME,
    LOST_SOUL_ABILITY_DESCRIPTION,
    LOST_SOUL_ABILITY_EFFECTS,
    LOST_SOUL_ABILITY_PASSIVE,
    LOST_SOUL_ABILITY_USES,
    LOST_SOUL_ATTACK_NAME,
    LOST_SOUL_ATTACK_DESCRIPTION,
    LOST_SOUL_ATTACK_EFFECTS,
    LOST_SOUL_ATTACK_DAMAGE,
    LOST_SOUL_ATTACK_COST
);
//}

// Void Family
//{
const Fighter BANISHER(
    BANISHER_NAME,
    BANISHER_ELEMENT,
    BANISHER_HEALTH,
    BANISHER_RETREAT_COST,
    BANISHER_OLD_RANK,
    BANISHER_ABILITY_NAME,
    BANISHER_ABILITY_DESCRIPTION,
    BANISHER_ABILITY_EFFECTS,
    BANISHER_ABILITY_PASSIVE,
    BANISHER_ABILITY_USES,
    BANISHER_ATTACK_NAME,
    BANISHER_ATTACK_DESCRIPTION,
    BANISHER_ATTACK_EFFECTS,
    BANISHER_ATTACK_DAMAGE,
    BANISHER_ATTACK_COST
);

const Fighter BANSHEE(
    BANSHEE_NAME,
    BANSHEE_ELEMENT,
    BANSHEE_HEALTH,
    BANSHEE_RETREAT_COST,
    BANSHEE_OLD_RANK,
    BANSHEE_ABILITY_NAME,
    BANSHEE_ABILITY_DESCRIPTION,
    BANSHEE_ABILITY_EFFECTS,
    BANSHEE_ABILITY_PASSIVE,
    BANSHEE_ABILITY_USES,
    BANSHEE_ATTACK_NAME,
    BANSHEE_ATTACK_DESCRIPTION,
    BANSHEE_ATTACK_EFFECTS,
    BANSHEE_ATTACK_DAMAGE,
    BANSHEE_ATTACK_COST
);

const Fighter CULTIST(
    CULTIST_NAME,
    CULTIST_ELEMENT,
    CULTIST_HEALTH,
    CULTIST_RETREAT_COST,
    CULTIST_OLD_RANK,
    CULTIST_ABILITY_NAME,
    CULTIST_ABILITY_DESCRIPTION,
    CULTIST_ABILITY_EFFECTS,
    CULTIST_ABILITY_PASSIVE,
    CULTIST_ABILITY_USES,
    CULTIST_ATTACK_NAME,
    CULTIST_ATTACK_DESCRIPTION,
    CULTIST_ATTACK_EFFECTS,
    CULTIST_ATTACK_DAMAGE,
    CULTIST_ATTACK_COST
);
//}

// Apprentice Family
//{
const Fighter APPRENTICE(
    APPRENTICE_NAME,
    APPRENTICE_ELEMENT,
    APPRENTICE_HEALTH,
    APPRENTICE_RETREAT_COST,
    APPRENTICE_OLD_RANK,
    APPRENTICE_ABILITY_NAME,
    APPRENTICE_ABILITY_DESCRIPTION,
    APPRENTICE_ABILITY_EFFECTS,
    APPRENTICE_ABILITY_PASSIVE,
    APPRENTICE_ABILITY_USES,
    APPRENTICE_ATTACK_NAME,
    APPRENTICE_ATTACK_DESCRIPTION,
    APPRENTICE_ATTACK_EFFECTS,
    APPRENTICE_ATTACK_DAMAGE,
    APPRENTICE_ATTACK_COST
);

const Fighter SENSEIS_CHOSEN(
    SENSEIS_CHOSEN_NAME,
    SENSEIS_CHOSEN_ELEMENT,
    SENSEIS_CHOSEN_HEALTH,
    SENSEIS_CHOSEN_RETREAT_COST,
    SENSEIS_CHOSEN_OLD_RANK,
    SENSEIS_CHOSEN_ABILITY_NAME,
    SENSEIS_CHOSEN_ABILITY_DESCRIPTION,
    SENSEIS_CHOSEN_ABILITY_EFFECTS,
    SENSEIS_CHOSEN_ABILITY_PASSIVE,
    SENSEIS_CHOSEN_ABILITY_USES,
    SENSEIS_CHOSEN_ATTACK_NAME,
    SENSEIS_CHOSEN_ATTACK_DESCRIPTION,
    SENSEIS_CHOSEN_ATTACK_EFFECTS,
    SENSEIS_CHOSEN_ATTACK_DAMAGE,
    SENSEIS_CHOSEN_ATTACK_COST
);

const Fighter NINJA(
    NINJA_NAME,
    NINJA_ELEMENT,
    NINJA_HEALTH,
    NINJA_RETREAT_COST,
    NINJA_OLD_RANK,
    NINJA_ABILITY_NAME,
    NINJA_ABILITY_DESCRIPTION,
    NINJA_ABILITY_EFFECTS,
    NINJA_ABILITY_PASSIVE,
    NINJA_ABILITY_USES,
    NINJA_ATTACK_NAME,
    NINJA_ATTACK_DESCRIPTION,
    NINJA_ATTACK_EFFECTS,
    NINJA_ATTACK_DAMAGE,
    NINJA_ATTACK_COST
);

const Fighter SAMURAI(
    SAMURAI_NAME,
    SAMURAI_ELEMENT,
    SAMURAI_HEALTH,
    SAMURAI_RETREAT_COST,
    SAMURAI_OLD_RANK,
    SAMURAI_ABILITY_NAME,
    SAMURAI_ABILITY_DESCRIPTION,
    SAMURAI_ABILITY_EFFECTS,
    SAMURAI_ABILITY_PASSIVE,
    SAMURAI_ABILITY_USES,
    SAMURAI_ATTACK_NAME,
    SAMURAI_ATTACK_DESCRIPTION,
    SAMURAI_ATTACK_EFFECTS,
    SAMURAI_ATTACK_DAMAGE,
    SAMURAI_ATTACK_COST
);
//}

// Elemental Family
//{
const Fighter FIRE_ELEMENTAL(
    FIRE_ELEMENTAL_NAME,
    FIRE_ELEMENTAL_ELEMENT,
    FIRE_ELEMENTAL_HEALTH,
    FIRE_ELEMENTAL_RETREAT_COST,
    FIRE_ELEMENTAL_OLD_RANK,
    FIRE_ELEMENTAL_ABILITY_NAME,
    FIRE_ELEMENTAL_ABILITY_DESCRIPTION,
    FIRE_ELEMENTAL_ABILITY_EFFECTS,
    FIRE_ELEMENTAL_ABILITY_PASSIVE,
    FIRE_ELEMENTAL_ABILITY_USES,
    FIRE_ELEMENTAL_ATTACK_NAME,
    FIRE_ELEMENTAL_ATTACK_DESCRIPTION,
    FIRE_ELEMENTAL_ATTACK_EFFECTS,
    FIRE_ELEMENTAL_ATTACK_DAMAGE,
    FIRE_ELEMENTAL_ATTACK_COST
);

const Fighter AIR_ELEMENTAL(
    AIR_ELEMENTAL_NAME,
    AIR_ELEMENTAL_ELEMENT,
    AIR_ELEMENTAL_HEALTH,
    AIR_ELEMENTAL_RETREAT_COST,
    AIR_ELEMENTAL_OLD_RANK,
    AIR_ELEMENTAL_ABILITY_NAME,
    AIR_ELEMENTAL_ABILITY_DESCRIPTION,
    AIR_ELEMENTAL_ABILITY_EFFECTS,
    AIR_ELEMENTAL_ABILITY_PASSIVE,
    AIR_ELEMENTAL_ABILITY_USES,
    AIR_ELEMENTAL_ATTACK_NAME,
    AIR_ELEMENTAL_ATTACK_DESCRIPTION,
    AIR_ELEMENTAL_ATTACK_EFFECTS,
    AIR_ELEMENTAL_ATTACK_DAMAGE,
    AIR_ELEMENTAL_ATTACK_COST
);

const Fighter WATER_ELEMENTAL(
    WATER_ELEMENTAL_NAME,
    WATER_ELEMENTAL_ELEMENT,
    WATER_ELEMENTAL_HEALTH,
    WATER_ELEMENTAL_RETREAT_COST,
    WATER_ELEMENTAL_OLD_RANK,
    WATER_ELEMENTAL_ABILITY_NAME,
    WATER_ELEMENTAL_ABILITY_DESCRIPTION,
    WATER_ELEMENTAL_ABILITY_EFFECTS,
    WATER_ELEMENTAL_ABILITY_PASSIVE,
    WATER_ELEMENTAL_ABILITY_USES,
    WATER_ELEMENTAL_ATTACK_NAME,
    WATER_ELEMENTAL_ATTACK_DESCRIPTION,
    WATER_ELEMENTAL_ATTACK_EFFECTS,
    WATER_ELEMENTAL_ATTACK_DAMAGE,
    WATER_ELEMENTAL_ATTACK_COST
);

const Fighter EARTH_ELEMENTAL(
    EARTH_ELEMENTAL_NAME,
    EARTH_ELEMENTAL_ELEMENT,
    EARTH_ELEMENTAL_HEALTH,
    EARTH_ELEMENTAL_RETREAT_COST,
    EARTH_ELEMENTAL_OLD_RANK,
    EARTH_ELEMENTAL_ABILITY_NAME,
    EARTH_ELEMENTAL_ABILITY_DESCRIPTION,
    EARTH_ELEMENTAL_ABILITY_EFFECTS,
    EARTH_ELEMENTAL_ABILITY_PASSIVE,
    EARTH_ELEMENTAL_ABILITY_USES,
    EARTH_ELEMENTAL_ATTACK_NAME,
    EARTH_ELEMENTAL_ATTACK_DESCRIPTION,
    EARTH_ELEMENTAL_ATTACK_EFFECTS,
    EARTH_ELEMENTAL_ATTACK_DAMAGE,
    EARTH_ELEMENTAL_ATTACK_COST
);

const Fighter OMEGA_ELEMENTAL(
    OMEGA_ELEMENTAL_NAME,
    OMEGA_ELEMENTAL_ELEMENT,
    OMEGA_ELEMENTAL_HEALTH,
    OMEGA_ELEMENTAL_RETREAT_COST,
    OMEGA_ELEMENTAL_OLD_RANK,
    OMEGA_ELEMENTAL_ABILITY_NAME,
    OMEGA_ELEMENTAL_ABILITY_DESCRIPTION,
    OMEGA_ELEMENTAL_ABILITY_EFFECTS,
    OMEGA_ELEMENTAL_ABILITY_PASSIVE,
    OMEGA_ELEMENTAL_ABILITY_USES,
    OMEGA_ELEMENTAL_ATTACK_NAME,
    OMEGA_ELEMENTAL_ATTACK_DESCRIPTION,
    OMEGA_ELEMENTAL_ATTACK_EFFECTS,
    OMEGA_ELEMENTAL_ATTACK_DAMAGE,
    OMEGA_ELEMENTAL_ATTACK_COST
);
//}

constexpr int FIGHTER_COUNT = 36;
const Fighter* const ALL_FIGHTERS[FIGHTER_COUNT] = {
    &DRIVER,
    &RACER,
    &HOT_RODDER,
    &SAILOR,
    &PIRATE,
    &DIRT_BIKER,
    &MONSTER_TRUCKER,
    &PILOT,
    &ASTRONAUT,
    &MAGE,
    &PYROMANCER,
    &WARLOCK,
    &CLERIC,
    &HYDROMANCER,
    &MINER,
    &EXCAVATOR,
    &SWIMMER,
    &SCUBA_DIVER,
    &WELDER,
    &PYROTECHNICIAN,
    &WIND_RUNNER,
    &CLOUD_SURFER,
    &BOXER,
    &LOST_SOUL,
    &BANISHER,
    &BANSHEE,
    &CULTIST,
    &APPRENTICE,
    &SENSEIS_CHOSEN,
    &NINJA,
    &SAMURAI,
    &FIRE_ELEMENTAL,
    &AIR_ELEMENTAL,
    &WATER_ELEMENTAL,
    &EARTH_ELEMENTAL,
    &OMEGA_ELEMENTAL
};
//}

// Supporters
//{
// Draw
//{
const Supporter PROFESSOR(
    PROFESSOR_NAME,
    PROFESSOR_DESCRIPTION,
    PROFESSOR_EFFECTS
);

const Supporter LECTURER(
    LECTURER_NAME,
    LECTURER_DESCRIPTION,
    LECTURER_EFFECTS
);

const Supporter INVESTOR(
    INVESTOR_NAME,
    INVESTOR_DESCRIPTION,
    INVESTOR_EFFECTS
);

const Supporter RESEARCHER(
    RESEARCHER_NAME,
    RESEARCHER_DESCRIPTION,
    RESEARCHER_EFFECTS
);

const Supporter GAMBLER(
    GAMBLER_NAME,
    GAMBLER_DESCRIPTION,
    GAMBLER_EFFECTS
);

const Supporter RECRUITER(
    RECRUITER_NAME,
    RECRUITER_DESCRIPTION,
    RECRUITER_EFFECTS
);
//}

// Search
//{
const Supporter CHEF(
    CHEF_NAME,
    CHEF_DESCRIPTION,
    CHEF_EFFECTS
);

const Supporter TRADER(
    TRADER_NAME,
    TRADER_DESCRIPTION,
    TRADER_EFFECTS
);

const Supporter LIBRARIAN(
    LIBRARIAN_NAME,
    LIBRARIAN_DESCRIPTION,
    LIBRARIAN_EFFECTS
);

const Supporter EXPERIMENTER(
    EXPERIMENTER_NAME,
    EXPERIMENTER_DESCRIPTION,
    EXPERIMENTER_EFFECTS
);

const Supporter PERSONAL_TRAINER(
    PERSONAL_TRAINER_NAME,
    PERSONAL_TRAINER_DESCRIPTION,
    PERSONAL_TRAINER_EFFECTS
);

const Supporter SCAPEGOAT(
    SCAPEGOAT_NAME,
    SCAPEGOAT_DESCRIPTION,
    SCAPEGOAT_EFFECTS
);
//}

// Recycle
//{
const Supporter ELECTRICIAN(
    ELECTRICIAN_NAME,
    ELECTRICIAN_DESCRIPTION,
    ELECTRICIAN_EFFECTS
);

const Supporter ALCHEMIST(
    ALCHEMIST_NAME,
    ALCHEMIST_DESCRIPTION,
    ALCHEMIST_EFFECTS
);

const Supporter TIME_TRAVELLER(
    TIME_TRAVELLER_NAME,
    TIME_TRAVELLER_DESCRIPTION,
    TIME_TRAVELLER_EFFECTS
);

const Supporter BANKER(
    BANKER_NAME,
    BANKER_DESCRIPTION,
    BANKER_EFFECTS
);

const Supporter GLUTTON(
    GLUTTON_NAME,
    GLUTTON_DESCRIPTION,
    GLUTTON_EFFECTS
);
//}

// Switch
//{
const Supporter SUBSTITUTE(
    SUBSTITUTE_NAME,
    SUBSTITUTE_DESCRIPTION,
    SUBSTITUTE_EFFECTS
);

const Supporter BOUNTY_HUNTER(
    BOUNTY_HUNTER_NAME,
    BOUNTY_HUNTER_DESCRIPTION,
    BOUNTY_HUNTER_EFFECTS
);
//}

// Healing
//{
const Supporter NURSE(
    NURSE_NAME,
    NURSE_DESCRIPTION,
    NURSE_EFFECTS
);

const Supporter INNKEEPER(
    INNKEEPER_NAME,
    INNKEEPER_DESCRIPTION,
    INNKEEPER_EFFECTS
);

const Supporter MIRACLE_WORKER(
    MIRACLE_WORKER_NAME,
    MIRACLE_WORKER_DESCRIPTION,
    MIRACLE_WORKER_EFFECTS
);

const Supporter DOCTOR(
    DOCTOR_NAME,
    DOCTOR_DESCRIPTION,
    DOCTOR_EFFECTS
);

const Supporter ESCAPE_ARTIST(
    ESCAPE_ARTIST_NAME,
    ESCAPE_ARTIST_DESCRIPTION,
    ESCAPE_ARTIST_EFFECTS
);
//}

// Direct Damage
//{
const Supporter ASSASSIN(
    ASSASSIN_NAME,
    ASSASSIN_DESCRIPTION,
    ASSASSIN_EFFECTS
);

const Supporter SNIPER(
    SNIPER_NAME,
    SNIPER_DESCRIPTION,
    SNIPER_EFFECTS
);
//}

// Power
//{
const Supporter CHEERLEADER(
    CHEERLEADER_NAME,
    CHEERLEADER_DESCRIPTION,
    CHEERLEADER_EFFECTS
);

const Supporter ARMS_SMUGGLER(
    ARMS_SMUGGLER_NAME,
    ARMS_SMUGGLER_DESCRIPTION,
    ARMS_SMUGGLER_EFFECTS
);

const Supporter MANIAC(
    MANIAC_NAME,
    MANIAC_DESCRIPTION,
    MANIAC_EFFECTS
);
//}

// Disruption
//{
const Supporter PEACEMAKER(
    PEACEMAKER_NAME,
    PEACEMAKER_DESCRIPTION,
    PEACEMAKER_EFFECTS
);

const Supporter MATCHMAKER(
    MATCHMAKER_NAME,
    MATCHMAKER_DESCRIPTION,
    MATCHMAKER_EFFECTS
);

const Supporter PLUMBER(
    PLUMBER_NAME,
    PLUMBER_DESCRIPTION,
    PLUMBER_EFFECTS
);

const Supporter LOCKSMITH(
    LOCKSMITH_NAME,
    LOCKSMITH_DESCRIPTION,
    LOCKSMITH_EFFECTS
);

const Supporter LOCK_PICKER(
    LOCK_PICKER_NAME,
    LOCK_PICKER_DESCRIPTION,
    LOCK_PICKER_EFFECTS
);

const Supporter GATEKEEPER(
    GATEKEEPER_NAME,
    GATEKEEPER_DESCRIPTION,
    GATEKEEPER_EFFECTS
);

const Supporter MILLER(
    MILLER_NAME,
    MILLER_DESCRIPTION,
    MILLER_EFFECTS
);

const Supporter ARSONIST(
    ARSONIST_NAME,
    ARSONIST_DESCRIPTION,
    ARSONIST_EFFECTS
);
//}

constexpr int SUPPORTER_COUNT = 37;
const Supporter* const ALL_SUPPORTERS[SUPPORTER_COUNT] = {
    &PROFESSOR,
    &LECTURER,
    &INVESTOR,
    &RESEARCHER,
    &GAMBLER,
    &RECRUITER,
    &CHEF,
    &TRADER,
    &LIBRARIAN,
    &EXPERIMENTER,
    &PERSONAL_TRAINER,
    &SCAPEGOAT,
    &ELECTRICIAN,
    &ALCHEMIST,
    &TIME_TRAVELLER,
    &BANKER,
    &GLUTTON,
    &SUBSTITUTE,
    &BOUNTY_HUNTER,
    &NURSE,
    &INNKEEPER,
    &MIRACLE_WORKER,
    &DOCTOR,
    &ESCAPE_ARTIST,
    &ASSASSIN,
    &SNIPER,
    &CHEERLEADER,
    &ARMS_SMUGGLER,
    &MANIAC,
    &PEACEMAKER,
    &MATCHMAKER,
    &PLUMBER,
    &LOCKSMITH,
    &LOCK_PICKER,
    &GATEKEEPER,
    &MILLER,
    &ARSONIST
};
//}

// Energy
//{
// Basic Energy
//{
const Energy FIRE_ENERGY(
    FIRE_ENERGY_NAME,
    FIRE_ENERGY_DESCRIPTION,
    FIRE_ENERGY_ELEMENT,
    FIRE_ENERGY_EFFECTS,
    FIRE_ENERGY_VALUE
);

const Energy AIR_ENERGY(
    AIR_ENERGY_NAME,
    AIR_ENERGY_DESCRIPTION,
    AIR_ENERGY_ELEMENT,
    AIR_ENERGY_EFFECTS,
    AIR_ENERGY_VALUE
);

const Energy WATER_ENERGY(
    WATER_ENERGY_NAME,
    WATER_ENERGY_DESCRIPTION,
    WATER_ENERGY_ELEMENT,
    WATER_ENERGY_EFFECTS,
    WATER_ENERGY_VALUE
);

const Energy EARTH_ENERGY(
    EARTH_ENERGY_NAME,
    EARTH_ENERGY_DESCRIPTION,
    EARTH_ENERGY_ELEMENT,
    EARTH_ENERGY_EFFECTS,
    EARTH_ENERGY_VALUE
);
//}

// Special Energy
//{
const Energy VOID_ENERGY(
    VOID_ENERGY_NAME,
    VOID_ENERGY_DESCRIPTION,
    VOID_ENERGY_ELEMENT,
    VOID_ENERGY_EFFECTS,
    VOID_ENERGY_VALUE
);

const Energy UNIVERSAL_ENERGY(
    UNIVERSAL_ENERGY_NAME,
    UNIVERSAL_ENERGY_DESCRIPTION,
    UNIVERSAL_ENERGY_ELEMENT,
    UNIVERSAL_ENERGY_EFFECTS,
    UNIVERSAL_ENERGY_VALUE
);

const Energy ALPHA_ENERGY(
    ALPHA_ENERGY_NAME,
    ALPHA_ENERGY_DESCRIPTION,
    ALPHA_ENERGY_ELEMENT,
    ALPHA_ENERGY_EFFECTS,
    ALPHA_ENERGY_VALUE
);

const Energy OMEGA_ENERGY(
    OMEGA_ENERGY_NAME,
    OMEGA_ENERGY_DESCRIPTION,
    OMEGA_ENERGY_ELEMENT,
    OMEGA_ENERGY_EFFECTS,
    OMEGA_ENERGY_VALUE
);

const Energy BOND_ENERGY(
    BOND_ENERGY_NAME,
    BOND_ENERGY_DESCRIPTION,
    BOND_ENERGY_ELEMENT,
    BOND_ENERGY_EFFECTS,
    BOND_ENERGY_VALUE
);
//}

constexpr int ENERGY_COUNT = 8;
const Energy* const ALL_ENERGY[ENERGY_COUNT] = {
    &FIRE_ENERGY,
    &AIR_ENERGY,
    &WATER_ENERGY,
    &EARTH_ENERGY,
    &UNIVERSAL_ENERGY,
    &ALPHA_ENERGY,
    &OMEGA_ENERGY,
    &BOND_ENERGY
};
//}

constexpr int CARD_COUNT = FIGHTER_COUNT + SUPPORTER_COUNT + ENERGY_COUNT;
//}

// Complex Classes
//{
/**
 * A generic storage for any quantity of cards.
 */
class CardStore {
    public:
        /**
         * Constructs an empty card store.
         */
        CardStore() noexcept {}
        
        /**
         * Constructs a deck consisting of the cards passed (in the deck code).
         */
        CardStore(const std::string& deck_code) noexcept {
            std::stringstream stream(deck_code);
            
            // The fighter cards are initialised.
            for (int i = 0; i < FIGHTER_COUNT; ++i) {
                int count;
                stream >> count;
                
                for (int j = 0; j < count; ++j) {
                    fighters.push_back(*ALL_FIGHTERS[i]);
                }
            }
            
            // The supporter cards are intialised.
            for (int i = 0; i < SUPPORTER_COUNT; ++i) {
                int count;
                stream >> count;
                
                for (int j = 0; j < count; ++j) {
                    supporters.push_back(*ALL_SUPPORTERS[i]);
                }
            }
            
            // The energy cards are initialised.
            for (int i = 0; i < ENERGY_COUNT; ++i) {
                int count;
                stream >> count;
                
                for (int j = 0; j < count; ++j) {
                    energy.push_back(*ALL_ENERGY[i]);
                }
            }
        }
    
        /**
         * Returns a reference to the card at the given index.
         */
        Card& operator[](int index) noexcept {
            // If the index is in the fighter range, the fighter card is returned.
            if (index < fighters.size()) {
                return fighters[index];
            }
            
            else {
                index -= fighters.size();
                
                // If the index is in the supporter range,
                //   the supporter card is returned.
                if (index < supporters.size()) {
                    return supporters[index];
                }
                
                // If the index is in the energy range,
                //   the energy card is returned.
                else {
                    return energy[index - supporters.size()];
                }
            }
        }
    
        /**
         * Returns a constant reference to the card at the given index.
         */
        const Card& operator[](int index) const noexcept {
            // If the index is in the fighter range, the fighter card is returned.
            if (index < fighters.size()) {
                return fighters[index];
            }
            
            else {
                index -= fighters.size();
                
                // If the index is in the supporter range,
                //   the supporter card is returned.
                if (index < supporters.size()) {
                    return supporters[index];
                }
                
                // If the index is in the energy range,
                //   the energy card is returned.
                else {
                    return energy[index - supporters.size()];
                }
            }
        }
    
        /**
         * Returns the number of cards stored.
         */
        int size() const noexcept {
            return fighters.size() + supporters.size() + energy.size();
        }
        
        /**
         * Returns true if this is a valid starting hand.
         */
        bool valid() const noexcept {
            bool invalid = true;
            
            for (int i = 0; i < fighters.size(); ++i) {
                if (fighters[i].basic()) {
                    invalid = false;
                    break;
                }
            }
            
            return !invalid;
        }
        
        /**
         * Stores a fighter card in the store.
         */
        void store(const Fighter& f) noexcept {
            fighters.push_back(f);
        }
        
        /**
         * Stores a supporter card in the store.
         */
        void store(const Supporter& s) noexcept {
            supporters.push_back(s);
        }
        
        /**
         * Stores an energy card in the store.
         */
        void store(const Energy& e) noexcept {
            energy.push_back(e);
        }
        
        /**
         * Stores a card in the store.
         */
        void store(const Card& card) noexcept {
            // A fighter card is stored.
            if (card.get_type() == FIGHTER_TYPE) {
                store(static_cast<const Fighter&>(card));
            }
            
            // A supporter card is stored.
            else if (card.get_type() == SUPPORTER_TYPE) {
                store(static_cast<const Supporter&>(card));
            }
            
            // A energy card is stored.
            else {
                store(static_cast<const Energy&>(card));
            }
        }
        
        /**
         * Stores all of the energy cards in the vector.
         */
        void store(const std::vector<Energy>& e) noexcept {
            for (int i = 0; i < e.size(); ++i) {
                energy.push_back(e[i]);
            }
        }
        
        /**
         * Stores a card in the store.
         */
        void store(const std::unique_ptr<Card>& card) noexcept {
            store(*card);
        }
        
        /**
         * Moves all of the cards in the given store to this store.
         */
        void store(CardStore& card_store) noexcept {
            while (card_store.size()) {
                store(card_store.remove());
            }
        }
        
        /**
         * Removes the card at the specified index.
         */
        std::unique_ptr<Card> remove(int index = 0) {
            if (!size()) {
                throw std::runtime_error(EMPTY_CARD_STORE);
            }
            
            Card& card = operator[](index);
            std::unique_ptr<Card> card_pointer;
            
            if (card.get_type() == FIGHTER_TYPE) {
                card_pointer = std::make_unique<Fighter>(static_cast<Fighter&>(card));
            }
            
            else if (card.get_type() == SUPPORTER_TYPE) {
                card_pointer = std::make_unique<Supporter>(static_cast<Supporter&>(card));
            }
            
            else {
                card_pointer = std::make_unique<Energy>(static_cast<Energy&>(card));
            }
            
            // If the index is in the fighter range, the fighter card is erased.
            if (index < fighters.size()) {
                fighters.erase(fighters.cbegin() + index);
            }
            
            else {
                index -= fighters.size();
                
                // If the index is in the supporter range,
                //   the supporter card is erased.
                if (index < supporters.size()) {
                    supporters.erase(supporters.cbegin() + index);
                }
                
                // If the index is in the energy range,
                //   the energy card is erased.
                else {
                    energy.erase(energy.cbegin() + (index - supporters.size()));
                }
            }
            
            return card_pointer;
        }
        
        /**
         * Draws a random card.
         * The type of card can be specified or omitted.
         */
        template<typename Type = Card>
        std::unique_ptr<Card> draw(std::mt19937& generator) {
            // Draws a random card.
            if (std::is_same<Type, Card>::value) {
                if (!size()) {
                    throw std::runtime_error(EMPTY_CARD_STORE);
                }
            
                return remove(Random::get_int(generator, 0, size() - 1));
            }
            
            // Draws a random fighter card.
            else if (std::is_same<Type, Fighter>::value) {
                if (!fighters.size()) {
                    throw std::runtime_error(EMPTY_CARD_STORE);
                }
            
                return remove(Random::get_int(generator, 0, fighters.size() - 1));
            }
            
            // Draws a random supporter card.
            else if (std::is_same<Type, Supporter>::value) {
                if (!supporters.size()) {
                    throw std::runtime_error(EMPTY_CARD_STORE);
                }
                
                return remove(
                    Random::get_int(
                        generator,
                        fighters.size(),
                        fighters.size() + supporters.size() - 1
                    )
                );
            }
            
            // Draws a random energy card.
            else {
                if (!energy.size()) {
                    throw std::runtime_error(EMPTY_CARD_STORE);
                }
                
                return remove(
                    Random::get_int(
                        generator,
                        size() - energy.size(),
                        size() - 1
                    )
                );
            }
        }
        
        /**
         * Displays the card store's contents with various modes.
         */
        void view(
            Display& display,
            const Renderer& renderer,
            const std::string& message = EMPTY_MESSAGE
        ) const noexcept {
            // The back button is initialised.
            Button back_button(
                renderer.render(
                    BACK_STRING,
                    BACK_WIDTH * display.width(),
                    BACK_HEIGHT * display.height(),
                    BACK_SEPARATION * display.width()
                ),
                display,
                BACK_X,
                BACK_Y
            );
            
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The store size sprite is intialised.
            Sprite store_size_sprite(
                renderer.render(
                    STORE_SIZE_STRING,
                    STORE_SIZE_WIDTH * display.width(),
                    STORE_SIZE_HEIGHT * display.height(),
                    STORE_SIZE_SEPARATION * display.width()
                )
            );
            
            // Determines which cards are displayed.
            int page = 0;
            
            // True if the function should return.
            bool end = false;
            
            while (!end) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                display.blit(store_size_sprite, STORE_SIZE_X, STORE_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    operator[](page * PAGE_COUNT + i).get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The user can return to the previous menu with
                    //   the use of the back button or submit key.
                    if (
                        Events::unpress(SUBMIT_KEY)
                        || Events::unpress(QUIT_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                operator[](page * PAGE_COUNT + i).render(display, renderer);
                                back_button.blit_to(display);
                                display.update();
                                
                                // The player proceeds at their own discretion.
                                while (
                                    !Events::unpress(QUIT_KEY)
                                    && !Events::unpress(NEXT_KEY)
                                    && !back_button.get_rectangle().unclick()
                                    && message == EMPTY_MESSAGE
                                ) {
                                    Events::update();
                                }
                                
                                found = true;
                                break;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
    
        /**
         * Chooses a basic fighter in the store and returns its index.
         */
        int choose_basic(
            Display& display,
            const Renderer& renderer
        ) const noexcept {
            // The components of the display are extracted.
            Sprite& display_sprite = display.get_sprite();
            int display_width = display_sprite.get_width();
            int display_height = display_sprite.get_height();
            
            // The basic fighter sprite is initialised.
            Sprite basic_fighter_sprite(
                renderer.render(
                    BASIC_FIGHTER_STRING,
                    BASIC_FIGHTER_WIDTH * display_width,
                    BASIC_FIGHTER_HEIGHT * display_height,
                    BASIC_FIGHTER_SEPARATION * display_width
                )
            );
            
            // The back button is initialised.
            Button back_button(
                renderer.render(
                    BACK_STRING,
                    BACK_WIDTH * display_width,
                    BACK_HEIGHT * display_height,
                    BACK_SEPARATION * display_width
                ),
                display_sprite,
                BACK_X,
                BACK_Y
            );
            
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display_width,
                    LEFT_HEIGHT * display_height
                ),
                display_sprite,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display_width,
                    RIGHT_HEIGHT * display_height
                ),
                display_sprite,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The choice buttons are initialised.
            std::vector<Button> choice_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                choice_buttons.push_back(
                    Button(
                        renderer.render(
                            CHOICE_STRING,
                            CHOICE_WIDTH * display_width,
                            CHOICE_HEIGHT * display_height,
                            CHOICE_SEPARATION * display_width
                        ),
                        display_sprite,
                        CHOICE_X,
                        CHOICE_Y + i * CHOICE_Y_SHIFT
                    )
                );
            }
    
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display_sprite.fill();
                display_sprite.blit(
                    basic_fighter_sprite,
                    BASIC_FIGHTER_X,
                    BASIC_FIGHTER_Y
                );
                
                if (page > 0) {
                    left_button.blit_to(display_sprite);
                }
                
                if (page < (size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display_sprite);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            renderer.render(
                                operator[](page * PAGE_COUNT + i).get_name(),
                                PAGE_WIDTH * display_width,
                                PAGE_HEIGHT * display_height,
                                PAGE_SEPARATION * display_width
                            ),
                            display_sprite,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display_sprite);
                    
                    if (
                        page * PAGE_COUNT + i < fighters.size()
                        && static_cast<const Fighter&>(operator[](
                            page * PAGE_COUNT + i
                        )).basic()
                    ) {
                        choice_buttons[i].blit_to(display_sprite);
                    }
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT && page * PAGE_COUNT + i < size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                operator[](page * PAGE_COUNT + i).render(display, renderer);
                                back_button.blit_to(display_sprite);
                                display.update();
                                
                                while (
                                    !Events::unpress(QUIT_KEY)
                                    && !back_button.get_rectangle().unclick()
                                ) {
                                    Events::update();
                                }
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a fighter.
                            else if (
                                page * PAGE_COUNT + i < fighters.size()
                                && static_cast<const Fighter&>(operator[](
                                    page * PAGE_COUNT + i
                                )).basic()
                                && choice_buttons[i].get_rectangle().unclick()
                            ) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Displays the card store's size.
         */
        void view_size(Display& display, const Renderer& renderer) const noexcept {
            display.fill();
            display.blit(
                renderer.lined_render(
                    VIEW_SIZE_STRING,
                    VIEW_SIZE_WIDTH * display.width(),
                    VIEW_SIZE_HEIGHT * display.height(),
                    VIEW_SIZE_SEPARATION_X * display.width(),
                    VIEW_SIZE_MAX_WIDTH * display.width(),
                    VIEW_SIZE_SEPARATION_Y * display.height(),
                    VIEW_SIZE_JUSTIFICATION
                ),
                VIEW_SIZE_X,
                VIEW_SIZE_Y
            );
        }
        
        /**
         * Allows one to choose a card to play.
         * Returns the index of the card chosen to be played.
         */
        int play(
            Display& display,
            const Renderer& renderer,
            const Button& back_button,
            const std::string& message = EMPTY_MESSAGE
        ) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The store size sprite is intialised.
            Sprite store_size_sprite(
                renderer.render(
                    STORE_SIZE_STRING,
                    STORE_SIZE_WIDTH * display.width(),
                    STORE_SIZE_HEIGHT * display.height(),
                    STORE_SIZE_SEPARATION * display.width()
                )
            );
            
            // The play buttons are initialised.
            std::vector<Button> play_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                play_buttons.push_back(
                    Button(
                        renderer.render(
                            display,
                            PLAY_CARD_STRING,
                            PLAY_CARD_WIDTH,
                            PLAY_CARD_HEIGHT,
                            PLAY_CARD_SEPARATION
                        ),
                        display,
                        PLAY_CARD_X,
                        PLAY_CARD_Y + i * PLAY_CARD_Y_SHIFT
                    )
                );
            }
            
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                display.blit(store_size_sprite, STORE_SIZE_X, STORE_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            renderer.render(
                                operator[](page * PAGE_COUNT + i).get_name(),
                                PAGE_WIDTH * display.width(),
                                PAGE_HEIGHT * display.height(),
                                PAGE_SEPARATION * display.width()
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The corresponding play button is displayed.
                    play_buttons[i].blit_to(display);
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The player can go back with the back button.
                    // Receiving a message also moves the player back.
                    if (
                        Events::unpress(BACK_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        return NO_CHOICE;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT && page * PAGE_COUNT + i < size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                operator[](page * PAGE_COUNT + i).render(display, renderer);
                                back_button.blit_to(display);
                                display.update();
                                
                                while (
                                    !Events::unpress(QUIT_KEY)
                                    && !back_button.get_rectangle().unclick()
                                ) {
                                    Events::update();
                                }
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a card.
                            else if (play_buttons[i].get_rectangle().unclick()) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Identical to play(), but has a choice buttons, instead of play buttons
         *   and the player cannot return to the previous menu without making a choice.
         * Only shows card of the given type (defaults to any card).
         */
        template<typename Type = Card>
        int choose(
            Display& display,
            const Renderer& renderer,
            const Button& back_button
        ) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The store size sprite is intialised.
            Sprite store_size_sprite(
                renderer.render(
                    STORE_SIZE_STRING,
                    STORE_SIZE_WIDTH * display.width(),
                    STORE_SIZE_HEIGHT * display.height(),
                    STORE_SIZE_SEPARATION * display.width()
                )
            );
            
            // The choice buttons are initialised.
            std::vector<Button> choice_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                choice_buttons.push_back(
                    Button(
                        renderer.render(
                            display,
                            CHOICE_STRING,
                            CHOICE_WIDTH,
                            CHOICE_HEIGHT,
                            CHOICE_SEPARATION
                        ),
                        display,
                        CHOICE_X,
                        CHOICE_Y + i * CHOICE_Y_SHIFT
                    )
                );
            }
    
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                display.blit(store_size_sprite, STORE_SIZE_X, STORE_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            renderer.render(
                                operator[](page * PAGE_COUNT + i).get_name(),
                                PAGE_WIDTH * display.width(),
                                PAGE_HEIGHT * display.height(),
                                PAGE_SEPARATION * display.width()
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The corresponding play button is displayed.
                    if (dynamic_cast<const Type*>(&operator[](page * PAGE_COUNT + i))) {
                        choice_buttons[i].blit_to(display);
                    }
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT && page * PAGE_COUNT + i < size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                operator[](page * PAGE_COUNT + i).render(display, renderer);
                                back_button.blit_to(display);
                                display.update();
                                
                                while (
                                    !Events::unpress(QUIT_KEY)
                                    && !back_button.get_rectangle().unclick()
                                ) {
                                    Events::update();
                                }
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a card.
                            else if (
                                dynamic_cast<const Type*>(&operator[](page * PAGE_COUNT + i))
                                && choice_buttons[i].get_rectangle().unclick()
                            ) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Returns the size of the corresponding substore.
         */
        template<typename Type>
        int size() const noexcept {
            if (std::is_same<Type, Fighter>::value) {
                return fighters.size();
            }
            
            else if (std::is_same<Type, Supporter>::value) {
                return supporters.size();
            }
            
            else {
                return energy.size();
            }
        }
        
        /**
         * Returns a reference to the fighter substore.
         */
        std::vector<Fighter>& get_fighters() noexcept {
            return fighters;
        }
        
        /**
         * Returns a constant reference to the fighter substore.
         */
        const std::vector<Fighter>& get_fighters() const noexcept {
            return fighters;
        }
        
        /**
         * Returns a constant reference to the supporter substore.
         */
        const std::vector<Supporter>& get_supporters() const noexcept {
            return supporters;
        }
        
        /**
         * Returns a reference to the energy substore.
         */
        std::vector<Energy>& get_energy() noexcept {
            return energy;
        }
        
        /**
         * Returns a constant reference to the energy substore.
         */
        const std::vector<Energy>& get_energy() const noexcept {
            return energy;
        }
        
        /**
         * Removes all of the cards in the substore that corresponds with the given type.
         */
        template<typename Type>
        void remove() noexcept {
            if (std::is_same<Type, Fighter>::value) {
                fighters.clear();
            }
            
            else if (std::is_same<Type, Supporter>::value) {
                supporters.clear();
            }
            
            else {
                energy.clear();
            }
        }
        
        /**
         * Removes the first card that matches the given name.
         */
        std::unique_ptr<Card> remove(const std::string& name) {
            for (int i = 0; i < size(); ++i) {
                if (operator[](i).get_name() == name) {
                    return remove(i);
                }
            }
            
            return std::unique_ptr<Card>();
        }
        
    private:
        std::vector<Fighter> fighters;     // The store of fighter cards.
        std::vector<Supporter> supporters; // The store of supporter cards.
        std::vector<Energy> energy;        // The store of energy cards.
};

/**
 * A class that defines a player.
 */
class Player: public Affectable {
    public:
        /**
         * Constructs a player with their deck, an empty hand, an empty trash,
         *   an empty store of life cards, and an empty board of fighters.
         */
        Player(
            const std::string& deck_code,
            Display& display,
            const Renderer& renderer,
            const Messenger& messenger,
            MessengerPackage& messenger_package,
            Thread& messenger_thread,
            const Button& back_button,
            const Button& next_button,
            CardStore& the_void,
            std::mt19937& generator,
            bool opposing,
            const bool& turn,
            const int& turn_count
        ) noexcept:
            Affectable(PLAYER_EFFECTS),
            deck(deck_code),
            display(display),
            renderer(renderer),
            messenger(messenger),
            messenger_package(messenger_package),
            messenger_thread(messenger_thread),
            back_button(back_button),
            next_button(next_button),
            the_void(the_void),
            generator(generator),
            opposing(opposing),
            message(messenger_package.get_string()),
            turn(turn),
            turn_count(turn_count)
        {}
        
        /**
         * Sets the opponent.
         */
        void set_opponent(Player& opponent) noexcept {
            this->opponent = &opponent;
        }
        
        /**
         * Returns true if the player's hand is valid for play.
         */
        bool valid_hand() const noexcept {
            return hand.size();
        }
        
        /**
         * Randomly draws cards from the deck to the hand.
         * Draws all of the cards in the deck by default.
         */
        void draw(int count = -1) noexcept {
            if (count < 0) {
                count = deck.size();
            }
            
            for (int i = 0; deck.size() && i < count; ++i) {
                last_drawn = deck.draw(generator);
                hand.store(*last_drawn);
            }
        }
    
        /**
         * Shuffles the hand into the deck.
         */
        void shuffle() noexcept {
            while (hand.size()) {
                deck.store(*hand.remove());
            }
        }
        
        /**
         * Discards the entire hand.
         */
        void discard() noexcept {
            while (hand.size()) {
                trash.store(*hand.remove());
            }
        }
        
        /**
         * Draws a new hand from the deck.
         * If the hand had no basic cards, they are displayed
         *   and are shuffled back into the deck.
         */
        void mulligan() noexcept {
            // The components of the display are extracted.
            Sprite& display_sprite = display.get_sprite();
            int display_width = display_sprite.get_width();
            int display_height = display_sprite.get_height();
            
            // The cards are drawn from the deck to form the starting hand.
            draw(HAND_SIZE - 1);
            
            // If the hand is valid, a random card is drawn
            if (hand.valid()) {
                draw(1);
            }
            
            // If the hand is invalid, an unranked fighter is drawn.
            else {
                std::vector<int> indices;
                
                for (int i = 0; i < deck.size<Fighter>(); ++i) {
                    if (deck.get_fighters()[i].get_old_rank() == NO_OLD_RANK) {
                        indices.push_back(i);
                    }
                }
                
                hand.store(
                    deck.remove(
                        indices[
                            Random::get_int(
                                generator,
                                0,
                                indices.size() - 1
                            )
                        ]
                    )
                );
            }
            
            // If the hand is invalid, the hand is displayed are shuffled back into the deck.
            if (!hand.valid()) {
                // The next button is initialised.
                Button next_button(
                    renderer.render(
                        NEXT_STRING,
                        NEXT_WIDTH * display_width,
                        NEXT_HEIGHT * display_height,
                        NEXT_SEPARATION * display_width
                    ),
                    display_sprite,
                    NEXT_X,
                    NEXT_Y
                );
                
                // The player is notified that the mulligan failed.
                display_sprite.fill();
                display_sprite.blit(
                    renderer.lined_render(
                        MULLIGAN_FAIL_STRING,
                        MULLIGAN_FAIL_WIDTH * display_width,
                        MULLIGAN_FAIL_HEIGHT * display_height,
                        MULLIGAN_FAIL_SEPARATION_X * display_width,
                        MULLIGAN_FAIL_MAX_WIDTH * display_width,
                        MULLIGAN_FAIL_SEPARATION_Y * display_height,
                        MULLIGAN_FAIL_JUSTIFICATION
                    ),
                    MULLIGAN_FAIL_X,
                    MULLIGAN_FAIL_Y
                );
                next_button.blit_to(display_sprite);
                display.update();
                
                // Proceeds at the player's discretion.
                while (
                    !Events::unpress(SUBMIT_KEY)
                    && !next_button.get_rectangle().unclick()
                ) {
                    Events::update();
                }
                
                // The hand is displayed.
                hand.view(display, renderer);
                
                // The player is notified that another mulligan will be performed.
                display_sprite.fill();
                display_sprite.blit(
                    renderer.lined_render(
                        NEW_MULLIGAN_STRING,
                        NEW_MULLIGAN_WIDTH * display_width,
                        NEW_MULLIGAN_HEIGHT * display_height,
                        NEW_MULLIGAN_SEPARATION_X * display_width,
                        NEW_MULLIGAN_MAX_WIDTH * display_width,
                        NEW_MULLIGAN_SEPARATION_Y * display_height,
                        NEW_MULLIGAN_JUSTIFICATION
                    ),
                    NEW_MULLIGAN_X,
                    NEW_MULLIGAN_Y
                );
                next_button.blit_to(display_sprite);
                display.update();
                
                // Proceeds at the player's discretion.
                while (
                    !Events::unpress(SUBMIT_KEY)
                    && !next_button.get_rectangle().unclick()
                ) {
                    Events::update();
                }
                
                // The hand is shuffled back into the deck.
                shuffle();
            }
            
            ++mulligan_count;
        }
        
        /**
         * Returns the number of mulligans performed.
         */
        int count_mulligans() const noexcept {
            return mulligan_count;
        }
    
        /**
         * Places the player's life cards.
         * Reveals the life cards if the player owns them.
         */
        void set_life_cards() noexcept {
            for (int i = 0; i < LIFE_SIZE; ++i) {
                // Supporter cards are the 1st priority.
                if (deck.size<Supporter>()) {
                    life_cards.store(deck.draw<Supporter>(generator));
                }
                
                // Energy cards are the 2nd priority.
                else if (deck.size<Energy>()) {
                    life_cards.store(deck.draw<Energy>(generator));
                }
                
                // Fighter cards are the 3rd priority.
                else {
                    life_cards.store(deck.draw<Fighter>(generator));
                }
            }
            
            // The components of the display are extracted.
            Sprite& display_sprite = display.get_sprite();
            int display_width = display_sprite.get_width();
            int display_height = display_sprite.get_height();
            
            // The life card message is displayed.
            display_sprite.fill();
            display_sprite.blit(
                renderer.lined_render(
                    LIFE_STRING,
                    LIFE_WIDTH * display_width,
                    LIFE_HEIGHT * display_height,
                    LIFE_SEPARATION_X * display_width,
                    LIFE_MAX_WIDTH * display_width,
                    LIFE_SEPARATION_Y * display_height,
                    LIFE_JUSTIFICATION
                ),
                LIFE_X,
                LIFE_Y
            );
            next_button.blit_to(display_sprite);
            display.update();
            
            // The player can advance at their discretion.
            while (
                !Events::unpress(SUBMIT_KEY)
                && !next_button.get_rectangle().unclick()
            ) {
                Events::update();
            }
            
            // The player may see their own life cards.
            if (!opposing) {
                life_cards.view(display, renderer);
            }
        }
    
        /**
         * Chooses the player's active fighter.
         * Returns the choice in string form.
         */
        std::string set_active() noexcept {
            // The components of the display are extracted.
            Sprite& display_sprite = display.get_sprite();
            int display_width = display_sprite.get_width();
            int display_height = display_sprite.get_height();
            
            display_sprite.fill();
            display_sprite.blit(
                renderer.lined_render(
                    SET_ACTIVE_STRING,
                    SET_ACTIVE_WIDTH * display_width,
                    SET_ACTIVE_HEIGHT * display_height,
                    SET_ACTIVE_SEPARATION_X * display_width,
                    SET_ACTIVE_MAX_WIDTH * display_width,
                    SET_ACTIVE_SEPARATION_Y * display_height,
                    SET_ACTIVE_JUSTIFICATION
                ),
                SET_ACTIVE_X,
                SET_ACTIVE_Y
            );
            next_button.blit_to(display_sprite);
            display.update();
            
            while (
                !Events::unpress(SUBMIT_KEY)
                && !next_button.get_rectangle().unclick()
            ) {
                Events::update();
            }
            
            int choice = hand.choose_basic(display, renderer);
            fighters.push_back(static_cast<Fighter&>(*hand.remove(choice)));
        
            return std::to_string(choice);
        }
        
        /**
         * Chooses the opponent's active fighter.
         */
        void set_active(const std::string& choice) noexcept {
            fighters.push_back(static_cast<Fighter&>(*hand.remove(std::stoi(choice))));
        }
    
        /**
         * Returns true if the player can draw from their deck.
         */
        bool can_draw() const noexcept {
            return deck.size();
        }
    
        /**
         * Displays the last drawn card's name.
         */
        void display_last_drawn() const noexcept {
            display.fill();
            display.blit(
                renderer.lined_render(
                    LAST_DRAWN_STRING,
                    LAST_DRAWN_WIDTH * display.width(),
                    LAST_DRAWN_HEIGHT * display.height(),
                    LAST_DRAWN_SEPARATION_X * display.width(),
                    LAST_DRAWN_MAX_WIDTH * display.width(),
                    LAST_DRAWN_SEPARATION_Y * display.height(),
                    LAST_DRAWN_JUSTIFICATION
                ),
                LAST_DRAWN_X,
                LAST_DRAWN_Y
            );
        }
    
        /**
         * Allows the player to view their hand.
         */
        void view_hand() const noexcept {
            hand.view(display, renderer, message);
        }
        
        /**
         * Allows the player to view their deck.
         */
        void view_deck() const noexcept {
            deck.view(display, renderer, message);
        }
        
        /**
         * Allows the player to view their trash.
         */
        void view_trash() const noexcept {
            trash.view(display, renderer, message);
        }
        
        /**
         * Allows the player to view their life cards.
         */
        void view_life_cards() const noexcept {
            life_cards.view(display, renderer, message);
        }
    
        /**
         * Renders the hand size to the display.
         */
        void view_hand_size() const noexcept {
            hand.view_size(display, renderer);
            back_button.blit_to(display);
            display.update();
            
            // The player proceeds at their own discretion.
            while (
                !Events::unpress(NEXT_KEY)
                && !Events::unpress(BACK_KEY)
                && !back_button.get_rectangle().unclick()
                && message == EMPTY_MESSAGE
            ) {
                Events::update();
            }
        }
        
        /**
         * Renders the deck size to the display.
         */
        void view_deck_size() const noexcept {
            deck.view_size(display, renderer);
            back_button.blit_to(display);
            display.update();
            
            // The player proceeds at their own discretion.
            while (
                !Events::unpress(NEXT_KEY)
                && !Events::unpress(BACK_KEY)
                && !back_button.get_rectangle().unclick()
                && message == EMPTY_MESSAGE
            ) {
                Events::update();
            }
        }
        
        /**
         * Renders the life cards size to the display.
         */
        void view_life_cards_size() const noexcept {
            life_cards.view_size(display, renderer);
            back_button.blit_to(display);
            display.update();
            
            // The player proceeds at their own discretion.
            while (
                !Events::unpress(NEXT_KEY)
                && !Events::unpress(BACK_KEY)
                && !back_button.get_rectangle().unclick()
                && message == EMPTY_MESSAGE
            ) {
                Events::update();
            }
        }
    
        /**
         * Displays the player's active fighter.
         */
        void view_active() const noexcept {
            fighters[0].view(display, renderer, back_button, message);
        }
        
        /**
         * Displays the player's benched fighters.
         * Clicking a fighter's name gives more details.
         */
        void view_bench() const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The bench size sprite is intialised.
            Sprite bench_size_sprite(
                renderer.render(
                    BENCH_SIZE_STRING,
                    BENCH_SIZE_WIDTH * display.width(),
                    BENCH_SIZE_HEIGHT * display.height(),
                    BENCH_SIZE_SEPARATION * display.width()
                )
            );
            
            // Determines which cards are displayed.
            int page = 0;
            
            // True if the function should return.
            bool end = false;
            
            while (!end) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                display.blit(bench_size_sprite, BENCH_SIZE_X, BENCH_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (fighters.size() - 2) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < fighters.size() - 1;
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    fighters[BENCH_INDEX + page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The user can return to the previous menu with
                    //   the use of the back button or submit key.
                    if (
                        Events::unpress(SUBMIT_KEY)
                        || Events::unpress(QUIT_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (fighters.size() - 2) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < fighters.size() - 1;
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                fighters[BENCH_INDEX + page * PAGE_COUNT + i].view(
                                    display,
                                    renderer,
                                    back_button,
                                    message
                                );
                                
                                found = true;
                                break;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
    
        /**
         * Allows the player to play a card from their hand.
         */
        void play(int index = NO_CHOICE) noexcept {
            if (index == NO_CHOICE) {
                // The player can play cards if they haven't reached their play cap.
                if (plays) {
                    index = hand.play(display, renderer, back_button, message);
                }
                
                // The player can only view their hand, if they have reached their cap.
                else {
                    view_hand();
                    index = -1;
                }
            }
            
            // The chosen card is checked.
            if (index >= 0) {
                if (hand[index].get_type() == FIGHTER_TYPE) {
                    Fighter& f = static_cast<Fighter&>(hand[index]);
                    
                    if (!f.basic() && !rank_search(f)) {
                        announce(UNRANKABLE_ANNOUNCEMENT);
                        
                        return;
                    }
                }
                        
                if (!opposing) {
                    messenger.send(PLAY_MESSAGE);
                    messenger.send(std::to_string(index));
                }
                
                std::unique_ptr<Card> chosen(hand.remove(index));
                
                // The card is a fighter card.
                if (chosen->get_type() == FIGHTER_TYPE) {
                    Fighter& f = static_cast<Fighter&>(*chosen);
                    
                    // The fighter card is basic.
                    if (f.basic()) {
                        // The card is played onto the bench.
                        fighters.push_back(f);
                        announce(BENCHED_ANNOUNCEMENT);
                    }
                    
                    // The fighter is to rank up another.
                    else {
                        play(f);
                    }
                }
                
                // The chosen card is a supporter card.
                else if (chosen->get_type() == SUPPORTER_TYPE) {
                    play(static_cast<Supporter&>(*chosen));
                }
                
                // The chosen card is an energy card.
                else {
                    play(static_cast<Energy&>(*chosen));
                }
            
                // The number of available card plays this turn is decremented.
                --plays;
            }
        }
        
        /**
         * Allows the player to rank up a fighter card into another.
         */
        void play(const Fighter& f) noexcept {
            // Negative if there are multiple fighters that could be ranked up.
            int index = -1;
            
            for (int i = 0; i < fighters.size(); ++i) {
                if (fighters[i].get_name() == f.get_old_rank()) {
                    if (index < 0) {
                        index = i;
                    }
                    
                    else {
                        index = -1;
                        break;
                    }
                }
            }
            
            // The player should choose a fighter to rank up.
            if (index < 0) {
                // The player chooses the recipient of the energy.
                if (!opposing) {
                    index = rank_up(f);
                    
                    messenger.send(std::to_string(index));
                }
                
                // The opponent awaits the player's choice.
                else {
                    // The opponent is notifed that the player is choosing a fighter.
                    display.fill();
                    display.blit(
                        renderer.lined_render(
                            display,
                            RANK_UP_STRING,
                            RANK_UP_WIDTH,
                            RANK_UP_HEIGHT,
                            RANK_UP_SEPARATION_X,
                            RANK_UP_MAX_WIDTH,
                            RANK_UP_SEPARATION_Y,
                            RANK_UP_JUSTIFICATION
                        ),
                        RANK_UP_X,
                        RANK_UP_Y
                    );
                    display.update();
                    
                    while (message == EMPTY_MESSAGE) {
                        Events::update();
                    }
                    
                    // The attachment indexed is received.
                    index = std::stoi(message);
                    
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                }
            }
            
            rank_up(f, index);
            
            // A constant pointer to the effects of the fighter upon being played.
            std::vector<std::vector<std::string>> filtered(
                fighters[index].effect_search(PLAY_EFFECT)
            );
            
            // The fighter's effects when played are checked.
            for (int i = 0; i < filtered.size(); ++i) {
                // Energy in play is returned to hand for both players.
                if (filtered[i][1] == ENERGY_BOUNCE_EFFECT) {
                    for (int i = 0; i < fighters.size(); ++i) {
                        hand.store(fighters[i].remove_energy());
                    }
                    
                    for (int i = 0; i < opponent->fighters.size(); ++i) {
                        opponent->hand.store(opponent->fighters[i].remove_energy());
                    }
                    
                    announce(ENERGY_BOUNCE_ANNOUNCEMENT);
                }
                
                // The effect only takes place if the fighter is in the active position.
                else if (filtered[i][1] == ACTIVE_EFFECT && !index) {
                    // The fighter is made invincible.
                    if (filtered[i][2] == INVINCIBILITY_EFFECT) {
                        fighters[index].affect(filtered[i][2]);
                        announce(INVINCIBILITY_ANNOUNCEMENT);
                    }
                    
                    // The fighter is rooted.
                    else if (filtered[i][2] == ROOT_EFFECT) {
                        fighters[index].affect(filtered[i][2]);
                        announce(ROOT_ANNOUNCEMENT);
                    }
                }
                
                // Energy in the hand is converted to match this fighter's element.
                else if (filtered[i][1] == HAND_CONVERSION_EFFECT) {
                    for (int j = 0; j < hand.get_energy().size(); ++j) {
                        hand.get_energy()[j].set_element(fighters[index].get_element());
                    }
                    
                    announce(HAND_CONVERSION_ANNOUNCEMENT);
                }
                
                // Cards are drawn.
                else if (filtered[i][1] == DRAW_EFFECT) {
                    int draws = std::stoi(filtered[i][2]);
                    
                    // The number of card draws cannot exceed
                    //   the number of cards in the deck.
                    if (draws > deck.size()) {
                        draws = deck.size();
                    }
                    
                    // The opponent only sees the number of draws.
                    if (opposing) {
                        draw(draws);
                        announce(DRAW_ANNOUNCEMENT);
                    }
                    
                    // The player sees what was drawn.
                    else {
                        for (int j = 0; j < draws; ++j) {
                            draw(1);
                            announce(LAST_DRAWN_ANNOUNCEMENT);
                        }
                        
                        announce(DRAW_ANNOUNCEMENT);
                    }
                }
                
                // attacked and retreated are set to false.
                else if (filtered[i][1] == RESET_EFFECT) {
                    attacked = false;
                    retreated = false;
                    announce(RESET_ANNOUNCEMENT);
                }
                
                // Player power is modified.
                else if (filtered[i][1] == POWER_EFFECT) {
                    affect(
                        filtered[i][1]
                        + EFFECT_SEPARATOR
                        + filtered[i][2]
                    );
                    
                    const std::string& power = filtered[i][2];
                    announce(PLAYER_POWER_ANNOUNCEMENT);
                }
                
                // This player's cards are converted to match this fighter's element.
                else if (filtered[i][1] == CONVERSION_EFFECT) {
                    // The fighter cards in the deck are converted.
                    for (int j = 0; j < deck.size<Fighter>(); ++j) {
                        deck.get_fighters()[j].set_element(fighters[index].get_element());
                    }
                    
                    // The energy cards in the deck are converted.
                    for (int j = 0; j < deck.size<Energy>(); ++j) {
                        deck.get_energy()[j].set_element(fighters[index].get_element());
                    }
                    
                    // The fighter cards in the trash are converted.
                    for (int j = 0; j < trash.size<Fighter>(); ++j) {
                        trash.get_fighters()[j].set_element(fighters[index].get_element());
                    }
                    
                    // The energy cards in the trash are converted.
                    for (int j = 0; j < trash.size<Energy>(); ++j) {
                        trash.get_energy()[j].set_element(fighters[index].get_element());
                    }
                    
                    // The fighter cards in the hand are converted.
                    for (int j = 0; j < hand.size<Fighter>(); ++j) {
                        hand.get_fighters()[j].set_element(fighters[index].get_element());
                    }
                    
                    // The energy cards in the hand are converted.
                    for (int j = 0; j < hand.size<Energy>(); ++j) {
                        hand.get_energy()[j].set_element(fighters[index].get_element());
                    }
                    
                    // The fighter cards in the life cards are converted.
                    for (int j = 0; j < life_cards.size<Fighter>(); ++j) {
                        life_cards.get_fighters()[j].set_element(
                            fighters[index].get_element()
                        );
                    }
                    
                    // The energy cards in the life cards are converted.
                    for (int j = 0; j < life_cards.size<Energy>(); ++j) {
                        life_cards.get_energy()[j].set_element(
                            fighters[index].get_element()
                        );
                    }
                    
                    // The fighter cards in play are converted (with their attached energy).
                    for (int j = 0; j < fighters.size(); ++j) {
                        fighters[j].set_element(fighters[index].get_element());
                        fighters[j].set_energy_element(fighters[index].get_element());
                    }
                    
                    announce(CONVERSION_ANNOUNCEMENT);
                }
            }
        }
        
        /**
         * Allows the player to play a supporter card.
         */
        void play(const Supporter& s) noexcept {
            // The effects are extracted.
            const std::vector<std::vector<std::string>>& effects = s.get_effects();
            
            // The results of the last set of coin flips.
            std::vector<bool> coin_flips;
            std::array<int, 2> flip_counts;
            
            // True, if the supporter card should be stored in the trash.
            bool to_discard = true;
            
            // The supporter card being played is announced.
            announce(SUPPORTER_ANNOUNCEMENT);
            
            // The effects are resolved.
            for (int i = 0; i < effects.size(); ++i) {
                // The supporter card allows the player to draw.
                if (effects[i][0] == DRAW_EFFECT) {
                    // The opponent draws.
                    if (effects[i][1] == OPPONENT_EFFECT) {
                        int draws = std::stoi(effects[i][2]);
                        
                        // The number of card draws cannot exceed
                        //   the number of cards in the deck.
                        if (draws > opponent->deck.size()) {
                            draws = opponent->deck.size();
                        }
                        
                        // The player only sees the number of draws.
                        if (!opposing) {
                            opponent->draw(draws);
                            announce(DRAW_OPPONENT_ANNOUNCEMENT);
                        }
                        
                        // The opponent sees what was drawn.
                        else {
                            for (int j = 0; j < draws; ++j) {
                                opponent->draw(1);
                                announce(LAST_DRAWN_OPPONENT_ANNOUNCEMENT);
                            }
                            
                            announce(DRAW_OPPONENT_ANNOUNCEMENT);
                        }
                    }
                    
                    // The player draws all of the unranked fighters in their deck.
                    else if (effects[i][1] == UNRANKED_EFFECT) {
                        for (int j = deck.size<Fighter>() - 1; j >= 0; --j) {
                            if (deck.get_fighters()[j].basic()) {
                                hand.store(deck.remove(j));
                            }
                        }
                        
                        announce(DRAW_UNRANKED_ANNOUNCEMENT);
                    }
                    
                    // The player draws.
                    else {
                        int draws = std::stoi(effects[i][1]);
                        
                        // The number of card draws cannot exceed
                        //   the number of cards in the deck.
                        if (draws > deck.size()) {
                            draws = deck.size();
                        }
                        
                        // The opponent only sees the number of draws.
                        if (opposing) {
                            draw(draws);
                            announce(DRAW_ANNOUNCEMENT);
                        }
                        
                        // The player sees what was drawn.
                        else {
                            for (int j = 0; j < draws; ++j) {
                                draw(1);
                                announce(LAST_DRAWN_ANNOUNCEMENT);
                            }
                            
                            announce(DRAW_ANNOUNCEMENT);
                        }
                    }
                }
                
                // The supporter card discards cards.
                else if (effects[i][0] == DISCARD_EFFECT) {
                    // Discards all of the cards in the hand.
                    if (effects[i][1] == UNIVERSAL_EFFECT) {
                        int discards = hand.size();
                        last_draws = discards;
                        announce(DISCARD_ALL_ANNOUNCEMENT);
                        discard();
                    }
                
                    // Discards energy cards in hand.
                    else if (effects[i][1] == ENERGY_TYPE) {
                        // Discards all of the energy cards in hand.
                        if (effects[i][2] == UNIVERSAL_EFFECT) {
                            int discards = hand.size<Energy>();
                            last_draws = discards;
                            announce(DISCARD_ENERGY_ALL_ANNOUNCEMENT);
                            trash.store(hand.get_energy());
                            hand.remove<Energy>();
                        }
                    }
                
                    // Discards a number of chosen cards from the hand.
                    else {
                        int discards = std::stoi(effects[i][1]);
                        
                        if (discards > hand.size()) {
                            discards = hand.size();
                        }
                        
                        // The player chooses cards to discard.
                        for (int i = 0; i < discards; ++i) {
                            int index;
                            
                            if (hand.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(TO_DISCARD_ANNOUNCEMENT);
                                
                                index = hand.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(TO_DISCARD_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            if (opposing) {
                                announce(DISCARD_PEEK_ANNOUNCEMENT);
                            }
                            
                            trash.store(hand.remove(index));
                        }
                        
                        announce(DISCARD_ANNOUNCEMENT);
                    }
                }
                
                // The supporter card banishes cards.
                else if (effects[i][0] == BANISH_EFFECT) {
                    int banishes = std::stoi(effects[i][1]);
                    
                    if (banishes > hand.size()) {
                        banishes = hand.size();
                    }
                    
                    // The player chooses cards to banish.
                    for (int i = 0; i < banishes; ++i) {
                        int index;
                        
                        if (hand.size() == 1) {
                            index = 0;
                        }
                        
                        else if (!opposing) {
                            announce(TO_BANISH_ANNOUNCEMENT);
                            
                            index = hand.choose(
                                display,
                                renderer,
                                back_button
                            );
                            
                            messenger.send(std::to_string(index));
                        }
                        
                        else {
                            announce(TO_BANISH_ANNOUNCEMENT, false);
                            
                            index = std::stoi(message);
                            
                            // A message is waited for in another thread.
                            message = EMPTY_MESSAGE;
                            messenger_thread.new_thread(
                                MessengerPackage::get_message,
                                &messenger_package
                            );
                        }
                        
                        if (opposing) {
                            announce(BANISH_PEEK_ANNOUNCEMENT);
                        }
                        
                        the_void.store(hand.remove(index));
                    }
                    
                    announce(BANISH_ANNOUNCEMENT);
                }
                
                // The supporter card shuffles cards into the deck.
                else if (effects[i][0] == SHUFFLE_EFFECT) {
                    // The opponent shuffles cards into their deck.
                    if (effects[i][1] == OPPONENT_EFFECT) {
                        // The opponent shuffles all of their cards into the deck.
                        if (effects[i][2] == UNIVERSAL_EFFECT) {
                            int shuffles = opponent->hand.size();
                            announce(SHUFFLE_OPPONENT_ALL_ANNOUNCEMENT);
                            opponent->shuffle();
                        }
                    }
                    
                    // Shuffles cards from the trash into the deck.
                    else if (effects[i][1] == TRASH_EFFECT) {
                        // Shuffles energy cards into the deck.
                        if (effects[i][2] == ENERGY_TYPE) {
                            if (effects[i][3] == UNIVERSAL_EFFECT) {
                                int shuffles = trash.size<Energy>();
                                deck.store(trash.get_energy());
                                announce(SHUFFLE_TRASH_ENERGY_ANNOUNCEMENT);
                                trash.remove<Energy>();
                            }
                        }
                        
                        // Shuffles a number of chosen cards from the trash into the deck.
                        else {
                            int shuffles = std::stoi(effects[i][2]);
                            
                            if (shuffles > trash.size()) {
                                shuffles = trash.size();
                            }
                            
                            // The player chooses cards to shuffle into the deck.
                            for (int i = 0; i < shuffles; ++i) {
                                int index;
                                
                                if (trash.size() == 1) {
                                    index = 0;
                                }
                                
                                else if (!opposing) {
                                    announce(TO_SHUFFLE_TRASH_ANNOUNCEMENT);
                                    
                                    index = trash.choose(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(TO_SHUFFLE_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                if (opposing) {
                                    announce(SHUFFLE_TRASH_PEEK_ANNOUNCEMENT);
                                }
                                
                                last_drawn = trash.remove(index);
                                deck.store(last_drawn);
                            }
                            
                            announce(SHUFFLE_ANNOUNCEMENT);
                        }
                    }
                    
                    // Shuffles all of the cards in the hand into the deck.
                    else if (effects[i][1] == UNIVERSAL_EFFECT) {
                        int shuffles = hand.size();
                        announce(SHUFFLE_ALL_ANNOUNCEMENT);
                        shuffle();
                    }
                    
                    // Shuffles a number of chosen cards from the hand into the deck.
                    else {
                        int shuffles = std::stoi(effects[i][1]);
                        
                        if (shuffles > hand.size()) {
                            shuffles = hand.size();
                        }
                        
                        // The player chooses cards to shuffle into the deck.
                        for (int i = 0; i < shuffles; ++i) {
                            int index;
                            
                            if (hand.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(TO_SHUFFLE_ANNOUNCEMENT);
                                
                                index = hand.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(TO_SHUFFLE_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            last_drawn = hand.remove(index);
                            deck.store(last_drawn);
                        }
                        
                        announce(SHUFFLE_ANNOUNCEMENT);
                    }
                }
            
                // The supporter card will draw cards at the turn's end.
                else if (effects[i][0] == END_DRAW_EFFECT) {
                    affect(
                        effects[i][0]
                        + EFFECT_SEPARATOR
                        + effects[i][1]
                    );
                    
                    announce(END_DRAW_ANNOUNCEMENT);
                }
            
                // The supporter card flips coins.
                else if (effects[i][0] == FLIP_EFFECT) {
                    // Preparation for the set of coin flips.
                    int flips = std::stoi(effects[i][1]);
                    coin_flips.clear();
                    flip_counts.fill(0);
                    
                    for (int i = 0; i < flips; ++i) {
                        bool result = coin_flip(generator);
                        coin_flips.push_back(result);
                        ++flip_counts[result];
                        announce(FLIP_ANNOUNCEMENT);
                    }
                    
                    announce(FLIP_COUNT_ANNOUNCEMENT);
                }
                
                // Takes effect only if the first coin flip was heads.
                else if (effects[i][0] == HEADS_EFFECT && coin_flips[0] == HEADS) {
                    // Takes effect only if the second coin flip was heads.
                    if (effects[i][1] == HEADS_EFFECT && coin_flips[1] == HEADS) {
                        // The supporter card allows the player to draw.
                        if (effects[i][2] == DRAW_EFFECT) {
                            int draws = std::stoi(effects[i][3]);
                            
                            // The number of card draws cannot exceed
                            //   the number of cards in the deck.
                            if (draws > deck.size()) {
                                draws = deck.size();
                            }
                            
                            // The opponent only sees the number of draws.
                            if (opposing) {
                                draw(draws);
                                announce(DRAW_ANNOUNCEMENT);
                            }
                            
                            // The player sees what was drawn.
                            else {
                                for (int j = 0; j < draws; ++j) {
                                    draw(1);
                                    announce(LAST_DRAWN_ANNOUNCEMENT);
                                }
                            
                                announce(DRAW_ANNOUNCEMENT);
                            }
                        }
                    }
                    
                    // Takes effect only if the second coin flip was tails.
                    else if (effects[i][1] == TAILS_EFFECT && coin_flips[1] == TAILS) {
                        // The supporter card allows the player to draw.
                        if (effects[i][2] == DRAW_EFFECT) {
                            int draws = std::stoi(effects[i][3]);
                            
                            // The number of card draws cannot exceed
                            //   the number of cards in the deck.
                            if (draws > deck.size()) {
                                draws = deck.size();
                            }
                            
                            // The opponent only sees the number of draws.
                            if (opposing) {
                                draw(draws);
                                announce(DRAW_ANNOUNCEMENT);
                            }
                            
                            // The player sees what was drawn.
                            else {
                                for (int j = 0; j < draws; ++j) {
                                    draw(1);
                                    announce(LAST_DRAWN_ANNOUNCEMENT);
                                }
                            
                                announce(DRAW_ANNOUNCEMENT);
                            }
                        }
                    }
                    
                    // The supporter card allows the player to draw.
                    else if (effects[i][1] == DRAW_EFFECT) {
                        int draws = std::stoi(effects[i][2]);
                        
                        // The number of card draws cannot exceed
                        //   the number of cards in the deck.
                        if (draws > deck.size()) {
                            draws = deck.size();
                        }
                        
                        // The opponent only sees the number of draws.
                        if (opposing) {
                            draw(draws);
                            announce(DRAW_ANNOUNCEMENT);
                        }
                        
                        // The player sees what was drawn.
                        else {
                            for (int j = 0; j < draws; ++j) {
                                draw(1);
                                announce(LAST_DRAWN_ANNOUNCEMENT);
                            }
                        
                            announce(DRAW_ANNOUNCEMENT);
                        }
                    }
                }
                
                // Takes effect only if the first coin flip was tails.
                else if (effects[i][0] == TAILS_EFFECT && coin_flips[0] == TAILS) {
                    // Takes effect only if the second coin flip was heads.
                    if (effects[i][1] == HEADS_EFFECT && coin_flips[1] == HEADS) {
                        // The supporter card allows the player to draw.
                        if (effects[i][2] == DRAW_EFFECT) {
                            int draws = std::stoi(effects[i][3]);
                            
                            // The number of card draws cannot exceed
                            //   the number of cards in the deck.
                            if (draws > deck.size()) {
                                draws = deck.size();
                            }
                            
                            // The opponent only sees the number of draws.
                            if (opposing) {
                                draw(draws);
                                announce(DRAW_ANNOUNCEMENT);
                            }
                            
                            // The player sees what was drawn.
                            else {
                                for (int j = 0; j < draws; ++j) {
                                    draw(1);
                                    announce(LAST_DRAWN_ANNOUNCEMENT);
                                }
                            
                                announce(DRAW_ANNOUNCEMENT);
                            }
                        }
                    }
                    
                    // Takes effect only if the second coin flip was tails.
                    else if (effects[i][1] == TAILS_EFFECT && coin_flips[1] == TAILS) {
                        // The supporter card allows the player to draw.
                        if (effects[i][2] == DRAW_EFFECT) {
                            int draws = std::stoi(effects[i][3]);
                            
                            // The number of card draws cannot exceed
                            //   the number of cards in the deck.
                            if (draws > deck.size()) {
                                draws = deck.size();
                            }
                            
                            // The opponent only sees the number of draws.
                            if (opposing) {
                                draw(draws);
                                announce(DRAW_ANNOUNCEMENT);
                            }
                            
                            // The player sees what was drawn.
                            else {
                                for (int j = 0; j < draws; ++j) {
                                    draw(1);
                                    announce(LAST_DRAWN_ANNOUNCEMENT);
                                }
                            
                                announce(DRAW_ANNOUNCEMENT);
                            }
                        }
                    }
                    
                    // The supporter card allows the player to draw.
                    else if (effects[i][1] == DRAW_EFFECT) {
                        int draws = std::stoi(effects[i][2]);
                        
                        // The number of card draws cannot exceed
                        //   the number of cards in the deck.
                        if (draws > deck.size()) {
                            draws = deck.size();
                        }
                        
                        // The opponent only sees the number of draws.
                        if (opposing) {
                            draw(draws);
                            announce(DRAW_ANNOUNCEMENT);
                        }
                        
                        // The player sees what was drawn.
                        else {
                            for (int j = 0; j < draws; ++j) {
                                draw(1);
                                announce(LAST_DRAWN_ANNOUNCEMENT);
                            }
                        
                            announce(DRAW_ANNOUNCEMENT);
                        }
                    }
                }
                
                // Allows the player to search for cards in their deck.
                else if (effects[i][0] == SEARCH_EFFECT) {
                    // The card searched for is to be discarded.
                    if (effects[i][1] == DISCARD_EFFECT) {
                        // The number of discard searches are extracted.
                        int discards = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (discards > deck.size()) {
                            discards = deck.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < discards; ++i) {
                            int index;
                            
                            if (deck.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(SEARCH_DISCARD_ANNOUNCEMENT);
                                
                                index = deck.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_DISCARD_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            if (opposing) {
                                announce(SEARCH_DISCARD_PEEK_ANNOUNCEMENT);
                            }
                            
                            trash.store(deck.remove(index));
                        }
                        
                        announce(DISCARD_ANNOUNCEMENT);
                    }
                    
                    // The card searched for is to be banished.
                    else if (effects[i][1] == BANISH_EFFECT) {
                        // The number of banish searches are extracted.
                        int banishes = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (banishes > deck.size()) {
                            banishes = deck.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < banishes; ++i) {
                            int index;
                            
                            if (deck.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(SEARCH_BANISH_ANNOUNCEMENT);
                                
                                index = deck.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_BANISH_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            if (opposing) {
                                announce(SEARCH_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            the_void.store(deck.remove(index));
                        }
                        
                        announce(BANISH_ANNOUNCEMENT);
                    }
                    
                    // The trash is searched for a card to draw.
                    else if (effects[i][1] == TRASH_EFFECT) {
                        if (effects[i][2] == ENERGY_TYPE) {
                            int searches = std::stoi(effects[i][3]);
                            
                            // The number of searches can't exceed
                            //   the number of cards in the deck.
                            if (searches > trash.size<Energy>()) {
                                searches = trash.size<Energy>();
                            }
                            
                            // The player chooses cards to search for.
                            for (int i = 0; i < searches; ++i) {
                                int index;
                                
                                if (trash.size<Energy>() == 1) {
                                    index = trash.size() - 1;
                                }
                                
                                else if (!opposing) {
                                    announce(SEARCH_TRASH_ENERGY_ANNOUNCEMENT);
                                    
                                    index = trash.choose<Energy>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(SEARCH_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                if (opposing) {
                                    announce(SEARCH_TRASH_PEEK_ANNOUNCEMENT);
                                }
                                
                                hand.store(trash.remove(index));
                            }
                            
                            announce(SEARCH_ANNOUNCEMENT);
                        }
                        
                        else {
                            int searches = std::stoi(effects[i][2]);
                            
                            // The number of searches can't exceed
                            //   the number of cards in the deck.
                            if (searches > trash.size()) {
                                searches = trash.size();
                            }
                            
                            // The player chooses cards to search for.
                            for (int i = 0; i < searches; ++i) {
                                int index;
                                
                                if (trash.size() == 1) {
                                    index = 0;
                                }
                                
                                else if (!opposing) {
                                    announce(SEARCH_TRASH_ANNOUNCEMENT);
                                    
                                    index = trash.choose(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(SEARCH_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                if (opposing) {
                                    announce(SEARCH_TRASH_PEEK_ANNOUNCEMENT);
                                }
                                
                                hand.store(trash.remove(index));
                            }
                            
                            announce(SEARCH_ANNOUNCEMENT);
                        }
                    }
                    
                    // The life cards are searched for a card to draw.
                    else if (effects[i][1] == LIFE_EFFECT) {
                        int searches = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the
                        //   number of cards in the life card store.
                        if (searches > life_cards.size()) {
                            searches = life_cards.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            // There is only one option.
                            if (life_cards.size() == 1) {
                                index = 0;
                            }
                            
                            // The player chooses a card.
                            else if (!opposing) {
                                announce(SEARCH_LIFE_ANNOUNCEMENT);
                                
                                index = life_cards.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            // The opponent waits for the player's choice.
                            else {
                                announce(SEARCH_LIFE_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                get_message();
                            }
                            
                            hand.store(life_cards.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                    
                    // The deck is searched for an energy card.
                    else if (effects[i][1] == ENERGY_TYPE) {
                        int searches = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (searches > deck.size<Energy>()) {
                            searches = deck.size<Energy>();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            // There is only one option.
                            if (deck.size<Energy>() == 1) {
                                index = deck.size() - 1;
                            }
                            
                            // The player chooses a card.
                            else if (!opposing) {
                                announce(SEARCH_ENERGY_ANNOUNCEMENT);
                                
                                index = deck.choose<Energy>(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_ENERGY_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            hand.store(deck.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                    
                    // The deck is searched for a card of the same type as last_drawn.
                    else if (effects[i][1] == SAME_TYPE_EFFECT) {
                        int searches = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed
                        //   the number of cards in the deck.
                        if (!last_drawn) {
                            searches = 0;
                        }
                        
                        else if (
                            last_drawn->get_type() == FIGHTER_TYPE
                            && searches > deck.size<Fighter>()
                        ) {
                            searches = deck.size<Fighter>();
                        }
                        
                        else if (
                            last_drawn->get_type() == SUPPORTER_TYPE
                            && searches > deck.size<Supporter>()
                        ) {
                            searches = deck.size<Supporter>();
                        }
                        
                        else if (
                            last_drawn->get_type() == ENERGY_TYPE
                            && searches > deck.size<Energy>()
                        ) {
                            searches = deck.size<Energy>();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            if (!opposing) {
                                announce(SEARCH_SAME_TYPE_ANNOUNCEMENT);
                                
                                if (last_drawn->get_type() == FIGHTER_TYPE) {
                                    index = deck.choose<Fighter>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                }
                                
                                else if (last_drawn->get_type() == SUPPORTER_TYPE) {
                                    index = deck.choose<Supporter>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                }
                                
                                else {
                                    index = deck.choose<Energy>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                }
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_SAME_TYPE_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            hand.store(deck.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                    
                    // The deck is searched for a card to draw.
                    else {
                        int searches = std::stoi(effects[i][1]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (searches > deck.size()) {
                            searches = deck.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            if (deck.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(TO_SEARCH_ANNOUNCEMENT);
                                
                                index = deck.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(TO_SEARCH_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            hand.store(deck.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                }
            
                // Switches in a fighter from the bench.
                else if (effects[i][0] == SWITCH_EFFECT) {
                    if (fighters.size() > 1) {
                        int index;
                        
                        // The player's sole benched fighter is switched in.
                        if (fighters.size() == 2) {
                            index = 1;
                        }
                        
                        // The player chooses a fighter to switch in.
                        else if (!opposing) {
                            announce(TO_SWITCH_ANNOUNCEMENT);
                            index = choose_bench();
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent receives the index of the fighter.
                        else {
                            announce(TO_SWITCH_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            
                            // A message is waited for in another thread.
                            message = EMPTY_MESSAGE;
                            messenger_thread.new_thread(
                                MessengerPackage::get_message,
                                &messenger_package
                            );
                        }
                        
                        // The fighter is switched in and the switch is announced.
                        switch_in(index);
                    }
                }
                
                // Switches in an opposing fighter from the bench.
                else if (effects[i][0] == HOOK_EFFECT) {
                    if (opponent->fighters.size() > 1) {
                        int index;
                        
                        // The opponent's sole benched fighter is switched in.
                        if (opponent->fighters.size() == 2) {
                            index = 1;
                        }
                        
                        // The player chooses a fighter to switch in.
                        else if (!opposing) {
                            announce(TO_HOOK_ANNOUNCEMENT);
                            index = opponent->choose_bench();
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent receives the index of the fighter.
                        else {
                            announce(TO_HOOK_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            
                            // A message is waited for in another thread.
                            message = EMPTY_MESSAGE;
                            messenger_thread.new_thread(
                                MessengerPackage::get_message,
                                &messenger_package
                            );
                        }
                        
                        // The fighter is switched in and the switch is announced.
                        opponent->switch_in(index);
                    }
                }
                
                // The supporter card will not be discarded.
                else if (effects[i][0] == RECYCLE_EFFECT) {
                    // The card is not shuffled into the deck.
                    if (effects[i].size() > 1) {
                        // The card joins the life cards.
                        if (effects[i][1] == LIFE_EFFECT) {
                            life_cards.store(s);
                            announce(RECYCLE_LIFE_ANNOUNCEMENT);
                        }
                        
                        // The card is returned to hand.
                        else if (effects[i][1] == HAND_EFFECT) {
                            hand.store(s);
                            announce(RECYCLE_HAND_ANNOUNCEMENT);
                        }
                    }
                    
                    // The card is shuffled into the deck
                    else {
                        deck.store(s);
                        announce(RECYCLE_ANNOUNCEMENT);
                    }
                    
                    to_discard = false;
                }
            
                // Increases the damage dealt by attacks this turn.
                else if (effects[i][0] == POWER_EFFECT) {
                    // The opponent's attacks' damage is modified.
                    if (effects[i][1] == OPPONENT_EFFECT) {
                        opponent->affect(
                            effects[i][0]
                            + EFFECT_SEPARATOR
                            + effects[i][2]
                        );
                        
                        const std::string& power = effects[i][2];
                        announce(OPPONENT_POWER_ANNOUNCEMENT);
                    }
                    
                    // The player's attacks' damage is modified.
                    else {
                        affect(
                            effects[i][0]
                            + EFFECT_SEPARATOR
                            + effects[i][1]
                        );
                        
                        const std::string& power = effects[i][1];
                        announce(PLAYER_POWER_ANNOUNCEMENT);
                    }
                }
            
                // Heals a fighter.
                else if (effects[i][0] == HEAL_EFFECT) {
                    // Heals the previously chosen fighter.
                    if (effects[i][1] == CHOSEN_EFFECT) {
                        int index = last_chosen;
                        
                        // Fully heals the fighter.
                        if (effects[i][2] == UNIVERSAL_EFFECT) {
                            fighters[index].full_heal();
                            announce(FULL_HEAL_ANNOUNCEMENT);
                        }
                    }
                    
                    // Randomly distributes the healing for all fighters.
                    else if (effects[i][1] == DISTRIBUTE_EFFECT) {
                        // The total healing is extracted.
                        int total_healing = std::stoi(effects[i][2]);
                        
                        // A vector storing how much healing each
                        //   fighter should receive is initialised.
                        std::vector<int> healing;
                        
                        for (int i = 0; i < fighters.size(); ++i) {
                            healing.push_back(0);
                        }
                        
                        // A vector storing the maximum amount of
                        //   healing each fighter can receive.
                        std::vector<int> max_healing;
                        
                        // The indices of fighters that are not fully healed are stored.
                        std::vector<int> indices;
                        
                        // max_healing and indices are initialised.
                        for (int i = 0; i < fighters.size(); ++i) {
                            max_healing.push_back(fighters[i].max_healing());
                            
                            if (max_healing[i]) {
                                indices.push_back(i);
                            }
                        }
                        
                        for (int i = 0; i < total_healing && indices.size(); ++i) {
                            // A random fighter's healing is incremented.
                            int index = Random::get_int(generator, 0, indices.size() - 1);
                            ++healing[indices[index]];
                            
                            // If the fighter is fully healed, it can't be chosen again.
                            if (healing[indices[index]] == max_healing[indices[index]]) {
                                indices.erase(indices.cbegin() + index);
                            }
                        }
                        
                        // The fighters are healed.
                        for (int i = 0; i < fighters.size(); ++i) {
                            healing[i] = fighters[i].heal(healing[i]);
                            announce(HEAL_DISTRIBUTION_SELF_ANNOUNCEMENT);
                        }
                    }
                    
                    // Restores health to all of the player's fighters.
                    else if (effects[i][1] == SPLASH_EFFECT) {
                        int healing;
                        
                        // The healing depends on the number of cards discarded.
                        if (effects[i][2] == DRAW_COUNT_EFFECT) {
                            healing = std::stoi(effects[i][3]) * last_draws;
                        }
                        
                        // The healing is independent of other factors.
                        else {
                            healing = std::stoi(effects[i][2]);
                        }
                        
                        // All of the friendly fighters are healed.
                        for (int i = 0; i < fighters.size(); ++i) {
                            fighters[i].heal(healing);
                        }
                        
                        announce(HEAL_SPLASH_ANNOUNCEMENT);
                    }
                    
                    // Heals one of the player's fighters.
                    else {
                        // The amount of healing is extracted.
                        int healing = std::stoi(effects[i][1]);
                        
                        // The fighter to be healed.
                        int index;
                        
                        // If the player only has one fighter, it is healed.
                        if (fighters.size() == 1) {
                            index = 0;
                        }
                        
                        // Else, the player chooses a fighter to heal.
                        else if (!opposing) {
                            announce(TO_HEAL_ANNOUNCEMENT);
                            index = choose_fighter();
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent receives the index of the fighter to heal.
                        else {
                            announce(TO_HEAL_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            get_message();
                        }
                        
                        healing = fighters[index].heal(healing);
                        announce(HEAL_ANNOUNCEMENT);
                    }
                }
            
                // Discards random cards from the deck.
                else if (effects[i][0] == MILL_EFFECT) {
                    // Discards the player's own cards.
                    if (effects[i][1] == SELF_EFFECT) {
                        // The milled cards are banished.
                        if (effects[i][2] == BANISH_EFFECT) {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][3]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > deck.size()) {
                                mills = deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = deck.draw(generator);
                                the_void.store(last_drawn);
                                announce(MILL_SELF_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_SELF_BANISH_ANNOUNCEMENT);
                        }
                        
                        // The milled cards are discarded.
                        else {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][2]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > deck.size()) {
                                mills = deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = deck.draw(generator);
                                trash.store(last_drawn);
                                announce(MILL_SELF_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_SELF_ANNOUNCEMENT);
                        }
                    }
                    
                    // Mills based on last_draws.
                    else if (effects[i][1] == DRAW_COUNT_EFFECT) {
                        // The number of cards to mill is found.
                        int mills = last_draws;
                        
                        // The player can't discard more cards
                        //   than they have in their deck.
                        if (mills > opponent->deck.size()) {
                            mills = opponent->deck.size();
                        }
                        
                        // The cards are discarded and displayed.
                        for (int i = 0; i < mills; ++i) {
                            last_drawn = opponent->deck.draw(generator);
                            opponent->trash.store(last_drawn);
                            announce(MILL_PEEK_ANNOUNCEMENT);
                        }
                        
                        // The total number of cards discarded is displayed.
                        announce(MILL_ANNOUNCEMENT);
                    }
                    
                    // Discard the opponent's cards.
                    else {
                        // The milled cards are banished.
                        if (effects[i][1] == BANISH_EFFECT) {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][2]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > opponent->deck.size()) {
                                mills = opponent->deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = opponent->deck.draw(generator);
                                the_void.store(last_drawn);
                                announce(MILL_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_BANISH_ANNOUNCEMENT);
                        }
                        
                        // The milled cards are discarded.
                        else {
                            // The number of cards to mill is extracted.
                            int mills = std::stoi(effects[i][1]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > opponent->deck.size()) {
                                mills = opponent->deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = opponent->deck.draw(generator);
                                opponent->trash.store(last_drawn);
                                announce(MILL_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_ANNOUNCEMENT);
                        }
                    }
                }
            
                // Discards energy attached to a fighter.
                else if (effects[i][0] == DRAIN_EFFECT) {
                    // The drain affects the player's own fighters.
                    if (effects[i][1] == SELF_EFFECT) {
                        // Discards all of the energy attached to the chosen fighter.
                        if (effects[i][2] == UNIVERSAL_EFFECT) {
                            int index;
                            
                            // If the player only has one fighter,
                            //   the index is set for the active.
                            if (fighters.size() == 1) {
                                index = 0;
                            }
                            
                            // Else, the player chooses one of their fighters to drain.
                            else if (!opposing) {
                                announce(TO_DRAIN_ANNOUNCEMENT);
                                index = choose_fighter();
                                messenger.send(std::to_string(index));
                            }
                            
                            // Else, the opponent waits for the player to choose.
                            else {
                                announce(TO_DRAIN_ANNOUNCEMENT, false);
                                index = std::stoi(message);
                                get_message();
                            }
                            
                            // The drain is announced.
                            announce(DRAIN_SELF_UNIVERSAL_ANNOUNCEMENT);
                            
                            // The energy is drained.
                            trash.store(fighters[index].remove_energy());
                            
                            // The index is remembered.
                            last_chosen = index;
                        }
                    
                        // Only fighters from the player's bench are applicable.
                        else if (effects[i][2] == BENCH_EFFECT && fighters.size() > 1) {
                            // Discards all of the energy attached to the chosen fighter.
                            if (effects[i][3] == UNIVERSAL_EFFECT) {
                                int index;
                                
                                // If the player only has one fighter,
                                //   the index is set for the active.
                                if (fighters.size() == 2) {
                                    index = 1;
                                }
                                
                                // Else, the player chooses one of their fighters to drain.
                                else if (!opposing) {
                                    announce(TO_DRAIN_ANNOUNCEMENT);
                                    index = choose_bench();
                                    messenger.send(std::to_string(index));
                                }
                                
                                // Else, the opponent waits for the player to choose.
                                else {
                                    announce(TO_DRAIN_ANNOUNCEMENT, false);
                                    index = std::stoi(message);
                                    get_message();
                                }
                                
                                // The drain is announced.
                                announce(DRAIN_SELF_UNIVERSAL_ANNOUNCEMENT);
                                
                                // The energy is drained.
                                trash.store(fighters[index].remove_energy());
                                
                                // The index is remembered.
                                last_chosen = index;
                            }
                        }
                    }
                    
                    // The drain affects the opponent's fighters.
                    else {
                        // The number of energy cards to discard are extracted.
                        int discards = std::stoi(effects[i][1]);
                        
                        for (int i = 0; i < discards; ++i) {
                            // The index of the fighter to discard energy from.
                            int index;
                            
                            // If the opponent only has one fighter,
                            //   the index is set for the active.
                            if (opponent->fighters.size() == 1) {
                                index = 0;
                            }
                            
                            // Else, the player chooses one of the
                            //   opponent's fighters to drain.
                            else if (!opposing) {
                                announce(TO_DRAIN_ANNOUNCEMENT);
                                index = opponent->choose_fighter();
                                messenger.send(std::to_string(index));
                            }
                            
                            // Else, the opponent waits for the player to choose.
                            else {
                                announce(TO_DRAIN_ANNOUNCEMENT, false);
                                index = std::stoi(message);
                                get_message();
                            }
                            
                            // Energy can only be discarded if the fighter has energy.
                            if (opponent->fighters[index].get_energy().size()) {
                                int energy_index;
                            
                                // If the fighter only has one energy card, the index is set.
                                if (opponent->fighters[index].get_energy().size() == 1) {
                                    energy_index = 0;
                                }
                                
                                // Else, the player chooses one of the energy cards to drain.
                                else if (!opposing) {
                                    announce(DRAIN_ENERGY_ANNOUNCEMENT);
                                    energy_index = opponent->fighters[index].choose_energy(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    messenger.send(std::to_string(energy_index));
                                }
                                
                                // Else, the opponent waits for the player to choose.
                                else {
                                    announce(DRAIN_ENERGY_ANNOUNCEMENT, false);
                                    energy_index = std::stoi(message);
                                    get_message();
                                }
                                
                                announce(DRAIN_ANNOUNCEMENT);
                                opponent->trash.store(opponent->fighters[index].remove_energy(
                                    energy_index
                                ));
                            }
                        }
                    }
                }
                
                // Clears the effects on the fighter.
                else if (effects[i][0] == CLEAR_EFFECT) {
                    // The index defaults to the active.
                    int index = 0;
                    
                    // The fighter chosen for the last effect is chosen for this one.
                    if (effects[i].size() > 1 && effects[i][1] == CHOSEN_EFFECT) {
                        index = last_chosen;
                    }
                    
                    fighters[index].clear_effects();
                    announce(CLEAR_ANNOUNCEMENT);
                }
                
                // Returns the fighter and it previous ranks to hand.
                else if (effects[i][0] == BOUNCE_EFFECT) {
                    int index = last_chosen;
                    
                    if (index > 0) {
                        fighters[index].reset();
                        Fighter last_fighter(fighters[index]);
                        fighters.erase(fighters.cbegin() + index);
                        
                        while (true) {
                            // The fighter is returned to hand.
                            hand.store(last_fighter);
                            announce(BOUNCE_ANNOUNCEMENT);
                            
                            // The indices of previous ranks.
                            std::vector<int> indices;
                            
                            // The indices of the previous ranks are found.
                            for (int i = 0; i < trash.get_fighters().size(); ++i) {
                                if (
                                    last_fighter.get_old_rank()
                                    == trash.get_fighters()[i].get_name()
                                ) {
                                    indices.push_back(i);
                                }
                            }
                            
                            // A random previous rank is chosen to be returned to hand.
                            if (indices.size()) {
                                int rank_index = indices[
                                    Random::get_int(generator, 0, indices.size() - 1)
                                ];
                                
                                last_fighter = static_cast<Fighter&>(*trash.remove(rank_index));
                            }
                            
                            // No more previous ranks were found. The effect terminates.
                            else {
                                break;
                            }
                        }
                    }
                }
            
                // Damages the opponent's active fighter.
                else if (effects[i][0] == DAMAGE_EFFECT) {
                    // The damage is extracted.
                    int damage = std::stoi(effects[i][1]);
                    
                    // The opponent's active fighter is damaged.
                    damage = opponent->fighters[0].damage(damage);
                    announce(DAMAGE_ANNOUNCEMENT);
                }
            
                // Can damage any opposing fighter.
                else if (effects[i][0] == SNIPE_EFFECT) {
                    int index;
                    
                    // The target must be the active, if it is the only fighter.
                    if (opponent->fighters.size() == 1) {
                        index = 0;
                    }
                    
                    // The player chooses a fighter to deal damage to.
                    else if (!opposing) {
                        announce(TO_SNIPE_ANNOUNCEMENT);
                        index = opponent->choose_fighter();
                        messenger.send(std::to_string(index));
                    }
                    
                    // The opponent waits for the player to choose.
                    else {
                        // The snipe choice is waited for.
                        announce(TO_SNIPE_ANNOUNCEMENT, false);
                        index = std::stoi(message);
                        
                        // A message is waited for in another thread.
                        message = EMPTY_MESSAGE;
                        messenger_thread.new_thread(
                            MessengerPackage::get_message,
                            &messenger_package
                        );
                    }
                    
                    int snipe = std::stoi(effects[i][1]);
                    
                    // The snipe has additional effects.
                    if (effects[i].size() > 2) {
                        // The snipe's damage can be modified.
                        if (effects[i][2] == POWER_EFFECT) {
                            // The snipe's damage is affected by the target's element.
                            if (
                                effects[i][3]
                                == opponent->fighters[index].get_element()
                            ) {
                                snipe += std::stoi(effects[i][4]);
                            }
                        }
                    }
                    
                    snipe = opponent->fighters[index].damage(snipe);
                    
                    announce(SNIPE_ANNOUNCEMENT);
                }
                
                // Returns all energy cards in play to the owners' hands.
                else if (effects[i][0] == ENERGY_BOUNCE_EFFECT) {
                    for (int i = 0; i < fighters.size(); ++i) {
                        hand.store(fighters[i].remove_energy());
                    }
                    
                    for (int i = 0; i < opponent->fighters.size(); ++i) {
                        opponent->hand.store(opponent->fighters[i].remove_energy());
                    }
                    
                    announce(ENERGY_BOUNCE_ANNOUNCEMENT);
                }
                
                // Maximally ranks up a fighter with cards from the deck.
                else if (effects[i][0] == TRAIN_EFFECT) {
                    // The index of the fighter to rank up.
                    int index;
                    
                    // The active fighter is chosen if it is the only fighter.
                    if (fighters.size() == 1) {
                        index = 0;
                    }
                    
                    // The player chooses the fighter.
                    else if (!opposing) {
                        announce(TRAIN_ANNOUNCEMENT);
                        index = choose_fighter();
                        messenger.send(std::to_string(index));
                    }
                    
                    // The opponent waits for the player's choice.
                    else {
                        announce(TRAIN_ANNOUNCEMENT, false);
                        index = std::stoi(message);
                        get_message();
                    }
                    
                    // Loop to maximally rank up the fighter.
                    while (true) {
                        // The indices of fighters that can rank up from the chosen fighter.
                        std::vector<int> indices;
                        
                        // The indices are found.
                        for (int i = 0; i < deck.get_fighters().size(); ++i) {
                            if (
                                deck.get_fighters()[i].get_old_rank()
                                == fighters[index].get_name()
                            ) {
                                indices.push_back(i);
                            }
                        }
                        
                        // A fighter can rank up from this fighter.
                        if (indices.size()) {
                            std::unique_ptr<Card> card(deck.remove(indices[
                                Random::get_int(generator, 0, indices.size() - 1)
                            ]));
                            rank_up(static_cast<Fighter&>(*card), index);
                        }
                        
                        // No fighters in the deck can rank up into this fighter.
                        else {
                            break;
                        }
                    }
                }
            
                // Cards in hand that share this card's name
                //   are discarded at the end of the turn.
                else if (effects[i][0] == END_DISCARD_EFFECT) {
                    affect(
                        std::string(END_DISCARD_EFFECT)
                        + EFFECT_SEPARATOR
                        + s.get_name()
                    );
                }
            
                // Cripples the opponent's active fighter (no retreat).
                else if (effects[i][0] == CRIPPLE_EFFECT) {
                    opponent->fighters[0].affect(effects[i][0]);
                    announce(CRIPPLE_ANNOUNCEMENT);
                }
            
                // Terminates the effect resolution if the player has attacked this turn.
                else if (effects[i][0] == ATTACKLESS_EFFECT && attacked) {
                    break;
                }
                
                // Terminates the effect resolution if the deck is not empty.
                else if (effects[i][0] == EMPTY_DECK_EFFECT && deck.size()) {
                    break;
                }
                
                // Terminates the effect resolution if the hand is not empty.
                else if (effects[i][0] == EMPTY_HAND_EFFECT && hand.size()) {
                    break;
                }
                
                // Terminates the effect resolution if the bench is not empty.
                else if (effects[i][0] == EMPTY_BENCH_EFFECT && fighters.size() > 1) {
                    break;
                }
            
                // Reduces the opponent's number of plays for next turn.
                else if (effects[i][0] == DEPLAY_EFFECT) {
                    // The number of deplays are found.
                    int deplays = std::stoi(effects[i][1]);
                    
                    // The opponent's plays are reduced.
                    opponent->plays -= deplays;
                    
                    // The opponent's cannot have a negative number of plays.
                    if (opponent->plays < 0) {
                        opponent->plays = 0;
                    }
                    
                    // The deplays are announced.
                    announce(DEPLAY_ANNOUNCEMENT);
                }
            
                // Modifies the number of card plays for this turn.
                else if (effects[i][0] == EXTRA_PLAY_EFFECT) {
                    int extra_plays = std::stoi(effects[i][1]);
                    plays += extra_plays;
                    announce(EXTRA_PLAY_ANNOUNCEMENT);
                }
                
                // Modifies the number of card plays for next turn.
                else if (effects[i][0] == OVERLOAD_EFFECT) {
                    affect(
                        effects[i][0]
                        + EFFECT_SEPARATOR
                        + effects[i][1]
                    );
                    
                    const std::string& overload = effects[i][1];
                    announce(OVERLOAD_ANNOUNCEMENT);
                }
            
                // Roots the opponent's active fighter (no switch).
                else if (effects[i][0] == ROOT_EFFECT) {
                    opponent->fighters[0].affect(effects[i][0]);
                    opponent->fighters[0].affect(DOUBLE_ROOT_EFFECT);
                    announce(ROOT_OPPONENT_ANNOUNCEMENT);
                }
            
                // Defeats the opponent's active fighter if its health is low enough.
                else if (effects[i][0] == ASSASSINATE_EFFECT) {
                    if (
                        opponent->fighters[0].get_health()
                        <= round(
                            std::stod(effects[i][1])
                            * opponent->fighters[0].get_max_health()
                        )
                    ) {
                        opponent->fighters[0].defeat();
                    }
                }
            
                // Increases the damage dealt by attacks for the rest of the duel.
                else if (effects[i][0] == POWER_AURA_EFFECT) {
                    affect(
                        effects[i][0]
                        + EFFECT_SEPARATOR
                        + effects[i][1]
                    );
                    
                    opponent->affect(
                        effects[i][0]
                        + EFFECT_SEPARATOR
                        + effects[i][1]
                    );
                    
                    const std::string& power = effects[i][1];
                    announce(POWER_AURA_ANNOUNCEMENT);
                }
            }
            
            // The supporter card is moved to the trash (usually).
            if (to_discard) {
                trash.store(s);
            }
        }
        
        /**
         * Allows the player to attach an energy card to a fighter card.
         */
        void play(const Energy& e) noexcept {
            // A pointer to the fighter that the energy card will be attached to.
            Fighter* recipient = nullptr;
            
            // The supporter card being played is announced.
            announce(ENERGY_ANNOUNCEMENT);
            
            // The effects are extracted.
            const std::vector<std::vector<std::string>>& effects = e.get_effects();
            
            for (int i = 0; i < effects.size(); ++i) {
                // The energy card allows the player to draw.
                if (effects[i][0] == DRAW_EFFECT) {
                    int draws = std::stoi(effects[i][1]);
                    
                    // The number of card draws cannot exceed
                    //   the number of cards in the deck.
                    if (draws > deck.size()) {
                        draws = deck.size();
                    }
                    
                    // The opponent only sees the number of draws.
                    if (opposing) {
                        draw(draws);
                        announce(DRAW_ANNOUNCEMENT);
                    }
                    
                    // The player sees what was drawn.
                    else {
                        for (int j = 0; j < draws; ++j) {
                            draw(1);
                            announce(LAST_DRAWN_ANNOUNCEMENT);
                        }
                        
                        announce(DRAW_ANNOUNCEMENT);
                    }
                }
                
                // The energycard discards cards.
                else if (effects[i][0] == DISCARD_EFFECT) {
                    // Discards all of the cards in the hand.
                    if (effects[i][1] == UNIVERSAL_EFFECT) {
                        int discards = hand.size();
                        announce(DISCARD_ALL_ANNOUNCEMENT);
                        discard();
                    }
                
                    // Discards a number of chosen cards from the hand.
                    else {
                        int discards = std::stoi(effects[i][1]);
                        
                        if (discards > hand.size()) {
                            discards = hand.size();
                        }
                        
                        // The player chooses cards to discard.
                        for (int i = 0; i < discards; ++i) {
                            int index;
                            
                            // There is only one option.
                            if (hand.size() == 1) {
                                index = 0;
                            }
                            
                            // The player chooses a card.
                            else if (!opposing) {
                                announce(TO_DISCARD_ANNOUNCEMENT);
                                
                                index = hand.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(TO_DISCARD_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            if (opposing) {
                                announce(DISCARD_PEEK_ANNOUNCEMENT);
                            }
                            
                            trash.store(hand.remove(index));
                        }
                        
                        announce(DISCARD_ANNOUNCEMENT);
                    }
                }
            
                // Modifies the number of card plays for this turn.
                else if (effects[i][0] == EXTRA_PLAY_EFFECT) {
                    int extra_plays = std::stoi(effects[i][1]);
                    plays += extra_plays;
                    announce(EXTRA_PLAY_ANNOUNCEMENT);
                }
            
                // Modifies the number of card plays for next turn.
                else if (effects[i][0] == OVERLOAD_EFFECT) {
                    affect(
                        effects[i][0]
                        + EFFECT_SEPARATOR
                        + effects[i][1]
                    );
                    
                    const std::string& overload = effects[i][1];
                    announce(OVERLOAD_ANNOUNCEMENT);
                }
            }
            
            // If the player has multiple fighters in play,
            //   they must select one to attach the energy to.
            if (fighters.size() > 1) {
                int index;
                
                // The player chooses the recipient of the energy.
                if (!opposing) {
                    index = attach(e);
                    
                    messenger.send(std::to_string(index));
                }
                
                // The opponent awaits the player's choice.
                else {
                    // The opponent is notifed that the player is choosing a fighter.
                    announce(ATTACHMENT_STRING, false);
                    
                    // The attachment indexed is received.
                    index = std::stoi(message);
                    
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                }
                
                // The fighter at the index is chosen to be the recipient.
                recipient = &fighters[index];
            }
            
            // Else, the player only has a single fighter in
            //   play, so the energy is attached to that fighter.
            else {
                recipient = &fighters[0];
            }
            
            recipient->attach(e);
            
            announce(ATTACHMENT_ANNOUNCEMENT);
        }
        
        /**
         * Allows the player to choose a fighter to attach energy to.
         */
        int attach(const Energy& e) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The attach buttons are initialised.
            std::vector<Button> attach_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                attach_buttons.push_back(
                    Button(
                        renderer.render(
                            ATTACH_STRING,
                            ATTACH_WIDTH * display.width(),
                            ATTACH_HEIGHT * display.height(),
                            ATTACH_SEPARATION * display.width()
                        ),
                        display,
                        ATTACH_X,
                        ATTACH_Y + i * ATTACH_Y_SHIFT
                    )
                );
            }
    
            // The preview button is initialised.
            Button preview_button(
                renderer.render(
                    display,
                    ATTACH_PREVIEW_STRING,
                    ATTACH_PREVIEW_WIDTH,
                    ATTACH_PREVIEW_HEIGHT,
                    ATTACH_PREVIEW_SEPARATION
                ),
                display,
                ATTACH_PREVIEW_X,
                ATTACH_PREVIEW_Y
            );
    
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                preview_button.blit_to(display);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (fighters.size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < fighters.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    fighters[page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The attach button is displayed.
                    attach_buttons[i].blit_to(display);
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (fighters.size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // Allows the player to preview the played card.
                    else if (preview_button.get_rectangle().unclick()) {
                        e.render(display, renderer);
                        back_button.blit_to(display);
                        display.update();
                        
                        while (
                            !Events::unpress(NEXT_KEY)
                            && !Events::unpress(BACK_KEY)
                            && !back_button.get_rectangle().unclick()
                        ) {
                            Events::update();
                        }
                        
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < fighters.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                fighters[page * PAGE_COUNT + i].view(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a fighter card to attach to.
                            else if (attach_buttons[i].get_rectangle().unclick()) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Allows the player to choose a fighter to rank up.
         */
        int rank_up(const Fighter& f) const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The rank buttons are initialised.
            std::vector<Button> rank_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                rank_buttons.push_back(
                    Button(
                        renderer.render(
                            RANK_STRING,
                            RANK_WIDTH * display.width(),
                            RANK_HEIGHT * display.height(),
                            RANK_SEPARATION * display.width()
                        ),
                        display,
                        RANK_X,
                        RANK_Y + i * RANK_Y_SHIFT
                    )
                );
            }
    
            // The preview button is initialised.
            Button preview_button(
                renderer.render(
                    display,
                    RANK_PREVIEW_STRING,
                    RANK_PREVIEW_WIDTH,
                    RANK_PREVIEW_HEIGHT,
                    RANK_PREVIEW_SEPARATION
                ),
                display,
                RANK_PREVIEW_X,
                RANK_PREVIEW_Y
            );
    
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                preview_button.blit_to(display);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (fighters.size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < fighters.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    fighters[page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The rank button is displayed.
                    if (f.get_old_rank() == fighters[page * PAGE_COUNT + i].get_name()) {
                        rank_buttons[i].blit_to(display);
                    }
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (fighters.size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // Allows the player to preview the played card.
                    else if (preview_button.get_rectangle().unclick()) {
                        f.render(display, renderer);
                        back_button.blit_to(display);
                        display.update();
                        
                        while (
                            !Events::unpress(NEXT_KEY)
                            && !Events::unpress(BACK_KEY)
                            && !back_button.get_rectangle().unclick()
                        ) {
                            Events::update();
                        }
                        
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < fighters.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                fighters[page * PAGE_COUNT + i].view(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a fighter card to rank to.
                            else if (
                                f.get_old_rank() == fighters[page * PAGE_COUNT + i].get_name()
                                && rank_buttons[i].get_rectangle().unclick()
                            ) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Ranks up a fighter at the given index using the given rank up card.
         */
        void rank_up(Fighter new_rank, int index, bool to_life = false) noexcept {
            fighters[index].rank_up(new_rank);
            
            if (to_life) {
                life_cards.store(fighters[index]);
            }
            
            else if (new_rank.energy_effect_search(BOND_EFFECT)) {
                hand.store(fighters[index]);
            }
            
            else {
                trash.store(fighters[index]);
            }
            
            announce(RANK_UP_ANNOUNCEMENT);
            fighters[index] = new_rank;
        }
        
        /**
         * Allows the player to use their active fighter.
         */
        void use_active() noexcept {
            // The energy button is initialised.
            Button energy_button(
                renderer.render(
                    FIGHTER_ENERGY_STRING,
                    FIGHTER_ENERGY_WIDTH * display.width(),
                    FIGHTER_ENERGY_HEIGHT * display.height(),
                    FIGHTER_ENERGY_SEPARATION * display.width()
                ),
                display,
                FIGHTER_ENERGY_X,
                FIGHTER_ENERGY_Y
            );
            
            // The effects button is initialised.
            Button effects_button(
                renderer.render(
                    FIGHTER_EFFECTS_STRING,
                    FIGHTER_EFFECTS_WIDTH * display.width(),
                    FIGHTER_EFFECTS_HEIGHT * display.height(),
                    FIGHTER_EFFECTS_SEPARATION * display.width()
                ),
                display,
                FIGHTER_EFFECTS_X,
                FIGHTER_EFFECTS_Y
            );
            
            // The ability button is initialised.
            Button ability_button(
                renderer.render(
                    FIGHTER_ABILITY_STRING,
                    FIGHTER_ABILITY_WIDTH * display.width(),
                    FIGHTER_ABILITY_HEIGHT * display.height(),
                    FIGHTER_ABILITY_SEPARATION * display.width()
                ),
                display,
                FIGHTER_ABILITY_X,
                FIGHTER_ABILITY_Y
            );
            
            // The attack button is initialised.
            Button attack_button(
                renderer.render(
                    FIGHTER_ATTACK_STRING,
                    FIGHTER_ATTACK_WIDTH * display.width(),
                    FIGHTER_ATTACK_HEIGHT * display.height(),
                    FIGHTER_ATTACK_SEPARATION * display.width()
                ),
                display,
                FIGHTER_ATTACK_X,
                FIGHTER_ATTACK_Y
            );
            
            // The retreat button is initialised.
            Button retreat_button(
                renderer.render(
                    FIGHTER_RETREAT_STRING,
                    FIGHTER_RETREAT_WIDTH * display.width(),
                    FIGHTER_RETREAT_HEIGHT * display.height(),
                    FIGHTER_RETREAT_SEPARATION * display.width()
                ),
                display,
                FIGHTER_RETREAT_X,
                FIGHTER_RETREAT_Y
            );
            
            // True when this function should return.
            bool end = false;
            
            // The energy discount effects are extracted from the active fighter.
            std::vector<std::vector<std::string>> filtered(
                fighters[0].effect_search(FUEL_EFFECT)
            );
            
            // The total energy discount.
            int discount = 0;
            
            // The discount effects are resolved.
            for (int i = 0; i < filtered.size(); ++i) {
                // Discounted by the number of cards in the void.
                if (filtered[i][1] == VOID_EFFECT) {
                    discount += the_void.size() * std::stoi(filtered[i][2]);
                }
            }
            
            while (!end) {
                // The display is rendered.
                fighters[0].render(display, renderer);
                back_button.blit_to(display);
                energy_button.blit_to(display);
                effects_button.blit_to(display);
                
                if (fighters[0].ability_usable()) {
                    ability_button.blit_to(display);
                }
                
                if (
                    !effect_search(PREPARATION_EFFECT).size()
                    && !attacked
                    && fighters[0].attack_usable(discount)
                ) {
                    attack_button.blit_to(display);
                }
                
                if (
                    fighters.size() > 1
                    && (!retreated || fighter_effect_search(FREEDOM_EFFECT))
                    && fighters[0].retreat_usable(
                        fighter_effect_count(
                            AGILITY_AURA_EFFECT
                        )
                        + discount
                    )
                ) {
                    retreat_button.blit_to(display);
                }
                
                display.update();
                
                while (true) {
                    // The player can go back using the next or back buttons.
                    // The opponent mking a move sends the player back, as well.
                    if (
                        Events::unpress(NEXT_KEY)
                        || Events::unpress(BACK_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The energy can be viewed by clicking the energy button.
                    else if (energy_button.get_rectangle().unclick()) {
                        fighters[0].view_energy(display, renderer, back_button, message);
                        break;
                    }
                    
                    // The effects can be viewed by clicking the effects button.
                    else if (effects_button.get_rectangle().unclick()) {
                        fighters[0].view_effects(display, renderer, back_button, message);
                        break;
                    }
                    
                    // The ability can be used by clicking the ability button.
                    else if (
                        fighters[0].ability_usable()
                        && ability_button.get_rectangle().unclick()
                    ) {
                        use_ability(0);
                        
                        return;
                    }
                    
                    // The fighter can retreat by clicking the retreat button.
                    else if (
                        (!retreated || fighter_effect_search(FREEDOM_EFFECT))
                        && fighters[0].retreat_usable(
                            fighter_effect_count(
                                AGILITY_AURA_EFFECT
                            )
                            + discount
                        )
                        && retreat_button.get_rectangle().unclick()
                    ) {
                        retreat();
                        
                        return;
                    }
                    
                    // The fighter can attack by clicking the retreat button.
                    else if (
                        !effect_search(PREPARATION_EFFECT).size()
                        && !attacked
                        && fighters[0].attack_usable(discount)
                        && attack_button.get_rectangle().unclick()
                    ) {
                        // The opponent is notified of the attack.
                        messenger.send(ATTACK_MESSAGE);
                        
                        attack();
                        
                        return;
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Allows the player to use their benched fighters.
         */
        void use_bench() noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The bench size sprite is intialised.
            Sprite bench_size_sprite(
                renderer.render(
                    BENCH_SIZE_STRING,
                    BENCH_SIZE_WIDTH * display.width(),
                    BENCH_SIZE_HEIGHT * display.height(),
                    BENCH_SIZE_SEPARATION * display.width()
                )
            );
            
            // The ability buttons are initialised.
            std::vector<Button> ability_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                ability_buttons.push_back(
                    Button(
                        renderer.render(
                            ABILITY_STRING,
                            ABILITY_WIDTH * display.width(),
                            ABILITY_HEIGHT * display.height(),
                            ABILITY_SEPARATION * display.width()
                        ),
                        display,
                        ABILITY_X,
                        ABILITY_Y + i * ABILITY_Y_SHIFT
                    )
                );
            }
    
            // Determines which cards are displayed.
            int page = 0;
            
            // True if the function should return.
            bool end = false;
            
            while (!end) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                display.blit(bench_size_sprite, BENCH_SIZE_X, BENCH_SIZE_Y);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (fighters.size() - 2) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && BENCH_INDEX + page * PAGE_COUNT + i < fighters.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    fighters[BENCH_INDEX + page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The ability button is displayed, if it is usable.
                    if (fighters[BENCH_INDEX + page * PAGE_COUNT + i].ability_usable()) {
                        ability_buttons[i].blit_to(display);
                    }
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The user can return to the previous menu with
                    //   the use of the back button or submit key.
                    if (
                        Events::unpress(SUBMIT_KEY)
                        || Events::unpress(QUIT_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (fighters.size() - 2) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < fighters.size() - 1;
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                fighters[BENCH_INDEX + page * PAGE_COUNT + i].view(
                                    display,
                                    renderer,
                                    back_button,
                                    message
                                );
                                
                                found = true;
                                break;
                            }
                            
                            // Uses a fighter's ability.
                            else if (
                                fighters[BENCH_INDEX + page * PAGE_COUNT + i].ability_usable()
                                && ability_buttons[i].get_rectangle().unclick()
                            ) {
                                use_ability(BENCH_INDEX + page * PAGE_COUNT + i);
                                
                                return;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Allows the user to view the effects on the player.
         */
        void view_effects() const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The vectors of effects and values are inItialised.
            std::vector<std::string> effect_names;
            std::vector<std::string> effect_values;
            
            for (int i = 0; i < PLAYER_EXPLANATION_COUNT; ++i) {
                // A filtered effect store for macros to use.
                std::vector<std::vector<std::string>> filtered;
                int value;
            
                if (PLAYER_EFFECT_CONDITIONS(i)) {
                    effect_names.push_back(PLAYER_EFFECT_REPRESENTATIONS[i]);
                    effect_values.push_back(PLAYER_EFFECT_VALUES(i));
                }
            }
            
            // Determines which effects are displayed.
            int page = 0;
            
            // True if the function should return.
            bool end = false;
            
            while (!end) {
                // The sprites are blitted to the display.
                display.fill();
                back_button.blit_to(display);
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (static_cast<int>(effect_names.size()) - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < effect_names.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            renderer.render(
                                effect_names[page * PAGE_COUNT + i],
                                PAGE_WIDTH * display.width(),
                                PAGE_HEIGHT * display.height(),
                                PAGE_SEPARATION * display.width()
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The value of the effect is displayed.
                    display.blit(
                        renderer.render(
                            display,
                            EFFECT_VALUE_STRING,
                            EFFECT_VALUE_WIDTH,
                            EFFECT_VALUE_HEIGHT,
                            EFFECT_VALUE_SEPARATION
                        ),
                        EFFECT_VALUE_X,
                        EFFECT_VALUE_Y + i * EFFECT_VALUE_Y_SHIFT
                    );
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The user can return to the previous menu with
                    //   the use of the back button or submit key.
                    if (
                        Events::unpress(SUBMIT_KEY)
                        || Events::unpress(QUIT_KEY)
                        || back_button.get_rectangle().unclick()
                        || message != EMPTY_MESSAGE
                    ) {
                        end = true;
                        break;
                    }
                    
                    // The page number is decremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (static_cast<int>(effect_names.size()) - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < effect_names.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                explain(
                                    display,
                                    renderer,
                                    back_button,
                                    message,
                                    effect_names[page * PAGE_COUNT + i],
                                    effect_values[page * PAGE_COUNT + i]
                                );
                                
                                found = true;
                                break;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Displays the announcement passed.
         * The function returns if the user chooses to advance or
         *   the passed string is no longer equal to EMPTY_MESSAGE.
         */
        void announce(const std::string& announcement, bool skippable = true) noexcept {
            display.fill();
            display.blit(
                renderer.lined_render(
                    ANNOUNCEMENT_STRING,
                    ANNOUNCEMENT_WIDTH * display.width(),
                    ANNOUNCEMENT_HEIGHT * display.height(),
                    ANNOUNCEMENT_SEPARATION_X * display.width(),
                    ANNOUNCEMENT_MAX_WIDTH * display.width(),
                    ANNOUNCEMENT_SEPARATION_Y * display.height(),
                    ANNOUNCEMENT_JUSTIFICATION
                ),
                ANNOUNCEMENT_X,
                ANNOUNCEMENT_Y
            );
            
            if (skippable) {
                next_button.blit_to(display);
            }
            
            display.update();
            
            // The player proceeds at their own discretion
            //   or if the opponent took an action.
            if (skippable) {
                while (
                    !Events::unpress(BACK_KEY)
                    && !Events::unpress(NEXT_KEY)
                    && !next_button.get_rectangle().unclick()
                    && message == EMPTY_MESSAGE
                ) {
                    Events::update();
                }
            }
            
            // The player proceeds when the opponent takes an action.
            else {
                while (message == EMPTY_MESSAGE) {
                    Events::update();
                }
            }
        }
        
        /**
         * Resets the player's attack, retreat, and ability uses.
         * Performs other end of turn effects on the player.
         */
        void reset() noexcept {
            attacked = false;
            retreated = false;
            
            reset_plays();
            reset_abilities();
            prepare();
            depower();
            end_discard();
            banishment();
            curse();
            heal_aura();
            vincible();
            unroot();
            reset_agility();
            uncripple();
            unimpair();
            end_draw();
        }
        
        /**
         * Returns true if any of the player's fighters
         *   can rank up into the given fighter.
         */
        bool rank_search(const Fighter& f) const noexcept {
            for (int i = 0; i < fighters.size(); ++i) {
                if (fighters[i].get_name() == f.get_old_rank()) {
                    return true;
                }
            }
            
            return false;
        }
        
        /**
         * Uses a fighter's ability.
         */
        void use_ability(int index = -1) noexcept {
            // The opponent receives the index.
            if (index < 0) {
                opposing = true;
                
                while (message == EMPTY_MESSAGE) {
                    Events::update();
                }
                
                // The index of the fighter is extracted.
                index = std::stoi(message);
                
                // The message from the opponent is awaited.
                message = EMPTY_MESSAGE;
                messenger_thread.new_thread(
                    MessengerPackage::get_message,
                    &messenger_package
                );
            }
            
            // The player notifies the opponent of the ability use.
            else {
                opposing = false;
                
                messenger.send(ABILITY_MESSAGE);
                messenger.send(std::to_string(index));
            }
            
            // A copy of the ability is extracted.
            Ability ability(
                fighters[index].get_ability()
            );
            
            // The effects are extracted.
            const std::vector<std::vector<std::string>>& effects = ability.get_effects();
            
            // The ability use is announced.
            announce(ABILITY_ANNOUNCEMENT);
            
            // The ability uses are incremented.
            fighters[index].use_ability();
        
            // The ability's effects are resolved.
            for (int i = 0; i < effects.size(); ++i) {
                // The fighter switches in if it was on the bench.
                if (effects[i][0] == SWITCH_IN_EFFECT) {
                    // Switching in can only work from the bench.
                    if (index) {
                        switch_in(index);
                        
                        // The fighter is now in the active position.
                        index = 0;
                        
                        // If switching in also boosts power, the fighter is empowered.
                        if (
                            effects[i].size() > 1
                            && effects[i][1] == POWER_EFFECT
                        ) {
                            fighters[index].affect(
                                effects[i][1]
                                + EFFECT_SEPARATOR
                                + effects[i][2]
                            );
                            
                            const std::string& power = effects[i][2];
                            announce(POWER_ANNOUNCEMENT);
                        }
                    }
                }
                
                // The ability allows the player to draw.
                else if (effects[i][0] == DRAW_EFFECT) {
                    int draws = std::stoi(effects[i][1]);
                    
                    // The number of card draws cannot exceed
                    //   the number of cards in the deck.
                    if (draws > deck.size()) {
                        draws = deck.size();
                    }
                    
                    // The opponent only sees the number of draws.
                    if (opposing) {
                        draw(draws);
                        announce(DRAW_ANNOUNCEMENT);
                    }
                    
                    // The player sees what was drawn.
                    else {
                        for (int j = 0; j < draws; ++j) {
                            draw(1);
                            announce(LAST_DRAWN_ANNOUNCEMENT);
                        }
                        
                        announce(DRAW_ANNOUNCEMENT);
                    }
                }
                
                // Allows the player to search for cards in their deck.
                else if (effects[i][0] == SEARCH_EFFECT) {
                    // The card is stolen from the opponent.
                    if (effects[i][1] == OPPONENT_EFFECT) {
                        // The trash is searched for a card to draw.
                        if (effects[i][2] == TRASH_EFFECT) {
                            int searches = std::stoi(effects[i][3]);
                            
                            // The number of searches can't exceed
                            //   the number of cards in the card store.
                            if (searches > opponent->trash.size()) {
                                searches = opponent->trash.size();
                            }
                            
                            // The player chooses cards to search for.
                            for (int i = 0; i < searches; ++i) {
                                int index;
                                
                                if (opponent->trash.size() == 1) {
                                    index = 0;
                                }
                                
                                else if (!opposing) {
                                    announce(SEARCH_OPPONENT_TRASH_ANNOUNCEMENT);
                                    
                                    index = opponent->trash.choose(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(SEARCH_OPPONENT_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                announce(SEARCH_OPPONENT_TRASH_PEEK_ANNOUNCEMENT);
                                hand.store(opponent->trash.remove(index));
                            }
                            
                            announce(SEARCH_ANNOUNCEMENT);
                        }
                        
                        // The hand is searched for a card to draw a copy of.
                        else if (effects[i][2] == HAND_EFFECT) {
                            int searches = std::stoi(effects[i][3]);
                            
                            // The number of searches can't exceed
                            //   the number of cards in the card store.
                            if (searches > opponent->hand.size()) {
                                searches = opponent->hand.size();
                            }
                            
                            // The player chooses cards to search for.
                            for (int i = 0; i < searches; ++i) {
                                int index;
                                
                                if (opponent->hand.size() == 1) {
                                    index = 0;
                                }
                                
                                else if (!opposing) {
                                    announce(SEARCH_OPPONENT_HAND_ANNOUNCEMENT);
                                    
                                    index = opponent->hand.choose(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(SEARCH_OPPONENT_HAND_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                // A copy is drawn.
                                hand.store(opponent->hand[index]);
                            }
                            
                            announce(SEARCH_ANNOUNCEMENT);
                        }
                    }
                    
                    // The card searched for is to be discarded.
                    else if (effects[i][1] == DISCARD_EFFECT) {
                        // The number of discard searches are extracted.
                        int discards = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (discards > deck.size()) {
                            discards = deck.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < discards; ++i) {
                            int index;
                            
                            if (deck.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(SEARCH_DISCARD_ANNOUNCEMENT);
                                
                                index = deck.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_DISCARD_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            announce(SEARCH_DISCARD_PEEK_ANNOUNCEMENT);
                            trash.store(deck.remove(index));
                        }
                        
                        announce(DISCARD_ANNOUNCEMENT);
                    }
                    
                    // The card searched for is to be banished.
                    else if (effects[i][1] == BANISH_EFFECT) {
                        // The number of banish searches are extracted.
                        int banishes = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (banishes > deck.size()) {
                            banishes = deck.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < banishes; ++i) {
                            int index;
                            
                            if (deck.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(SEARCH_BANISH_ANNOUNCEMENT);
                                
                                index = deck.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_BANISH_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            announce(SEARCH_BANISH_PEEK_ANNOUNCEMENT);
                            the_void.store(deck.remove(index));
                        }
                        
                        announce(BANISH_ANNOUNCEMENT);
                    }
                    
                    // The trash is searched for a card to draw.
                    else if (effects[i][1] == TRASH_EFFECT) {
                        if (effects[i][2] == ENERGY_TYPE) {
                            int searches = std::stoi(effects[i][3]);
                            
                            // The number of searches can't exceed
                            //   the number of cards in the deck.
                            if (searches > trash.size<Energy>()) {
                                searches = trash.size<Energy>();
                            }
                            
                            // The player chooses cards to search for.
                            for (int i = 0; i < searches; ++i) {
                                int index;
                                
                                if (trash.size<Energy>() == 1) {
                                    index = trash.size() - 1;
                                }
                                
                                else if (!opposing) {
                                    announce(SEARCH_TRASH_ENERGY_ANNOUNCEMENT);
                                    
                                    index = trash.choose<Energy>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(SEARCH_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                announce(SEARCH_TRASH_PEEK_ANNOUNCEMENT);
                                hand.store(trash.remove(index));
                            }
                            
                            announce(SEARCH_ANNOUNCEMENT);
                        }
                        
                        else {
                            int searches = std::stoi(effects[i][2]);
                            
                            // The number of searches can't exceed
                            //   the number of cards in the deck.
                            if (searches > trash.size()) {
                                searches = trash.size();
                            }
                            
                            // The player chooses cards to search for.
                            for (int i = 0; i < searches; ++i) {
                                int index;
                                
                                if (trash.size() == 1) {
                                    index = 0;
                                }
                                
                                else if (!opposing) {
                                    announce(SEARCH_TRASH_ANNOUNCEMENT);
                                    
                                    index = trash.choose(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                else {
                                    announce(SEARCH_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                announce(SEARCH_TRASH_PEEK_ANNOUNCEMENT);
                                hand.store(trash.remove(index));
                            }
                            
                            announce(SEARCH_ANNOUNCEMENT);
                        }
                    }
                    
                    // The life cards are searched for a card to draw.
                    else if (effects[i][1] == LIFE_EFFECT) {
                        int searches = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the
                        //   number of cards in the life card store.
                        if (searches > life_cards.size()) {
                            searches = life_cards.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            // There is only one option.
                            if (life_cards.size() == 1) {
                                index = 0;
                            }
                            
                            // The player chooses a card.
                            else if (!opposing) {
                                announce(SEARCH_LIFE_ANNOUNCEMENT);
                                
                                index = life_cards.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            // The opponent waits for the player's choice.
                            else {
                                announce(SEARCH_LIFE_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                get_message();
                            }
                            
                            hand.store(life_cards.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                    
                    // The deck is searched for an energy card.
                    else if (effects[i][1] == ENERGY_TYPE) {
                        int searches = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (searches > deck.size<Energy>()) {
                            searches = deck.size<Energy>();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            // There is only one option.
                            if (deck.size<Energy>() == 1) {
                                index = deck.size() - 1;
                            }
                            
                            // The player chooses a card.
                            else if (!opposing) {
                                announce(SEARCH_ENERGY_ANNOUNCEMENT);
                                
                                index = deck.choose<Energy>(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_ENERGY_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            hand.store(deck.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                    
                    // The deck is searched for a card of the same type as last_drawn.
                    else if (effects[i][1] == SAME_TYPE_EFFECT) {
                        int searches = std::stoi(effects[i][2]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (
                            last_drawn->get_type() == FIGHTER_TYPE
                            && searches > deck.size<Fighter>()
                        ) {
                            searches = deck.size<Fighter>();
                        }
                        
                        else if (
                            last_drawn->get_type() == SUPPORTER_TYPE
                            && searches > deck.size<Supporter>()
                        ) {
                            searches = deck.size<Supporter>();
                        }
                        
                        else if (searches > deck.size<Energy>()) {
                            searches = deck.size<Energy>();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            if (!opposing) {
                                announce(SEARCH_SAME_TYPE_ANNOUNCEMENT);
                                
                                if (last_drawn->get_type() == FIGHTER_TYPE) {
                                    index = deck.choose<Fighter>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                }
                                
                                else if (last_drawn->get_type() == SUPPORTER_TYPE) {
                                    index = deck.choose<Supporter>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                }
                                
                                else {
                                    index = deck.choose<Energy>(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                }
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(SEARCH_SAME_TYPE_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            hand.store(deck.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                    
                    // The deck is searched for a card to draw.
                    else {
                        int searches = std::stoi(effects[i][1]);
                        
                        // The number of searches can't exceed the number of cards in the deck.
                        if (searches > deck.size()) {
                            searches = deck.size();
                        }
                        
                        // The player chooses cards to search for.
                        for (int i = 0; i < searches; ++i) {
                            int index;
                            
                            if (deck.size() == 1) {
                                index = 0;
                            }
                            
                            else if (!opposing) {
                                announce(TO_SEARCH_ANNOUNCEMENT);
                                
                                index = deck.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(TO_SEARCH_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            hand.store(deck.remove(index));
                        }
                        
                        announce(SEARCH_ANNOUNCEMENT);
                    }
                }
            
                // Discards random cards from the deck.
                else if (effects[i][0] == MILL_EFFECT) {
                    // Discards the player's own cards.
                    if (effects[i][1] == SELF_EFFECT) {
                        // The milled cards are banished.
                        if (effects[i][2] == BANISH_EFFECT) {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][3]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > deck.size()) {
                                mills = deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = deck.draw(generator);
                                the_void.store(last_drawn);
                                announce(MILL_SELF_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_SELF_BANISH_ANNOUNCEMENT);
                        }
                        
                        // The milled cards are discarded.
                        else {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][2]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > deck.size()) {
                                mills = deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = deck.draw(generator);
                                trash.store(last_drawn);
                                announce(MILL_SELF_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_SELF_ANNOUNCEMENT);
                        }
                    }
                    
                    // Mills based on last_draws.
                    else if (effects[i][1] == DRAW_COUNT_EFFECT) {
                        // The number of cards to mill is found.
                        int mills = last_draws;
                        
                        // The player can't discard more cards
                        //   than they have in their deck.
                        if (mills > opponent->deck.size()) {
                            mills = opponent->deck.size();
                        }
                        
                        // The cards are discarded and displayed.
                        for (int i = 0; i < mills; ++i) {
                            last_drawn = opponent->deck.draw(generator);
                            opponent->trash.store(last_drawn);
                            announce(MILL_PEEK_ANNOUNCEMENT);
                        }
                        
                        // The total number of cards discarded is displayed.
                        announce(MILL_ANNOUNCEMENT);
                    }
                    
                    // Discard the opponent's cards.
                    else {
                        // The milled cards are banished.
                        if (effects[i][1] == BANISH_EFFECT) {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][2]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > opponent->deck.size()) {
                                mills = opponent->deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = opponent->deck.draw(generator);
                                the_void.store(last_drawn);
                                announce(MILL_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_BANISH_ANNOUNCEMENT);
                        }
                        
                        // The milled cards are discarded.
                        else {
                            // The number of cards to mill is extracted.
                            int mills = std::stoi(effects[i][1]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > opponent->deck.size()) {
                                mills = opponent->deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = opponent->deck.draw(generator);
                                opponent->trash.store(last_drawn);
                                announce(MILL_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_ANNOUNCEMENT);
                        }
                    }
                }
                
                // Heals a fighter.
                else if (effects[i][0] == HEAL_EFFECT) {
                    // Heals the user.
                    if (effects[i][1] == SELF_EFFECT) {
                        // The amount to heal is extracted.
                        int healing = std::stoi(effects[i][2]);
                        healing = fighters[index].heal(healing);
                        announce(HEAL_ANNOUNCEMENT);
                    }
                    
                    // Heals any friendly fighter (dependent on the void's size).
                    else if (effects[i][1] == VOID_EFFECT && the_void.size()) {
                        // The amount of healing is extracted.
                        int healing = the_void.size() * std::stoi(effects[i][2]);
                        
                        // The maximum amount of healing is extracted.
                        int max_healing = std::stoi(effects[i][3]);
                        
                        // The healing cannot exceed the maximum.
                        if (healing > max_healing) {
                            healing = max_healing;
                        }
                        
                        // The fighter to be healed.
                        int index;
                        
                        // If the player only has one fighter, it is healed.
                        if (fighters.size() == 1) {
                            index = 0;
                        }
                        
                        // Else, the player chooses a fighter to heal.
                        else if (!opposing) {
                            announce(TO_HEAL_ANNOUNCEMENT);
                            index = choose_fighter();
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent receives the index of the fighter to heal.
                        else {
                            announce(TO_HEAL_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            get_message();
                        }
                        
                        healing = fighters[index].heal(healing);
                        announce(HEAL_ANNOUNCEMENT);
                    }
                }
            
                // Only active fighters can use the ability's effects.
                else if (effects[i][0] == ACTIVE_EFFECT && !index) {
                    // Switches in an opposing fighter from the bench.
                    if (effects[i][1] == HOOK_EFFECT) {
                        if (opponent->fighters.size() > BENCH_INDEX) {
                            int index;
                            
                            // The opponent's sole benched fighter is switched in.
                            if (opponent->fighters.size() == 2) {
                                index = 1;
                            }
                            
                            // The player chooses a fighter to switch in.
                            else if (!opposing) {
                                announce(TO_HOOK_ANNOUNCEMENT);
                                index = opponent->choose_bench();
                                messenger.send(std::to_string(index));
                            }
                            
                            // The opponent receives the index of the fighter.
                            else {
                                announce(TO_HOOK_ANNOUNCEMENT, false);
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            // The fighter is switched in and the switch is announced.
                            opponent->switch_in(index);
                        }
                    }
                }
            
                // The fighter is ranked down into a previous rank in the trash.
                else if (effects[i][0] == RANK_DOWN_EFFECT) {
                    // The indices of fighters that can rank down from the chosen fighter.
                    std::vector<int> indices;
                    
                    // The indices are found.
                    for (int i = 0; i < deck.get_fighters().size(); ++i) {
                        if (
                            deck.get_fighters()[i].get_name()
                            == fighters[index].get_old_rank()
                        ) {
                            indices.push_back(i);
                        }
                    }
                    
                    // A fighter can rank down from this fighter.
                    if (indices.size()) {
                        std::unique_ptr<Card> card(deck.remove(indices[
                            Random::get_int(generator, 0, indices.size() - 1)
                        ]));
                        Fighter& old_rank = static_cast<Fighter&>(*card);
                        fighters[index].rank_up(old_rank);
                        trash.store(fighters[index]);
                        announce(RANK_DOWN_ANNOUNCEMENT);
                        fighters[index] = old_rank;
                    
                        // The ability allows the player to search for cards in their deck.
                        if (effects[i][1] == SEARCH_EFFECT) {
                            // The trash is searched for a card to draw.
                            if (effects[i][2] == TRASH_EFFECT) {
                                int searches = std::stoi(effects[i][3]);
                                
                                // The number of searches can't exceed
                                //   the number of cards in the deck.
                                if (searches > trash.size()) {
                                    searches = trash.size();
                                }
                                
                                // The player chooses cards to search for.
                                for (int i = 0; i < searches; ++i) {
                                    int index;
                                    
                                    if (!opposing) {
                                        announce(SEARCH_TRASH_ANNOUNCEMENT);
                                        
                                        index = trash.choose(
                                            display,
                                            renderer,
                                            back_button
                                        );
                                        
                                        messenger.send(std::to_string(index));
                                    }
                                    
                                    else {
                                        announce(SEARCH_TRASH_ANNOUNCEMENT, false);
                                        
                                        index = std::stoi(message);
                                        
                                        // A message is waited for in another thread.
                                        message = EMPTY_MESSAGE;
                                        messenger_thread.new_thread(
                                            MessengerPackage::get_message,
                                            &messenger_package
                                        );
                                    }
                                    
                                    announce(SEARCH_TRASH_PEEK_ANNOUNCEMENT);
                                    hand.store(trash.remove(index));
                                }
                                
                                announce(SEARCH_ANNOUNCEMENT);
                            }
                        }
                    }
                }
            
                // Matching element energy from the deck is attached to the fighter.
                else if (effects[i][0] == ACCELERATION_EFFECT) {
                    // The number of energy cards to be attached.
                    int count = std::stoi(effects[i][1]);
                    
                    for (int i = 0; i < count; ++i) {
                        // The indices of energy cards that match in element.
                        std::vector<int> indices;
                        
                        // The indices are intialised.
                        for (int j = 0; j < deck.get_energy().size(); ++j) {
                            if (
                                deck.get_energy()[j].get_element()
                                == fighters[index].get_element()
                            ) {
                                indices.push_back(j);
                            }
                        }
                        
                        // If no valid energy cards were found, the process is terminated.
                        if (!indices.size()) {
                            break;
                        }
                        
                        // The index of the energy card to be attached is generated.
                        int energy_index =
                            indices[
                                Random::get_int(generator, 0, indices.size() - 1)
                            ]
                            + deck.get_fighters().size()
                            + deck.get_supporters().size()
                        ;
                        
                        // The energy card is attached to the fighter.
                        announce(ACCELERATION_ANNOUNCEMENT);
                        fighters[index].attach(
                            static_cast<Energy&>(
                                *deck.remove(energy_index)
                            )
                        );
                    }
                }
                
                // Random old ranks are banished from the trash.
                else if (effects[i][0] == ABANDON_EFFECT) {
                    // The number of abandons are extracted.
                    int count = std::stoi(effects[i][1]);
                    
                    // True if all of the abandons were successfully performed.
                    bool success = true;
                    
                    for (int i = 0; i < count; ++i) {
                        // The indices of the old ranks.
                        std::vector<int> indices;
                        
                        // The indices are initialised.
                        for (int j = 0; j < trash.get_fighters().size(); ++j) {
                            if (
                                trash[j].get_name()
                                == fighters[index].get_old_rank()
                            ) {
                                indices.push_back(j);
                            }
                        }
                        
                        if (!indices.size()) {
                            success = false;
                            break;
                        }
                        
                        // The index of the energy card to be attached is generated.
                        int fighter_index =
                            indices[
                                Random::get_int(generator, 0, indices.size() - 1)
                            ]
                        ;
                        
                        announce(ABANDON_ANNOUNCEMENT);
                        the_void.store(trash.remove(fighter_index));
                    }
                    
                    // Abandon effects only work if the abandons were successful.
                    if (success) {
                        // The ability allows the player to search for cards in their deck.
                        if (effects[i][2] == SEARCH_EFFECT) {
                            // The trash is searched for a card to draw.
                            if (effects[i][3] == TRASH_EFFECT) {
                                int searches = std::stoi(effects[i][4]);
                                
                                // The number of searches can't exceed
                                //   the number of cards in the deck.
                                if (searches > trash.size()) {
                                    searches = trash.size();
                                }
                                
                                // The player chooses cards to search for.
                                for (int i = 0; i < searches; ++i) {
                                    int index;
                                    
                                    if (!opposing) {
                                        announce(SEARCH_TRASH_ANNOUNCEMENT);
                                        
                                        index = trash.choose(
                                            display,
                                            renderer,
                                            back_button
                                        );
                                        
                                        messenger.send(std::to_string(index));
                                    }
                                    
                                    else {
                                        announce(SEARCH_TRASH_ANNOUNCEMENT, false);
                                        
                                        index = std::stoi(message);
                                        
                                        // A message is waited for in another thread.
                                        message = EMPTY_MESSAGE;
                                        messenger_thread.new_thread(
                                            MessengerPackage::get_message,
                                            &messenger_package
                                        );
                                    }
                                    
                                    announce(SEARCH_TRASH_PEEK_ANNOUNCEMENT);
                                    hand.store(trash.remove(index));
                                }
                                
                                announce(SEARCH_ANNOUNCEMENT);
                            }
                        }
                    
                        // Switches in an opposing fighter from the bench.
                        else if (effects[i][2] == HOOK_EFFECT) {
                            if (opponent->fighters.size() > 1) {
                                int index;
                                
                                // The opponent's sole benched fighter is switched in.
                                if (opponent->fighters.size() == 2) {
                                    index = 1;
                                }
                                
                                // The player chooses a fighter to switch in.
                                else if (!opposing) {
                                    announce(TO_HOOK_ANNOUNCEMENT);
                                    index = opponent->choose_bench();
                                    messenger.send(std::to_string(index));
                                }
                                
                                // The opponent receives the index of the fighter.
                                else {
                                    announce(TO_HOOK_ANNOUNCEMENT, false);
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                // The fighter is switched in and the switch is announced.
                                opponent->switch_in(index);
                            }
                    
                            // Cripples the opponent's active fighter (no retreat).
                            if (effects[i].size() > 3 && effects[i][3] == CRIPPLE_EFFECT) {
                                opponent->fighters[0].affect(effects[i][3]);
                                announce(CRIPPLE_ANNOUNCEMENT);
                            }
                        }
                    }
                }
                
                // Fusion summons a fighter from the hand if the conditions are met.
                else if (effects[i][0] == FUSION_EFFECT && !index) {
                    int fusion_count = 0;
                    
                    // The fighters with the same effect are defeated.
                    for (int i = 1; i < fighters.size(); ++i) {
                        if (effects == fighters[i].get_ability_effects()) {
                            fighters[i].defeat();
                            ++fusion_count;
                        }
                    }
                    
                    // The conditions were met.
                    if (fusion_count >= std::stoi(effects[i][1])) {
                        // The name of the ability should match the fusion fighter's old rank.
                        std::string name = ability.get_name();
                        
                        // The indices of the fusion cards.
                        std::vector<int> indices;
                        
                        // The indices are found.
                        for (int j = 0; j < hand.size<Fighter>(); ++j) {
                            if (hand.get_fighters()[j].get_old_rank() == name) {
                                indices.push_back(j);
                            }
                        }
                        
                        // The rank up only occurs if there is a valid fusion card in hand.
                        if (indices.size()) {
                            // The active fighter is ranked up into the fusion card.
                            rank_up(
                                static_cast<Fighter&>(
                                    *hand.remove(
                                        indices[
                                            Random::get_int(generator, 0, indices.size() - 1)
                                        ]
                                    )
                                ),
                                index,
                                true
                            );
                        }
                    }
                }
            
                // The ability banishes cards.
                else if (effects[i][0] == BANISH_EFFECT) {
                    int banishes = std::stoi(effects[i][1]);
                    
                    if (banishes > hand.size()) {
                        banishes = hand.size();
                    }
                    
                    // The player chooses cards to banish.
                    for (int i = 0; i < banishes; ++i) {
                        int index;
                        
                        if (hand.size() == 1) {
                            index = 0;
                        }
                        
                        else if (!opposing) {
                            announce(TO_BANISH_ANNOUNCEMENT);
                            
                            index = hand.choose(
                                display,
                                renderer,
                                back_button
                            );
                            
                            messenger.send(std::to_string(index));
                        }
                        
                        else {
                            announce(TO_BANISH_ANNOUNCEMENT, false);
                            
                            index = std::stoi(message);
                            
                            // A message is waited for in another thread.
                            message = EMPTY_MESSAGE;
                            messenger_thread.new_thread(
                                MessengerPackage::get_message,
                                &messenger_package
                            );
                        }
                        
                        if (opposing) {
                            announce(BANISH_PEEK_ANNOUNCEMENT);
                        }
                        
                        the_void.store(hand.remove(index));
                    }
                    
                    announce(BANISH_ANNOUNCEMENT);
                }
            
                // The ability ranks up the user into a fighter in hand.
                else if (effects[i][0] == ASCENSION_EFFECT) {
                    // The indices of the rank up cards.
                    std::vector<int> indices;
                    
                    // The indices are found.
                    for (int j = 0; j < hand.size<Fighter>(); ++j) {
                        if (
                            hand.get_fighters()[j].get_old_rank()
                            == fighters[index].get_name()
                        ) {
                            indices.push_back(j);
                        }
                    }
                    
                    // The rank up only occurs if there is a valid rank up card in hand.
                    if (indices.size()) {
                        // The active fighter is ranked up.
                        rank_up(
                            static_cast<Fighter&>(
                                *hand.remove(
                                    indices[
                                        Random::get_int(generator, 0, indices.size() - 1)
                                    ]
                                )
                            ),
                            index
                        );
                    }
                }
            }
        }
        
        /**
         * Switches a fighter into the active position from the bench.
         * The active fighter is switched out to the bench.
         * The benched fighter has its effect cleared.
         * If the active fighter is rooted, this function has no effect.
         */
        void switch_in(int index, bool clear = true) noexcept {
            if (!fighters[0].effect_search(ROOT_EFFECT).size()) {
                Fighter temporary(fighters[index]);
                fighters[index] = fighters[0];
                fighters[0] = temporary;
                
                // The effects are optionally cleared from the retreated fighter.
                if (clear) {
                    fighters[index].clear_effects();
                    announce(SWITCH_IN_ANNOUNCEMENT);
                }
            }
        }
        
        /**
         * Removes all power effects from this player and their fighters.
         * This only takes effect at the end of the player's turn.
         */
        void depower() noexcept {
            if (turn == opposing) {
                unaffect(POWER_EFFECT);
                
                for (int i = 0; i < fighters.size(); ++i) {
                    fighters[i].unaffect(POWER_EFFECT);
                }
            }
        }
        
        /**
         * Chooses a fighter on the bench to switch in.
         */
        void retreat(int index = -1) noexcept {
            // The player chooses the fighter that should retreat.
            if (index < 0) {
                // If only one fighter can be chosen, it is chosen automatically.
                if (fighters.size() == 2) {
                    index = 1;
                }
                
                // Else, the player chooses the fighter to switch in.
                else {
                    // The left button is initialised.
                    Button left_button(
                        Sprite(
                            LEFT_SOURCE,
                            LEFT_WIDTH * display.width(),
                            LEFT_HEIGHT * display.height()
                        ),
                        display,
                        LEFT_X,
                        LEFT_Y
                    );
                    
                    // The right button is initialised.
                    Button right_button(
                        Sprite(
                            RIGHT_SOURCE,
                            RIGHT_WIDTH * display.width(),
                            RIGHT_HEIGHT * display.height()
                        ),
                        display,
                        RIGHT_X,
                        RIGHT_Y
                    );
                    
                    // The preview button is initialised.
                    Button preview_button(
                        renderer.render(
                            display,
                            RETREAT_PREVIEW_STRING,
                            RETREAT_PREVIEW_WIDTH,
                            RETREAT_PREVIEW_HEIGHT,
                            RETREAT_PREVIEW_SEPARATION
                        ),
                        display,
                        RETREAT_PREVIEW_X,
                        RETREAT_PREVIEW_Y
                    );
            
                    // The switch_in buttons are initialised.
                    std::vector<Button> switch_in_buttons;
                    
                    for (int i = 0; i < PAGE_COUNT; ++i) {
                        switch_in_buttons.push_back(
                            Button(
                                renderer.render(
                                    SWITCH_IN_STRING,
                                    SWITCH_IN_WIDTH * display.width(),
                                    SWITCH_IN_HEIGHT * display.height(),
                                    SWITCH_IN_SEPARATION * display.width()
                                ),
                                display,
                                SWITCH_IN_X,
                                SWITCH_IN_Y + i * SWITCH_IN_Y_SHIFT
                            )
                        );
                    }
            
                    // Determines which cards are displayed.
                    int page = 0;
                    
                    // True when the fighter to switch in has been chosen.
                    bool end = false;
                    
                    while (!end) {
                        // The sprites are blitted to the display.
                        display.fill();
                        preview_button.blit_to(display);
                        
                        // The previous page button is displayed, when relevant.
                        if (page > 0) {
                            left_button.blit_to(display);
                        }
                        
                        // The next page button is displayed, when relevant.
                        if (page < (fighters.size() - 2) / PAGE_COUNT) {
                            right_button.blit_to(display);
                        }
                        
                        // A vector of buttons for the names is generated.
                        std::vector<Button> name_buttons;
                        
                        // The cards' names on the page are displayed.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < fighters.size() - 1;
                            ++i
                        ) {
                            // The name button is stored in the vector.
                            name_buttons.push_back(
                                Button(
                                    Sprite(
                                        renderer.render(
                                            fighters[BENCH_INDEX + page * PAGE_COUNT + i].get_name(),
                                            PAGE_WIDTH * display.width(),
                                            PAGE_HEIGHT * display.height(),
                                            PAGE_SEPARATION * display.width()
                                        )
                                    ),
                                    display,
                                    PAGE_NAME_X,
                                    PAGE_Y + i * PAGE_Y_SHIFT
                                )
                            );
                            
                            // The name is displayed.
                            name_buttons[i].blit_to(display);
                            
                            // The switch_in button is displayed, if it is usable.
                            switch_in_buttons[i].blit_to(display);
                        }
                        
                        // The display is updated.
                        display.update();
                        
                        // Loop to get user input.
                        while (true) {
                            // The user can return to the previous menu with
                            //   the use of the back button or submit key.
                            if (preview_button.get_rectangle().unclick()) {
                                fighters[0].view(
                                    display,
                                    renderer,
                                    back_button,
                                    message
                                );
                            }
                            
                            // The page number is decremented (if possible).
                            else if (
                                (
                                    Events::unpress(Events::LEFT)
                                    || left_button.get_rectangle().unclick()
                                ) && page > 0
                            ) {
                                --page;
                                break;
                            }
                            
                            // The page number is incremented (if possible).
                            else if (
                                (
                                    Events::unpress(Events::RIGHT)
                                    || right_button.get_rectangle().unclick()
                                ) && page < (fighters.size() - 2) / PAGE_COUNT
                            ) {
                                ++page;
                                break;
                            }
                            
                            // The other buttons are checked.
                            else {
                                // True if the button being clicked was found.
                                bool found = false;
                                
                                // The plus and minus buttons increment or decrement
                                //   the number of copies of a card in the deck.
                                // The names display the card's details.
                                for (
                                    int i = 0;
                                    i < PAGE_COUNT
                                    && page * PAGE_COUNT + i < fighters.size() - 1;
                                    ++i
                                ) {
                                    // Diplays a card's details.
                                    if (name_buttons[i].get_rectangle().unclick()) {
                                        fighters[BENCH_INDEX + page * PAGE_COUNT + i].view(
                                            display,
                                            renderer,
                                            back_button,
                                            message
                                        );
                                        
                                        found = true;
                                        break;
                                    }
                                    
                                    // Switches in the benched fighter.
                                    else if (switch_in_buttons[i].get_rectangle().unclick()) {
                                        index = BENCH_INDEX + page * PAGE_COUNT + i;
                                        end = true;
                                        found = true;
                                        break;
                                    }
                                }
                                
                                if (found) {
                                    break;
                                }
                            }
                            
                            // The events are updated.
                            Events::update();
                        }
                    }
                }
                
                messenger.send(RETREAT_MESSAGE);
                messenger.send(std::to_string(index));
            }
            
            announce(RETREAT_ANNOUNCEMENT);
            switch_in(index);
            retreated = true;
        }
        
        /**
         * Performs the active's fighter's attack.
         */
        void attack(bool combo = false) noexcept {
            // A copy of the attack is extracted.
            Attack attack(fighters[0].get_attack());
            
            // The effects are extracted.
            const std::vector<std::vector<std::string>>& effects = attack.get_effects();
            
            // The power boost is calculated.
            int power =
                effect_count(POWER_AURA_EFFECT)
                + effect_count(POWER_EFFECT)
                + fighters[0].effect_count(POWER_EFFECT)
            ;
            
            // The results of the last set of coin flips.
            std::vector<bool> coin_flips;
            std::array<int, 2> flip_counts;
            
            // The attack usage is annouced.
            announce(ATTACK_ANNOUNCEMENT);
            
            // The damage boost from the attack's effects.
            int boost = 0;
            
            // The attack's effects are resolved.
            for (int i = 0; i < effects.size(); ++i) {
                // Can damage any opposing fighter.
                if (effects[i][0] == SNIPE_EFFECT) {
                    // The number of snipes depends on the flip results.
                    if (effects[i][1] == HEADS_COUNT_EFFECT) {
                        std::string effect(
                            effects[i][0]
                            + EFFECT_SEPARATOR
                            + effects[i][2]
                        );
                        
                        for (int i = 0; i < flip_counts[HEADS]; ++i) {
                            attack.affect(effect);
                        }
                    }
                    
                    // A single snipe of predetermined power.
                    else {
                        int index;
                        
                        // The target must be the active, if it is the only fighter.
                        if (opponent->fighters.size() == 1) {
                            index = 0;
                        }
                        
                        // The player chooses a fighter to deal damage to.
                        else if (!opposing) {
                            announce(TO_SNIPE_ANNOUNCEMENT);
                            index = opponent->choose_fighter();
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent waits for the player to choose.
                        else {
                            // The snipe choice is waited for.
                            announce(TO_SNIPE_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            
                            // A message is waited for in another thread.
                            message = EMPTY_MESSAGE;
                            messenger_thread.new_thread(
                                MessengerPackage::get_message,
                                &messenger_package
                            );
                        }
                        
                        int snipe = std::stoi(effects[i][1]) + power + boost;
                        
                        // The snipe has additional effects.
                        if (effects[i].size() > 2) {
                            // The snipe's damage can be modified.
                            if (effects[i][2] == POWER_EFFECT) {
                                // The snipe's damage is affected by the target's element.
                                if (
                                    effects[i][3]
                                    == opponent->fighters[index].get_element()
                                ) {
                                    snipe += std::stoi(effects[i][4]);
                                }
                            }
                        }
                        
                        snipe = opponent->fighters[index].damage(snipe);
                        
                        announce(SNIPE_ANNOUNCEMENT);
                    }
                }
                
                // The attack's damage can be increased.
                else if (effects[i][0] == POWER_EFFECT) {
                    // The damage is boosted by the number of cards in the trash.
                    if (effects[i][1] == TRASH_EFFECT) {
                        boost += trash.size() * std::stoi(effects[i][2]);
                    }
                    
                    // The damage is boosted by the fighter's total energy value.
                    else if (effects[i][1] == ENERGY_TYPE) {
                        int proto_boost = round(
                            fighters[0].energy_value()
                            * std::stod(effects[i][2])
                        );
                        
                        int max_boost = std::stoi(effects[i][3]);
                        
                        if (proto_boost > max_boost) {
                            proto_boost = max_boost;
                        }
                        
                        boost += proto_boost;
                    }
                    
                    // The damage is boosted if the fighter is invincible.
                    else if (
                        effects[i][1] == INVINCIBILITY_EFFECT
                        && fighters[0].effect_search(INVINCIBILITY_EFFECT).size()
                    ) {
                        boost += std::stoi(effects[i][2]);
                    }
                    
                    // The damage is boosted if the deck has no fighter cards.
                    else if (
                        effects[i][1] == FIGHTERLESS_EFFECT
                        && !deck.get_fighters().size()
                    ) {
                        boost += std::stoi(effects[i][2]);
                    }
                    
                    // The damage is boosted by the number of cards in the void.
                    else if (effects[i][1] == VOID_EFFECT) {
                        int proto_boost = the_void.size() * std::stoi(effects[i][2]);
                        int max_boost = std::stoi(effects[i][3]);
                        
                        if (proto_boost > max_boost) {
                            proto_boost = max_boost;
                        }
                        
                        boost += proto_boost;
                    }
                    
                    // The damage is boosted by the number of cards in the hand.
                    else if (effects[i][1] == HAND_EFFECT) {
                        boost += hand.size() * std::stoi(effects[i][2]);
                    }
                }

                // The target's retreat cost is changed for a turn.
                else if (effects[i][0] == AGILITY_EFFECT) {
                    opponent->fighters[0].affect(
                        effects[i][0]
                        + EFFECT_SEPARATOR
                        + effects[i][1]
                    );
                    std::string agility(effects[i][1]);
                    announce(AGILITY_ANNOUNCEMENT);
                }
            
                // The opponent's active fighter is switched out and randomly replaced.
                else if (effects[i][0] == GUST_EFFECT && opponent->fighters.size() > 1) {
                    // The replacement is randomly chosen.
                    int index = Random::get_int(generator, 1, opponent->fighters.size() - 1);
                    
                    // The fighter is switched in and the switch is announced.
                    opponent->switch_in(index);
                }
            
                // Deals damage to all of a player's benched fighters.
                else if (effects[i][0] == SPLASH_EFFECT) {
                    // Splashes the player's own bench.
                    if (effects[i][1] == SELF_EFFECT) {
                        if (fighters.size() > 1) {
                            int damage = std::stoi(effects[i][2]) + power + boost;
                            
                            // Negative damage is shown as zero.
                            if (damage < 0) {
                                damage = 0;
                            }
                            
                            for (int i = 1; i < fighters.size(); ++i) {
                                fighters[i].damage(damage);
                            }
                            
                            announce(SPLASH_SELF_ANNOUNCEMENT);
                        }
                    }
                    
                    // Splashes the opponent's bench.
                    else {
                        if (opponent->fighters.size() > 1) {
                            int damage = std::stoi(effects[i][1]) + power + boost;
                            
                            // Negative damage is shown as zero.
                            if (damage < 0) {
                                damage = 0;
                            }
                            
                            for (int i = 1; i < opponent->fighters.size(); ++i) {
                                opponent->fighters[i].damage(damage);
                            }
                            
                            announce(SPLASH_ANNOUNCEMENT);
                        }
                    }
                }
            
                // Deals damage to the user.
                else if (effects[i][0] == RECOIL_EFFECT) {
                    int damage = std::stoi(effects[i][1]) + boost + power;
                    int index = 0;
                    damage = fighters[index].damage(damage);
                    announce(RECOIL_ANNOUNCEMENT);
                }
            
                // Heals a fighter.
                else if (effects[i][0] == HEAL_EFFECT) {
                    // Heals the user.
                    if (effects[i][1] == SELF_EFFECT) {
                        if (effects[i][2] == DAMAGE_EFFECT) {
                            int healing = round(last_draws * std::stod(effects[i][3]));
                            int index = 0;
                            healing = fighters[index].heal(healing);
                            announce(HEAL_ANNOUNCEMENT);
                        }
                        
                        else {
                            // The amount to heal is extracted.
                            int healing = std::stoi(effects[i][2]);
                            int index = 0;
                            healing = fighters[index].heal(healing);
                            announce(HEAL_ANNOUNCEMENT);
                        }
                    }
                    
                    // Heals opposing fighters.
                    else if (effects[i][1] == OPPONENT_EFFECT) {
                        // Heals all of the opposing fighters.
                        if (effects[i][2] == SPLASH_EFFECT) {
                            int healing = std::stoi(effects[i][3]);
                            
                            // All of the opposing fighters are healed.
                            for (int i = 0; i < opponent->fighters.size(); ++i) {
                                opponent->fighters[i].heal(healing);
                            }
                            
                            // The healing is announced.
                            announce(HEAL_OPPONENT_SPLASH_ANNOUNCEMENT);
                        }
                    }
                
                    // Restores health to all of the player's fighters.
                    else if (effects[i][1] == SPLASH_EFFECT) {
                        int healing = std::stoi(effects[i][2]);
                        
                        // All of the friendly fighters are healed.
                        for (int i = 0; i < fighters.size(); ++i) {
                            fighters[i].heal(healing);
                        }
                        
                        // The healing is announced.
                        announce(HEAL_SPLASH_ANNOUNCEMENT);
                    }
                }
            
                // Allows the player to draw.
                else if (effects[i][0] == DRAW_EFFECT) {
                    // The opponent draws.
                    if (effects[i][1] == OPPONENT_EFFECT) {
                        // The number of cards to draw.
                        int draws;
                        
                        // The number of cards to draw depends on previous effects.
                        if (effects[i][2] == DRAW_COUNT_EFFECT) {
                            draws = last_draws;
                        }
                        
                        // The number of draws is specified.
                        else {
                            draws = std::stoi(effects[i][2]);
                        }
                        
                        // The number of card draws cannot exceed
                        //   the number of cards in the deck.
                        if (draws > opponent->deck.size()) {
                            draws = opponent->deck.size();
                        }
                        
                        // The player only sees the number of draws.
                        if (!opposing) {
                            opponent->draw(draws);
                            announce(DRAW_OPPONENT_ANNOUNCEMENT);
                        }
                        
                        // The opponent sees what was drawn.
                        else {
                            for (int j = 0; j < draws; ++j) {
                                opponent->draw(1);
                                announce(LAST_DRAWN_OPPONENT_ANNOUNCEMENT);
                            }
                            
                            announce(DRAW_OPPONENT_ANNOUNCEMENT);
                        }
                    }
                    
                    // The player draws a fighter card.
                    else if (effects[i][1] == FIGHTER_TYPE) {
                        int draws = std::stoi(effects[i][2]);
                        
                        if (draws > deck.get_fighters().size()) {
                            draws = deck.get_fighters().size();
                        }
                        
                        for (int i = 0; i < draws; ++i) {
                            last_drawn = deck.remove(
                                Random::get_int(generator, 0, deck.get_fighters().size() - 1)
                            );
                            
                            hand.store(last_drawn);
                            
                            if (!opposing) {
                                announce(LAST_DRAWN_ANNOUNCEMENT);
                            }
                        }
                        
                        announce(DRAW_ANNOUNCEMENT);
                    }
                    
                    // The player draws.
                    else {
                        // The number of cards to draw.
                        int draws;
                        
                        // The number of cards to draw depends on previous effects.
                        if (effects[i][1] == DRAW_COUNT_EFFECT) {
                            draws = last_draws;
                        }
                        
                        // The number of draws is specified.
                        else {
                            draws = std::stoi(effects[i][1]);
                        }
                        
                        // The number of card draws cannot exceed
                        //   the number of cards in the deck.
                        if (draws > deck.size()) {
                            draws = deck.size();
                        }
                        
                        // The opponent only sees the number of draws.
                        if (opposing) {
                            draw(draws);
                            announce(DRAW_ANNOUNCEMENT);
                        }
                        
                        // The player sees what was drawn.
                        else {
                            for (int j = 0; j < draws; ++j) {
                                draw(1);
                                announce(LAST_DRAWN_ANNOUNCEMENT);
                            }
                            
                            announce(DRAW_ANNOUNCEMENT);
                        }
                    }
                }
                
                // Shuffles cards into the deck.
                else if (effects[i][0] == SHUFFLE_EFFECT) {
                    // The opponent shuffles cards into their deck.
                    if (effects[i][1] == OPPONENT_EFFECT) {
                        // The opponent shuffles all of their cards into the deck.
                        if (effects[i][2] == UNIVERSAL_EFFECT) {
                            int shuffles = last_draws = opponent->hand.size();
                            announce(SHUFFLE_OPPONENT_ALL_ANNOUNCEMENT);
                            opponent->shuffle();
                        }
                    }
                    
                    // Shuffles cards from the trash into the deck.
                    else if (effects[i][1] == TRASH_EFFECT) {
                        // Shuffles energy cards into the deck.
                        if (effects[i][2] == ENERGY_TYPE) {
                            if (effects[i][3] == UNIVERSAL_EFFECT) {
                                int shuffles = trash.size<Energy>();
                                deck.store(trash.get_energy());
                                announce(SHUFFLE_TRASH_ENERGY_ANNOUNCEMENT);
                                trash.remove<Energy>();
                            }
                        }
                        
                        // Shuffles a number of chosen cards from the trash into the deck.
                        else {
                            int shuffles = std::stoi(effects[i][2]);
                            
                            if (shuffles > trash.size()) {
                                shuffles = trash.size();
                            }
                            
                            // The player chooses cards to shuffle into the deck.
                            for (int i = 0; i < shuffles; ++i) {
                                int index;
                                
                                // The only available choice is chosen.
                                if (trash.size()) {
                                    index = 0;
                                }
                                
                                // The player chooses a card.
                                else if (!opposing) {
                                    announce(TO_SHUFFLE_TRASH_ANNOUNCEMENT);
                                    
                                    index = trash.choose(
                                        display,
                                        renderer,
                                        back_button
                                    );
                                    
                                    messenger.send(std::to_string(index));
                                }
                                
                                // The opponent waits for the choice to be made.
                                else {
                                    announce(TO_SHUFFLE_TRASH_ANNOUNCEMENT, false);
                                    
                                    index = std::stoi(message);
                                    
                                    // A message is waited for in another thread.
                                    message = EMPTY_MESSAGE;
                                    messenger_thread.new_thread(
                                        MessengerPackage::get_message,
                                        &messenger_package
                                    );
                                }
                                
                                announce(SHUFFLE_TRASH_PEEK_ANNOUNCEMENT);
                                last_drawn = trash.remove(index);
                                deck.store(last_drawn);
                            }
                            
                            announce(SHUFFLE_ANNOUNCEMENT);
                        }
                    }
                    
                    // Shuffles all of the cards in the hand into the deck.
                    else if (effects[i][1] == UNIVERSAL_EFFECT) {
                        int shuffles = last_draws = hand.size();
                        announce(SHUFFLE_ALL_ANNOUNCEMENT);
                        shuffle();
                    }
                    
                    // Shuffles a number of chosen cards from the hand into the deck.
                    else {
                        int shuffles = std::stoi(effects[i][1]);
                        
                        if (shuffles > hand.size()) {
                            shuffles = hand.size();
                        }
                        
                        // The player chooses cards to shuffle into the deck.
                        for (int i = 0; i < shuffles; ++i) {
                            int index;
                            
                            // The only available choice is chosen.
                            if (hand.size()) {
                                index = 0;
                            }
                            
                            // The player chooses a card.
                            else if (!opposing) {
                                announce(TO_SHUFFLE_ANNOUNCEMENT);
                                
                                index = hand.choose(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                messenger.send(std::to_string(index));
                            }
                            
                            else {
                                announce(TO_SHUFFLE_ANNOUNCEMENT, false);
                                
                                index = std::stoi(message);
                                
                                // A message is waited for in another thread.
                                message = EMPTY_MESSAGE;
                                messenger_thread.new_thread(
                                    MessengerPackage::get_message,
                                    &messenger_package
                                );
                            }
                            
                            last_drawn = hand.remove(index);
                            deck.store(last_drawn);
                        }
                        
                        announce(SHUFFLE_ANNOUNCEMENT);
                    }
                }
                
                // Clears the effects on the fighter.
                else if (effects[i][0] == CLEAR_EFFECT) {
                    int index = 0;
                    fighters[index].clear_effects();
                    announce(CLEAR_ANNOUNCEMENT);
                }
                
                // The attack flips coins.
                else if (effects[i][0] == FLIP_EFFECT) {
                    // Preparation for the set of coin flips.
                    int flips = std::stoi(effects[i][1]);
                    coin_flips.clear();
                    flip_counts.fill(0);
                    
                    for (int i = 0; i < flips; ++i) {
                        bool result = coin_flip(generator);
                        coin_flips.push_back(result);
                        ++flip_counts[result];
                        announce(FLIP_ANNOUNCEMENT);
                    }
                    
                    announce(FLIP_COUNT_ANNOUNCEMENT);
                }
                
                // The effect is only resolved if heads was flipped.
                else if (effects[i][0] == HEADS_EFFECT && coin_flips[0] == HEADS) {
                    // The effect is only resolved if the 2nd coin flip was heads.
                    if (effects[i][1] == HEADS_EFFECT && coin_flips[1] == HEADS) {
                        // Cripples the opponent's active fighter (no retreat).
                        if (effects[i][2] == CRIPPLE_EFFECT) {
                            opponent->fighters[0].affect(effects[i][2]);
                            announce(CRIPPLE_ANNOUNCEMENT);
                        }
                        
                        // Impairs the opponent's active fighter (no attack).
                        else if (effects[i][2] == IMPAIR_EFFECT) {
                            opponent->fighters[0].affect(effects[i][2]);
                            announce(IMPAIR_ANNOUNCEMENT);
                        }
                    }
                    
                    // The attack's damage can be increased.
                    else if (effects[i][1] == POWER_EFFECT) {
                        boost += std::stoi(effects[i][2]);
                    }
                
                    // Cripples the opponent's active fighter (no retreat).
                    else if (effects[i][1] == CRIPPLE_EFFECT) {
                        opponent->fighters[0].affect(effects[i][1]);
                        announce(CRIPPLE_ANNOUNCEMENT);
                    }
                    
                    // Impairs the opponent's active fighter (no attack).
                    else if (effects[i][1] == IMPAIR_EFFECT) {
                        opponent->fighters[0].affect(effects[i][1]);
                        announce(IMPAIR_ANNOUNCEMENT);
                    }
                }
            
                // The attack deals damage over time.
                else if (effects[i][0] == CURSE_EFFECT) {
                    // The damage is dependent on the void's size.
                    if (effects[i][1] == VOID_EFFECT) {
                        int curse_value = the_void.size() * std::stoi(effects[i][2]);
                        int max_curse = std::stoi(effects[i][3]);
                        
                        if (curse_value > max_curse) {
                            curse_value = max_curse;
                        }
                        
                        std::string curse(
                            std::to_string(curse_value)
                        );
                        
                        opponent->fighters[0].affect(
                            effects[i][0]
                            + EFFECT_SEPARATOR
                            + curse
                        );
                        
                        announce(CURSE_ANNOUNCEMENT);
                    }
                }
                
                // The attack uses another fighter's attack.
                else if (effects[i][0] == MIMIC_EFFECT) {
                    // The fighter to mimic must be in the void.
                    if (effects[i][1] == VOID_EFFECT && the_void.get_fighters().size()) {
                        // The index of the fighter to mimic.
                        int index;
                        
                        // The only fighter in the void is chosen.
                        if (the_void.get_fighters().size() == 1) {
                            index = 0;
                        }
                        
                        // The player chooses a fighter to mimic.
                        else if (!opposing) {
                            announce(MIMIC_ANNOUNCEMENT);
                            index = the_void.choose<Fighter>(
                                display,
                                renderer,
                                back_button
                            );
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent awaits the player's choice.
                        else  {
                            announce(MIMIC_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            get_message();
                        }
                        
                        // The attack is used an announced.
                        Attack new_attack(
                            static_cast<const Fighter&>(the_void[index]).get_attack()
                        );
                        
                        // Another mimic attack can't be chosen.
                        if (!new_attack.effect_search(MIMIC_EFFECT).size()) {
                            attack = new_attack;
                            i = -1;
                            announce(ATTACK_ANNOUNCEMENT);
                        }
                    }
                }
            
                // Switches in a fighter from the bench.
                else if (effects[i][0] == SWITCH_EFFECT) {
                    if (fighters.size() > 1) {
                        int index;
                        
                        // The player's sole benched fighter is switched in.
                        if (fighters.size() == 2) {
                            index = 1;
                        }
                        
                        // The player chooses a fighter to switch in.
                        else if (!opposing) {
                            announce(TO_SWITCH_ANNOUNCEMENT);
                            index = choose_bench();
                            messenger.send(std::to_string(index));
                        }
                        
                        // The opponent receives the index of the fighter.
                        else {
                            announce(TO_SWITCH_ANNOUNCEMENT, false);
                            index = std::stoi(message);
                            
                            // A message is waited for in another thread.
                            message = EMPTY_MESSAGE;
                            messenger_thread.new_thread(
                                MessengerPackage::get_message,
                                &messenger_package
                            );
                        }
                        
                        // The fighter is switched in and the switch is announced.
                        switch_in(index);
                    }
                }
            
                // Discards random cards from the deck.
                else if (effects[i][0] == MILL_EFFECT) {
                    // Discards the player's own cards.
                    if (effects[i][1] == SELF_EFFECT) {
                        // The milled cards are banished.
                        if (effects[i][2] == BANISH_EFFECT) {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][3]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > deck.size()) {
                                mills = deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = deck.draw(generator);
                                the_void.store(last_drawn);
                                announce(MILL_SELF_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_SELF_BANISH_ANNOUNCEMENT);
                        }
                        
                        // The milled cards are discarded.
                        else {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][2]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > deck.size()) {
                                mills = deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = deck.draw(generator);
                                trash.store(last_drawn);
                                announce(MILL_SELF_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_SELF_ANNOUNCEMENT);
                        }
                    }
                    
                    // Mills based on last_draws.
                    else if (effects[i][1] == DRAW_COUNT_EFFECT) {
                        // The number of cards to mill is found.
                        int mills = last_draws;
                        
                        // The player can't discard more cards
                        //   than they have in their deck.
                        if (mills > opponent->deck.size()) {
                            mills = opponent->deck.size();
                        }
                        
                        // The cards are discarded and displayed.
                        for (int i = 0; i < mills; ++i) {
                            last_drawn = opponent->deck.draw(generator);
                            opponent->trash.store(last_drawn);
                            announce(MILL_PEEK_ANNOUNCEMENT);
                        }
                        
                        // The total number of cards discarded is displayed.
                        announce(MILL_ANNOUNCEMENT);
                    }
                    
                    // Discard the opponent's cards.
                    else {
                        // The milled cards are banished.
                        if (effects[i][1] == BANISH_EFFECT) {
                            // The number of cards to mill are extracted.
                            int mills = std::stoi(effects[i][2]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > opponent->deck.size()) {
                                mills = opponent->deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = opponent->deck.draw(generator);
                                the_void.store(last_drawn);
                                announce(MILL_BANISH_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_BANISH_ANNOUNCEMENT);
                        }
                        
                        // The milled cards are discarded.
                        else {
                            // The number of cards to mill is extracted.
                            int mills = std::stoi(effects[i][1]);
                            
                            // The player can't discard more cards
                            //   than they have in their deck.
                            if (mills > opponent->deck.size()) {
                                mills = opponent->deck.size();
                            }
                            
                            // The cards are discarded and displayed.
                            for (int i = 0; i < mills; ++i) {
                                last_drawn = opponent->deck.draw(generator);
                                opponent->trash.store(last_drawn);
                                announce(MILL_PEEK_ANNOUNCEMENT);
                            }
                            
                            // The total number of cards discarded is displayed.
                            announce(MILL_ANNOUNCEMENT);
                        }
                    }
                }
            
                // Randomly distributes the damage for all fighters.
                else if (effects[i][0] == DISTRIBUTE_EFFECT) {
                    // The total damage is extracted.
                    int total_damage = std::stoi(effects[i][1]) + boost + power;
                    
                    // A vector storing how much damage each
                    //   fighter should receive is initialised.
                    std::vector<int> damage;
                    
                    for (int i = 0; i < opponent->fighters.size(); ++i) {
                        damage.push_back(0);
                    }
                    
                    // A vector storing the maximum amount of
                    //   damage each fighter can receive.
                    std::vector<int> max_damage;
                    
                    // The indices of fighters that are not fully healed are stored.
                    std::vector<int> indices;
                    
                    // max_damage and indices are initialised.
                    for (int i = 0; i < opponent->fighters.size(); ++i) {
                        max_damage.push_back(opponent->fighters[i].get_health());
                        
                        if (max_damage[i]) {
                            indices.push_back(i);
                        }
                    }
                    
                    for (int i = 0; i < total_damage && indices.size(); ++i) {
                        // A random fighter's damage is incremented.
                        int index = Random::get_int(generator, 0, indices.size() - 1);
                        ++damage[indices[index]];
                        
                        // If the fighter is defeated, it can't be chosen again.
                        if (damage[indices[index]] == max_damage[indices[index]]) {
                            indices.erase(indices.cbegin() + index);
                        }
                    }
                    
                    // The actual total damage is recorded.
                    last_draws = 0;
                    
                    // The fighters are damaged.
                    for (int i = 0; i < opponent->fighters.size(); ++i) {
                        damage[i] = opponent->fighters[i].damage(damage[i]);
                        announce(DAMAGE_DISTRIBUTION_ANNOUNCEMENT);
                        last_draws += damage[i];
                    }
                }
            
                // Removes the boost from the attack.
                else if (effects[i][0] == DEPOWER_EFFECT) {
                    boost = 0;
                }
            }
            
            // The damage is caculated.
            int damage = attack.get_damage() + boost;
            
            // Damage is only boosted by power if it was non-zero.
            if (damage) {
                damage += power;
            }
            
            // The opponent's active fighter is damaged.
            int true_damage = opponent->fighters[0].damage(damage);
            
            // The attack's damage is announced.
            if (damage) {
                // Still displays the damage of an attack that was weakened to zero.
                damage = true_damage;
                announce(DAMAGE_ANNOUNCEMENT);
            }
        
            // The combo attack does not affect the attack status.
            // The combo attack can't combo with other fighters.
            if (!combo) {
                attacked = true;
                
                // If the active fighter has the "Combo Attack" ability,
                //   the benched fighters with the same ability also attack.
                // The attack is only performed if the fighter
                //   has a sufficient amount of energy.
                if (fighters[0].effect_search(COMBO_EFFECT).size()) {
                    for (int i = 1; i < fighters.size(); ++i) {
                        // Benched fighters are checked for Combo Attack and energy.
                        if (
                            fighters[i].effect_search(COMBO_EFFECT).size()
                            && fighters[i].attack_usable()
                        ) {
                            // The switches don't remove effects.
                            switch_in(i, false);
                            this->attack(true);
                            switch_in(i, false);
                        }
                    }
                }
            }
        }
        
        /**
         * Checks for defeated fighters.
         * Also performs end of action effects.
         */
        void defeat_check() noexcept {
            // The number of life cards to be drawn.
            int life_draws = 0;
            
            // The number of life cards to be banished.
            int life_banishes = 0;
            
            // Defeated benched fighters and their energy are discarded.
            for (int i = fighters.size() - 1; i >= 0; --i) {
                // The fighter was defeated.
                if (fighters[i].get_health() <= 0) {
                    // Non-zero if the fighter has the forsaken effect.
                    int forsaken = fighters[i].effect_count(FORSAKEN_EFFECT);
                    
                    // The defeat is announced.
                    announce(DEFEAT_ANNOUNCEMENT);
                    
                    // The energy attached to the fighter is discarded.
                    if (forsaken) {
                        the_void.store(fighters[i].get_energy());
                    }
                    
                    else {
                        trash.store(fighters[i].get_energy());
                    }
                    
                    // Non-active fighters are dealt with.
                    if (i > 0) {
                        // The fighter is reset and discarded.
                        fighters[i].reset();
                        
                        if (forsaken) {
                            the_void.store(fighters[i]);
                        }
                        
                        else {
                            trash.store(fighters[i]);
                        }
                    
                        // Benched fighters are removed immediately.
                        fighters.erase(fighters.cbegin() + i);
                    }
                    
                    // Forsaken fighters banish life cards upon defeat.
                    // Forsaken fighters also banish-mill both players upon defeat.
                    if (forsaken) {
                        // The number of life cards to be banished is incremented.
                        ++life_banishes;
                    
                        // The number of cards to mill are extracted.
                        int mills = forsaken;
                        
                        // The player can't discard more cards
                        //   than they have in their deck.
                        if (mills > opponent->deck.size()) {
                            mills = opponent->deck.size();
                        }
                        
                        // The cards are discarded and displayed.
                        for (int i = 0; i < mills; ++i) {
                            last_drawn = opponent->deck.draw(generator);
                            the_void.store(last_drawn);
                            announce(MILL_BANISH_PEEK_ANNOUNCEMENT);
                        }
                        
                        // The total number of cards discarded is displayed.
                        announce(MILL_BANISH_ANNOUNCEMENT);
                        
                        // The top cards of each player's deck are banished.
                        // The number of cards to mill are extracted.
                        mills = forsaken;
                        
                        // The player can't discard more cards
                        //   than they have in their deck.
                        if (mills > deck.size()) {
                            mills = deck.size();
                        }
                        
                        // The cards are discarded and displayed.
                        for (int i = 0; i < mills; ++i) {
                            last_drawn = deck.draw(generator);
                            the_void.store(last_drawn);
                            announce(MILL_SELF_BANISH_PEEK_ANNOUNCEMENT);
                        }
                        
                        // The total number of cards discarded is displayed.
                        announce(MILL_SELF_BANISH_ANNOUNCEMENT);
                    }
                    
                    // Life cards are usually drawn.
                    else {
                        // The number of life cards to be drawn is incremented.
                        ++life_draws;
                    }
                }
            }
            
            // True if the player has reached a loss condition.
            bool defeated = false;
            
            // If the player draws all of their life cards, they lose.
            if (life_draws + life_banishes >= life_cards.size()) {
                if (life_cards.size()) {
                    // Set for the announcement.
                    life_draws = life_cards.size();
                    
                    // All of the life cards are drawn.
                    while (life_cards.size()) {
                        hand.store(life_cards.remove());
                    }
                    
                    announce(NO_LIFE_ANNOUNCEMENT);
                }
                
                // The player is defeated.
                defeated = true;
            }
            
            // The active fighter was defeated.
            if (fighters[0].get_health() <= 0) {
                // If all of the player's fighters are defeated, they lose.
                if (fighters.size() == 1) {
                    announce(NO_FIGHTERS_ANNOUNCEMENT);
                    
                    // The player is defeated.
                    defeated = true;
                }
                
                // Else, a new active fighter must be chosen (if not yet defeated).
                else if (!defeated) {
                    // There is only one fighter on the bench, so it is switched in.
                    if (fighters.size() == 2) {
                        new_active(1);
                    }
                    
                    // The player chooses a new active fighter.
                    else if (!opposing) {
                        announce(NEW_ACTIVE_ANNOUNCEMENT);
                        new_active();
                    }
                    
                    // The new active fighter is awaited.
                    else {
                        announce(NEW_ACTIVE_ANNOUNCEMENT, false);
                        
                        int index = std::stoi(message);
                        
                        // The message from the opponent is awaited.
                        message = EMPTY_MESSAGE;
                        messenger_thread.new_thread(
                            MessengerPackage::get_message,
                            &messenger_package
                        );
                        
                        new_active(index);
                    }
                }
            }
            
            // If the player was not defeated, they draw life cards
            //   for each of their fighters that were defeated.
            if (!defeated) {
                draw_life(life_draws);
                banish_life(life_banishes);
                aggressive();
            }
            
            // "last" variables are invalidated at the end of each action.
            last_drawn = nullptr;
            last_draws = 0;
            last_chosen = -1;
        }
        
        /**
         * Returns the number of loss conditions for this fighter.
         */
        int loss_conditions() const noexcept {
            int conditions = 0;
            
            if (fighters.size() == 1 && fighters[0].get_health() <= 0) {
                ++conditions;
            }
            
            if (!life_cards.size()) {
                ++conditions;
            }
            
            return conditions;
        }
        
        /**
         * Chooses a fighter on the bench to replace the active fighter.
         */
        void new_active(int index = -1) noexcept {
            // The player chooses the fighter that should switch in.
            if (index < 0) {
                // The left button is initialised.
                Button left_button(
                    Sprite(
                        LEFT_SOURCE,
                        LEFT_WIDTH * display.width(),
                        LEFT_HEIGHT * display.height()
                    ),
                    display,
                    LEFT_X,
                    LEFT_Y
                );
                
                // The right button is initialised.
                Button right_button(
                    Sprite(
                        RIGHT_SOURCE,
                        RIGHT_WIDTH * display.width(),
                        RIGHT_HEIGHT * display.height()
                    ),
                    display,
                    RIGHT_X,
                    RIGHT_Y
                );
                
                // The preview button is initialised.
                Button preview_button(
                    renderer.render(
                        display,
                        RETREAT_PREVIEW_STRING,
                        RETREAT_PREVIEW_WIDTH,
                        RETREAT_PREVIEW_HEIGHT,
                        RETREAT_PREVIEW_SEPARATION
                    ),
                    display,
                    RETREAT_PREVIEW_X,
                    RETREAT_PREVIEW_Y
                );
        
                // The switch_in buttons are initialised.
                std::vector<Button> switch_in_buttons;
                
                for (int i = 0; i < PAGE_COUNT; ++i) {
                    switch_in_buttons.push_back(
                        Button(
                            renderer.render(
                                SWITCH_IN_STRING,
                                SWITCH_IN_WIDTH * display.width(),
                                SWITCH_IN_HEIGHT * display.height(),
                                SWITCH_IN_SEPARATION * display.width()
                            ),
                            display,
                            SWITCH_IN_X,
                            SWITCH_IN_Y + i * SWITCH_IN_Y_SHIFT
                        )
                    );
                }
        
                // Determines which cards are displayed.
                int page = 0;
                
                // True when the fighter to switch in has been chosen.
                bool end = false;
                
                while (!end) {
                    // The sprites are blitted to the display.
                    display.fill();
                    preview_button.blit_to(display);
                    
                    // The previous page button is displayed, when relevant.
                    if (page > 0) {
                        left_button.blit_to(display);
                    }
                    
                    // The next page button is displayed, when relevant.
                    if (page < (fighters.size() - 2) / PAGE_COUNT) {
                        right_button.blit_to(display);
                    }
                    
                    // A vector of buttons for the names is generated.
                    std::vector<Button> name_buttons;
                    
                    // The cards' names on the page are displayed.
                    for (
                        int i = 0;
                        i < PAGE_COUNT
                        && page * PAGE_COUNT + i < fighters.size() - 1;
                        ++i
                    ) {
                        // The name button is stored in the vector.
                        name_buttons.push_back(
                            Button(
                                Sprite(
                                    renderer.render(
                                        fighters[BENCH_INDEX + page * PAGE_COUNT + i].get_name(),
                                        PAGE_WIDTH * display.width(),
                                        PAGE_HEIGHT * display.height(),
                                        PAGE_SEPARATION * display.width()
                                    )
                                ),
                                display,
                                PAGE_NAME_X,
                                PAGE_Y + i * PAGE_Y_SHIFT
                            )
                        );
                        
                        // The name is displayed.
                        name_buttons[i].blit_to(display);
                        
                        // The switch_in button is displayed, if it is usable.
                        switch_in_buttons[i].blit_to(display);
                    }
                    
                    // The display is updated.
                    display.update();
                    
                    // Loop to get user input.
                    while (true) {
                        // The user can return to the previous menu with
                        //   the use of the back button or submit key.
                        if (preview_button.get_rectangle().unclick()) {
                            fighters[0].view(
                                display,
                                renderer,
                                back_button,
                                message
                            );
                        }
                        
                        // The page number is decremented (if possible).
                        else if (
                            (
                                Events::unpress(Events::LEFT)
                                || left_button.get_rectangle().unclick()
                            ) && page > 0
                        ) {
                            --page;
                            break;
                        }
                        
                        // The page number is incremented (if possible).
                        else if (
                            (
                                Events::unpress(Events::RIGHT)
                                || right_button.get_rectangle().unclick()
                            ) && page < (fighters.size() - 2) / PAGE_COUNT
                        ) {
                            ++page;
                            break;
                        }
                        
                        // The other buttons are checked.
                        else {
                            // True if the button being clicked was found.
                            bool found = false;
                            
                            // The plus and minus buttons increment or decrement
                            //   the number of copies of a card in the deck.
                            // The names display the card's details.
                            for (
                                int i = 0;
                                i < PAGE_COUNT
                                && page * PAGE_COUNT + i < fighters.size() - 1;
                                ++i
                            ) {
                                // Diplays a card's details.
                                if (name_buttons[i].get_rectangle().unclick()) {
                                    fighters[BENCH_INDEX + page * PAGE_COUNT + i].view(
                                        display,
                                        renderer,
                                        back_button,
                                        message
                                    );
                                    
                                    found = true;
                                    break;
                                }
                                
                                // Switches in the benched fighter.
                                else if (switch_in_buttons[i].get_rectangle().unclick()) {
                                    index = BENCH_INDEX + page * PAGE_COUNT + i;
                                    end = true;
                                    found = true;
                                    break;
                                }
                            }
                            
                            if (found) {
                                break;
                            }
                        }
                        
                        // The events are updated.
                        Events::update();
                    }
                }
            
                messenger.send(std::to_string(index));
            }
            
            // The active fighter is reset and discarded.
            fighters[0].reset();
            
            // Forsaken fighters are banished.
            if (fighters[0].effect_count(FORSAKEN_EFFECT)) {
                the_void.store(fighters[0]);
            }
            
            // Fighters are usually discarded.
            else {
                trash.store(fighters[0]);
            }
            
            // The benched fighter replaces the active fighter.
            fighters[0] = fighters[index];
        
            // The original benched fighter is removed from the vector.
            fighters.erase(fighters.cbegin() + index);
            
            // The replacement is announced.
            announce(REPLACEMENT_ANNOUNCEMENT);
        }
        
        /**
         * Randomly returns 0 or 1.
         */
        static bool coin_flip(std::mt19937& generator) noexcept {
            return Random::get_int(generator, 0, 1);
        }

        /**
         * Removes the preparation effect from this fighter.
         */
        void prepare() noexcept {
            unaffect(PREPARATION_EFFECT);
        }

        /**
         * Allows the player to draw cards at the end of their opponent's turn.
         * This member function also removes the effect from the player.
         */
        void end_draw() noexcept {
            if (turn != opposing) {
                int draws = effect_count(END_DRAW_EFFECT);
                
                if (draws) {
                    // The number of card draws cannot exceed
                    //   the number of cards in the deck.
                    if (draws > deck.size()) {
                        draws = deck.size();
                    }
                    
                    // The opponent only sees the number of draws.
                    if (opposing) {
                        draw(draws);
                        announce(DRAW_ANNOUNCEMENT);
                    }
                    
                    // The player sees what was drawn.
                    else {
                        for (int j = 0; j < draws; ++j) {
                            draw(1);
                            announce(LAST_DRAWN_ANNOUNCEMENT);
                        }
                            
                        announce(DRAW_ANNOUNCEMENT);
                    }
                }
                
                unaffect(END_DRAW_EFFECT);
            }
        }
        
        /**
         * Chooses a fighter and returns its index.
         */
        int choose_fighter() const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The choice buttons are initialised.
            std::vector<Button> choice_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                choice_buttons.push_back(
                    Button(
                        renderer.render(
                            CHOICE_STRING,
                            CHOICE_WIDTH * display.width(),
                            CHOICE_HEIGHT * display.height(),
                            CHOICE_SEPARATION * display.width()
                        ),
                        display,
                        CHOICE_X,
                        CHOICE_Y + i * CHOICE_Y_SHIFT
                    )
                );
            }
    
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (fighters.size() - 1) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && page * PAGE_COUNT + i < fighters.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    fighters[page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The choice button is displayed.
                    choice_buttons[i].blit_to(display);
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (fighters.size() - 1) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && page * PAGE_COUNT + i < fighters.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                fighters[page * PAGE_COUNT + i].view(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a fighter card to choice to.
                            else if (choice_buttons[i].get_rectangle().unclick()) {
                                return page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Resets the agility of the player's fighters.
         */
        void reset_agility() noexcept {
            // Agility is only reset at the end of the player's turn.
            if (turn == opposing) {
                for (int i = 0; i < fighters.size(); ++i) {
                    fighters[i].unaffect(AGILITY_EFFECT);
                }
            }
        }

        /**
         * Returns the total effect of all of the player's fighter.
         */
        int fighter_effect_count(const std::string& effect) const noexcept {
            int count = 0;
            
            for (int i = 0; i < fighters.size(); ++i) {
                count += fighters[i].effect_count(effect);
            }
            
            return count;
        }
        
        /**
         * Returns true if one of the player's fighters has the given effect.
         */
        bool fighter_effect_search(const std::string& effect) const noexcept {
            for (int i = 0; i < fighters.size(); ++i) {
                if (fighters[i].effect_search(effect).size()) {
                    return true;
                }
            }
            
            return false;
        }
        
        /**
         * Chooses a benched fighter and returns its index.
         */
        int choose_bench() const noexcept {
            // The left button is initialised.
            Button left_button(
                Sprite(
                    LEFT_SOURCE,
                    LEFT_WIDTH * display.width(),
                    LEFT_HEIGHT * display.height()
                ),
                display,
                LEFT_X,
                LEFT_Y
            );
            
            // The right button is initialised.
            Button right_button(
                Sprite(
                    RIGHT_SOURCE,
                    RIGHT_WIDTH * display.width(),
                    RIGHT_HEIGHT * display.height()
                ),
                display,
                RIGHT_X,
                RIGHT_Y
            );
            
            // The choice buttons are initialised.
            std::vector<Button> choice_buttons;
            
            for (int i = 0; i < PAGE_COUNT; ++i) {
                choice_buttons.push_back(
                    Button(
                        renderer.render(
                            CHOICE_STRING,
                            CHOICE_WIDTH * display.width(),
                            CHOICE_HEIGHT * display.height(),
                            CHOICE_SEPARATION * display.width()
                        ),
                        display,
                        CHOICE_X,
                        CHOICE_Y + i * CHOICE_Y_SHIFT
                    )
                );
            }
    
            // Determines which cards are displayed.
            int page = 0;
            
            while (true) {
                // The sprites are blitted to the display.
                display.fill();
                
                if (page > 0) {
                    left_button.blit_to(display);
                }
                
                if (page < (fighters.size() - 2) / PAGE_COUNT) {
                    right_button.blit_to(display);
                }
                
                // A vector of buttons for the names is generated.
                std::vector<Button> name_buttons;
                
                // The cards' names on the page are displayed.
                for (
                    int i = 0;
                    i < PAGE_COUNT
                    && BENCH_INDEX + page * PAGE_COUNT + i < fighters.size();
                    ++i
                ) {
                    // The name button is stored in the vector.
                    name_buttons.push_back(
                        Button(
                            Sprite(
                                renderer.render(
                                    fighters[BENCH_INDEX + page * PAGE_COUNT + i].get_name(),
                                    PAGE_WIDTH * display.width(),
                                    PAGE_HEIGHT * display.height(),
                                    PAGE_SEPARATION * display.width()
                                )
                            ),
                            display,
                            PAGE_NAME_X,
                            PAGE_Y + i * PAGE_Y_SHIFT
                        )
                    );
                    
                    // The name is displayed.
                    name_buttons[i].blit_to(display);
                    
                    // The choice button is displayed.
                    choice_buttons[i].blit_to(display);
                }
                
                // The display is updated.
                display.update();
                
                // Loop to get user input.
                while (true) {
                    // The page number is decremented (if possible).
                    if (
                        (
                            Events::unpress(Events::LEFT)
                            || left_button.get_rectangle().unclick()
                        ) && page > 0
                    ) {
                        --page;
                        break;
                    }
                    
                    // The page number is incremented (if possible).
                    else if (
                        (
                            Events::unpress(Events::RIGHT)
                            || right_button.get_rectangle().unclick()
                        ) && page < (fighters.size() - 2) / PAGE_COUNT
                    ) {
                        ++page;
                        break;
                    }
                    
                    // The other buttons are checked.
                    else {
                        // True if the button being clicked was found.
                        bool found = false;
                        
                        // The plus and minus buttons increment or decrement
                        //   the number of copies of a card in the deck.
                        // The names display the card's details.
                        for (
                            int i = 0;
                            i < PAGE_COUNT
                            && BENCH_INDEX + page * PAGE_COUNT + i < fighters.size();
                            ++i
                        ) {
                            // Diplays a card's details.
                            if (name_buttons[i].get_rectangle().unclick()) {
                                fighters[BENCH_INDEX + page * PAGE_COUNT + i].view(
                                    display,
                                    renderer,
                                    back_button
                                );
                                
                                found = true;
                                break;
                            }
                            
                            // Chooses a fighter card to choice to.
                            else if (choice_buttons[i].get_rectangle().unclick()) {
                                return BENCH_INDEX + page * PAGE_COUNT + i;
                            }
                        }
                        
                        if (found) {
                            break;
                        }
                    }
                    
                    // The events are updated.
                    Events::update();
                }
            }
        }
        
        /**
         * Empties the message and waits for a new one.
         */
        void get_message() noexcept {
            message = EMPTY_MESSAGE;
            messenger_thread.new_thread(
                MessengerPackage::get_message,
                &messenger_package
            );
        }
        
        /**
         * Draws a number of life cards from the life card store.
         * All of the life cards are drawn automatically, if the number of
         *   life cards to draw equals or exceeds the number of life cards.
         */
        void draw_life(int life_draws) noexcept {
            // If the player draws all of their life cards, they lose.
            if (life_draws >= life_cards.size()) {
                if (life_cards.size()) {
                    // Set for the announcement.
                    life_draws = life_cards.size();
                    
                    // All of the life cards are drawn.
                    while (life_cards.size()) {
                        hand.store(life_cards.remove());
                    }
                    
                    announce(NO_LIFE_ANNOUNCEMENT);
                }
                
                return;
            }
            
            // The opponent sees the number of life cards drawn.
            if (opposing && life_draws) {
                announce(LIFE_DRAW_ANNOUNCEMENT, false);
            }
            
            for (int i = 0; i < life_draws; ++i) {
                // The index of the life card to draw.
                int index;
                
                // If this is the player, they choose the life cards to draw.
                if (!opposing) {
                    // Informs the player that they should draw a life card.
                    announce(DRAW_LIFE_ANNOUNCEMENT);
                    
                    // The index of the life card to be drawn is chosen.
                    index = life_cards.choose(
                        display,
                        renderer,
                        back_button
                    );
                    
                    // The index is sent.
                    messenger.send(std::to_string(index));
                }
                
                // Else, the choice of life cards is waited for.
                else {
                    while (message == EMPTY_MESSAGE) {
                        Events::update();
                    }
                    
                    // The index is set.
                    index = std::stoi(message);
                    
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                }
                
                // The life card is drawn.
                hand.store(life_cards.remove(index));
            }
        }
        
        /**
         * Banishes a number of life cards from the life card store.
         * All of the life cards are banished automatically, if the number of
         *   life cards to banish equals or exceeds the number of life cards.
         */
        void banish_life(int life_banishes) noexcept {
            // If the player banishes all of their life cards, they lose.
            if (life_banishes >= life_cards.size()) {
                if (life_cards.size()) {
                    // Set for the announcement.
                    life_banishes = life_cards.size();
                    
                    // All of the life cards are banished.
                    while (life_cards.size()) {
                        the_void.store(life_cards.remove());
                    }
                    
                    announce(NO_LIFE_ANNOUNCEMENT);
                }
                
                return;
            }
            
            // The opponent sees the number of life cards banished.
            if (opposing && life_banishes) {
                announce(LIFE_BANISH_ANNOUNCEMENT, false);
            }
            
            for (int i = 0; i < life_banishes; ++i) {
                // The index of the life card to banish.
                int index;
                
                // If this is the player, they choose the life cards to banish.
                if (!opposing) {
                    // Informs the player that they should banish a life card.
                    announce(BANISH_LIFE_ANNOUNCEMENT);
                    
                    // The index of the life card to be banished is chosen.
                    index = life_cards.choose(
                        display,
                        renderer,
                        back_button
                    );
                    
                    // The index is sent.
                    messenger.send(std::to_string(index));
                }
                
                // Else, the choice of life cards is waited for.
                else {
                    while (message == EMPTY_MESSAGE) {
                        Events::update();
                    }
                    
                    // The index is set.
                    index = std::stoi(message);
                    
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                }
                
                // The life card is banished.
                announce(BANISH_LIFE_PEEK_ANNOUNCEMENT);
                the_void.store(life_cards.remove(index));
            }
        }
        
        /**
         * Heals all of the player's fighters at the end of the turn.
         */
        void heal_aura() noexcept {
            // Healing aura only heals at the end of the player's turn.
            if (turn == opposing) {
                // The amount to heal is found.
                int healing = fighter_effect_count(HEAL_AURA_EFFECT);
                
                // Only non-zero healing is considered.
                if (healing) {
                    heal(healing);
                    announce(HEAL_AURA_ANNOUNCEMENT);
                }
            }
        }
        
        /**
         * Heals all of the player's fighters the given amount.
         */
        void heal(int healing) noexcept {
            for (int i = 0; i < fighters.size(); ++i) {
                fighters[i].heal(healing);
            }
        }
        
        /**
         * Any cards that are to be discarded at the end of the turn are discarded.
         */
        void end_discard() noexcept {
            std::vector<std::vector<std::string>> filtered(
                effect_search(END_DISCARD_EFFECT)
            );
            
            for (int i = 0; i < filtered.size(); ++i) {
                const std::string& name = filtered[i][1];
                
                for (int index = hand.size() - 1; index >= 0; --index) {
                    if (hand[index].get_name() == name) {
                        announce(DISCARD_PEEK_ANNOUNCEMENT);
                        trash.store(hand.remove(index));
                    }
                }
            }
            
            // The End Discard effect is removed.
            unaffect(END_DISCARD_EFFECT);
        }
        
        /**
         * Removes the invinciblity effect from the player's active fighter.
         * This function only takes effect after the opponent's turn.
         */
        void vincible() noexcept {
            if (turn != opposing) {
                fighters[0].unaffect(INVINCIBILITY_EFFECT);
            }
        }
        
        /**
         * Removes the cripple effect from the player's active fighter.
         * This function only takes effect after the player's turn.
         */
        void uncripple() noexcept {
            if (turn == opposing) {
                fighters[0].unaffect(CRIPPLE_EFFECT);
            }
        }
        
        /**
         * Removes the impair effect from the player's active fighter.
         * This function only takes effect after the player's turn.
         */
        void unimpair() noexcept {
            if (turn == opposing) {
                fighters[0].unaffect(IMPAIR_EFFECT);
            }
        }
        
        /**
         * Banishes all of the cards in the trash.
         * This function only takes effect after the player's turn.
         */
        void banishment() noexcept {
            if (turn == opposing && fighter_effect_search(BANISHMENT_EFFECT)) {
                the_void.store(trash);
                announce(BANISHMENT_ANNOUNCEMENT);
            }
        }
        
        /**
         * Reset the ability usage of the player's fighters.
         */
        void reset_abilities() noexcept {
            for (int i = 0; i < fighters.size(); ++i) {
                fighters[i].reset_ability();
            }
        }
        
        /**
         * Deals damage to a cursed actie fighter.
         */
        void curse() noexcept {
            // Curses can only affect the active fighter.
            int index = 0;
            
            // The curse's damage is extracted.
            int damage = fighters[index].effect_count(CURSE_EFFECT);
            
            // If the fighter is cursed, the damage is dealt and announced.
            if (damage) {
                damage = fighters[index].damage(damage);
                announce(FRIENDLY_DAMAGE_ANNOUNCEMENT);
            }
        }
        
        /**
         * Switches in all fighters with the aggressive effect.
         * This effect happens at the end of each action.
         */
        void aggressive() noexcept {
            for (int index = 1; index < fighters.size(); ++index) {
                if (fighters[index].effect_search(AGGRESSIVE_EFFECT).size()) {
                    switch_in(index);
                }
            }
        }
        
        /**
         * Increments the number of cards playable and resets the number of cards played.
         * Also manages the overload effect on the player.
         * Takes effect at the end of the player's turn.
         */
        void reset_plays() noexcept {
            if (turn == opposing) {
                card_limit += CARD_LIMIT_INCREMENT;
                plays = card_limit - effect_count(OVERLOAD_EFFECT);
                
                // The player cannot have a negative number of plays.
                if (plays < 0) {
                    plays = 0;
                }
                
                unaffect(OVERLOAD_EFFECT);
            }
        }
        
        /**
         * Returns the power boost of the active fighter's attack.
         */
        int get_boost() const noexcept {
            // A copy of the attack is extracted.
            Attack attack(fighters[0].get_attack());
            
            // The effects are extracted.
            const std::vector<std::vector<std::string>>& effects = attack.get_effects();
            
            // The damage boost from the attack's effects.
            int boost = 0;
            
            // The attack's effects are resolved.
            for (int i = 0; i < effects.size(); ++i) {
                // The attack's damage can be increased.
                if (effects[i][0] == POWER_EFFECT) {
                    // The damage is boosted by the number of cards in the trash.
                    if (effects[i][1] == TRASH_EFFECT) {
                        boost += trash.size() * std::stoi(effects[i][2]);
                    }
                    
                    // The damage is boosted by the fighter's total energy value.
                    else if (effects[i][1] == ENERGY_TYPE) {
                        int proto_boost = round(
                            fighters[0].energy_value()
                            * std::stod(effects[i][2])
                        );
                        
                        int max_boost = std::stoi(effects[i][3]);
                        
                        if (proto_boost > max_boost) {
                            proto_boost = max_boost;
                        }
                        
                        boost += proto_boost;
                    }
                    
                    // The damage is boosted if the fighter is invincible.
                    else if (
                        effects[i][1] == INVINCIBILITY_EFFECT
                        && fighters[0].effect_search(INVINCIBILITY_EFFECT).size()
                    ) {
                        boost += std::stoi(effects[i][2]);
                    }
                    
                    // The damage is boosted if the deck has no fighter cards.
                    else if (
                        effects[i][1] == FIGHTERLESS_EFFECT
                        && !deck.get_fighters().size()
                    ) {
                        boost += std::stoi(effects[i][2]);
                    }
                    
                    // The damage is boosted by the number of cards in the void.
                    else if (effects[i][1] == VOID_EFFECT) {
                        int proto_boost = the_void.size() * std::stoi(effects[i][2]);
                        int max_boost = std::stoi(effects[i][3]);
                        
                        if (proto_boost > max_boost) {
                            proto_boost = max_boost;
                        }
                        
                        boost += proto_boost;
                    }
                    
                    // The damage is boosted by the number of cards in the hand.
                    else if (effects[i][1] == HAND_EFFECT) {
                        boost += hand.size() * std::stoi(effects[i][2]);
                    }
                }
            
                // The attack deals damage over time.
                else if (effects[i][0] == CURSE_EFFECT) {
                    // The damage is dependent on the void's size.
                    if (effects[i][1] == VOID_EFFECT) {
                        int curse_value = the_void.size() * std::stoi(effects[i][2]);
                        int max_curse = std::stoi(effects[i][3]);
                        
                        if (curse_value > max_curse) {
                            curse_value = max_curse;
                        }
                        
                        boost += curse_value;
                    }
                }
            }
            
            return boost;
        }
        
        /**
         * Increments the number of plays.
         */
        void extra_plays(int increment = 1) noexcept {
            plays += increment;
        }
        
        /**
         * Removes the root effect from the player's active fighter.
         * This function only takes effect after the opponent's turn.
         */
        void unroot() noexcept {
            if (turn != opposing) {
                if (fighters[0].effect_search(DOUBLE_ROOT_EFFECT).size()) {
                    fighters[0].unaffect(DOUBLE_ROOT_EFFECT);
                }
                
                else {
                    fighters[0].unaffect(ROOT_EFFECT);
                }
            }
        }
        
    private:
        CardStore deck; // The player's deck (where the player's cards start off in).
        CardStore hand; // The player's hand (where cards that can be played go).
        CardStore trash; // The player's trash (where discarded cards are stored).
        CardStore life_cards; // If the player draws all of these cards, they lose.
        // The player's active and benched fighters are stored here.
        std::vector<Fighter> fighters;
        int mulligan_count = 0; // The number of mulligans performed.
        std::unique_ptr<Card> last_drawn; // A copy of the last "drawn" card.
        int last_draws; // The number of cards "drawn" most recently.
        int last_chosen; // The index of the fighter chosen most recently.
        bool attacked = false; // True if the player has attacked this turn.
        bool retreated = false; // True if the player has retreated this turn.
        Display& display; // A reference to the display.
        const Renderer& renderer; // A constant reference to the renderer.
        const Messenger& messenger; // A constant reference to the messenger.
        MessengerPackage& messenger_package; // A reference to the messenger thread package.
        Thread& messenger_thread; // A reference to the thread used to get messages.
        const Button& back_button; // A constant reference to the back button.
        const Button& next_button; // A constant reference to the next button.
        Player* opponent; // A pointer to the opponent.
        CardStore& the_void; // A reference to the void card store.
        std::mt19937& generator; // A reference to the random number generator.
        bool opposing; // True if this player is the opponent (equates turn during turn).
        std::string& message; // A reference to the message sent by the opponent.
        const bool& turn; // A reference to the current turn (equates opposing during turn).
        const int& turn_count; // A reference to the number of turns passed.
        int card_limit = BASE_CARD_LIMIT; // The base number of cards that can be played.
        int plays = BASE_CARD_LIMIT; // The number of cards that can be played.
};
//}

// Deck Generator
//{
/**
 * A class that defines a generatable deck.
 */
class DeckCode {
    public:
        /**
         * Constructs a deck code with its name, description, and code.
         */
        DeckCode(
            const std::string& name,
            const std::string& description,
            const std::array<int, CARD_COUNT>& code
        ) noexcept:
            name(name),
            description(description),
            code(code),
            size()
        {
            for (int i = 0; i < CARD_COUNT; ++i) {
                size += code[i];
            }
        }
        
        /**
         * Returns the deck code's name.
         */
        const std::string& get_name() const noexcept {
            return name;
        }
        
        /**
         * Returns the deck's description.
         */
        const std::string& get_description() const noexcept {
            return description;
        }
        
        /**
         * Returns the deck's code.
         */
        const std::array<int, CARD_COUNT>& get_code() const noexcept {
            return code;
        }
        
        /**
         * Returns the number of cards that will be generated.
         */
        int get_size() const noexcept {
            return size;
        }
        
    private:
        std::string name;                 // The name of the deck.
        std::string description;          // The description of the deck.
        std::array<int, CARD_COUNT> code; // Corresponds with the deck's contents.
        int size;                         // The number of cards in the deck.
};

// Deck Codes
//{
const DeckCode TEST_DECK(
    "Test",
    "A deck for gametesting.",
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
        
        4, // APPRENTICE
        4, // SENSEI'S CHOSEN
        4, // NINJA
        4, // SAMURAI
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        0, // LECTURER
        0, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        0, // RECRUITER
        
        0, // CHEF
        0, // TRADER
        0, // LIBRARIAN
        0, // EXPERIMENTER
        0, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        0, // ELECTRICIAN
        0, // ALCHEMIST
        0, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        0, // NURSE
        0, // INNKEEPER
        0, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        4, // ARMS SMUGGLER
        0, // MANIAC
        
        0, // PEACEMAKER
        0, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        0, // LOCK PICKER
        0, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        5, // ALPHA ENERGY
        0, // OMEGA ENERGY
        5  // BOND ENERGY
    }
);

const DeckCode CLEAR_DECK(
    "Clear Deck",
    "Clears the deck currently being built.",
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
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        0, // LECTURER
        0, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        0, // RECRUITER
        
        0, // CHEF
        0, // TRADER
        0, // LIBRARIAN
        0, // EXPERIMENTER
        0, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        0, // ELECTRICIAN
        0, // ALCHEMIST
        0, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        0, // NURSE
        0, // INNKEEPER
        0, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        0, // PEACEMAKER
        0, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        0, // LOCK PICKER
        0, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        0, // ALPHA ENERGY
        0, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);

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
        
        0, // CHEF
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
        1, // ESCAPE ARTIST
        
        1, // ASSASSIN
        1, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        1, // PEACEMAKER
        1, // MATCHMAKER
        1, // PLUMBER
        1, // LOCKSMITH
        1, // LOCK PICKER
        1, // GATEKEEPER
        0, // MILLER
        1, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
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
);

const DeckCode RANDOM_DECK(
    "Random",
    "Generates a deck, randomly chosen from the available decklists.",
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
        
        0, // FIRE ELEMENTAL
        0, // AIR ELEMENTAL
        0, // WATER ELEMENTAL
        0, // EARTH ELEMENTAL
        0, // OMEGA ELEMENTAL
        
        // Supporter Cards
        0, // PROFESSOR
        0, // LECTURER
        0, // INVESTOR
        0, // RESEARCHER
        0, // GAMBLER
        0, // RECRUITER
        
        0, // CHEF
        0, // TRADER
        0, // LIBRARIAN
        0, // EXPERIMENTER
        0, // PERSONAL TRAINER
        0, // SCAPEGOAT
        
        0, // ELECTRICIAN
        0, // ALCHEMIST
        0, // TIME TRAVELLER
        0, // BANKER
        0, // GLUTTON
        
        0, // SUBSTITUTE
        0, // BOUNTY HUNTER
        
        0, // NURSE
        0, // INNKEEPER
        0, // MIRACLE WORKER
        0, // DOCTOR
        0, // ESCAPE ARTIST
        
        0, // ASSASSIN
        0, // SNIPER
        
        0, // CHEERLEADER
        0, // ARMS SMUGGLER
        0, // MANIAC
        
        0, // PEACEMAKER
        0, // MATCHMAKER
        0, // PLUMBER
        0, // LOCKSMITH
        0, // LOCK PICKER
        0, // GATEKEEPER
        0, // MILLER
        0, // ARSONIST
        
        // Energy Cards
        0, // FIRE ENERGY
        0, // AIR ENERGY
        0, // WATER ENERGY
        0, // EARTH ENERGY
        
        0, // UNIVERSAL ENERGY
        0, // ALPHA ENERGY
        0, // OMEGA ENERGY
        0  // BOND ENERGY
    }
);
//}

// All of the deck codes.
constexpr int DECK_CODE_COUNT = 11;
const DeckCode* const ALL_DECK_CODES[DECK_CODE_COUNT] = {
//  &TEST_DECK,
    &CLEAR_DECK,
    &AGGRO_DECK,
    &TEMPO_DECK,
    &BLEND_DECK,
    &CONTROL_DECK,
    &MILL_DECK,
    &MIDRANGE_DECK,
    &AGGRO_COMBO_DECK,
    &CONTROL_COMBO_DECK,
    &OTK_COMBO_DECK,
    &RANDOM_DECK
};
//}

// Main Functions
//{
// Main Game Functions
//{ 
/**
 * Converts a deck code from an array to a string.
 */
std::string to_deck_code(const std::array<int, CARD_COUNT>& card_counts) noexcept {
    std::stringstream stream;
    
    for (int i = 0; i < CARD_COUNT; i++) {
        stream << card_counts[i] << ' ';
    }
    
    return stream.str();
}

/**
 * Allows the player to draw extra cards after a successful mulligan.
 * Returns the number of extra cards drawn in string form.
 */
std::string bonus_draw(
    Display& display,
    const Renderer& renderer,
    Player& player,
    std::mt19937& generator,
    const Button& next_button,
    int difference
) {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The bonus sprite is initialised.
    Sprite bonus_sprite(
        renderer.render(
            BONUS_STRING,
            BONUS_WIDTH * display_width,
            BONUS_HEIGHT * display_height,
            BONUS_SEPARATION * display_width
        )
    );
    
    // The number of cards to be drawn.
    std::string bonus;
    
    // True if the function should return.
    bool end = false;
    
    // Loop to display the bonus draw menu.
    while (!end) {
        // The display is blitted to.
        display_sprite.fill();
        display_sprite.blit(bonus_sprite, BONUS_X, BONUS_Y);
        next_button.blit_to(display_sprite);
        
        // The host port is rendered.
        display_sprite.blit(
            renderer.render(
                bonus,
                BONUS_WIDTH * display_width,
                BONUS_HEIGHT * display_height,
                BONUS_SEPARATION * display_width
            ),
            BONUS_X,
            BONUS_Y + BONUS_SHIFT
        );
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // If the user clicks the next button or presses
            //   the submit key, the cards are drawn.
            if (
                Events::unpress(SUBMIT_KEY)
                || next_button.get_rectangle().unclick()
            ) {
                int draws;
                
                // An attempt to get an integral number of draws is tried.
                try {
                    draws = std::stoi(bonus);
                }
                
                // If it fails, the number of draws is set to -1.
                catch (const std::exception&) {
                    draws = -1;
                }
                
                // If the number of cards to be drawn is valid, the cards are drawn.
                // Drawing terminates this functions.
                if (0 <= draws && draws <= difference) {
                    player.draw(draws);
                    end = true;
                }
                
                break;
            }
            
            // If the user presses the delete button,
            //   the last character entered is removed.
            else if (Events::unpress(DELETE_KEY) && bonus.length()) {
                bonus.pop_back();
                break;
            }
            
            // Else the number buttons are checked to form the bonus string.
            else {
                // True when the key being pressed is found.
                bool found = false;
                
                // The numbers are checked.
                for (int i = 0; !found && i < NUMBERS; i++) {
                    if (Events::unpress(Events::NUMBERS[i])) {
                        bonus += '0' + i;
                        found = true;
                    }
                }
                
                // If a valid key was pressed, the display is updated.
                if (found) {
                    break;
                }
            }

            Events::update();
        }
    }
    
    return bonus;
}

/**
 * Displays how many cards the opponent drew.
 */
void display_draw_count(
    Display& display,
    const Renderer& renderer,
    int draws
) noexcept {
    display.fill();
    display.blit(
        renderer.lined_render(
            OPPONENT_DRAW_STRING,
            OPPONENT_DRAW_WIDTH * display.width(),
            OPPONENT_DRAW_HEIGHT * display.height(),
            OPPONENT_DRAW_SEPARATION_X * display.width(),
            OPPONENT_DRAW_MAX_WIDTH * display.width(),
            OPPONENT_DRAW_SEPARATION_Y * display.height(),
            OPPONENT_DRAW_JUSTIFICATION
        ),
        OPPONENT_DRAW_X,
        OPPONENT_DRAW_Y
    );
}

/**
 * The mulligan is performed.
 * Each player draws cards from their deck to form their starting hand.
 * If a player does not have a "basic" fighter, they redraw.
 * The player that redrew a lower number of times can draw an
 *   extra card for each extra redraw that the opponent performed.
 */
void mulligan(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    std::vector<Player>& players,
    bool turn,
    std::mt19937& generator,
    const Button& next_button
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    display_sprite.fill();
    display_sprite.blit(
        renderer.lined_render(
            MULLIGAN_STRING,
            MULLIGAN_WIDTH * display_width,
            MULLIGAN_HEIGHT * display_height,
            MULLIGAN_SEPARATION_X * display_width,
            MULLIGAN_MAX_WIDTH * display_width,
            MULLIGAN_SEPARATION_Y * display_height,
            MULLIGAN_JUSTIFICATION
        ),
        MULLIGAN_X,
        MULLIGAN_Y
    );
    next_button.blit_to(display_sprite);
    display.update();
    
    // The user proceeds at their discretion.
    while (
        !Events::unpress(SUBMIT_KEY)
        && !next_button.get_rectangle().unclick()
    ) {
        Events::update();
    }
    
    // While both players do not have a valid hand, the mulligan continues.
    while (!players[0].valid_hand() || !players[1].valid_hand()) {
        // The first player performs the mulligan if they don't have a valid hand.
        if (!players[turn].valid_hand()) {
            players[turn].mulligan();
        }
        
        // The second player performs the mulligan if they don't have a valid hand.
        if (!players[!turn].valid_hand()) {
            players[!turn].mulligan();
        }
    }
    
    // The difference in the number of mulligans determines the bonus draws.
    int difference = players[1].count_mulligans() - players[0].count_mulligans();
    
    // The number of extra card draws is limited to allow for the life cards to be played.
    if (difference > MAX_BONUS) {
        difference = MAX_BONUS;
    }
    
    else if (difference < -MAX_BONUS) {
        difference = -MAX_BONUS;
    }
    
    // If the player performed fewer mulligans, they may draw extra cards.
    if (difference > 0) {
        display_sprite.fill();
        display_sprite.blit(
            renderer.lined_render(
                BONUS_DRAW_STRING,
                BONUS_DRAW_WIDTH * display_width,
                BONUS_DRAW_HEIGHT * display_height,
                BONUS_DRAW_SEPARATION_X * display_width,
                BONUS_DRAW_MAX_WIDTH * display_width,
                BONUS_DRAW_SEPARATION_Y * display_height,
                BONUS_DRAW_JUSTIFICATION
            ),
            BONUS_DRAW_X,
            BONUS_DRAW_Y
        );
        next_button.blit_to(display_sprite);
        display.update();
        
        // The user proceeds at their discretion.
        while (
            !Events::unpress(SUBMIT_KEY)
            && !next_button.get_rectangle().unclick()
        ) {
            Events::update();
        }
        
        players[PLAYER].view_hand();
        
        messenger.send(bonus_draw(
            display,
            renderer,
            players[0],
            generator,
            next_button,
            difference
        ));
    }
    
    // If the opponent performed fewer mulligans, the may draw extra cards.
    else if (difference < 0) {
        // The opponent's draw potential is revealed.
        display_sprite.fill();
        display_sprite.blit(
            renderer.lined_render(
                NO_BONUS_DRAW_STRING,
                NO_BONUS_DRAW_WIDTH * display_width,
                NO_BONUS_DRAW_HEIGHT * display_height,
                NO_BONUS_DRAW_SEPARATION_X * display_width,
                NO_BONUS_DRAW_MAX_WIDTH * display_width,
                NO_BONUS_DRAW_SEPARATION_Y * display_height,
                NO_BONUS_DRAW_JUSTIFICATION
            ),
            NO_BONUS_DRAW_X,
            NO_BONUS_DRAW_Y
        );
        display.update();
        
        // The draw count is received from the opponent.
        std::string draw_string(EMPTY_MESSAGE);
        MessengerPackage draw_package(messenger, draw_string);
        Thread draw_thread(MessengerPackage::get_message, &draw_package);
        
        // Events are updated to prevent closure due to app inactivity.
        while (draw_string == EMPTY_MESSAGE) {
            Events::update();
        }
        
        int draws = std::stoi(draw_string);
        
        // The user can advance when the opponent has sent their message.
        next_button.blit_to(display_sprite);
        display.update();
        
        // The user proceeds at their discretion.
        while (
            !Events::unpress(SUBMIT_KEY)
            && !next_button.get_rectangle().unclick()
        ) {
            Events::update();
        }
        
        // The opponent draws.
        players[1].draw(draws);
        
        // The opponent's bonus draw is revealed.
        display_draw_count(display, renderer, draws);
        next_button.blit_to(display_sprite);
        display.update();
        
        // The user proceeds at their discretion.
        while (
            !Events::unpress(SUBMIT_KEY)
            && !next_button.get_rectangle().unclick()
        ) {
            Events::update();
        }
    }
}

/**
 * Checks the player for defeated fighters.
 */
int defeat_check(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    MessengerPackage& messenger_package,
    Thread& messenger_thread,
    const Button& back_button,
    const Button& next_button,
    std::vector<Player>& players,
    CardStore& the_void,
    std::mt19937& generator,
    bool turn
) noexcept {
    // The player, whose turn it is, is checked first.
    players[turn].defeat_check();
    
    // The other player is then checked.
    players[!turn].defeat_check();
    
    // The number of win conditions is calculated.
    std::array<int, PLAYERS> win_conditions{};
    
    win_conditions[turn] = players[!turn].loss_conditions();
    win_conditions[!turn] = players[turn].loss_conditions();
    
    // No player has reached a win condition yet.
    if (!win_conditions[turn] && !win_conditions[!turn]) {
        return NO_END;
    }
    
    // Tie game.
    else if (win_conditions[turn] == win_conditions[!turn]) {
        return TIE;
    }
    
    // The winner is returned.
    else {
        return win_conditions[OPPONENT] > win_conditions[PLAYER];
    }
}

/**
 * Hosts the main game.
 */
void game(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    const std::array<int, CARD_COUNT>& card_counts,
    MessengerPackage& messenger_package,
    Thread& messenger_thread
) noexcept {
    // Game set up.
    //{
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The wait screen sprite is intialised.
    Sprite wait_sprite(
        renderer.lined_render(
            WAIT_STRING,
            WAIT_WIDTH * display_width,
            WAIT_HEIGHT * display_height,
            WAIT_SEPARATION_X * display_width,
            WAIT_MAX_WIDTH * display_width,
            WAIT_SEPARATION_Y * display_height,
            WAIT_JUSTIFICATION
        )
    );
    
    // The wait screen is rendered.
    display_sprite.fill();
    display_sprite.blit(wait_sprite, WAIT_X, WAIT_Y);
    display.update();
    
    // The main game song is loaded and queued in another thread.
    Audio duel_song(DUEL_SONG_SOURCE, DUEL_SONG_LENGTH);
    Thread song_thread(Audio::thread_queue, &duel_song);
    
    // The message is extracted from the package.
    std::string& message = messenger_package.get_string();
    
    // The seeder is determined.
    // The player with the smaller value seeds the RNG.
    std::array<double, PLAYERS> speeds = {0, 0};
    
    while (speeds[0] == speeds[1]) {
        speeds[0] = Timer::time();
        messenger.send(std::to_string(speeds[0]));
        
        // The opponent's message is waited for.
        // Event updating is used to prevent "app inactivity".
        while (message == EMPTY_MESSAGE) {
            Events::update();
        }
        
        // If the other player quit, the game cannot begin.
        if (message == TERMINATOR_STRING) {
            duel_song.pause();
            return;
        }
        
        speeds[1] = std::stod(message);
    }
    
    int seed;
    
    // The smaller value player determines the seed and sends it to the other.
    if (speeds[0] < speeds[1]) {
        seed = Timer::current();
        messenger.send(std::to_string(seed));
    }
    
    // The greater value player receives the seed.
    else {
        // The seed is received.
        seed = std::stoi(messenger.read());
    }
    
    // The RNG is seeded.
    std::mt19937 generator(seed);
    
    // The player to go first is determined.
    // Player's turn when turn is false.
    // Opponent's turn when turn is true.
    bool turn;
    
    // A coin is flipped to determine who goes first.
    if (speeds[0] < speeds[1]) {
        turn = Player::coin_flip(generator);
    }
    
    // The coin flip to go first is mirrored.
    else {
        turn = !Player::coin_flip(generator);
    }
    
    // The deck code is converted to string form and exchanged.
    std::array<std::string, PLAYERS> deck_codes;
    deck_codes[0] = to_deck_code(card_counts);
    messenger.send(deck_codes[0]);
    deck_codes[1] = messenger.read();
    
    // The back button is initialised.
    Button back_button(
        renderer.render(
            BACK_STRING,
            BACK_WIDTH * display.width(),
            BACK_HEIGHT * display.height(),
            BACK_SEPARATION * display.width()
        ),
        display,
        BACK_X,
        BACK_Y
    );
    
    // The next button is initialised.
    Button next_button(
        renderer.render(
            NEXT_STRING,
            NEXT_WIDTH * display_width,
            NEXT_HEIGHT * display_height,
            NEXT_SEPARATION * display_width
        ),
        display_sprite,
        NEXT_X,
        NEXT_Y
    );
    
    // The void is initialised.
    // The void is shared by the players.
    CardStore the_void;
    
    // Counts the number of rounds that have passed.
    // Fighters may not attack on the first turn.
    int turn_count = 0;
    
    // The players are initialised.
    std::vector<Player> players;
    
    for (int i = 0; i < PLAYERS; ++i) {
        players.push_back(
            Player(
                deck_codes[i],
                display,
                renderer,
                messenger,
                messenger_package,
                messenger_thread,
                back_button,
                next_button,
                the_void,
                generator,
                i,
                turn,
                turn_count
            )
        );
    }
    
    for (int i = 0; i < PLAYERS; ++i) {
        players[i].set_opponent(players[!i]);
    }
    
    // The player ordering is revealed.
    display_sprite.fill();
    display_sprite.blit(
        renderer.lined_render(
            ORDER_STRING,
            ORDER_WIDTH * display_width,
            ORDER_HEIGHT * display_height,
            ORDER_SEPARATION_X * display_width,
            ORDER_MAX_WIDTH * display_width,
            ORDER_SEPARATION_Y * display_height,
            ORDER_JUSTIFICATION
        ),
        ORDER_X,
        ORDER_Y
    );
    next_button.blit_to(display_sprite);
    display.update();
    
    // The user may proceed at their discretion.
    while (
        !Events::unpress(SUBMIT_KEY)
        && !next_button.get_rectangle().unclick()
    ) {
        Events::update();
    }
    
    // The players perform the mulligan.
    mulligan(display, renderer, messenger, players, turn, generator, next_button);
    
    // The life cards are set up.
    players[turn].set_life_cards();
    players[!turn].set_life_cards();
    
    // The player sets up and sends their board.
    messenger.send(players[0].set_active());
    
    // The opponent's choice is waited for.
    message = "";
    messenger_thread.new_thread(MessengerPackage::get_message, &messenger_package);
    
    display.fill();
    display.blit(
        renderer.lined_render(
            WAIT_STRING,
            WAIT_WIDTH * display.width(),
            WAIT_HEIGHT * display.height(),
            WAIT_SEPARATION_X * display.width(),
            WAIT_MAX_WIDTH * display.width(),
            WAIT_SEPARATION_Y * display.height()
        ),
        WAIT_X,
        WAIT_Y
    );
    display.update();
    
    while (message == "") {
        Events::update();
    }
    
    // The opponent's board is set up.
    players[1].set_active(message);
    
    // Non-negative when the game should end.
    int winner = -1;
    
    // The message from the opponent is awaited.
    message = EMPTY_MESSAGE;
    messenger_thread.new_thread(
        MessengerPackage::get_message,
        &messenger_package
    );
    
    // The player taking the first turn can't attack on their first turn.
    players[turn].affect(PREPARATION_EFFECT);
    
    // The player taking the second turn can play an extra card on their first turn.
    players[!turn].extra_plays();
    //}
    
    // Board buttons initialised.
    //{
    // The player's buttons are initialised.
    //{
    // Button for the player's deck.
    Button your_deck_button(
        renderer.lined_render(
            YOUR_DECK_STRING,
            YOUR_DECK_WIDTH * display.width(),
            YOUR_DECK_HEIGHT * display.height(),
            YOUR_DECK_SEPARATION_X * display.width(),
            YOUR_DECK_MAX_WIDTH * display.width(),
            YOUR_DECK_SEPARATION_Y * display.height(),
            YOUR_DECK_JUSTIFICATION
        ),
        display,
        YOUR_DECK_X,
        YOUR_DECK_Y
    );
    
    // Button for the player's trash.
    Button your_trash_button(
        renderer.lined_render(
            YOUR_TRASH_STRING,
            YOUR_TRASH_WIDTH * display.width(),
            YOUR_TRASH_HEIGHT * display.height(),
            YOUR_TRASH_SEPARATION_X * display.width(),
            YOUR_TRASH_MAX_WIDTH * display.width(),
            YOUR_TRASH_SEPARATION_Y * display.height(),
            YOUR_TRASH_JUSTIFICATION
        ),
        display,
        YOUR_TRASH_X,
        YOUR_TRASH_Y
    );
    
    // Button for the player's hand.
    Button your_hand_button(
        renderer.lined_render(
            YOUR_HAND_STRING,
            YOUR_HAND_WIDTH * display.width(),
            YOUR_HAND_HEIGHT * display.height(),
            YOUR_HAND_SEPARATION_X * display.width(),
            YOUR_HAND_MAX_WIDTH * display.width(),
            YOUR_HAND_SEPARATION_Y * display.height(),
            YOUR_HAND_JUSTIFICATION
        ),
        display,
        YOUR_HAND_X,
        YOUR_HAND_Y
    );
    
    // Button for the player's life cards.
    Button your_life_button(
        renderer.lined_render(
            YOUR_LIFE_STRING,
            YOUR_LIFE_WIDTH * display.width(),
            YOUR_LIFE_HEIGHT * display.height(),
            YOUR_LIFE_SEPARATION_X * display.width(),
            YOUR_LIFE_MAX_WIDTH * display.width(),
            YOUR_LIFE_SEPARATION_Y * display.height(),
            YOUR_LIFE_JUSTIFICATION
        ),
        display,
        YOUR_LIFE_X,
        YOUR_LIFE_Y
    );
    
    // Button for the player's active fighter.
    Button your_active_button(
        renderer.lined_render(
            YOUR_ACTIVE_STRING,
            YOUR_ACTIVE_WIDTH * display.width(),
            YOUR_ACTIVE_HEIGHT * display.height(),
            YOUR_ACTIVE_SEPARATION_X * display.width(),
            YOUR_ACTIVE_MAX_WIDTH * display.width(),
            YOUR_ACTIVE_SEPARATION_Y * display.height(),
            YOUR_ACTIVE_JUSTIFICATION
        ),
        display,
        YOUR_ACTIVE_X,
        YOUR_ACTIVE_Y
    );
    
    // Button for the player's benched fighters.
    Button your_bench_button(
        renderer.lined_render(
            YOUR_BENCH_STRING,
            YOUR_BENCH_WIDTH * display.width(),
            YOUR_BENCH_HEIGHT * display.height(),
            YOUR_BENCH_SEPARATION_X * display.width(),
            YOUR_BENCH_MAX_WIDTH * display.width(),
            YOUR_BENCH_SEPARATION_Y * display.height(),
            YOUR_BENCH_JUSTIFICATION
        ),
        display,
        YOUR_BENCH_X,
        YOUR_BENCH_Y
    );
    
    // Button for the player's effects fighters.
    Button your_effects_button(
        renderer.lined_render(
            YOUR_EFFECTS_STRING,
            YOUR_EFFECTS_WIDTH * display.width(),
            YOUR_EFFECTS_HEIGHT * display.height(),
            YOUR_EFFECTS_SEPARATION_X * display.width(),
            YOUR_EFFECTS_MAX_WIDTH * display.width(),
            YOUR_EFFECTS_SEPARATION_Y * display.height(),
            YOUR_EFFECTS_JUSTIFICATION
        ),
        display,
        YOUR_EFFECTS_X,
        YOUR_EFFECTS_Y
    );
    //}
    
    // The opponent's buttons are initialised.
    //{
    // Button for the opponent's deck.
    Button opponent_deck_button(
        renderer.lined_render(
            OPPONENT_DECK_STRING,
            OPPONENT_DECK_WIDTH * display.width(),
            OPPONENT_DECK_HEIGHT * display.height(),
            OPPONENT_DECK_SEPARATION_X * display.width(),
            OPPONENT_DECK_MAX_WIDTH * display.width(),
            OPPONENT_DECK_SEPARATION_Y * display.height(),
            OPPONENT_DECK_JUSTIFICATION
        ),
        display,
        OPPONENT_DECK_X,
        OPPONENT_DECK_Y
    );
    
    // Button for the opponent's trash.
    Button opponent_trash_button(
        renderer.lined_render(
            OPPONENT_TRASH_STRING,
            OPPONENT_TRASH_WIDTH * display.width(),
            OPPONENT_TRASH_HEIGHT * display.height(),
            OPPONENT_TRASH_SEPARATION_X * display.width(),
            OPPONENT_TRASH_MAX_WIDTH * display.width(),
            OPPONENT_TRASH_SEPARATION_Y * display.height(),
            OPPONENT_TRASH_JUSTIFICATION
        ),
        display,
        OPPONENT_TRASH_X,
        OPPONENT_TRASH_Y
    );
    
    // Button for the opponent's hand.
    Button opponent_hand_button(
        renderer.lined_render(
            OPPONENT_HAND_STRING,
            OPPONENT_HAND_WIDTH * display.width(),
            OPPONENT_HAND_HEIGHT * display.height(),
            OPPONENT_HAND_SEPARATION_X * display.width(),
            OPPONENT_HAND_MAX_WIDTH * display.width(),
            OPPONENT_HAND_SEPARATION_Y * display.height(),
            OPPONENT_HAND_JUSTIFICATION
        ),
        display,
        OPPONENT_HAND_X,
        OPPONENT_HAND_Y
    );
    
    // Button for the opponent's life cards.
    Button opponent_life_button(
        renderer.lined_render(
            OPPONENT_LIFE_STRING,
            OPPONENT_LIFE_WIDTH * display.width(),
            OPPONENT_LIFE_HEIGHT * display.height(),
            OPPONENT_LIFE_SEPARATION_X * display.width(),
            OPPONENT_LIFE_MAX_WIDTH * display.width(),
            OPPONENT_LIFE_SEPARATION_Y * display.height(),
            OPPONENT_LIFE_JUSTIFICATION
        ),
        display,
        OPPONENT_LIFE_X,
        OPPONENT_LIFE_Y
    );
    
    // Button for the opponent's active fighter.
    Button opponent_active_button(
        renderer.lined_render(
            OPPONENT_ACTIVE_STRING,
            OPPONENT_ACTIVE_WIDTH * display.width(),
            OPPONENT_ACTIVE_HEIGHT * display.height(),
            OPPONENT_ACTIVE_SEPARATION_X * display.width(),
            OPPONENT_ACTIVE_MAX_WIDTH * display.width(),
            OPPONENT_ACTIVE_SEPARATION_Y * display.height(),
            OPPONENT_ACTIVE_JUSTIFICATION
        ),
        display,
        OPPONENT_ACTIVE_X,
        OPPONENT_ACTIVE_Y
    );
    
    // Button for the opponent's benched fighters.
    Button opponent_bench_button(
        renderer.lined_render(
            OPPONENT_BENCH_STRING,
            OPPONENT_BENCH_WIDTH * display.width(),
            OPPONENT_BENCH_HEIGHT * display.height(),
            OPPONENT_BENCH_SEPARATION_X * display.width(),
            OPPONENT_BENCH_MAX_WIDTH * display.width(),
            OPPONENT_BENCH_SEPARATION_Y * display.height(),
            OPPONENT_BENCH_JUSTIFICATION
        ),
        display,
        OPPONENT_BENCH_X,
        OPPONENT_BENCH_Y
    );
    
    // Button for the opponent's effects fighters.
    Button opponent_effects_button(
        renderer.lined_render(
            OPPONENT_EFFECTS_STRING,
            OPPONENT_EFFECTS_WIDTH * display.width(),
            OPPONENT_EFFECTS_HEIGHT * display.height(),
            OPPONENT_EFFECTS_SEPARATION_X * display.width(),
            OPPONENT_EFFECTS_MAX_WIDTH * display.width(),
            OPPONENT_EFFECTS_SEPARATION_Y * display.height(),
            OPPONENT_EFFECTS_JUSTIFICATION
        ),
        display,
        OPPONENT_EFFECTS_X,
        OPPONENT_EFFECTS_Y
    );
    //}
    
    // The other buttons are initialised.
    //{
    // Button for the void.
    Button the_void_button(
        renderer.render(
            THE_VOID_STRING,
            THE_VOID_WIDTH * display.width(),
            THE_VOID_HEIGHT * display.height(),
            THE_VOID_SEPARATION * display.width()
        ),
        display,
        THE_VOID_X,
        THE_VOID_Y
    );
    
    // Button to end one's turn.
    Button end_turn_button(
        renderer.render(
            END_TURN_STRING,
            END_TURN_WIDTH * display.width(),
            END_TURN_HEIGHT * display.height(),
            END_TURN_SEPARATION * display.width()
        ),
        display,
        END_TURN_X,
        END_TURN_Y
    );
    
    // Button to concede.
    Button concede_button(
        renderer.render(
            CONCEDE_STRING,
            CONCEDE_WIDTH * display.width(),
            CONCEDE_HEIGHT * display.height(),
            CONCEDE_SEPARATION * display.width()
        ),
        display,
        CONCEDE_X,
        CONCEDE_Y
    );
    //}
    //}
    
    // The main game loop.
    while (winner < 0) {
        // If the player can draw at the start of their turn, they do so.
        if (players[turn].can_draw()) {
            int draws = TURN_DRAW;
            players[turn].draw(draws);
            
            // The player sees the drawn card.
            if (!turn) {
                // The drawn card is displayed.
                players[PLAYER].display_last_drawn();
                next_button.blit_to(display);
                display.update();
                
                // The player proceeds at their own discretion
                //   or if the opponent conceded.
                while (
                    !Events::unpress(SUBMIT_KEY)
                    && !next_button.get_rectangle().unclick()
                    && message == EMPTY_MESSAGE
                ) {
                    Events::update();
                }
            }
            
            // The opponent sees the quantity of drawn cards.
            else {
                // The number of cards that the opponent drew is displayed.
                display_draw_count(display, renderer, draws);
                next_button.blit_to(display);
                display.update();
                
                // The player proceeds at their own discretion
                //   or when the opponent makes a move.
                while (
                    !Events::unpress(SUBMIT_KEY)
                    && !next_button.get_rectangle().unclick()
                    && message == EMPTY_MESSAGE
                ) {
                    Events::update();
                }
            }
        }
        
        // Else, they draw a life card.
        else {
            // The player is informed that the draw failed.
            players[0].announce(DRAW_FAIL_STRING);
            
            // The player draws a life card.
            players[turn].draw_life(TURN_DRAW);
        }
        
        // Defeat is checked for at the start of the battle.
        winner = defeat_check(
            display,
            renderer,
            messenger,
            messenger_package,
            messenger_thread,
            back_button,
            next_button,
            players,
            the_void,
            generator,
            turn
        );
        
        // True when the turn should end.
        bool end = false;
        
        // Player's turn.
        while (!turn && !end && winner < 0) {
            // The board is renderered.
            //{
            // The display is cleared.
            display.fill();
            
            // The player's buttons are blitted.
            your_deck_button.blit_to(display);
            your_trash_button.blit_to(display);
            your_hand_button.blit_to(display);
            your_life_button.blit_to(display);
            your_active_button.blit_to(display);
            your_bench_button.blit_to(display);
            your_effects_button.blit_to(display);
            
            // The opponent's buttons are blitted.
            opponent_deck_button.blit_to(display);
            opponent_trash_button.blit_to(display);
            opponent_hand_button.blit_to(display);
            opponent_life_button.blit_to(display);
            opponent_active_button.blit_to(display);
            opponent_bench_button.blit_to(display);
            opponent_effects_button.blit_to(display);
            
            // The other buttons are blitted.
            the_void_button.blit_to(display);
            end_turn_button.blit_to(display);
            concede_button.blit_to(display);
            
            // The display is updated.
            display.update();
            //}
        
            // True when the board should be rerendered.
            bool rerender = false;
        
            // Loop to get user input.
            while (!rerender) {
                // End turn and concede.
                //{
                // The player can end their turn by
                //   clicking the end turn button.
                if (end_turn_button.get_rectangle().unclick()) {
                    messenger.send(END_TURN_STRING);
                    end = true;
                    break;
                }
                
                // The player can concede by clicking the concede button.
                else if (concede_button.get_rectangle().unclick()) {
                    messenger.send(CONCEDE_STRING);
                    
                    // The player is informed that they conceded.
                    display.fill();
                    display.blit(
                        renderer.lined_render(
                            PLAYER_CONCEDE_STRING,
                            PLAYER_CONCEDE_WIDTH * display.width(),
                            PLAYER_CONCEDE_HEIGHT * display.height(),
                            PLAYER_CONCEDE_SEPARATION_X * display.width(),
                            PLAYER_CONCEDE_MAX_WIDTH * display.width(),
                            PLAYER_CONCEDE_SEPARATION_Y * display.height(),
                            PLAYER_CONCEDE_JUSTIFICATION
                        ),
                        PLAYER_CONCEDE_X,
                        PLAYER_CONCEDE_Y
                    );
                    next_button.blit_to(display);
                    display.update();
                    
                    // The player proceeds at their own discretion.
                    while (
                        !Events::unpress(SUBMIT_KEY)
                        && !next_button.get_rectangle().unclick()
                    ) {
                        Events::update();
                    }
                    
                    winner = OPPONENT;
                    end = true;
                    break;
                }
                //}
                
                // Game state checks.
                //{
                // The player can view their deck by clicking on it.
                else if (your_deck_button.get_rectangle().unclick()) {
                    players[PLAYER].view_deck();
                    rerender = true;
                }
                
                // The player can view their trash by clicking on it.
                else if (your_trash_button.get_rectangle().unclick()) {
                    players[PLAYER].view_trash();
                    rerender = true;
                }
                
                // The plyer can view their life cards by clicking on them.
                else if (your_life_button.get_rectangle().unclick()) {
                    players[PLAYER].view_life_cards();
                    rerender = true;
                }
                
                // The player can view the void by clicking on it.
                else if (the_void_button.get_rectangle().unclick()) {
                    the_void.view(display, renderer, message);
                    rerender = true;
                }
                
                // The player can view the opponent's hand's size.
                else if (opponent_hand_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_hand_size();
                    rerender = true;
                }
                
                // The player can view the opponent's deck's size.
                else if (opponent_deck_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_deck_size();
                    rerender = true;
                }
                
                // The player can view the opponent's trash's size.
                else if (opponent_trash_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_trash();
                    rerender = true;
                }
                
                // The player can view the opponent's life cards' size.
                else if (opponent_life_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_life_cards_size();
                    rerender = true;
                }
                
                // The player can view their opponent's active fighter.
                else if (opponent_active_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_active();
                    rerender = true;
                }
                
                // The player can view their opponent's benched fighters.
                else if (opponent_bench_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_bench();
                    rerender = true;
                }
                
                // The player can view their effects.
                else if (your_effects_button.get_rectangle().unclick()) {
                    players[PLAYER].view_effects();
                    rerender = true;
                }
                
                // The player can view their opponent's effects.
                else if (opponent_effects_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_effects();
                    rerender = true;
                }
                //}
                
                // Potential moves.
                //{
                // The player may play a card from their hand during their turn.
                else if (your_hand_button.get_rectangle().unclick()) {
                    players[turn].play();
                    rerender = true;
                }
                
                // The player may use their active fighter during their turn.
                else if (your_active_button.get_rectangle().unclick()) {
                    players[turn].use_active();
                    rerender = true;
                }
                
                // The player may use their benched fighters during their turn.
                else if (your_bench_button.get_rectangle().unclick()) {
                    players[turn].use_bench();
                    rerender = true;
                }
                //}
                
                // Opponent's actions.
                //{
                // The opponent conceded.
                if (message == CONCEDE_STRING) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                
                    // The player is informed that the opponent conceded.
                    display.fill();
                    display.blit(
                        renderer.lined_render(
                            OPPONENT_CONCEDE_STRING,
                            OPPONENT_CONCEDE_WIDTH * display.width(),
                            OPPONENT_CONCEDE_HEIGHT * display.height(),
                            OPPONENT_CONCEDE_SEPARATION_X * display.width(),
                            OPPONENT_CONCEDE_MAX_WIDTH * display.width(),
                            OPPONENT_CONCEDE_SEPARATION_Y * display.height(),
                            OPPONENT_CONCEDE_JUSTIFICATION
                        ),
                        OPPONENT_CONCEDE_X,
                        OPPONENT_CONCEDE_Y
                    );
                    next_button.blit_to(display);
                    display.update();
                    
                    // The player proceeds at their own discretion.
                    // The opponent quitting forces a procession.
                    while (
                        !Events::unpress(SUBMIT_KEY)
                        && !next_button.get_rectangle().unclick()
                        && message != TERMINATOR_STRING
                    ) {
                        Events::update();
                    }
                    
                    winner = PLAYER;
                    end = true;
                    break;
                }
                
                // A message was sent and was not dealt with.
                // This can cause a player desync, so the error is logged.
                else if (message != EMPTY_MESSAGE) {
                    std::cerr
                        << "\nUnhandled message:\n"
                        << message
                        << std::endl
                    ;
                }
                //}
                
                // The events are updated.
                Events::update();
            }
        
            // A concede doesn't require a check.
            if (winner == NO_END) {
                // The players are checked for any defeated fighters.
                winner = defeat_check(
                    display,
                    renderer,
                    messenger,
                    messenger_package,
                    messenger_thread,
                    back_button,
                    next_button,
                    players,
                    the_void,
                    generator,
                    turn
                );
            }
        }
        
        // Opponent's turn.
        while (turn && !end && winner < 0) {
            // The board is renderered.
            //{
            // The display is cleared.
            display.fill();
            
            // The player's buttons are blitted.
            your_deck_button.blit_to(display);
            your_trash_button.blit_to(display);
            your_hand_button.blit_to(display);
            your_life_button.blit_to(display);
            your_active_button.blit_to(display);
            your_bench_button.blit_to(display);
            your_effects_button.blit_to(display);
            
            // The opponent's buttons are blitted.
            opponent_deck_button.blit_to(display);
            opponent_trash_button.blit_to(display);
            opponent_hand_button.blit_to(display);
            opponent_life_button.blit_to(display);
            opponent_active_button.blit_to(display);
            opponent_bench_button.blit_to(display);
            opponent_effects_button.blit_to(display);
            
            // The void' button is blitted.
            the_void_button.blit_to(display);
            concede_button.blit_to(display);
            
            // The display is updated.
            display.update();
            //}
        
            // True when the board should be rerendered.
            bool rerender = false;
        
            // Loop for user input.
            while (!rerender) {
                // The player's actions.
                //{
                // The player can concede by clicking the concede button.
                if (concede_button.get_rectangle().unclick()) {
                    messenger.send(CONCEDE_STRING);
                    
                    // The player is informed that they conceded.
                    display.fill();
                    display.blit(
                        renderer.lined_render(
                            PLAYER_CONCEDE_STRING,
                            PLAYER_CONCEDE_WIDTH * display.width(),
                            PLAYER_CONCEDE_HEIGHT * display.height(),
                            PLAYER_CONCEDE_SEPARATION_X * display.width(),
                            PLAYER_CONCEDE_MAX_WIDTH * display.width(),
                            PLAYER_CONCEDE_SEPARATION_Y * display.height(),
                            PLAYER_CONCEDE_JUSTIFICATION
                        ),
                        PLAYER_CONCEDE_X,
                        PLAYER_CONCEDE_Y
                    );
                    next_button.blit_to(display);
                    display.update();
                    
                    // The player proceeds at their own discretion.
                    while (
                        !Events::unpress(SUBMIT_KEY)
                        && !next_button.get_rectangle().unclick()
                    ) {
                        Events::update();
                    }
                    
                    winner = OPPONENT;
                    end = true;
                    break;
                }
                
                // The player can view their hand by clicking on it.
                else if (your_hand_button.get_rectangle().unclick()) {
                    players[PLAYER].view_hand();
                    rerender = true;
                }
                
                // The player can view their deck by clicking on it.
                else if (your_deck_button.get_rectangle().unclick()) {
                    players[PLAYER].view_deck();
                    rerender = true;
                }
                
                // The player can view their trash by clicking on it.
                else if (your_trash_button.get_rectangle().unclick()) {
                    players[PLAYER].view_trash();
                    rerender = true;
                }
                
                // The plyer can view their life cards by clicking on them.
                else if (your_life_button.get_rectangle().unclick()) {
                    players[PLAYER].view_life_cards();
                    rerender = true;
                }
                
                // The player can view the void by clicking on it.
                else if (the_void_button.get_rectangle().unclick()) {
                    the_void.view(display, renderer, message);
                    rerender = true;
                }
                
                // The player can view the opponent's hand's size.
                else if (opponent_hand_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_hand_size();
                    rerender = true;
                }
                
                // The player can view the opponent's deck's size.
                else if (opponent_deck_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_deck_size();
                    rerender = true;
                }
                
                // The player can view the opponent's trash's size.
                else if (opponent_trash_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_trash();
                    rerender = true;
                }
                
                // The player can view the opponent's life cards' size.
                else if (opponent_life_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_life_cards_size();
                    rerender = true;
                }
                
                // The player can view their active fighter.
                else if (your_active_button.get_rectangle().unclick()) {
                    players[PLAYER].view_active();
                    rerender = true;
                }
                
                // The player can view their benched fighters.
                else if (your_bench_button.get_rectangle().unclick()) {
                    players[PLAYER].view_bench();
                    rerender = true;
                }
                
                // The player can view their opponent's active fighter.
                else if (opponent_active_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_active();
                    rerender = true;
                }
                
                // The player can view their opponent's benched fighters.
                else if (opponent_bench_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_bench();
                    rerender = true;
                }
                
                // The player can view their effects.
                else if (your_effects_button.get_rectangle().unclick()) {
                    players[PLAYER].view_effects();
                    rerender = true;
                }
                
                // The player can view their opponent's effects.
                else if (opponent_effects_button.get_rectangle().unclick()) {
                    players[OPPONENT].view_effects();
                    rerender = true;
                }
                //}
                
                // The opponent's actions.
                //{
                // The opponent ended their turn.
                if (message == END_TURN_STRING) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                    
                    end = true;
                    break;
                }
                
                // The opponent conceded.
                else if (message == CONCEDE_STRING) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                    
                    // The player is informed that the opponent conceded.
                    display.fill();
                    display.blit(
                        renderer.lined_render(
                            OPPONENT_CONCEDE_STRING,
                            OPPONENT_CONCEDE_WIDTH * display.width(),
                            OPPONENT_CONCEDE_HEIGHT * display.height(),
                            OPPONENT_CONCEDE_SEPARATION_X * display.width(),
                            OPPONENT_CONCEDE_MAX_WIDTH * display.width(),
                            OPPONENT_CONCEDE_SEPARATION_Y * display.height(),
                            OPPONENT_CONCEDE_JUSTIFICATION
                        ),
                        OPPONENT_CONCEDE_X,
                        OPPONENT_CONCEDE_Y
                    );
                    next_button.blit_to(display);
                    display.update();
                    
                    // The player proceeds at their own discretion.
                    // The opponent quitting forces a procession.
                    while (
                        !Events::unpress(SUBMIT_KEY)
                        && !next_button.get_rectangle().unclick()
                        && message != TERMINATOR_STRING
                    ) {
                        Events::update();
                    }
                    
                    winner = PLAYER;
                    end = true;
                    break;
                }
                
                // The opponent played a card.
                else if (message == PLAY_MESSAGE) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                    
                    // The message is waited for.
                    while (message == EMPTY_MESSAGE) {
                        Events::update();
                    }
                    
                    // The index of the card is taken.
                    int index = std::stoi(message);
                    
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                
                    players[turn].play(index);
                    
                    rerender = true;
                }
                
                // The opponent used an ability.
                else if (message == ABILITY_MESSAGE) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                    
                    // The ability is used.
                    players[turn].use_ability();
                    
                    rerender = true;
                }
                
                // The opponent retreated their active fighter.
                else if (message == RETREAT_MESSAGE) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                    
                    // The message is waited for.
                    while (message == EMPTY_MESSAGE) {
                        Events::update();
                    }
                    
                    // The index of the fighter to switch is extracted.
                    int index = std::stoi(message);
                    
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                
                    players[turn].retreat(index);
                    
                    rerender = true;
                }
                
                // The opponent attacked with their active fighter.
                else if (message == ATTACK_MESSAGE) {
                    // The message from the opponent is awaited.
                    message = EMPTY_MESSAGE;
                    messenger_thread.new_thread(
                        MessengerPackage::get_message,
                        &messenger_package
                    );
                    
                    players[turn].attack();
                    
                    rerender = true;
                }
                
                // A message was sent and was not dealt with.
                // This can cause a player desync, so the error is logged.
                else if (message != EMPTY_MESSAGE) {
                    std::cerr
                        << "\nUnhandled message:\n"
                        << message
                        << std::endl
                    ;
                }
                //}
                
                // The events are updated.
                Events::update();
            }
        
            // A concede doesn't require a check.
            if (winner == NO_END) {
                // The players are checked for any defeated fighters.
                winner = defeat_check(
                    display,
                    renderer,
                    messenger,
                    messenger_package,
                    messenger_thread,
                    back_button,
                    next_button,
                    players,
                    the_void,
                    generator,
                    turn
                );
            }
        }
        
        // End of turn effects.
        if (winner < 0) {
            // The players perform their end of turn effects.
            players[turn].reset();
            players[!turn].reset();
            
            // The other player takes their turn.
            turn = !turn;
            
            // The number of turns taken is incremented.
            ++turn_count;
        }
        
        
    }
    
    // Post game.
    //{
    // The play is notified if they won or lost.
    display.fill();
    display.blit(
        renderer.render(
            GAME_STRING,
            GAME_WIDTH * display.width(),
            GAME_HEIGHT * display.height(),
            GAME_SEPARATION * display.width()
        ),
        GAME_X,
        GAME_Y
    );
    next_button.blit_to(display);
    display.update();
    
    // The player may advance at their discretion.
    // The opponent quitting forces a procession.
    while (
        !Events::unpress(SUBMIT_KEY)
        && !next_button.get_rectangle().unclick()
        && message != TERMINATOR_STRING
    ) {
        Events::update();
    }
    
    // The song is paused to terminate the thread.
    duel_song.pause();
    //}
}
//}

// Deck Building Menus
//{
/**
 * Tells the user that the player that they connected
 *   with has an incompatible version of the program.
 */
void incompatible(Display& display, const Renderer& renderer) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The incomptability sprite is initialised.
    Sprite incompatible_sprite(
        renderer.lined_render(
            INCOMPATIBLE_STRING,
            INCOMPATIBLE_WIDTH * display_width,
            INCOMPATIBLE_HEIGHT * display_height,
            INCOMPATIBLE_SEPARATION_X * display_width,
            INCOMPATIBLE_MAX_WIDTH * display_width,
            INCOMPATIBLE_SEPARATION_Y * display_height,
            INCOMPATIBLE_JUSTIFICATION
        )
    );
    
    // The back button is intialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The display is blitted to.
    display_sprite.fill();
    display_sprite.blit(incompatible_sprite, INCOMPATIBLE_X, INCOMPATIBLE_Y);
    back_button.blit_to(display_sprite);
    display.update();
    
    // Loop for user input.
    while (
        !Events::unpress(QUIT_KEY)
        && !back_button.get_rectangle().unclick()
    ) {
        Events::update();
    }
}   

/**
 * Adds fighter cards to the player's deck.
 */
void add_fighter(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    std::array<int, CARD_COUNT>& card_counts,
    int& card_count,
    const std::string& message
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The deck builder sprite is intialised.
    Sprite builder_sprite(
        renderer.render(
            BUILDER_STRING,
            BUILDER_WIDTH * display_width,
            BUILDER_HEIGHT * display_height,
            BUILDER_SEPARATION * display_width
        )
    );
    
    // The back button is initialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The left button is initialised.
    Button left_button(
        Sprite(
            LEFT_SOURCE,
            LEFT_WIDTH * display_width,
            LEFT_HEIGHT * display_height
        ),
        display_sprite,
        LEFT_X,
        LEFT_Y
    );
    
    // The right button is initialised.
    Button right_button(
        Sprite(
            RIGHT_SOURCE,
            RIGHT_WIDTH * display_width,
            RIGHT_HEIGHT * display_height
        ),
        display_sprite,
        RIGHT_X,
        RIGHT_Y
    );
    
    // The minus buttons are intialised.
    std::vector<Button> minus_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        minus_buttons.push_back(
            Button(
                Sprite(
                    MINUS_SOURCE,
                    MINUS_WIDTH * display_width,
                    MINUS_HEIGHT * display_height
                ),
                display_sprite,
                MINUS_X,
                MINUS_Y + i * MINUS_Y_SHIFT
            )
        );
    }
    
    // The plus buttons are initialised.
    std::vector<Button> plus_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        plus_buttons.push_back(
            Button(
                Sprite(
                    PLUS_SOURCE,
                    PLUS_WIDTH * display_width,
                    PLUS_HEIGHT * display_height
                ),
                display_sprite,
                PLUS_X,
                PLUS_Y + i * PLUS_Y_SHIFT
            )
        );
    }
    
    // Determines which cards are displayed.
    int page = 0;
    
    // True if the function should return.
    bool end = false;
    
    while (!end) {
        // The sprites are blitted to the display.
        display_sprite.fill();
        display_sprite.blit(builder_sprite, BUILDER_X, BUILDER_Y);
        back_button.blit_to(display_sprite);
        
        if (page > 0) {
            left_button.blit_to(display_sprite);
        }
        
        if (page < (FIGHTER_COUNT - 1) / PAGE_COUNT) {
            right_button.blit_to(display_sprite);
        }
        
        // The deck's capacity info is displayed.
        display_sprite.blit(
            renderer.render(
                CAPACITY_STRING,
                CAPACITY_WIDTH * display_width,
                CAPACITY_HEIGHT * display_height,
                CAPACITY_SEPARATION * display_width
            ),
            CAPACITY_X,
            CAPACITY_Y
        );
        
        // A vector of buttons for the names is generated.
        std::vector<Button> name_buttons;
        
        // The cards' names on the page are displayed.
        for (
            int i = 0;
            i < PAGE_COUNT
            && page * PAGE_COUNT + i < FIGHTER_COUNT;
            ++i
        ) {
            // The name button is stored in the vector.
            name_buttons.push_back(
                Button(
                    Sprite(
                        renderer.render(
                            ALL_FIGHTERS[page * PAGE_COUNT + i]->get_name(),
                            PAGE_WIDTH * display_width,
                            PAGE_HEIGHT * display_height,
                            PAGE_SEPARATION * display_width
                        )
                    ),
                    display_sprite,
                    PAGE_NAME_X,
                    PAGE_Y + i * PAGE_Y_SHIFT
                )
            );
            
            // The name is displayed.
            name_buttons[i].blit_to(display_sprite);
            
            // The card count is displayed.
            display_sprite.blit(
                renderer.render(
                    std::to_string(card_counts[page * PAGE_COUNT + i])
                    + '/'
                    + std::to_string(MAX_FIGHTER_COPIES),
                    PAGE_WIDTH * display_width,
                    PAGE_HEIGHT * display_height,
                    PAGE_SEPARATION * display_width
                ),
                PAGE_VALUE_X,
                PAGE_Y + i * PAGE_Y_SHIFT
            );
            
            if (card_counts[page * PAGE_COUNT + i]) {
                minus_buttons[i].blit_to(display_sprite);
            }
            
            if (
                card_counts[page * PAGE_COUNT + i] < MAX_FIGHTER_COPIES
                && card_count < DECK_SIZE
            ) {
                plus_buttons[i].blit_to(display_sprite);
            }
        }
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // The user can return to the deck building menu
            //   with the use of the back button.
            // The opponent disconnecting also has this effect.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
                || message == TERMINATOR_STRING
            ) {
                end = true;
                break;
            }
            
            // The page number is decremented (if possible).
            else if (
                (
                    Events::unpress(Events::LEFT)
                    || left_button.get_rectangle().unclick()
                ) && page > 0
            ) {
                --page;
                break;
            }
            
            // The page number is incremented (if possible).
            else if (
                (
                    Events::unpress(Events::RIGHT)
                    || right_button.get_rectangle().unclick()
                ) && page < (FIGHTER_COUNT - 1) / PAGE_COUNT
            ) {
                ++page;
                break;
            }
            
            // The other buttons are checked.
            else {
                // True if the button being clicked was found.
                bool found = false;
                
                // The plus and minus buttons increment or decrement
                //   the number of copies of a card in the deck.
                // The names display the card's details.
                for (
                    int i = 0;
                    i < PAGE_COUNT && page * PAGE_COUNT + i < FIGHTER_COUNT;
                    ++i
                ) {
                    // Removes a card.
                    if (
                        card_counts[page * PAGE_COUNT + i]
                        && minus_buttons[i].get_rectangle().unclick()
                    ) {
                        --card_counts[page * PAGE_COUNT + i];
                        --card_count;
                        found = true;
                        break;
                    }
                    
                    // Adds a card.
                    else if (
                        card_counts[page * PAGE_COUNT + i] < MAX_FIGHTER_COPIES
                        && card_count < DECK_SIZE
                        && plus_buttons[i].get_rectangle().unclick()
                    ) {
                        ++card_counts[page * PAGE_COUNT + i];
                        ++card_count;
                        found = true;
                        break;
                    }
                    
                    // Diplays a card's details.
                    else if (name_buttons[i].get_rectangle().unclick()) {
                        ALL_FIGHTERS[page * PAGE_COUNT + i]->render(display, renderer);
                        back_button.blit_to(display_sprite);
                        display.update();
                        
                        while (
                            !Events::unpress(QUIT_KEY)
                            && !back_button.get_rectangle().unclick()
                        ) {
                            Events::update();
                        }
                        
                        found = true;
                        break;
                    }
                }
                
                if (found) {
                    break;
                }
            }
            
            // The events are updated.
            Events::update();
        }
    }
}

/**
 * Adds supporter cards to the player's deck.
 */
void add_supporter(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    std::array<int, CARD_COUNT>& card_counts,
    int& card_count,
    const std::string& message
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The deck builder sprite is intialised.
    Sprite builder_sprite(
        renderer.render(
            BUILDER_STRING,
            BUILDER_WIDTH * display_width,
            BUILDER_HEIGHT * display_height,
            BUILDER_SEPARATION * display_width
        )
    );
    
    // The back button is initialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The left button is initialised.
    Button left_button(
        Sprite(
            LEFT_SOURCE,
            LEFT_WIDTH * display_width,
            LEFT_HEIGHT * display_height
        ),
        display_sprite,
        LEFT_X,
        LEFT_Y
    );
    
    // The right button is initialised.
    Button right_button(
        Sprite(
            RIGHT_SOURCE,
            RIGHT_WIDTH * display_width,
            RIGHT_HEIGHT * display_height
        ),
        display_sprite,
        RIGHT_X,
        RIGHT_Y
    );
    
    // The minus buttons are intialised.
    std::vector<Button> minus_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        minus_buttons.push_back(
            Button(
                Sprite(
                    MINUS_SOURCE,
                    MINUS_WIDTH * display_width,
                    MINUS_HEIGHT * display_height
                ),
                display_sprite,
                MINUS_X,
                MINUS_Y + i * MINUS_Y_SHIFT
            )
        );
    }
    
    
    // The plus buttons are initialised.
    std::vector<Button> plus_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        plus_buttons.push_back(
            Button(
                Sprite(
                    PLUS_SOURCE,
                    PLUS_WIDTH * display_width,
                    PLUS_HEIGHT * display_height
                ),
                display_sprite,
                PLUS_X,
                PLUS_Y + i * PLUS_Y_SHIFT
            )
        );
    }
    
    // Determines which cards are displayed.
    int page = 0;
    
    // True if the function should return.
    bool end = false;
    
    while (!end) {
        // The sprites are blitted to the display.
        display_sprite.fill();
        display_sprite.blit(builder_sprite, BUILDER_X, BUILDER_Y);
        back_button.blit_to(display_sprite);
        
        if (page > 0) {
            left_button.blit_to(display_sprite);
        }
        
        if (page < (SUPPORTER_COUNT - 1) / PAGE_COUNT) {
            right_button.blit_to(display_sprite);
        }
        
        // The deck's capacity info is displayed.
        display_sprite.blit(
            renderer.render(
                CAPACITY_STRING,
                CAPACITY_WIDTH * display_width,
                CAPACITY_HEIGHT * display_height,
                CAPACITY_SEPARATION * display_width
            ),
            CAPACITY_X,
            CAPACITY_Y
        );
        
        // A vector of buttons for the names is generated.
        std::vector<Button> name_buttons;
        
        // The cards' names on the page are displayed.
        for (
            int i = 0;
            i < PAGE_COUNT
            && page * PAGE_COUNT + i < SUPPORTER_COUNT;
            ++i
        ) {
            // The name button is stored in the vector.
            name_buttons.push_back(
                Button(
                    Sprite(
                        renderer.render(
                            ALL_SUPPORTERS[page * PAGE_COUNT + i]->get_name(),
                            PAGE_WIDTH * display_width,
                            PAGE_HEIGHT * display_height,
                            PAGE_SEPARATION * display_width
                        )
                    ),
                    display_sprite,
                    PAGE_NAME_X,
                    PAGE_Y + i * PAGE_Y_SHIFT
                )
            );
            
            // The name is displayed.
            name_buttons[i].blit_to(display_sprite);
            
            // The card count is displayed.
            display_sprite.blit(
                renderer.render(
                    std::to_string(card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i])
                    + '/'
                    + std::to_string(MAX_SUPPORTER_COPIES),
                    PAGE_WIDTH * display_width,
                    PAGE_HEIGHT * display_height,
                    PAGE_SEPARATION * display_width
                ),
                PAGE_VALUE_X,
                PAGE_Y + i * PAGE_Y_SHIFT
            );
            
            if (card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i]) {
                minus_buttons[i].blit_to(display_sprite);
            }
            
            if (
                card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i] < MAX_SUPPORTER_COPIES
                && card_count < DECK_SIZE
            ) {
                plus_buttons[i].blit_to(display_sprite);
            }
        }
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // The user can return to the deck building menu
            //   with the use of the back button.
            // The opponent disconnecting also has this effect.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
                || message == TERMINATOR_STRING
            ) {
                end = true;
                break;
            }
            
            // The page number is decremented (if possible).
            else if (
                (
                    Events::unpress(Events::LEFT)
                    || left_button.get_rectangle().unclick()
                ) && page > 0
            ) {
                --page;
                break;
            }
            
            // The page number is incremented (if possible).
            else if (
                (
                    Events::unpress(Events::RIGHT)
                    || right_button.get_rectangle().unclick()
                ) && page < (SUPPORTER_COUNT - 1) / PAGE_COUNT
            ) {
                ++page;
                break;
            }
            
            // The other buttons are checked.
            else {
                // True if the button being clicked was found.
                bool found = false;
                
                // The plus and minus buttons increment or decrement
                //   the number of copies of a card in the deck.
                // The names display the card's details.
                for (
                    int i = 0;
                    i < PAGE_COUNT && page * PAGE_COUNT + i < SUPPORTER_COUNT;
                    ++i
                ) {
                    // Removes a card.
                    if (
                        card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i]
                        && minus_buttons[i].get_rectangle().unclick()
                    ) {
                        --card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i];
                        --card_count;
                        found = true;
                        break;
                    }
                    
                    // Adds a card.
                    else if (
                        card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i]
                        < MAX_SUPPORTER_COPIES
                        && card_count < DECK_SIZE
                        && plus_buttons[i].get_rectangle().unclick()
                    ) {
                        ++card_counts[FIGHTER_COUNT + page * PAGE_COUNT + i];
                        ++card_count;
                        found = true;
                        break;
                    }
                    
                    // Diplays a card's details.
                    else if (name_buttons[i].get_rectangle().unclick()) {
                        ALL_SUPPORTERS[page * PAGE_COUNT + i]->render(display, renderer);
                        back_button.blit_to(display_sprite);
                        display.update();
                        
                        while (
                            !Events::unpress(QUIT_KEY)
                            && !back_button.get_rectangle().unclick()
                        ) {
                            Events::update();
                        }
                        
                        found = true;
                        break;
                    }
                }
                
                if (found) {
                    break;
                }
            }
            
            // The events are updated.
            Events::update();
        }
    }
}

/**
 * Adds energy cards to the player's deck.
 */
void add_energy(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    std::array<int, CARD_COUNT>& card_counts,
    int& card_count,
    const std::string& message
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The deck builder sprite is intialised.
    Sprite builder_sprite(
        renderer.render(
            BUILDER_STRING,
            BUILDER_WIDTH * display_width,
            BUILDER_HEIGHT * display_height,
            BUILDER_SEPARATION * display_width
        )
    );
    
    // The back button is initialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The left button is initialised.
    Button left_button(
        Sprite(
            LEFT_SOURCE,
            LEFT_WIDTH * display_width,
            LEFT_HEIGHT * display_height
        ),
        display_sprite,
        LEFT_X,
        LEFT_Y
    );
    
    // The right button is initialised.
    Button right_button(
        Sprite(
            RIGHT_SOURCE,
            RIGHT_WIDTH * display_width,
            RIGHT_HEIGHT * display_height
        ),
        display_sprite,
        RIGHT_X,
        RIGHT_Y
    );
    
    // The minus buttons are intialised.
    std::vector<Button> minus_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        minus_buttons.push_back(
            Button(
                Sprite(
                    MINUS_SOURCE,
                    MINUS_WIDTH * display_width,
                    MINUS_HEIGHT * display_height
                ),
                display_sprite,
                MINUS_X,
                MINUS_Y + i * MINUS_Y_SHIFT
            )
        );
    }
    
    
    // The plus buttons are initialised.
    std::vector<Button> plus_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        plus_buttons.push_back(
            Button(
                Sprite(
                    PLUS_SOURCE,
                    PLUS_WIDTH * display_width,
                    PLUS_HEIGHT * display_height
                ),
                display_sprite,
                PLUS_X,
                PLUS_Y + i * PLUS_Y_SHIFT
            )
        );
    }
    
    // Determines which cards are displayed.
    int page = 0;
    
    // True if the function should return.
    bool end = false;
    
    while (!end) {
        // The sprites are blitted to the display.
        display_sprite.fill();
        display_sprite.blit(builder_sprite, BUILDER_X, BUILDER_Y);
        back_button.blit_to(display_sprite);
        
        if (page > 0) {
            left_button.blit_to(display_sprite);
        }
        
        if (page < (ENERGY_COUNT - 1) / PAGE_COUNT) {
            right_button.blit_to(display_sprite);
        }
        
        // The deck's capacity info is displayed.
        display_sprite.blit(
            renderer.render(
                CAPACITY_STRING,
                CAPACITY_WIDTH * display_width,
                CAPACITY_HEIGHT * display_height,
                CAPACITY_SEPARATION * display_width
            ),
            CAPACITY_X,
            CAPACITY_Y
        );
        
        // A vector of buttons for the names is generated.
        std::vector<Button> name_buttons;
        
        // The cards' names on the page are displayed.
        for (
            int i = 0;
            i < PAGE_COUNT
            && page * PAGE_COUNT + i < ENERGY_COUNT;
            ++i
        ) {
            // The name button is stored in the vector.
            name_buttons.push_back(
                Button(
                    Sprite(
                        renderer.render(
                            ALL_ENERGY[page * PAGE_COUNT + i]->get_name(),
                            PAGE_WIDTH * display_width,
                            PAGE_HEIGHT * display_height,
                            PAGE_SEPARATION * display_width
                        )
                    ),
                    display_sprite,
                    PAGE_NAME_X,
                    PAGE_Y + i * PAGE_Y_SHIFT
                )
            );
            
            // The name is displayed.
            name_buttons[i].blit_to(display_sprite);
            
            // The card count is displayed.
            display_sprite.blit(
                renderer.render(
                    std::to_string(card_counts[
                        FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i
                    ])
                    + '/'
                    + std::to_string(MAX_ENERGY_COPIES),
                    PAGE_WIDTH * display_width,
                    PAGE_HEIGHT * display_height,
                    PAGE_SEPARATION * display_width
                ),
                PAGE_VALUE_X,
                PAGE_Y + i * PAGE_Y_SHIFT
            );
            
            if (card_counts[FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i]) {
                minus_buttons[i].blit_to(display_sprite);
            }
            
            if (
                card_counts[FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i]
                < MAX_ENERGY_COPIES
                && card_count < DECK_SIZE
            ) {
                plus_buttons[i].blit_to(display_sprite);
            }
        }
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // The user can return to the deck building menu
            //   with the use of the back button.
            // The opponent disconnecting also has this effect.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
                || message == TERMINATOR_STRING
            ) {
                end = true;
                break;
            }
            
            // The page number is decremented (if possible).
            else if (
                (
                    Events::unpress(Events::LEFT)
                    || left_button.get_rectangle().unclick()
                ) && page > 0
            ) {
                --page;
                break;
            }
            
            // The page number is incremented (if possible).
            else if (
                (
                    Events::unpress(Events::RIGHT)
                    || right_button.get_rectangle().unclick()
                ) && page < (ENERGY_COUNT - 1) / PAGE_COUNT
            ) {
                ++page;
                break;
            }
            
            // The other buttons are checked.
            else {
                // True if the button being clicked was found.
                bool found = false;
                
                // The plus and minus buttons increment or decrement
                //   the number of copies of a card in the deck.
                // The names display the card's details.
                for (
                    int i = 0;
                    i < PAGE_COUNT && page * PAGE_COUNT + i < ENERGY_COUNT;
                    ++i
                ) {
                    // Removes a card.
                    if (
                        card_counts[FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i]
                        && minus_buttons[i].get_rectangle().unclick()
                    ) {
                        --card_counts[
                            FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i
                        ];
                        --card_count;
                        found = true;
                        break;
                    }
                    
                    // Adds a card.
                    else if (
                        card_counts[FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i]
                        < MAX_ENERGY_COPIES
                        && card_count < DECK_SIZE
                        && plus_buttons[i].get_rectangle().unclick()
                    ) {
                        ++card_counts[
                            FIGHTER_COUNT + SUPPORTER_COUNT + page * PAGE_COUNT + i
                        ];
                        ++card_count;
                        found = true;
                        break;
                    }
                    
                    // Diplays a card's details.
                    else if (name_buttons[i].get_rectangle().unclick()) {
                        ALL_ENERGY[page * PAGE_COUNT + i]->render(display, renderer);
                        back_button.blit_to(display_sprite);
                        display.update();
                        
                        while (
                            !Events::unpress(QUIT_KEY)
                            && !back_button.get_rectangle().unclick()
                        ) {
                            Events::update();
                        }
                        
                        found = true;
                        break;
                    }
                }
                
                if (found) {
                    break;
                }
            }
            
            // The events are updated.
            Events::update();
        }
    }
}

/**
 * Generates a premade deck.
 */
void generate(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger,
    std::array<int, CARD_COUNT>& card_counts,
    int& card_count,
    const std::string& message
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The deck builder sprite is intialised.
    Sprite builder_sprite(
        renderer.render(
            BUILDER_STRING,
            BUILDER_WIDTH * display_width,
            BUILDER_HEIGHT * display_height,
            BUILDER_SEPARATION * display_width
        )
    );
    
    // The back button is initialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The left button is initialised.
    Button left_button(
        Sprite(
            LEFT_SOURCE,
            LEFT_WIDTH * display_width,
            LEFT_HEIGHT * display_height
        ),
        display_sprite,
        LEFT_X,
        LEFT_Y
    );
    
    // The right button is initialised.
    Button right_button(
        Sprite(
            RIGHT_SOURCE,
            RIGHT_WIDTH * display_width,
            RIGHT_HEIGHT * display_height
        ),
        display_sprite,
        RIGHT_X,
        RIGHT_Y
    );
    
    // The generate buttons are intialised.
    std::vector<Button> generate_buttons;
    
    for (int i = 0; i < PAGE_COUNT; ++i) {
        generate_buttons.push_back(
            Button(
                renderer.render(
                    GENERATE_STRING,
                    GENERATE_WIDTH * display_width,
                    GENERATE_HEIGHT * display_height,
                    GENERATE_SEPARATION * display_width
                ),
                display_sprite,
                GENERATE_X,
                GENERATE_Y + i * GENERATE_Y_SHIFT
            )
        );
    }
    
    // Determines which decks are displayed.
    int page = 0;
    
    // True if the function should return.
    bool end = false;
    
    while (!end) {
        // The sprites are blitted to the display.
        display_sprite.fill();
        display_sprite.blit(builder_sprite, BUILDER_X, BUILDER_Y);
        back_button.blit_to(display_sprite);
        
        if (page > 0) {
            left_button.blit_to(display_sprite);
        }
        
        if (page < (DECK_CODE_COUNT - 1) / PAGE_COUNT) {
            right_button.blit_to(display_sprite);
        }
        
        // The deck's capacity info is displayed.
        display_sprite.blit(
            renderer.render(
                CAPACITY_STRING,
                CAPACITY_WIDTH * display_width,
                CAPACITY_HEIGHT * display_height,
                CAPACITY_SEPARATION * display_width
            ),
            CAPACITY_X,
            CAPACITY_Y
        );
        
        // A vector of buttons for the names is generated.
        std::vector<Button> name_buttons;
        
        // The decks' names on the page are displayed.
        for (
            int i = 0;
            i < PAGE_COUNT
            && page * PAGE_COUNT + i < DECK_CODE_COUNT;
            ++i
        ) {
            // The name button is stored in the vector.
            name_buttons.push_back(
                Button(
                    Sprite(
                        renderer.render(
                            ALL_DECK_CODES[page * PAGE_COUNT + i]->get_name(),
                            PAGE_WIDTH * display_width,
                            PAGE_HEIGHT * display_height,
                            PAGE_SEPARATION * display_width
                        )
                    ),
                    display_sprite,
                    PAGE_NAME_X,
                    PAGE_Y + i * PAGE_Y_SHIFT
                )
            );
            
            // The name is displayed.
            name_buttons[i].blit_to(display_sprite);
            
            // The generate buttons are diplayed.
            generate_buttons[i].blit_to(display_sprite);
        }
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // The user can return to the deck building menu
            //   with the use of the back button.
            // The opponent disconnecting also has this effect.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
                || message == TERMINATOR_STRING
            ) {
                end = true;
                break;
            }
            
            // The page number is decremented (if possible).
            else if (
                (
                    Events::unpress(Events::LEFT)
                    || left_button.get_rectangle().unclick()
                ) && page > 0
            ) {
                --page;
                break;
            }
            
            // The page number is incremented (if possible).
            else if (
                (
                    Events::unpress(Events::RIGHT)
                    || right_button.get_rectangle().unclick()
                ) && page < (DECK_CODE_COUNT - 1) / PAGE_COUNT
            ) {
                ++page;
                break;
            }
            
            // The other buttons are checked.
            else {
                // True if the button being clicked was found.
                bool found = false;
                
                // The plus and minus buttons increment or decrement
                //   the number of copies of a card in the deck.
                // The names display the card's details.
                for (
                    int i = 0;
                    i < PAGE_COUNT && page * PAGE_COUNT + i < DECK_CODE_COUNT;
                    ++i
                ) {
                    // Generates the chosen deck.
                    if (generate_buttons[i].get_rectangle().unclick()) {
                        int index = page * PAGE_COUNT + i;
                        
                        // The random deck was chosen.
                        if (index == DECK_CODE_COUNT - 1) {
                            // RNG is initialised using the current time.
                            std::mt19937 generator(
                                Timer::current()
                            );
                            
                            // A random index of a valid deck is assigned.
                            index = Random::get_int(generator, 1, DECK_CODE_COUNT - 2);
                        }
                        
                        card_counts = ALL_DECK_CODES[index]->get_code();
                        card_count = ALL_DECK_CODES[index]->get_size();
                        found = true;
                        break;
                    }
                    
                    // Displays a deck's details.
                    else if (name_buttons[i].get_rectangle().unclick()) {
                        display_sprite.fill();
                        display_sprite.blit(
                            renderer.lined_render(
                                DESCRIPTION_STRING,
                                DESCRIPTION_WIDTH * display_width,
                                DESCRIPTION_HEIGHT * display_height,
                                DESCRIPTION_SEPARATION_X * display_width,
                                DESCRIPTION_MAX_WIDTH * display_width,
                                DESCRIPTION_SEPARATION_Y * display_height,
                                DESCRIPTION_JUSTIFICATION
                            ),
                            DESCRIPTION_X,
                            DESCRIPTION_Y
                        );
                        back_button.blit_to(display_sprite);
                        display.update();
                        
                        // Pressing or clicking back stops displaying the deck's details.
                        while (
                            !Events::unpress(QUIT_KEY)
                            && !back_button.get_rectangle().unclick()
                        ) {
                            Events::update();
                        }
                        
                        found = true;
                        break;
                    }
                }
                
                if (found) {
                    break;
                }
            }
            
            // The events are updated.
            Events::update();
        }
    }
}

/**
 * Returns true if the deck has a fighter that
 *   does not rank up from another fighter.
 */
bool has_basic(const std::array<int, CARD_COUNT>& card_counts) noexcept {
    for (int i = 0; i < FIGHTER_COUNT; i++) {
        if (card_counts[i]) {
            if (ALL_FIGHTERS[i]->basic()) {
                return true;
            }
        }
    }
    
    return false;
}

/**
 * Returns true if the deck is valid.
 * Gives the reason for deck invalidity if false is to be returned.
 */
bool valid_deck(
    Display& display,
    const Renderer& renderer,
    const std::array<int, CARD_COUNT>& card_counts,
    const int& card_count
) noexcept {
    std::string error_string;
    
    if (card_count == DECK_SIZE) {
        if (has_basic(card_counts)) {
            return true;
        }
        
        else {
            error_string = NO_BASICS_STRING;
        }
    }
    
    else {
        error_string = INVALID_SIZE_STRING;
    }
    
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The error sprite is initialised.
    Sprite deck_error_sprite(
        renderer.lined_render(
            error_string,
            DECK_ERROR_WIDTH * display_width,
            DECK_ERROR_HEIGHT * display_height,
            DECK_ERROR_SEPARATION_X * display_width,
            DECK_ERROR_MAX_WIDTH * display_width,
            DECK_ERROR_SEPARATION_Y * display_height,
            DECK_ERROR_JUSTIFICATION
        )
    );
    
    // The back button is initialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The display is blitted to.
    display_sprite.fill();
    display_sprite.blit(deck_error_sprite, DECK_ERROR_X, DECK_ERROR_Y);
    back_button.blit_to(display_sprite);
    display.update();
    
    // The error message is displayed until the user goes back.
    while (
        !Events::unpress(QUIT_KEY)
        && !back_button.get_rectangle().unclick()
    ) {
        Events::update();
    }
    
    return false;
}

/**
 * Builds each player's deck and sends them to the opponent.
 * Also sends the RNG from the server to the
 *   client and seeds both player's RNG.
 */
void build_deck(
    Display& display,
    const Renderer& renderer,
    const Messenger& messenger
) noexcept {
    std::string connection_test = System::version(VERSION);
    
    // Sends a message to the other player to confirm the connection.
    // The message sent is the program version in string form.
    messenger.send(connection_test);
    
    // If the received string does not match, the connection was unsuccessful.
    // This ensures that other TCP program do not connect with this one.
    // This also ensures that the versions of the program match.
    // This also allows for connection bridging to be performed safely,
    //   as the game will not start until both players connect.
    if (messenger.read() != connection_test) {
        incompatible(display, renderer);
        messenger.send(TERMINATOR_STRING);
        return;
    }
    
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The deck builder sprite is intialised.
    Sprite builder_sprite(
        renderer.render(
            BUILDER_STRING,
            BUILDER_WIDTH * display_width,
            BUILDER_HEIGHT * display_height,
            BUILDER_SEPARATION * display_width
        )
    );
    
    // The fighter button is intialised.
    Button fighter_button(
        Sprite(
            renderer.render(
                FIGHTER_STRING,
                FIGHTER_WIDTH * display_width,
                FIGHTER_HEIGHT * display_height,
                FIGHTER_SEPARATION * display_width
            )
        ),
        display_sprite,
        FIGHTER_X,
        FIGHTER_Y
    );
    
    // The supporter button is intitialised.
    Button supporter_button(
        Sprite(
            renderer.render(
                SUPPORTER_STRING,
                SUPPORTER_WIDTH * display_width,
                SUPPORTER_HEIGHT * display_height,
                SUPPORTER_SEPARATION * display_width
            )
        ),
        display_sprite,
        SUPPORTER_X,
        SUPPORTER_Y
    );
    
    // The energy button is intialised.
    Button energy_button(
        Sprite(
            renderer.render(
                ENERGY_STRING,
                ENERGY_WIDTH * display_width,
                ENERGY_HEIGHT * display_height,
                ENERGY_SEPARATION * display_width
            )
        ),
        display_sprite,
        ENERGY_X,
        ENERGY_Y
    );
    
    // The generator button is initialised.
    Button generator_button(
        Sprite(
            renderer.render(
                GENERATOR_STRING,
                GENERATOR_WIDTH * display_width,
                GENERATOR_HEIGHT * display_height,
                GENERATOR_SEPARATION * display_width
            )
        ),
        display_sprite,
        GENERATOR_X,
        GENERATOR_Y
    );
    
    // The done button is initialised.
    Button done_button(
        Sprite(
            renderer.render(
                DONE_STRING,
                DONE_WIDTH * display_width,
                DONE_HEIGHT * display_height,
                DONE_SEPARATION * display_width
            )
        ),
        display_sprite,
        DONE_X,
        DONE_Y
    );
    
    // The quit button is initialised.
    Button quit_button(
        Sprite(
            renderer.render(
                QUIT_STRING,
                QUIT_WIDTH * display_width,
                QUIT_HEIGHT * display_height,
                QUIT_SEPARATION * display_width
            )
        ),
        display_sprite,
        QUIT_X_ALT,
        QUIT_Y
    );
    
    // The deck building song is loaded and queued in another thread.
    Audio build_song(BUILD_SONG_SOURCE, BUILD_SONG_LENGTH);
    Thread song_thread(Audio::thread_queue, &build_song);
    
    // The opponent's message is read and stored in another thread.
    std::string message(EMPTY_MESSAGE);
    MessengerPackage package(messenger, message);
    Thread message_thread(MessengerPackage::get_message, &package);
    
    // The number of cards currently in the player's deck.
    int card_count = 0;
    
    // The number of cards that should be included in the players deck.
    std::array<int, CARD_COUNT> card_counts{};
    
    // True if the function should return.
    bool end = false;
    
    // Loop to display the deck building main menu.
    while (!end) {
        // The display is blitted to.
        display_sprite.fill();
        display_sprite.blit(builder_sprite, BUILDER_X, BUILDER_Y);
        fighter_button.blit_to(display_sprite);
        supporter_button.blit_to(display_sprite);
        energy_button.blit_to(display_sprite);
        generator_button.blit_to(display_sprite);
        done_button.blit_to(display_sprite);
        quit_button.blit_to(display_sprite);
        
        // The deck's capacity info is displayed.
        display_sprite.blit(
            renderer.render(
                CAPACITY_STRING,
                CAPACITY_WIDTH * display_width,
                CAPACITY_HEIGHT * display_height,
                CAPACITY_SEPARATION * display_width
            ),
            CAPACITY_X,
            CAPACITY_Y
        );
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // If the quit button was pressed or
            //   clicked, or the opponent disconnected,
            //   the port menu is returned to.
            if (
                quit_button.get_rectangle().unclick()
                || message == TERMINATOR_STRING
            ) {
                end = true;
                break;
            }
            
            // Else, if the fighter button was clicked,
            //   the fighter addition menu is opened.
            else if (fighter_button.get_rectangle().unclick()) {
                add_fighter(
                    display,
                    renderer,
                    messenger,
                    card_counts,
                    card_count,
                    message
                );
                
                break;
            }
            
            // Else, if the supporter button was clicked,
            //   the supporter addition menu is opened.
            else if (supporter_button.get_rectangle().unclick()) {
                add_supporter(
                    display,
                    renderer,
                    messenger,
                    card_counts,
                    card_count,
                    message
                );
                
                break;
            }
            
            // Else, if the energy button was clicked,
            //   the energy addition menu is opened.
            else if (energy_button.get_rectangle().unclick()) {
                add_energy(
                    display,
                    renderer,
                    messenger,
                    card_counts,
                    card_count,
                    message
                );
                
                break;
            }
            
            // Else, if the deck generator button was clicked,
            //   the deck generator menu is opened.
            else if (generator_button.get_rectangle().unclick()) {
                generate(
                    display,
                    renderer,
                    messenger,
                    card_counts,
                    card_count,
                    message
                );
                
                break;
            }
            
            // Else, if the done button was pressed or clicked
            //   and the deck is valid, the game begins.
            else if (done_button.get_rectangle().unclick()) {
                // Separate if statement to get the break (for rendering this menu).
                if (valid_deck(display, renderer, card_counts, card_count)) {
                    build_song.pause();
                    song_thread.wait();
                    build_song.play();
                    build_song.dequeue();
                    game(
                        display,
                        renderer,
                        messenger,
                        card_counts,
                        package,
                        message_thread
                    );
                    song_thread.new_thread(Audio::thread_queue, &build_song);
                }
                
                break;
            }
            
            // The events are updated.
            Events::update();
        }
    }
    
    // The other player is notified that this player has disconnected.
    messenger.send(TERMINATOR_STRING);
    
    // The build song is paused, which terminates the queuing thread.
    build_song.pause();
}
//}

// Main and Connection Menus
//{
/**
 * Attempts to initialise the server.
 * The user may cancel this intialisation.
 */
void set_server(
    Display& display,
    const Renderer& renderer,
    Audio& menu_song,
    Thread& song_thread,
    Button& back_button,
    int port
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The wait sprite is intialised.
    Sprite wait_sprite(
        renderer.lined_render(
            WAIT_STRING,
            WAIT_WIDTH * display_width,
            WAIT_HEIGHT * display_height,
            WAIT_SEPARATION_X * display_width,
            WAIT_MAX_WIDTH * display_width,
            WAIT_SEPARATION_Y * display_height,
            WAIT_JUSTIFICATION
        )
    );
    
    // True if the function should return.
    bool end = false;
    
    // The server is initialised in another thread.
    // This allows the user to cancel the operation.
    std::unique_ptr<Server> server;
    ServerPackage package(server, end, port);
    Thread thread(ServerPackage::make_server, &package);
    
    // Loop to display the wait screen.
    while (!end) {
        // The display is blitted to.
        display_sprite.fill();
        display_sprite.blit(wait_sprite, WAIT_X, WAIT_Y);
        back_button.blit_to(display_sprite);
        display.update();
        
        // Loop to get user input and wait for the client.
        while (!end) {
            // If the user clicks the back button or presses
            //   the quit key, the port menu is returned to.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
            ) {
                end = true;
            }
            
            // If the server was successfully constructed,
            //   the main game is moved to.
            // The main menu music stops playing and is dequeued.
            // The music starts playing from the start,
            //   when the main game function returns.
            // This screen is not returned to.
            else if (server) {
                menu_song.pause();
                song_thread.wait();
                menu_song.play();
                menu_song.dequeue();
                
                build_deck(
                    display,
                    renderer,
                    *server
                );
                
                song_thread.new_thread(Audio::thread_queue, &menu_song);
                end = true;
            }
            
            // The events are updated.
            Events::update();
        }
    }
}

/**
 * Attempts to initialise the client.
 * The initialisation is cancelled if the host cannot be resolved.
 */
void set_client(
    Display& display,
    const Renderer& renderer,
    Audio& menu_song,
    Thread& song_thread,
    Button& back_button,
    const std::string& address,
    int port
) noexcept {
    // The main menu music is stopped.
    menu_song.pause();
    song_thread.wait();
    menu_song.play();
    menu_song.dequeue();
    
    // An attempt is made to connect to the server.
    try {
        build_deck(
            display,
            renderer,
            Client(address, port)
        );
    }
    
    // If the server cannot be connected to, an error message
    //   is displayed on the screen and the user can return
    //   to the port configuration menu.
    catch (const std::exception&) {
        // The components of the display are extracted.
        Sprite& display_sprite = display.get_sprite();
        int display_width = display_sprite.get_width();
        int display_height = display_sprite.get_height();
        
        Sprite no_server_sprite(
            renderer.lined_render(
                NO_SERVER_STRING,
                NO_SERVER_WIDTH * display_width,
                NO_SERVER_HEIGHT * display_height,
                NO_SERVER_SEPARATION_X * display_width,
                NO_SERVER_MAX_WIDTH * display_width,
                NO_SERVER_SEPARATION_Y * display_height,
                NO_SERVER_JUSTIFICATION
            )
        );
        
        // The display is blitted to.
        display_sprite.fill();
        display_sprite.blit(no_server_sprite, NO_SERVER_X, NO_SERVER_Y);
        back_button.blit_to(display_sprite);
        display.update();
        
        // Loop for input.
        while (
            !Events::unpress(QUIT_KEY)
            && !back_button.get_rectangle().unclick()
        ) {
            Events::update();
        }
    }
    
    // The main menu music recommences from the start.
    song_thread.new_thread(Audio::thread_queue, &menu_song);
}

/**
 * Sets the host's port.
 */
void set_port(
    Display& display,
    const Renderer& renderer,
    Audio& menu_song,
    Thread& song_thread,
    Button& back_button,
    Button& next_button,
    const std::string& address
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The port sprite is initialised.
    Sprite port_sprite(
        renderer.render(
            PORT_STRING,
            PORT_WIDTH * display_width,
            PORT_HEIGHT * display_height,
            PORT_SEPARATION * display_width
        )
    );
    
    // The host's port.
    std::string port;
    
    // True if the function should return.
    bool end = false;
    
    // Loop to display the port menu.
    while (!end) {
        // The display is blitted to.
        display_sprite.fill();
        display_sprite.blit(port_sprite, PORT_X, PORT_Y);
        back_button.blit_to(display_sprite);
        next_button.blit_to(display_sprite);
        
        // The host port is rendered.
        display_sprite.blit(
            renderer.render(
                port,
                PORT_WIDTH * display_width,
                PORT_HEIGHT * display_height,
                PORT_SEPARATION * display_width
            ),
            PORT_X,
            PORT_Y + PORT_SHIFT
        );
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // If the user clicks the back button or presses
            //   the quit key, the address menu is returned to.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
            ) {
                end = true;
                break;
            }
            
            // If the user clicks the next button or presses the
            //   submit key, the messenger is initialised.
            else if (
                Events::unpress(SUBMIT_KEY)
                || next_button.get_rectangle().unclick()
            ) {
                try {
                    // The server is hosted at the given port.
                    if (address == SERVER_STRING) {
                        set_server(
                            display,
                            renderer,
                            menu_song,
                            song_thread,
                            back_button,
                            std::stoi(port)
                        );
                    }
                    
                    // The client attempts to connect to the server.
                    else {
                        set_client(
                            display,
                            renderer,
                            menu_song,
                            song_thread,
                            back_button,
                            address,
                            std::stoi(port)
                        );
                    }
                }
                
                catch (const std::exception&) {}
                
                break;
            }
            
            // If the user presses the delete button,
            //   the last character entered is removed.
            else if (Events::unpress(DELETE_KEY) && port.length()) {
                port.pop_back();
                break;
            }
            
            // Else the number buttons are checked to form the port string.
            else {
                // True when the key being pressed is found.
                bool found = false;
                
                // The numbers are checked.
                for (int i = 0; !found && i < NUMBERS; i++) {
                    if (Events::unpress(Events::NUMBERS[i])) {
                        port += '0' + i;
                        found = true;
                    }
                }
                
                // If a valid key was pressed, the display is updated.
                if (found) {
                    break;
                }
            }

            Events::update();
        }
    }
}

/**
 * Sets the host's address.
 */
void set_address(
    Display& display,
    const Renderer& renderer,
    Audio& menu_song,
    Thread& song_thread,
    Button& back_button,
    Button& next_button
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The address sprite is initialised.
    Sprite address_sprite(
        renderer.render(
            ADDRESS_STRING,
            ADDRESS_WIDTH * display_width,
            ADDRESS_HEIGHT * display_height,
            ADDRESS_SEPARATION * display_width
        )
    );
    
    // The address of the host.
    std::string address;
    
    // True if the function should return.
    bool end = false;
    
    // Loop to display the address menu.
    while (!end) {
        // The display is blitted to.
        display_sprite.fill();
        display_sprite.blit(address_sprite, ADDRESS_X, ADDRESS_Y);
        back_button.blit_to(display_sprite);
        next_button.blit_to(display_sprite);
        
        // The host address is rendered.
        display_sprite.blit(
            renderer.render(
                address,
                ADDRESS_WIDTH * display_width,
                ADDRESS_HEIGHT * display_height,
                ADDRESS_SEPARATION * display_width
            ),
            ADDRESS_X,
            ADDRESS_Y + ADDRESS_SHIFT
        );
        
        // The display is updated.
        display.update();
        
        // Loop to get user input.
        while (true) {
            // If the user clicks the back button or presses
            //   the quit key, the connect menu is returned to.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
            ) {
                end = true;
                break;
            }
            
            // If the user clicks the next button or presses
            //   the submit key, the port menu is moved to.
            else if (
                Events::unpress(SUBMIT_KEY)
                || next_button.get_rectangle().unclick()
            ) {
                set_port(
                    display,
                    renderer,
                    menu_song,
                    song_thread,
                    back_button,
                    next_button,
                    address
                );
                
                break;
            }
            
            // If the user presses the delete button,
            //   the last character entered is removed.
            else if (Events::unpress(DELETE_KEY) && address.length()) {
                address.pop_back();
                break;
            }
            
            // A full stop is appended to the address, if
            //   the user pressed the full stop button.
            else if (Events::unpress(Events::FULL_STOP)) {
                address += '.';
                break;
            }
            
            // Else the number buttons are checked to form the address string.
            else {
                // True when the key being pressed is found.
                bool found = false;
                
                // The numbers are checked.
                for (int i = 0; !found && i < NUMBERS; i++) {
                    if (Events::unpress(Events::NUMBERS[i])) {
                        address += '0' + i;
                        found = true;
                    }
                }
                
                // If a valid key was pressed, the display is updated.
                if (found) {
                    break;
                }
            }

            Events::update();
        }
    }
}

/**
 * Connects the player with another.
 * One player will host the server.
 * The other player will connect to the server as a client.
 */
void connect(
    Display& display,
    const Renderer& renderer,
    Audio& menu_song,
    Thread& song_thread
) noexcept {
    // The components of the display are extracted.
    Sprite& display_sprite = display.get_sprite();
    int display_width = display_sprite.get_width();
    int display_height = display_sprite.get_height();
    
    // The server button is initialised.
    Button server_button(
        Sprite(
            renderer.render(
                SERVER_STRING,
                SERVER_WIDTH * display_width,
                SERVER_HEIGHT * display_height,
                SERVER_SEPARATION * display_width
            )
        ),
        display_sprite,
        SERVER_X,
        SERVER_Y
    );
    
    // The client button is initialised.
    Button client_button(
        Sprite(
            renderer.render(
                CLIENT_STRING,
                CLIENT_WIDTH * display_width,
                CLIENT_HEIGHT * display_height,
                CLIENT_SEPARATION * display_width
            )
        ),
        display_sprite,
        CLIENT_X,
        CLIENT_Y
    );
    
    // The back button is initialised.
    Button back_button(
        Sprite(
            renderer.render(
                BACK_STRING,
                BACK_WIDTH * display_width,
                BACK_HEIGHT * display_height,
                BACK_SEPARATION * display_width
            )
        ),
        display_sprite,
        BACK_X,
        BACK_Y
    );
    
    // The next button is initialised for future use.
    Button next_button(
        Sprite(
            renderer.render(
                NEXT_STRING,
                NEXT_WIDTH * display_width,
                NEXT_HEIGHT * display_height,
                NEXT_SEPARATION * display_width
            )
        ),
        display_sprite,
        NEXT_X,
        NEXT_Y
    );
    
    // True if the function should return.
    bool end = false;
    
    // Loop to display the connection menu.
    while (!end) {
        // The sprites are blitted to the display.
        display_sprite.fill();
        server_button.blit_to(display_sprite);
        client_button.blit_to(display_sprite);
        back_button.blit_to(display_sprite);
        display.update();
        
        // Loop to get user input.
        while (true) {
            // If the user clicks the back button or the
            //   quit key, the main menu is returned to.
            if (
                Events::unpress(QUIT_KEY)
                || back_button.get_rectangle().unclick()
            ) {
                end = true;
                break;
            }
            
            // If the server button is clicked, the port for
            //   the server to be hosted on is prompted for.
            else if (server_button.get_rectangle().unclick()) {
                set_port(
                    display,
                    renderer,
                    menu_song,
                    song_thread,
                    back_button,
                    next_button,
                    SERVER_STRING
                );
                
                break;
            }
            
            // If the client button is clicked, the
            //   address of the server is prompted for.
            else if (client_button.get_rectangle().unclick()) {
                set_address(
                    display,
                    renderer,
                    menu_song,
                    song_thread,
                    back_button,
                    next_button
                );
                
                break;
            }
            
            // The events are updated.
            Events::update();
        }
    }
}

/**
 * A card game designed by Chigozie Agomo.
 * Powered by the SDL and Net Utilities library.
 * A retake on LifeTCG with graphics.
 */
int main(int argc, char** argv) noexcept {
    // The library is initialised for video, audio, and networking.
    System::initialise(System::VIDEO | System::AUDIO | System::NET);
    
    // The version of this program and the version of
    //   the SDL and Net Utilities library are displayed.
    std::string version_string = System::version(VERSION);
    std::cout
        << "\nDemi Duel by Chigozie Agomo.\nVersion: "
        << version_string
        << "\n\nPowered by:\n"
        << System::info()
        << std::endl
    ;
    
    {
        // The display can be modified by command line arguments.
        int width = WINDOW_WIDTH;
        int height = WINDOW_HEIGHT;
        
        if (argc > 2) {
            width = std::stoi(argv[1]);
            height = std::stoi(argv[2]);
        }
        
        // The display is initialised and its components are extracted.
        Display display(TITLE_STRING, width, height);
        Sprite& display_sprite = display.get_sprite();
        int display_width = display_sprite.get_width();
        int display_height = display_sprite.get_height();
        
        // The renderer is initialised.
        //   The characters and sources are set.
        std::array<char, RENDERER_COUNT> characters;
        std::array<std::string, RENDERER_COUNT> sources;
        
        //     The directory is set.
        for (int i = 0; i < RENDERER_COUNT; i++) {
            sources[i] = SOURCE_DIRECTORY;
        }
        
        //     The lowercase letters are set.
        for (int i = 0; i < LETTERS; i++) {
            characters[i] = 'a' + i;
            sources[i] += 'a' + i;
        }
        
        // The uppercase letters are set.
        for (int i = 0; i < LETTERS; i++) {
            characters[LETTERS + i] = 'A' + i;
            sources[LETTERS + i] += 'a' + i;
        }
        
        //     The numbers are set.
        for (int i = 0; i < NUMBERS; i++) {
            characters[2 * LETTERS + i] = '0' + i;
            sources[2 * LETTERS + i] += '0' + i;
        }
        
        //     The file extension is set.
        for (int i = 0; i < RENDERER_COUNT; i++) {
            sources[i] += SOURCE_EXTENSION;
        }
        
        // The punctuation characters and sources are set.
        characters[RENDERER_COUNT - 4] = '.';
        sources[RENDERER_COUNT - 4] = FULL_STOP_SOURCE;
        characters[RENDERER_COUNT - 3] = ',';
        sources[RENDERER_COUNT - 3] = COMMA_SOURCE;
        characters[RENDERER_COUNT - 2] = ':';
        sources[RENDERER_COUNT - 2] = COLON_SOURCE;
        characters[RENDERER_COUNT - 1] = '/';
        sources[RENDERER_COUNT - 1] = SLASH_SOURCE;
        characters[RENDERER_COUNT - 7] = '!';
        sources[RENDERER_COUNT - 7] = EXCLAMATION_SOURCE;
        characters[RENDERER_COUNT - 6] = '?';
        sources[RENDERER_COUNT - 6] = QUESTION_SOURCE;
        characters[RENDERER_COUNT - 5] = ';';
        sources[RENDERER_COUNT - 5] = SEMICOLON_SOURCE;
        characters[RENDERER_COUNT - 9] = '(';
        sources[RENDERER_COUNT - 9] = LEFT_BRACKET_SOURCE;
        characters[RENDERER_COUNT - 8] = ')';
        sources[RENDERER_COUNT - 8] = RIGHT_BRACKET_SOURCE;
        characters[RENDERER_COUNT - 10] = '\'';
        sources[RENDERER_COUNT - 10] = APOSTROPHE_SOURCE;
        characters[RENDERER_COUNT - 12] = '+';
        sources[RENDERER_COUNT - 12] = PLUS_SOURCE;
        characters[RENDERER_COUNT - 11] = '-';
        sources[RENDERER_COUNT - 11] = MINUS_SOURCE;
        
        //   The sprites are loaded.
        FullRenderer<RENDERER_COUNT> renderer(characters, sources);
        
        // The title is rendered.
        Sprite title_sprite(
            renderer.render(
                TITLE_STRING,
                TITLE_WIDTH * display_width,
                TITLE_HEIGHT * display_height,
                TITLE_SEPARATION * display_width
            )
        );
        
        // The copyright is rendered.
        Sprite credits_sprite(
            renderer.lined_render(
                CREDITS_STRING,
                CREDITS_WIDTH * display_width,
                CREDITS_HEIGHT * display_height,
                CREDITS_SEPARATION_X * display_width,
                CREDITS_MAX_WIDTH * display_width,
                CREDITS_SEPARATION_Y * display_height,
                CREDITS_JUSTIFICATION
            )
        );
        
        // The quit button is initialised.
        Button quit_button(
            Sprite(
                renderer.render(
                    QUIT_STRING,
                    QUIT_WIDTH * display_width,
                    QUIT_HEIGHT * display_height,
                    QUIT_SEPARATION * display_width
                )
            ),
            display_sprite,
            QUIT_X,
            QUIT_Y
        );
        
        // The play button is initialised.
        Button play_button(
            Sprite(
                renderer.render(
                    PLAY_STRING,
                    PLAY_WIDTH * display_width,
                    PLAY_HEIGHT * display_height,
                    PLAY_SEPARATION * display_width
                )
            ),
            display_sprite,
            PLAY_X,
            PLAY_Y
        );
        
        // The menu song is loaded and queued in another thread.
        Audio menu_song(MENU_SONG_SOURCE, MENU_SONG_LENGTH);
        Thread thread(Audio::thread_queue, &menu_song);
        
        // True when the program should end.
        bool end = false;
        
        // Loop to display the main menu.
        while (!end) {
            display_sprite.fill();
            display_sprite.blit(title_sprite, TITLE_X, TITLE_Y);
            display_sprite.blit(credits_sprite, CREDITS_X, CREDITS_Y);
            quit_button.blit_to(display_sprite);
            play_button.blit_to(display_sprite);
            display.update();
            
            // Loop to get user input.
            while (true) {
                // The user can quit with the keyboard or mouse.
                if (
                    Events::press(QUIT_KEY)
                    || quit_button.get_rectangle().click()
                ) {
                    end = true;
                    break;
                }
                
                // The user can start by clicking the play button.
                else if (
                    play_button.get_rectangle().unclick()
                ) {
                    connect(display, renderer, menu_song, thread);
                    break;
                }
                
                // The events are updated.
                Events::update();
            }
        }

        // The menu song is paused, which terminates the queuing thread.
        menu_song.pause();
    }
    
    // The library is shut down.
    System::terminate();
    return 0;
}
//}
//}

/* CHANGELOG:
     v1.12.0.1:
       Replaced Chef in Midrange with Electrician.
     v1.12:
       Banisher's retreat cost was decreased from 2000 to 0.
       Burnt Offering was renamed to Void Servant.
       Shadow Flame's scaling was increased from 40 to 50.
       Shadow Flame's cap was decreased from 600 to 500.
       Shadow Flame's cost was decreased from 2000 to 0.
       Banshee's retreat cost was decreased from 2000 to 0.
       Forbidden Fuel was replaced with Void Servant.
       Screech's scaling was increased from 60 to 75.
       Screech's cap was decreased from 900 to 750.
       Screech's cost was decreased from 2000 to 0.
       Void Pact's scaling was increased from 20 to 30.
       Changes to the Midrange Decklist.
     v1.11.1:
       Time Traveller no longer gives an extra play.
       Time Traveller's overload was decreased from 2 to 1.
       Arms Smuggler's power aura was increased from 50 to 100.
       Arms Sumggler's power aura is now symmetrical.
       Arms Smuggler's overload was decreased from 1 to 0.
       Arms Smuggler now gives an extra play.
       Arms Smuggler now draws a card.
       Changes to some of the decklists.
     v1.11:
       Void Pact's scaling was decreased from 25 to 20.
       Void Pact's cap was decreased from 375 to 300.
       Shadow Bond's cost was decreased from 3000 to 2000.
       Earth Affinity and Air Affinity were replaced with Ascension.
       Ascension allows for a rank up into a card in hand.
       Shuriken Storm was replaced with Infiltrate.
       Infiltrate deals 400 to 600 damage in a single snipe (depending on coin flips).
       Subjugate's damage was decreased from 275 to 250.
       Omega Fusion's defeat requirement was increased from 2 to 3.
       Omega Fusion now stores the user in the life cards (if successful).
       Omega Elemental's health was increased from 1750 to 2000.
       Assimilate's damage was decreased from 700 to 500.
       Assimilate's healing ratio was increased from 0.5 to 0.8.
       Arms Smuggler's effect was changed to a permanent power boost of 50 (overload 1).
       Peacemaker's damage reduction was increased from 1000 to 10000.
       Improved decklist descriptions.
     v1.10.1.1:
       The mobile version's Duel Song was changed to the Record Keeper remix.
       Audio Constants were separated from the Universal Constants.
     v1.10.1:
       Nitro Boost's damage was increased from 425 to 450.
       Acceleration's damage boost was decreased from 125 to 50.
       Super Nitro's damage was increased from 500 to 650.
       Charged Thruster's damage boost was decreased from 250 to 100.
     v1.10:
       Undercurrent's damage was decreased from 650 to 600.
       Undercurrent's bonus damage was increased from 150 to 200.
       Shadow Bond's cost was increassed from 2000 to 3000.
       Assassin's effect was changed to defeat fighters below a specific health threshold.
       Arsonist's mill was decreased from 3 to 2.
       Tempo was renamed to Blend.
       A new Tempo deck featuring Pyrotechnician, Scuba Diver, and Cloud Surfer was added.
       Changes to some of the decklists.
       Changes to the ordering of the decklists.
     v1.9.5:
       The Overload effect explanation was replaced with the Next Turn effect explanation.
       Pyromancer's health was decreased from 1250 to 1150.
       Warlock's health was increased from 1150 to 1250.
       Shadow Pulse's recoil damage was increased from 100 to 150.
       Locksmith's draw count was increased from 3 to 5.
       Aggro Combo replaced Bounty Hunter with Trader.
       Updated Matchmaker's description to match its new effect.
       Improvements to various cards' descriptions.
     v1.9.4:
       Primed Payload's cost was decreased from 2000 to 0.
     v1.9.3:
       Miner's retreat cost was decreased from 1500 to 1000.
       Blowtorch's cost was increased from 1500 to 2000.
       Blowtorch's damage was increased from 350 to 450.
       Tempo replaced Chef with Recruiter.
       The mobile version only plays the Duel Song (throughout the entire app).
       Mobile Constants have been separated from the Universal Constants.
     v1.9.2:
       Incinerate's opposing mill was decreased from 2 to 1.
       Incinerate no longer mills the player.
       Incinerate no longer searches the deck for a card to draw.
       Shadow Pulse's damage was increased from 750 to 800.
       Shadow Pulse's recoil damage was decreased from 150 to 100.
       Undercurrent's damage was increased from 550 to 650.
       Undercurrent's bonus damage was decreased from 250 to 150.
       Miller's mill was decreased from 2 to 1.
       Arsonist no longer searches the deck for a card to draw.
       OTK Combo replaced Miller with Miracle Worker.
       The root effect explanation now has the correct spacing.
       Tabs have been converted to spaces.
     v1.9.1:
       Accelerate's damage boost was increased from 100 to 125.
       Nitro Boost's damage was increased from 400 to 425.
       Nitro Boost's cost was decreased from 1500 to 1000.
       Charged Thruster's damage boost was increased from 200 to 250.
       Sailor's retreat cost was decreased from 1500 to 1000.
       Dirt Biker's retreat cost was decreased from 1500 to 1000.
       Shred's damage scaling was increased from 7 to 8.
       Shred's cost was decreased from 1500 to 1000.
       Divebomb's damage was decreased from 400 to 375.
       Pyromancer's health was increased from 1200 to 1250.
       Warlock's health was increased from 1100 to 1150.
       Cleric's health was inreased from 1300 to 1350.
       Healing Aura' healing was increased from 125 to 150.
       Hydromancer's health was increased from 1000 to 1050.
       Primed Payload's damage cap was increased from 650 to 700.
       Omega Elemental's health was increased from 1500 to 1750.
       The audio files were returned to the mobile version.
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