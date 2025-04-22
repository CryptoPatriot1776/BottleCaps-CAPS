
Debian
====================
This directory contains files used to package capsd/caps-qt
for Debian-based Linux systems. If you compile capsd/caps-qt yourself, there are some useful files here.

## caps: URI support ##


caps-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install caps-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your caps-qt binary to `/usr/bin`
and the `../../share/pixmaps/caps128.png` to `/usr/share/pixmaps`

caps-qt.protocol (KDE)

