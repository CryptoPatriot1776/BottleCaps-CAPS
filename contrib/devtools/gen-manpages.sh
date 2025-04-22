#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CAPSD=${CAPSD:-$SRCDIR/capsd}
CAPSCLI=${CAPSCLI:-$SRCDIR/caps-cli}
CAPSTX=${CAPSTX:-$SRCDIR/caps-tx}
CAPSQT=${CAPSQT:-$SRCDIR/qt/caps-qt}

[ ! -x $CAPSD ] && echo "$CAPSD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
RVNVER=($($CAPSCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for capsd if --version-string is not set,
# but has different outcomes for caps-qt and caps-cli.
echo "[COPYRIGHT]" > footer.h2m
$CAPSD --version | sed -n '1!p' >> footer.h2m

for cmd in $CAPSD $CAPSCLI $CAPSTX $CAPSQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${RVNVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${RVNVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
