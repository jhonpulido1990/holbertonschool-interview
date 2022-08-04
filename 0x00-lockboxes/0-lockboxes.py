#!/usr/bin/python3
""""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """Write a method that determines if all the boxes can be opened."""
    key = [0]
    for mykey in key:
        for let_key in boxes[mykey]:
            if let_key not in key and let_key < len(boxes):
                key.append(let_key)
    if len(key) == len(boxes):
        return True
    return False
