Run on Arch Linux

install OpenCV4 and Qt
```
sudo pacman -Syu qt5-base qtcreator qt5-doc gdb cmake opencv vtk hdf5
```

open the project on Qt Creator

Optionally, build with gcc
```
gcc -v 2_1.cpp -I/usr/include/opencv4 -L/usr/lib -lstdc++ -L/usr/lib -lopencv_highgui -lopencv_imgcodecs -lopencv_core  -o 2_1
./2_1  ~/Pictures/spacex.jpg

gcc -v 2_3.cpp -I/usr/include/opencv4 -L/usr/lib -lstdc++ -L/usr/lib -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio  -lopencv_video -lopencv_videostab  -lopencv_core  -o 2_3
./2_3 ~/Videos/"Tesla Autonomy Day.mp4"
```
