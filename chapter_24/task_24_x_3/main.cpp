#include "creature.h"
#include "monster.h"
#include "player.h"
#include "random.h"
#include <iostream>
#include <string>

// attack Monster, include leveling up
void attackMonster(Player& player, Monster& monster)
{
    monster.reduceHealth(player.getAttack());
    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << "\n";
        player.addGold(monster.getGold());
        player.levelUp();
        std::cout << "You level up \n";
        std::cout << player << "\n";
    }
}

// handle fight player and single Monster
void fightMonster(Player& player, Monster& monster)
{

    while (!monster.isDead() && !player.isDead())
    {
        // player attack first
        attackMonster(player, monster);
        if (monster.isDead())
        {
            break;
        }
        else
        {
            player.reduceHealth(monster.getAttack());
        }
    }
}

// handle monster attacking the player
void attackPlayer(Player& player, const Monster& monster)
{
    std::cout << "The " << monster.getName() << " hit you for "
              << monster.getAttack() << " damage.\n";
    player.reduceHealth(monster.getAttack());
    std::cout << "Your current health is " << player.getHealth() << "\n";
}

void runOrFight(Player& player, Monster monster)
{
    std::cout << "(r)un or (f)ight ";
    char userChoice{};
    std::cin >> userChoice; // currently without user input validation

    if (userChoice == 'f')
    {
        fightMonster(player, monster);
    }
    else
    {
        int runSucceed{Random::get(0, 1)};
        if (runSucceed == 0)
        { // dont succeed to run so player have to fight
            attackPlayer(player, monster); // one free attack for the monster
            if (player.getHealth() > 0)
            {
                runOrFight(player,
                           monster); // recursion, player can decide again
            }
        }
        else
        {
            std::cout << "You successfully fled. \n";
        }
    }
}

int main()
{
    std::cout << "Whats your name hero? \n";
    std::string nameHero;
    std::cin >> nameHero;
    std::cout << "Welcome Sir " << nameHero << " good luck \n";

    Player player{Player(nameHero)};
    std::cout << "You have health: " << player.getHealth()
              << " attack: " << player.getAttack() << "\n";

    while (true)
    {
        Monster monster{Monster::getRandomMonster()};
        std::cout << "You have encountered a " << monster.getName() << "("
                  << monster.getSymbol() << ") \n";
        runOrFight(player, monster);

        if (player.hasWon())
        {
            std::cout << "You did it champ. You saved the world \n";
            std::cout << "You have gold: " << player.getGold()
                      << " ,level: " << player.getLevel()
                      << " , health: " << player.getHealth();
            break;
        }
        if (player.getHealth() <= 0)
        {
            std::cout << "You are dead bro. Maybe next time. \n";
            std::cout << "You have gold: " << player.getGold()
                      << " ,level: " << player.getLevel()
                      << " , health: " << player.getHealth() << "\n";
            break;
        }
    }

    return 0;
}
