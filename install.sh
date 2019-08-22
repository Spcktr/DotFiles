#!/bin/bash

sudo apt-get install vim -y
sudo apt-get install git -y
sudo apt-get install tmux -y
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
mv ~/dotfiles/.vimrc ~
mv ~/dotfiles/.tmux.conf ~
sudo mv ~/dotfiles/gruvbox.vim /usr/share/vim/vim80/colors/
vim -c ':PluginInstall' -c ":q" -c ':q'
echo "Moves and installs complete, delete folder."
