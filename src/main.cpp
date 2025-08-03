#include "Tamagotchi.hpp"

void drawBar(WINDOW *win, int y, int x, int value, int maxValue, const char *label)
{
    int barWidth;  // ajustado para que no se corte en ventana de 30 cols
    int filled;

    barWidth = 12;
    filled = (value * barWidth) / maxValue;

    // Imprime la etiqueta seguida de ": "
    mvwprintw(win, y, x, "%s: ", label);

    // Calcula posición de inicio de la barra
    int barStartX;

    barStartX = 12;

    // Imprime el corchete de apertura
    mvwprintw(win, y, barStartX, "[");

    // Decide el color
    int colorPair;
    float ratio = (float)value / maxValue;
    if (ratio > 0.7)
        colorPair = 1; // Verde
    else if (ratio > 0.3)
        colorPair = 2; // Amarillo
    else
        colorPair = 3; // Rojo

    // Pinta la parte rellena con color
    wattron(win, COLOR_PAIR(colorPair));
    for (int i = 0; i < filled; ++i)
        mvwaddch(win, y, barStartX + 1 + i, '#');  // posición dentro de la barra
    wattroff(win, COLOR_PAIR(colorPair));

    // Pinta el resto sin color
    for (int i = filled; i < barWidth; ++i)
        mvwaddch(win, y, barStartX + 1 + i, ' ');

    // Corchete de cierre
    mvwprintw(win, y, barStartX + 1 + barWidth, "]");

    // Imprime la parte numérica
    mvwprintw(win, y, barStartX + 3 + barWidth, " %d/%d", value, maxValue);
}

void    drawStatus(WINDOW *win, const Tamagotchi &pet)
{
    werase(win);
    box(win, 0, 0);

    drawBar(win, 1, 2, pet.getHunger(), 10, "Hunger");
    drawBar(win, 2, 2, pet.getEnergy(), 10, "Energy");
    drawBar(win, 3, 2, pet.getHappiness(), 10, "Happiness");

    wrefresh(win);
}

void    drawMenu(WINDOW *win)
{
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "1 - Feed");
    mvwprintw(win, 2, 2, "2 - Play");
    mvwprintw(win, 3, 2, "3 - Sleep");
    mvwprintw(win, 4, 2, "4 - Do nothing");
    mvwprintw(win, 6, 2, "Q - Quit");
    wrefresh(win);
}

void    drawTamagotchi(WINDOW *win, const Tamagotchi &pet, std::string &msg)
{
    werase(win);
    box(win, 0, 0);

    // Ejemplo básico de cara feliz/triste según estado
    if (!pet.isAlive(msg))
    {
        mvwprintw(win, 2, 2, "  x   x  ");
        mvwprintw(win, 3, 2, "    ^    ");
        mvwprintw(win, 4, 2, "  \\___/  ");
    }
    else if (pet.getHunger() > 7)
    {
        mvwprintw(win, 2, 2, "  -   -  ");
        mvwprintw(win, 3, 2, "    O    ");
        mvwprintw(win, 4, 2, "  \\___/  ");
    }
    else
    {
        mvwprintw(win, 2, 2, "  o   o  ");
        mvwprintw(win, 3, 2, "    ^    ");
        mvwprintw(win, 4, 2, "  \\___/  ");
    }
    wrefresh(win);
}

int main()
{
    Tamagotchi pet;
    
    initscr();  //inicializa ncurses
    
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    noecho();   //no mostrar input
    cbreak();   //desactiva el buffering
    curs_set(0); //oculta el cursor
    keypad(stdscr, TRUE); //habilita teclas especiales

    WINDOW  *statusWin;
    WINDOW  *menuWin;
    WINDOW  *msgWin;
    WINDOW  *petWin;

    statusWin = newwin(5, 40, 0, 0);
    menuWin = newwin(8, 20, 5, 0);
    msgWin = newwin(3, 50, 21, 1);  // ventana de 3 filas, 50 columnas, posición fila 21, col 1
    petWin = newwin(8, 20, 5, 21);

    int         choice;
    std::string msg;
    bool        running;
    int         time;

    time = 0;
    running = true;
    while (running && pet.isAlive(msg))
    {
        drawStatus(statusWin, pet);
        drawMenu(menuWin);
        drawTamagotchi(petWin, pet, msg);

        choice = wgetch(menuWin);

        switch  (choice)
        {
            case '1':
            {
                msg = pet.feed();
                break ;
            }
            case '2':
            {
                msg = pet.play();
                break ;
            } 
            case '3':
            {
                msg = pet.sleep();
                break ;
            } 
            case '4':
            {
                pet.passTime();
                msg = "Time passes...";
                break ;
            }
            case 'q':
            {
                break ;
            }
            case 'Q':
            {
                running = false;
                msg = "";
                break ;
            }
            default:
            {
                msg = "";
                break ;
            }
        }
        time++;

        werase(msgWin);
        box(msgWin, 0, 0);
        mvwprintw(msgWin, 1, 2, "%s", msg.c_str());
        wrefresh(msgWin);

        usleep(400000);
    }
    
    clear();
    if (!pet.isAlive(msg))
    {
        mvprintw(5, 5, "%s, Game Over.", msg.c_str());
    }
    else
    {
        mvprintw(5, 5, "👋 Goodbye!");
    }

    mvprintw(7, 5, "Press any key to exit...");
    refresh();
    getch();

    delwin(statusWin);
    delwin(menuWin);
    delwin(msgWin);
    endwin();   //Finaliza ncurses
    return (0);
}