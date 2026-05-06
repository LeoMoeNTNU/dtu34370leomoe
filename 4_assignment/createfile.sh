#!/bin/bash

# Check if a filename was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

touch "tests/test$1.c"
touch "$1.c"
touch "$1.h"
touch "scripts/test$1.sh"

echo "Created 4 files for $1"