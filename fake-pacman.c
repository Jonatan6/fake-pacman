 #include <ncurses.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>

 int main() {

 initscr(); start_color(); noecho(); curs_set(FALSE);
 int max_y = 0, max_x = 0;
 init_pair(1, COLOR_BLUE, COLOR_BLACK), init_pair(2, COLOR_YELLOW, COLOR_BLACK);
 char pac[20];

 getmaxyx(stdscr, max_y, max_x);
 max_x = max_x-71-1;

 char *buf;
 buf=(char *)malloc(32*sizeof(char));
 getlogin_r(buf,32);

 int typekeys(int y, int x, bool pacupdate) {
 for (int ch; ch != 10; x++) {
 ch = getch();
 move(y, x);
 if (ch != 127) { // Check if the key pressed is backspace, if it is dont print the key pressed.
 printw("%c", ch);
 if (pacupdate) pac[x-27-sizeof ("%s", buf)] = ch;
 }
 else {
 x--;
 move(y, x);
 printw(" "); 
 x--;}
 }
 }

 int i;
 int eater(int y, int wait) {
 for ( i=0; i<=63; i++ ) {
 attron(COLOR_PAIR(2));
 if (i % 3) { mvprintw(y, i+max_x+1, "c");}
 else {mvprintw(y, i+max_x+1, "C");} refresh();
 attroff(COLOR_PAIR(2));
 mvprintw(y, i+max_x+1, "-");
 mvprintw(y, max_x+1+66, "%d%%", i/11+i/2+i+1);
 usleep(wait);} refresh();
 }

 mvprintw(0, 0, "%s@archlinux $ sudo pacman -S", buf); refresh();

 typekeys(0, 27 + sizeof ("%s", buf), true);
 strtok(pac, "\n"); // Remove newline char

 mvprintw(1, 0, "[sudo] password for %s", buf); refresh();
 typekeys(1, 25 + sizeof ("%s"), false);

 mvprintw(2, 0, "resolving dependencies..."); refresh(); usleep(10000);
 mvprintw(3, 0, "looking for conflicting packages..."); refresh(); usleep(12000);
 attron(A_BOLD); mvprintw(5, 0, "Packages (1)"); attroff(A_BOLD); mvprintw(5, 13, pac);
 attron(A_BOLD); mvprintw(7, 0, "Total Download Size:");  mvprintw(7, 23, "8.19 MiB");
 mvprintw(8, 0, "Total Installed Size:");  mvprintw(8, 23, "34.02 MiB");
 mvprintw(9, 0, "Net Upgrade Size:"); attroff(A_BOLD);  mvprintw(9, 23, "0.02 MiB"); 

 attron(A_BOLD); mvprintw(11, 0, "   Proceed with installation? [Y/n]"); attron(COLOR_PAIR(1)); mvprintw(11, 0, "::"); attroff(COLOR_PAIR(1)); attroff(A_BOLD); refresh();
 typekeys(11, 36, false);

 attron(A_BOLD); mvprintw(12, 0, "   Retrieving packages..."); attron(COLOR_PAIR(1)); mvprintw(12, 0, "::"); attroff(COLOR_PAIR(1)); attroff(A_BOLD); refresh(); usleep(10000);
 mvprintw(13, 0, "%s.2.1.8", pac); mvprintw(13, max_x-26, "6.4 MiB  11.8 MiB/s 00:00 [o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%");

 eater(13, 100000);
 usleep(500000);

 mvprintw(14, 0, "%s.runtime.0.3.7", pac); mvprintw(14, max_x-29, "1785.6 KiB  17.4 MiB/s 00:00 [o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%"); refresh();

 eater(14, 35000);

 mvprintw(15, 0, "(2/2) checking keys in keyring"); mvprintw(15, max_x, "[----------------------------------------------------------------] 100%%"); refresh(); usleep(85000);
 mvprintw(16, 0, "(2/2) checking package integrity"); mvprintw(16, max_x, "[----------------------------------------------------------------] 100%%"); refresh(); usleep(70000);
 mvprintw(17, 0, "(2/2) loading package files"); mvprintw(17, max_x, "[----------------------------------------------------------------] 100%%"); refresh(); usleep(52000);
 mvprintw(18, 0, "(2/2) checking for file conflicts"); mvprintw(18, max_x, "[----------------------------------------------------------------] 100%%"); refresh(); usleep(110000);
 mvprintw(19, 0, "(2/2) checking available disk space"); mvprintw(19, max_x, "[----------------------------------------------------------------] 100%%"); refresh(); usleep(10000);
 attron(A_BOLD); mvprintw(20, 0, "   Processing package changes..."); attron(COLOR_PAIR(1)); mvprintw(20, 0, "::"); attroff(COLOR_PAIR(1)); attroff(A_BOLD); refresh(); usleep(20000);
 mvprintw(21, 0, "(1/2) installing %s-runtime", pac); mvprintw(21, max_x, "[o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%");
 mvprintw(22, 0, "(2/2) installing %s", pac); mvprintw(22, max_x, "[o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o] 0%%"); refresh();

 eater(21, 25000);
 usleep(500000);

 eater(22, 31000);
 usleep(10000);

 attron(A_BOLD); mvprintw(23, 0, "   Running post-transaction hooks..."); attron(COLOR_PAIR(1)); mvprintw(23, 0, "::"); attroff(COLOR_PAIR(1)); attroff(A_BOLD); refresh(); usleep(8000);

 mvprintw(24, 0, "(1/3) Arming ConditionNeedsUpdate..."); refresh(); usleep(10000);
 mvprintw(25, 0, "(2/3) Updating icon theme caches..."); refresh(); usleep(10000);
 mvprintw(26, 0, "(3/3) Updating the desktop file MIME type cache..."); refresh(); usleep(10000);

 mvprintw(27, 0, "%s@archlinux $", buf); refresh();
 typekeys(27, 17 + sizeof("%s"), false);

 endwin();
 }
