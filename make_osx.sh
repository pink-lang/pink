set -e

export PINK_HOME="$(dirname "$(readlink -f "$0")")"/src
export PINK_OS=linux

test -f ./dist/pink && dist/pink -nosourcemap -o src/c/out_pink_osx.c src/pink

clang -o dist/pink src/c/pink.c

