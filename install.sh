#!/bin/bash

sudo apt install vim -y
sudo apt install git -y
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
mv ~/dotfiles/.vimrc ~
mv ~/dotfiles/.bash_aliases ~
mv ~/dotfiles/.tmux.conf ~
sudo mv ~/dotfiles/gruvbox.vim /usr/share/vim/vim80/colors/
vim -c ':PluginInstall' -c ":q" -c ':q'
echo "Moves and installs complete, delete folder."
