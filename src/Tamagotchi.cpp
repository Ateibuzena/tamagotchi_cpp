#include "Tamagotchi.hpp"

Tamagotchi::Tamagotchi() : hunger(5), energy(5), happiness(5)
{

}

std::string Tamagotchi::feed()
{
    if (hunger > 0)
    {
        hunger--;
        energy--;
        return ("Yummy! Thanks for the food.");
    }
    else
    {
        energy--;
        return ("Thanks, but i'm not hungry.");
    }
}

std::string Tamagotchi::play()
{
    if (energy > 0)
    {
        energy--;
        happiness++;
        hunger++;
        return ("So funny!");
    }
    else
    {
        happiness--;
        return ("I'm so tired.." );
    }
}

std::string Tamagotchi::sleep()
{
    energy++;
    hunger++;
    return ("Zzz..Zzz..Zzz..");
}

void    Tamagotchi::showStatus() const
{
    std::cout << "Tamagotchi Status:\n" << std::endl;
    std::cout << "Hungry:   " << hunger << std::endl;
    std::cout << "Energy:   " << energy << std::endl;
    std::cout << "Happiness: " << happiness << std::endl;
}

void    Tamagotchi::passTime()
{
    hunger++;
    energy--;
    happiness--;
}

bool    Tamagotchi::isAlive(std::string &msg) const
{
    if (hunger >= MAX_HUNGER)
    {
        msg = "Tamagotchi died of hunger!";
        return (false);
    }
    else if (energy <= MIN_ENERGY)
    {
        msg = "Tamagotchi died of exhaustion!";
        return (false);
    }
    else if (happiness <= MIN_HAPPINESS)
    {
        msg = "Tamagotchi died of sadness!";
        return (false);
    }
    msg.clear();
    return (true);
}

int Tamagotchi::getHunger() const
{
    return (hunger);
}

int Tamagotchi::getEnergy() const
{
    return (energy);
}

int Tamagotchi::getHappiness() const
{
    return (happiness);
}