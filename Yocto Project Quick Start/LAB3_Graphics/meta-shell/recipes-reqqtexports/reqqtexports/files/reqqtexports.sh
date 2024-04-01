#!/bin/bash

export QT_QPA_PLATFORM=wayland:xcb
export QT_QPA_FONTDIR=/usr/share/fonts/truetype
echo "QT_QPA_PLATFORM environment variable value: $QT_QPA_PLATFORM \n"
echo "QT_QPA_FONTDIR  environment variable value: $/us \n"

helloQt