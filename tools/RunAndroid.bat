cd deploy/android/
taskkill /F /FI "WINDOWTITLE eq AndroidConsole" /T
adb shell setprop debug.perfhudes 0
adb logcat -c
start "AndroidConsole" adb logcat -b main -v raw TRACE:V ActivityManager:W haxor.platform.android:V *:E
adb shell am force-stop haxor.platform.android 
adb uninstall haxor.platform.android		
adb install bin/HelloWorld-debug.apk
adb shell am start -n haxor.platform.android/haxor.platform.android.Entry

