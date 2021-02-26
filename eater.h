int eater(int y, int x, int wait, int secupdate) {		
  for (int i = 1; i <= 64; i++) {
    attron(COLOR_PAIR(2));
    if (i % 3) mvprintw(y, i + x, "c");
    else mvprintw(y, i + x, "C");
    refresh();
    attroff(COLOR_PAIR(2));
    mvprintw(y, i + x, "-");
    mvprintw(y, x + 67, "%d%%", i / 13 + i / 2 + i);
    usleep(wait);
    if (secupdate) mvprintw(y, x - 2, "%d", i/secupdate);
    if (secupdate && i % secupdate == 3) mvprintw(y, x - 18, "%d.%d", rand() % 100, rand() % 10);
  }
  refresh();
}
