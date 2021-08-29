#!/bin/bash
g++ -v --help 2>/dev/null | grep -E "^\s+\-std=.*$" 