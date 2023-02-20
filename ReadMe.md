# Calibration Tool

카메라 내/외부 캘리브레이션을 하기위한 tool



## 1. Install

> reference : https://wiki.qt.io/Install_Qt_5_on_Ubuntu

### 1.1. Qt5

- 5.7.0 version 설치

```shell
wget https://download.qt.io/new_archive/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run

chmod +x qt-opensource-linux-x64-5.7.0.run

./qt-opensource-linux-x64-5.7.0.run
```



### 1.2. g++

```sh
sudo apt-get install build-essential
```



### 1.3. Compiler

```sh
sudo apt-get install libfontconfig1
```



### 1.4. OpenCV 4.4.x install

>reference : https://webnautes.tistory.com/1433

1. 설치된 OpenCV 제거

```sh
#OpenCV 설치 유무 확인 --> 설치x

pkg-config --modversion opencv

Package opencv was not found in the pkg-config search path.
Perhaps you should add the directory containing `opencv.pc'
to the PKG_CONFIG_PATH environment variable
No package 'opencv' found
```

```sh
#OpenCV 설치 유무 확인 --> 설치o

pkg-config --modversion opencv

3.4.2

# opencv 삭제
$ sudo apt-get purge  libopencv* python-opencv

$ sudo apt-get autoremove
```



2. 기존 설치된 패키지 업그레이드

```sh
sudo apt-get update

sudo apt-get upgrade
```



3. OpenCV 컴파일 전 필요한 패키지 설치

```sh
sudo apt-get install build-essential cmake

sudo apt-get install pkg-config

sudo apt-get install libjpeg-dev libtiff5-dev libpng-dev

sudo apt-get install ffmpeg libavcodec-dev libavformat-dev libswscale-dev libxvidcore-dev libx264-dev libxine2-dev
 
sudo apt-get install libv4l-dev v4l-utils
 
sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev 
  
sudo apt-get install libgtk-3-dev
  
sudo apt-get install mesa-utils libgl1-mesa-dri libgtkgl2.0-dev libgtkglext1-dev  
  
sudo apt-get install libatlas-base-dev gfortran libeigen3-dev
  
sudo apt-get install python3-dev python3-numpy
```



4. OpenCV 설정과 컴파일 및 설치

```sh
mkdir opencv

cd opencv
  
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.4.0.zip
  
unzip opencv.zip
  
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.4.0.zip
  
unzip opencv_contrib.zip

cd opencv-4.4.0

mkdir build

cd build
  
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=OFF -D WITH_IPP=OFF -D WITH_1394=OFF -D BUILD_WITH_DEBUG_INFO=OFF -D BUILD_DOCS=OFF -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=OFF -D BUILD_PACKAGE=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D WITH_QT=OFF -D WITH_GTK=ON -D WITH_OPENGL=ON -D BUILD_opencv_python3=ON -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.4.0/modules -D WITH_V4L=ON  -D WITH_FFMPEG=ON -D WITH_XINE=ON -D OPENCV_ENABLE_NONFREE=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D OPENCV_SKIP_PYTHON_LOADER=ON -D OPENCV_GENERATE_PKGCONFIG=ON ../

# 다음과 같은 메시지가 보이면 정상적으로 설치

-- Configuring done

-- Generating done

-- Build files have been written to: /home/webnautes/opencv/opencv-4.4.0/build

# make

time make -j$(nproc)
  
sudo make install

sudo ldconfig

cat /etc/ld.so.conf.d/*

pkg-config --modversion opencv4
```



## 2. Setup

```sh
#bashrc open
gedit ~/.bashrc 

#bashrc 맨 아랫줄에 export추가 
#Qt5.7설치 위치에 따라 변경
export LD_LIBRARY_PATH=/home/lsh/Qt5.7.0/5.7/gcc_64/lib:$LD_LIBRARY_PATH
```



## 3. Getting Started

```sh
./e_calibration
```



## 4. Description

### 4.1 main

- 내부 파라미터
- 외부 파라미터

![mainWindow](/media/server/WORK/sh_git/TempProject/ReadMe_image/Main_Window.png)



### 4.2 Intrinsic Calibration

INPUT

- Video Path : Calibration 할 동영상 입력
- Save Path : Calibration 진행 후 결과파일을 저장할 폴더
- Chess board Point(horizontal)(vertical) : Chessboard의 가로, 세로
- Frame per Second : Calibration할 동영상에서 초당 추출할 프레임 수 입력

OUTPUT

- Principal Point Error :  
- Reprojection Error : 재투영 오차
- Save Path에 각종 결과물 출력

![Intrinsic_Calibration](/media/server/WORK/sh_git/TempProject/ReadMe_image/Intrinsic_Calibration.png)



### 4.3 Extrinsic Calibration

#### 4.3.1 Parameter Input

INPUT

- Car width : Wheel to Wheel
- Car Height
- Camera to bumper
- Camera Install Position : 카메라의 설치 위치
- Instrinsic Parameter : 앞서 구한 Instarixsic Parameter txt 파일 로드 (Load하지 않을 시 VFe34차량 내부파라미터)
- Chessboard Cell Size : Chessboard Cell하나의 크기
- Chessboard Point Size : Chessboard의 가로, 세로 사이즈
- Chessboard Distance : 카메라와 Chessboard사이의 거리
- CameraNumber : Input Camera의 번호

![Parameter_Input](/media/server/WORK/sh_git/TempProject/ReadMe_image/Parameter_Input.png)



#### 4.3.2 CaptureImg

INPUT

- Capture_1 : ParameterInput --> Chessboard Distance에 첫번째로 입력된 거리에서의 Chessboard
- Capture_2 : ParameterInput --> Chessboard Distance에 두번째로 입력된 거리에서의 Chessboard
- Clear : Capture Image 초기화

OUTPUT

- Roll : Capture당시의 Roll
- Tilt : Capture_1과 Capture_2사이의 물리적거리와 도형의 닮은비를 이용한 Tilt 계산값

![CapturImage](/media/server/WORK/sh_git/TempProject/ReadMe_image/CapturImage.png)



#### 4.3.3 CameraPoseEstimation

OUTPUT

- Detedcted Point Image : Chessboard corner Detection, Image Center, Principal Point, Chessboard Center 표시
- Reprojection Point Image : Z가 0이고 Y가 증가 할때 발생하는 Point
- Rotation Matirx
- Translation Matrix
- Reprojection Error
- Camera Position :  World좌표에서의 Camera의 위치의 바닥부분을 [0,0,0]으로 지정 하였음. 이상적인 값으로는 Z값만 나오는게 맞음. 아래 값들은 예시 사진으로 다를 수 있음.
- Camera Pose
  - Tilt : 카메라가 아래를 바라보고있을 시 -, 위쪽을 바라보고 있을 시 +
  - Pan : 카메라가 오른쪽을 바라보고 있을 시 -, 왼쪽을 바라보고 있을 시 +
  - Roll : 후면에바라봤을 때 카메라가 오른쪽로 돌아 갔을 시 -, 왼쪽으로 돌아 갔을 시 +
- Export : 외부 파라미터 txt파일로 출력

![CameraPoseEstimation](/media/server/WORK/sh_git/TempProject/ReadMe_image/CameraPoseEstimation.png)
