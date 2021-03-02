#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "typer.h"
#include "eater.h"

char pac[20]; // This is the name of the package.
char * usr; // This is the username of the user.
char answer[20]; // This is what the user types when prompted "[Y/n]".

int main() {

  srand(time(0)); // Seed the rng using Unix time.

  initscr();
  start_color(); // Make it possible to use colored text.
  noecho(); // Suppress the echoing of typed characters.
  curs_set(FALSE); // Don't show the cursor.

  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x); // Get the size of the screen.
  max_x = max_x - 71 - 1; // Subtract the lenght of the progress bar from the size of the screen.


  usr = (char * ) malloc(32 * sizeof(char)); // I'm allocating 32 characters for the username, as that is the max lenght of a username in Unix.
  getlogin_r(usr, 32);

  init_pair(1, COLOR_BLUE, COLOR_BLACK), init_pair(2, COLOR_YELLOW, COLOR_BLACK);

  mvprintw(0, 0, "%s@archlinux $ sudo pacman -S", usr);
  refresh();

  typer(0, 28 + strlen(usr), false, pac);
  strtok(pac, "\n"); // Remove newline character from the package-name.

  mvprintw(1, 0, "[sudo] password for %s", usr);
  refresh();
  typer(1, 21 + strlen(usr), true, false);

  mvprintw(2, 0, "resolving dependencies...");
  refresh();
  usleep(100000);
  mvprintw(3, 0, "looking for conflicting packages...");
  refresh();
  usleep(120000);
  attron(A_BOLD);
  mvprintw(5, 0, "Packages (1)");
  attroff(A_BOLD);
  mvprintw(5, 13, pac); // Print the package-name on the screen.
  attron(A_BOLD);
  mvprintw(7, 0, "Total Download Size:");
  mvprintw(7, 23, "%d.%d MiB", rand() % 100, rand() % 100);
  mvprintw(8, 0, "Total Installed Size:");
  mvprintw(8, 23, "%d.%d MiB", rand() % 10 + 5, rand() % 100);
  mvprintw(9, 0, "Net Upgrade Size:");
  attroff(A_BOLD);
  mvprintw(9, 23, "%d.%d MiB", rand() % 5 + 1, rand() % 9);

  attron(A_BOLD);
  mvprintw(11, 0, "   Proceed with installation? [Y/n]");
  attron(COLOR_PAIR(1));
  mvprintw(11, 0, "::");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  refresh();

  typer(11, 36, false, answer);
  strtok(answer, "\n"); // Remove newline character from the typed string.
  if (strcmp(answer, "y") != 0 && strcmp(answer, "yes") != 0 && strcmp(answer, "Yes") != 0 && strcmp(answer, "\n") != 0) {
    for (int i = 12; i < max_y; i++) {
      mvprintw(i, 0, "%s@archlinux $", usr);
      refresh();
      typer(i, 13 + strlen(usr), false, false);
    }
  }

  attron(A_BOLD);
  mvprintw(12, 0, "   Retrieving packages...");
  attron(COLOR_PAIR(1));
  mvprintw(12, 0, "::");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  refresh();
  usleep(10000);
  mvprintw(13, 0, "%s.2.1.8", pac);
  mvprintw(13, max_x - 26, "%d.%d MiB  1234 MiB/s 00:00 [o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%", rand() % 10, rand() % 10);

  eater(13, max_x, 100000, 10); // Spawn the eating pacman at line 13.
  usleep(500000);

  mvprintw(14, 0, "%s.runtime.0.3.7", pac);
  mvprintw(14, max_x - 29, "%d.%d KiB  1234 MiB/s 00:00 [o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%", rand() % 10000, rand() % 10);
  refresh();

  eater(14, max_x, 33333, 30); // Spawn the eating pacman at line 14.

  mvprintw(15, 0, "(2/2) checking keys in keyring");
  mvprintw(15, max_x, "[----------------------------------------------------------------] 100%%");
  refresh();
  usleep(85000);
  mvprintw(16, 0, "(2/2) checking package integrity");
  mvprintw(16, max_x, "[----------------------------------------------------------------] 100%%");
  refresh();
  usleep(70000);
  mvprintw(17, 0, "(2/2) loading package files");
  mvprintw(17, max_x, "[----------------------------------------------------------------] 100%%");
  refresh();
  usleep(52000);
  mvprintw(18, 0, "(2/2) checking for file conflicts");
  mvprintw(18, max_x, "[----------------------------------------------------------------] 100%%");
  refresh();
  usleep(110000);
  mvprintw(19, 0, "(2/2) checking available disk space");
  mvprintw(19, max_x, "[----------------------------------------------------------------] 100%%");
  refresh();
  usleep(10000);
  attron(A_BOLD);
  mvprintw(20, 0, "   Processing package changes...");
  attron(COLOR_PAIR(1));
  mvprintw(20, 0, "::");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  refresh();
  usleep(20000);
  mvprintw(21, 0, "(1/2) installing %s-runtime", pac);
  mvprintw(21, max_x, "[o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%");
  mvprintw(22, 0, "(2/2) installing %s", pac);
  mvprintw(22, max_x, "[o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%");
  refresh();

  eater(21, max_x, 25000, false); // Spawn the eating pacman at line 21.
  usleep(500000);

  eater(22, max_x, 31000, false); // Spawn the eating pacman at line 22.
  usleep(10000);

  attron(A_BOLD);
  mvprintw(23, 0, "   Running post-transaction hooks...");
  attron(COLOR_PAIR(1));
  mvprintw(23, 0, "::");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  refresh();
  usleep(1000000);

  mvprintw(24, 0, "(1/3) Arming ConditionNeedsUpdate...");
  refresh();
  usleep(1000000);
  mvprintw(25, 0, "(2/3) Updating icon theme caches...");
  refresh();
  usleep(1000000);
  mvprintw(26, 0, "(3/3) Updating the desktop file MIME type cache...");
  refresh();
  usleep(80000);

  for (int i = 27; i < max_y; i++) {
    mvprintw(i, 0, "%s@archlinux $", usr);
    refresh();
    typer(i, 13 + strlen(usr), false, false);
  }

  endwin(); // Close the program.
}
