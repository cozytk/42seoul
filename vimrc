call plug#begin('~/.vim/plugged')
    "Plug 'Github계정명/저장소명'"
Plug 'tpope/vim-sensible'
Plug 'pandark/42header.vim'
Plug 'cozytk/42'"
call plug#end()

function RunFile(filetype, name)
    let str = ':!'
    let str .= 'echo "' . a:name . '"; '
    let str .= 'echo "---- RUN --------------"' . '; '
    if a:filetype=='c'
        let str .= 'gcc *.c; ./a.out 2>&1' . '; '
    elseif a:filetype=='swift'
        let str .= 'swift "' . a:name . '"; '
    else
        let str .= 'echo "지원하지 않는 파일 입니다."; '
    endif
    let str .= 'echo "\n---- END --------------"'
    execute str
endfunction

function DebugRunFile(filetype, name)
    let str = ':!'
    if a:filetype=='c'
        let str .= 'gcc -g *.c; lldb ./a.out' . '; '
    elseif a:filetype=='swift'
        let str .= 'swift "' . a:name . '"; '
    else
        let str .= 'echo "지원하지 않는 파일 입니다."; '
    endif
    execute str
endfunction

map <F3> <ESC>:NERDTreeToggle<CR>
imap <F3> <ESC>:NERDTreeToggle<CR>
map <F6> <ESC>:w<CR>:call RunFile(expand('%:e'), expand('%'))<CR>
imap <F6> <ESC>:w<CR>:call RunFile(expand('%:e'), expand('%'))<CR>
map <S-F6> <ESC>:w<CR>:call DebugRunFile(expand('%:e'), expand('%'))<CR>
imap <S-F6> <ESC>:w<CR>:call DebugRunFile(expand('%:e'), expand('%'))<CR>


if has("syntax")    " syntax가 있는 파일에서
    syntax on    " syntax highlighting 기능을 on
endif
set nu            " 왼쪽에 줄 번호를 표시
set mouse=a        " vim에서 마우스를 사용
set autoindent        " 자동으로 들여쓰기
set cursorline        " 커서가 있는 라인 강조
set ignorecase        " 검색 기능 사용 시 대소문자 무시
set title        " 열려 있는 파일을 창 타이틀에 표시
set smartindent
set ts=4
set shiftwidth=4

nmap <f1> :FortyTwoHeader<CR>"

"set clipboard=unnamedplus
