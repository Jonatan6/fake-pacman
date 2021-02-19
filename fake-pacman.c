 #include <ncurses.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>

   char pac[20];	// This is the name of the package.
   char * usr;		// This is the username of the user.
  
   int typekeys(int y, int x, bool pacupdate, bool hidden) {
     for (int ch; ch != 10; x++) {	// If the key pressed is not Enter, run the loop again.
       ch = getch();
       if (ch != 127) {			// If the key pressed is not Backspace, then continue.
         if (!hidden) mvprintw(y, x, "%c", ch);
         else mvprintw(y, x, "*");	// If what you're typing is not supposed to be hidden, continue.
         if (pacupdate) pac[x - 28 - strlen(usr)] = ch;
       }				// If what you type should update the package-name, continue.
       else x = x - 2;
       mvprintw(y, x + 1, " ");		// If the key pressed is Backspace, instead print " " where the previous character was typed.
     }
   }

   int eater(int y, int x, int wait) {		// The y integer is the y coordinate.
     for (int i = 0; i <= 63; i++) {		// The x integer is the x coordinate.
       attron(COLOR_PAIR(2));			// The wait integer is the amount of
       if (i % 3) mvprintw(y, i + x, "c");	// time each cycle will take.
       else mvprintw(y, i + x, "C");
       refresh();
       attroff(COLOR_PAIR(2));
       mvprintw(y, i + x, "-");
       mvprintw(y, x + 66, "%d%%", i / 11 + i / 2 + i + 1);	// This part updates the percentages.
       usleep(wait);
     }
     refresh();
   }
//----------------------------------------------------------------------------------------
 int main() {
//----------------------------------------------------------------------------------------

   initscr();
   start_color();	// This makes it possible to use colored text.
   noecho();		// This suppresses the echoing of typed characters.
   curs_set(FALSE);	// Don't show the cursor.

   int max_y = 0, max_x = 0;
   getmaxyx(stdscr, max_y, max_x);	// Get the size of the screen.
   max_x = max_x - 71 - 1;		// Subtract the lenght of the progress bar from the size of the screen.


   usr = (char * ) malloc(32 * sizeof(char));	// I'm allocating 32 characters for theu username,
   getlogin_r(usr, 32);				// as that is the max lenght of a username in linux.

   init_pair(1, COLOR_BLUE, COLOR_BLACK), init_pair(2, COLOR_YELLOW, COLOR_BLACK);

   mvprintw(0, 0, "%s@archlinux $ sudo pacman -S", usr);
   refresh();

   typekeys(0, 28 + strlen(usr), true, false);
   strtok(pac, "\n"); 	// Remove newline character from the package-name.

   mvprintw(1, 0, "[sudo] password for %s", usr);
   refresh();
   typekeys(1, 21 + strlen(usr), false, true);

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
   mvprintw(7, 23, "8.19 MiB");
   mvprintw(8, 0, "Total Installed Size:");
   mvprintw(8, 23, "34.02 MiB");
   mvprintw(9, 0, "Net Upgrade Size:");
   attroff(A_BOLD);
   mvprintw(9, 23, "0.02 MiB");

   attron(A_BOLD);
   mvprintw(11, 0, "   Proceed with installation? [Y/n]");
   attron(COLOR_PAIR(1));
   mvprintw(11, 0, "::");
   attroff(COLOR_PAIR(1));
   attroff(A_BOLD);
   refresh();
   typekeys(11, 36, false, false);

   attron(A_BOLD);
   mvprintw(12, 0, "   Retrieving packages...");
   attron(COLOR_PAIR(1));
   mvprintw(12, 0, "::");
   attroff(COLOR_PAIR(1));
   attroff(A_BOLD);
   refresh();
   usleep(10000);
   mvprintw(13, 0, "%s.2.1.8", pac);
   mvprintw(13, max_x - 26, "6.4 MiB  11.8 MiB/s 00:00 [o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%");

   eater(13, max_x+1, 100000);	// Spawn the eating pacman at line 13.
   usleep(500000);

   mvprintw(14, 0, "%s.runtime.0.3.7", pac);
   mvprintw(14, max_x - 29, "1785.6 KiB  17.4 MiB/s 00:00 [o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%");
   refresh();

   eater(14, max_x+1, 35000);	// Spawn the eating pacman at line 14.

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

   eater(21, max_x+1, 25000);	// Spawn the eating pacman at line 21.
   usleep(500000);

   eater(22, max_x+1, 31000);	// Spawn the eating pacman at line 22.
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

   for (int i = 27; i < max_y; i++) { // 27 is the ASCII value for the Escape key.
     mvprintw(i, 0, "%s@archlinux $", usr);
     refresh();
     typekeys(i, 13 + strlen(usr), false, false);
   }

   endwin(); // Close the program.
 }
