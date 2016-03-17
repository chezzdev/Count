#!/bin/bash
cd ..
g++ src/*.cpp -pthread -I$HOME/mongo-client-install/include -L$HOME/mongo-client-install/lib -lmongoclient -lboost_thread -lboost_system -lboost_regex -O2 -fPIC -lfastcgi-daemon2 -shared -o libCount.so
