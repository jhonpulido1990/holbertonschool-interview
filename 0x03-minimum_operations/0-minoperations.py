#!/usr/bin/python3
'''Your text editor can execute only two operations in this
file: Copy All and Paste. Given a number n, write a method
that calculates the fewest number of operations needed toresult in exactly n H characters in the file.'''

def minOperations(n):
	'''copy and paste counts as 2 actions'''
	if n <= 1:
		return 0

	num = n
	div = 2
	operations = 0

	while num > 1:
		if num % div == 0:
			num = num / div
			operations = operations + div
		else:
			div += 1
	return operations
