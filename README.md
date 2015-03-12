![](http://i.imgur.com/vKlQyP4.png)

# Installation  

* Install Haxe `3.2.0` (latest build).
 * `Byte` classes are needed for ArrayBuffer features and better HTML compatibility.
* Git install using `haxelib` command.
 * `haxelib git haxor https://github.com/haxorplatform/haxor-engine.git 1.0`
* Link the `haxor` library in `Flashdevelop` or command line `haxe` compiler.

# Information

## Build HTML

TBD

## Build Android

TBD

## Build Windows

TBD

### Flags
 * `-subsystem: console` enables cmdline.
 * `-D HXCPP_FLOAT32` uses `float` instead of `double`

### Dependencies
 * hxcpp
 * `ndll/Windows/` folder in hxssl
 * glew32.lib
 * glew32.dll
 * `bin` folder in hxcpp
