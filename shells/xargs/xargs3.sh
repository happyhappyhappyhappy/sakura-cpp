#!/bin/bash
# Pattarn 1
sudo grep -l bash /etc/*  2> /dev/null | xargs -I {} echo "[" {} "]" 
# Pattarn 2
sudo grep -l bash /etc/*  2> /dev/null | xargs -L 1 echo "Files: "