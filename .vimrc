set nocompatible              " required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

" add all your plugins here (note older versions of Vundle
" used Bundle instead of Plugin)
  
Plugin 'tmhedberg/SimpylFold'

" highlight syntax errors & highlighting
Plugin 'vim-syntastic/syntastic'
Plugin 'pangloss/vim-javascript'

" variables, functions, etc
Plugin 'xolox/vim-misc'
Plugin 'xolox/vim-easytags'
Plugin 'majutsushi/tagbar'

" nerd tree
Plugin 'preservim/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'

" ctrl + p to bring up file list
Plugin 'kien/ctrlp.vim'

" git commits using :Gcommit
Plugin 'tpope/vim-fugitive'

" adds git 
" Plugin 'ariblade/vim-gitgutter'
Plugin 'Xuyuanp/nerdtree-git-plugin'


" opens and close brackets
Plugin 'Raimondi/delimitMate'

" icons
Plugin 'ryanoasis/vim-devicons'

" beancount syntax highligher
" Plugin 'nathangrigg/vim-beancount'
" plugin for nord theme
Plugin 'arcticicestudio/nord-vim'

" Vim Wiki
" Plugin 'vimwiki/vimwiki'

" vim markdown
Plugin 'SidOfc/mkdx'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

" encoding
set encoding=utf-8

" set split
set splitbelow
set splitright

" Split navigation

nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>


" nerdtree alias mapping
nnoremap <Space>nt :NERDTree<CR>

" Enable folding
set foldmethod=indent
set foldlevel=99

" Enable folding with the spacebar
nnoremap <space> za

syntax on
" line number
set relativenumber
set showcmd
set incsearch
set hlsearch
set ruler
set backspace=indent,eol,start


set mouse=a
set number
au! BufNewFile,BufRead *.svelte set ft=html

filetype plugin on
set tabstop=4

" mkdx settings
let g:mkdx#settings     = { 'highlight': { 'enable': 1 },
                        \ 'enter': { 'shift': 1 },
                        \ 'links': { 'external': { 'enable': 1 } },
                        \ 'toc': { 'text': 'Table of Contents', 'update_on_write': 1 },
                        \ 'fold': { 'enable': 1 } }
