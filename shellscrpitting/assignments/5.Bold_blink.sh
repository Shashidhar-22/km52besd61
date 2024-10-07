<<c
#!/bin/sh

echo  "\033[0;5;30mshashidhar\033[0m"
echo  "\033[1;5;31mshashidhar\033[0m"
echo  "\033[2;5;32mshashidhar\033[0m"
echo  "\033[3;5;33mshashidhar\033[0m"
echo  "\033[4;5;34mshashidhar\033[0m"
echo  "\033[5;5;35mshashidhar\033[0m"
echo  "\033[6;5;36mshashidhar\033[0m"
echo  "\033[7;5;37mshashidhar\033[0m"


c

bold=$(tput bold)
normal=$(tput sgr0)

echo "${bold}Hello World"

tput blink
echo Hello World
tput sgr0

color_red=$(tput setaf 1) # red var
color_normal=$(tput sgr0) # normal var
color_blue=$(tput setaf 4) # blue var
color_yellow=$(tput setaf 3) # yellow var
color_violet=$(tput setaf 5) # violet var
color_normal=$(tput sgr0) # normal var
tput blink
echo "$color_red ${bold}Hello$color_blue World"
tput sgr0

