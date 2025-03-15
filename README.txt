Demi Duel by Chigozie Agomo
This is a card game that is a reimagination of LifeTCG
  (also by Chigozie Agomo) with an improved UI.



INSTRUCTIONS:
  CONNECTING:
    One player should host the game as the server.
    The server should select an available port to host the game on.
    The other player should connect as the client.
    The client needs to enter the server's IP address and port.
    
    Two clients may connect to each other using a bridging program
      hosted by a third party (such as utility/bridge2).
    
    To duel with both players on the same PC, the client
      should connect to the 127.0.0.1 IP address.
    
    To duel against Demi Duel: AUTO (CPU) set up a
      server with a port in the range 80700 - 80710.
    
    The port determines the deck used by the bot:
      80700 - Random Deck.
      80701 - Aggro Deck (Incomplete).
      80702 - Tempo Deck.
      80703 - Blend Deck (Incomplete).
      80704 - Control Deck (Incomplete).
      80705 - Mill Deck (Incomplete).
      80706 - Midrange Deck (Incomplete).
      80707 - Aggro Combo Deck (Incomplete).
      80708 - Control Combo Deck (Incomplete).
      80709 - OTK Combo Deck (Incomplete).
      80710 - AFK.
    
    
  DECK BUILDING:
    The deck building phase allows the players to choose
      fighter, supporter, and energy cards to add to the deck.
    The player may choose to build their deck, generate
      a premade deck, or edit a premade deck.
    
    A deck must have exactly 30 cards.
    A deck must have at least one unranked fighter.
    A deck can only have, at most, one copy of a fighter or supporter card.
    A deck can only have, at most, two copies of an energy card.
    
    
  DUEL SETUP:
    At the start of the duel, a player is randomly chosen to go first.
    The player that goes first can't attack on their first turn.
    The player that goes second can play an extra card on their first turn.
    Players draw seven cards from their deck at the start of the game.
    An unranked fighter is guaranteed to be in the starting hand.
    
    Each player then places three life cards onto the board.
    Life cards are special and powerful supporter cards,
      that are not part of the player's deck.
    Life cards are drawn when the player's fighter is defeated.
    
    An unranked fighter is then chosen to be the active fighter.
    Active fighters can attack, retreat, or use their ability.
    Most attacks deal damage to the opponent's active fighter.
    
    
  DUELING:
    This game is turn-based and each player draws a
      card from their deck at the start of their turn.
    If the deck is empty when the player tries to draw at the start
      of their turn, they must choose one life card to draw instead.
    
    On a player's 9th turn and each turn after that, the number of cards
      to draw at the start of the turn are increased by one.
    If a player does not have enough cards in their deck to draw the full number,
      they draw all of the cards in their deck and then draw one life card.
    
    A player can check the fighters in play, their cards in their various stores,
      the opponent's cards in their trash, and the cards in the void.
    
    The player can play cards in their hand.
    The number of cards that can be played each turn is limited.
    The number starts of at one and increments with each turn
      to a maximum of five cards to play per turn.
    
    Playing an unranked fighter places it on the bench.
    Benched fighters can't attack or retreat and usually can't be attacked.
    However, a benched fighter can become the active fighter, if
      the active fighter retreats, is defeated, or is removed.
    Benched fighters may still be able to use their ability.
    
    Playing a ranked fighter ranks up the fighter that it ranks up from.
    When a fighter ranks up, the old rank is discarded, the effects on the old
      rank are removed, and the new rank keeps all the cards attached to the old rank.
    
    When a supporter card is played, its effects are
      resolved and the card is then discarded.
    
    Playing an energy card allows the energy card to be attached to a fighter.
    Energy allows fighters to attack or retreat.
    Only fighters with a sufficient amount of energy can attack or retreat
      and the energy's element often needs to match the fighter.
    
    The player can attack once a turn.
    Only the active fighter's attack may be used.
    Attacks often deal damage to the opponent's active
      fighter and may have additional effects.
    
    The player can retreat once a turn.
    Retreating switches the active fighter with a fighter on the bench.
    Nothing is discarded when retreating in this game.
    Retreating removes all effects from the active fighter.
    
    When a fighter takes damage (usually from attacks), their health decreases.
    When a fighter's health drops to zero or below, the fighter is defeated.
    Players draw a life card for each of their defeated fighters.
    Defeated fighters are discarded (sent to the trash)
      along with their attached energy cards.
    
    A player loses if they concede or run out of life cards or fighters in play.
    
    
  CUSTOM DECKS:
    Replace the fields given with valid deck data.
    Changing the file structure may result in deck corruption.
    The structure on lines after "DESCRIPTION:" can be modified freely.
    
    
  TIPS:
    A fighter being defeated may not be the end!
    In this game, the losing player draws the life card,
      so a comeback is possible!
    
    Different decks have different playstyles,
      strengths, weaknesses, and win conditions!
    Playing different decks can help you learn about them and know their counters!
    
    Decks should have a thought-out, but flexible,
      game plan, in order to maximise the chance of winning.
    Use cards that work well with each other and have a
      good balance of fighter, supporter, and energy cards!
    
    Not all decks will attempt to win by defeating your fighters and some
      decks will need a couple of turns to set up before dominating!
    If a player seems to want you to run out of cards in your deck,
      try to avoid drawing too many cards!
    If a player seems to be stalling, make sure that you play
      aggressively to prevent them from setting up!
    
    Fighters can't be affected by temporary effects, while they are on the bench.
    Switching can be an effective way to remove detrimental effects from your fighters!



SUPPORT:
  Email: chiago321@gmail.com
  Projects: https://github.com/chig00



CREDITS:
  Programmed by Chigozie Agomo in C++
  Uses the SDL and SDL Net Utilities library by Chigozie Agomo.
  SDL and SDL Net Utilities is an abstraction of SDL and SDL Net.
  Compiled using MinGW (which is a Windows port of GCC).
  Sprites produced by Chigozie Agomo in Pixelformer.
