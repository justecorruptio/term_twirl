from sys import argv

LETTERS = 'ETAOINSHRDLUFCMGYPWBVKXJQZ'
PRIMES = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
]
LETTERS_TO_PRIMES = dict(zip(LETTERS, PRIMES))

def hx(letters):
    global LETTERS_TO_PRIMES
    r = 1
    for c in letters:
        r *= LETTERS_TO_PRIMES[c]
    return r

hashes = []

count_sixes = 0

fh = open(argv[1], 'r')
for line in fh:
    word = line.strip()
    h = hx(word)
    #print '%s\t%s' % (word, h)
    hashes.append(h)
    if len(word) == 6:
        count_sixes += 1

print 'FILE:', argv[1]
print 'MAX_HASH:', max(hashes)
print 'SIXES:', count_sixes

#freqs = [None] * 26
#for i, l in enumerate(LETTERS):
#    freqs[ord(l) - ord('A')] = PRIMES[i]
#print freqs
