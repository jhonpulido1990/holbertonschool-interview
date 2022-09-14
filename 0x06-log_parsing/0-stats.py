#!/usr/bin/python3
"""
Write a script that reads stdin line
by line and computes metrics:
"""
import sys


def print_list():
    """
    Total file size: File size: <total size>
    format: <status code>: <number>
    """
    for key in sorted(statecode.keys()):
        if statecode[key] > 0:
            print(f"{key}: {statecode[key]}")


if __name__ == "__main__":
    COUNT = 1
    SIZEFILE = 0
    statecode = {"200": 0, "301": 0, "400": 0,
                 "401": 0, "403": 0, "404": 0,
                 "405": 0, "500": 0}

    try:
        for line in sys.stdin:
            getdata = line.split(" ")
            SIZEFILE += int(getdata[8])
            key_statucode = getdata[7]
            if key_statucode in statecode:
                statecode[key_statucode] += 1
            if COUNT % 10 == 0:
                print(f"File size: {SIZEFILE}")
                print_list()
            COUNT += 1
    except KeyboardInterrupt:
        print(f"File size: {SIZEFILE}")
        print_list()
        raise
    print(f"File size: {SIZEFILE}")
    print_list()
