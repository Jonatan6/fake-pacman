# fake-pacman
Fake-pacman is a program that will make it look like you are installing a pacman package. 
Just run the executable by running `./fake-pacman`, then type any package name and watch it "install" the package.

## Compiling
### Linux
To install ncurses run `sudo pacman -S ncurses` on Arch, or `sudo apt install libncurses-dev` on Debian.

Then to compile it you need to run: `gcc -lncurses fake-pacman.c -o fake-pacman`, or using the included makefile just run: `make`
### Mac
Install Xcode Command Line Tools by running `xcode-select --install`, and install the ncurses libraby by running `brew install ncurses`.

Then to compile using the included Makefile, run `make mac`.
## License
Fake-pacman is free and open source, it's distributed under the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html).
