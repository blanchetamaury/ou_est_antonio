#!/bin/bash

# Définir la version de FFmpeg à installer (vous pouvez changer cette valeur)
FFMPEG_VERSION=6.1

# Dossier d'installation
INSTALL_DIR="$(pwd)/FFMPEG"

# Créer le dossier si nécessaire
mkdir -p "$INSTALL_DIR"

cd FFMPEG
# Télécharger les binaires statiques de FFmpeg depuis le site officiel
echo "Téléchargement de FFmpeg $FFMPEG_VERSION..."
wget -O ffmpeg-release.tar.xz https://johnvansickle.com/ffmpeg/releases/ffmpeg-release-amd64-static.tar.xz

# Extraire l'archive
tar -xf ffmpeg-release.tar.xz

# Trouver le dossier extrait
FFMPEG_FOLDER=$(find . -type d -name "ffmpeg-*static" | head -n 1)

# Copier les binaires dans le dossier local
cp "$FFMPEG_FOLDER"/ffmpeg "$INSTALL_DIR"
cp "$FFMPEG_FOLDER"/ffprobe "$INSTALL_DIR"

# Ajouter FFmpeg à votre PATH local si ce n'est pas déjà fait
if ! grep -q "$INSTALL_DIR" "$HOME/.bashrc"; then
    echo "export PATH=\"$INSTALL_DIR:\$PATH\"" >> "$HOME/.bashrc"
    echo "Ajout de FFmpeg au PATH dans .bashrc"
fi

echo "Installation terminée ! Redémarrez votre terminal ou exécutez :"
echo "export PATH=\"$INSTALL_DIR:\$PATH\""
cd ..

# Tester l'installation
"$INSTALL_DIR/ffmpeg" -version