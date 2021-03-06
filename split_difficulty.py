CUTOFF = 15000

raw_easy = set()

for i in xrange(3, 7):
    fh = open('input_data/list_easy_%s.txt' % (i,), 'r')
    for i, line in enumerate(fh):
        raw_easy.add(line.strip())
    fh.close()

fh = open('generated_data/output.txt', 'r')

easy_words = []
hard_words = []
for line in fh:
    word = line.strip()
    if word in raw_easy:
        easy_words.append(word)
    else:
        hard_words.append(word)

fh.close()

fh = open('generated_data/easy.txt', 'w')
for word in sorted(easy_words):
    fh.write(word + '\n')
fh.close()

fh = open('generated_data/hard.txt', 'w')
for word in sorted(hard_words[:len(hard_words) / 2]):
    fh.write(word + '\n')
fh.close()

fh = open('generated_data/more.txt', 'w')
for word in sorted(hard_words[len(hard_words) / 2:]):
    fh.write(word + '\n')
fh.close()
