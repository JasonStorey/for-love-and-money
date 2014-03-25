For Love and Money
========

Installation
-------

    git clone git@github.com:JasonStorey/for_love_and_money.git


*/lib* directory includes dependencies.

* [TLC library](https://code.google.com/p/tlc5940arduino/) - *lib copy is pre-configured for this project via 'tlc_config.h'*

* [RTC library](https://github.com/adafruit/RTClib) - *lib has dependency on wire.h*

To install library go to **Sketch > Import Library > Add Library**.

Arduino will add it into **Documents > Arduino > libraries**.

[Library installation docs](http://arduino.cc/en/Guide/Libraries#.UxW5OvR_sX4)

Gotchas
------
TLC library must be configured correctly for the number of TLCs. See installation docs above.