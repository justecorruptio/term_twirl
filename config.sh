echo "GENERATING SIXES"
python gen_sixes.py > easy.txt
echo "GENERATING USED WORDS LIST"
python gen_word_list.py > output.txt
python test_output.py
echo "GENERATING DAWG"
python dawg_gen.py output.txt
echo "GENERATING .H FILE"
python create_dawg_progmem.py > dict_dawg.h
echo "DONE"
