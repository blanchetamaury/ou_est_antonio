#!/usr/bin/env bash

RES=$(xdpyinfo | awk '/dimensions:/ {print $2}')
OUTDIR="$PWD"
mkdir -p "$OUTDIR"
rm -f $OUTDIR/bg.png

ffmpeg -f x11grab -video_size "$RES" -i "$DISPLAY" \
    -vframes 1 "$OUTDIR/bg.png" \
    && echo "Sauvegardé dans $OUTDIR/bg.png"

