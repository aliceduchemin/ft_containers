#!/bin/bash

echo "Executing the tests with the STL library :"
sed -i "s/#define CHOICE 2/#define CHOICE 0/" "./testers/testsContainers.hpp"
make re
./test > STD_results.txt 2>&1

echo ""
echo "Executing the tests with the FT library :"
sed -i "s/#define CHOICE 0/#define CHOICE 1/" "./testers/testsContainers.hpp"
make re
./test > FT_results.txt 2>&1

sed -i "s/#define CHOICE 1/#define CHOICE 2/" "./testers/testsContainers.hpp"
diff "STD_results.txt" "FT_results.txt" > "Diff.txt"
echo ""
echo "You can now check the results in the STD_results.txt and FT_results.txt files, or check the differences in the Diff.txt"