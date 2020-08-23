Demi Duel by Chigozie Agomo
This is a card game that is a graphical reimagination
  of LifeTCG (also by Chigozie Agomo).


INSTRUCTIONS:
  CONNECTING:
    One player should host the game as the server.
	The server should select an available port to host the game on.
	The other player should conect as the client.
	The client needs to enter the server's address and port.
	
	Two clients may connect to each other using a bridging program
	  hosted by a third party (such as utility/bridge2).
	
	To duel with both players on the same PC, the Client
	  should connect to the 127.0.0.1 IP address.
	
	
  DECK BUILDING:
    The deckbuilding phase allows the players to choose
	  fighter, supporter, and energy cards to add to the deck.
	The player may choose to build their deck, generate
	  a premade deck, or edit a premade deck.
	  
	A deck must have exactly 40 cards.
	A deck must have at lest one unranked fighter.
	A deck can only have, at most, one copy
	  of a fighter or supporter card.
	A deck can only have, at most, four copies of an energy card.
	
  DUEL SETUP:
    At the start of the duel, some set up is required.
	A player is randomly chosen to go first.
	The player that goes first can't attack on their first turn.
	The player that goes second can play an extra card on their first turn.
	Players draw 5 cards until they have an unranked fighter in their hand.
	The player that performs fewer redraws can draw extra cards.
	
	Players can then place 4 life cards from their deck onto the board.
	Life cards are drawn when the player's fighter is defeated.
	
	An unranked fighter is then chosen to be the active fighter.
	Active fighters can attack, retreat, or use their ability.
	Most attacks deal damage to the active fighter.
	
	Benched fighters are chosen to be played later.
	Benched fighters can't attack or retreat and usually can't be attacked.
	However, a benched fighter can become the active fighter, if
	  the active fighter retreats, is defeated, or is removed.
	Benched fighters may still be able to use their ability.
	
	
  DUELING:
    This game is turn based and each player draws a
	  card from their deck at the start of their turn.
	If the deck is empty when the player tries to draw at the start
	  of their turn, they must choose a life card to draw instead.
	
	A player can check the fighters in play, their cards in their various stores,
	  the opponent's cards in ther trash, and the cards in the void.
	  
	The player can play cards in their hand. Playing an unranked fighter places it
	  on the bench. Playing a ranked fighter ranks up the fighter that it ranks up from.
	  When a supporter card is played, its effects are performed and the card is then
	  discarded. Playing an energy card allows the energy card to be attached to a fighter.
	
	The number of cards that can be played each turn is limited.
	The number starts of at one and increments with each turn.
	  
	Energy allows fighters to attack or retreat. Only fighters with a sufficient amount of
	  energy can attack or retreat and the energy's element often needs to match the fighter.
	  
	The player can attack once a turn. Only the active fighter's attack may be used.
	Attacks often deal damage to the opponent's active
	  fighter and may have additional effects.
	  
	The player can retreat once a turn. Retreating switched the active fighter with
	  a fighter on the bench. Nothing is exchanged when retreating in this game.
	Retreating removes all effects from the retreated fighter.
	  
	When a fighter takes damage (usually from attacks), their health decreases.
	When a fighter's health drops to zero or below, the fighter is defeated.
	Players draw a life card for each of their defeated fighters.
	Defeated fighters are discarded (sent to the trash) along with their attached energy cards.
	
	If a fighter runs out of life cards or fighters in play, they lose.
	If a player concedes, they lose.
	
	
  TIPS:
    A fighter being defeated may not be the end! In this game, the
	  losing player draws the life card, so a comeback is possible!
	  
	Different decks have different playstyles, strengths, weaknesses,
	  and win conditions! Playing different decks can help you learn
	  about them and know their counters!
	  
	Decks should have a thought-out, but flexible, gameplan, in order to
	  maximise the chance of winning. Use cards that work well with each
	  other and have a good balance of fighter, supporter, and energy cards!
	  
	Not all decks will attempt to win by defeating your fighters and some
	  decks will need a couple of turns to set-up before dominating!
	  If a player seems to want you to run out of cards in your deck,
	  try to avoid drawing too many cards! If a player seems to be stalling,
	  make sure that you play aggressively to prevent them from setting up!
	  
	Fighters can't be affected by temporary effects, while they are on the bench.
	Switching can be an effective way to remove detrimental effects from your fighters!


SUPPORT:
  Have any questions, comments, or feedback?
  Want to see my other projects?
  Care to support my development of free, open-source software?
  Check me out here: https://gf.me/u/x4rw9t
  My email address: chiago321@gmail.com

CREDITS:
  Programmed by Chigozie Agomo in C++
  Uses the SDL and SDL Net Utilities library by Chigozie Agomo.
  Compiled using MinGW (which is a Windows port of GCC).
  SDL and SDL Net Utilities is an abstraction of SDL and SDL Net.
  Sprites when produced by Chigozie Agomo in Pixelformer.
  The audio was modified using Audacity.
  Menu Music source: https://www.youtube.com/watch?v=Yk0lZorU3ns
  Deck building music source: https://www.youtube.com/watch?v=FDXu7D3GGXY
  Duel music source: https://www.youtube.com/watch?v=PGCCa_HZ6Wc