LETTERS = 'ETAOINSHRDLUFCMGYPWBVKXJQZ'
PRIMES = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
]
LETTERS_TO_PRIMES = dict(zip(LETTERS, PRIMES))

SIX = 6

def hx(letters):
    global LETTERS_TO_PRIMES
    r = 1
    for c in letters:
        r *= LETTERS_TO_PRIMES[c]
    return r

fh = open('sixes.txt', 'r')

sixes = {}

for line in fh:
    line = line.strip()
    if len(line) == SIX and hx(line) <= 2 ** 32:
        sixes.setdefault(hx(line), set()).add(line)

fh.close()

fh = open('twl.txt', 'r')

words = []

for line in fh:
    line = line.strip()
    h = hx(line)
    if len(line) >= 3 and len(line) <= SIX and any(sh % h == 0 for sh in sixes):
        words.append(line)

mapping = {}

for word in words:
    h = hx(word)
    for sh in sixes:
        if sh % h == 0:
            mapping.setdefault(sh, set()).add(word)

used_words = set()

for arr in mapping.itervalues():
    if len(arr) > 30 or len(arr) < 6:
        continue
    inner_sixes = [w for w in arr if len(w) == SIX]
    if not all(w in sixes.get(hx(w), {}) for w in inner_sixes):
        continue
    #print ' '.join(sorted(arr, key=lambda x: (-len(x), x)))

    used_words.update(arr)

for word in sorted(used_words):
    print word
