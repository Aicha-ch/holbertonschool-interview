#!/usr/bin/python3

"""calculating how many square units of water
    will be retained after it rains."""


def rain(walls):
    """Returns total amount of water retained."""
    water = 0

    for i in range(1, len(walls) - 1):

        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water += (min(left, right) - walls[i])

    return water
