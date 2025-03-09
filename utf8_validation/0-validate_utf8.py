#!/usr/bin/python3
"""
validUTF8
"""


def validUTF8(data):
    """ is a given data set represents a valid UTF-8?"""
    bytes = 0

    for n in data:
        n = n & 0xFF
        if 191 >= n >= 128:
            if not bytes:
                return False
            bytes -= 1
        else:
            if bytes:
                return False
            if n < 128:
                continue
            elif n < 224:
                bytes = 1
            elif n < 240:
                bytes = 2
            elif n < 248:
                bytes = 3
            else:
                return False
    return bytes == 0