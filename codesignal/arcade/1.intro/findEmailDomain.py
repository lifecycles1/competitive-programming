# Given a valid email address, find its domain part.

# Python solution

def solution(address):
    return address.split('@')[-1]


# JavaScript solution

# function solution(address) {
#     return address.split('@').pop()
# }
