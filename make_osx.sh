set -e

export PINK_HOME="$(dirname "$(readlink -f "$0")")"/dist
export PINK_OS=linux

test -f ./dist/bin/pink && ./dist/bin/pink -nosourcemap -o src/c/out_pink_osx.c src/pink

clang -o ./dist/bin/pink src/c/pink.c

