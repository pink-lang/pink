set -e

export PINK_HOME="$(dirname "$(readlink -f "$0")")"/dist
export PINK_OS=linux

test -f ./dist/bin/pink && dist/bin/pink -nosourcemap -o src/c/out_pink_linux.c src/pink

gcc -pipe -O2 -flto -static -o dist/bin/pink src/c/pink.c

