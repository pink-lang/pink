export PINK_HOME="$(dirname "$(readlink -f "$0")")"/src
export PINK_OS=linux

dist/pink -nosourcemap -o src/c/out_pink_linux.c src/pink

gcc -static -o dist/pink src/c/pink.c

