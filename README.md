![](https://dl.dropboxusercontent.com/u/20655747/haxor/img/haxor-engine-logo.png)

# Usage  

* Install Haxe `3.2.0` (latest build).
 * `Byte` classes are needed for ArrayBuffer features.
 * Better HTML compatibility.
* Git install using `haxelib` command.
 * `haxelib git haxor https://github.com/haxorplatform/haxor-engine.git 1.0`
* Link the `haxor` library in `Flashdevelop` or command line `haxe` compiler.
 * ![](https://dl.dropboxusercontent.com/u/20655747/haxor/img/usage-flashdevelop-dialog.jpg)
 * `haxe -lib haxor ...`

# Build

## HTML

TBD

## Android

TBD

## Windows

TBD

### Flags
 * `-subsystem: console` enables cmdline.
 * `-D HXCPP_FLOAT32` uses `float` instead of `double`

### Dependencies
 * `hxcpp`
 * `ndll/Windows/` folder in hxssl
 * `glew32.lib`
 * `glew32.dll`
 * `bin` folder in hxcpp
