#### Console based game maker

###### author: Kai

### Game mechanics

###### Save/Load Game

- game can not be saved during a fight with an enemy

- game saves as a file

- (possibly) game allows for multiple save file slots

- player can then choose a save file to load, at which point the game starts

###### Pausing Game

- player can exit to the pause screen at any point unless they are in the middle of a fight

- allows to save/load the game

- allows to access inventory

###### Fighting mechanics

- both the player and the enemy can get a slight random increase during a fight

- when the player defeats the enemy, there is a random chance of an item drop (clothing, food, weapons)

- The outcome of a fight depends on the enemy and the player's HP and AP stats. The enemy's stats will be randomly
  generated (but not too out of bounds so that the player has a considerable chance of winning) (possible
  functionality - make it resemble a turn based RPG where the player has a choice of attacking, defending and using an
  item from the inventory)

- gives score points based on the enemy's HP

###### Score System

- defeating an enemy gives scores based on the enemy's HP

- solving a puzzle gives a score based on the puzzle type

- score is displayed after key points in the story & at the end of the game

- possible functionality: earned score points can be used as currency and can be traded in a shop (need to implement
  shop for this), or traded at certain story line points (for example if a player meets a merchant NPC)

---

### Game entities

###### User

- name (inputted by the user)

- score

- health points (HP) (default - 100)

- defense points (DP) (default - 0)

- attack points (AP) (default - 10)

- one slot for current weapon (default - none)

- one slot for current clothing (default - none)

- inventory (that can hold a limited number of items) (default - empty, limit - 10 items)

###### Enemy

- health points (HP)

- attack points (AP) (can get a slight random increase during a fight)

- when defeated, have a slight chance to drop various items, most commonly food, sometimes weapons and rarely clothing

enemy's HP and AP are randomly generated at the beginning of the fight based on the player's HP and AP so that the enemy
is not too powerful for the player

possible functionality - adding boss fights

###### Inventory

- (holds a limited number of items) (possible functionality: the limit increases the further the user progresses into
  the story)

  each item has methods:

- use item

- throw away the item

- view item

possible functionality - items like weapons and clothing take up more item slots compared to food

###### Item Types

- weapon - can be held by a player (state: attack points - increases the player's attack points) (possibly might have a
  special ability, e.g. a small chance to set the enemy on fire)

- clothing - can be worn by the player (state: defense points - increases the player's defense points). When being
  attacked, the player's defence points will decrease the incoming attack points by a certain percentage (will create a
  calculation formula for this later) (possibly might have a lifespan, e.g. after 10 battles the clothing breaks down)

- food - can be eaten by the player (state: HP - increases the player's HP). some types of food might unlock new story
  paths.

possible functionality: add special items like keys that open treasure chests

