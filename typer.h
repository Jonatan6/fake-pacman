int typekeys(int y, int x, bool hidden, char* pacupdate, char* usrupdate) {
  for (int ch; ch != 10; x++) {
    ch = getch();
    if (ch != 127) {
      if (!hidden) mvprintw(y, x, "%c", ch);
      else mvprintw(y, x, "*");
      if (pacupdate) pacupdate[x - 28 - strlen(usrupdate)] = ch;
    }
    else x = x - 2;
    mvprintw(y, x + 1, " ");	
  }
}
