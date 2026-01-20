#! /bin/bash

asciidoctor assts/*.adoc *.adoc
if [ $# -ne 1 ]; then 
  echo "usage: ./build.sh <message>"
fi

git add .
git commit -m "$1" 
