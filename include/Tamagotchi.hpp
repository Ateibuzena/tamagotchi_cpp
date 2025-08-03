#ifndef TAMAGOTCHI_HPP
# define TAMAGOTCHI_HPP

# define MAX_HUNGER 10
# define MIN_ENERGY 0
# define MIN_HAPPINESS 0

# include <string>
# include <ncurses.h>
# include <unistd.h> //para sleep();
# include <iostream>
# include <cstring>

class   Tamagotchi 
{
    private:
                int hunger;
                int energy;
                int happiness;
    
    public:
                Tamagotchi();   //constructor por defecto

                std::string     feed();
                std::string     play();
                std::string     sleep();

                void            showStatus() const;
                void            passTime(); //simula el paso del tiempo
                bool            isAlive(std::string &msg) const;

                int             getHunger() const;
                int             getEnergy() const;
                int             getHappiness() const;
};

#endif
