#!/bin/bash

sudo service nginx restart
fastcgi-daemon2 --config=src/HelloFastCGI.conf
