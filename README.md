# Hiredis Connectivity Example

## Contents
1.  [Summary](#summary)
2.  [Features](#features)
3.  [Prerequisites](#prerequisites)
4.  [Setup](#setup)
4.  [Usage](#usage)


## Summary <a name="summary"></a>
This demonstrates use of the hiredis client lib.  It creates a connection to a Redis database then loops forever with a Echo command every 5 seconds.

## Features <a name="features"></a>
- hiredis

## Prerequisites <a name="prerequisites"></a>
- Linux OS

## Setup <a name="setup"></a>
```bash
git clone git@github.com:joeywhelan/hiredis-example.git && cd hiredis-example
wget https://github.com/redis/hiredis/archive/refs/heads/master.zip
cd hiredis-master
make
make install
cd ..
sudo ldconfig
```
## Usage <a name="usage"></a>
- ./conntest <options>
- -h host
- -p port
- -a password for default user
