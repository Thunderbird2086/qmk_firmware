## Steno layer

This was derived from the great work by Vissale Neang (GitHub user FromtonRouge) on his [Ergodox
layout](https://github.com/FromtonRouge/qmk_firmware/tree/master/keyboard/ergodox_ez/keymaps/fromtonrouge).
See that page for more complete information on key combinations. 
Jackdaw was developed mainly by [Jennifer Brien](https://groups.google.com/forum/?fromgroups#!topic/ploversteno/C42uhF0P8WI). 

![Steno layer](https://cdn.rawgit.com/tshort/qmk_firmware/master/keyboards/subsurface/keymaps/default/steno/steno.svg)

Here is a cheat sheet with some of the nonobvious [Shelton chords](http://www.google.com/patents/US3970185) included ([pdf](jackdaw-cheatsheet.pdf)).

![Steno cheat sheet](https://cdn.rawgit.com/tshort/qmk_firmware/master/keyboards/subsurface/keymaps/default/steno/jackdaw-cheatsheet.svg)

I added a few chords on the right side that are not in the Shelton spec: LD = LGCHS, LDS = LGCHTS, and NL = NLGC.

Two spacing modes are provided that control entry of spaces:

* *Space mode* -- The default mode. A trailing space is added after each chord. This is useful because most common words can be typed in one chord. 
* *No-space mode* -- No spaces are added.

Used alone, the "Meta-Space" key toggles between these two spacing modes. If the
Meta-Space key is used with a chord, it toggles the spacing mode just for that
chord. When the Meta-Space key is used alone to enable Space mode, a space is
inserted. 

Normally, I use this in the space mode. If I have an easy two-chord word, I'll
hit the Meta-Space key as part of the first chord. If it's a longer word, I'll
toggle into no-space mode and toggle back out after the end of the word.