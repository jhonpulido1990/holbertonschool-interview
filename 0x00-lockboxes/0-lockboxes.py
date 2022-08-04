#!/usr/bin/python3
""""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """Write a method that determines if all the boxes can be opened."""
    numberlist = []
    set_list = []
    for x in range(len(boxes)):
        if len(boxes[x]) == 0 and (n - 1) != x:
            return False
        for i in boxes[x]:
            numberlist.append(i)
    set_list = [*set(numberlist)]
    return sorted(set_list) == list(range(min(set_list), max(set_list) + 1))
