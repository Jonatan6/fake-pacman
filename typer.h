int typer(int y, int x, bool hidden, char* pacupdate) {
  for (int ch, ox = x; ch != 10; x++) {
    ch = getch();
    if (ch != 127) {
      if (!hidden) mvprintw(y, x, "%c", ch);
      else mvprintw(y, x, "*");
      if (pacupdate) pacupdate[x - ox] = ch;
    }
    else x = x - 2;
    mvprintw(y, x + 1, " ");	
  }
}
