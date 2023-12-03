export PINK_HOME="$(dirname "$(readlink -f "$0")")"/src
export PINK_OS=linux

if [ -e dist/pink ]; then
  dist/pink -nosourcemap -notypeinfo -o src/c/out_pink_linux.c src/pink
else
  echo
  echo "-- No pink binary found; using previously built src/c/out_pink_linux.c --"
  echo
fi

gcc -static -o dist/pink src/c/pink.c

