g++ correct.cpp -o correctcode
g++ aditya.cpp -o mycode
g++ gen.cpp -o gen
for((i = 1; ; ++i)); do
     ./gen > tc.txt
    # cat tc.txt
      ./mycode < tc.txt > myop.txt
      ./correctcode < tc.txt > correctop.txt
    diff -i myop.txt correctop.txt > /dev/null || break
    echo "Passed test: " $i  
    # cat tc.txt
    cat myop.txt
done
echo "WA on the following test:"
cat tc.txt
echo "Your answer is:"
cat myop.txt
echo "Correct answer is:"
cat correctop.txt
