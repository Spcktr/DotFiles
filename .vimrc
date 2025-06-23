" ------------------------------------------------------------
" Load plugins
" ------------------------------------------------------------

set nocompatible
filetype off

" Set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim

" Plugins will be downloaded under the specified directory.
call vundle#begin('~/.vim/plugged')

" Let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" Colorschemes
Plugin 'kristijanhusak/vim-hybrid-material'
Plugin 'cocopon/iceberg.vim'
Plugin 'arcticicestudio/nord-vim'
Plugin 'sjl/badwolf'
Plugin 'lifepillar/vim-solarized8'
Plugin 'scheakur/vim-scheakur'
Plugin 'Badacadabra/vim-archery'

" PloyGlot
Plugin 'sheerun/vim-polyglot'

" Auto Pairs
Plugin 'jiangmiao/auto-pairs'   " Auto Pairs

" NERDTree
Plugin 'preservim/nerdtree'

" Tagbar
Plugin 'preservim/tagbar'

" vim-protodef 
Plugin 'derekwyatt/vim-protodef'

" vim-astro
Plugin 'wuelnerdotexe/vim-astro'

" List ends here. Plugins become visible to Vim after this call.
call vundle#end()
filetype plugin indent on


" ------------------------------------------------------------
" auto-pairs configuration
" ------------------------------------------------------------

let g:AutoPairsShortcutToggle = '<C-P>'


" ------------------------------------------------------------
" NERDTree configuration
" ------------------------------------------------------------

let NERDTreeShowBookmarks = 1
let NERDTreeShowHidden = 1
let NERDTreeShowLineNumbers = 0
let NERDTreeMinimalMenu = 1
let NERDTreeWinPos = "left"
let NERDTreeWinSize = 31


" ------------------------------------------------------------
" tagbar configuration
" ------------------------------------------------------------

let g:tagbar_autofocus = 1
let g:tagbar_autoshowtag = 1
let g:tagbar_position = 'botright vertical'

" ------------------------------------------------------------
" Vim Astro configuration
" ------------------------------------------------------------

let g:astro_typescript = 'enable'
let g:astro_javascript = 'enable'

" ------------------------------------------------------------
" vim-protodef configuration 
" ------------------------------------------------------------

nmap <buffer> <silent> <leader> ,PP
nmap <buffer> <silent> <leader> ,PN

" NOTE: This doesn't seem to disable the sorting.
let g:disable_protodef_sorting = 1


" ------------------------------------------------------------
" Vim configuration
" ------------------------------------------------------------

set nu                  " Enable line numbers
syntax on               " Enable synax highlighting
set incsearch           " Enable incremental search
set hlsearch            " Enable highlight search
set splitbelow          " Always split below"
set mouse=a             " Enable mouse drag on window splits
set tabstop=4           " How many columns of whitespace a \t is worth
set shiftwidth=4        " How many columns of whitespace a “level of indentation” is worth
set expandtab           " Use spaces when tabbing

if !has('nvim')
    set termwinsize=12x0    " Set terminal size
endif

set background=dark     " Set background 
colorscheme scheakur    " Set color scheme


" ------------------------------------------------------------
" Key mappings
" ------------------------------------------------------------

" General
nmap        <C-B>     :buffers<CR>
nmap        <C-J>     :term<CR>

" NERDTree
nmap        <F2>      :NERDTreeToggle<CR>

" tagbar
nmap        <F8>      :TagbarToggle<CR>

