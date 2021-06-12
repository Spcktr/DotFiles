#!/bin/bash

sudo apt-get install vim -y
sudo apt-get install git -y
sudo apt-get install tmux -y
sudo apt-get install fonts-powerline
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
mv .vimrc ~
mv .tmux.conf ~
mv .tmux.conf.local ~
sudo mv ~/dotfiles/gruvbox.vim /usr/share/vim/vim80/colors/
vim -c ':PluginInstall' -c ":qa"
echo "Moves and installs complete, delete folder."
