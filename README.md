# Dotfiles

Inluded dotfiles for my environments

* .tmuf.conf
* .bash_aliases 
* .vimrc
* gruvbox.vim


## Installation
There are two methods to install

### Automatic
Install using the install.sh script

First:
```sudo chmod +x install.sh```
then run:
```./install.sh```

### Manually
Ensure vim is isntalled
```sudo apt install vim```

All dotfiles are for home directory.

The gruvbox.vim goes in the folfer ```/usr/share/vim/vim80/colors/```

The leto.reg is for gruvbox colors in putty windows, edit the key name to insert correctly.

For installing and setting up Vundle and vim-airline, run:
```bash 
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
```
Open vim then run:
```bash
:PluginInstall
```
It will isntall all plugins from the .vimrc dotfile

# CRKDB QMK Keymap

I've added a [QMK](https://docs.qmk.fm/#/) keymap for my [corne v2](https://github.com/foostan/crkbd). This is a chorded keymap that covers most modifiers that I use. I will get around to uploading a keymap image at some point in the future but the keymap.c is pretty obvious.

# Notes if using WSL

Make sure you are using windows terminal (the new terminal) for best results. For the full Nord theme in your settings.json use the scheme below to ensure best colours.
```json
{
   	  "name" : "nord",
  	  "background" : "#2e3440",
   	  "foreground" : "#d8dee9",
  	  "black": "#3b4252",
  	  "blue": "#5e81ac",
  	  "brightBlack": "#4c566a",
  	  "brightBlue": "#81a1c1",
  	  "brightCyan": "#8fbcbb", 
   	  "brightGreen": "#a3be8c",
  	  "brightPurple": "#b48ead",
	  "brightRed": "#bf616a",
   	  "brightWhite": "#eceff4",
   	  "brightYellow": "#ebcb8b",
  	  "cyan": "#88c0d0",
          "green": "#a3be8c",
  	  "purple": "#b48ead",
    	  "red": "#bf616a",
   	  "white": "#e5e9f0",
   	  "yellow": "#ebcb8b"
	}
```

## Issues
Font showing as blocks? You may need to download fonts patched with Powerline symbols or the standalone [PowerlineSymbols.otf](https://powerline.readthedocs.io/en/master/installation/linux.html#fonts-installation).
Make sure you set the font for your terminal to be either the powerline font or one that is powerline enabled.
List of fonts that are powerline enabled can be found [here](https://github.com/powerline/fonts), you can also use `sudo apt-get install fonts-powerline`
