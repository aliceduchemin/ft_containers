#!/bin/bash

make re
./FT_containers > ft
./STL_containers > stl
diff ft stl