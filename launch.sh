#!/bin/bash
# Forcer l'utilisation de SDL locale dans ~/.local/lib
export PATH=$(pwd)/SDL_LIB/bin:$PATH
export PKG_CONFIG_PATH=$(pwd)/SDL_LIB/lib/pkgconfig
export LD_LIBRARY_PATH=$(pwd)/SDL_LIB/lib:$LD_LIBRARY_PATH

export PATH=$(pwd)/FFMPEG:$PATH

sleep 1

RES=$(xdpyinfo | awk '/dimensions:/ {print $2}')
OUTDIR="$PWD"
mkdir -p "$OUTDIR"
rm -f $OUTDIR/bg.png

ffmpeg -f x11grab -video_size "$RES" -i "$DISPLAY" \
    -vframes 1 "$OUTDIR/bg.png" \
    && echo "Sauvegardé dans $OUTDIR/bg.png"

# Lancer le jeu depuis son dossier
cd "$(dirname "$0")"
exec ./ou_est_antonio

