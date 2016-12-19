
# sdkbox Appnext sample

##Getting Started

###Setup
~~~bash
# run setup script
./setup
~~~

After setup your directory will looks like this
~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-appnext
| +-- cpp
| +-- lua
| \-- js
~~~

* cpp: contains cocos2d-x c++ project sample
* js: contains cocos2d-x js project sample
* lua: contains cocos2d-x lua project sample

###Run

Under each sample project there are project files for different platform

* proj.ios_mac: project file for ios/mac platform
* proj.android: project file to android platform


You can also run the sample with commandline
~~~bash

# run sample with specified language and platform
# eg: cpp and ios
./sdkbox-cocos2d-x-binary/run_sample.sh appnext cpp ios
## or
cd cpp && cocos run -p ios

# javascript and android
./sdkbox-cocos2d-x-binary/run_sample.sh appnext js android
## or
cd js && cocos run -p android

# <optional> if exists "download-depends.sh" in sample repo, execute it
# ./sdkbox-sample-appnext/download-depends.sh

~~~


