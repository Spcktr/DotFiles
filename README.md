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
