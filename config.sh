echo "GENERATING SIXES"
python gen_sixes.py > sixes.txt
echo "GENERATING USED WORDS LIST"
python gen_word_list.py > output.txt
echo "SPLITTING INTO EASY AND HARD LISTS"
python split_difficulty.py
echo "TESTING OUTPUTS"
python test_output.py easy.txt
python test_output.py hard.txt
echo "GENERATING DAWG"
python dawg_gen.py easy.txt easy.dawg
python dawg_gen.py hard.txt hard.dawg
echo "GENERATING .H FILE"
python create_dawg_progmem.py easy > dict_dawg_easy.h
python create_dawg_progmem.py hard > dict_dawg_hard.h
echo "DONE"
