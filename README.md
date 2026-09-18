# Codeforces

C++ solutions, organised by rating range. Tests are pulled from the browser
into Neovim with the Competitive Companion extension and run with
[competitest.nvim](https://github.com/xeluxee/competitest.nvim).

## One-time setup

1. `brew install gcc` — Codeforces judges with GNU G++; Apple's `g++` is clang
   and has no `<bits/stdc++.h>`. The Neovim config picks the newest
   `/opt/homebrew/bin/g++-NN` automatically. If the major version changes,
   update `Compiler:` in `.clangd` too.
2. Install the **Competitive Companion** extension
   ([Chrome](https://chrome.google.com/webstore/detail/competitive-companion/cjnmckjndlpiamhfimnnjmnckgghkjbl)
   / [Firefox](https://addons.mozilla.org/firefox/addon/competitive-companion/)).
   No extension settings needed: it already targets port 27121.
3. Neovim: `~/.config/nvim/lua/plugins/competitest.lua` plus the LazyVim
   `lang.clangd` extra. Run `:Lazy sync` once.

## Daily workflow

1. `cd 800to1000 && nvim` (open Neovim inside the rating folder you want).
2. In Neovim press `<leader>tR` (receive problem). Status line says it is
   listening.
3. In the browser, open the problem page and click the Competitive Companion
   icon (green plus). Neovim creates and opens
   `<Problem>/<Problem>.cpp` from `template.cpp`, with samples in
   `<Problem>/tests/`.
4. Write the solution. `<leader>tr` compiles and runs every sample in a split
   on the right. In that split: `d` toggles diff, `i`/`a`/`o`/`e` show
   input / expected / stdout / stderr, `R` reruns one, `<C-r>` reruns all,
   `q` closes. `<leader>ts` reopens it.
5. Add your own edge cases with `<leader>ta` (`<C-s>` saves the editor).

## Keymaps

| Key          | Action                             |
|--------------|------------------------------------|
| `<leader>tR` | receive problem (file + tests)     |
| `<leader>tC` | receive whole contest              |
| `<leader>tt` | receive testcases into current file|
| `<leader>tr` | compile and run all testcases      |
| `<leader>tn` | run without recompiling            |
| `<leader>ts` | reopen runner UI                   |
| `<leader>ta` | add testcase                       |
| `<leader>te` | edit testcase                      |
| `<leader>td` | delete testcase                    |
| `<leader>tq` | close the results panel            |

## Layout

```
800to1000/
  AWatermelon/
    AWatermelon.cpp
    AWatermelon.out         # binary, gitignored
    tests/
      AWatermelon_input0.txt
      AWatermelon_output0.txt
```

Compile flags: `-std=c++20 -O2 -Wall -Wextra -DLOCAL`. `LOCAL` enables the
`dbg(x)` macro in the template; it is off on the judge.
