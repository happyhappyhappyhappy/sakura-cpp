#!/usr/bin/bash
sudo grep -l bash /etc/* 2> /dev/null | xargs -L1 -p head -3
