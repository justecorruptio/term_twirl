from sys import argv

diff = argv[1]

print '#ifndef DICT_DAWG_%s_H' % (diff.upper(),)
print '#define DICT_DAWG_%s_H' % (diff.upper(),)
print 'PROGMEM const uint8_t DICT_DAWG_%s [] = {' % (diff.upper(),)

data = open(diff + '.dawg', 'r').read()
text = ['0x%02x,' % ord(c) for c in data]

for i, item in enumerate(text):
    print item,
    if i % 16 == 15:
        print

print '0x00 };'
print 'const uint16_t DICT_DAWG_%s_START_PTR = 0x%04X;' % (
    diff.upper(),
    ord(data[-3]) | (ord(data[-2]) << 8),
)

fh = open(diff + '.txt', 'r')
count = 0
for line in fh:
    if len(line.strip()) == 6:
        count += 1

print 'const uint16_t DICT_DAWG_%s_NUM_TARGETS = %s;' % (
    diff.upper(),
    count,
)

print '#endif'
