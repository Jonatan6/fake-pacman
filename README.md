# fake-pacman
Fake-pacman is a program that will make it look like you are installing a pacman package. Just run the executable by running `./fake-pacman`, then type any package name and watch it "install" the package.

## Compiling
This program is written in C with the ncurses library. So to compile it you will need ncurses, and a C compiler like gcc.

To isntall ncurses run `sudo pacman -S ncurses` on Arch, or `sudo apt install ncurses` on Debian.
Then to compile it you need to run `gcc -lncurses fake-pacman.c -o fake-pacman`
## License
Fake-pacman is free and open source, it's distributed under the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html).
