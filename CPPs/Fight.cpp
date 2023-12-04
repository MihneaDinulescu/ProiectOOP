//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Fight.h"
#include "../Headers/Correct Read Function.h"

void Fight::generateMobs() {

    int numberOfMobs = rand() % 3 + 1;

    for (int i = 0; i < numberOfMobs; i++) {

        if (fightPlayer->getCurrentMap()->getName().compare("Joan") == 0) {
            int randmob = rand() % 3 + 1;
            switch (randmob) {
                case 1:
                    fightMobsVector.push_back(new WildDog());
                    break;
                case 2:
                    fightMobsVector.push_back(new Wolf());
                    break;
                case 3:
                    fightMobsVector.push_back(new Boar());
                    break;
            }

        } else if (fightPlayer->getCurrentMap()->getName() == "Bakra") {
            int randmob = rand() % 2 + 1;
            switch (randmob) {
                case 1:
                    fightMobsVector.push_back(new Soldier());
                    break;
                case 2:
                    fightMobsVector.push_back(new Tiger());
                    break;
            }

        } else if (fightPlayer->getCurrentMap()->getName().compare("Seungryong") == 0) {
            int randmob = rand() % 2 + 1;
            switch (randmob) {
                case 1:
                    fightMobsVector.push_back(new Ork());
                    break;
                case 2:
                    fightMobsVector.push_back(new DarkFanatic());
                    break;
            }

        }

    }
}

Fight::Fight(Player *player) {
    this->fightPlayer = player;
    generateMobs();
    fightFunction();
}

Fight::~Fight() {
    for (auto &j: fightMobsVector)
        delete j;
}

void Fight::printMobsWithHP() {
    for (unsigned long i = 0; i < this->fightMobsVector.size(); i++) {
        std::cout << i + 1 << "." << this->fightMobsVector.at(i)->getName() << " has "
                  << this->fightMobsVector.at(i)->getHp() << " % HP\n";

    }
}

void Fight::fightFunction() {

    this->printMobsWithHP();

    while (!fightMobsVector.empty()) {
        if (fightPlayer->isDead()) {
            std::cout << "--------- YOU HAVE DIED ! ----------\n";
            //SARE ITEM DIN INVENTAR
            if (!fightPlayer->getInventory()->isEmpty()) {
                int randItem = rand() % fightPlayer->getInventory()->getInventorySize();
                while (fightPlayer->getInventory()->getInventorySpace().at(randItem)->getQuantity() == 0)
                    randItem = rand() % fightPlayer->getInventory()->getInventorySize();
                std::cout << "You have lost "
                          << fightPlayer->getInventory()->getInventorySpace().at(randItem)->getItemName();
                if (fightPlayer->getInventory()->getInventorySpace().at(randItem)->getCurentItem()->getDamage() != 0)
                    std::cout << " with +" << fightPlayer->getInventory()->getInventorySpace().at(
                            randItem)->getCurentItem()->getPlusLevel()
                              << " plus level";
                std::cout << "\n";
                fightPlayer->getInventory()->getInventorySpace().at(randItem)->setQuantity(0);
                if (fightPlayer->getInventory()->getInventorySpace().at(randItem)->getCurentItem() ==
                    fightPlayer->getSword())
                    fightPlayer->setSwordNull();

            }
            fightPlayer->setHp(25);
            std::cout << "You will be respawned with 25% HP\n";
            return;
        }
        this->awaitPlayerInput();

    }


}

void Fight::awaitPlayerInput() {

    fightPlayer->displayHp();
    std::cout << "1. Hit\n";

    int decission = read(1, 1);

    switch (decission) {
        case 1:
            this->hitFunction();
            if (!this->fightMobsVector.empty())
                this->getAttacked();
            break;
        default:
            std::cout << "Invalid Input\n";
            break;

    }

}

void Fight::getAttacked() {

    int randomAttack = 0;
    while (randomAttack == 0)
        randomAttack = rand() % fightMobsVector.size() + 1;

    int freq[4] = {0};  // vector evidenta acelasi mob la random
    while (randomAttack > 0) {
        int randomIndex = rand() % fightMobsVector.size();
        freq[randomIndex]++;
        if (freq[randomIndex] == 1) {
            fightMobsVector.at(randomIndex)->attack(fightPlayer);
            std::cout << "The " << randomIndex + 1 << " " << fightMobsVector.at(randomIndex)->getName()
                      << " hit you for " <<
                      fightMobsVector.at(randomIndex)->getDamage() << " damage!\n";
        }
        randomAttack--;
    }
}


void Fight::hitFunction() {

    std::cout << "Choose a monster to be hit\n";

    unsigned long numberOfMob;

    while (true) {

        this->printMobsWithHP();
        numberOfMob = read2(1, fightMobsVector.size());

        if ((this->fightMobsVector.size() >= numberOfMob) && numberOfMob >= 1) {

            break;

        }

        std::cout << "Invalid input!\n";

    }

    int totaldmg = this->fightPlayer->getDamage();
    if (fightPlayer->getSword() != nullptr)
        totaldmg += this->fightPlayer->getSword()->getDamage() + this->fightPlayer->getSword()->getPlusLevel();
    std::cout << "You've hit the " << numberOfMob << ". " << this->fightMobsVector.at(numberOfMob - 1)->getName()
              << " for " << totaldmg << " damage!\n";
    this->fightMobsVector.at(numberOfMob - 1)->takeDamage(totaldmg);
    if (this->fightMobsVector.at(numberOfMob - 1)->getHp() <= 0) {
        this->fightPlayer->addXp(this->fightMobsVector.at(numberOfMob - 1)->getXpGain());
        this->fightPlayer->sumYang(this->fightMobsVector.at(numberOfMob - 1)->getYangDrop());
        delete this->fightMobsVector.at(numberOfMob - 1);
        this->fightMobsVector.erase(this->fightMobsVector.begin() + numberOfMob - 1);
    }

}


