# 0x16. C - Simple Shell
 **By Spencer Cheng, featuring Julien Barbier**
 Project to be done in teams of 2 people (your team: Benson Kiprotich)

# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

# Authors
Benson Kiprotich

## How to add Author file
`Bash script for generating the list of authors in git repo`
```
#!/bin/sh

git shortlog -se \
  | perl -spe 's/^\s+\d+\s+//' \
  | sed -e '/^CommitSyncScript.*$/d' \
  > AUTHORS
  ```
