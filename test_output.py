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

fh = open('output.txt', 'r')
for line in fh:
    word = line.strip()
    h = hx(word)
    print '%s\t%s' % (word, h)
    hashes.append(h)

print 'MAX_HASH:', max(hashes)

freqs = [None] * 26
for i, l in enumerate(LETTERS):
    freqs[ord(l) - ord('A')] = PRIMES[i]
print freqs
