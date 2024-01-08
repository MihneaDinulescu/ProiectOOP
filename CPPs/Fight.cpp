//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Fight.h"
#include "../Headers/Correct Read Function.h"
#include "../Headers/MonsterFactory.h"
#include "../Headers/WildDogFactory.h"
#include "../Headers/WolfFactory.h"
#include "../Headers/BoarFactory.h"
#include "../Headers/SoldierFactory.h"
#include "../Headers/TigerFactory.h"
#include "../Headers/OrkFactory.h"
#include "../Headers/DarkFanaticFactory.h"

/**
 * @brief Method to generate monsters based on the current map and add them to the fightMobsVector.
 *
 * The generateMobs function evaluates the current map associated with the player and randomly selects
 * a monster type from that map to generate using the appropriate MonsterFactory subclass. Once a monster is created,
 * it is added to the fightMobsVector for the ongoing fight scenario.
 *
 * The method uses conditional checks to determine the current map's name and subsequently selects
 * the type of monster to be generated using the corresponding factory class.
 * Randomization is employed to introduce variability in monster selection based on the current map.
 *
 * Note: Proper cleanup is ensured by deleting the factory object after monster creation to avoid memory leaks.
 */
void Fight::generateMobs() {
    MonsterFactory *factory = nullptr; /**< Pointer to MonsterFactory for creating monster objects. */
    int numberOfMobs = rand() % 3 + 1;
    for (int i = 0; i < numberOfMobs; i++) {
        // Check the current map associated with the player and generate monsters accordingly.
        if (fightPlayer->getCurrentMap()->getName() == "Joan") {
            int randmob = rand() % 3 + 1; // Randomly select between three monster types.
            switch (randmob) {
                case 1:
                    factory = new WildDogFactory();
                    break;
                case 2:
                    factory = new WolfFactory();
                    break;
                case 3:
                    factory = new BoarFactory();
                    break;
            }
        } else if (fightPlayer->getCurrentMap()->getName() == "Bakra") {
            int randmob = rand() % 2 + 1; // Randomly select between two monster types.
            switch (randmob) {
                case 1:
                    factory = new SoldierFactory();
                    break;
                case 2:
                    factory = new TigerFactory();
                    break;
            }
        } else if (fightPlayer->getCurrentMap()->getName() == "Seungryong") {
            int randmob = rand() % 2 + 1; // Randomly select between two monster types.
            switch (randmob) {
                case 1:
                    factory = new OrkFactory();
                    break;
                case 2:
                    factory = new DarkFanaticFactory();
                    break;
            }
        }

        // Create a monster using the selected factory and add it to the fightMobsVector.
        if (factory) {
            fightMobsVector.push_back(factory->createMonster());
            delete factory; // Release memory allocated for the factory.
        } else {
            std::cout << "No matching factory found for the current map." << std::endl;
        }
    }
}


/**
 * @brief Constructor for the Fight class.
 *
 * The constructor initializes the fightPlayer with the provided Player object and initiates the
 * generation of monsters via the generateMobs method. Additionally, the fightFunction is invoked
 * to commence the fighting scenario.
 *
 * @param player Pointer to the Player object representing the player involved in the fight.
 */
Fight::Fight(Player *player) {
    this->fightPlayer = player; // Assign the provided Player object to fightPlayer.
    generateMobs();             // Generate monsters for the fight scenario.
    fightFunction();            // Initiate the fighting mechanism.
}

/**
 * @brief Destructor for the Fight class.
 *
 * The destructor ensures proper cleanup by iterating through the fightMobsVector and deleting
 * each dynamically allocated Monster object to prevent memory leaks.
 */
Fight::~Fight() {
    for (auto &j: fightMobsVector) {
        delete j; // Delete each dynamically allocated Monster object.
    }
}

/**
 * @brief Method to print the monsters in the fight along with their respective HP percentages.
 *
 * The printMobsWithHP function traverses through the fightMobsVector and displays each monster's
 * name along with its current HP percentage. This provides a visual representation of the monsters
 * present in the ongoing fight and their health status.
 */
void Fight::printMobsWithHP() {
    for (unsigned long i = 0; i < this->fightMobsVector.size(); i++) {
        std::cout << i + 1 << ". " << this->fightMobsVector.at(i)->getName() << " has "
                  << this->fightMobsVector.at(i)->getHp() << " % HP\n";
    }
}

/**
 * @brief Method to manage the main mechanics of the fight scenario.
 *
 * The fightFunction is responsible for orchestrating the primary mechanics of the fight. It initiates
 * the combat loop where the player and monsters engage in actions until either the player's health
 * depletes or all monsters are defeated. During the fight, the method checks the player's health,
 * handles player's death scenarios, and prompts for player's input to decide actions during combat.
 * In the event of the player's death, the method handles the respawn mechanics, including potential
 * item loss and setting the player's health to a specific percentage for the respawn.
 */
void Fight::fightFunction() {
    this->printMobsWithHP(); // Display the monsters along with their respective HP percentages.

    // Continue the fight until there are no monsters left.
    while (!fightMobsVector.empty()) {
        // Check if the player has been defeated.
        if (fightPlayer->isDead()) {
            std::cout << "--------- YOU HAVE DIED ! ----------\n";

            // Handle item loss from the player's inventory upon death.
            if (!fightPlayer->getInventory()->isEmpty()) {
                int randItem = rand() % fightPlayer->getInventory()->getInventorySize();
                while (fightPlayer->getInventory()->getInventorySpace().at(randItem)->getQuantity() == 0)
                    randItem = rand() % fightPlayer->getInventory()->getInventorySize();

                // Display the lost item and its details.
                std::cout << "You have lost " << fightPlayer->getInventory()->getInventorySpace().at(randItem)->getItemName();
                if (fightPlayer->getInventory()->getInventorySpace().at(randItem)->getCurentItem()->getDamage() != 0)
                    std::cout << " with +" << fightPlayer->getInventory()->getInventorySpace().at(randItem)->getCurentItem()->getPlusLevel() << " plus level";
                std::cout << "\n";

                // Update the item quantity and reset the sword if it was the lost item.
                fightPlayer->getInventory()->getInventorySpace().at(randItem)->setQuantity(0);
                if (fightPlayer->getInventory()->getInventorySpace().at(randItem)->getCurentItem() == fightPlayer->getSword())
                    fightPlayer->setSwordNull();
            }

            // Respawn the player with 25% HP and provide feedback.
            fightPlayer->setHp(25);
            std::cout << "You will be respawned with 25% HP\n";
            return; // Exit the method after handling the player's death.
        }
        this->awaitPlayerInput(); // Await player's input during the combat loop.
    }
}

/**
 * @brief Awaits player's input during combat.
 *
 * This method displays the player's current health and provides an option for the player to choose
 * an action. Based on the player's choice, it either triggers a hit action against the monsters or
 * provides feedback for an invalid input. After the player's action, if monsters remain, the player
 * can be attacked by the monsters in response.
 */
void Fight::awaitPlayerInput() {
    fightPlayer->displayHp(); // Display the current health of the player.
    std::cout << "1. Hit\n";

    int decision = read(1, 1); // Read the player's decision.
    switch (decision) {
        case 1:
            this->hitFunction(); // Execute the hit action.
            if (!this->fightMobsVector.empty())
                this->getAttacked(); // If monsters remain, trigger their attack.
            break;
        default:
            std::cout << "Invalid Input\n"; // Handle invalid input from the player.
            break;
    }
}

/**
 * @brief Executes the attack action from the remaining monsters.
 *
 * This method randomly selects monsters from the fightMobsVector to launch an attack against the player.
 * It ensures that each monster attacks not more than once during this phase.
 */
void Fight::getAttacked() {
    int randomAttack = 0;
    while (randomAttack == 0)
        randomAttack = rand() % fightMobsVector.size() + 1;

    int freq[4] = {0};
    while (randomAttack > 0) {
        int randomIndex = rand() % fightMobsVector.size();
        freq[randomIndex]++;
        if (freq[randomIndex] == 1) {
            fightMobsVector.at(randomIndex)->attack(fightPlayer);
            std::cout << "The " << randomIndex + 1 << " " << fightMobsVector.at(randomIndex)->getName()
                      << " hit you for " << fightMobsVector.at(randomIndex)->getDamage() << " damage!\n";
        }
        randomAttack--;
    }
}


/**
 * @brief Executes the player's hit action against a chosen monster.
 *
 * This method allows the player to choose a monster to attack. Once the monster is selected,
 * it calculates the total damage inflicted by the player and updates the monster's health.
 * If the monster's health drops to zero or below, it rewards the player with experience points
 * and currency, removes the defeated monster from the fight, and updates the fightMobsVector.
 */
void Fight::hitFunction() {
    std::cout << "Choose a monster to be hit\n";

    unsigned long numberOfMob;
    while (true) {
        this->printMobsWithHP();
        numberOfMob = read2(1, fightMobsVector.size()); // Read the chosen monster index.

        if ((this->fightMobsVector.size() >= numberOfMob) && numberOfMob >= 1) {
            break;
        }

        std::cout << "Invalid input!\n"; // Handle invalid input.
    }

    // Calculate the total damage to be dealt to the chosen monster.
    int totalDamage = this->fightPlayer->getDamage();
    if (fightPlayer->getSword() != nullptr)
        totalDamage += this->fightPlayer->getSword()->getDamage() + this->fightPlayer->getSword()->getPlusLevel();

    // Display the damage dealt and update the monster's health.
    std::cout << "You've hit the " << numberOfMob << ". " << this->fightMobsVector.at(numberOfMob - 1)->getName()
              << " for " << totalDamage << " damage!\n";
    this->fightMobsVector.at(numberOfMob - 1)->takeDamage(totalDamage);

    // Check if the monster has been defeated and update the player's rewards accordingly.
    if (this->fightMobsVector.at(numberOfMob - 1)->getHp() <= 0) {
        this->fightPlayer->addXp(this->fightMobsVector.at(numberOfMob - 1)->getXpGain());
        this->fightPlayer->sumYang(this->fightMobsVector.at(numberOfMob - 1)->getYangDrop());
        delete this->fightMobsVector.at(numberOfMob - 1);
        this->fightMobsVector.erase(this->fightMobsVector.begin() + numberOfMob - 1);
    }
}


