#!/bin/bash
g++ src/*.cpp -O2 -fPIC -lfastcgi-daemon2 -shared -o libHelloFastCGI.so
