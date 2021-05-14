# fake-pacman ![animation](https://i.imgur.com/JUkcCKJ.gif)

Fake-pacman is a terminal program for macOS and Linux that will make it look like you are installing a pacman package. 

Just run the executable, type any package name and watch it "install" the package.

## Compiling
### Linux
First you have to install **ncurses**, just run `sudo pacman -S ncurses` on Arch, or `sudo apt install libncurses-dev` on Debian.

Then to compile it, run `make linux`.

### MacOS
Install gcc by running `brew install gcc`, and install **ncurses** by running `brew install ncurses`. If you want to compile a universal executable that will run on all macs, you also need **Xcode Command Line Tools**, install it by running `xcode-select --install`.

Then to compile type `make macX86` or `make macARM` depending on what procceser you have. To make the universal executable run `make macUNI`.

## License
Fake-pacman is free and open source, it's distributed under the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html).
