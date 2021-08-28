#!/bin/sh
echo "----sample1----"
sudo grep -l bash /etc/* 2> /dev/null | xargs head -3
echo "----sample2----"
sudo grep -l bash /etc/* 2> /dev/null | xargs -p head -3
echo "----sample3----"
sudo grep -l bash /etc/* 2> /dev/null | xargs -t head -10