#!/usr/bin/python3
"""
Write a script that reads stdin line
by line and computes metrics:
"""
from sys import stdin


statecode = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

size = 0


def print_list():
    """
    Total file size:
    """
    print("File size: {}".format(size))
    for key in sorted(statecode.keys()):
        if statecode[key]:
            print("{}: {}".format(key, statecode[key]))


if __name__ == "__main__":
    count = 0
    try:
        for line in stdin:
            try:
                getdata = line.split()
                size += int(getdata[8])
                key_statucode = getdata[7]
                if key_statucode in statecode:
                    statecode[key_statucode] += 1
            except:
                pass
            if count == 9:
                print_list()
                count = -1
            count += 1
    except KeyboardInterrupt:
        print_list()
        raise
    print_list()
