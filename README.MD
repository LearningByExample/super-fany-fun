# Super Fany Fun
A project for learning to develop video games in C++

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)

## info

This project has been created for teaching some friends about developing video games using C++, we have choose [Cocox2d-x](http://www.cocos2d-x.org) to simplify our development.

Main goals:

- keep it simple
- do small steps
- focus in game mechanics
- don't build an engine
- giving live to a game

# requirements

- C++ compiler for your platform (clang, gcc, etc.)
- C++ IDE (XCode, Visual Studio Code, Android Studio)
- python

## building

First download the dependencies

```bash
$ cd cocos2d
$ python download-deps.py
```

Now you could open the project folder for the platform you like to use:

- proj.android
- proj.ios_mac
- proj.linux
- proj.win32

Currently we are just updating the iOS and Mac project other may not work, yet.

## running from the command line 

If you like to work with the command line you need is easer if you use the cocos tool, for installing it following this steps:

```bash
$ git clone --depth 1 git@github.com:cocos2d/cocos2d-x.git cocos2d
$ cd cocos2d
$ python download-deps.py
$ git submodule update --init
$ python setup.py
```

now for running the game, from the project folder:

```bash
$ cocos run -p <PLATFORM>
```

where `<PLATFORM>` is :
- `ios`
- `android` 
- `mac`

## using visual studio code

You could use visual studio code, follow [this guide](https://code.visualstudio.com/docs/languages/cpp) provided by Microsoft to add C++ support.

## resources

- Game art by [Game Art 2D](https://www.gameart2d.com/)
- [Cocox2d-x Github](https://github.com/cocos2d/cocos2d-x)
